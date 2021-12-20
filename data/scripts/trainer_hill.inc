TrainerHill_OnResume:
	setvar VAR_TEMP_2, 0
	trainerhill_resumetimer
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, TrainerHill_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, TrainerHill_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, TrainerHill_1F_EventScript_Lost
	end

TrainerHill_OnWarp:
	map_script_2 VAR_TEMP_3, 0, TrainerHill_1F_EventScript_DummyOnWarp
	.2byte 0

TrainerHill_1F_EventScript_DummyOnWarp::
	setvar VAR_TEMP_3, 1
.ifdef BUGFIX
	end  @ Missing end. By chance, the next byte (0x02 of VAR_TEMP_2) is also the id for the end cmd
.endif

TrainerHill_OnFrame:
	map_script_2 VAR_TEMP_2, 0, TrainerHill_1F_EventScript_DummyWarpToEntranceCounter
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

EventScript_TrainerHillTimer::
	lockall
	trainerhill_gettime
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerHill_1F_EventScript_DummyWarpToEntranceCounter::
	setvar VAR_TEMP_2, 1
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_1F_EventScript_WarpSilentToEntranceCounter  @ VAR_RESULT always FALSE here
	end

@ Never reached
TrainerHill_1F_EventScript_WarpSilentToEntranceCounter::
	warpsilent MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

TrainerHill_1F_EventScript_Lost::
	trainerhill_settrainerflags
	trainerhill_lost
	setvar VAR_TEMP_1, 1
	end

TrainerHill_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

@ Unused
TrainerHill_1F_Movement_SetInvisible::
	set_invisible
	step_end

@ TRAINER_PHILLIP is an actual Trainer on the SS Tidal, but is used as a placeholder here
TrainerHill_EventScript_TrainerBattle::
	trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	trainerhill_postbattletext
	waitmessage
	waitbuttonpress
	closemessage
	end
