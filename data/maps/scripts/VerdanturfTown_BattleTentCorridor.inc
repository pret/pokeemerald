VerdanturfTown_BattleTentCorridor_MapScripts:: @ 820208A
	map_script 2, VerdanturfTown_BattleTentCorridor_MapScript2_202090
	.byte 0

VerdanturfTown_BattleTentCorridor_MapScript2_202090: @ 8202090
	map_script_2 VAR_0x4000, 0, VerdanturfTown_BattleTentCorridor_EventScript_20209A
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_20209A:: @ 820209A
	lockall
	setvar VAR_0x4000, 1
	applymovement 1, VerdanturfTown_BattleTentCorridor_Movement_2020DE
	applymovement 255, VerdanturfTown_BattleTentCorridor_Movement_2020DE
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement 1, VerdanturfTown_BattleTentCorridor_Movement_2020E4
	applymovement 255, VerdanturfTown_BattleTentCorridor_Movement_2020E3
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 255, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_2020DE: @ 82020DE
	step_up
	step_up
	step_up
	step_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_2020E3: @ 82020E3
	step_up

VerdanturfTown_BattleTentCorridor_Movement_2020E4: @ 82020E4
	step_up
	step_54
	step_end

	.incbin "baserom.gba", 0x2020e7, 0x213

