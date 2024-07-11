import re
import glob

eggMoveSpecies = []

exceptions = [ # the following exceptions are hardcoded to streamline the process. you may need to manually check what happens in case you have added forms that work similar to these below
    ["ShellosWestSea", "Shellos"],
    ["OricorioBaile", "Oricorio"]
]

# convert egg_moves.h to the new format
with open("src/data/pokemon/egg_moves.h", "r") as f:
    data = f.read()

data = re.sub(r"#define(.|\n)*const u16 gEggMoves\[\] = {", "static const u16 sNoneEggMoveLearnset[] = {\n    MOVE_UNAVAILABLE,\n};\n", data) # remove and replace header
data = re.sub(r"\n    EGG_MOVES_TERMINATOR\n};\n\n", "", data) # remove footer

for mon in re.findall(r"egg_moves\((.*),", data):
    monname = re.sub(r"_", " ", mon).title().replace(" ", "")
    for x in exceptions:
        if monname == x[0]:
            monname = x[1]
    # add it to the list for later
    eggMoveSpecies.append(monname)
    # regex the egg_moves.h file
    data = re.sub(r"    egg_moves\(" + mon + r",", "static const u16 s%sEggMoveLearnset[] = {" % monname, data)

data = re.sub(r"\),\n", ",\n        MOVE_UNAVAILABLE,\n};\n", data) # add terminator to each old macro

data = re.sub(r"        MOVE_", "    MOVE_", data) # fix indentation

with open("src/data/pokemon/egg_moves.h", "w") as f:
    f.write(data)

# update gBaseStats

for file in glob.glob('./src/data/pokemon/species_info/gen_*_families.h'):
    with open(file, "r") as f:
        data = f.read()

    # go through all Pokemon with teachable learnsets that are also in the list, then assign egg moves to them
    for mon in eggMoveSpecies:
        # first do the plain replacements outside of macros
        data = re.sub(r"\.teachableLearnset = s" + mon + r"sTeachableLearnset,\n", ".teachableLearnset = s%sTeachableLearnset,\n        .eggMoveLearnset = s%sEggMoveLearnset,\n" % (mon, mon), data)
        # check for macros (since they require \ at the end of the line and do those manually)
        macrocheck = re.findall(r"\.teachableLearnset = s" + mon + r"TeachableLearnset,( *)\\\\", data)
        if len(macrocheck) > 0:
            data = re.sub(r"\.teachableLearnset = s" + mon + r"TeachableLearnset," + macrocheck[0] + r"\\\\", ".teachableLearnset = s%sTeachableLearnset,%s\\\\\n        .eggMoveLearnset = s%sEggMoveLearnset,%s\\\\" % (mon, macrocheck[0], mon, " " * (len(macrocheck[0]) + 4)), data)

    with open(file, "w") as f:
        f.write(data)
