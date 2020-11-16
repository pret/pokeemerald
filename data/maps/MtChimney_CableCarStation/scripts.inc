.set LOCALID_ATTENDANT, 1

MtChimney_CableCarStation_MapScripts:: @ 822ABFA
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_OnFrame
	.byte 0

MtChimney_CableCarStation_OnTransition: @ 822AC05
	compare VAR_CABLE_CAR_STATION_STATE, 1
	call_if_eq MtChimney_CableCarStation_EventScript_MoveAttendantAside
	end

MtChimney_CableCarStation_EventScript_MoveAttendantAside:: @ 822AC11
	setobjectxyperm LOCALID_ATTENDANT, 5, 4
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
	return

MtChimney_CableCarStation_OnFrame: @ 822AC1D
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_ExitCableCar
	.2byte 0

MtChimney_CableCarStation_EventScript_ExitCableCar:: @ 822AC27
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

MtChimney_CableCarStation_EventScript_Attendant:: @ 822AC4B
	lock
	faceplayer
	msgbox MtChimney_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtChimney_CableCarStation_EventScript_RideCableCar
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_CableCarStation_EventScript_DeclineRide
	end

MtChimney_CableCarStation_EventScript_RideCableCar:: @ 822AC6C
	msgbox MtChimney_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, TRUE  @ Going down
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

MtChimney_CableCarStation_EventScript_DeclineRide:: @ 822AC9B
	msgbox MtChimney_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

MtChimney_CableCarStation_Movement_LeadPlayerToCableCar: @ 822ACA5
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_right
	step_end

MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar: @ 822ACAA
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

MtChimney_CableCarStation_Movement_BoardCableCar: @ 822ACAF
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

MtChimney_CableCarStation_Movement_ExitCableCar: @ 822ACB4
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

MtChimney_CableCarStation_Text_CableCarReadyGetOn: @ 822ACB9
	.string "The CABLE CAR is ready to go down.\n"
	.string "Would you like to be on it?$"

MtChimney_CableCarStation_Text_StepThisWay: @ 822ACF8
	.string "Please step this way.$"

MtChimney_CableCarStation_Text_RideAnotherTime: @ 822AD0E
	.string "Please ride with us another time.$"

