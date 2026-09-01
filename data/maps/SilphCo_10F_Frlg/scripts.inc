SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
	.string "Welcome to 10F!\n"
	.string "So good of you to join me!$"

SilphCo_10F_Text_GruntDefeat::
	.string "I'm stunned!$"

SilphCo_10F_Text_GruntPostBattle::
	.string "Nice try, but the boardroom is up\n"
	.string "one more floor.$"

SilphCo_10F_Text_TravisIntro::
	.string "Enough of your silly games!$"

SilphCo_10F_Text_TravisDefeat::
	.string "No continues left!$"

SilphCo_10F_Text_TravisPostBattle::
	.string "Are you satisfied with beating me?\n"
	.string "Then go on home!$"

SilphCo_10F_Text_WaaaImScared::
	.string "Waaaaa!\n"
	.string "I'm scared!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "About me crying…\n"
	.string "Please keep it a secret.$"

SilphCo_10F_Text_FloorSign::
	.string "SILPH CO. HEAD OFFICE\n"
	.string "10F$"

