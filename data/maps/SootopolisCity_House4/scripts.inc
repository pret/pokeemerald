SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Listen up, and I'll tell you something\n"
	.string "good.\p"
	.string "There's supposed to be an ancient\n"
	.string "ruin in the sea around here.\p"
	.string "There could be treasures just waiting\n"
	.string "to be discovered down there.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Ancient treasures…\p"
	.string "It would be nice if they existed, but\n"
	.string "even if they didn't, it would be so\l"
	.string "beautiful to take an underwater\l"
	.string "stroll with my Pokémon.$"

SootopolisCity_House4_Text_Azumarill:
	.string "Azumarill: Marurii.$"

