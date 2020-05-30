import json

PHYSICALLITY = "        .physicality = "
MOVE_CONST = "MOVE_PHYSICALITY_"
PHYSICAL = "PHYSICAL,\n"
SPECIAL = "SPECIAL,\n"
OTHER = "OTHER,\n"

with open("moves.json","r") as movesfile:
    moves_data = json.load(movesfile)

newBMoves = []

with open("battle_moves.OLD.h", "r") as bmovesfile:
    newBMoves.append(bmovesfile.readline())
    newBMoves.append(bmovesfile.readline())
    
    for i in range(0, 355):
        thisMove = bmovesfile.readline()
        newBMoves.append(thisMove)
        thisMove = thisMove.replace("[MOVE_", "")
        thisMove = thisMove.strip()
        thisMove = thisMove.replace("_", "")
        thisMove = thisMove.replace("] =","")
        thisMove = thisMove.lower()
        for j in range(0, 10):
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
            thisLine = bmovesfile.readline()
            newBMoves.append(thisLine)
        # Now add wether move is physical or special
        if thisMove in moves_data:
            physicality = PHYSICALLITY + MOVE_CONST
            move_type = moves_data[thisMove]["category"]
            if move_type == "physical":
                physicality += PHYSICAL
            elif move_type == "special":
                physicality += SPECIAL
            else:
                physicality += OTHER
            newBMoves.append(physicality)
        thisLine = bmovesfile.readline() # },
        newBMoves.append(thisLine)
        thisLine = bmovesfile.readline() # Newline end of move
        newBMoves.append(thisLine)
    newBMoves += bmovesfile.readlines()
        
with open("battle_moves.h", "w") as bmovesfile:
    bmovesfile.writelines(newBMoves)
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        