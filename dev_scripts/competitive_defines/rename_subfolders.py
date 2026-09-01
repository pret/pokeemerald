import glob
import re
import json
import os
import subprocess

def rename_subdirs(rootDir, old, new):
    for root, dirs, files in os.walk(rootDir):
        for name in files:
            originalName = os.path.join(root, name)
            if root.endswith(old) and os.path.isfile(originalName):
                newName = originalName.replace(old + '/', new + '/')
                print(originalName + " -> " + newName)
                if (not os.path.isdir(root.replace(old, '') + new)):
                    os.mkdir(root.replace(old, '') + new)
                os.rename(originalName, newName)

rename_subdirs("graphics/pokemon", '/alolan', "/alola")
rename_subdirs("graphics/pokemon", '/galarian', "/galar")
rename_subdirs("graphics/pokemon", '/hisuian', "/hisui")
rename_subdirs("graphics/pokemon", '/gigantamax', "/gmax")
