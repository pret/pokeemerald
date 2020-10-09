.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaCorridor_MapScripts:: @ 82573B9
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_OnFrame
	.byte 0

BattleFrontier_BattleArenaCorridor_OnFrame: @ 82573BF
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom
	.2byte 0

BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom:: @ 82573C9
	delay 16
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn, MSGBOX_SIGN
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM, 255, 7, 5
	waitstate
	end

BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor: @ 8257417
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor: @ 825742C
	walk_right
	set_invisible
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor: @ 825742F
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer: @ 8257444
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay: @ 8257446
	walk_up
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn: @ 8257449
	.string "Your battles shall be waged in\n"
	.string "the next room. Please step in!$"

