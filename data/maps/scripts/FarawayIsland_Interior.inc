FarawayIsland_Interior_MapScripts:: @ 8267CFA
	map_script 5, FarawayIsland_Interior_MapScript1_267D54
	map_script 3, FarawayIsland_Interior_MapScript1_267D72
	map_script 2, FarawayIsland_Interior_MapScript2_267D98
	map_script 7, FarawayIsland_Interior_MapScript1_267D0F
	.byte 0

FarawayIsland_Interior_MapScript1_267D0F: @ 8267D0F
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, FarawayIsland_Interior_EventScript_267D19
	end

FarawayIsland_Interior_EventScript_267D19:: @ 8267D19
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 1
	goto_eq FarawayIsland_Interior_EventScript_267D4B
	compare_var_to_value VAR_RESULT, 4
	goto_eq FarawayIsland_Interior_EventScript_267D4B
	compare_var_to_value VAR_RESULT, 5
	goto_eq FarawayIsland_Interior_EventScript_267D4B
	compare_var_to_value VAR_RESULT, 10
	goto_eq FarawayIsland_Interior_EventScript_267D4B
	return

FarawayIsland_Interior_EventScript_267D4B:: @ 8267D4B
	setvar VAR_0x8004, 1
	special sub_81D4A90
	return

FarawayIsland_Interior_MapScript1_267D54: @ 8267D54
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, FarawayIsland_Interior_EventScript_267D5E
	end

FarawayIsland_Interior_EventScript_267D5E:: @ 8267D5E
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, FarawayIsland_Interior_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_MapScript1_267D72: @ 8267D72
	setvar VAR_0x403A, 0
	setvar VAR_0x4001, 1
	checkflag FLAG_0x1CA
	call_if 0, FarawayIsland_Interior_EventScript_267D86
	end

FarawayIsland_Interior_EventScript_267D86:: @ 8267D86
	checkflag FLAG_0x1C7
	goto_eq FarawayIsland_Interior_EventScript_27374E
	clearflag FLAG_0x2CE
	setvar VAR_0x4001, 0
	return

FarawayIsland_Interior_MapScript2_267D98: @ 8267D98
	map_script_2 VAR_0x4001, 0, FarawayIsland_Interior_EventScript_267DA2
	.2byte 0

FarawayIsland_Interior_EventScript_267DA2:: @ 8267DA2
	lockall
	playse SE_PIN
	applymovement 1, FarawayIsland_Interior_Movement_272598
	waitmovement 0
	applymovement 1, FarawayIsland_Interior_Movement_27259A
	waitmovement 0
	applymovement 1, FarawayIsland_Interior_Movement_267DCE
	waitmovement 0
	moveobjectoffscreen 1
	setvar VAR_0x4001, 1
	releaseall
	end

FarawayIsland_Interior_Movement_267DCE: @ 8267DCE
	step_up
	step_up
	step_up
	step_25
	step_54
	step_end

FarawayIsland_Interior_Movement_267DD4: @ 8267DD4
	step_55
	step_end

FarawayIsland_Interior_Movement_267DD6: @ 8267DD6
	step_40
	step_16
	step_16
	step_41
	step_1d
	step_1d
	step_end

FarawayIsland_Interior_Movement_267DDD: @ 8267DDD
	step_40
	step_16
	step_16
	step_41
	step_1e
	step_1e
	step_end

FarawayIsland_Interior_Movement_267DE4: @ 8267DE4
	step_40
	step_16
	step_16
	step_41
	step_20
	step_20
	step_end

FarawayIsland_Interior_Movement_267DEB: @ 8267DEB
	step_40
	step_16
	step_16
	step_41
	step_1f
	step_1f
	step_end

FarawayIsland_Interior_EventScript_267DF2:: @ 8267DF2
	lock
	faceplayer
	applymovement 1, FarawayIsland_Interior_Movement_267DD4
	waitmovement 0
	setvar VAR_0x8004, 0
	special sub_81D4A90
	message FarawayIsland_Interior_Text_2C6DFF
	waitse
	playmoncry SPECIES_MEW, 2
	compare_var_to_value VAR_FACING, 2
	call_if 1, FarawayIsland_Interior_EventScript_267EAF
	compare_var_to_value VAR_FACING, 1
	call_if 1, FarawayIsland_Interior_EventScript_267EBA
	compare_var_to_value VAR_FACING, 3
	call_if 1, FarawayIsland_Interior_EventScript_267EC5
	compare_var_to_value VAR_FACING, 4
	call_if 1, FarawayIsland_Interior_EventScript_267ED0
	special sub_81D4BEC
	delay 40
	waitmoncry
	setvar VAR_0x8004, 151
	setvar VAR_0x8005, 30
	setvar VAR_0x8006, 0
	special DoScriptedWildBattle
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special sub_80B0934
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 1
	goto_eq FarawayIsland_Interior_EventScript_267E96
	compare_var_to_value VAR_RESULT, 4
	goto_eq FarawayIsland_Interior_EventScript_267EA4
	compare_var_to_value VAR_RESULT, 5
	goto_eq FarawayIsland_Interior_EventScript_267EA4
	compare_var_to_value VAR_RESULT, 10
	goto_eq FarawayIsland_Interior_EventScript_267EA4
	setflag FLAG_0x1CA
	release
	end

FarawayIsland_Interior_EventScript_267E96:: @ 8267E96
	setflag FLAG_0x1C7
	setvar VAR_0x8004, 151
	goto FarawayIsland_Interior_EventScript_273776
	end

FarawayIsland_Interior_EventScript_267EA4:: @ 8267EA4
	setvar VAR_0x8004, 151
	goto FarawayIsland_Interior_EventScript_273776
	end

FarawayIsland_Interior_EventScript_267EAF:: @ 8267EAF
	applymovement 1, FarawayIsland_Interior_Movement_267DD6
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267EBA:: @ 8267EBA
	applymovement 1, FarawayIsland_Interior_Movement_267DDD
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267EC5:: @ 8267EC5
	applymovement 1, FarawayIsland_Interior_Movement_267DE4
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_267ED0:: @ 8267ED0
	applymovement 1, FarawayIsland_Interior_Movement_267DEB
	waitmovement 0
	return

gUnknown_08267EDB:: @ 8267EDB
	.incbin "baserom.gba", 0x267edb, 0x3a
