BattleFrontier_BattleTowerElevator_MapScripts:: @ 82419DB
	map_script 2, BattleFrontier_BattleTowerElevator_MapScript2_2419E6
	map_script 4, BattleFrontier_BattleTowerElevator_MapScript2_241A96
	.byte 0

BattleFrontier_BattleTowerElevator_MapScript2_2419E6: @ 82419E6
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattleTowerElevator_EventScript_2419F0
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_2419F0:: @ 82419F0
	setvar VAR_0x4000, 1
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_241A86
	applymovement 255, BattleFrontier_BattleTowerElevator_Movement_241A8A
	waitmovement 0
	special sub_813A080
	waitse
	special sub_8139A78
	waitstate
	delay 48
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_241A8E
	applymovement 255, BattleFrontier_BattleTowerElevator_Movement_241A92
	waitmovement 0
	call BattleFrontier_BattleTowerElevator_EventScript_241A28
	end

BattleFrontier_BattleTowerElevator_EventScript_241A28:: @ 8241A28
	compare VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerElevator_EventScript_241A55
	compare VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleTowerElevator_EventScript_241A55
	compare VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerElevator_EventScript_241A5F
	compare VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerElevator_EventScript_241A72
	return

BattleFrontier_BattleTowerElevator_EventScript_241A55:: @ 8241A55
	warp BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 255, 8, 1
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A5F:: @ 8241A5F
	checkflag FLAG_0x152
	goto_if 0, BattleFrontier_BattleTowerElevator_EventScript_241A7C
	warp BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR_2, 255, 7, 2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A72:: @ 8241A72
	warp BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR_2, 255, 7, 2
	waitstate
	return

BattleFrontier_BattleTowerElevator_EventScript_241A7C:: @ 8241A7C
	warp BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 1
	waitstate
	return

BattleFrontier_BattleTowerElevator_Movement_241A86: @ 8241A86
	step_up
	step_right
	step_00
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A8A: @ 8241A8A
	step_up
	step_up
	step_00
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A8E: @ 8241A8E
	step_down
	step_down
	step_54
	step_end

BattleFrontier_BattleTowerElevator_Movement_241A92: @ 8241A92
	step_right
	step_down
	step_down
	step_end

BattleFrontier_BattleTowerElevator_MapScript2_241A96: @ 8241A96
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattleTowerElevator_EventScript_241AA0
	.2byte 0

BattleFrontier_BattleTowerElevator_EventScript_241AA0:: @ 8241AA0
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

