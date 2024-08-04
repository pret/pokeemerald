import glob
import re
import json
import os
import subprocess

# THIS IS A TEMPORARY SCRIPT MADE TO RENAME FILES WITH THE "FOLLOWER" NAME TO "OVERWORLD",
# AS THESE GRAPHICS CAN ALSO BE USED OUTSIDE THE FOLLOWER FEATURE.
#
# I'M SAVING IT HERE IN CASE IT'S NEEDED SOMEWHERE IN THE FUTURE, THOUGH TWEAKING MIGHT BE NEEDED.
# - AsparagusEduardo

def rename_files(dir, old, new):
    for root, dirs, files in os.walk(dir):
        for name in files:
            if name.endswith(old):
                originalName = os.path.join(root, name)
                newName = originalName.replace(old, new)
                print(originalName + " -> " + newName)
                os.rename(originalName, newName)

rename_files("graphics/pokemon", 'follower.png', "overworld.png")
rename_files("graphics/pokemon", 'follow_normal.pal', "overworld_normal.pal")
rename_files("graphics/pokemon", 'follow_shiny.pal', "overworld_shiny.pal")
