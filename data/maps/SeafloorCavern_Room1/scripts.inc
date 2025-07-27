SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef FRENCH
	.include "data/maps/SeafloorCavern_Room1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SeafloorCavern_Room1/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SeafloorCavern_Room1/text_es.inc"
.else
	.include "data/maps/SeafloorCavern_Room1/text.inc"
.endif
.endif
.endif
