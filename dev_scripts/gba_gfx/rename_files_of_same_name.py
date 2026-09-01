import glob
import re
import json
import os
import subprocess

def rename_files(dirOld, dirNew, old, new):
    for root, dirs, files in os.walk(dirOld):
        for name in files:
            if name.endswith(old):
                originalName = os.path.join(root, name)
                newName = originalName.replace(old, new)
                newName = newName.replace(dirOld, dirNew)
                print(originalName + " -> " + newName)
                os.rename(originalName, newName)

rename_files("graphics/pokemon_old", "graphics/pokemon", 'anim_front.png', "anim_front_gba.png")
rename_files("graphics/pokemon_old", "graphics/pokemon", 'normal.pal', "normal_gba.pal")
rename_files("graphics/pokemon_old", "graphics/pokemon", 'shiny.pal', "shiny_gba.pal")
rename_files("graphics/pokemon_old", "graphics/pokemon", 'back.png', "back_gba.png")
rename_files("graphics/pokemon_old", "graphics/pokemon", 'icon.png', "icon_gba.png")
rename_files("graphics/pokemon_old", "graphics/pokemon", 'footprint.png', "footprint_gba.png")
