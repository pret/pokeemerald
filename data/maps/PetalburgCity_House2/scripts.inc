PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/PetalburgCity_House2/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/PetalburgCity_House2/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/PetalburgCity_House2/text_it.inc"
.endif
.endif
.endif
