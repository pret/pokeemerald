import json

PHYSICALLITY = "        .physicality = "
MOVE_CONST = "MOVE_PHYSICALITY_"
PHYSICAL = "PHY"
SPECIAL = "SPE"
OTHER = "STA"

with open("../moves.json","r") as movesfile:
    moves_data = json.load(movesfile)

newBMoves = []

with open("move_descriptions.OLD.h", "r") as bmovesfile:
    newBMoves.append(bmovesfile.readline())
    newBMoves.append(bmovesfile.readline())
    newBMoves.append(bmovesfile.readline())
    
    for i in range(0, 355):
        thisMove = bmovesfile.readline()
        newBMoves.append(thisMove)
        thisMove = thisMove.replace("static const u8 s", "")
        thisMove = thisMove.strip()
        thisMove = thisMove.replace("Description[] = _(","")
        thisMove = thisMove.lower()
        # Now add wether move is physical or special
        if thisMove in moves_data:
            physicality = ''
            move_type = moves_data[thisMove]["category"]
            if move_type == "physical":
                physicality += PHYSICAL
            elif move_type == "special":
                physicality += SPECIAL
            else:
                physicality += OTHER
            #newBMoves.append(physicality+', "\n)
        for j in range(0, 3):
            """
            {
                .effect = EFFECT,
                .power = POWER,
                .type = TYPE,
                .accuracy = ACCURACY,
                .pp = PP,
                .secondaryEffectChance = EFFECT,
                .target = MOVE_TARGET,
                .priority = PRIORITY,
                .flags = FLAGS,
            """
            if j == 1:
                thisLine = bmovesfile.readline()
                print(thisLine)
                thisLine = thisLine.replace('."', ". "+physicality+'"')
            else:
                thisLine = bmovesfile.readline()
            newBMoves.append(thisLine)
    newBMoves += bmovesfile.readlines()
        
with open("move_descriptions.h", "w") as bmovesfile:
    bmovesfile.writelines(newBMoves)