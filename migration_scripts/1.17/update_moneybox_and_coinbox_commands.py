from itertools import chain

import glob
import os
import re

replacements = [
    [r'updatecoinsbox\s+\d+[,\s]+\d+', 'updatecoinsbox'],
    [r'hidecoinsbox\s+\d+[,\s]+\d+', 'hidecoinsbox'],
]

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

for inc_fname in chain(glob.glob("./data/scripts/*.inc"), glob.glob("./data/maps/*/scripts.inc")):
    new_lines = []
    with open(inc_fname, "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            line = re.sub(r'updatecoinsbox\s+\d+[,\s]+\d+', 'updatecoinsbox', line)
            line = re.sub(r'hidecoinsbox\s+\d+[,\s]+\d+', 'hidecoinsbox', line)
            match = re.search(r'showcoinsbox\s+(\d+)[,\s]+(\d+)', line)
            if match:
                x = int(match.group(1)) - 1
                y = int(match.group(2)) - 1
                line = re.sub(r'showcoinsbox\s+\d+[,\s]+\d+', f"showcoinsbox {x}, {y}", line)
            new_lines.append(line)
    with open(inc_fname, 'w+') as file:
        for line in new_lines:
            file.write(line)