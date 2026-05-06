#!/usr/bin/env python3
import re
from pathlib import Path

OUT = Path('intro_statement_problem1.csv')
DIR = Path('final')

def read(p):
    return p.read_text(errors='ignore')

def find_decls(text):
    decls = set()
    for m in re.finditer(r'\bFILE\s*\*\s*(\w+)', text):
        decls.add(m.group(1))
    for m in re.finditer(r'\b(int|double|char|float|long)\s+(\w+)', text):
        decls.add(m.group(2))
    return decls

def analyze(text):
    minors = []
    majors = []

    # fopen detection
    fopen_calls = list(re.finditer(r'fopen\s*\(\s*([^,]+)\s*,\s*([^\)]+)\)', text))
    if not fopen_calls:
        majors.append('missing fopen')
    else:
        # inspect modes if literal
        for m in fopen_calls:
            mode = m.group(2).strip()
            lit = re.match(r"['\"]([rawb+t]+)['\"]", mode)
            if lit:
                mm = lit.group(1)
                if 'r' in mm or 'a' in mm:
                    minors.append(f'fopen mode {mm} (should be w)')

    # fprintf detection
    fprintfs = list(re.finditer(r'fprintf\s*\(\s*([^,\)]+)\s*,', text))
    if not fprintfs:
        # no fprintf — major: did not print to file / missing fprintf
        majors.append('missing fprintf (no printing to file)')
    else:
        decls = find_decls(text)
        for f in fprintfs:
            first = f.group(1).strip()
            # fprintf("..."  -> missing fp
            if re.match(r"^['\"]", first):
                minors.append('missing fp inside fprintf')
            else:
                # check declared
                name = re.match(r'([A-Za-z_][A-Za-z0-9_]*)', first)
                if name:
                    var = name.group(1)
                    if var not in decls:
                        minors.append(f'used var not declared: {var}')

    # fclose
    if not re.search(r'fclose\s*\(', text):
        minors.append('did not fclose')

    # content-typo heuristics: look for 'intro' in string literals
    string_literals = re.findall(r'"([^\"]+)"', text)
    intro_found = any(re.search(r'intro|introduct|introduction', s, re.IGNORECASE) for s in string_literals)
    if not intro_found:
        # Not necessarily major if they used different text; don't mark major, mark minor as potential typo/missing text
        minors.append('intro statement not found in string literals')

    # collapse duplicates
    minors = list(dict.fromkeys(minors))
    majors = list(dict.fromkeys(majors))
    return majors, minors

def grade(majors, minors):
    if majors or len(minors) > 3:
        return 0.0, ('major error: ' + '; '.join(majors + minors)) if (majors or minors) else ('major error')
    if 0 < len(minors) <= 3:
        return 5.0, (f'{len(minors)} minor error(s): ' + '; '.join(minors))
    return 6.25, 'meets rubric'

def main():
    files = sorted(DIR.glob('*.c'))
    lines = ['file,score,reason']
    for p in files:
        text = read(p)
        majors, minors = analyze(text)
        score, reason = grade(majors, minors)
        lines.append(f'{p.name},{score:.2f},{reason}')
        print(f'Graded {p.name}: {score:.2f} — {reason}')

    OUT.write_text('\n'.join(lines) + '\n')
    print('Wrote', OUT)

if __name__ == '__main__':
    main()
