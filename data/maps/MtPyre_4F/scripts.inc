MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef ENGLISH
	.include "data/maps/MtPyre_4F/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/MtPyre_4F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/MtPyre_4F/text_it.inc"
.endif
.endif
.endif
