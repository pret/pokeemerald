PitArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_OnTransition
	.byte 0

PitArena_OnTransition:
	random 53
	addvar VAR_RESULT, 4
	setvar VAR_OBJ_GFX_ID_0, VAR_RESULT
	random 53
	addvar VAR_RESULT, 4
	setvar VAR_OBJ_GFX_ID_1, VAR_RESULT
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_TrainerBattle::
	trainerbattle_single TRAINER_RANDOM_BATTLE, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end


