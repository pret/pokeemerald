import glob
import re
import json
import os
import subprocess

# THIS IS A TEMPORARY SCRIPT MADE TO MOVE EXISTING FOLLOWER GRAPHICS FROM A SINGLE DIRECTORY.
# IT TAKES FOLLOWER GRAPHICS FROM a 'followers' FOLDER IN THE ROOT FOLDER AND MOVES THEM BASED ON THEIR NAME.
# EG. 'followers/bulbasaur.png' WILL BE MOVED to 'graphics/pokemon/bulbasaur/follower.png'.
#
# I'M SAVING IT HERE IN CASE IT'S NEEDED SOMEWHERE IN THE FUTURE, THOUGH TWEAKING MIGHT BE NEEDED.
# - AsparagusEduardo

def rename_files():
    dict_out = {}
    count = 0
    for pth in sorted(glob.glob('data/maps/*/text.inc')):
        name = pth.replace("data/maps/", "").replace("/text.inc", "")
        count+=1
        print(name)

        os.rename('data/maps/' + name + '/text.inc', 'data/maps/' + name + '/text_es.inc')

rename_files()
