import math

inFile = "battle_anim_scripts.s"
#outFile = "createsprite.txt"
outFile = "battle_anim_scripts.s"

fIN = open(inFile, 'r')

ANIM_BANK_ATTACKER = 0b00000000
ANIM_BANK_TARGET = 0b10000000
ONE = 0b1111111

#
inLines = fIN.readlines()

text = ""

count = 0

uniques = set()

def lsb(n):
    return 0

# createsprite2 gBattleAnimSpriteTemplate_83D96F8, ANIM_BANK_ATTACKER, 40, 200, -32, 0, 100, 0
# createsprite  gBattleAnimSpriteTemplate_83D96F8, 40,                     200, -32, 0, 100, 0

# createsprite2 gBattleAnimSpriteTemplate_83DAC10, ANIM_BANK_ATTACKER, 66, 0
# createsprite  gBattleAnimSpriteTemplate_83DAC10, 66, 0

# line 3891
for line in inLines:
    count += 1
    if (not line.startswith("\tcreatesprite")):# or (count > 500): # 3890 < x < 3899
        text += line

    else:
        split = line.replace(',','').strip().split()
        #print(split[3:-1])

        text += '\t'
        text += "createsprite2 " + split[1] + ', '

        #try:
        combined = int(split[2], 0)
        #except:
        #    combined = int(split[2], 0)

        battler = combined
        uniques.add((battler, battler & ONE))
        #priority = str(lsb(battler))

        if battler & ANIM_BANK_TARGET:
            battler_txt = "ANIM_BANK_TARGET"
            priority_txt = str(battler & ONE)

        else:
            battler_txt = "ANIM_BANK_ATTACKER" #split[2] | battler
            priority_txt = str(battler & ONE)

        text += battler_txt + ', ' + priority_txt + ', '

    # createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
    # createsprite2 gBasicHitSplatSpriteTemplate, ANIM_BANK_ATTACKER, 2, 0, 0, 1, 2

    #    .if battler == ANIM_BANK_TARGET
    #    .byte 0x80 | (subpriority_offset & 0x3F)
    #    .else
    #    .byte (subpriority_offset & 0x3F)

        if len(split) > 3:
            for item in split[3:-1]:
                text += item + ', '
            text += split[-1] + '\n'

        else:
            text = text[:-2] + '\n'

print(uniques)

fOUT = open(outFile, 'w')
fOUT.write(text)

fIN.close()
fOUT.close()
