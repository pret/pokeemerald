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

def rellocate_follower_graphics():
    dict_out = {}
    count = 0
    for pth in sorted(glob.glob('followers/*.png')):
        name = pth.replace(".png", "").replace("followers/", "")
        count+=1
        #if (count == 2):
        #    break
        print(name)
        newname = name
        newname = newname.replace("_female", "/female")
        newname = newname.replace("_hisuian", "/hisuian")
        newname = newname.replace("_galarian", "/galarian")
        newname = newname.replace("_origin", "/origin")
        newname = newname.replace("_therian", "/therian")
        newname = newname.replace("_east_sea", "/east_sea")
        newname = newname.replace("_crowned", "/crowned")

        newname = newname.replace("arceus_", "arceus/")
        newname = newname.replace("burmy_", "burmy/")
        newname = newname.replace("basculin_", "basculin/")
        newname = newname.replace("castform_", "castform/")
        newname = newname.replace("calyrex_", "calyrex/")
        newname = newname.replace("deerling_", "deerling/")
        newname = newname.replace("deoxys_", "deoxys/")
        newname = newname.replace("flabebe_", "flabebe/")
        newname = newname.replace("floette_", "floette/")
        newname = newname.replace("florges_", "florges/")
        newname = newname.replace("furfrou_", "furfrou/")
        newname = newname.replace("hoopa_", "hoopa/")
        newname = newname.replace("lycanroc_", "lycanroc/")
        newname = newname.replace("meloetta_", "meloetta/")
        newname = newname.replace("necrozma_", "necrozma/")
        newname = newname.replace("pichu_", "pichu/")
        newname = newname.replace("rotom_", "rotom/")
        newname = newname.replace("sawsbuck_", "sawsbuck/")
        newname = newname.replace("toxtricity_", "toxtricity/")
        newname = newname.replace("unown_", "unown/")
        newname = newname.replace("ursaluna_", "ursaluna/")
        newname = newname.replace("vivillon_", "vivillon/")
        newname = newname.replace("wormadam_", "wormadam/")

        if (os.path.exists('followers/' + newname) == False):
            os.mkdir('followers/' + newname)
        os.rename('followers/' + name + '.png', 'followers/' + newname + '/follower.png')
        #os.popen('cp followers/' + name + '.png followers/' + name + '/follower.png')
        #os.remove('followers/' + name + '.png')
        #print(pth)
        #subprocess.run(["tools/gbagfx/gbagfx " + name +".png " + name + "_normal.pal'" + str(count) + "'"]) 

rellocate_follower_graphics()
