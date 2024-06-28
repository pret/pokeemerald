RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/RustboroCity_House2/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/RustboroCity_House2/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_House2/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_House2/text_es.inc"
.endif
.endif
.endif
.endif
