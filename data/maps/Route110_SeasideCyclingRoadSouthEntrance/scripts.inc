Route110_SeasideCyclingRoadSouthEntrance_MapScripts:: @ 826EBA1
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadSouthEntrance_OnTransition
	.byte 0

Route110_SeasideCyclingRoadSouthEntrance_OnTransition: @ 826EBA7
	compare VAR_CYCLING_CHALLENGE_STATE, 3
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	compare VAR_CYCLING_CHALLENGE_STATE, 2
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge:: @ 826EBBE
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk:: @ 826EBC4
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck:: @ 826EBD0
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 2
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike
	compare VAR_RESULT, 0
	goto_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike:: @ 826EBF6
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike:: @ 826EBFC
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter: @ 826EC11
	walk_left
	step_end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad:: @ 826EC13
	lockall
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad: @ 826EC23
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk: @ 826ECAA
	.string "Sorry, you can't walk on CYCLING\n"
	.string "ROAD. It's too dangerous.\p"
	.string "Please come back with a BIKE.$"

