BattleFrontier_BattleTowerMultiCorridor_MapScripts:: @ 8248D4A
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnFrame
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by object event 1, which has the gfx id VAR_OBJ_GFX_ID_F
	@ The multi partner is represented by object event 4, which has the gfx id VAR_OBJ_GFX_ID_E

BattleFrontier_BattleTowerMultiCorridor_OnTransition: @ 8248D5A
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx
	end

BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx:: @ 8248D71
	tower_setpartnergfx
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_BRENDAN_NORMAL
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale:: @ 8248D8B
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_MAY_NORMAL
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx:: @ 8248D91
	special SetBattleTowerLinkPlayerGfx
	return

BattleFrontier_BattleTowerMultiCorridor_OnWarp: @ 8248D95
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects:: @ 8248D9F
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
	hideobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
	hideobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
	special OffsetCameraForBattle
	end

BattleFrontier_BattleTowerMultiCorridor_OnFrame: @ 8248DB2
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor
	.2byte 0

BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor:: @ 8248DBC
	lockall
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
	opendoor 1, 1
	waitdooranim
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
	showobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
	showobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
	waitmovement 0
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
	closedoor 1, 1
	waitdooranim
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor
	applymovement 3, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor
	applymovement 2, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor
	waitmovement 0
	delay 40
	applymovement 3, Common_Movement_WalkInPlaceFastestUp
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 7, 1
	waitdooranim
	applymovement 3, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
	applymovement 2, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
	waitmovement 0
	closedoor 7, 1
	waitdooranim
	delay 30
	setvar VAR_TEMP_1, 1
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom
	releaseall
	end

BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom:: @ 8248E71
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom:: @ 8248E9E
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 255, 4, 8
	waitstate
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom:: @ 8248EA8
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 4, 5
	waitstate
	return

@ Unnecessary duplicate of the above
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom:: @ 8248EB2
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 4, 5
	waitstate
	return

BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor: @ 8248EBC
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor: @ 8248EC4
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor: @ 8248ECC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor: @ 8248ED5
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor: @ 8248EDE
	delay_16
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor: @ 8248EE3
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator: @ 8248EE6
	walk_down
	step_end

