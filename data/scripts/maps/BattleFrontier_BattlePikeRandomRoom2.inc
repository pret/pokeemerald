BattleFrontier_BattlePikeRandomRoom2_MapScripts:: @ 825E392
	map_script 2, BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E39D
	map_script 4, BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E3DE
	.byte 0

BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E39D: @ 825E39D
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3A7
	.2byte 0

BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3A7:: @ 825E3A7
	delay 16
	applymovement 1, BattleFrontier_BattlePikeRandomRoom2_Movement_25E3DB
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special sub_81A1780
	lockall
	msgbox BattleFrontier_BattlePikeRandomRoom2_Text_25E3F2, 4
	closemessage
	releaseall
	warp BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom2_Movement_25E3DB: @ 825E3DB
	step_down
	step_down
	step_end

BattleFrontier_BattlePikeRandomRoom2_MapScript2_25E3DE: @ 825E3DE
	map_script_2 VAR_0x4004, 0, BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3E8
	.2byte 0

BattleFrontier_BattlePikeRandomRoom2_EventScript_25E3E8:: @ 825E3E8
	setvar VAR_0x4004, 1
	turnobject 255, 2
	end

BattleFrontier_BattlePikeRandomRoom2_Text_25E3F2: @ 825E3F2
	.string "Congratulations…\n"
	.string "Now, this way, please…$"

