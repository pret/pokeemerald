
PitArena_OnFrame:
	map_script_2 VAR_REWARD_STATE, 1, PitArena_OnFrameRewardDrop
	.2byte 0

PitArena_OnFrameRewardDrop::
	lockall
	setvar VAR_PIT_TUTOR_STATE, 0
	setvar VAR_REWARD_STATE, 2
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
	addobject 9
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_4:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	addobject 9
	addobject 10
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_5:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	clearflag FLAG_REWARD_ITEM_3
	addobject 9
	addobject 10
	addobject 11
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
	callnative SetWarpTileActive
	setflashlevel 0
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnResumeNormal
	addvar VAR_REWARD_STATE, 1
	goto_if_ne VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY, 0, PitArena_OnResumeNormal
	setflashlevel 1
PitArena_OnResumeNormal:
	end

PitArena_OnTransition:
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnTransitionNormal
PitArena_OnTransitionNormal::
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	goto_if_ne VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY, 0, PitArena_OnTransitionNormalNoFlash
	setflashlevel 1
	return

PitArena_OnTransitionNormalNoFlash::
	setflashlevel 0
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
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
Pit_Warp_Advance_Floor::
	callnative SetAutosaveFlag
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
	callnative SetRandomMonEncounter
	warpteleport MAP_RANDOM, 9, 8
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
