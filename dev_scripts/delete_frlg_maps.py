import json
import os
import re

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

os.system("rm -R data/layouts/*_Frlg")
print("rm -R data/layouts/*_Frlg")
os.system("touch data/layouts/layouts.json")
os.system("rm -R data/maps/*_Frlg")
print("rm -R data/maps/*_Frlg")

fileInput = "data/event_scripts.s"
allLines = list()
print("Deleting FRLG maps from data/event_scripts.s")
with open(fileInput, 'r', encoding='UTF-8') as file:
    while line:=file.readline():
        if re.search(r"data/maps/\w+_Frlg", line):
            pass
        else:
            allLines.append(line)

with open(fileInput, 'w', encoding='UTF-8') as file:
    for line in allLines:
        file.write(line)

fileInput = "data/maps/map_groups.json"
print("Deleting FRLG maps from data/maps/map_groups.json")
with open(fileInput, 'r') as f:
    map_data = json.load(f)

new_group_order = list()
for group in map_data["group_order"]:
    if re.search(r"\w+_Frlg", group):
        map_data.pop(group, None)
    else:
        new_group_order.append(group)

map_data["group_order"] = new_group_order;

with open(fileInput, 'w') as f:
    json.dump(map_data, f, indent=2)
