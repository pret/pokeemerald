LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script 1, LittlerootTown_BrendansHouse_1F_MapScript1_1F7765
	map_script 3, LittlerootTown_BrendansHouse_1F_MapScript1_1F77A4
	map_script 2, LittlerootTown_BrendansHouse_1F_MapScript2_1F77EA
	.byte 0

LittlerootTown_BrendansHouse_1F_MapScript1_1F7765: @ 81F7765
	compare_var_to_value VAR_0x4092, 6
	call_if 0, LittlerootTown_BrendansHouse_1F_EventScript_1F777A
	checkflag FLAG_0x112
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F778D
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F777A:: @ 81F777A
	setmetatile 5, 4, 624, 1
	setmetatile 5, 2, 616, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F778D:: @ 81F778D
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_1F779A
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F779A:: @ 81F779A
	setmetatile 3, 7, 659, 1
	return

LittlerootTown_BrendansHouse_1F_MapScript1_1F77A4: @ 81F77A4
	compare_var_to_value VAR_0x4092, 3
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F77DE
	compare_var_to_value VAR_0x4092, 5
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F77C6
	compare_var_to_value VAR_0x4092, 6
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F77D2
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F77C6:: @ 81F77C6
	setobjectxyperm 1, 8, 4
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F77D2:: @ 81F77D2
	setobjectxyperm 1, 4, 5
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F77DE:: @ 81F77DE
	setobjectxyperm 1, 9, 8
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_MapScript2_1F77EA: @ 81F77EA
	map_script_2 VAR_0x4092, 3, LittlerootTown_BrendansHouse_1F_EventScript_1F783C
	map_script_2 VAR_0x4092, 5, LittlerootTown_BrendansHouse_1F_EventScript_1F7814
	map_script_2 VAR_0x4092, 6, LittlerootTown_BrendansHouse_1F_EventScript_1F784D
	map_script_2 VAR_0x4082, 1, LittlerootTown_BrendansHouse_1F_EventScript_1F785E
	map_script_2 VAR_0x4082, 3, LittlerootTown_BrendansHouse_1F_EventScript_292AF2
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_1F7814:: @ 81F7814
	lockall
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7B67, 4
	closemessage
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_1F783A
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_1F783A
	waitmovement 0
	warp LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_1F783A: @ 81F783A
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F783C:: @ 81F783C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_292704
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F784D:: @ 81F784D
	lockall
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_29286D
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F785E:: @ 81F785E
	lockall
	playse SE_PIN
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_272598
	waitmovement 0
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_27259A
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_1F789C
	waitmovement 0
	special sub_8138B48
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8BC5, 4
	setflag FLAG_0x057
	setvar VAR_0x4082, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_1F789C: @ 81F789C
	step_down
	step_right
	step_right
	step_right
	step_right
	step_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F78A3:: @ 81F78A3
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	applymovement VAR_0x8004, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_292765
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F78BE:: @ 81F78BE
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_1F78E2
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F78CA:: @ 81F78CA
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_1F78E2
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F78D6:: @ 81F78D6
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_1F78E2
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F78E2:: @ 81F78E2
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_272598
	waitmovement 0
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x8008, 1
	call_if 5, LittlerootTown_BrendansHouse_1F_EventScript_1F7981
	playbgm BGM_BOY_SUP, 1
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F798C
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F7997
	compare_var_to_value VAR_0x8008, 2
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F79A2
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F90B4, 4
	closemessage
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F79C1
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F79D3
	compare_var_to_value VAR_0x8008, 2
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_1F79E5
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_0x2E9
	setflag FLAG_0x331
	clearflag FLAG_0x2F8
	delay 30
	setvar VAR_0x408D, 3
	setvar VAR_0x4050, 1
	savebgm SE_STOP
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_1F7981:: @ 81F7981
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725AA
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F798C:: @ 81F798C
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F79AD
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F7997:: @ 81F7997
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F79B5
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F79A2:: @ 81F79A2
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F79B9
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_1F79AD: @ 81F79AD
	step_27
	step_left
	step_26
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F79B5: @ 81F79B5
	step_up
	step_up
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F79B9: @ 81F79B9
	step_28
	step_right
	step_26
	step_up
	step_up
	step_up
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F79C1:: @ 81F79C1
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_1F79F7
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F7A06
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F79D3:: @ 81F79D3
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_1F79FB
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F7A0C
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_1F79E5:: @ 81F79E5
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_1F7A02
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_1F7A16
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_1F79F7: @ 81F79F7
	step_14
	step_13
	step_28
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F79FB: @ 81F79FB
	step_14
	step_13
	step_28
	step_14
	step_14
	step_26
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F7A02: @ 81F7A02
	step_14
	step_13
	step_27
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F7A06: @ 81F7A06
	step_28
	step_right
	step_26
	step_up
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F7A0C: @ 81F7A0C
	step_28
	step_right
	step_26
	step_up
	step_up
	step_27
	step_left
	step_26
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_1F7A16: @ 81F7A16
	step_27
	step_left
	step_26
	step_up
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_Text_1F7A1C: @ 81F7A1C
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn’t it nice in here, too?$"

LittlerootTown_BrendansHouse_1F_Text_1F7A46: @ 81F7A46
	.string "The mover’s POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don’t forget to set it!$"

LittlerootTown_BrendansHouse_1F_Text_1F7B24: @ 81F7B24
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren’t you interested in seeing your\n"
	.string "very own room?$"

LittlerootTown_BrendansHouse_1F_Text_1F7B67: @ 81F7B67
