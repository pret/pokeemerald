PitArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PitArena_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PitArena_OnFrame
	.byte 0

PitArena_OnFrame:
	map_script_2 VAR_REWARD_STATE, 1, PitArena_OnFrameRewardDrop
	.2byte 0

PitArena_OnFrameRewardDrop::
	lockall
	setvar VAR_REWARD_STATE, 2
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	additem 6
	additem 7
	callnative UpdateObjectEventsFromScript
	releaseall
	end

PitArena_OnResume:
	callnative CheckFloorCleared
	setflashlevel 1
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnResumeNormal
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_REWARD_STATE, 1
PitArena_OnResumeNormal:
	end

PitArena_OnTransition:
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnTransitionNormal
PitArena_OnTransitionNormal::
	callnative StartTimer1Script
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_Warp::
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
	lockall
	addvar VAR_PIT_FLOOR, 1
	clearflag FLAG_FLOOR_CLEARED
	setflag FLAG_REWARD_ITEM_1
	setflag FLAG_REWARD_ITEM_2
	setvar VAR_REWARD_STATE, 0
	callnative BufferMapFloorString
	callnative SetRandomTrainers
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
PitArena_WarpEnd::
	releaseall
	end

PitArena_Debug::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	end

PitArena_TrainerBattleFinished::
	end

PitArena_HealNPC::
	lockall
	special HealPlayerParty
	msgbox PitArena_HealNPC_Text, MSGBOX_DEFAULT
	release
	end

PitArena_HealNPC_Text:
	.string "Your party has been healed.\p"
	.string "Have a nice descent.$"

PitArena_RewardDrop1::
	finditem ITEM_RARE_CANDY
	end

PitArena_RewardDrop2::
	finditem ITEM_RARE_CANDY
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

PitArena_Text_Intro:
	.string "$"

PitArena_Text_Defeat:
	.string "$"
