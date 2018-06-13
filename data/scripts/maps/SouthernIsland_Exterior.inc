SouthernIsland_Exterior_MapScripts:: @ 82429C8
	map_script 3, SouthernIsland_Exterior_MapScript1_2429CE
	.byte 0

SouthernIsland_Exterior_MapScript1_2429CE: @ 82429CE
	setflag FLAG_LANDMARK_SOUTHERN_ISLAND
	end

SouthernIsland_Exterior_EventScript_2429D2:: @ 82429D2
	lock
	faceplayer
	msgbox SouthernIsland_Exterior_Text_2A69F1, 5
	compare VAR_RESULT, 0
	goto_eq SouthernIsland_Exterior_EventScript_242A17
	msgbox SouthernIsland_Exterior_Text_2A6A5D, 4
	closemessage
	applymovement VAR_LAST_TALKED, SouthernIsland_Exterior_Movement_2725AA
	waitmovement 0
	delay 30
	hideobjectat 1, SOUTHERN_ISLAND_EXTERIOR
	setvar VAR_0x8004, 2
	call SouthernIsland_Exterior_EventScript_272250
	warp LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_242A17:: @ 8242A17
	msgbox SouthernIsland_Exterior_Text_2A6A82, 4
	release
	end

BattleFrontier_OutsideWest_EventScript_242A21:: @ 8242A21
	applymovement 255, BattleFrontier_OutsideWest_Movement_242A37
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_242A2C:: @ 8242A2C
	applymovement 255, BattleFrontier_OutsideWest_Movement_242A39
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_242A37: @ 8242A37
	walk_down
	step_end

BattleFrontier_OutsideWest_Movement_242A39: @ 8242A39
	walk_left
	walk_in_place_fastest_down
	step_end

SouthernIsland_Exterior_EventScript_242A3C:: @ 8242A3C
	msgbox SouthernIsland_Exterior_Text_2A6AD5, 3
	end

