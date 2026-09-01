import re
import os
import shutil

item_to_ball = {
    "ITEM_STRANGE_BALL": "Strange",
    "ITEM_POKE_BALL": "Poke",
    "ITEM_GREAT_BALL": "Great",
    "ITEM_ULTRA_BALL": "Ultra",
    "ITEM_MASTER_BALL": "Master",
    "ITEM_PREMIER_BALL": "Premier",
    "ITEM_HEAL_BALL": "Heal",
    "ITEM_NET_BALL": "Net",
    "ITEM_NEST_BALL": "Nest",
    "ITEM_DIVE_BALL": "Dive",
    "ITEM_DUSK_BALL": "Dusk",
    "ITEM_TIMER_BALL": "Timer",
    "ITEM_QUICK_BALL": "Quick",
    "ITEM_REPEAT_BALL": "Repeat",
    "ITEM_LUXURY_BALL": "Luxury",
    "ITEM_LEVEL_BALL": "Level",
    "ITEM_LURE_BALL": "Lure",
    "ITEM_MOON_BALL": "Moon",
    "ITEM_FRIEND_BALL": "Friend",
    "ITEM_LOVE_BALL": "Love",
    "ITEM_FAST_BALL": "Fast",
    "ITEM_HEAVY_BALL": "Heavy",
    "ITEM_DREAM_BALL": "Dream",
    "ITEM_SAFARI_BALL": "Safari",
    "ITEM_SPORT_BALL": "Sport",
    "ITEM_PARK_BALL": "Park",
    "ITEM_BEAST_BALL": "Beast",
    "ITEM_CHERISH_BALL": "Cherish",
}

def make_backup_files(files):
    for file in files:
        backup = os.path.basename(file) + ".backup"
        if not os.path.isfile(backup):
            print("Creating backup for " + file)
            shutil.copy2(file, backup, follow_symlinks=True)

def parse_ball(line):
    line = line.removeprefix("Ball:").strip()
    item = "ITEM_"
    for c in line:
        if ('A' <= c and c <= 'Z') or ('0' <= c and c <= '9'):
            item += c
        elif 'a' <= c and c <= 'z':
            item += c.upper()
        elif c == '\'':
            pass
        else:
            item += "_"

    if item not in item_to_ball:
        print("unrecognized pattern:" + item)
        quit()
    return ("Ball: " + item_to_ball[item] + "\n")

def parse_and_change(filepath):
    backup = os.path.basename(filepath) + ".backup"
    allLines = list()
    with open(backup, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if "Ball:" in line:
                allLines.append(parse_ball(line))
            else:
                allLines.append(line)

    with open(filepath, 'w+', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

files = ["src/data/battle_partners.party", "src/data/trainers.party"]
make_backup_files(files)

for file in files:
    parse_and_change(file)

print("Migration complete. You can delete battle_partners.party.backup and trainers.party.backup if things are working properly")
