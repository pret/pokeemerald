NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnLoad:
	compare VAR_NEW_MAUVILLE_STATE, 0
	call_if_eq NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, 1
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, 1
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, 1
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, 1
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, 1
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, 1
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, 0
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, 0
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, 0
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, 1
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, 0
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, 1
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

