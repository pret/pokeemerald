#!/usr/bin/env python3
"""Mark every string that currently triggers a narrow-window WARN as reviewed.

Run this only after checking each warning by hand: it adds `label-ok: reviewed`
to the notes column of those rows in strings.tsv.
"""
import subprocess
import sys

from common import read_tsv, write_tsv

out = subprocess.run([sys.executable, __file__.replace("review.py", "check.py")],
                     capture_output=True, text=True).stdout
keys = {line.split()[2].rstrip(":") for line in out.splitlines() if line.startswith("WARN")}
rows = read_tsv("strings")
for r in rows:
    if r["key"] in keys:
        r["notes"] = (r["notes"] + "; " if r["notes"] else "") + "label-ok: reviewed"
write_tsv("strings", rows)
print(f"marked {len(keys)} strings as reviewed")
