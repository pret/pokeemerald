Route104_MapScripts:: @ 81ECC32
	map_script 2, Route104_MapScript2_1ECC3D
	map_script 3, Route104_MapScript1_1ECC4E
	.byte 0

Route104_MapScript2_1ECC3D: @ 81ECC3D
	map_script_2 VAR_0x408E, 1, Route104_EventScript_1ECC47
	.2byte 0

Route104_EventScript_1ECC47:: @ 81ECC47
	lockall
	goto Route104_EventScript_1ED099
	end

Route104_MapScript1_1ECC4E: @ 81ECC4E
	call Route104_EventScript_271ED7
	call Route104_EventScript_1ECC78
	call Route104_EventScript_1ECC5E
	end

Route104_EventScript_1ECC5E:: @ 81ECC5E
	checkflag FLAG_0x07F
	goto_if 0, Route104_EventScript_1ECC74
	checkflag FLAG_BADGE03_GET
	goto_if 0, Route104_EventScript_1ECC74
	clearflag FLAG_0x38A
	return

Route104_EventScript_1ECC74:: @ 81ECC74
	setflag FLAG_0x38A
	return

Route104_EventScript_1ECC78:: @ 81ECC78
	compare_var_to_value VAR_0x408E, 1
	goto_if 4, Route104_EventScript_1ECC9D
	checkflag FLAG_0x120
	goto_eq Route104_EventScript_1ECC9D
	checkflag FLAG_0x07C
	goto_if 0, Route104_EventScript_1ECC9D
	setobjectxyperm 34, 17, 52
	return

Route104_EventScript_1ECC9D:: @ 81ECC9D
	return

Route104_EventScript_1ECC9E:: @ 81ECC9E
	lockall
	setvar VAR_0x8008, 1
	applymovement 34, Route104_Movement_27259E
	waitmovement 0
	goto Route104_EventScript_1ECD33

Route104_EventScript_1ECCB3:: @ 81ECCB3
	lockall
	setflag FLAG_0x32E
	setvar VAR_0x405A, 8
	setvar VAR_0x4063, 2
	applymovement 255, Route104_Movement_2725A6
	waitmovement 0
	delay 10
	addobject 34
	clearflag FLAG_0x2CF
	applymovement 255, Route104_Movement_1ECF86
	waitmovement 0
	applymovement 34, Route104_Movement_1ECF8A
	waitmovement 0
	delay 20
	setvar VAR_0x8008, 0
	call Route104_EventScript_1E0DD1
	playse SE_PIN
	applymovement 34, Route104_Movement_272598
	waitmovement 0
	applymovement 34, Route104_Movement_27259A
	waitmovement 0
	goto Route104_EventScript_1ECD33

Route104_EventScript_1ECD11:: @ 81ECD11
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_1ECD29
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECD2E
	return

Route104_EventScript_1ECD29:: @ 81ECD29
	playbgm BGM_GIRL_SUP, 1
	return

Route104_EventScript_1ECD2E:: @ 81ECD2E
	playbgm BGM_BOY_SUP, 1
	return

Route104_EventScript_1ECD33:: @ 81ECD33
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_1ECD4B
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECE6F
	end

Route104_EventScript_1ECD4B:: @ 81ECD4B
	checkflag FLAG_0x07D
	goto_eq Route104_EventScript_1ECE1C
	checkflag FLAG_0x07C
	goto_eq Route104_EventScript_1ECDD0
	setflag FLAG_0x07C
	msgbox Route104_Text_1EDBFF, 4
	closemessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox Route104_Text_1EDC8F, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x0FD
	applymovement 255, Route104_Movement_1ECDCD
	applymovement 34, Route104_Movement_1ECDC8
	msgbox Route104_Text_1EDCB1, 4
	closemessage
	waitmovement 0
	applymovement 34, Route104_Movement_1ECDCA
	waitmovement 0
	moveobjectoffscreen 34
	msgbox Route104_Text_1EDCED, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECDED
	msgbox Route104_Text_1EDD2A, 4
	call Route104_EventScript_1ECE31
	releaseall
	end

Route104_Movement_1ECDC8: @ 81ECDC8
	slow_step_left
	step_end

Route104_Movement_1ECDCA: @ 81ECDCA
	step_down
	step_03
	step_end

Route104_Movement_1ECDCD: @ 81ECDCD
	step_12
	step_27
	step_end

Route104_EventScript_1ECDD0:: @ 81ECDD0
	msgbox Route104_Text_1EDD9F, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECDED
	msgbox Route104_Text_1EDD2A, 4
	releaseall
	end

Route104_EventScript_1ECDED:: @ 81ECDED
	msgbox Route104_Text_1EDDDB, 4
	switch VAR_FIRST_POKE
	case 0, Route104_EventScript_1ECE36
	case 1, Route104_EventScript_1ECE49
	case 2, Route104_EventScript_1ECE5C
	end

Route104_EventScript_1ECE1C:: @ 81ECE1C
	msgbox Route104_Text_1EDE3E, 4
	compare_var_to_value VAR_0x8008, 0
	call_if 1, Route104_EventScript_1ECE31
	releaseall
	end

Route104_EventScript_1ECE31:: @ 81ECE31
	savebgm SE_STOP
	fadedefaultbgm
	return

Route104_EventScript_1ECE36:: @ 81ECE36
	trainerbattle 3, TRAINER_MAY_14, 0, Route104_Text_1EDE18
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECE1C
	end

Route104_EventScript_1ECE49:: @ 81ECE49
	trainerbattle 3, TRAINER_MAY_15, 0, Route104_Text_1EDE18
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECE1C
	end

Route104_EventScript_1ECE5C:: @ 81ECE5C
	trainerbattle 3, TRAINER_MAY_10, 0, Route104_Text_1EDE18
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECE1C
	end

Route104_EventScript_1ECE6F:: @ 81ECE6F
	checkflag FLAG_0x07D
	goto_eq Route104_EventScript_1ECF38
	checkflag FLAG_0x07C
	goto_eq Route104_EventScript_1ECEEC
	setflag FLAG_0x07C
	msgbox Route104_Text_1EDF04, 4
	closemessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox Route104_Text_1EDFA0, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x0FD
	applymovement 255, Route104_Movement_1ECDCD
	applymovement 34, Route104_Movement_1ECDC8
	msgbox Route104_Text_1EDFC6, 4
	closemessage
	waitmovement 0
	applymovement 34, Route104_Movement_1ECDCA
	waitmovement 0
	moveobjectoffscreen 34
	msgbox Route104_Text_1EE009, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECF09
	msgbox Route104_Text_1EE04D, 4
	call Route104_EventScript_1ECE31
	releaseall
	end

Route104_EventScript_1ECEEC:: @ 81ECEEC
	msgbox Route104_Text_1EE094, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ECF09
	msgbox Route104_Text_1EE04D, 4
	releaseall
	end

Route104_EventScript_1ECF09:: @ 81ECF09
	msgbox Route104_Text_1EE0C7, 4
	switch VAR_FIRST_POKE
	case 0, Route104_EventScript_1ECF4D
	case 1, Route104_EventScript_1ECF60
	case 2, Route104_EventScript_1ECF73
	end

Route104_EventScript_1ECF38:: @ 81ECF38
	msgbox Route104_Text_1EE120, 4
	compare_var_to_value VAR_0x8008, 0
	call_if 1, Route104_EventScript_1ECE31
	releaseall
	end

Route104_EventScript_1ECF4D:: @ 81ECF4D
	trainerbattle 3, TRAINER_BRENDAN_10, 0, Route104_Text_1EE107
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECF38
	end

Route104_EventScript_1ECF60:: @ 81ECF60
	trainerbattle 3, TRAINER_BRENDAN_12, 0, Route104_Text_1EE107
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECF38
	end

Route104_EventScript_1ECF73:: @ 81ECF73
	trainerbattle 3, TRAINER_BRENDAN_11, 0, Route104_Text_1EE107
	setflag FLAG_0x07D
	goto Route104_EventScript_1ECF38
	end

Route104_Movement_1ECF86: @ 81ECF86
	step_40
	step_down
	step_41
	step_end

Route104_Movement_1ECF8A: @ 81ECF8A
	step_down
	step_end

Route104_EventScript_1ECF8C:: @ 81ECF8C
	lock
	faceplayer
	checkflag FLAG_0x0F6
	goto_eq Route104_EventScript_1ECFC3
	msgbox Route104_Text_2A6D86, 4
	giveitem_std ITEM_CHESTO_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_272054
	setflag FLAG_0x0F6
	msgbox Route104_Text_2A6E32, 4
	release
	end

Route104_EventScript_1ECFC3:: @ 81ECFC3
	msgbox Route104_Text_2A6E32, 4
	release
	end

Route104_EventScript_1ECFCD:: @ 81ECFCD
	lock
	faceplayer
	checkflag FLAG_0x117
	goto_eq Route104_EventScript_1ECFFC
	msgbox Route104_Text_1ED96A, 4
	giveitem_std ITEM_WHITE_HERB
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_272054
	setflag FLAG_0x117
	release
	end

Route104_EventScript_1ECFFC:: @ 81ECFFC
	msgbox Route104_Text_1EDA0F, 4
	release
	end

Route104_EventScript_1ED006:: @ 81ED006
	msgbox Route104_Text_1ED5EC, 2
	end

Route104_EventScript_1ED00F:: @ 81ED00F
	msgbox Route104_Text_1ED662, 3
	end

Route104_EventScript_1ED018:: @ 81ED018
	msgbox Route104_Text_1EDA8C, 3
	end

Route104_EventScript_1ED021:: @ 81ED021
	msgbox Route104_Text_1EDAA1, 3
	end

Route104_EventScript_1ED02A:: @ 81ED02A
	msgbox Route104_Text_1EDABC, 3
	end

Route104_EventScript_1ED033:: @ 81ED033
	msgbox Route104_Text_1EDAD6, 3
	end

Route104_EventScript_1ED03C:: @ 81ED03C
	msgbox Route104_Text_1EDAEF, 3
	end

Route104_EventScript_1ED045:: @ 81ED045
	msgbox Route104_Text_1ED6A2, 2
	end

Route104_EventScript_1ED04E:: @ 81ED04E
	msgbox Route104_Text_1ED735, 2
	end

Route104_EventScript_1ED057:: @ 81ED057
	lock
	faceplayer
	checkflag FLAG_0x106
	goto_eq Route104_EventScript_1ED086
	msgbox Route104_Text_1ED838, 4
	giveitem_std ITEM_TM09
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_272054
	setflag FLAG_0x106
	release
	end

Route104_EventScript_1ED086:: @ 81ED086
	msgbox Route104_Text_1ED8E7, 4
	release
	end

Route104_EventScript_1ED090:: @ 81ED090
	msgbox Route104_Text_1ED7A2, 2
	end

Route104_EventScript_1ED099:: @ 81ED099
	setobjectpriority 8, ROUTE_104, 0
	setobjectpriority 255, ROUTE_104, 0
	applymovement 8, Route104_Movement_1ED359
	waitmovement 0
	removeobject 8
	applymovement 255, Route104_Movement_1ED34F
	waitmovement 0
	hideobjectat 255, ROUTE_104
	call Route104_EventScript_2720A0
	checkflag FLAG_0x132
	goto_eq Route104_EventScript_1ED0D9
	checkflag FLAG_0x132
	goto_if 0, Route104_EventScript_1ED0EF
	end

Route104_EventScript_1ED0D9:: @ 81ED0D9
	applymovement 7, Route104_Movement_1ED28C
	applymovement 255, Route104_Movement_1ED28C
	waitmovement 0
	goto Route104_EventScript_1ED139

Route104_EventScript_1ED0EF:: @ 81ED0EF
	applymovement 7, Route104_Movement_1ED1C8
	applymovement 255, Route104_Movement_1ED1C8
	waitmovement 0
	pokenavcall Route104_Text_1EE336
	waitmessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox Route104_Text_1EE463, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x132
	applymovement 255, Route104_Movement_1ED22A
	applymovementat 7, Route104_Movement_1ED22A, ROUTE_104
	waitmovementat 7, ROUTE_104
	waitmovement 0
	goto Route104_EventScript_1ED139

Route104_EventScript_1ED139:: @ 81ED139
	delay 50
	applymovement 255, Route104_Movement_1ED353
	waitmovement 0
	call Route104_EventScript_2720A8
	showobjectat 255, DEWFORD_TOWN
	applymovement 255, Route104_Movement_1ED355
	waitmovement 0
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, DEWFORD_TOWN, 0
	clearflag FLAG_0x2E4
	applymovement 2, Route104_Movement_1ED35C
	waitmovement 0
	addobject 4
	clearflag FLAG_0x2E7
	call Route104_EventScript_2720A8
	setflag FLAG_0x2E6
	hideobjectat 7, ROUTE_104
	copyvar VAR_0x4096, VAR_0x8008
	resetobjectpriority 255, ROUTE_104
	resetobjectpriority 2, DEWFORD_TOWN
	moveobjectoffscreen 2
	setvar VAR_0x408E, 0
	checkflag FLAG_0x0BD
	goto_if 0, Route104_EventScript_1ED1B4
	checkflag FLAG_0x0BD
	goto_eq Route104_EventScript_1ED1BE
	end

Route104_EventScript_1ED1B4:: @ 81ED1B4
	msgbox Route104_Text_1E9AAF, 4
	releaseall
	end

Route104_EventScript_1ED1BE:: @ 81ED1BE
	msgbox Route104_Text_1E9C1D, 4
	releaseall
	end

Route104_Movement_1ED1C8: @ 81ED1C8
	step_down
	step_down
	step_down
	step_down
	step_15
	step_15
	step_15
	step_15
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_15
	step_15
	step_15
	step_15
	step_18
	step_18
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_18
	step_18
	step_15
	step_15
	step_15
	step_15
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_end

Route104_Movement_1ED22A: @ 81ED22A
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_15
	step_15
	step_15
	step_15
	step_18
	step_18
	step_18
	step_18
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_18
	step_18
	step_18
	step_18
	step_right
	step_right
	step_down
	step_down
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_down
	step_down
	step_end

Route104_Movement_1ED28C: @ 81ED28C
	step_down
	step_down
	step_down
	step_down
	step_15
	step_15
	step_15
	step_15
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_15
	step_15
	step_15
	step_15
	step_18
	step_18
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_18
	step_18
	step_15
	step_15
	step_15
	step_15
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_15
	step_15
	step_15
	step_15
	step_18
	step_18
	step_18
	step_18
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_30
	step_18
	step_18
	step_18
	step_18
	step_right
	step_right
	step_down
	step_down
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_down
	step_down
	step_end

Route104_Movement_1ED34F: @ 81ED34F
	step_left
	step_down
	step_down
	step_end

Route104_Movement_1ED353: @ 81ED353
	step_down
	step_end

Route104_Movement_1ED355: @ 81ED355
	step_down
	step_left
	step_28
	step_end

Route104_Movement_1ED359: @ 81ED359
	step_down
	step_down
	step_end

Route104_Movement_1ED35C: @ 81ED35C
	step_down
	step_27
	step_end

Route104_EventScript_1ED35F:: @ 81ED35F
	trainerbattle 0, TRAINER_IVAN, 0, Route104_Text_2954BD, Route104_Text_295509
	msgbox Route104_Text_29554E, 6
	end

Route104_EventScript_1ED376:: @ 81ED376
	trainerbattle 0, TRAINER_BILLY, 0, Route104_Text_29558A, Route104_Text_2955B4
	msgbox Route104_Text_2955E8, 6
	end

Route104_EventScript_1ED38D:: @ 81ED38D
	trainerbattle 2, TRAINER_HALEY_1, 0, Route104_Text_29563A, Route104_Text_29566F, Route104_EventScript_1ED3CE
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ED424
	setvar VAR_0x8004, 604
	specialvar VAR_RESULT, sub_813B4E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_1ED3F8
	msgbox Route104_Text_295689, 4
	release
	end

Route104_EventScript_1ED3CE:: @ 81ED3CE
	special sub_80B4808
	waitmovement 0
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED3DF
	release
	end

Route104_EventScript_1ED3DF:: @ 81ED3DF
	msgbox Route104_Text_29576B, 4
	setvar VAR_0x8004, 604
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 604
	callstd 8
	release
	end

Route104_EventScript_1ED3F8:: @ 81ED3F8
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED40B
	msgbox Route104_Text_295689, 4
	release
	end

Route104_EventScript_1ED40B:: @ 81ED40B
	msgbox Route104_Text_2956FF, 4
	setvar VAR_0x8004, 604
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 604
	callstd 8
	release
	end

Route104_EventScript_1ED424:: @ 81ED424
	trainerbattle 5, TRAINER_HALEY_1, 0, Route104_Text_2957D7, Route104_Text_2957F0
	msgbox Route104_Text_29580C, 6
	end

Route104_EventScript_1ED43B:: @ 81ED43B
	trainerbattle 2, TRAINER_WINSTON_1, 0, Route104_Text_295870, Route104_Text_2958AD, Route104_EventScript_1ED47C
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ED4D2
	setvar VAR_0x8004, 136
	specialvar VAR_RESULT, sub_813B4E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_1ED4A6
	msgbox Route104_Text_2958C1, 4
	release
	end

Route104_EventScript_1ED47C:: @ 81ED47C
	special sub_80B4808
	waitmovement 0
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED48D
	release
	end

Route104_EventScript_1ED48D:: @ 81ED48D
	msgbox Route104_Text_29595A, 4
	setvar VAR_0x8004, 136
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 136
	callstd 8
	release
	end

Route104_EventScript_1ED4A6:: @ 81ED4A6
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED4B9
	msgbox Route104_Text_2958C1, 4
	release
	end

Route104_EventScript_1ED4B9:: @ 81ED4B9
	msgbox Route104_Text_2958F8, 4
	setvar VAR_0x8004, 136
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 136
	callstd 8
	release
	end

Route104_EventScript_1ED4D2:: @ 81ED4D2
	trainerbattle 5, TRAINER_WINSTON_1, 0, Route104_Text_2959BC, Route104_Text_2959FC
	msgbox Route104_Text_295A1E, 6
	end

Route104_EventScript_1ED4E9:: @ 81ED4E9
	trainerbattle 2, TRAINER_CINDY_1, 0, Route104_Text_295A7E, Route104_Text_295ABB, Route104_EventScript_1ED52A
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route104_EventScript_1ED580
	setvar VAR_0x8004, 114
	specialvar VAR_RESULT, sub_813B4E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route104_EventScript_1ED554
	msgbox Route104_Text_295AC3, 4
	release
	end

Route104_EventScript_1ED52A:: @ 81ED52A
	special sub_80B4808
	waitmovement 0
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED53B
	release
	end

Route104_EventScript_1ED53B:: @ 81ED53B
	msgbox Route104_Text_295B60, 4
	setvar VAR_0x8004, 114
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 114
	callstd 8
	release
	end

Route104_EventScript_1ED554:: @ 81ED554
	checkflag FLAG_0x12F
	goto_eq Route104_EventScript_1ED567
	msgbox Route104_Text_295AC3, 4
	release
	end

Route104_EventScript_1ED567:: @ 81ED567
	msgbox Route104_Text_295B01, 4
	setvar VAR_0x8004, 114
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 114
	callstd 8
	release
	end

Route104_EventScript_1ED580:: @ 81ED580
	trainerbattle 5, TRAINER_CINDY_1, 0, Route104_Text_295BC8, Route104_Text_295BFA
	msgbox Route104_Text_295C1F, 6
	end

Route104_EventScript_1ED597:: @ 81ED597
	trainerbattle 4, TRAINER_GINA_AND_MIA_1, 0, Route104_Text_2952BB, Route104_Text_2952E6, Route104_Text_295330
	special sub_8138B10
	msgbox Route104_Text_2952FE, 4
	release
	end

Route104_EventScript_1ED5B6:: @ 81ED5B6
	trainerbattle 4, TRAINER_GINA_AND_MIA_1, 0, Route104_Text_2953AF, Route104_Text_2953E1, Route104_Text_295449
	special sub_8138B10
	msgbox Route104_Text_29540D, 4
	release
	end

Route104_EventScript_1ED5D5:: @ 81ED5D5
	trainerbattle 0, TRAINER_DARIAN, 0, Route104_Text_295C5D, Route104_Text_295CC9
	msgbox Route104_Text_295CD3, 6
	end

Route104_Text_1ED5EC: @ 81ED5EC
	.string "That seaside cottage is where\n"
	.string "MR. BRINEY lives.\p"
	.string "He was once a mighty sailor who never\n"
	.string "feared the sea, however stormy.$"

Route104_Text_1ED662: @ 81ED662
	.string "The sea, huh?\p"
	.string "I wonder what it’s like at the bottom\n"
	.string "of the sea?$"

Route104_Text_1ED6A2: @ 81ED6A2
	.string "If you’re going to throw a POKé BALL,\n"
	.string "weaken the wild POKéMON first.\p"
	.string "It will be easier to catch if it’s been\n"
	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_1ED735: @ 81ED735
	.string "You’re a thief if you try to steal\n"
	.string "someone else’s POKéMON.\p"
	.string "You should throw POKé BALLS only at\n"
	.string "wild POKéMON.$"

Route104_Text_1ED7A2: @ 81ED7A2
	.string "Oh, no, I’m not a TRAINER.\p"
	.string "But that’s right, if TRAINERS lock eyes,\n"
	.string "it’s a challenge to battle.\p"
	.string "If you don’t want to battle, stay out\n"
	.string "of their sight.$"

Route104_Text_1ED838: @ 81ED838
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for firing seeds rapidly.$"

Route104_Text_1ED8E7: @ 81ED8E7
	.string "A word of advice!\p"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it’s gone.\n"
	.string "Think twice before using it!$"

Route104_Text_1ED96A: @ 81ED96A
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don’t need this WHITE HERB anymore.\n"
	.string "Would you take it, please?$"

Route104_Text_1EDA0F: @ 81EDA0F
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_1EDA8C: @ 81EDA8C
	.string "MR. BRINEY’S COTTAGE$"

Route104_Text_1EDAA1: @ 81EDAA1
	.string "ROUTE 1O4\n"
	.string "{0x7C} PETALBURG CITY$"

Route104_Text_1EDABC: @ 81EDABC
	.string "ROUTE 1O4\n"
	.string "{0x79} RUSTBORO CITY$"

Route104_Text_1EDAD6: @ 81EDAD6
	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_1EDAEF: @ 81EDAEF
	.string "TRAINER TIPS\p"
	.string "In the HOENN region there are pairs\n"
	.string "of TRAINERS who challenge others\l"
	.string "for 2-on-2 POKéMON battles called\l"
	.string "DOUBLE BATTLES.\p"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
	.string "send out two POKéMON, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how POKéMON are lined up.$"

Route104_Text_1EDBFF: @ 81EDBFF
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
	.string "DEVON upgraded your POKéNAV with\n"
	.string "the MATCH CALL system, huh?\p"
	.string "We should register each other so we\n"
	.string "can get in contact anytime.$"

Route104_Text_1EDC8F: @ 81EDC8F
	.string "{PLAYER} registered MAY\n"
	.string "in the POKéNAV.$"

Route104_Text_1EDCB1: @ 81EDCB1
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
	.string "how’s your POKéDEX coming along?$"

Route104_Text_1EDCED: @ 81EDCED
	.string "Mine’s looking pretty decent.\n"
	.string "So…\l"
	.string "How about a little battle?$"

Route104_Text_1EDD2A: @ 81EDD2A
	.string "MAY: Oh, what’s the matter?\p"
	.string "Haven’t you caught or raised your\n"
	.string "POKéMON very much?\p"
	.string "That’s not very good for a TRAINER!$"

Route104_Text_1EDD9F: @ 81EDD9F
	.string "MAY: So, what do you think?\n"
	.string "How about a little battle here?$"

Route104_Text_1EDDDB: @ 81EDDDB
	.string "MAY: You just became a TRAINER,\n"
	.string "{PLAYER}{KUN}. I’m not going to lose!$"

Route104_Text_1EDE18: @ 81EDE18
	.string "Yikes!\n"
	.string "You’re better than I expected!$"

Route104_Text_1EDE3E: @ 81EDE3E
	.string "MAY: I can tell you’ve gotten pretty\n"
	.string "good with the way you handle POKéMON.\p"
	.string "But instead of only making them\n"
	.string "battle, you should be like MR. BRINEY.\p"
	.string "It’s important to become friends with\n"
	.string "POKéMON, too.$"

Route104_Text_1EDF04: @ 81EDF04
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
	.string "Cool, you had DEVON install the MATCH\n"
	.string "CALL system on your POKéNAV!\p"
	.string "Let’s register each other in our\n"
	.string "POKéNAVS so we can keep in touch.$"

Route104_Text_1EDFA0: @ 81EDFA0
	.string "{PLAYER} registered BRENDAN\n"
	.string "in the POKéNAV.$"

Route104_Text_1EDFC6: @ 81EDFC6
	.string "BRENDAN: {PLAYER}, how’s your POKéDEX?\n"
	.string "Have you filled in any pages yet?$"

Route104_Text_1EE009: @ 81EE009
	.string "Me, I’m doing great!\p"
	.string "Want to check out how good I am with\n"
	.string "a battle?$"

Route104_Text_1EE04D: @ 81EE04D
	.string "BRENDAN: What’s the matter? Don’t have\n"
	.string "any confidence in your POKéMON?$"

Route104_Text_1EE094: @ 81EE094
	.string "BRENDAN: What’s up?\n"
	.string "Want to have a battle with me?$"

Route104_Text_1EE0C7: @ 81EE0C7
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won’t go easy!$"

Route104_Text_1EE107: @ 81EE107
	.string "Hmm…\n"
	.string "You’re pretty good.$"

Route104_Text_1EE120: @ 81EE120
	.string "BRENDAN: You’ve gotten pretty decent\n"
	.string "at handling POKéMON.\p"
	.string "But, you know, you shouldn’t just be\n"
	.string "making POKéMON battle.\p"
	.string "Like MR. BRINEY, it’s important to\n"
	.string "become friends with your POKéMON.$"

