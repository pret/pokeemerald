FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

.ifdef FRENCH
	.include "data/maps/FortreeCity_House5/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/FortreeCity_House5/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/FortreeCity_House5/text_es.inc"
.else
	.include "data/maps/FortreeCity_House5/text.inc"
.endif
.endif
.endif
