SilphCo_9F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
	.string "You look tired.\n"
	.string "You should take a quick nap.$"

SilphCo_9F_Text_DontGiveUp::
	.string "Don't give up!$"

SilphCo_9F_Text_ThankYouSoMuch::
	.string "Thank you so much.$"

SilphCo_9F_Text_Grunt1Intro::
	.string "Your POKéMON seem to adore you,\n"
	.string "kid!$"

SilphCo_9F_Text_Grunt1Defeat::
	.string "Ghaaah!$"

SilphCo_9F_Text_Grunt1PostBattle::
	.string "If I had started as a TRAINER at\n"
	.string "your age…$"

SilphCo_9F_Text_EdIntro::
	.string "Your POKéMON have weak points!\n"
	.string "I can nail them!$"

SilphCo_9F_Text_EdDefeat::
	.string "You hammered me!$"

SilphCo_9F_Text_EdPostBattle::
	.string "Exploiting weak spots does work.\n"
	.string "Think about type advantages.$"

SilphCo_9F_Text_Grunt2Intro::
	.string "I am one of the four ROCKET\n"
	.string "BROTHERS!$"

SilphCo_9F_Text_Grunt2Defeat::
	.string "Warg!\n"
	.string "Brothers, I lost!$"

SilphCo_9F_Text_Grunt2PostBattle::
	.string "My brothers will avenge me!$"

SilphCo_9F_Text_FloorSign::
	.string "SILPH CO. HEAD OFFICE\n"
	.string "9F$"

