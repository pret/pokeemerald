Route119_MapScripts:: @ 81F4424
	map_script 5, Route119_MapScript1_1F442F
	map_script 3, Route119_MapScript1_1F444D
	.byte 0

Route119_MapScript1_1F442F: @ 81F442F
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, Route119_EventScript_1F4439
	end

Route119_EventScript_1F4439:: @ 81F4439
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, Route119_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

Route119_MapScript1_1F444D: @ 81F444D
	call Route119_EventScript_271ED7
	call Route119_EventScript_271EFB
	compare_var_to_value VAR_0x40B3, 1
	call_if 1, Route119_EventScript_1F4466
	special sub_8139648
	end

Route119_EventScript_1F4466:: @ 81F4466
	setflag FLAG_0x37D
	clearflag FLAG_0x37C
	setvar VAR_0x40B3, 2
	return

Route119_EventScript_1F4472:: @ 81F4472
	setvar VAR_0x4001, 1
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F447D:: @ 81F447D
	setvar VAR_0x4001, 2
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F4488:: @ 81F4488
	lockall
	addobject 25
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, Route119_EventScript_1F4501
	compare_var_to_value VAR_RESULT, 1
	call_if 1, Route119_EventScript_1F4506
	delay 65
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F46C6
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F46D1
	applymovement 255, Route119_Movement_2725AA
	waitmovement 0
	delay 30
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F4700
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F470F
	removeobject 25
	addobject 16
	delay 30
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route119_EventScript_1F450B
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route119_EventScript_1F4585
	releaseall
	end

Route119_EventScript_1F4501:: @ 81F4501
	playbgm BGM_GIRL_SUP, 1
	return

Route119_EventScript_1F4506:: @ 81F4506
	playbgm BGM_BOY_SUP, 1
	return

Route119_EventScript_1F450B:: @ 81F450B
	msgbox Route119_Text_1F49FD, 4
	switch VAR_FIRST_POKE
	case 0, Route119_EventScript_1F453A
	case 1, Route119_EventScript_1F454A
	case 2, Route119_EventScript_1F455A
	end

Route119_EventScript_1F453A:: @ 81F453A
	trainerbattle 3, TRAINER_MAY_6, 0, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F454A:: @ 81F454A
	trainerbattle 3, TRAINER_MAY_9, 0, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F455A:: @ 81F455A
	trainerbattle 3, TRAINER_MAY_3, 0, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F456A:: @ 81F456A
	msgbox Route119_Text_1F4AF3, 4
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4B56, 4
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F4585:: @ 81F4585
	msgbox Route119_Text_1F4C9A, 4
	switch VAR_FIRST_POKE
	case 0, Route119_EventScript_1F45B4
	case 1, Route119_EventScript_1F45C4
	case 2, Route119_EventScript_1F45D4
	end

Route119_EventScript_1F45B4:: @ 81F45B4
	trainerbattle 3, TRAINER_BRENDAN_6, 0, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45C4:: @ 81F45C4
	trainerbattle 3, TRAINER_BRENDAN_9, 0, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45D4:: @ 81F45D4
	trainerbattle 3, TRAINER_BRENDAN_3, 0, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45E4:: @ 81F45E4
	msgbox Route119_Text_1F4D4B, 4
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4DB5, 4
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F45FF:: @ 81F45FF
	giveitem_std ITEM_HM02
	setflag FLAG_0x06E
	return

Route119_EventScript_1F460F:: @ 81F460F
	closemessage
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F4700
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F470F
	removeobject 16
	addobject 25
	delay 30
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F46DC
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F46EE
	removeobject 25
	setvar VAR_0x4072, 1
	savebgm SE_STOP
	fadedefaultbgm
	delay 60
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F46A0
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F46A8
	addobject 43
	applymovement 43, Route119_Movement_1F4752
	waitmovement 0
	addvar VAR_0x40D1, 1
	msgbox Route119_Text_1F4E60, 4
	closemessage
	compare_var_to_value VAR_0x4001, 1
	call_if 1, Route119_EventScript_1F46B0
	compare_var_to_value VAR_0x4001, 2
	call_if 1, Route119_EventScript_1F46BB
	removeobject 43
	releaseall
	end

Route119_EventScript_1F46A0:: @ 81F46A0
	setobjectxyperm 43, 27, 25
	return

Route119_EventScript_1F46A8:: @ 81F46A8
	setobjectxyperm 43, 28, 25
	return

Route119_EventScript_1F46B0:: @ 81F46B0
	applymovement 43, Route119_Movement_1F475A
	waitmovement 0
	return

Route119_EventScript_1F46BB:: @ 81F46BB
	applymovement 43, Route119_Movement_1F4763
	waitmovement 0
	return

Route119_EventScript_1F46C6:: @ 81F46C6
	applymovement 25, Route119_Movement_1F4728
	waitmovement 0
	return

Route119_EventScript_1F46D1:: @ 81F46D1
	applymovement 25, Route119_Movement_1F4732
	waitmovement 0
	return

Route119_EventScript_1F46DC:: @ 81F46DC
	applymovement 255, Route119_Movement_1F471E
	applymovement 25, Route119_Movement_1F473D
	waitmovement 0
	return

Route119_EventScript_1F46EE:: @ 81F46EE
	applymovement 255, Route119_Movement_1F4723
	applymovement 25, Route119_Movement_1F4747
	waitmovement 0
	return

Route119_EventScript_1F4700:: @ 81F4700
	setobjectxyperm 16, 25, 32
	setobjectxyperm 25, 25, 32
	return

Route119_EventScript_1F470F:: @ 81F470F
	setobjectxyperm 16, 26, 32
	setobjectxyperm 25, 26, 32
	return

Route119_Movement_1F471E: @ 81F471E
	step_14
	step_28
	step_13
	step_26
	step_end

Route119_Movement_1F4723: @ 81F4723
	step_14
	step_27
	step_13
	step_26
	step_end

Route119_Movement_1F4728: @ 81F4728
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_16
	step_end

Route119_Movement_1F4732: @ 81F4732
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_16
	step_end

Route119_Movement_1F473D: @ 81F473D
	step_18
	step_16
	step_16
	step_16
	step_18
	step_16
	step_16
	step_16
	step_16
	step_end

Route119_Movement_1F4747: @ 81F4747
	step_17
	step_16
	step_16
	step_16
	step_18
	step_18
	step_16
	step_16
	step_16
	step_16
	step_end

Route119_Movement_1F4752: @ 81F4752
	step_down
	step_down
	step_down
	step_down
	step_left
	step_left
	step_down
	step_end

Route119_Movement_1F475A: @ 81F475A
	step_up
	step_right
	step_right
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

Route119_Movement_1F4763: @ 81F4763
	step_up
	step_right
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

Route119_EventScript_1F476B:: @ 81F476B
	msgbox Route119_Text_1F5261, 2
	end

Route119_EventScript_1F4774:: @ 81F4774
	msgbox Route119_Text_1F530E, 3
	end

Route119_EventScript_1F477D:: @ 81F477D
	msgbox Route119_Text_1F5327, 3
	end

Route119_EventScript_1F4786:: @ 81F4786
	trainerbattle 0, TRAINER_BRENT, 0, Route119_Text_29D8C2, Route119_Text_29D8F0
	msgbox Route119_Text_29D902, 6
	end

Route119_EventScript_1F479D:: @ 81F479D
	trainerbattle 0, TRAINER_DONALD, 0, Route119_Text_29D941, Route119_Text_29D97C
	msgbox Route119_Text_29D993, 6
	end

Route119_EventScript_1F47B4:: @ 81F47B4
	trainerbattle 0, TRAINER_TAYLOR, 0, Route119_Text_29D9CD, Route119_Text_29DA14
	msgbox Route119_Text_29DA2C, 6
	end

Route119_EventScript_1F47CB:: @ 81F47CB
	trainerbattle 0, TRAINER_DOUG, 0, Route119_Text_29DA7D, Route119_Text_29DABC
	msgbox Route119_Text_29DADB, 6
	end

Route119_EventScript_1F47E2:: @ 81F47E2
	trainerbattle 0, TRAINER_GREG, 0, Route119_Text_29DB17, Route119_Text_29DB66
	msgbox Route119_Text_29DB7C, 6
	end

Route119_EventScript_1F47F9:: @ 81F47F9
	trainerbattle 0, TRAINER_KENT, 0, Route119_Text_29DBC2, Route119_Text_29DC20
	msgbox Route119_Text_29DC2B, 6
	end

Route119_EventScript_1F4810:: @ 81F4810
	trainerbattle 2, TRAINER_JACKSON_1, 0, Route119_Text_29DC4C, Route119_Text_29DC9F, Route119_EventScript_1F483C
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route119_EventScript_1F485B
	msgbox Route119_Text_29DCC6, 4
	release
	end

Route119_EventScript_1F483C:: @ 81F483C
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DD1C, 4
	setvar VAR_0x8004, 552
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 552
	callstd 8
	release
	end

Route119_EventScript_1F485B:: @ 81F485B
	trainerbattle 5, TRAINER_JACKSON_1, 0, Route119_Text_29DD62, Route119_Text_29DDA5
	msgbox Route119_Text_29DDBD, 6
	end

Route119_EventScript_1F4872:: @ 81F4872
	trainerbattle 2, TRAINER_CATHERINE_1, 0, Route119_Text_29DE0F, Route119_Text_29DE5D, Route119_EventScript_1F489E
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route119_EventScript_1F48BD
	msgbox Route119_Text_29DE88, 4
	release
	end

Route119_EventScript_1F489E:: @ 81F489E
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DEF7, 4
	setvar VAR_0x8004, 559
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 559
	callstd 8
	release
	end

Route119_EventScript_1F48BD:: @ 81F48BD
	trainerbattle 5, TRAINER_CATHERINE_1, 0, Route119_Text_29DF6B, Route119_Text_29DF92
	msgbox Route119_Text_29DFAF, 6
	end

Route119_EventScript_1F48D4:: @ 81F48D4
	trainerbattle 0, TRAINER_HUGH, 0, Route119_Text_29E007, Route119_Text_29E063
	msgbox Route119_Text_29E071, 6
	end

Route119_EventScript_1F48EB:: @ 81F48EB
	trainerbattle 0, TRAINER_PHIL, 0, Route119_Text_29E0A5, Route119_Text_29E0E1
	msgbox Route119_Text_29E0F6, 6
	end

Route119_EventScript_1F4902:: @ 81F4902
	trainerbattle 0, TRAINER_YASU, 0, Route119_Text_29E134, Route119_Text_29E18D
	msgbox Route119_Text_29E19D, 6
	end

Route119_EventScript_1F4919:: @ 81F4919
	trainerbattle 0, TRAINER_TAKASHI, 0, Route119_Text_29E1F5, Route119_Text_29E22B
	msgbox Route119_Text_29E245, 6
	end

Route119_EventScript_1F4930:: @ 81F4930
	trainerbattle 0, TRAINER_HIDEO, 0, Route119_Text_29E26A, Route119_Text_29E288
	msgbox Route119_Text_29E2A3, 6
	end

Route119_EventScript_1F4947:: @ 81F4947
	trainerbattle 0, TRAINER_CHRIS, 0, Route119_Text_29E30D, Route119_Text_29E372
	msgbox Route119_Text_29E3A2, 6
	end

Route119_EventScript_1F495E:: @ 81F495E
	trainerbattle 0, TRAINER_FABIAN, 0, Route119_Text_29E3FF, Route119_Text_29E44F
	msgbox Route119_Text_29E492, 6
	end

Route119_EventScript_1F4975:: @ 81F4975
	trainerbattle 0, TRAINER_DAYTON, 0, Route119_Text_29E4DF, Route119_Text_29E513
	msgbox Route119_Text_29E532, 6
	end

Route119_EventScript_1F498C:: @ 81F498C
	trainerbattle 0, TRAINER_RACHEL, 0, Route119_Text_29E56F, Route119_Text_29E5B1
	msgbox Route119_Text_29E5CB, 6
	end

Route119_EventScript_1F49A3:: @ 81F49A3
	lock
	faceplayer
	msgbox Route119_Text_1F50EB, 4
	closemessage
	applymovement VAR_LAST_TALKED, Route119_Movement_2725A2
	waitmovement 0
	release
	end

Route119_EventScript_1F49BA:: @ 81F49BA
	lock
	faceplayer
	msgbox Route119_Text_1F5147, 4
	closemessage
	applymovement VAR_LAST_TALKED, Route119_Movement_2725A2
	waitmovement 0
	release
	end

Route119_EventScript_1F49D1:: @ 81F49D1
	msgbox Route119_Text_1F51A2, 2
	end

Route119_EventScript_1F49DA:: @ 81F49DA
	msgbox Route119_Text_1F52B9, 2
	end

Route119_EventScript_1F49E3:: @ 81F49E3
	msgbox Route119_Text_1F5339, 3
	end

