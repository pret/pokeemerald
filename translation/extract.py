#!/usr/bin/env python3
"""Refresh the `english` column of translation/nl/*.tsv from the source files.

Existing `dutch` and `notes` cells are kept. The english text is taken from the
source only when the file still holds English (no Dutch applied yet); after
apply.py has run, the english column already in the TSV is kept.
"""
from common import SPECS, read_tsv, scan, write_tsv


def main():
    by_tsv = {}
    for spec in SPECS:
        by_tsv.setdefault(spec.tsv, []).extend(scan(spec))

    for name, entries in by_tsv.items():
        old = {r["key"]: r for r in read_tsv(name)}
        rows = []
        for e in entries:
            r = old.get(e.key, {})
            applied = r.get("dutch") and e.text == r["dutch"]
            rows.append({
                "key": e.key,
                "english": r["english"] if applied else e.text,
                "dutch": r.get("dutch", ""),
                "notes": r.get("notes", ""),
            })
        write_tsv(name, rows)
        done = sum(1 for r in rows if r["dutch"])
        print(f"{name}.tsv: {len(rows)} rows, {done} translated")


if __name__ == "__main__":
    main()
