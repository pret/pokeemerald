BattleFrontier_BattlePikeCorridor_MapScripts:: @ 825C771
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_MapScript2_25C77C
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_MapScript2_25C7F7
	.byte 0

BattleFrontier_BattlePikeCorridor_MapScript2_25C77C: @ 825C77C
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeCorridor_EventScript_25C786
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_25C786:: @ 825C786
	delay 16
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 20
	special CallBattlePikeFunction
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 1
	special CallBattlePikeFunction
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_25C80B
	applymovement 1, BattleFrontier_BattlePikeCorridor_Movement_25C812
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeCorridor_Text_25C817, MSGBOX_DEFAULT
	closemessage
	releaseall
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_25C80E
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 99
	special CallFrontierUtilFunc
	call BattleFrontier_BattlePikeCorridor_EventScript_25BB49
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
	waitstate
	end

BattleFrontier_BattlePikeCorridor_MapScript2_25C7F7: @ 825C7F7
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeCorridor_EventScript_25C801
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_25C801:: @ 825C801
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

BattleFrontier_BattlePikeCorridor_Movement_25C80B: @ 825C80B
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeCorridor_Movement_25C80E: @ 825C80E
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeCorridor_Movement_25C812: @ 825C812
	walk_up
	walk_up
	walk_left
	face_down
	step_end

BattleFrontier_BattlePikeCorridor_Text_25C817: @ 825C817
	.string "Your Battle Choice challenge\n"
	.string "has now begun…$"

