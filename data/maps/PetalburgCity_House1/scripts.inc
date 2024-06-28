PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/PetalburgCity_House1/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/PetalburgCity_House1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/PetalburgCity_House1/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/PetalburgCity_House1/text_es.inc"
.endif
.endif
.endif
.endif
