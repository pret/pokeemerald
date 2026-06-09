RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

.ifdef FRENCH
	.include "data/maps/RustboroCity_Flat2_1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_Flat2_1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_Flat2_1F/text_es.inc"
.else
	.include "data/maps/RustboroCity_Flat2_1F/text.inc"
.endif
.endif
.endif
