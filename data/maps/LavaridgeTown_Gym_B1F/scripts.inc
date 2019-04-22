LavaridgeTown_Gym_B1F_MapScripts:: @ 81FF87E
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
	.byte 0

LavaridgeTown_Gym_B1F_OnTransition: @ 81FF884
	call LavaridgeTown_Gym_B1F_EventScript_1FF88F
	call LavaridgeTown_Gym_B1F_EventScript_1FF8DC
	end

LavaridgeTown_Gym_B1F_EventScript_1FF88F:: @ 81FF88F
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	checktrainerflag TRAINER_KEEGAN
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8B1
	setvar VAR_TEMP_7, 1

LavaridgeTown_Gym_B1F_EventScript_1FF8B1:: @ 81FF8B1
	checktrainerflag TRAINER_JACE
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8BF
	setvar VAR_TEMP_8, 1

LavaridgeTown_Gym_B1F_EventScript_1FF8BF:: @ 81FF8BF
	checktrainerflag TRAINER_JEFF
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8CD
	setvar VAR_TEMP_9, 1

LavaridgeTown_Gym_B1F_EventScript_1FF8CD:: @ 81FF8CD
	checktrainerflag TRAINER_ELI
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8DB
	setvar VAR_TEMP_A, 1

LavaridgeTown_Gym_B1F_EventScript_1FF8DB:: @ 81FF8DB
	return

LavaridgeTown_Gym_B1F_EventScript_1FF8DC:: @ 81FF8DC
	checktrainerflag TRAINER_KEEGAN
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8E9
	setobjectmovementtype 2, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_B1F_EventScript_1FF8E9:: @ 81FF8E9
	checktrainerflag TRAINER_JACE
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF8F6
	setobjectmovementtype 1, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_B1F_EventScript_1FF8F6:: @ 81FF8F6
	checktrainerflag TRAINER_JEFF
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF903
	setobjectmovementtype 3, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_B1F_EventScript_1FF903:: @ 81FF903
	checktrainerflag TRAINER_ELI
	goto_if_eq LavaridgeTown_Gym_B1F_EventScript_1FF910
	setobjectmovementtype 4, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_B1F_EventScript_1FF910:: @ 81FF910
	return

