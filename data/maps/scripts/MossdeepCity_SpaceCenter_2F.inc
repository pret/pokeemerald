MossdeepCity_SpaceCenter_2F_MapScripts:: @ 8223D58
	map_script 3, MossdeepCity_SpaceCenter_2F_MapScript1_223D63
	map_script 2, MossdeepCity_SpaceCenter_2F_MapScript2_223DB5
	.byte 0

MossdeepCity_SpaceCenter_2F_MapScript1_223D63: @ 8223D63
	compare_var_to_value VAR_0x405D, 2
	call_if 1, MossdeepCity_SpaceCenter_2F_EventScript_223D7A
	compare_var_to_value VAR_0x409F, 2
	call_if 1, MossdeepCity_SpaceCenter_2F_EventScript_223D9F
	end

MossdeepCity_SpaceCenter_2F_EventScript_223D7A:: @ 8223D7A
	clearflag FLAG_0x0CD
	setobjectxyperm 3, 5, 3
	setobjectmovementtype 3, 10
	setobjectxyperm 1, 3, 2
	setobjectmovementtype 1, 10
	setobjectxyperm 2, 1, 3
	setobjectmovementtype 2, 10
	return

MossdeepCity_SpaceCenter_2F_EventScript_223D9F:: @ 8223D9F
	setobjectxyperm 5, 11, 2
	setobjectxyperm 7, 15, 2
	setobjectxyperm 6, 13, 4
	return

MossdeepCity_SpaceCenter_2F_MapScript2_223DB5: @ 8223DB5
	map_script_2 VAR_0x409F, 1, MossdeepCity_SpaceCenter_2F_EventScript_223DBF
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_223DBF:: @ 8223DBF
	playse SE_PIN
	applymovement 255, MossdeepCity_SpaceCenter_2F_Movement_272598
	waitmovement 0
	applymovement 255, MossdeepCity_SpaceCenter_2F_Movement_27259A
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2243A4, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223E09
	msgbox MossdeepCity_SpaceCenter_2F_Text_2243FE, 4
	closemessage
	applymovement 255, MossdeepCity_SpaceCenter_2F_Movement_223E07
	waitmovement 0
	warp MOSSDEEP_CITY_SPACE_CENTER_1F, 255, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223E07: @ 8223E07
	step_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223E09:: @ 8223E09
	msgbox MossdeepCity_SpaceCenter_2F_Text_22442D, 4
	trainerbattle 3, TRAINER_GRUNT_34, 0, MossdeepCity_SpaceCenter_2F_Text_224461
	applymovement 6, MossdeepCity_SpaceCenter_2F_Movement_223E85
	waitmovement 0
	applymovement 255, MossdeepCity_SpaceCenter_2F_Movement_2725A4
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_22446E, 4
	trainerbattle 3, TRAINER_GRUNT_35, 0, MossdeepCity_SpaceCenter_2F_Text_224499
	applymovement 5, MossdeepCity_SpaceCenter_2F_Movement_223E81
	waitmovement 0
	applymovement 255, MossdeepCity_SpaceCenter_2F_Movement_2725A8
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2244AB, 4
	trainerbattle 3, TRAINER_GRUNT_36, 0, MossdeepCity_SpaceCenter_2F_Text_2244F1
	applymovement 7, MossdeepCity_SpaceCenter_2F_Movement_223E89
	waitmovement 0
	setvar VAR_0x409F, 2
	moveobjectoffscreen 5
	moveobjectoffscreen 7
	moveobjectoffscreen 6
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223E81: @ 8223E81
	step_40
	step_left
	step_41
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223E85: @ 8223E85
	step_40
	step_down
	step_41
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223E89: @ 8223E89
	step_40
	step_right
	step_41
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223E8D:: @ 8223E8D
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223EB4
	compare_var_to_value VAR_0x405D, 2
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223EBE
	compare_var_to_value VAR_0x405D, 2
	goto_if 0, MossdeepCity_SpaceCenter_2F_EventScript_223EB4
	goto MossdeepCity_SpaceCenter_2F_EventScript_223EBE
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EB4:: @ 8223EB4
	msgbox MossdeepCity_SpaceCenter_2F_Text_2241A1, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EBE:: @ 8223EBE
	msgbox MossdeepCity_SpaceCenter_2F_Text_22420C, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EC8:: @ 8223EC8
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223EEF
	compare_var_to_value VAR_0x405D, 2
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223EF9
	compare_var_to_value VAR_0x405D, 2
	goto_if 0, MossdeepCity_SpaceCenter_2F_EventScript_223EEF
	goto MossdeepCity_SpaceCenter_2F_EventScript_223EF9
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EEF:: @ 8223EEF
	msgbox MossdeepCity_SpaceCenter_2F_Text_224253, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EF9:: @ 8223EF9
	msgbox MossdeepCity_SpaceCenter_2F_Text_2242C5, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F03:: @ 8223F03
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223F2A
	compare_var_to_value VAR_0x405D, 2
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223F34
	compare_var_to_value VAR_0x405D, 2
	goto_if 0, MossdeepCity_SpaceCenter_2F_EventScript_223F2A
	goto MossdeepCity_SpaceCenter_2F_EventScript_223F34
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F2A:: @ 8223F2A
	msgbox MossdeepCity_SpaceCenter_2F_Text_224342, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F34:: @ 8223F34
	msgbox MossdeepCity_SpaceCenter_2F_Text_224376, 4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F3E:: @ 8223F3E
	msgbox MossdeepCity_SpaceCenter_2F_Text_22452C, 2
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F47:: @ 8223F47
	msgbox MossdeepCity_SpaceCenter_2F_Text_224570, 2
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F50:: @ 8223F50
	msgbox MossdeepCity_SpaceCenter_2F_Text_2245AF, 2
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F59:: @ 8223F59
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_2245D9, 4
	applymovement VAR_LAST_TALKED, MossdeepCity_SpaceCenter_2F_Movement_2725A2
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F6F:: @ 8223F6F
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_22467B, 4
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F7A:: @ 8223F7A
	lockall
	checkflag FLAG_0x0CD
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_223FDA
	setflag FLAG_0x0CD
	msgbox MossdeepCity_SpaceCenter_2F_Text_2246B2, 4
	msgbox MossdeepCity_SpaceCenter_2F_Text_2246F0, 4
	closemessage
	delay 30
	playse SE_KOUKA_L
	switch VAR_FACING
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_223FBA
	applymovement 4, MossdeepCity_SpaceCenter_2F_Movement_223FC6
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_223FBA:: @ 8223FBA
	applymovement 4, MossdeepCity_SpaceCenter_2F_Movement_223FCF
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223FC6: @ 8223FC6
	step_40
	step_16
	step_16
	step_41
	step_14
	step_14
	slow_step_down
	slow_step_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223FCF: @ 8223FCF
	step_02
	step_40
	step_18
	step_18
	step_41
	step_14
	step_14
	slow_step_left
	slow_step_left
	step_00
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223FDA:: @ 8223FDA
	applymovement VAR_LAST_TALKED, MossdeepCity_SpaceCenter_2F_Movement_27259E
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2247FF, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq MossdeepCity_SpaceCenter_2F_EventScript_22400C
	msgbox MossdeepCity_SpaceCenter_2F_Text_224854, 4
	closemessage
	applymovement VAR_LAST_TALKED, MossdeepCity_SpaceCenter_2F_Movement_2725AA
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_22400C:: @ 822400C
	applymovement VAR_LAST_TALKED, MossdeepCity_SpaceCenter_2F_Movement_2725AA
	waitmovement 0
	special copy_player_party_to_sav1
	fadescreen 1
	special sub_80F9438
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, MossdeepCity_SpaceCenter_2F_EventScript_224032
	special copy_player_party_from_sav1
	goto MossdeepCity_SpaceCenter_2F_EventScript_223FDA

MossdeepCity_SpaceCenter_2F_EventScript_224032:: @ 8224032
	special sub_80F94E8
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special sub_8163AC4
	waitstate
	setvar VAR_0x8004, 6
	special sub_81A1780
	special copy_player_party_from_sav1
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_224071
	fadescreen 1
	special sp0C8_whiteout_maybe
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_224071:: @ 8224071
	msgbox MossdeepCity_SpaceCenter_2F_Text_2248C2, 4
	closemessage
	delay 20
	applymovement 9, MossdeepCity_SpaceCenter_2F_Movement_2725A4
	applymovement 8, MossdeepCity_SpaceCenter_2F_Movement_2725AA
	waitmovement 0
	delay 60
	applymovement 9, MossdeepCity_SpaceCenter_2F_Movement_2725A6
	applymovement 8, MossdeepCity_SpaceCenter_2F_Movement_2725A8
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_2249DC, 4
	closemessage
	setvar VAR_0x405D, 3
	fadedefaultbgm
	fadescreen 1
	setvar VAR_0x409F, 3
	setflag FLAG_0x2F4
	setflag FLAG_0x35E
	setflag FLAG_0x337
	removeobject 5
	removeobject 7
	removeobject 6
	removeobject 8
	removeobject 9
	setobjectxy 3, 5, 6
	turnobject 3, 1
	setobjectxy 2, 11, 8
	turnobject 2, 2
	setobjectxy 1, 6, 2
	turnobject 1, 2
	call MossdeepCity_SpaceCenter_2F_EventScript_224131
	fadescreen 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_224A4A, 4
	closemessage
	fadescreen 1
	setflag FLAG_0x075
	setflag FLAG_0x3C7
	removeobject 4
	setflag FLAG_0x2E1
	clearflag FLAG_0x3C7
	setvar VAR_0x40C6, 1
	setflag FLAG_0x314
	removeobject 3
	setobjectxyperm 3, 5, 6
	setobjectmovementtype 3, 2
	addobject 3
	fadescreen 0
	end

MossdeepCity_SpaceCenter_2F_EventScript_224131:: @ 8224131
	switch VAR_FACING
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_22414D
	case 3, MossdeepCity_SpaceCenter_2F_EventScript_224152
	return

MossdeepCity_SpaceCenter_2F_EventScript_22414D:: @ 822414D
	turnobject 4, 2
	return

MossdeepCity_SpaceCenter_2F_EventScript_224152:: @ 8224152
	turnobject 4, 4
	return

	.incbin "baserom.gba", 0x224157, 0x1

