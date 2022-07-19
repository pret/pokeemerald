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
	.string "Ecoute-moi bien, je vais te dire\n"
	.string "quelque chose d’intéressant.\p"
	.string "Il paraît qu’il existe, pas très loin\n"
	.string "d’ici, une vieille ruine dans la mer.\p"
	.string "Il y a peut-être là-bas des trésors qui\n"
	.string "ne demandent qu’à être découverts.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "D’anciens trésors…\p"
	.string "Ce serait formidable s’ils existaient\n"
	.string "vraiment, mais même si ce n’est pas le\l"
	.string "cas, ce serait merveilleux de faire\l"
	.string "un tour sous l’eau avec mon POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Zuzu.$"

