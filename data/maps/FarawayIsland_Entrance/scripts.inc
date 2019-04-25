FarawayIsland_Entrance_MapScripts:: @ 8267C8E
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition: @ 8267C94
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	end

FarawayIsland_Entrance_EventScript_267C98:: @ 8267C98
	setweather WEATHER_CLOUDS
	doweather
	end

FarawayIsland_Entrance_EventScript_267C9D:: @ 8267C9D
	setweather WEATHER_NONE
	doweather
	end

FarawayIsland_Entrance_EventScript_267CA2:: @ 8267CA2
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_2C6B42, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FarawayIsland_Entrance_EventScript_267CE7
	msgbox FarawayIsland_Entrance_Text_2A6A5D, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	hideobjectat 1, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, 2
	call FarawayIsland_Entrance_EventScript_272250
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_267CE7:: @ 8267CE7
	msgbox FarawayIsland_Entrance_Text_2A6A82, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_267CF1:: @ 8267CF1
	msgbox FarawayIsland_Entrance_Text_2C6D5A, MSGBOX_SIGN
	end

