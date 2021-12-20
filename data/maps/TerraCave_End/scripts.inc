.set LOCALID_GROUDON, 1

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveGroudon
	end

TerraCave_End_EventScript_TryRemoveGroudon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_GROUDON
	return

TerraCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_GROUDON, TerraCave_End_EventScript_ShowGroudon
	end

TerraCave_End_EventScript_ShowGroudon::
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
	setvar VAR_TEMP_1, 1
	return

TerraCave_End_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GROUDON, TerraCave_End_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
	setwildbattle SPECIES_GROUDON, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TerraCave_End_EventScript_DefeatedGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TerraCave_End_EventScript_RanFromGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TerraCave_End_EventScript_RanFromGroudon
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	releaseall
	end

TerraCave_End_EventScript_DefeatedGroudon::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	goto Common_EventScript_RemoveStaticPokemon
	end

TerraCave_End_EventScript_RanFromGroudon::
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

