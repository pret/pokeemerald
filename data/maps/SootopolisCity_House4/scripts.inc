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
	.string "Luister, ik vertel je iets leuks.\p"
	.string "Er zou een oude ruïne in de\n"
	.string "zee hier vlakbij liggen.\p"
	.string "Daar liggen misschien schatten\n"
	.string "te wachten om gevonden te worden.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Oude schatten…\p"
	.string "Het zou mooi zijn als ze bestaan,\n"
	.string "maar ook zonder is het fijn om\l"
	.string "onder water te wandelen met\l"
	.string "mijn POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

