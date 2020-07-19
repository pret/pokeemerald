.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePikeCorridor_MapScripts:: @ 825C771
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_OnWarp
	.byte 0

BattleFrontier_BattlePikeCorridor_OnFrame: @ 825C77C
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor:: @ 825C786
	delay 16
	frontier_set FRONTIER_DATA_BATTLE_NUM, 1
	pike_cleartrainerids
	pike_nohealing TRUE
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun, MSGBOX_DEFAULT
	closemessage
	releaseall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor
	waitmovement 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
	waitstate
	end

BattleFrontier_BattlePikeCorridor_OnWarp: @ 825C7F7
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth:: @ 825C801
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor: @ 825C80B
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor: @ 825C80E
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor: @ 825C812
	walk_up
	walk_up
	walk_left
	face_down
	step_end

BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun: @ 825C817
	.string "Your Battle Choice challenge\n"
	.string "has now begun…$"

