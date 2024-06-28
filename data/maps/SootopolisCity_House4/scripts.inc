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

.ifdef ENGLISH
	.include "data/maps/SootopolisCity_House4/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/SootopolisCity_House4/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SootopolisCity_House4/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SootopolisCity_House4/text_es.inc"
.endif
.endif
.endif
.endif
