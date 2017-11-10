FallarborTown_BattleTentCorridor_MapScripts:: @ 82006A7
	map_script 2, FallarborTown_BattleTentCorridor_MapScript2_2006AD
	.byte 0

FallarborTown_BattleTentCorridor_MapScript2_2006AD: @ 82006AD
	map_script_2 VAR_0x4000, 0, FallarborTown_BattleTentCorridor_EventScript_2006B7
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_2006B7:: @ 82006B7
	lockall
	setvar VAR_0x4000, 1
	applymovement 1, FallarborTown_BattleTentCorridor_Movement_2006FB
	applymovement 255, FallarborTown_BattleTentCorridor_Movement_2006FB
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement 1, FallarborTown_BattleTentCorridor_Movement_200701
	applymovement 255, FallarborTown_BattleTentCorridor_Movement_200700
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 255, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_2006FB: @ 82006FB
	step_up
	step_up
	step_up
	step_up
	step_end

FallarborTown_BattleTentCorridor_Movement_200700: @ 8200700
	step_up

FallarborTown_BattleTentCorridor_Movement_200701: @ 8200701
	step_up
	step_54
	step_end

	.incbin "baserom.gba", 0x200704, 0x195

