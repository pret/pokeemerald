MarineCave_End_MapScripts:: @ 823AFDF
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_MapScript1_23AFEA
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_MapScript1_23AFEA: @ 823AFEA
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_23AFF4
	end

MarineCave_End_EventScript_23AFF4:: @ 823AFF4
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

MarineCave_End_OnTransition: @ 823B008
	call_if_unset FLAG_DEFEATED_KYOGRE, MarineCave_End_EventScript_23B012
	end

MarineCave_End_EventScript_23B012:: @ 823B012
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	setvar VAR_TEMP_1, 1
	return

MarineCave_End_EventScript_23B01B:: @ 823B01B
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 1, MarineCave_End_Movement_23B09D
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 1
	setwildbattle SPECIES_KYOGRE, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq MarineCave_End_EventScript_23B084
	compare VAR_RESULT, 4
	goto_if_eq MarineCave_End_EventScript_23B092
	compare VAR_RESULT, 5
	goto_if_eq MarineCave_End_EventScript_23B092
	setvar VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	releaseall
	end

MarineCave_End_EventScript_23B084:: @ 823B084
	setvar VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	goto MarineCave_End_EventScript_27376D
	end

MarineCave_End_EventScript_23B092:: @ 823B092
	setvar VAR_0x8004, 404
	goto MarineCave_End_EventScript_273776
	end

MarineCave_End_Movement_23B09D: @ 823B09D
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

