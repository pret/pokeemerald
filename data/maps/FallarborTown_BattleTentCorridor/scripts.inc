FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
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
	.string "In de voorronde gaat het prima,\n"
	.string "maar de finale winnen we nooit…\p"
	.string "Misschien moet ik beter kijken\n"
	.string "wat de anderen doen…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Kijk!\n"
	.string "Mijn POKéMON won al deze LINTEN!\p"
	.string "Heeft jouw POKéMON ook LINTEN?\n"
	.string "Dat zie je op je POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Ik win niet van GYMLEIDERS…\p"
	.string "Ik win ook geen WEDSTRIJDEN…\p"
	.string "Ik ben overal geweest,\n"
	.string "maar het helpt niks…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "POKéMON WEDSTRIJDEN\n"
	.string "SUPER RANK PODIUM!$"

