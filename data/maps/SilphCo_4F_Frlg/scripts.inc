SilphCo_4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
	.string "Sssh!\n"
	.string "Can't you see I'm hiding?$"

SilphCo_4F_Text_TeamRocketIsGone::
	.string "Huh?\n"
	.string "TEAM ROCKET is gone?$"

SilphCo_4F_Text_Grunt1Intro::
	.string "TEAM ROCKET has taken control\n"
	.string "of SILPH CO.!$"

SilphCo_4F_Text_Grunt1Defeat::
	.string "Arrgh!$"

SilphCo_4F_Text_Grunt1PostBattle::
	.string "Fwahahaha!\n"
	.string "My BOSS has been after this place!$"

SilphCo_4F_Text_RodneyIntro::
	.string "My POKéMON is my loyal servant.$"

SilphCo_4F_Text_RodneyDefeat::
	.string "Darn!\n"
	.string "You weak POKéMON!$"

SilphCo_4F_Text_RodneyPostBattle::
	.string "The doors are electronically\n"
	.string "locked.\p"
	.string "It takes a CARD KEY to open the\n"
	.string "doors here.$"

SilphCo_4F_Text_Grunt2Intro::
	.string "Intruder spotted!$"

SilphCo_4F_Text_Grunt2Defeat::
	.string "Who are you?$"

SilphCo_4F_Text_Grunt2PostBattle::
	.string "I better tell the BOSS on 11F!$"

SilphCo_4F_Text_FloorSign::
	.string "SILPH CO. HEAD OFFICE\n"
	.string "4F$"

