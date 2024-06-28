MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef ENGLISH
	.include "data/maps/MtPyre_5F/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/MtPyre_5F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/MtPyre_5F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/MtPyre_5F/text_es.inc"
.endif
.endif
.endif
.endif
