MauvilleCity_MapScripts:: @ 81DF385
	map_script 3, MauvilleCity_MapScript1_1DF38B
	.byte 0

MauvilleCity_MapScript1_1DF38B: @ 81DF38B
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_0x09D
	clearflag FLAG_0x3C1
	setflag FLAG_SYS_TV_START
	clearflag FLAG_0x063
	setvar VAR_0x4093, 0
	checkflag FLAG_0x0D1
	call_if 1, MauvilleCity_EventScript_1DF3A9
	end

MauvilleCity_EventScript_1DF3A9:: @ 81DF3A9
	clearflag FLAG_0x391
	setflag FLAG_0x390
	setflag FLAG_0x05B
	return

MauvilleCity_EventScript_1DF3B3:: @ 81DF3B3
	msgbox MauvilleCity_Text_1E0301, 2
	end

MauvilleCity_EventScript_1DF3BC:: @ 81DF3BC
	msgbox MauvilleCity_Text_1E037C, 2
	end

MauvilleCity_EventScript_1DF3C5:: @ 81DF3C5
	msgbox MauvilleCity_Text_1E03FB, 2
	end

MauvilleCity_EventScript_1DF3CE:: @ 81DF3CE
	msgbox MauvilleCity_Text_1E044A, 2
	end

MauvilleCity_EventScript_1DF3D7:: @ 81DF3D7
	msgbox MauvilleCity_Text_1E0485, 3
	end

MauvilleCity_EventScript_1DF3E0:: @ 81DF3E0
	msgbox MauvilleCity_Text_1E04B7, 3
	end

MauvilleCity_EventScript_1DF3E9:: @ 81DF3E9
	msgbox MauvilleCity_Text_1E0504, 3
	end

MauvilleCity_EventScript_1DF3F2:: @ 81DF3F2
	msgbox MauvilleCity_Text_1E053C, 3
	end

MauvilleCity_EventScript_1DF3FB:: @ 81DF3FB
	lock
	faceplayer
	checkflag FLAG_0x062
	goto_eq MauvilleCity_EventScript_1DF413
	msgbox MauvilleCity_Text_1E056A, 4
	setflag FLAG_0x062
	release
	end

MauvilleCity_EventScript_1DF413:: @ 81DF413
	msgbox MauvilleCity_Text_1E0699, 4
	release
	end

MauvilleCity_EventScript_1DF41D:: @ 81DF41D
	lock
	faceplayer
	checkflag FLAG_0x11C
	goto_eq MauvilleCity_EventScript_1DF43D
	msgbox MauvilleCity_Text_1DF7DC, 4
	closemessage
	applymovement 7, MauvilleCity_Movement_2725A2
	waitmovement 0
	release
	end

MauvilleCity_EventScript_1DF43D:: @ 81DF43D
	msgbox MauvilleCity_Text_1DFAA5, 4
	closemessage
	applymovement 7, MauvilleCity_Movement_2725A2
	waitmovement 0
	release
	end

MauvilleCity_EventScript_1DF452:: @ 81DF452
	lockall
	checkflag FLAG_0x11C
	goto_eq MauvilleCity_EventScript_1DF690
	applymovement 6, MauvilleCity_Movement_2725A8
	waitmovement 0
	msgbox MauvilleCity_Text_1DF845, 4
	msgbox MauvilleCity_Text_1DF8B9, 4
	msgbox MauvilleCity_Text_1DF963, 4
	applymovement 6, MauvilleCity_Movement_27259E
	waitmovement 0
	playse SE_PIN
	applymovement 6, MauvilleCity_Movement_272598
	waitmovement 0
	applymovement 6, MauvilleCity_Movement_27259A
	waitmovement 0
	msgbox MauvilleCity_Text_1DF9B2, 5
	goto MauvilleCity_EventScript_1DF4AD
	end

MauvilleCity_EventScript_1DF4AD:: @ 81DF4AD
	compare_var_to_value VAR_RESULT, 1
	call_if 1, MauvilleCity_EventScript_1DF63A
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_1DF683
	closemessage
	switch VAR_FACING
	case 2, MauvilleCity_EventScript_1DF4E0
	case 4, MauvilleCity_EventScript_1DF53D
	end

MauvilleCity_EventScript_1DF4E0:: @ 81DF4E0
	applymovement 255, MauvilleCity_Movement_1DF6DF
	applymovement 6, MauvilleCity_Movement_1DF6A8
	applymovement 7, MauvilleCity_Movement_1DF6E2
	waitmovement 0
	applymovement 6, MauvilleCity_Movement_2725A8
	waitmovement 0
	delay 30
	applymovement 255, MauvilleCity_Movement_1DF6EE
	applymovement 7, MauvilleCity_Movement_1DF6F3
	waitmovement 0
	msgbox MauvilleCity_Text_1DFD34, 4
	closemessage
	applymovement 255, MauvilleCity_Movement_1DF6CC
	applymovement 7, MauvilleCity_Movement_1DF6FA
	applymovement 6, MauvilleCity_Movement_1DF6B4
	waitmovement 0
	goto MauvilleCity_EventScript_1DF593
	end

MauvilleCity_EventScript_1DF53D:: @ 81DF53D
	applymovement 255, MauvilleCity_Movement_1DF6DC
	applymovement 6, MauvilleCity_Movement_1DF6AE
	applymovement 7, MauvilleCity_Movement_1DF6E8
	waitmovement 0
	applymovement 6, MauvilleCity_Movement_2725A8
	waitmovement 0
	delay 30
	applymovement 7, MauvilleCity_Movement_1DF6F7
	waitmovement 0
	msgbox MauvilleCity_Text_1DFD34, 4
	closemessage
	applymovement 255, MauvilleCity_Movement_1DF6D0
	applymovement 7, MauvilleCity_Movement_1DF703
	applymovement 6, MauvilleCity_Movement_1DF6C0
	waitmovement 0
	goto MauvilleCity_EventScript_1DF593
	end

MauvilleCity_EventScript_1DF593:: @ 81DF593
	removeobject 6
	removeobject 7
	clearflag FLAG_0x326
	clearflag FLAG_0x329
	setflag FLAG_0x0BE
	setvar VAR_0x40F2, 0
	setflag FLAG_0x088
	compare_var_to_value VAR_FACING, 2
	call_if 1, MauvilleCity_EventScript_1DF5F3
	compare_var_to_value VAR_FACING, 4
	call_if 1, MauvilleCity_EventScript_1DF601
	applymovement 255, MauvilleCity_Movement_2725AA
	waitmovement 0
	msgbox MauvilleCity_Text_1DFED5, 4
	closemessage
	addvar VAR_0x40D1, 1
	compare_var_to_value VAR_FACING, 2
	call_if 1, MauvilleCity_EventScript_1DF616
	compare_var_to_value VAR_FACING, 4
	call_if 1, MauvilleCity_EventScript_1DF628
	removeobject 11
	releaseall
	end

MauvilleCity_EventScript_1DF5F3:: @ 81DF5F3
	addobject 11
	applymovement 11, MauvilleCity_Movement_1DF70D
	waitmovement 0
	return

MauvilleCity_EventScript_1DF601:: @ 81DF601
	setobjectxyperm 11, 12, 13
	addobject 11
	applymovement 11, MauvilleCity_Movement_1DF719
	waitmovement 0
	return

MauvilleCity_EventScript_1DF616:: @ 81DF616
	applymovement 255, MauvilleCity_Movement_1DF6D5
	applymovement 11, MauvilleCity_Movement_1DF725
	waitmovement 0
	return

MauvilleCity_EventScript_1DF628:: @ 81DF628
	applymovement 255, MauvilleCity_Movement_1DF6D8
	applymovement 11, MauvilleCity_Movement_1DF72F
	waitmovement 0
	return

MauvilleCity_EventScript_1DF63A:: @ 81DF63A
	msgbox MauvilleCity_Text_1DFB6D, 4
	trainerbattle 3, TRAINER_WALLY_2, 0, MauvilleCity_Text_1DFB96
	applymovement 6, MauvilleCity_Movement_2725A8
	waitmovement 0
	msgbox MauvilleCity_Text_1DFBC3, 4
	applymovement 6, MauvilleCity_Movement_27259E
	waitmovement 0
	msgbox MauvilleCity_Text_1DFBED, 4
	applymovement 6, MauvilleCity_Movement_2725A8
	waitmovement 0
	msgbox MauvilleCity_Text_1DFC8A, 4
	return

MauvilleCity_EventScript_1DF683:: @ 81DF683
	setflag FLAG_0x11C
	msgbox MauvilleCity_Text_1DFA4A, 4
	release
	end

MauvilleCity_EventScript_1DF690:: @ 81DF690
	applymovement 6, MauvilleCity_Movement_27259E
	waitmovement 0
	msgbox MauvilleCity_Text_1DFB42, 5
	goto MauvilleCity_EventScript_1DF4AD
	end

MauvilleCity_Movement_1DF6A8: @ 81DF6A8
	step_left
	step_left
	step_down
	step_down
	step_left
	step_end

MauvilleCity_Movement_1DF6AE: @ 81DF6AE
	step_down
	step_down
	step_left
	step_left
	step_left
	step_end

MauvilleCity_Movement_1DF6B4: @ 81DF6B4
	step_14
	step_14
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_13
	step_end

MauvilleCity_Movement_1DF6C0: @ 81DF6C0
	step_14
	step_14
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_13
	step_end

MauvilleCity_Movement_1DF6CC: @ 81DF6CC
	step_14
	step_13
	step_27
	step_end

MauvilleCity_Movement_1DF6D0: @ 81DF6D0
	step_14
	step_14
	step_14
	step_27
	step_end

MauvilleCity_Movement_1DF6D5: @ 81DF6D5
	step_14
	step_27
	step_end

MauvilleCity_Movement_1DF6D8: @ 81DF6D8
	step_14
	step_14
	step_27
	step_end

MauvilleCity_Movement_1DF6DC: @ 81DF6DC
	step_14
	step_25
	step_end

MauvilleCity_Movement_1DF6DF: @ 81DF6DF
	step_14
	step_27
	step_end

MauvilleCity_Movement_1DF6E2: @ 81DF6E2
	step_left
	step_left
	step_left
	step_down
	step_down
	step_end

MauvilleCity_Movement_1DF6E8: @ 81DF6E8
	step_left
	step_down
	step_down
	step_left
	step_left
	step_end

MauvilleCity_Movement_1DF6EE: @ 81DF6EE
	step_14
	step_13
	step_12
	step_25
	step_end

MauvilleCity_Movement_1DF6F3: @ 81DF6F3
	step_right
	step_right
	step_26
	step_end

MauvilleCity_Movement_1DF6F7: @ 81DF6F7
	step_right
	step_up
	step_end

MauvilleCity_Movement_1DF6FA: @ 81DF6FA
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_end

MauvilleCity_Movement_1DF703: @ 81DF703
	step_down
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_end

MauvilleCity_Movement_1DF70D: @ 81DF70D
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_left
	step_left
	step_left
	step_left
	step_26
	step_end

MauvilleCity_Movement_1DF719: @ 81DF719
	step_up
	step_up
	step_up
	step_up
	step_up
	step_left
	step_left
	step_left
	step_left
	step_left
	step_up
	step_end

MauvilleCity_Movement_1DF725: @ 81DF725
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_end

MauvilleCity_Movement_1DF72F: @ 81DF72F
	step_down
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_end

MauvilleCity_EventScript_1DF73A:: @ 81DF73A
	lock
	faceplayer
	checkflag FLAG_0x0D1
	goto_eq MauvilleCity_EventScript_1DF7B0
	compare_var_to_value VAR_0x40BA, 2
	goto_eq MauvilleCity_EventScript_1DF784
	checkflag FLAG_0x0D0
	goto_eq MauvilleCity_EventScript_1DF77A
	msgbox MauvilleCity_Text_1DFFE4, 4
	giveitem_std ITEM_BASEMENT_KEY
	setflag FLAG_0x0D0
	msgbox MauvilleCity_Text_1E0154, 4
	release
	end

MauvilleCity_EventScript_1DF77A:: @ 81DF77A
	msgbox MauvilleCity_Text_1E0154, 4
	release
	end

MauvilleCity_EventScript_1DF784:: @ 81DF784
	msgbox MauvilleCity_Text_1E020E, 4
	giveitem_std ITEM_TM24
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_272054
	setflag FLAG_0x0D1
	msgbox MauvilleCity_Text_1E02AA, 4
	release
	end

MauvilleCity_EventScript_1DF7B0:: @ 81DF7B0
	msgbox MauvilleCity_Text_1E02AA, 4
	release
	end

