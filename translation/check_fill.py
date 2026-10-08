#!/usr/bin/env python3
"""Check a fill file (KEY<TAB>dutch per line) without writing any TSV.

    check_fill.py batch.txt

Runs the same checks as check.py (characters, control codes, line widths) on
each line, against the English of that key. Exits non-zero on any problem, and
reports unknown keys and duplicate keys.
"""
import re
import sys

from check import problems
from common import KINDS, SPECS, TSV_DIR, read_tsv


def tsv_kinds():
    """Map TSV name (or `prefix/` for glob specs) to its Kind."""
    out = {}
    for s in SPECS:
        name = s.tsv.split("{")[0] if "{" in s.tsv else s.tsv
        out.setdefault(name, KINDS[s.kind])
    return out


def main():
    kinds = tsv_kinds()
    rows = {}
    for p in sorted(TSV_DIR.rglob("*.tsv")):
        name = p.relative_to(TSV_DIR).with_suffix("").as_posix()
        kind = kinds.get(name) or kinds.get(name.split("/")[0] + "/")
        if kind is None:
            continue  # misc.tsv and other notes-only tables
        for r in read_tsv(name):
            rows[r["key"]] = (name, r, kind)

    bad = 0
    seen = set()
    for n, line in enumerate(open(sys.argv[1], encoding="utf-8"), 1):
        line = line.rstrip("\n")
        if not line or line.startswith("#"):
            continue
        if "\t" not in line:
            print(f"line {n}: no TAB between key and text")
            bad += 1
            continue
        key, text = line.split("\t", 1)
        if key in seen:
            print(f"line {n}: duplicate key {key}")
            bad += 1
        seen.add(key)
        if key not in rows:
            print(f"line {n}: unknown key {key}")
            bad += 1
            continue
        name, row, kind = rows[key]
        m = re.search(r"max:(\d+)", row.get("notes", ""))
        skip = "width-ok" in row.get("notes", "")
        for p in problems(text, kind, row["english"], skip, int(m[1]) if m else None):
            print(f"line {n}: {key}: {p}\n    {text}")
            bad += 1
    print(f"{len(seen)} lines checked, {bad} problems")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
