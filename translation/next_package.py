#!/usr/bin/env python3
"""Print untranslated dialogue as KEY<TAB>english for one package.

    next_package.py '<regex>'          maps/ TSVs whose map name matches, plus
                                       text/trainers keys that match
    next_package.py 'text/tv'          a whole shared-text or script TSV
    next_package.py --summary          untranslated count per map/TSV

The regex is matched against the map name (e.g. LavaridgeTown_Gym_1F) and
against trainer keys in text/trainers.tsv (e.g. Route112_Text_...).
"""
import re
import sys

from common import TSV_DIR, read_tsv


def tables():
    for p in sorted(TSV_DIR.glob("*/*.tsv")):
        yield p.relative_to(TSV_DIR).with_suffix("").as_posix()


def main():
    arg = sys.argv[1]
    if arg == "--summary":
        for name in tables():
            n = sum(1 for r in read_tsv(name) if not r["dutch"])
            if n:
                print(f"{n:5}  {name}")
        return
    if "/" in arg:
        names, rx = [arg], None
    else:
        rx = re.compile(arg)
        names = [n for n in tables() if n.startswith("maps/") and rx.search(n[5:])]
        names.append("text/trainers")
    for name in names:
        for r in read_tsv(name):
            if r["dutch"]:
                continue
            if name == "text/trainers" and rx and not rx.search(r["key"]):
                continue
            print(f"{r['key']}\t{r['english']}")


if __name__ == "__main__":
    main()
