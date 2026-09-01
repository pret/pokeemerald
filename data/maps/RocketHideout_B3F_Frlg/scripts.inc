RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "Stop meddling in TEAM ROCKET's\n"
	.string "affairs or else!$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "Oof!\n"
	.string "Taken down!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "SILPH SCOPE?\n"
	.string "Oh, that machine the BOSS stole.\p"
	.string "It's here somewhere.$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "We got word from upstairs that you\n"
	.string "were coming!$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "What?\n"
	.string "I lost? No!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "Go ahead and go!\p"
	.string "But you can't run the elevator\n"
	.string "without the LIFT KEY.$"

