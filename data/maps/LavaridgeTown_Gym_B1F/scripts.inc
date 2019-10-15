LavaridgeTown_Gym_B1F_MapScripts:: @ 81FF87E
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
	.byte 0

LavaridgeTown_Gym_B1F_OnTransition: @ 81FF884
	call LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_B1F_EventScript_CheckHideTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars:: @ 81FF88F
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	checktrainerflag TRAINER_KEEGAN
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar
	setvar VAR_TEMP_7, 1
LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar:: @ 81FF8B1
	checktrainerflag TRAINER_JACE
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar
	setvar VAR_TEMP_8, 1
LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar:: @ 81FF8BF
	checktrainerflag TRAINER_JEFF
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar
	setvar VAR_TEMP_9, 1
LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar:: @ 81FF8CD
	checktrainerflag TRAINER_ELI
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_A, 1
LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars:: @ 81FF8DB
	return

LavaridgeTown_Gym_B1F_EventScript_CheckHideTrainers:: @ 81FF8DC
	checktrainerflag TRAINER_KEEGAN
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_CheckHideJace
	setobjectmovementtype 2, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_B1F_EventScript_CheckHideJace:: @ 81FF8E9
	checktrainerflag TRAINER_JACE
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_CheckHideJeff
	setobjectmovementtype 1, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_B1F_EventScript_CheckHideJeff:: @ 81FF8F6
	checktrainerflag TRAINER_JEFF
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_CheckHideEli
	setobjectmovementtype 3, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_B1F_EventScript_CheckHideEli:: @ 81FF903
	checktrainerflag TRAINER_ELI
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_EndCheckHideTrainers
	setobjectmovementtype 4, MOVEMENT_TYPE_HIDDEN
LavaridgeTown_Gym_B1F_EventScript_EndCheckHideTrainers:: @ 81FF910
	return

