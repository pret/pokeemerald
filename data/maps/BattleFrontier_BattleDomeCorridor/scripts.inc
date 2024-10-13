BattleFrontier_BattleDomeCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame
	.byte 0

BattleFrontier_BattleDomeCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor
	.2byte 0

BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor::
	delay 16
	setvar VAR_TEMP_0, 1
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50
	waitmovement 0
	opendoor 13, 3
	waitdooranim
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50
	waitmovement 0
	closedoor 13, 3
	waitdooranim
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom

BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen::
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen
	waitmovement 0
	opendoor 37, 3
	waitdooranim
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen
	waitmovement 0
	closedoor 37, 3
	waitdooranim
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom::
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 7
	waitstate
	end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50:
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
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50:
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

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen:
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
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen:
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

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen:
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight:
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
