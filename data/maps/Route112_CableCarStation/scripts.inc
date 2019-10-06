Route112_CableCarStation_MapScripts:: @ 822AABE
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_MapScript2_22AAE9
	.byte 0

Route112_CableCarStation_OnTransition: @ 822AAC9
	setescapewarp MAP_ROUTE112, 255, 28, 28
	compare VAR_CABLE_CAR_STATION_STATE, 2
	call_if_eq Route112_CableCarStation_EventScript_22AADD
	end

Route112_CableCarStation_EventScript_22AADD:: @ 822AADD
	setobjectxyperm 1, 7, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return

Route112_CableCarStation_MapScript2_22AAE9: @ 822AAE9
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_22AAF3
	.2byte 0

Route112_CableCarStation_EventScript_22AAF3:: @ 822AAF3
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Route112_CableCarStation_Movement_22AB80
	applymovement 1, Route112_CableCarStation_Movement_22AB76
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm 1, 6, 7
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

Route112_CableCarStation_EventScript_22AB17:: @ 822AB17
	lock
	faceplayer
	msgbox Route112_CableCarStation_Text_22AB85, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route112_CableCarStation_EventScript_22AB38
	compare VAR_RESULT, 0
	goto_if_eq Route112_CableCarStation_EventScript_22AB67
	end

Route112_CableCarStation_EventScript_22AB38:: @ 822AB38
	msgbox Route112_CableCarStation_Text_22ABC2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Route112_CableCarStation_Movement_22AB71
	applymovement EVENT_OBJ_ID_PLAYER, Route112_CableCarStation_Movement_22AB7B
	waitmovement 0
	setvar VAR_0x8004, 0
	setvar VAR_CABLE_CAR_STATION_STATE, 1
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

Route112_CableCarStation_EventScript_22AB67:: @ 822AB67
	msgbox Route112_CableCarStation_Text_22ABD8, MSGBOX_DEFAULT
	release
	end

Route112_CableCarStation_Movement_22AB71: @ 822AB71
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_left
	step_end

Route112_CableCarStation_Movement_22AB76: @ 822AB76
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

Route112_CableCarStation_Movement_22AB7B: @ 822AB7B
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

Route112_CableCarStation_Movement_22AB80: @ 822AB80
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

Route112_CableCarStation_Text_22AB85: @ 822AB85
	.string "The CABLE CAR is ready to go up.\n"
	.string "Would you like to be on it?$"

Route112_CableCarStation_Text_22ABC2: @ 822ABC2
	.string "Please step this way.$"

Route112_CableCarStation_Text_22ABD8: @ 822ABD8
	.string "Please ride with us another time.$"

