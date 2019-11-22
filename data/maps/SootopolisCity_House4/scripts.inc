SootopolisCity_House4_MapScripts:: @ 8226D15
	.byte 0

SootopolisCity_House4_EventScript_Man:: @ 8226D16
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman:: @ 8226D1F
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill:: @ 8226D28
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea: @ 8226D3B
	.string "Listen up, and I'll tell you something\n"
	.string "good.\p"
	.string "There's supposed to be an ancient\n"
	.string "ruin in the sea around here.\p"
	.string "There could be treasures just waiting\n"
	.string "to be discovered down there.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon: @ 8226DEA
	.string "Ancient treasures…\p"
	.string "It would be nice if they existed, but\n"
	.string "even if they didn't, it would be so\l"
	.string "beautiful to take an underwater\l"
	.string "stroll with my POKéMON.$"

SootopolisCity_House4_Text_Azumarill: @ 8226E7F
	.string "AZUMARILL: Marurii.$"

