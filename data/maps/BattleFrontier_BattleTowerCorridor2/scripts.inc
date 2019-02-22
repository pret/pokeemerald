BattleFrontier_BattleTowerCorridor2_MapScripts:: @ 8248D4A
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerCorridor2_MapScript1_248D5A
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerCorridor2_MapScript2_248D95
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor2_MapScript2_248DB2
	.byte 0

BattleFrontier_BattleTowerCorridor2_MapScript1_248D5A: @ 8248D5A
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248D71
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248D91
	end

BattleFrontier_BattleTowerCorridor2_EventScript_248D71:: @ 8248D71
	setvar VAR_0x8004, 14
	special sub_8161F74
	checkplayergender
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248D8B
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_BRENDAN_NORMAL
	return

BattleFrontier_BattleTowerCorridor2_EventScript_248D8B:: @ 8248D8B
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_MAY_NORMAL
	return

BattleFrontier_BattleTowerCorridor2_EventScript_248D91:: @ 8248D91
	special sub_813A76C
	return

BattleFrontier_BattleTowerCorridor2_MapScript2_248D95: @ 8248D95
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerCorridor2_EventScript_248D9F
	.2byte 0

BattleFrontier_BattleTowerCorridor2_EventScript_248D9F:: @ 8248D9F
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2
	hideobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2
	hideobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2
	special sub_8139980
	end

BattleFrontier_BattleTowerCorridor2_MapScript2_248DB2: @ 8248DB2
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerCorridor2_EventScript_248DBC
	.2byte 0

BattleFrontier_BattleTowerCorridor2_EventScript_248DBC:: @ 8248DBC
	lockall
	setflag FLAG_SPECIAL_FLAG_0x4002
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 1
	opendoor 1, 1
	waitdooranim
	clearflag FLAG_SPECIAL_FLAG_0x4002
	showobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2
	showobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR2
	applymovement 1, BattleFrontier_BattleTowerCorridor2_Movement_248EE6
	applymovement 4, BattleFrontier_BattleTowerCorridor2_Movement_248EE6
	waitmovement 0
	setflag FLAG_SPECIAL_FLAG_0x4002
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 1
	closedoor 1, 1
	waitdooranim
	clearflag FLAG_SPECIAL_FLAG_0x4002
	applymovement 1, BattleFrontier_BattleTowerCorridor2_Movement_248EBC
	applymovement 4, BattleFrontier_BattleTowerCorridor2_Movement_248EC4
	applymovement 3, BattleFrontier_BattleTowerCorridor2_Movement_248ECC
	applymovement 2, BattleFrontier_BattleTowerCorridor2_Movement_248ED5
	waitmovement 0
	delay 40
	applymovement 3, Common_Movement_WalkInPlaceUp
	applymovement 2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	opendoor 7, 1
	waitdooranim
	applymovement 3, BattleFrontier_BattleTowerCorridor2_Movement_248EE3
	applymovement 2, BattleFrontier_BattleTowerCorridor2_Movement_248EE3
	applymovement 1, BattleFrontier_BattleTowerCorridor2_Movement_248EDE
	applymovement 4, BattleFrontier_BattleTowerCorridor2_Movement_248EDE
	waitmovement 0
	closedoor 7, 1
	waitdooranim
	delay 30
	setvar VAR_TEMP_1, 1
	call BattleFrontier_BattleTowerCorridor2_EventScript_248E71
	releaseall
	end

BattleFrontier_BattleTowerCorridor2_EventScript_248E71:: @ 8248E71
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248E9E
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248E9E
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248EA8
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerCorridor2_EventScript_248EB2
	return

BattleFrontier_BattleTowerCorridor2_EventScript_248E9E:: @ 8248E9E
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 255, 4, 8
	waitstate
	return

BattleFrontier_BattleTowerCorridor2_EventScript_248EA8:: @ 8248EA8
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM2, 255, 4, 5
	waitstate
	return

BattleFrontier_BattleTowerCorridor2_EventScript_248EB2:: @ 8248EB2
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM2, 255, 4, 5
	waitstate
	return

BattleFrontier_BattleTowerCorridor2_Movement_248EBC: @ 8248EBC
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248EC4: @ 8248EC4
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248ECC: @ 8248ECC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248ED5: @ 8248ED5
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248EDE: @ 8248EDE
	delay_16
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248EE3: @ 8248EE3
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_248EE6: @ 8248EE6
	walk_down
	step_end

