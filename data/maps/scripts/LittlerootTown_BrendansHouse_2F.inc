LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script 3, LittlerootTown_BrendansHouse_2F_MapScript1_1F83EE
	map_script 4, LittlerootTown_BrendansHouse_2F_MapScript2_1F846A
	.byte 0

LittlerootTown_BrendansHouse_2F_MapScript1_1F83EE: @ 81F83EE
	compare_var_to_value VAR_0x408D, 2
	call_if 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8457
	compare_var_to_value VAR_0x408D, 3
	call_if 4, LittlerootTown_BrendansHouse_2F_EventScript_1F841A
	compare_var_to_value VAR_0x4092, 4
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_2926FE
	call LittlerootTown_BrendansHouse_2F_EventScript_275CE1
	setvar VAR_0x4089, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F841A:: @ 81F841A
	checkflag FLAG_0x124
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8433
	compare_var_to_value VAR_0x4084, 2
	goto_if 4, LittlerootTown_BrendansHouse_2F_EventScript_1F8456
	goto LittlerootTown_BrendansHouse_2F_EventScript_1F8433

LittlerootTown_BrendansHouse_2F_EventScript_1F8433:: @ 81F8433
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8456
	compare_var_to_value VAR_0x40D3, 2
	goto_if 4, LittlerootTown_BrendansHouse_2F_EventScript_1F9309
	setobjectxyperm 1, 0, 2
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8456:: @ 81F8456
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8457:: @ 81F8457
	checkplayergender
	compare_var_to_value VAR_RESULT, 1
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8464
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8464:: @ 81F8464
	setvar VAR_0x408D, 2
	return

LittlerootTown_BrendansHouse_2F_MapScript2_1F846A: @ 81F846A
	map_script_2 VAR_0x4089, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8474
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_1F8474:: @ 81F8474
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq gUnknown_08275D0C
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8481:: @ 81F8481
	lockall
	compare_var_to_value VAR_0x408D, 2
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8497
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F9991, 4
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8497:: @ 81F8497
	delay 10
	addobject 1
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85BC
	waitmovement 0
	playse SE_PIN
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_272598
	waitmovement 0
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_27259A
	waitmovement 0
	delay 10
	playbgm BGM_BOY_SUP, 1
	compare_var_to_value VAR_FACING, 2
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F8507
	compare_var_to_value VAR_FACING, 1
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F8536
	compare_var_to_value VAR_FACING, 3
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F8565
	compare_var_to_value VAR_FACING, 4
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_1F8594
	setvar VAR_0x408D, 3
	setflag FLAG_0x331
	clearflag FLAG_0x2F8
	setvar VAR_0x4050, 1
	savebgm SE_STOP
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8507:: @ 81F8507
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85C0
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A8
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F97B4, 4
	closemessage
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_1F85CF
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85C6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8536:: @ 81F8536
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85D7
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A8
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F97B4, 4
	closemessage
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_1F85E2
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85DB
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8565:: @ 81F8565
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85E8
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A8
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F97B4, 4
	closemessage
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_1F85F6
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85ED
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8594:: @ 81F8594
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85FD
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A6
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F97B4, 4
	closemessage
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F8604
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_1F85BC: @ 81F85BC
	step_down
	step_down
	step_27
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85C0: @ 81F85C0
	step_left
	step_left
	step_down
	step_down
	step_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85C6: @ 81F85C6
	step_up
	step_up
	step_up
	step_left
	step_left
	step_left
	step_left
	step_26
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85CF: @ 81F85CF
	step_14
	step_26
	step_14
	step_14
	step_14
	step_14
	step_27
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85D7: @ 81F85D7
	step_left
	step_left
	step_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85DB: @ 81F85DB
	step_up
	step_left
	step_left
	step_left
	step_left
	step_26
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85E2: @ 81F85E2
	step_14
	step_26
	step_14
	step_14
	step_27
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85E8: @ 81F85E8
	step_left
	step_left
	step_down
	step_27
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85ED: @ 81F85ED
	step_up
	step_up
	step_left
	step_left
	step_left
	step_left
	step_left
	step_26
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85F6: @ 81F85F6
	step_13
	step_14
	step_26
	step_14
	step_14
	step_27
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85FD: @ 81F85FD
	step_left
	step_left
	step_left
	step_left
	step_left
	step_25
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F8604: @ 81F8604
	step_up
	step_left
	step_left
	step_26
	step_end

	.incbin "baserom.gba", 0x1f8609, 0x4

