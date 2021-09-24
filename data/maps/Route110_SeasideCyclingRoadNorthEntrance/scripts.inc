Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 0
	goto_if_eq Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad::
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad:
	.string "On Cycling Road, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk:
	.string "Sorry, you can't walk on Cycling\n"
	.string "Road. It's too dangerous.\p"
	.string "Please come back with a Bike.$"

