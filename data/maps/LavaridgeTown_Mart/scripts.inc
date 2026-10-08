LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Gebruik X SNELHEID om de\n"
	.string "SNELHEID van een POKéMON te\l"
	.string "verhogen in een gevecht.\p"
	.string "Dan kan hij als eerste aanvallen,\n"
	.string "en dat is een groot voordeel!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Op de top van MT. CHIMNEY is\n"
	.string "een speciale lekkernij die je alleen\l"
	.string "daar koopt.\p"
	.string "Geef het aan een POKéMON,\n"
	.string "en hij wordt super blij.$"

