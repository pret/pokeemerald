BattleFrontier_BattlePikeRandomRoom2_MapScripts:: @ 825E392
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E39D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E3DE
	.byte 0

BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E39D: @ 825E39D
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3A7
	.2byte 0

BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3A7:: @ 825E3A7
	delay 16
	applymovement 1, BattleFrontier_BattlePikeRandomRoom2_Movement_25E3DB
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	lockall
	msgbox BattleFrontier_BattlePikeRandomRoom2_Text_25E3F2, MSGBOX_DEFAULT
	closemessage
	releaseall
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom2_Movement_25E3DB: @ 825E3DB
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E3DE: @ 825E3DE
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3E8
	.2byte 0

BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3E8:: @ 825E3E8
	setvar VAR_TEMP_4, 1
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

BattleFrontier_BattlePikeRandomRoom2_Text_25E3F2: @ 825E3F2
	.string "Congratulations…\n"
	.string "Now, this way, please…$"

