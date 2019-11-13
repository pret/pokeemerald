TrainerHill_OnResume: @ 82C8336
	setvar VAR_TEMP_2, 0
	setvar VAR_0x8004, TRAINER_HILL_FUNC_RESUME_TIMER
	special CallTrainerHillFunction
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 5
	special CallFrontierUtilFunc
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq TrainerHill_1F_EventScript_Lost
	compare VAR_RESULT, B_OUTCOME_DREW
	goto_if_eq TrainerHill_1F_EventScript_Lost
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq TrainerHill_1F_EventScript_Lost
	end

TrainerHill_OnWarp: @ 82C8372
	map_script_2 VAR_TEMP_3, 0, TrainerHill_1F_EventScript_DummyOnWarp
	.2byte 0

TrainerHill_1F_EventScript_DummyOnWarp:: @ 82C837C
	setvar VAR_TEMP_3, 1
@ forced stop

TrainerHill_OnFrame: @ 82C8381
	map_script_2 VAR_TEMP_2, 0, TrainerHill_1F_EventScript_DummyWarpToEntranceCounter
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

EventScript_TrainerHillTimer:: @ 82C8393
	lockall
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_TIME
	special CallTrainerHillFunction
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerHill_1F_EventScript_DummyWarpToEntranceCounter:: @ 82C83A6
	setvar VAR_TEMP_2, 1
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CLEAR_RESULT
	special CallTrainerHillFunction
	compare VAR_RESULT, 1  @ VAR_RESULT always 0 here
	goto_if_eq TrainerHill_1F_EventScript_WarpSilentToEntranceCounter
	end

@ Never reached
TrainerHill_1F_EventScript_WarpSilentToEntranceCounter:: @ 82C83BF
	warpsilent MAP_TRAINER_HILL_ENTRANCE, 255, 9, 6
	waitstate
	end

TrainerHill_1F_EventScript_Lost:: @ 82C83C9
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_ALL_TRAINER_FLAGS
	special CallTrainerHillFunction
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_LOST
	special CallTrainerHillFunction
	setvar VAR_TEMP_1, 1
	end

TrainerHill_EventScript_WarpToEntranceCounter:: @ 82C83DF
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 9, 6
	waitstate
	end

@ Unused
TrainerHill_1F_Movement_SetInvisible:: @ 82C83EE
	set_invisible
	step_end

@ TRAINER_PHILLIP is an actual Trainer on the SS Tidal, but is used as a placeholder here
TrainerHill_EventScript_TrainerBattle:: @ 82C83F0
	trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	setvar VAR_0x8004, TRAINER_HILL_FUNC_POST_BATTLE_TEXT
	special CallTrainerHillFunction
	waitmessage
	waitbuttonpress
	closemessage
	end
