#!/usr/bin/env python3
"""Write the TSV glossaries into the source files.

Each managed string becomes its `dutch` cell, or its `english` cell when the
Dutch one is empty, so clearing a cell and re-applying reverts it.
"""
from common import ROOT, SPECS, read_tsv, scan, text_to_body


def main():
    by_path = {}
    tsvs = {}
    for spec in SPECS:
        for e in scan(spec):
            if e.tsv not in tsvs:
                tsvs[e.tsv] = {r["key"]: r for r in read_tsv(e.tsv)}
            r = tsvs[e.tsv].get(e.key)
            if r:
                by_path.setdefault(e.path, []).append((e, r["dutch"] or r["english"]))

    for path, items in by_path.items():
        file = ROOT / path
        src = file.read_text(encoding="utf-8")
        changed = 0
        for e, text in sorted(items, key=lambda x: x[0].start, reverse=True):
            if text == e.text:
                continue
            body = text_to_body(text, src[e.start:e.end], e.spec.style)
            src = src[:e.start] + body + src[e.end:]
            changed += 1
        if changed:
            file.write_text(src, encoding="utf-8")
        if changed:
            print(f"{path}: {changed} strings updated")


if __name__ == "__main__":
    main()
