#!/usr/bin/env python3
"""Validate the Dutch cells of translation/nl/*.tsv.

Checks characters (charmap.txt), byte length, line count and pixel width per
line. Exits non-zero on any violation.

    check.py               check Dutch cells
    check.py --english     check the English text instead (to calibrate limits)
"""
import re
import sys

import common
from common import KINDS, SPECS, control_codes, encode, line_widths, read_tsv, scan, split_lines


def problems(text, kind, english=None, skip_width=False, max_px=None):
    out = []
    data, errors = encode(text)
    out += errors
    if '"' in text or "\t" in text:
        out.append('contains " or a tab')
    if kind.max_bytes is not None and len(data) > kind.max_bytes:
        out.append(f"{len(data)} bytes > {kind.max_bytes}")
    if english is not None and control_codes(text) != control_codes(english):
        out.append(f"control codes differ from English: {control_codes(english)}")
    for line in split_lines(text):
        for m in re.finditer(r"\{CLEAR_TO (\d+)\}", line):
            w = line_widths(line[:m.start()], "normal")[0]
            if w > int(m[1]):
                out.append(f"text before {{CLEAR_TO {m[1]}}} is {w}px")
    lines = text.count("\\n") + 1
    if lines > kind.max_lines:
        out.append(f"{lines} lines > {kind.max_lines}")
    limits = [("normal", max_px, "window from notes")] if max_px else kind.limits
    for font, max_px, where in ([] if skip_width else limits):
        for i, w in enumerate(line_widths(text, font), 1):
            if w > max_px:
                out.append(f"line {i} is {w}px > {max_px}px ({where})")
    return out


def warn_label(key, text, english):
    """Narrow English text often sits in a small window: flag Dutch that is wider."""
    en, nl = max(line_widths(english, "normal")), max(line_widths(text, "normal"))
    if en <= 130 and nl > en:
        print(f"WARN strings.tsv  {key}: {nl}px wider than English {en}px\n    {english} -> {text}")


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
            m = re.search(r"max:(\d+)", row.get("notes", ""))
            if spec.kind == "ui" and english and column == "dutch" and not skip \
                    and "label-ok" not in row.get("notes", ""):
                warn_label(e.key, text, english)
            for p in problems(text, kind, english, skip, int(m[1]) if m else None):
                bad += 1
                print(f"{spec.tsv}.tsv  {e.key}: {p}\n    {text}")
    if column == "english":
        for k, (w, t) in widest.items():
            print(f"widest {k}: {w}px  {t}")
    print(f"{checked} strings checked, {bad} problems")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
