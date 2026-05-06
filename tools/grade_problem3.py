#!/usr/bin/env python3
"""Auto-grader for Exam Problem 3.

Rubric (Problem 3):
- Asks user to enter P or R (expects prompt + user input).
- Error checks indefinitely until the input is valid.

Minor errors (<= 3 minor => 5 pts):
1) Any content-related typo.
2) Used var not declared.
3) Wrong data type used.
4) Missing space for %c in scanf.
5) Error checking with branching instead of looping.

Major errors (any major => 0 pts):
1) Did not ask for user choice (missing printf AND scanf).
2) No error checking included.

Scoring:
- 6.25: no rubric errors detected
- 5: <= 3 minor errors
- 0: any major error OR > 3 minor errors

This script intentionally avoids checking code outside Problem 3 scope.
"""

from __future__ import annotations

import csv
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Optional


DIR = Path("final")


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


def skip_ws(code: str, i: int) -> int:
    while i < len(code) and code[i].isspace():
        i += 1
    return i


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


def parse_statement(code: str, start: int) -> tuple[str, int]:
    """Parse a C statement starting at start. Returns (stmt_text, end_pos_exclusive)."""

    i = skip_ws(code, start)
    if i >= len(code):
        return "", i
    if code[i] == "{":
        end = find_matching_brace(code, i)
        if end is None:
            return code[i:], len(code)
        return code[i : end + 1], end + 1

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
            end = find_matching_brace(code, j)
            if end is None:
                return code[i:], len(code)
            return code[i : end + 1], end + 1
        j += 1

    return code[i:], len(code)


@dataclass(frozen=True)
class InputCall:
    pos: int
    func: str  # scanf|fscanf|scanf_s|getchar
    fmt: Optional[str]
    arg_expr: Optional[str]
    var: str
    has_amp: Optional[bool]


def find_printf_like_calls(section: str) -> list[tuple[int, str]]:
    """Return (pos, literal_string) for printf/puts where first arg is a string literal."""
    calls: list[tuple[int, str]] = []
    for m in re.finditer(r"\b(?:printf|puts)\s*\(\s*\"([^\"]*)\"", section, flags=re.IGNORECASE):
        calls.append((m.start(), m.group(1)))
    return calls


def has_standalone_letter(s: str, letter: str) -> bool:
    # Detect '(P)', ' P ', 'P:' etc; avoid matching words like 'Please'.
    return bool(re.search(rf"(^|[^A-Za-z0-9]){re.escape(letter)}([^A-Za-z0-9]|$)", s, flags=re.IGNORECASE))


def is_pr_prompt_literal(s: str) -> bool:
    return has_standalone_letter(s, "P") and has_standalone_letter(s, "R")


def find_input_calls(code: str) -> list[InputCall]:
    inputs: list[InputCall] = []

    # scanf / scanf_s
    for m in re.finditer(
        r"\b(scanf|scanf_s)\s*\(\s*\"([^\"]*)\"\s*,\s*([^,\)]+)",
        code,
        flags=re.IGNORECASE,
    ):
        func = m.group(1)
        fmt = m.group(2)
        arg_expr = m.group(3).strip()
        var_m = re.search(r"&?\s*([A-Za-z_][A-Za-z0-9_]*)", arg_expr)
        if not var_m:
            continue
        var = var_m.group(1)
        has_amp = arg_expr.lstrip().startswith("&")
        inputs.append(InputCall(pos=m.start(), func=func.lower(), fmt=fmt, arg_expr=arg_expr, var=var, has_amp=has_amp))

    # fscanf
    for m in re.finditer(
        r"\bfscanf\s*\(\s*[^,]+\s*,\s*\"([^\"]*)\"\s*,\s*([^,\)]+)",
        code,
        flags=re.IGNORECASE,
    ):
        fmt = m.group(1)
        arg_expr = m.group(2).strip()
        var_m = re.search(r"&?\s*([A-Za-z_][A-Za-z0-9_]*)", arg_expr)
        if not var_m:
            continue
        var = var_m.group(1)
        has_amp = arg_expr.lstrip().startswith("&")
        inputs.append(InputCall(pos=m.start(), func="fscanf", fmt=fmt, arg_expr=arg_expr, var=var, has_amp=has_amp))

    # getchar assignments
    for m in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*=\s*getchar\s*\(\s*\)", code):
        var = m.group(1)
        inputs.append(InputCall(pos=m.start(), func="getchar", fmt=None, arg_expr=None, var=var, has_amp=None))

    return inputs


def pr_char_literals_present(text: str) -> bool:
    return bool(re.search(r"'[Pp]'", text)) and bool(re.search(r"'[Rr]'", text))


def pr_compare_flags(text: str, var: str) -> tuple[bool, bool, bool, bool]:
    """Return (cmp_p, cmp_r, bare_p, bare_r) where bare_* means compared to identifier P/R.

    This intentionally looks for comparison operators (==/!=) so we don't accidentally
    treat prompt strings like "Enter P ... R ..." as a validity check.
    """

    v = re.escape(var)
    var_expr = rf"(?:\b{v}\b|\b(?:toupper|tolower)\s*\(\s*{v}\s*\))"
    p_lit = r"'[Pp]'"
    r_lit = r"'[Rr]'"
    p_sym = r"\bP\b"
    r_sym = r"\bR\b"

    cmp_p = bool(re.search(rf"{var_expr}\s*(?:==|!=)\s*(?:{p_lit}|{p_sym})", text)) or bool(
        re.search(rf"(?:{p_lit}|{p_sym})\s*(?:==|!=)\s*{var_expr}", text)
    )
    cmp_r = bool(re.search(rf"{var_expr}\s*(?:==|!=)\s*(?:{r_lit}|{r_sym})", text)) or bool(
        re.search(rf"(?:{r_lit}|{r_sym})\s*(?:==|!=)\s*{var_expr}", text)
    )

    bare_p = bool(re.search(rf"{var_expr}\s*(?:==|!=)\s*{p_sym}", text)) or bool(
        re.search(rf"{p_sym}\s*(?:==|!=)\s*{var_expr}", text)
    )
    bare_r = bool(re.search(rf"{var_expr}\s*(?:==|!=)\s*{r_sym}", text)) or bool(
        re.search(rf"{r_sym}\s*(?:==|!=)\s*{var_expr}", text)
    )

    return cmp_p, cmp_r, bare_p, bare_r


def pr_any_compare_flags(text: str) -> tuple[bool, bool, bool, bool]:
    """Return (cmp_p, cmp_r, bare_p, bare_r) for ANY ==/!= comparison to P/R.

    Used to recognize students' intended P/R checks even if they accidentally
    compare the wrong variable name in part of the condition.
    """

    p_lit = r"'[Pp]'"
    r_lit = r"'[Rr]'"
    p_sym = r"\bP\b"
    r_sym = r"\bR\b"

    cmp_p = bool(re.search(rf"(?:==|!=)\s*(?:{p_lit}|{p_sym})", text)) or bool(
        re.search(rf"(?:{p_lit}|{p_sym})\s*(?:==|!=)", text)
    )
    cmp_r = bool(re.search(rf"(?:==|!=)\s*(?:{r_lit}|{r_sym})", text)) or bool(
        re.search(rf"(?:{r_lit}|{r_sym})\s*(?:==|!=)", text)
    )

    bare_p = bool(re.search(rf"(?:==|!=)\s*{p_sym}", text)) or bool(re.search(rf"{p_sym}\s*(?:==|!=)", text))
    bare_r = bool(re.search(rf"(?:==|!=)\s*{r_sym}", text)) or bool(re.search(rf"{r_sym}\s*(?:==|!=)", text))
    return cmp_p, cmp_r, bare_p, bare_r


def pick_option_input(inputs: list[InputCall], pr_prompts: list[tuple[int, str]], code: str) -> Optional[InputCall]:
    if not inputs:
        return None

    prompt_positions = [p for p, _ in pr_prompts]
    best: Optional[InputCall] = None
    best_score = -10**9

    for inp in inputs:
        score = 0
        name_low = inp.var.lower()
        if inp.func == "getchar":
            score += 6
        if inp.fmt:
            fmt_low = inp.fmt.lower()
            if "%c" in fmt_low:
                score += 8
            elif "%s" in fmt_low:
                score += 5
            else:
                score += 1

        if re.search(r"\b(opt|option|choice|select|letter|porr|pr|usr|user|ans|answer)\b", name_low):
            score += 4

        # prefer inputs near a P/R prompt
        if prompt_positions:
            dist = min(abs(inp.pos - pp) for pp in prompt_positions)
            if dist < 600:
                score += 7
            elif dist < 1500:
                score += 3

        # prefer inputs near P/R char literals
        window = code[max(0, inp.pos - 900) : min(len(code), inp.pos + 3200)]
        if pr_char_literals_present(window):
            score += 5
        if re.search(r"payment|rating|ratings", window, flags=re.IGNORECASE):
            score += 1

        if score > best_score:
            best_score = score
            best = inp

    return best


def find_near_pr_prompt(code: str, input_pos: int) -> Optional[str]:
    """Find a nearby P/R prompt string literal before input_pos (best-effort)."""
    lo = max(0, input_pos - 800)
    window = code[lo:input_pos]
    prompts = find_printf_like_calls(window)
    if not prompts:
        return None
    # Prefer the last prompt that actually mentions both P and R.
    for _, lit in reversed(prompts):
        if is_pr_prompt_literal(lit):
            return lit
    return prompts[-1][1]


def find_decl_type(code: str, var: str, around: int) -> Optional[str]:
    """Heuristic: find the nearest primitive declaration of var before around."""
    start = max(0, around - 3000)
    end = min(len(code), around + 200)
    window = code[start:end]

    pattern = re.compile(
        rf"\b(?P<type>unsigned\s+|signed\s+)?(?P<t>int|float|double|char|long|short)\b[^;\n]*\b{re.escape(var)}\b",
        flags=re.IGNORECASE,
    )
    last: Optional[re.Match[str]] = None
    for m in pattern.finditer(window):
        last = m
    if not last:
        return None
    return last.group("t").lower()


def fmt_missing_leading_ws_for_percent_c(fmt: str) -> bool:
    """Return True if the first %c has no whitespace before it in the format string."""
    # Find the first %c (not supporting all scanf modifiers; sufficient for this rubric check).
    idx = fmt.find("%c")
    if idx == -1:
        return False
    if idx == 0:
        return True
    return fmt[idx - 1] not in (" ", "\t", "\n", "\r", "\v", "\f")


@dataclass
class WhileParse:
    cond: str
    body_text: str
    end_pos: int


def parse_while(code: str, while_pos: int) -> Optional[WhileParse]:
    m = re.match(r"\bwhile\b", code[while_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    i = skip_ws(code, while_pos + m.end())
    if i >= len(code) or code[i] != "(":
        return None
    close = find_matching_paren(code, i)
    if close is None:
        return None
    cond = code[i + 1 : close]
    body_text, body_end = parse_statement(code, close + 1)
    return WhileParse(cond=cond, body_text=body_text, end_pos=body_end)


@dataclass
class ForParse:
    header: str
    body_text: str
    end_pos: int


def parse_for(code: str, for_pos: int) -> Optional[ForParse]:
    m = re.match(r"\bfor\b", code[for_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    i = skip_ws(code, for_pos + m.end())
    if i >= len(code) or code[i] != "(":
        return None
    close = find_matching_paren(code, i)
    if close is None:
        return None
    header = code[i + 1 : close]
    body_text, body_end = parse_statement(code, close + 1)
    return ForParse(header=header, body_text=body_text, end_pos=body_end)


@dataclass
class DoWhileParse:
    cond: str
    body_text: str
    end_pos: int


def parse_do_while(code: str, do_pos: int) -> Optional[DoWhileParse]:
    m = re.match(r"\bdo\b", code[do_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    body_text, body_end = parse_statement(code, do_pos + m.end())
    j = skip_ws(code, body_end)
    if not re.match(r"\bwhile\b", code[j:], flags=re.IGNORECASE):
        return None
    j2 = j + re.match(r"\bwhile\b", code[j:], flags=re.IGNORECASE).end()  # type: ignore[union-attr]
    j2 = skip_ws(code, j2)
    if j2 >= len(code) or code[j2] != "(":
        return None
    close = find_matching_paren(code, j2)
    if close is None:
        return None
    cond = code[j2 + 1 : close]
    # Consume trailing ';' if present
    end_pos = close + 1
    end_pos = skip_ws(code, end_pos)
    if end_pos < len(code) and code[end_pos] == ";":
        end_pos += 1
    return DoWhileParse(cond=cond, body_text=body_text, end_pos=end_pos)


@dataclass
class SwitchParse:
    expr: str
    body_text: str
    end_pos: int


def parse_switch(code: str, switch_pos: int) -> Optional[SwitchParse]:
    m = re.match(r"\bswitch\b", code[switch_pos:], flags=re.IGNORECASE)
    if not m:
        return None
    i = skip_ws(code, switch_pos + m.end())
    if i >= len(code) or code[i] != "(":
        return None
    close = find_matching_paren(code, i)
    if close is None:
        return None
    expr = code[i + 1 : close]
    body_text, body_end = parse_statement(code, close + 1)
    return SwitchParse(expr=expr, body_text=body_text, end_pos=body_end)


def contains_input_for_var(text: str, var: str) -> bool:
    # Accept scanf/fscanf/scanf_s and getchar assignment.
    if re.search(rf"\b(?:scanf|scanf_s|fscanf)\s*\([^;\)]*\b{re.escape(var)}\b", text, flags=re.IGNORECASE):
        return True
    if re.search(rf"\b{re.escape(var)}\b\s*=\s*getchar\s*\(", text):
        return True
    return False


def contains_pr_compare(text: str, var: str) -> bool:
    cmp_p, cmp_r, _, _ = pr_compare_flags(text, var)
    return cmp_p and cmp_r


def loop_validation_present(section: str, var: str) -> bool:
    """Detect a loop that reads the option and checks for P/R validity."""

    for m in re.finditer(r"\b(do|while|for)\b", section, flags=re.IGNORECASE):
        kw = m.group(1).lower()
        pos = m.start()
        parsed = None
        if kw == "while":
            parsed = parse_while(section, pos)
            if parsed is None:
                continue
            cond = parsed.cond
            body = parsed.body_text
        elif kw == "for":
            parsed_f = parse_for(section, pos)
            if parsed_f is None:
                continue
            cond = parsed_f.header
            body = parsed_f.body_text
        else:  # do
            parsed_d = parse_do_while(section, pos)
            if parsed_d is None:
                continue
            cond = parsed_d.cond
            body = parsed_d.body_text

        if not contains_input_for_var(body, var):
            continue

        any_p_c, any_r_c, _, _ = pr_any_compare_flags(cond)
        any_p_b, any_r_b, _, _ = pr_any_compare_flags(body)

        # If either the loop condition or body contains comparisons to BOTH P and R, treat as loop validation.
        # (Even if the student mistyped the variable name in part of the condition, that's a rubric minor.)
        if (any_p_c and any_r_c) or (any_p_b and any_r_b) or ((any_p_c or any_p_b) and (any_r_c or any_r_b)):
            return True

        # Some students write malformed conditions like: while (option!='P' && 'R')
        # which still clearly targets the P/R validation. Count it as an attempt (rubric minor elsewhere).
        if pr_char_literals_present(cond):
            return True

        # Also accept switch(var) with a default inside a loop (default handles invalid input).
        for sm in re.finditer(r"\bswitch\b", body, flags=re.IGNORECASE):
            sp = parse_switch(body, sm.start())
            if sp is None:
                continue
            if not re.search(rf"\b{re.escape(var)}\b", sp.expr):
                continue
            if re.search(r"\bdefault\s*:", sp.body_text, flags=re.IGNORECASE):
                return True

    return False


def branch_error_check_present(section: str, var: str) -> bool:
    """Detect non-loop error checking (branching) for invalid P/R."""

    # Single-condition invalid/valid check using both P and R
    for m in re.finditer(r"\bif\b\s*\(", section, flags=re.IGNORECASE):
        open_p = section.find("(", m.start())
        if open_p == -1:
            continue
        close_p = find_matching_paren(section, open_p)
        if close_p is None:
            continue
        cond = section[open_p + 1 : close_p]
        any_p, any_r, _, _ = pr_any_compare_flags(cond)
        if any_p and any_r:
            return True

    # else-if chain with a final else (accept bare P/R identifier mistakes)
    if re.search(
        rf"\bif\s*\([^\)]*\b{re.escape(var)}\b[^\)]*(?:'[Pp]'|\bP\b)[^\)]*\)"  # if (..var..P..)
        rf"[\s\S]{{0,1200}}\belse\s+if\s*\([^\)]*\b{re.escape(var)}\b[^\)]*(?:'[Rr]'|\bR\b)[^\)]*\)"  # else if (..var..R..)
        rf"[\s\S]{{0,800}}\belse\b",
        section,
        flags=re.IGNORECASE,
    ):
        return True
    if re.search(
        rf"\bif\s*\([^\)]*\b{re.escape(var)}\b[^\)]*(?:'[Rr]'|\bR\b)[^\)]*\)"
        rf"[\s\S]{{0,1200}}\belse\s+if\s*\([^\)]*\b{re.escape(var)}\b[^\)]*(?:'[Pp]'|\bP\b)[^\)]*\)"
        rf"[\s\S]{{0,800}}\belse\b",
        section,
        flags=re.IGNORECASE,
    ):
        return True

    # switch(var) with a default (parse body to avoid false positives)
    for sm in re.finditer(r"\bswitch\b", section, flags=re.IGNORECASE):
        sp = parse_switch(section, sm.start())
        if sp is None:
            continue
        if not re.search(rf"\b{re.escape(var)}\b", sp.expr):
            continue
        if re.search(r"\bdefault\s*:", sp.body_text, flags=re.IGNORECASE):
            return True

    return False


def content_typo_present(prompt: str) -> bool:
    # Catch a small set of common typos; rubric says any content-related typo.
    return bool(
        re.search(
            r"payement|paymet|paymen\b|raings|raitings|ratngs|ratiings|ratigns|rattings|paymant|paymnet",
            prompt,
            flags=re.IGNORECASE,
        )
    )


def symbol_declared(code: str, name: str) -> bool:
    # Macro
    if re.search(rf"^\s*#\s*define\s+{re.escape(name)}\b", code, flags=re.MULTILINE):
        return True
    # Primitive declaration (including const)
    if re.search(
        rf"\b(?:const\s+)?(?:unsigned\s+|signed\s+)?(?:int|float|double|char|long|short)\b[^;\n]*\b{re.escape(name)}\b",
        code,
        flags=re.IGNORECASE,
    ):
        return True
    return False


def analyze_problem3(code: str) -> tuple[list[str], list[str]]:
    majors: list[str] = []
    minors: list[str] = []

    code_nc = strip_c_comments(code)

    prompts = find_printf_like_calls(code_nc)
    pr_prompts = [(p, s) for p, s in prompts if is_pr_prompt_literal(s)]
    inputs = find_input_calls(code_nc)
    opt_inp = pick_option_input(inputs, pr_prompts, code_nc)

    if opt_inp is None:
        if not pr_prompts:
            majors.append("Did not ask for user choice (missing printf AND scanf).")
            return list(dict.fromkeys(majors)), list(dict.fromkeys(minors))
        # Prompt exists but no input detected (rare); treat as minor.
        minors.append("Did not ask for user choice (missing scanf/getchar).")
        return list(dict.fromkeys(majors)), list(dict.fromkeys(minors))

    # Analyze a local window around the option input.
    win_start = max(0, opt_inp.pos - 3500)
    win_end = min(len(code_nc), opt_inp.pos + 9000)
    section = code_nc[win_start:win_end]

    near_prompt = find_near_pr_prompt(code_nc, opt_inp.pos)
    if near_prompt is None:
        minors.append("Content-related issue (missing prompt for P/R option).")
    else:
        if not is_pr_prompt_literal(near_prompt):
            minors.append("Content-related typo (prompt does not clearly mention both P and R).")
        if content_typo_present(near_prompt):
            minors.append("Content-related typo (prompt typo).")

    # Variable declaration + type
    decl_type = find_decl_type(code_nc, opt_inp.var, opt_inp.pos)
    if decl_type is None:
        minors.append("Used var not declared (P/R option variable).")
    else:
        # If they scan %c or use getchar, expected a char variable.
        expects_char = opt_inp.func == "getchar" or (opt_inp.fmt is not None and "%c" in opt_inp.fmt.lower())
        if expects_char and decl_type != "char":
            minors.append("Wrong data type used (P/R option should be char).")

    # Missing leading space before %c in scanf format
    if opt_inp.fmt and "%c" in opt_inp.fmt.lower():
        if fmt_missing_leading_ws_for_percent_c(opt_inp.fmt):
            minors.append("Missing space for %c in scanf.")

    # If they compare against bare identifiers P/R (instead of 'P'/'R'), count as minor when undeclared.
    bare_p = bool(re.search(rf"\b{re.escape(opt_inp.var)}\b\s*(?:==|!=)\s*\bP\b", section)) or bool(
        re.search(rf"\bP\b\s*(?:==|!=)\s*\b{re.escape(opt_inp.var)}\b", section)
    )
    bare_r = bool(re.search(rf"\b{re.escape(opt_inp.var)}\b\s*(?:==|!=)\s*\bR\b", section)) or bool(
        re.search(rf"\bR\b\s*(?:==|!=)\s*\b{re.escape(opt_inp.var)}\b", section)
    )
    bare_case = bool(re.search(r"\bcase\s+P\s*:", section)) or bool(re.search(r"\bcase\s+R\s*:", section))
    if (bare_p or bare_r or bare_case) and not (symbol_declared(code_nc, "P") and symbol_declared(code_nc, "R")):
        minors.append("Used var not declared (P/R constants).")

    has_loop = loop_validation_present(section, opt_inp.var)
    has_branch = branch_error_check_present(section, opt_inp.var)

    # If the section compares to both P and R but the chosen option variable itself isn't
    # compared against both, it's commonly a mistyped/undeclared variable in the check.
    any_p, any_r, _, _ = pr_any_compare_flags(section)
    var_p, var_r, _, _ = pr_compare_flags(section, opt_inp.var)
    if (any_p and any_r) and not (var_p and var_r):
        minors.append("Used var not declared (option check variable).")

    if not has_loop and not has_branch:
        majors.append("No error checking included.")
    elif not has_loop and has_branch:
        minors.append("Error checking with branching instead of looping.")

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
    return 6.25, "No rubric errors detected in problem 3 block."


def next_out_path() -> Path:
    base = Path("problem3.csv")
    if not base.exists():
        return base
    i = 2
    while True:
        p = Path(f"problem3_{i}.csv")
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
            majors, minors = analyze_problem3(read_text(p))
            score, reason = grade(majors, minors)
            if score in (0.0, 5.0):
                score_out: str | float = int(score)
            else:
                score_out = score
            w.writerow([p.name, score_out, reason])
            print(f"Graded {p.name}: {score_out} — {reason}")

    print("Wrote", out_path)


if __name__ == "__main__":
    main()
