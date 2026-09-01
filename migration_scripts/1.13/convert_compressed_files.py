import glob
import re
import os
from pathlib import Path

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

primaryTileset_pattern = re.compile(r"(.*\"data/tilesets/primary/.+\.4bpp\.)lz(\".*)")
secondaryTileset_pattern = re.compile(r"(.*\"data/tilesets/secondary/.+\.4bpp\.)lz(\".*)")
tilemap_pattern = re.compile(r"(.*\"graphics/.+\.bin\.)(?:lz|rl)(\".*)")
lzuncomp_pattern = re.compile(r"(.*)\bLZ77UnComp([WV])ram\b(\(.*)")
lzdecomp_pattern = re.compile(r"(.*)\bLZDecompress([WV])ram\b(\(.*)")
rluncomp_pattern = re.compile(r"(.*)\bRLUnComp([WV])ram\b(\(.*)")

def handle_file(fileInput):
    fileTest = Path(fileInput)
    if not fileTest.is_file():
        return False
    allLines = list()
    with open(fileInput, 'r', encoding='UTF-8') as file:
        has_decompress_h = False
        needs_decompress_h = False

        while line:=file.readline():
            if line.strip() == "#include \"decompress.h\"":
                has_decompress_h = True
            elif match := secondaryTileset_pattern.match(line):
                line = match.group(1) + "fastSmol" + match.group(2) + "\n"
            elif match := primaryTileset_pattern.match(line):
                line = match.group(1) + "smol" + match.group(2) + "\n"
            elif match := tilemap_pattern.match(line):
                line = match.group(1) + "smolTM" + match.group(2) + "\n"
            elif ".4bpp.lz" in line:
                line = line.replace(".4bpp.lz", ".4bpp.smol")
            elif ".4bpp.rl" in line:
                line = line.replace(".4bpp.rl", ".4bpp.smol")
            elif ".8bpp.lz" in line:
                line = line.replace(".8bpp.lz", ".8bpp.smol")
            elif ".8bpp.rl" in line:
                line = line.replace(".8bpp.rl", ".8bpp.smol")
            elif match := lzuncomp_pattern.match(line):
                if allLines[-1].strip() != "case MODE_LZ77:": # do not modify DecompressDataWithHeader itself
                    line = match.group(1) + "DecompressDataWithHeader" + match.group(2) + "ram" + match.group(3) + "\n"
                    needs_decompress_h = True
            elif match := lzdecomp_pattern.match(line):
                line = match.group(1) + "DecompressDataWithHeader" + match.group(2) + "ram" + match.group(3) + "\n"
                needs_decompress_h = True
            elif match := rluncomp_pattern.match(line):
                line = match.group(1) + "DecompressDataWithHeader" + match.group(2) + "ram" + match.group(3) + "\n"
                needs_decompress_h = True
            else:
                pass

            allLines.append(line)

        if needs_decompress_h and not has_decompress_h:
            # attempt to place the new header in alphabetical order
            i = 0
            while not allLines[i].startswith("#include \"") or allLines[i] == "#include \"global.h\"\n":
                i += 1
            while allLines[i].startswith("#include \"") and allLines[i] < "#include \"decompress.h\"\n":
                i += 1
            allLines.insert(i, "#include \"decompress.h\"\n")

    with open(fileInput, 'w', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)
    return True

for path in glob.glob("src/**/*.c", recursive=True):
    handle_file(path)
for path in glob.glob("src/**/*.h", recursive=True):
    handle_file(path)
