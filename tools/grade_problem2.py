#!/usr/bin/env python3
"""Auto-grader for Exam Problem 2.

Rubric (Problem 2):
- Asks user to enter password (expects prompt + scanf).
- Branches correctly based on password (incorrect path should not proceed).
- Branches based on user choice (expects both P and R branches).

Scoring:
- 6.25: no rubric errors
- 5: <= 3 minor errors
- 0: any major error OR > 3 minor errors

This script intentionally avoids checking code outside Problem 2 scope.
"""

from __future__ import annotations

import csv
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Optional


DIR = Path("final")
PASSWORD_LITERAL = "5678"


def read_text(path: Path) -> str:
    return path.read_text(errors="ignore")


def strip_c_comments(code: str) -> str:
    """Remove // and /* */ comments while preserving strings/chars."""

    out: list[str] = []
    i = 0
    n = len(code)
    in_str = False
    in_chr = False
    in_line = False
    in_block = False
    escape = False

    while i < n:
        ch = code[i]
        nxt = code[i + 1] if i + 1 < n else ""

        if in_line:
            if ch == "\n":
                in_line = False
                out.append(ch)
            i += 1
            continue

        if in_block:
            if ch == "*" and nxt == "/":
                in_block = False
                i += 2
            else:
                i += 1
            continue

        if in_str:
            out.append(ch)
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_str = False
            i += 1
            continue

        if in_chr:
            out.append(ch)
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_chr = False
            i += 1
            continue

        # normal
        if ch == "/" and nxt == "/":
            in_line = True
            i += 2
            continue
        if ch == "/" and nxt == "*":
            in_block = True
            i += 2
            continue
        if ch == '"':
            in_str = True
            out.append(ch)
            i += 1
            continue
        if ch == "'":
            in_chr = True
            out.append(ch)
            i += 1
            continue

        out.append(ch)
        i += 1

    return "".join(out)


def normalize_ws(s: str) -> str:
    return re.sub(r"\s+", " ", s).strip()


@dataclass(frozen=True)
class ScanCall:
    pos: int
    fmt: str
    arg_expr: str
    var: str
    has_amp: bool


def find_printf_like_calls(section: str) -> list[tuple[int, str]]:
    """Return (pos, literal_string) for printf/puts where first arg is a string literal."""
    calls: list[tuple[int, str]] = []
    for m in re.finditer(r"\b(?:printf|puts)\s*\(\s*\"([^\"]*)\"", section, flags=re.IGNORECASE):
        calls.append((m.start(), m.group(1)))
    return calls


def find_scan_calls(section: str) -> list[ScanCall]:
    scans: list[ScanCall] = []
    for m in re.finditer(
        r"\bscanf\s*\(\s*\"([^\"]*)\"\s*,\s*([^,\)]+)",
        section,
        flags=re.IGNORECASE,
    ):
        fmt = m.group(1)
        arg_expr = m.group(2).strip()
        var_m = re.search(r"&?\s*([A-Za-z_][A-Za-z0-9_]*)", arg_expr)
        if not var_m:
            continue
        var = var_m.group(1)
        has_amp = arg_expr.lstrip().startswith("&")
        scans.append(ScanCall(pos=m.start(), fmt=fmt, arg_expr=arg_expr, var=var, has_amp=has_amp))
    return scans


def pick_password_scan(scans: list[ScanCall], prompts: list[tuple[int, str]], section: str) -> Optional[ScanCall]:
    if not scans:
        return None

    prompt_positions = [p for p, _ in prompts]
    best: Optional[ScanCall] = None
    best_score = -10**9

    for sc in scans:
        score = 0
        fmt_low = sc.fmt.lower()
        var_low = sc.var.lower()

        if "%d" in fmt_low or "%i" in fmt_low:
            score += 2
        if "password" in fmt_low:
            score += 3
        if re.search(r"\b(pass|pw|password|code)\b", var_low):
            score += 2

        # prefer scans near a prompt
        if prompt_positions:
            dist = min(abs(sc.pos - pp) for pp in prompt_positions)
            if dist < 500:
                score += 5
            elif dist < 1200:
                score += 2

        # prefer scans near the password literal
        nearby = section[max(0, sc.pos - 1200) : min(len(section), sc.pos + 2400)]
        if PASSWORD_LITERAL in nearby:
            score += 3

        if score > best_score:
            best_score = score
            best = sc

    return best


def find_decl_type(code: str, var: str, around: int) -> Optional[str]:
    """Heuristic: find the nearest primitive declaration of var before around."""
    start = max(0, around - 2500)
    end = min(len(code), around + 200)
    window = code[start:end]

    # Capture the last occurrence in the window (closest prior declaration)
    pattern = re.compile(
        rf"\b(?P<type>unsigned\s+|signed\s+)?(?P<t>int|float|double|char|long|short)\b[^;\n]*\b{re.escape(var)}\b",
        flags=re.IGNORECASE,
    )
    last: Optional[re.Match[str]] = None
    for m in pattern.finditer(window):
        last = m
    if not last:
        return None
    t = last.group("t").lower()
    return t


def has_return_or_exit(code: str) -> bool:
    return bool(re.search(r"\b(return\b|exit\s*\(|_Exit\s*\()", code))


def find_first_control_after(section: str, start_pos: int, var: Optional[str]) -> Optional[tuple[str, int]]:
    """Return (kind, pos) where kind in {'if','while'} for first control using var/5678."""
    needle = section[start_pos:]
    for m in re.finditer(r"\b(if|while)\b\s*\(", needle, flags=re.IGNORECASE):
        kind = m.group(1).lower()
        pos = start_pos + m.start()
        # cheap check: see if ')' segment mentions var or 5678
        close = needle.find(")", m.end())
        if close == -1:
            continue
        cond = needle[m.end() : close].lower()
        if PASSWORD_LITERAL in cond:
            return kind, pos
        if var and re.search(rf"\b{re.escape(var.lower())}\b", cond):
            return kind, pos
    return None


def find_matching_paren(code: str, open_pos: int) -> Optional[int]:
    depth = 0
    i = open_pos
    n = len(code)
    in_str = False
    in_chr = False
    escape = False
    while i < n:
        ch = code[i]
        if in_str:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_str = False
            i += 1
            continue
        if in_chr:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_chr = False
            i += 1
            continue
        if ch == '"':
            in_str = True
            i += 1
            continue
        if ch == "'":
            in_chr = True
            i += 1
            continue

        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return None


def find_matching_brace(code: str, open_pos: int) -> Optional[int]:
    depth = 0
    i = open_pos
    n = len(code)
    in_str = False
    in_chr = False
    escape = False
    while i < n:
        ch = code[i]
        if in_str:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_str = False
            i += 1
            continue
        if in_chr:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_chr = False
            i += 1
            continue
        if ch == '"':
            in_str = True
            i += 1
            continue
        if ch == "'":
            in_chr = True
            i += 1
            continue

        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return None


def skip_ws(code: str, i: int) -> int:
    while i < len(code) and code[i].isspace():
        i += 1
    return i


def parse_statement(code: str, start: int) -> tuple[str, int]:
    """Parse a C statement starting at start. Returns (stmt_text, end_pos_exclusive)."""
    i = skip_ws(code, start)
    if i >= len(code):
        return "", i
    if code[i] == "{":
        end = find_matching_brace(code, i)
        if end is None:
            # Unbalanced; take a conservative slice
            return code[i:], len(code)
        return code[i : end + 1], end + 1

    # single statement: consume until ';' (best-effort, ignoring strings/chars)
    in_str = False
    in_chr = False
    escape = False
    j = i
    while j < len(code):
        ch = code[j]
        if in_str:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_str = False
            j += 1
            continue
        if in_chr:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_chr = False
            j += 1
            continue
        if ch == '"':
            in_str = True
        elif ch == "'":
            in_chr = True
        elif ch == ";":
            return code[i : j + 1], j + 1
        elif ch == "{":
            # statement is a compound block starting here; parse as block
            end = find_matching_brace(code, j)
            if end is None:
                return code[i:], len(code)
            return code[i : end + 1], end + 1
        j += 1

    return code[i:], len(code)


@dataclass
class IfParse:
    cond: str
    then_text: str
    else_text: Optional[str]
    end_pos: int


def parse_if(code: str, if_pos: int) -> Optional[IfParse]:
    m = re.match(r"\bif\b", code[if_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    i = if_pos + m.end()
    i = skip_ws(code, i)
    if i >= len(code) or code[i] != "(":
        return None
    close = find_matching_paren(code, i)
    if close is None:
        return None
    cond = code[i + 1 : close]
    then_text, then_end = parse_statement(code, close + 1)
    j = skip_ws(code, then_end)
    else_text = None
    if re.match(r"\belse\b", code[j:], flags=re.IGNORECASE):
        j2 = j + re.match(r"\belse\b", code[j:], flags=re.IGNORECASE).end()  # type: ignore[union-attr]
        else_text, else_end = parse_statement(code, j2)
        return IfParse(cond=cond, then_text=then_text, else_text=else_text, end_pos=else_end)
    return IfParse(cond=cond, then_text=then_text, else_text=None, end_pos=then_end)


@dataclass
class WhileParse:
    cond: str
    body_text: str
    end_pos: int


def parse_while(code: str, while_pos: int) -> Optional[WhileParse]:
    m = re.match(r"\bwhile\b", code[while_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    i = while_pos + m.end()
    i = skip_ws(code, i)
    if i >= len(code) or code[i] != "(":
        return None
    close = find_matching_paren(code, i)
    if close is None:
        return None
    cond = code[i + 1 : close]
    body_text, body_end = parse_statement(code, close + 1)
    return WhileParse(cond=cond, body_text=body_text, end_pos=body_end)


def pr_branch_presence(text: str) -> tuple[bool, bool]:
    """Return (has_P_branch, has_R_branch) based on patterns in text."""
    # NOTE: don't use word boundaries after quoted chars because the final quote
    # is not a word character (e.g., "case 'P':" would fail with a trailing \b).
    has_p = bool(
        re.search(r"\bcase\s*\(?\s*'P'\s*\)?\s*:", text)
        or re.search(r"\bcase\s*\(?\s*'p'\s*\)?\s*:", text)
        or re.search(r"==\s*'P'", text)
        or re.search(r"==\s*'p'", text)
    )
    has_r = bool(
        re.search(r"\bcase\s*\(?\s*'R'\s*\)?\s*:", text)
        or re.search(r"\bcase\s*\(?\s*'r'\s*\)?\s*:", text)
        or re.search(r"==\s*'R'", text)
        or re.search(r"==\s*'r'", text)
    )
    return has_p, has_r


def contains_incorrect_password_message(text: str) -> bool:
    # Accept variants like "Incorrect password" with typos
    return bool(re.search(r"incorrect\s*password|incorrect\b|password\b", text, flags=re.IGNORECASE))


def find_near_prompt(section: str, scan_pos: int) -> Optional[str]:
    """Find a printf/puts literal within ~350 chars before scan_pos."""
    lo = max(0, scan_pos - 350)
    window = section[lo:scan_pos]
    prompts = find_printf_like_calls(window)
    if not prompts:
        return None
    # take the last prompt before scanf
    return prompts[-1][1]


def analyze_problem2(code: str) -> tuple[list[str], list[str]]:
    majors: list[str] = []
    minors: list[str] = []

    code_nc = strip_c_comments(code)

    # Anchor near the password portion
    lower = code_nc.lower()
    anchor = lower.find("password")
    if anchor == -1:
        anchor = lower.find(PASSWORD_LITERAL)
    if anchor == -1:
        anchor = 0

    win_start = max(0, anchor - 600)
    win_end = min(len(code_nc), anchor + 9000)
    section = code_nc[win_start:win_end]

    prompts = find_printf_like_calls(section)
    scans = find_scan_calls(section)
    pw_scan = pick_password_scan(scans, prompts, section)

    if pw_scan is None:
        majors.append("Did not ask user to enter password (missing scanf).")
        # Without scanf we can't reliably proceed.
        return list(dict.fromkeys(majors)), list(dict.fromkeys(minors))

    pw_var = pw_scan.var
    scan_abs = win_start + pw_scan.pos

    near_prompt = find_near_prompt(section, pw_scan.pos)
    if near_prompt is None:
        majors.append("Did not ask user to enter password (missing printf/puts prompt).")
    else:
        if "password" not in near_prompt.lower():
            minors.append("Content-related typo (prompt does not mention password).")
        if re.search(r"passowrd|pasword|passwrod", near_prompt, flags=re.IGNORECASE):
            minors.append("Content-related typo (password prompt typo).")

    # password var declared + type check
    decl_type = find_decl_type(code_nc, pw_var, scan_abs)
    if decl_type is None:
        minors.append("Used var not declared (password variable).")
    elif decl_type != "int":
        minors.append("Wrong data type used (password should be int).")

    fmt_low = pw_scan.fmt.lower()
    if not ("%d" in fmt_low or "%i" in fmt_low):
        # If they used %s/%f etc for password, count as wrong data type
        minors.append("Wrong data type used (password scanf format).")
    else:
        if not pw_scan.has_amp:
            minors.append("Wrong data type used (scanf missing & for password).")

    # Find password check structure after scan
    ctrl = find_first_control_after(section, pw_scan.pos, pw_var)
    if ctrl is None:
        majors.append("Did not use a branching structure for the password check.")
        return list(dict.fromkeys(majors)), list(dict.fromkeys(minors))

    kind, ctrl_pos = ctrl
    ctrl_abs = win_start + ctrl_pos
    after_ctrl_abs = ctrl_abs - win_start

    correct_scope = ""
    incorrect_scope = ""

    if kind == "while":
        # Detect re-prompt loop for password (major: doesn't end on wrong password)
        parsed_w = parse_while(section, ctrl_pos)
        if parsed_w is None:
            # Fallback: conservative slice
            loop_chunk = section[ctrl_pos : min(len(section), ctrl_pos + 1200)]
            loop_body = loop_chunk
            remainder = section[ctrl_pos + len(loop_chunk) :]
        else:
            loop_body = parsed_w.body_text
            remainder = section[parsed_w.end_pos :]

        # If the loop body re-scans the password, it allows retrying (major per rubric).
        loop_has_rescan = bool(
            re.search(
                r"\bscanf\s*\(\s*\"[^\"]*\"\s*,\s*&?\s*" + re.escape(pw_var) + r"\b",
                loop_body,
                flags=re.IGNORECASE,
            )
        )
        if loop_has_rescan and not has_return_or_exit(loop_body):
            majors.append("Program doesn't end if wrong password is entered (re-prompts in a loop).")

        # In a while-check pattern, the code after the loop is the "correct password" path.
        correct_scope = remainder
        incorrect_scope = loop_body
    else:
        parsed = parse_if(section, ctrl_pos)
        if parsed is None:
            # fall back: look for else keyword and incorrect message
            majors.append("Did not use a valid branching structure for password (unparsable if-statement).")
            return list(dict.fromkeys(majors)), list(dict.fromkeys(minors))

        cond_low = normalize_ws(parsed.cond.lower())
        then_txt = parsed.then_text
        else_txt = parsed.else_text
        remainder = section[parsed.end_pos :]

        # Determine which branch is incorrect vs correct (heuristic)
        cond_is_incorrect_when_true = False
        if PASSWORD_LITERAL in cond_low:
            if "!=" in cond_low or "<" in cond_low or ">" in cond_low:
                cond_is_incorrect_when_true = True
            elif "==" in cond_low:
                cond_is_incorrect_when_true = False

        if else_txt is None:
            # Missing an explicit branch
            if cond_is_incorrect_when_true:
                # then is incorrect; correct is remainder after if
                incorrect_scope = then_txt
                correct_scope = remainder
                if not has_return_or_exit(then_txt):
                    majors.append("Program doesn't end if wrong password is entered (no else/return).")
            else:
                majors.append("Missing one of the branches (no incorrect-password branch).")
                correct_scope = then_txt
        else:
            if cond_is_incorrect_when_true:
                incorrect_scope = then_txt
                correct_scope = else_txt
            else:
                correct_scope = then_txt
                incorrect_scope = else_txt

            # If there is code after the if/else that includes P/R branching,
            # and the incorrect branch does not return/exit, then wrong password may proceed.
            has_p, has_r = pr_branch_presence(remainder)
            if (has_p or has_r) and not has_return_or_exit(incorrect_scope):
                majors.append("Program doesn't end if wrong password is entered (continues after password check).")

            # Common student structure: handle incorrect password with `return`,
            # then do P/R branching *after* the if/else. In that case, the remainder
            # is part of the correct-password path and should count toward P/R detection.
            if has_return_or_exit(incorrect_scope):
                correct_scope = (correct_scope + "\n" + remainder) if correct_scope else remainder

        # Missing statement for incorrect password (minor)
        if incorrect_scope and not re.search(r"\bprintf\b|\bputs\b", incorrect_scope, flags=re.IGNORECASE):
            minors.append("Missing the statement for when password is incorrect.")

        # Content typos in incorrect password message
        if incorrect_scope and re.search(r"\bprintf\b\s*\(\s*\"[^\"]*\"", incorrect_scope, flags=re.IGNORECASE):
            # Extract literals inside incorrect scope
            lits = re.findall(r"\b(?:printf|puts)\s*\(\s*\"([^\"]*)\"", incorrect_scope, flags=re.IGNORECASE)
            joined = " ".join(lits)
            if re.search(r"inncorrect|incorect|inccorect", joined, flags=re.IGNORECASE):
                minors.append("Content-related typo (incorrect-password message typo).")
            # If they never mention incorrect, count as missing statement (already handled) but keep this lenient.

        # If the incorrect branch contains P/R branching, then wrong password proceeds (major)
        if incorrect_scope:
            has_p_i, has_r_i = pr_branch_presence(incorrect_scope)
            if has_p_i or has_r_i:
                majors.append("Program doesn't end if wrong password is entered (options reachable on wrong password).")

    # User choice branching (P/R)
    has_p, has_r = pr_branch_presence(correct_scope)
    if not (has_p or has_r):
        majors.append("Did not set up branching structure based on user choice (P/R).")
    elif not (has_p and has_r):
        majors.append("Missing one of the user-choice branches (needs both P and R).")

    # Dedupe
    majors = list(dict.fromkeys(majors))
    minors = list(dict.fromkeys(minors))
    return majors, minors


def grade(majors: list[str], minors: list[str]) -> tuple[float, str]:
    if majors or len(minors) > 3:
        reasons = majors + minors
        if not reasons:
            return 0.0, "Major error."
        return 0.0, "; ".join(reasons)
    if 0 < len(minors) <= 3:
        return 5.0, "; ".join(minors)
    return 6.25, "No rubric errors detected in problem 2 block."


def next_out_path() -> Path:
    base = Path("problem2.csv")
    if not base.exists():
        return base
    i = 2
    while True:
        p = Path(f"problem2_{i}.csv")
        if not p.exists():
            return p
        i += 1


def main() -> None:
    files = sorted(DIR.glob("*.c"))
    out_path = next_out_path()

    with out_path.open("w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["student_file", "score", "reason"])
        for p in files:
            majors, minors = analyze_problem2(read_text(p))
            score, reason = grade(majors, minors)
            # match prior CSV style (no forced decimals for 0/5)
            if score in (0.0, 5.0):
                score_out: str | float = int(score)
            else:
                score_out = score
            w.writerow([p.name, score_out, reason])
            print(f"Graded {p.name}: {score_out} — {reason}")

    print("Wrote", out_path)


if __name__ == "__main__":
    main()
