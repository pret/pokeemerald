.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePikeRoomFinal_MapScripts:: @ 825E392
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomFinal_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomFinal_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomFinal_OnFrame: @ 825E39D
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom:: @ 825E3A7
	delay 16
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer
	waitmovement 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	lockall
	msgbox BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease, MSGBOX_DEFAULT
	closemessage
	releaseall
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer: @ 825E3DB
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomFinal_OnWarp: @ 825E3DE
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth:: @ 825E3E8
	setvar VAR_TEMP_4, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease: @ 825E3F2
	.string "Congratulations…\n"
	.string "Now, this way, please…$"

