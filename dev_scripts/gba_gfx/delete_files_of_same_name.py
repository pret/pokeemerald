import glob
import re
import json
import os
import subprocess

# THIS IS A TEMPORARY SCRIPT MADE TO DELETE FILES WITH THE "footprint.png" NAME
# FROM THE "graphics/pokemon_old" folder, AS MOST OF THEM ALREADY EXISTED IN "graphics/pokemon".
#
# I'M SAVING IT HERE IN CASE IT'S NEEDED SOMEWHERE IN THE FUTURE, THOUGH TWEAKING MIGHT BE NEEDED.
# - AsparagusEduardo

def rename_files(dir, filename):
    for root, dirs, files in os.walk(dir):
        for name in files:
            if name.endswith(filename):
                fullName = os.path.join(root, name)
                print(fullName + " deleted.")
                os.remove(fullName)

rename_files("graphics/pokemon_old", 'footprint.png')
