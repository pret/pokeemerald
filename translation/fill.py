#!/usr/bin/env python3
"""Fill `dutch` cells from a simple text file:  KEY<TAB>dutch text  per line.

    fill.py abilities batch.txt
    fill.py 'maps/*' batch.txt      search the keys in every matching TSV

Keys not found are reported. Lines starting with # are ignored.
"""
import sys

from common import TSV_DIR, read_tsv, write_tsv


def main():
    pattern, path = sys.argv[1], sys.argv[2]
    names = [p.relative_to(TSV_DIR).with_suffix("").as_posix()
             for p in sorted(TSV_DIR.glob(f"{pattern}.tsv"))]
    tables = {n: read_tsv(n) for n in names}
    where = {r["key"]: (n, r) for n, rows in tables.items() for r in rows}
    touched, n = set(), 0
    for line in open(path, encoding="utf-8"):
        line = line.rstrip("\n")
        if not line or line.startswith("#"):
            continue
        key, text = line.split("\t", 1)
        if key not in where:
            print(f"unknown key: {key}")
            continue
        name, row = where[key]
        row["dutch"] = text
        touched.add(name)
        n += 1
    for name in touched:
        write_tsv(name, tables[name])
    print(f"{n} cells filled in {len(touched)} TSV file(s)")


if __name__ == "__main__":
    main()
