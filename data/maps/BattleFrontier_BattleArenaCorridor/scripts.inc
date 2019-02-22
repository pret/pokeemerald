BattleFrontier_BattleArenaCorridor_MapScripts:: @ 82573B9
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_MapScript2_2573BF
	.byte 0

BattleFrontier_BattleArenaCorridor_MapScript2_2573BF: @ 82573BF
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaCorridor_EventScript_2573C9
	.2byte 0

BattleFrontier_BattleArenaCorridor_EventScript_2573C9:: @ 82573C9
	delay 16
	setvar VAR_TEMP_0, 1
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_25742F
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_257417
	waitmovement 0
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_257444
	waitmovement 0
	msgbox BattleFrontier_BattleArenaCorridor_Text_257449, MSGBOX_SIGN
	applymovement 1, BattleFrontier_BattleArenaCorridor_Movement_257446
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_25742C
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM, 255, 7, 5
	waitstate
	end

BattleFrontier_BattleArenaCorridor_Movement_257417: @ 8257417
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

BattleFrontier_BattleArenaCorridor_Movement_25742C: @ 825742C
	walk_right
	set_invisible
	step_end

BattleFrontier_BattleArenaCorridor_Movement_25742F: @ 825742F
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

BattleFrontier_BattleArenaCorridor_Movement_257444: @ 8257444
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaCorridor_Movement_257446: @ 8257446
	walk_up
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleArenaCorridor_Text_257449: @ 8257449
	.string "Your battles shall be waged in\n"
	.string "the next room. Please step in!$"

