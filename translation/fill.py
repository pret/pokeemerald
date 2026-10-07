#!/usr/bin/env python3
"""Fill `dutch` cells from a simple text file:  KEY<TAB>dutch text  per line.

    fill.py abilities batch.txt

Keys not in the TSV are reported. Lines starting with # are ignored.
"""
import sys

from common import read_tsv, write_tsv


def main():
    name, path = sys.argv[1], sys.argv[2]
    rows = read_tsv(name)
    by_key = {r["key"]: r for r in rows}
    n = 0
    for line in open(path, encoding="utf-8"):
        line = line.rstrip("\n")
        if not line or line.startswith("#"):
            continue
        key, text = line.split("\t", 1)
        if key not in by_key:
            print(f"unknown key: {key}")
            continue
        by_key[key]["dutch"] = text
        n += 1
    write_tsv(name, rows)
    print(f"{name}.tsv: {n} cells filled")


if __name__ == "__main__":
    main()
