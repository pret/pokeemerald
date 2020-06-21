.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleDomeCorridor_MapScripts:: @ 824B0FE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame
	.byte 0

BattleFrontier_BattleDomeCorridor_OnFrame: @ 824B104
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor
	.2byte 0

BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor:: @ 824B10E
	delay 16
	setvar VAR_TEMP_0, 1
	frontier_get FRONTIER_DATA_LVL_MODE
	compare VAR_RESULT, FRONTIER_LVL_OPEN
	goto_if_eq BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50
	waitmovement 0
	opendoor 13, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50
	waitmovement 0
	closedoor 13, 3
	waitdooranim
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom

BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen:: @ 824B161
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen
	waitmovement 0
	opendoor 37, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen
	waitmovement 0
	closedoor 37, 3
	waitdooranim
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom:: @ 824B18F
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 7
	waitstate
	end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50: @ 824B1A1
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

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50: @ 824B1AE
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50: @ 824B1B2
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

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50: @ 824B1BE
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen: @ 824B1C1
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

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen: @ 824B1D2
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen: @ 824B1D6
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

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen: @ 824B1E6
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight: @ 824B1E9
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
