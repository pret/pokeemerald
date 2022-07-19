.set LOCALID_ATTENDANT, 1

Route112_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
	.byte 0

Route112_CableCarStation_OnTransition:
	setescapewarp MAP_ROUTE112, 28, 28
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_MoveAttendantAside
	end

Route112_CableCarStation_EventScript_MoveAttendantAside::
	setobjectxyperm LOCALID_ATTENDANT, 7, 4
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
	return

Route112_CableCarStation_OnFrame:
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_ExitCableCar
	.2byte 0

Route112_CableCarStation_EventScript_ExitCableCar::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

Route112_CableCarStation_EventScript_Attendant::
	lock
	faceplayer
	msgbox Route112_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route112_CableCarStation_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, Route112_CableCarStation_EventScript_DeclineRide
	end

Route112_CableCarStation_EventScript_RideCableCar::
	msgbox Route112_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, FALSE  @ Going up
	setvar VAR_CABLE_CAR_STATION_STATE, 1
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

Route112_CableCarStation_EventScript_DeclineRide::
	msgbox Route112_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

Route112_CableCarStation_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

Route112_CableCarStation_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

Route112_CableCarStation_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

Route112_CableCarStation_Text_CableCarReadyGetOn:
	.string "Le TELEPHERIQUE est sur le point\n"
	.string "de monter. Voulez-vous l’emprunter?$"

Route112_CableCarStation_Text_StepThisWay:
	.string "Entrez, je vous en prie.$"

Route112_CableCarStation_Text_RideAnotherTime:
	.string "N’hésitez pas à revenir nous voir.$"

