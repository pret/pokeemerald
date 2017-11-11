BattleFrontier_BattleArenaCorridor_MapScripts:: @ 82573B9
	map_script 2, BattleFrontier_BattleArenaCorridor_MapScript2_2573BF
	.byte 0

BattleFrontier_BattleArenaCorridor_MapScript2_2573BF: @ 82573BF
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattleArenaCorridor_EventScript_2573C9
	.2byte 0

BattleFrontier_BattleArenaCorridor_EventScript_2573C9:: @ 82573C9
	delay 16
	setvar VAR_0x4000, 1
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_25742F
	applymovement 255, BattleFrontier_BattleArenaCorridor_Movement_257417
	waitmovement 0
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_257444
	waitmovement 0
	msgbox BattleFrontier_BattleArenaCorridor_Text_257449, 3
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_257446
	waitmovement 0
	applymovement 255, BattleFrontier_BattleArenaCorridor_Movement_25742C
	waitmovement 0
	setvar VAR_0x8006, 0
	warp BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM, 255, 7, 5
	waitstate
	end

BattleFrontier_BattleArenaCorridor_Movement_257417: @ 8257417
	step_up
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_right
	step_right
	step_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_25742C: @ 825742C
	step_right
	step_54
	step_end

BattleFrontier_BattleArenaCorridor_Movement_25742F: @ 825742F
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_right
	step_right
	step_right
	step_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_257444: @ 8257444
	step_27
	step_end

BattleFrontier_BattleArenaCorridor_Movement_257446: @ 8257446
	step_up
	step_25
	step_end

BattleFrontier_BattleArenaCorridor_Text_257449: @ 8257449
	.string "Your battles shall be waged in\n"
	.string "the next room. Please step in!$"

