TerraCave_End_MapScripts:: @ 823B0B0
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_MapScript1_23B0BB
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_MapScript1_23B0BB: @ 823B0BB
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_23B0C5
	end

TerraCave_End_EventScript_23B0C5:: @ 823B0C5
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

TerraCave_End_OnTransition: @ 823B0D9
	call_if_unset FLAG_DEFEATED_GROUDON, TerraCave_End_EventScript_23B0E3
	end

TerraCave_End_EventScript_23B0E3:: @ 823B0E3
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
	setvar VAR_TEMP_1, 1
	return

TerraCave_End_EventScript_23B0EC:: @ 823B0EC
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 1, TerraCave_End_Movement_23B16E
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 1
	setwildbattle SPECIES_GROUDON, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq TerraCave_End_EventScript_23B155
	compare VAR_RESULT, 4
	goto_if_eq TerraCave_End_EventScript_23B163
	compare VAR_RESULT, 5
	goto_if_eq TerraCave_End_EventScript_23B163
	setvar VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	releaseall
	end

TerraCave_End_EventScript_23B155:: @ 823B155
	setvar VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	goto TerraCave_End_EventScript_27376D
	end

TerraCave_End_EventScript_23B163:: @ 823B163
	setvar VAR_0x8004, 405
	goto TerraCave_End_EventScript_273776
	end

TerraCave_End_Movement_23B16E: @ 823B16E
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

