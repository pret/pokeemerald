SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef ENGLISH
	.include "data/maps/SeafloorCavern_Room3/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/SeafloorCavern_Room3/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SeafloorCavern_Room3/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SeafloorCavern_Room3/text_es.inc"
.endif
.endif
.endif
.endif
