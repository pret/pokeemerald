TerraCave_End_MapScripts:: @ 823B0B0
	map_script 5, TerraCave_End_MapScript1_23B0BB
	map_script 3, TerraCave_End_MapScript1_23B0D9
	.byte 0

TerraCave_End_MapScript1_23B0BB: @ 823B0BB
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, TerraCave_End_EventScript_23B0C5
	end

TerraCave_End_EventScript_23B0C5:: @ 823B0C5
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, TerraCave_End_EventScript_27374E
	removeobject 1
	return

TerraCave_End_MapScript1_23B0D9: @ 823B0D9
	checkflag FLAG_0x1BF
	call_if 0, TerraCave_End_EventScript_23B0E3
	end

TerraCave_End_EventScript_23B0E3:: @ 823B0E3
	clearflag FLAG_0x30F
	setvar VAR_0x4001, 1
	return

TerraCave_End_EventScript_23B0EC:: @ 823B0EC
	lockall
	applymovement 255, TerraCave_End_Movement_2725B2
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
	setvar VAR_0x4001, 0
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 1
	goto_eq TerraCave_End_EventScript_23B155
	compare_var_to_value VAR_RESULT, 4
	goto_eq TerraCave_End_EventScript_23B163
	compare_var_to_value VAR_RESULT, 5
	goto_eq TerraCave_End_EventScript_23B163
	setvar VAR_0x4039, 1
	setflag FLAG_0x1BF
	releaseall
	end

TerraCave_End_EventScript_23B155:: @ 823B155
	setvar VAR_0x4039, 1
	setflag FLAG_0x1BF
	goto TerraCave_End_EventScript_27376D
	end

TerraCave_End_EventScript_23B163:: @ 823B163
	setvar VAR_0x8004, 405
	goto TerraCave_End_EventScript_273776
	end

TerraCave_End_Movement_23B16E: @ 823B16E
	step_5e
	step_62
	step_14
	step_14
	step_63
	step_14
	step_14
	step_63
	step_end

