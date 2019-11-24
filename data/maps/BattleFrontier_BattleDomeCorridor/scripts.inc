BattleFrontier_BattleDomeCorridor_MapScripts:: @ 824B0FE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_MapScript2_24B104
	.byte 0

BattleFrontier_BattleDomeCorridor_MapScript2_24B104: @ 824B104
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_24B10E
	.2byte 0

BattleFrontier_BattleDomeCorridor_EventScript_24B10E:: @ 824B10E
	delay 16
	setvar VAR_TEMP_0, 1
	frontier_get FRONTIER_DATA_LVL_MODE
	compare VAR_RESULT, FRONTIER_LVL_OPEN
	goto_if_eq BattleFrontier_BattleDomeCorridor_EventScript_24B161
	applymovement 1, BattleFrontier_BattleDomeCorridor_Movement_24B1B2
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_24B1A1
	waitmovement 0
	opendoor 13, 3
	waitdooranim
	applymovement 1, BattleFrontier_BattleDomeCorridor_Movement_24B1BE
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_24B1AE
	waitmovement 0
	closedoor 13, 3
	waitdooranim
	goto BattleFrontier_BattleDomeCorridor_EventScript_24B18F

BattleFrontier_BattleDomeCorridor_EventScript_24B161:: @ 824B161
	applymovement 1, BattleFrontier_BattleDomeCorridor_Movement_24B1D6
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_24B1C1
	waitmovement 0
	opendoor 37, 3
	waitdooranim
	applymovement 1, BattleFrontier_BattleDomeCorridor_Movement_24B1E6
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_24B1D2
	waitmovement 0
	closedoor 37, 3
	waitdooranim
BattleFrontier_BattleDomeCorridor_EventScript_24B18F:: @ 824B18F
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 7
	waitstate
	end

BattleFrontier_BattleDomeCorridor_Movement_24B1A1: @ 824B1A1
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1AE: @ 824B1AE
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1B2: @ 824B1B2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1BE: @ 824B1BE
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1C1: @ 824B1C1
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1D2: @ 824B1D2
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1D6: @ 824B1D6
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1E6: @ 824B1E6
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_24B1E9: @ 824B1E9
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end
