Route110_SeasideCyclingRoadNorthEntrance_MapScripts:: @ 826EA77
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA78:: @ 826EA78
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_26EAC1, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA84:: @ 826EA84
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 0
	goto_if_eq Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA9F
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA9F:: @ 826EA9F
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_26EB48, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_26EAB4
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Movement_26EAB4: @ 826EAB4
	walk_left
	step_end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EAB6:: @ 826EAB6
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Text_26EAC1: @ 826EAC1
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadNorthEntrance_Text_26EB48: @ 826EB48
	.string "Sorry, you can't walk on CYCLING\n"
	.string "ROAD. It's too dangerous.\p"
	.string "Please come back with a BIKE.$"

