LittlerootTown_MaysHouse_2F_MapScripts:: @ 81F9296
	map_script 3, LittlerootTown_MaysHouse_2F_MapScript1_1F92A1
	map_script 4, LittlerootTown_MaysHouse_2F_MapScript2_1F931D
	.byte 0

LittlerootTown_MaysHouse_2F_MapScript1_1F92A1: @ 81F92A1
	compare_var_to_value VAR_0x408D, 2
	call_if 0, LittlerootTown_MaysHouse_2F_EventScript_1F930A
	compare_var_to_value VAR_0x408D, 3
	call_if 4, LittlerootTown_MaysHouse_2F_EventScript_1F92CD
	compare_var_to_value VAR_0x4092, 4
	call_if 1, LittlerootTown_MaysHouse_2F_EventScript_2926FE
	call LittlerootTown_MaysHouse_2F_EventScript_275CE1
	setvar VAR_0x4089, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_1F92CD:: @ 81F92CD
	checkflag FLAG_0x124
	goto_eq LittlerootTown_MaysHouse_2F_EventScript_1F92E6
	compare_var_to_value VAR_0x4084, 2
	goto_if 4, LittlerootTown_MaysHouse_2F_EventScript_1F9309
	goto LittlerootTown_MaysHouse_2F_EventScript_1F92E6

LittlerootTown_MaysHouse_2F_EventScript_1F92E6:: @ 81F92E6
	checkplayergender
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_MaysHouse_2F_EventScript_1F9309
	compare_var_to_value VAR_0x40D3, 2
	goto_if 4, LittlerootTown_MaysHouse_2F_EventScript_1F9309
	setobjectxyperm 1, 8, 2
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F9309:: @ 81F9309
LittlerootTown_MaysHouse_2F_EventScript_1F9309:: @ 81F9309
	return

LittlerootTown_MaysHouse_2F_EventScript_1F930A:: @ 81F930A
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_MaysHouse_2F_EventScript_1F9317
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9317:: @ 81F9317
	setvar VAR_0x408D, 2
	return

LittlerootTown_MaysHouse_2F_MapScript2_1F931D: @ 81F931D
	map_script_2 VAR_0x4089, 0, LittlerootTown_MaysHouse_2F_EventScript_1F9327
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_1F9327:: @ 81F9327
	checkplayergender
	compare_var_to_value VAR_RESULT, 1
	goto_eq gUnknown_08275D0C
	end

LittlerootTown_MaysHouse_2F_EventScript_1F9334:: @ 81F9334
	lockall
	compare_var_to_value VAR_0x408D, 2
	goto_eq LittlerootTown_MaysHouse_2F_EventScript_1F934A
	msgbox LittlerootTown_MaysHouse_2F_Text_1F9991, 4
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F934A:: @ 81F934A
	delay 10
	addobject 1
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F946F
	waitmovement 0
	playse SE_PIN
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_272598
	waitmovement 0
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_27259A
	waitmovement 0
	delay 10
	playbgm BGM_GIRL_SUP, 1
	compare_var_to_value VAR_FACING, 2
	call_if 1, LittlerootTown_MaysHouse_2F_EventScript_1F93BA
	compare_var_to_value VAR_FACING, 1
	call_if 1, LittlerootTown_MaysHouse_2F_EventScript_1F93E9
	compare_var_to_value VAR_FACING, 3
	call_if 1, LittlerootTown_MaysHouse_2F_EventScript_1F9418
	compare_var_to_value VAR_FACING, 4
	call_if 1, LittlerootTown_MaysHouse_2F_EventScript_1F9440
	setvar VAR_0x408D, 3
	setflag FLAG_0x332
	clearflag FLAG_0x2D2
	setvar VAR_0x4050, 1
	savebgm SE_STOP
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F93BA:: @ 81F93BA
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F9473
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_Text_1F959C, 4
	closemessage
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_1F9483
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F9479
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F93E9:: @ 81F93E9
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F948B
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_Text_1F959C, 4
	closemessage
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_1F9497
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F948F
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9418:: @ 81F9418
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F949D
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_2725A6
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_Text_1F959C, 4
	closemessage
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94A4
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9440:: @ 81F9440
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94AD
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_Text_1F959C, 4
	closemessage
	applymovement 255, LittlerootTown_MaysHouse_2F_Movement_1F94BB
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94B2
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_1F946F: @ 81F946F
	step_down
	step_down
	step_28
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9473: @ 81F9473
	step_right
	step_right
	step_down
	step_down
	step_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9479: @ 81F9479
	step_up
	step_up
	step_up
	step_28
	step_right
	step_right
	step_right
	step_right
	step_26
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9483: @ 81F9483
	step_14
	step_26
	step_14
	step_14
	step_14
	step_14
	step_28
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F948B: @ 81F948B
	step_right
	step_right
	step_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F948F: @ 81F948F
	step_up
	step_28
	step_right
	step_right
	step_right
	step_right
	step_26
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9497: @ 81F9497
	step_14
	step_26
	step_14
	step_14
	step_28
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F949D: @ 81F949D
	step_right
	step_right
	step_right
	step_right
	step_right
	step_25
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94A4: @ 81F94A4
	step_up
	step_right
	step_right
	step_26
	step_end

	.incbin "baserom.gba", 0x1f94a9, 0x4

LittlerootTown_MaysHouse_2F_Movement_1F94AD: @ 81F94AD
	step_right
	step_right
	step_down
	step_28
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94B2: @ 81F94B2
	step_up
	step_up
	step_right
	step_right
	step_right
	step_right
	step_right
	step_26
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94BB: @ 81F94BB
	step_14
	step_26
	step_14
	step_14
	step_28
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_1F94C1:: @ 81F94C1
LittlerootTown_MaysHouse_2F_EventScript_1F94C1:: @ 81F94C1
	lockall
	checkflag FLAG_0x124
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F94F7
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F94E3
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F94ED
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F94E3:: @ 81F94E3
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F978A, 4
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F94ED:: @ 81F94ED
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F9962, 4
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F94F7:: @ 81F94F7
	applymovement VAR_LAST_TALKED, LittlerootTown_BrendansHouse_2F_Movement_27259E
	waitmovement 0
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F951D
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F952F
	setflag FLAG_0x125
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F951D:: @ 81F951D
	checkflag FLAG_0x125
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F9541
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F99C9, 4
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F952F:: @ 81F952F
	checkflag FLAG_0x125
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F954A
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F9B0D, 4
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F9541:: @ 81F9541
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F9A9E, 4
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F954A:: @ 81F954A
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F9BE7, 4
	return

