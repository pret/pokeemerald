BattleFrontier_BattlePikeCorridor_MapScripts:: @ 825C771
	map_script 2, BattleFrontier_BattlePikeCorridor_MapScript2_25C77C
	map_script 4, BattleFrontier_BattlePikeCorridor_MapScript2_25C7F7
	.byte 0

BattleFrontier_BattlePikeCorridor_MapScript2_25C77C: @ 825C77C
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattlePikeCorridor_EventScript_25C786
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_25C786:: @ 825C786
	delay 16
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_81A1780
	setvar VAR_0x8004, 20
	special sub_81A703C
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 1
	special sub_81A703C
	applymovement 255, BattleFrontier_BattlePikeCorridor_Movement_25C80B
	applymovement 1, BattleFrontier_BattlePikeCorridor_Movement_25C812
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeCorridor_Text_25C817, 4
	closemessage
	releaseall
	applymovement 255, BattleFrontier_BattlePikeCorridor_Movement_25C80E
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 99
	special sub_81A1780
	call BattleFrontier_BattlePikeCorridor_EventScript_25BB49
	warpsilent BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
	waitstate
	end

BattleFrontier_BattlePikeCorridor_MapScript2_25C7F7: @ 825C7F7
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattlePikeCorridor_EventScript_25C801
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_25C801:: @ 825C801
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

BattleFrontier_BattlePikeCorridor_Movement_25C80B: @ 825C80B
	step_up
	step_up
	step_end

BattleFrontier_BattlePikeCorridor_Movement_25C80E: @ 825C80E
	step_up
	step_up
	step_54
	step_end

BattleFrontier_BattlePikeCorridor_Movement_25C812: @ 825C812
	step_up
	step_up
	step_left
	step_00
	step_end

BattleFrontier_BattlePikeCorridor_Text_25C817: @ 825C817
	.string "Your Battle Choice challenge\n"
	.string "has now begun…$"

