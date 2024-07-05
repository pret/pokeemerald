RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/RustboroCity_Flat2_3F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_Flat2_3F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_Flat2_3F/text_es.inc"
.else
	.include "data/maps/RustboroCity_Flat2_3F/text.inc"
.endif
.endif
.endif
