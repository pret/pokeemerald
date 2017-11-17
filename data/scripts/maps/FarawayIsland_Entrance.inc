FarawayIsland_Entrance_MapScripts:: @ 8267C8E
	map_script 3, FarawayIsland_Entrance_MapScript1_267C94
	.byte 0

FarawayIsland_Entrance_MapScript1_267C94: @ 8267C94
	setflag FLAG_0x8D8
	end

FarawayIsland_Entrance_EventScript_267C98:: @ 8267C98
	setweather 1
	doweather
	end

FarawayIsland_Entrance_EventScript_267C9D:: @ 8267C9D
	setweather 0
	doweather
	end

FarawayIsland_Entrance_EventScript_267CA2:: @ 8267CA2
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_2C6B42, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq FarawayIsland_Entrance_EventScript_267CE7
	msgbox FarawayIsland_Entrance_Text_2A6A5D, 4
	closemessage
	applymovement VAR_LAST_TALKED, FarawayIsland_Entrance_Movement_2725AA
	waitmovement 0
	delay 30
	hideobjectat 1, FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, 2
	call FarawayIsland_Entrance_EventScript_272250
	warp LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_267CE7:: @ 8267CE7
	msgbox FarawayIsland_Entrance_Text_2A6A82, 4
	release
	end

FarawayIsland_Entrance_EventScript_267CF1:: @ 8267CF1
	msgbox FarawayIsland_Entrance_Text_2C6D5A, 3
	end

