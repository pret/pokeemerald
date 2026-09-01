import glob
import re
import os
from pathlib import Path

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

allPals = list()

def find_pals(fileInput):
    fileTest = Path(fileInput)
    if not fileTest.is_file():
        return False
    with open(fileInput, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if ".gbapal.lz" in line and "u32" in line:
                allPals.append(line)
                line, sep, tail = line.partition("=")
                line, sep, tail = line.partition("[]")
                head, sep, line = line.partition("u32 ")
                allPals.append(line)

def handle_file(fileInput):
    fileTest = Path(fileInput)
    if not fileTest.is_file():
        return False
    allLines = list()
    with open(fileInput, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if "struct CompressedSpritePalette" in line:
                line = line.replace("struct CompressedSpritePalette", "struct SpritePalette")
            elif "LoadCompressedSpritePaletteUsingHeap" in line:
                line = line.replace("LoadCompressedSpritePaletteUsingHeap", "LoadSpritePalette")
            elif "LoadCompressedSpritePaletteWithTag" in line:
                line = line.replace("LoadCompressedSpritePaletteWithTag", "LoadSpritePaletteWithTag")
            elif "LoadCompressedSpritePalette" in line:
                line = line.replace("LoadCompressedSpritePalette", "LoadSpritePalette")
            elif "LoadCompressedPalette" in line:
                line = line.replace("LoadCompressedPalette", "LoadPalette")
            elif "u32" in line:
                for currPal in allPals:
                    if currPal in line:
                        line = line.replace("u32", "u16")
                        if "INCBIN_U32" in line:
                            line = line.replace("INCBIN_U32", "INCBIN_U16")
                            line = line.replace(".lz", "")
                        break
            else:
                pass
            allLines.append(line)

    with open(fileInput, 'w', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)
    return True

for path in glob.glob("src/**/*.c", recursive=True):
    find_pals(path)
for path in glob.glob("src/**/*.h", recursive=True):
    find_pals(path)
for path in glob.glob("include/**/*.h", recursive=True):
    find_pals(path)

for path in glob.glob("src/**/*.c", recursive=True):
    handle_file(path)
for path in glob.glob("src/**/*.h", recursive=True):
    handle_file(path)
for path in glob.glob("include/**/*.h", recursive=True):
    handle_file(path)
