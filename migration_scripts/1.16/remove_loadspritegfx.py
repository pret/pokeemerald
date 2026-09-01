import glob
import re
import os
from pathlib import Path

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

def remove_loadspritegfx(fileInput):
    fileTest = Path(fileInput)
    if not fileTest.is_file():
        return False
    allLines = list()
    with open(fileInput, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if "unloadspritegfx" in line:
                line2 = file.readline()
                if ("unloadspritepal" in line2):
                    allLines.append(line)
                else:
                    allLines.append(line)
                    tag = line.lstrip().replace("unloadspritegfx", "")
                    line = "\tunloadspritepal" + tag
                    allLines.append(line)

                if not "loadspritegfx" in line2:
                    allLines.append(line2)
            elif not "loadspritegfx" in line:
                allLines.append(line)

    with open(fileInput, 'w', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)

remove_loadspritegfx("data/battle_anim_scripts.s")
