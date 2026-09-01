#!/usr/bin/python3

"""
Checks that all documentation pages that should be mentioned in
`docs/SUMMARY.md` are mentioned the file
"""

import glob
import re
import os
from pathlib import Path

errorLines = []

if not os.path.exists("Makefile"):
    errorLines.append("Please run this script from your root folder.")

summaryFile = Path("docs/SUMMARY.md")
if not errorLines:
    if not summaryFile.is_file():
        errorLines.append("docs/SUMMARY.md missing")

summaryContents = []
if not errorLines:
    with open(summaryFile, 'r', encoding='UTF-8') as file:
        entry_pattern = re.compile(r" *\- \[[^\]]*\]\(([^\)]*)\)\n")
        lineNo = 0
        while line:=file.readline():
            lineNo = lineNo + 1
            if line == "# Summary\n" or line == "\n":
                pass
            elif match:=entry_pattern.match(line):
                if "" != match.group(1):
                    summaryContents.append(Path(match.group(1)))
            else:
                if not errorLines:
                    errorLines.append("## Unexpected lines in docs/SUMMARY.md")
                errorLines.append(f"- {lineNo}: {line.strip()}")

if not errorLines:
    for pathName in glob.glob("**/*.md", root_dir="docs", recursive=True):
        path = Path(pathName)
        if path == Path("SUMMARY.md"):
            pass
        elif path == Path("changelogs/template.md"):
            pass
        elif path in summaryContents:
            pass
        else:
            if not errorLines:
                errorLines.append("## `docs/**/*.md` files present but not mentioned in `docs/SUMMARY.md`")
            errorLines.append("- " + str(path))

if errorLines:
    for line in errorLines:
        print(line)

    if 'GITHUB_STEP_SUMMARY' in os.environ:
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'w', encoding='UTF-8') as file:
            for line in errorLines:
                file.write(line)
                file.write('\n')

    quit(1)
