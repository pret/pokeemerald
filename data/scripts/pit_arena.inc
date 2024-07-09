
PitArena_OnFrame:
	map_script_2 VAR_REWARD_STATE, 1, PitArena_OnFrameRewardDrop
	.2byte 0

PitArena_OnFrameRewardDrop::
	lockall
	setvar VAR_PIT_TUTOR_STATE, 0
	setvar VAR_REWARD_STATE, 2
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnFrameRewardDrop_4
	goto_if_set FLAG_DOUBLES_MODE, PitArena_OnFrameRewardDrop_Doubles
	random 3
	switch VAR_RESULT
	case 0, PitArena_OnFrameRewardDrop_3
	case 1, PitArena_OnFrameRewardDrop_4
	case 2, PitArena_OnFrameRewardDrop_5
PitArena_OnFrameRewardDrop_1:
	callnative UpdateObjectEventsFromScript
	releaseall
	end

PitArena_OnFrameRewardDrop_3:
	clearflag FLAG_REWARD_ITEM_1
	addobject 6
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_4:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	addobject 6
	addobject 7
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_5:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	clearflag FLAG_REWARD_ITEM_3
	addobject 6
	addobject 7
	addobject 12
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_Doubles:
	random 2
	switch VAR_RESULT
	case 0, PitArena_OnFrameRewardDrop_4
	case 1, PitArena_OnFrameRewardDrop_5
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnResume:
	callnative CheckFloorCleared
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnResumeNormal
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setflashlevel 0
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnResumeNormal
	addvar VAR_REWARD_STATE, 1
	setflashlevel 1
PitArena_OnResumeNormal:
	end

PitArena_OnTransition:
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnTransitionNormal
PitArena_OnTransitionNormal::
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_RewardDrop1::
	finditem ITEM_RARE_CANDY
	end

PitArena_RewardDrop2::
	finditem ITEM_NET_BALL
	end

PitArena_RewardDrop3::
	finditem ITEM_MAWILITE
	end

PitArena_Warp::
	callnative SetAutosaveFlag
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
	goto_if_unset FLAG_AUTO_SAVE, PitArenaNoAutoSave
	clearflag FLAG_SAVING_FIELD_EFFECT
	dofieldeffect(FLDEFF_SAVING)
	waitfieldeffect(FLDEFF_SAVING)
	callnative AutoSave
PitArenaNoAutoSave::
	lockall
	addvar VAR_PIT_FLOOR, 1
	callnative LevelUpParty
	special TryLevelUpOverworldEvo
PitArenaContinueAfterEvo::
	clearflag FLAG_FLOOR_CLEARED
	setflag FLAG_REWARD_ITEM_1
	setflag FLAG_REWARD_ITEM_2
	setflag FLAG_REWARD_ITEM_3
	setvar VAR_REWARD_STATE, 0
	callnative BufferMapFloorString
	callnative SetRandomTrainers
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_WarpFloor100
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	goto PitArena_WarpEnd
PitArena_WarpFloor100::
	setvar VAR_FINAL_FLOOR, 2
	setvar VAR_REWARD_STATE, 2
	warpteleport MAP_PIT_ARENA, 9, 11
	waitstate
PitArena_WarpEnd::
	releaseall
	end


PitArena_TrainerBattle::
	trainerbattle_single TRAINER_RANDOM_BATTLE_0, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle1::
	trainerbattle_single TRAINER_RANDOM_BATTLE_1, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle2::
	trainerbattle_single TRAINER_RANDOM_BATTLE_2, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle3::
	trainerbattle_single TRAINER_RANDOM_BATTLE_3, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle4::
	trainerbattle_double TRAINER_RANDOM_BATTLE_4, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_Text_NotEnoughMons, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle5::
	trainerbattle_double TRAINER_RANDOM_BATTLE_5, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_Text_NotEnoughMons, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle6::
	trainerbattle_double TRAINER_RANDOM_BATTLE_6, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_Text_NotEnoughMons, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle7::
	trainerbattle_double TRAINER_RANDOM_BATTLE_7, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_Text_NotEnoughMons, PitArena_TrainerBattleFinished
	end

PitArena_Text_Intro:
	.string ".$"

PitArena_Text_Defeat:
	.string ".$"

PitArena_Text_NotEnoughMons:
	.string "Not enough mons.$"

PitArena_TrainerBattleFinished::
	end
