from itertools import chain

import glob
import os
import re
import shutil

item_to_ball = {
    "ITEM_STRANGE_BALL": "BALL_STRANGE",
    "ITEM_POKE_BALL": "BALL_POKE",
    "ITEM_GREAT_BALL": "BALL_GREAT",
    "ITEM_ULTRA_BALL": "BALL_ULTRA",
    "ITEM_MASTER_BALL": "BALL_MASTER",
    "ITEM_PREMIER_BALL": "BALL_PREMIER",
    "ITEM_HEAL_BALL": "BALL_HEAL",
    "ITEM_NET_BALL": "BALL_NET",
    "ITEM_NEST_BALL": "BALL_NEST",
    "ITEM_DIVE_BALL": "BALL_DIVE",
    "ITEM_DUSK_BALL": "BALL_DUSK",
    "ITEM_TIMER_BALL": "BALL_TIMER",
    "ITEM_QUICK_BALL": "BALL_QUICK",
    "ITEM_REPEAT_BALL": "BALL_REPEAT",
    "ITEM_LUXURY_BALL": "BALL_LUXURY",
    "ITEM_LEVEL_BALL": "BALL_LEVEL",
    "ITEM_LURE_BALL": "BALL_LURE",
    "ITEM_MOON_BALL": "BALL_MOON",
    "ITEM_FRIEND_BALL": "BALL_FRIEND",
    "ITEM_LOVE_BALL": "BALL_LOVE",
    "ITEM_FAST_BALL": "BALL_FAST",
    "ITEM_HEAVY_BALL": "BALL_HEAVY",
    "ITEM_DREAM_BALL": "BALL_DREAM",
    "ITEM_SAFARI_BALL": "BALL_SAFARI",
    "ITEM_SPORT_BALL": "BALL_SPORT",
    "ITEM_PARK_BALL": "BALL_PARK",
    "ITEM_BEAST_BALL": "BALL_BEAST",
    "ITEM_CHERISH_BALL": "BALL_CHERISH",
}

INCFILE_CREATEMON_PAT = re.compile(r"\s*(createmon|givemon)")
BALL_ARG_PAT = re.compile(r"ball=(\w+)")
ARG_PAT = re.compile(r"[A-Z_]+")

def parse_createmon(line, command):
    ball_arg = BALL_ARG_PAT.search(line)
    if ball_arg:
        item = ball_arg.group(1)
        if item not in item_to_ball:
            print("unrecognized item:" + item)
            quit()
        return line.replace(item, item_to_ball[item])
    args = line.split(',')
    if command == "createmon":
        arg_num = 5
    else:
        arg_num = 3
    if len(args) < (arg_num + 1):
        return line
    arg = ARG_PAT.match(args[arg_num].strip())
    if arg:
        item = arg.group(0)
        if item not in item_to_ball:
            print("unrecognized item:" + item)
            quit()
        return line.replace(item, item_to_ball[item])
    return line


for inc_fname in chain(glob.glob("./data/scripts/*.inc"), glob.glob("./data/maps/*/scripts.inc")):
    new_lines = []
    with open(inc_fname, "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            command = INCFILE_CREATEMON_PAT.search(line)
            if command:
                #print(inc_fname, line)
                new_line = parse_createmon(line, command.group(0))
                new_lines.append(new_line)
            else:
                new_lines.append(line)
    with open(inc_fname, 'w+') as file:
        for line in new_lines:
            file.write(line)
