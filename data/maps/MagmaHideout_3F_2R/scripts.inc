MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef ENGLISH
	.include "data/maps/MagmaHideout_3F_2R/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/MagmaHideout_3F_2R/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/MagmaHideout_3F_2R/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/MagmaHideout_3F_2R/text_es.inc"
.endif
.endif
.endif
.endif
