NewMauville_Entrance_MapScripts:: @ 82372AD
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_MapScript1_2372B8
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_MapScript1_2372B8: @ 82372B8
	compare VAR_NEW_MAUVILLE_STATE, 0
	call_if_eq NewMauville_Entrance_EventScript_2372C4
	end

NewMauville_Entrance_EventScript_2372C4:: @ 82372C4
	setmetatile 3, 0, 788, 1
	setmetatile 4, 0, 789, 1
	setmetatile 5, 0, 790, 1
	setmetatile 3, 1, 796, 1
	setmetatile 4, 1, 797, 1
	setmetatile 5, 1, 798, 1
	return

NewMauville_Entrance_OnTransition: @ 82372FB
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_2372FF:: @ 82372FF
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_237382, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq NewMauville_Entrance_EventScript_237380
	msgbox NewMauville_Entrance_Text_237396, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewMauville_Entrance_EventScript_237380
	msgbox NewMauville_Entrance_Text_2373AC, MSGBOX_DEFAULT
	setmetatile 3, 0, 707, 0
	setmetatile 4, 0, 708, 0
	setmetatile 5, 0, 709, 0
	setmetatile 3, 1, 715, 1
	setmetatile 4, 1, 716, 0
	setmetatile 5, 1, 717, 1
	special DrawWholeMapView
	playse SE_BAN
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_237380:: @ 8237380
	releaseall
	end

NewMauville_Entrance_Text_237382: @ 8237382
	.string "The door is locked.$"

NewMauville_Entrance_Text_237396: @ 8237396
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_2373AC: @ 82373AC
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

