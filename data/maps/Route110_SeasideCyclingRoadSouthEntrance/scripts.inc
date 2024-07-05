Route110_SeasideCyclingRoadSouthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadSouthEntrance_OnTransition
	.byte 0

Route110_SeasideCyclingRoadSouthEntrance_OnTransition:
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	call_if_eq VAR_RESULT, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad::
	lockall
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

.ifdef FRENCH
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/text_es.inc"
.else
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/text.inc"
.endif
.endif
.endif
