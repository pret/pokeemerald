PitArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PitArena_OnResume
	.byte 0

PitArena_OnResume:
	callnative CheckFloorCleared
	setflashlevel 1
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnResumeNormal
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
PitArena_OnResumeNormal:
	return

PitArena_OnTransition:
PitArena_OnTransitionNormal::
	callnative StartTimer1Script
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_TrainerBattle::
	trainerbattle_single TRAINER_RANDOM_BATTLE_0, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end
PitArena_TrainerBattle1::
	trainerbattle_single TRAINER_RANDOM_BATTLE_1, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end
PitArena_TrainerBattle2::
	trainerbattle_single TRAINER_RANDOM_BATTLE_2, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end
PitArena_TrainerBattle3::
	trainerbattle_single TRAINER_RANDOM_BATTLE_3, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

PitArena_Warp::
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
	lockall
	addvar VAR_PIT_FLOOR, 1
	clearflag FLAG_FLOOR_CLEARED
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
