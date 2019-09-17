BattleFrontier_BattleTowerElevator_MapScripts:: @ 82419DB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_MapScript2_2419E6
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_MapScript2_241A96
	.byte 0

BattleFrontier_BattleTowerElevator_MapScript2_2419E6: @ 82419E6
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerElevator_EventScript_2419F0
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_2419F0:: @ 82419F0
	setvar VAR_TEMP_0, 1
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_241A86
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_241A8A
	waitmovement 0
	special BufferBattleTowerElevatorFloors
	waitse
	special MoveElevator
	waitstate
	delay 48
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_241A8E
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_241A92
	waitmovement 0
	call BattleFrontier_BattleTowerElevator_EventScript_241A28
	end

BattleFrontier_BattleTowerElevator_EventScript_241A28:: @ 8241A28
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_241A55
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_241A55
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_241A5F
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_241A72
	return

BattleFrontier_BattleTowerElevator_EventScript_241A55:: @ 8241A55
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 255, 8, 1
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A5F:: @ 8241A5F
	goto_if_unset FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerElevator_EventScript_241A7C
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2, 255, 7, 2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A72:: @ 8241A72
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2, 255, 7, 2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A7C:: @ 8241A7C
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 1
	waitstate
	return

BattleFrontier_BattleTowerElevator_Movement_241A86: @ 8241A86
	walk_up
	walk_right
	face_down
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A8A: @ 8241A8A
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A8E: @ 8241A8E
	walk_down
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A92: @ 8241A92
	walk_right
	walk_down
	walk_down
	step_end

BattleFrontier_BattleTowerElevator_MapScript2_241A96: @ 8241A96
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerElevator_EventScript_241AA0
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_241AA0:: @ 8241AA0
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

