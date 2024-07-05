PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/PetalburgCity_House2/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/PetalburgCity_House2/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/PetalburgCity_House2/text_es.inc"
.else
	.include "data/maps/PetalburgCity_House2/text.inc"
.endif
.endif
.endif
