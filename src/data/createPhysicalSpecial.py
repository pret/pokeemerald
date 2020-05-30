import json

PHYSICALLITY = ".physicality = "
MOVE_CONST = "MOVE_PHYSICALITY_"
PHYSICAL = "PHYSICAL"
SPECIAL = "SPECIAL"

with open("moves.json","r") as movesfile:
    moves_data = json.load(movesfile)

newBMoves = []

with open("battle_moves.h", "r") as bmovesfile:
    newBMoves.append(bmovesfile.readline())
    newBMoves.append(bmovesfile.readline())
    
    for i in range(0, 355):
        thisMove = bmovesfile.readline()
        newBMoves.append(thisMove)
        thisMove = thisMove.replace("[MOVE_", "")
        thisMove = thisMove.strip()
        thisMove = thisMove.replace("_", "")
        thisMove = thisMove.replace("] =","")
        thisMove.lower()
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
        print(thisMove)
        if thisMove in moves_data:
            print(moves_data[thisMove]["category"])
        thisLine = bmovesfile.readline()
        newBMoves.append(thisLine)
        thisLine = bmovesfile.readline()
        newBMoves.append(thisLine)
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        