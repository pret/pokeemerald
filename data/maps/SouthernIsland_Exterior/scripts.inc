.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

SouthernIsland_Exterior_MapScripts:: @ 82429C8
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_OnTransition
	.byte 0

SouthernIsland_Exterior_OnTransition: @ 82429CE
	setflag FLAG_LANDMARK_SOUTHERN_ISLAND
	end

SouthernIsland_Exterior_EventScript_Sailor:: @ 82429D2
	lock
	faceplayer
	msgbox EventTicket_Text_SouthernIslandSailBack, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SouthernIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_SOUTHERN_ISLAND_EXTERIOR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_AsYouLike:: @ 8242A17
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

Ferry_EventScript_DepartIslandSouth:: @ 8242A21
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_EventScript_DepartIslandBoardSouth
	waitmovement 0
	return

Ferry_EventScript_DepartIslandWest:: @ 8242A2C
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_EventScript_DepartIslandBoardWest
	waitmovement 0
	return

Ferry_EventScript_DepartIslandBoardSouth: @ 8242A37
	walk_down
	step_end

Ferry_EventScript_DepartIslandBoardWest: @ 8242A39
	walk_left
	walk_in_place_fastest_down
	step_end

SouthernIsland_Exterior_EventScript_Sign:: @ 8242A3C
	msgbox SouthernIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end

