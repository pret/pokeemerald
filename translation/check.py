#!/usr/bin/env python3
"""Validate the Dutch cells of translation/nl/*.tsv.

Checks characters (charmap.txt), byte length, line count and pixel width per
line. Exits non-zero on any violation.

    check.py               check Dutch cells
    check.py --english     check the English text instead (to calibrate limits)
"""
import sys

import common
from common import KINDS, SPECS, control_codes, encode, line_widths, read_tsv, scan


def problems(text, kind, english=None, skip_width=False):
    out = []
    data, errors = encode(text)
    out += errors
    if '"' in text or "\t" in text:
        out.append('contains " or a tab')
    if kind.max_bytes is not None and len(data) > kind.max_bytes:
        out.append(f"{len(data)} bytes > {kind.max_bytes}")
    if english is not None and control_codes(text) != control_codes(english):
        out.append(f"control codes differ from English: {control_codes(english)}")
    lines = text.count("\\n") + 1
    if lines > kind.max_lines:
        out.append(f"{lines} lines > {kind.max_lines}")
    for font, max_px, where in ([] if skip_width else kind.limits):
        for i, w in enumerate(line_widths(text, font), 1):
            if w > max_px:
                out.append(f"line {i} is {w}px > {max_px}px ({where})")
    return out


def main():
    column = "english" if "--english" in sys.argv else "dutch"
    if column == "english":
        common.PREFIX = "Wild "  # longest English battle name prefix
    bad = checked = 0
    widest = {}
    for spec in SPECS:
        kind = KINDS[spec.kind]
        rows = {r["key"]: r for r in read_tsv(spec.tsv)}
        for e in scan(spec):
            row = rows.get(e.key, {})
            text = row.get(column, "")
            if not text:
                continue
            checked += 1
            for font, _, where in kind.limits:
                w = max(line_widths(text, font))
                if w > widest.get(where, (0, ""))[0]:
                    widest[where] = (w, text)
            english = row.get("english") if column == "dutch" else None
            skip = "width-ok" in row.get("notes", "")
            for p in problems(text, kind, english, skip):
                bad += 1
                print(f"{spec.tsv}.tsv  {e.key}: {p}\n    {text}")
    if column == "english":
        for k, (w, t) in widest.items():
            print(f"widest {k}: {w}px  {t}")
    print(f"{checked} strings checked, {bad} problems")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
