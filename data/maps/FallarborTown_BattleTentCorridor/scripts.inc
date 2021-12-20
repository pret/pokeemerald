.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "We do all right in the preliminary round,\n"
	.string "but we can never win the appeals…\p"
	.string "Maybe it means I have to watch what\n"
	.string "other contestants are doing…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "See!\n"
	.string "My POKéMON won all these RIBBONS!\p"
	.string "Have your POKéMON earned any RIBBONS?\n"
	.string "You can check them on your POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "I can't beat GYM LEADERS…\p"
	.string "I can't win any CONTESTS…\p"
	.string "I've been here, there, and everywhere,\n"
	.string "and it's all for naught…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "POKéMON CONTESTS\n"
	.string "SUPER RANK STAGE!$"

