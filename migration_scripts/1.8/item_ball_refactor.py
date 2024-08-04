import glob
import re
import json
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# scan incs
incs_to_check =    glob.glob('./data/scripts/*.inc') # all .incs in the script folder
incs_to_check +=   glob.glob('./data/maps/*/scripts.inc') # all map scripts
pories_to_check =  glob.glob('./data/scripts/*.pory') ## all .porys in the script folder
pories_to_check += glob.glob('./data/maps/*/scripts.pory') # all map scripts

array = []
array_pories = []

# make a list of which script corresponds to which item
for file in incs_to_check:
    with open(file, "r") as f2:
        raw = f2.read()
    array += re.findall("(.*)::\n[	 ]*finditem (.*)\n[	 ]*end", raw)

# since this doesn't catch poryscript-generated inc files, do the same for poryscript
for file in pories_to_check:
    with open(file, "r") as f2:
        raw = f2.read()
    array_pories += re.findall("script ([\w]*)[	 \n]*\{[	 \n]*finditem\((.*)\)[	 \n]*\}", raw)

dict = {}
# poryscript values are prioritised because they would overwrite inc files anyway if different
for x in array_pories:
    dict[x[0]] = x[1]
for x in array:
    if not x[0] in dict:
        dict[x[0]] = x[1]

# apply changes to inc files
for map in glob.glob('./data/maps/*/map.json'):
    with open(map, "r") as f2:
        data = json.load(f2)
    if not 'object_events' in data:
        continue
    for objevent in data['object_events']:
        if objevent["script"] in dict:
            objevent["trainer_sight_or_berry_tree_id"] = dict[objevent["script"]]
            objevent["script"] = "Common_EventScript_FindItem"
    with open(map, "w") as f2:
        f2.write(json.dumps(data, indent=2) + "\n")

# do another map search to find out which finditem scripts would somehow be still in use
still_in_use = []
for map in glob.glob('./data/maps/*/map.json'):
    with open(map, "r") as f2:
        data = json.load(f2)
    if not 'object_events' in data:
        continue
    for objevent in data['object_events']:
        if objevent["script"] in dict and not objevent["script"] in still_in_use:
            still_in_use.append(objevent["script"])

for x in list(dict.keys()):
    if x in still_in_use:
        del dict[x]

# clean up scripts that are now no longer in use
for file in incs_to_check:
    with open(file, "r") as f2:
        raw = f2.read()
    for unused in list(dict.keys()):
        raw = re.sub("%s::\n[	 ]*finditem (.*)\n[	 ]*end\n*" % unused, "", raw)
    with open(file, "w") as f2:
        f2.write(raw)

# also clean up pory files
for file in pories_to_check:
    with open(file, "r") as f2:
        raw = f2.read()
    for unused in list(dict.keys()):
        raw = re.sub("script %s[	 \n]*\{[	 \n]*finditem\((.*)\)[	 \n]*\}[	 \n]*" % unused, "", raw)
    with open(file, "w") as f2:
        f2.write(raw)
    
print("Done!")
