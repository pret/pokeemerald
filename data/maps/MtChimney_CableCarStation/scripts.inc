MtChimney_CableCarStation_MapScripts:: @ 822ABFA
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_MapScript2_22AC1D
	.byte 0

MtChimney_CableCarStation_OnTransition: @ 822AC05
	compare VAR_CABLE_CAR_STATION_STATE, 1
	call_if_eq MtChimney_CableCarStation_EventScript_22AC11
	end

MtChimney_CableCarStation_EventScript_22AC11:: @ 822AC11
	setobjectxyperm 1, 5, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	return

MtChimney_CableCarStation_MapScript2_22AC1D: @ 822AC1D
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_22AC27
	.2byte 0

MtChimney_CableCarStation_EventScript_22AC27:: @ 822AC27
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, MtChimney_CableCarStation_Movement_22ACB4
	applymovement 1, MtChimney_CableCarStation_Movement_22ACAA
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm 1, 6, 7
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

MtChimney_CableCarStation_EventScript_22AC4B:: @ 822AC4B
	lock
	faceplayer
	msgbox MtChimney_CableCarStation_Text_22ACB9, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MtChimney_CableCarStation_EventScript_22AC6C
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_CableCarStation_EventScript_22AC9B
	end

MtChimney_CableCarStation_EventScript_22AC6C:: @ 822AC6C
	msgbox MtChimney_CableCarStation_Text_22ACF8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, MtChimney_CableCarStation_Movement_22ACA5
	applymovement EVENT_OBJ_ID_PLAYER, MtChimney_CableCarStation_Movement_22ACAF
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat 48
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

MtChimney_CableCarStation_EventScript_22AC9B:: @ 822AC9B
	msgbox MtChimney_CableCarStation_Text_22AD0E, MSGBOX_DEFAULT
	release
	end

MtChimney_CableCarStation_Movement_22ACA5: @ 822ACA5
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_right
	step_end

MtChimney_CableCarStation_Movement_22ACAA: @ 822ACAA
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

MtChimney_CableCarStation_Movement_22ACAF: @ 822ACAF
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

MtChimney_CableCarStation_Movement_22ACB4: @ 822ACB4
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

MtChimney_CableCarStation_Text_22ACB9: @ 822ACB9
	.string "The CABLE CAR is ready to go down.\n"
	.string "Would you like to be on it?$"

MtChimney_CableCarStation_Text_22ACF8: @ 822ACF8
	.string "Please step this way.$"

MtChimney_CableCarStation_Text_22AD0E: @ 822AD0E
	.string "Please ride with us another time.$"

