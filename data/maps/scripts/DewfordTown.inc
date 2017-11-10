DewfordTown_MapScripts:: @ 81E9507
	map_script 3, DewfordTown_MapScript1_1E950D
	.byte 0

DewfordTown_MapScript1_1E950D: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_1E9511:: @ 81E9511
	lock
	faceplayer
	checkflag FLAG_0x0BD
	goto_if 0, DewfordTown_EventScript_1E9585
	message DewfordTown_Text_1E9C8A
	waitmessage
	multichoicedefault 21, 6, 0, 2, 0
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_1E955A
	case 1, DewfordTown_EventScript_1E956A
	case 2, DewfordTown_EventScript_1E957A
	case 127, DewfordTown_EventScript_1E957A
	end

DewfordTown_EventScript_1E955A:: @ 81E955A
	msgbox DewfordTown_Text_1E9CE5, 4
	closemessage
	goto DewfordTown_EventScript_1E9660
	release
	end

DewfordTown_EventScript_1E956A:: @ 81E956A
	msgbox DewfordTown_Text_1E9D3A, 4
	closemessage
	goto DewfordTown_EventScript_1E96E7
	release
	end

DewfordTown_EventScript_1E957A:: @ 81E957A
	msgbox DewfordTown_Text_1E9D8F, 4
	closemessage
	release
	end

DewfordTown_EventScript_1E9585:: @ 81E9585
	msgbox DewfordTown_Text_1E9B24, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq DewfordTown_EventScript_1E95A2
	msgbox DewfordTown_Text_1E9BD9, 4
	release
	end

DewfordTown_EventScript_1E95A2:: @ 81E95A2
	msgbox DewfordTown_Text_1E9B7F, 4
	closemessage
	goto DewfordTown_EventScript_1E9660
	end

DewfordTown_EventScript_1E95B1:: @ 81E95B1
	msgbox DewfordTown_Text_1E99A8, 2
	end

DewfordTown_EventScript_1E95BA:: @ 81E95BA
	msgbox DewfordTown_Text_1E9A0F, 3
	end

DewfordTown_EventScript_1E95C3:: @ 81E95C3
	msgbox DewfordTown_Text_1E9A3D, 3
	end

DewfordTown_EventScript_1E95CC:: @ 81E95CC
	msgbox DewfordTown_Text_1E9A7F, 3
	end

DewfordTown_EventScript_1E95D5:: @ 81E95D5
	lock
	faceplayer
	checkflag FLAG_0x101
	goto_eq DewfordTown_EventScript_1E962A
	msgbox DewfordTown_Text_1E9DD1, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq DewfordTown_EventScript_1E95FF
	compare_var_to_value VAR_RESULT, 0
	goto_eq DewfordTown_EventScript_1E9620
	end

DewfordTown_EventScript_1E95FF:: @ 81E95FF
	msgbox DewfordTown_Text_1E9E14, 4
	giveitem_std ITEM_OLD_ROD
	setflag FLAG_0x101
	msgbox DewfordTown_Text_1E9E65, 4
	release
	end

DewfordTown_EventScript_1E9620:: @ 81E9620
	msgbox DewfordTown_Text_1E9F92, 4
	release
	end

DewfordTown_EventScript_1E962A:: @ 81E962A
	message DewfordTown_Text_1E9FB8
	waitmessage
	multichoice 20, 8, 50, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq DewfordTown_EventScript_1E964C
	compare_var_to_value VAR_RESULT, 1
	goto_eq DewfordTown_EventScript_1E9656
	end

DewfordTown_EventScript_1E964C:: @ 81E964C
	msgbox DewfordTown_Text_1E9FD0, 4
	release
	end

DewfordTown_EventScript_1E9656:: @ 81E9656
	msgbox DewfordTown_Text_1EA004, 4
	release
	end

DewfordTown_EventScript_1E9660:: @ 81E9660
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, DEWFORD_TOWN, 0
	setobjectpriority 255, DEWFORD_TOWN, 0
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement 255, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat 255, DEWFORD_TOWN
	call DewfordTown_EventScript_2720A0
	applymovement 4, DewfordTown_Movement_1E97A2
	applymovement 255, DewfordTown_Movement_1E97A2
	waitmovement 0
	showobjectat 255, ROUTE_104
	call DewfordTown_EventScript_2720A8
	applymovement 255, DewfordTown_Movement_1E9914
	waitmovement 0
	showobjectat 255, ROUTE_104
	clearflag FLAG_0x2E3
	clearflag FLAG_0x371
	clearflag FLAG_0x2E6
	setflag FLAG_0x2E7
	hideobjectat 4, DEWFORD_TOWN
	setvar VAR_0x408E, 2
	resetobjectpriority 255, DEWFORD_TOWN
	warp ROUTE_104_MR_BRINEYS_HOUSE, 255, 5, 4
	copyvar VAR_0x4096, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_1E96E7:: @ 81E96E7
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, DEWFORD_TOWN, 0
	setobjectpriority 255, DEWFORD_TOWN, 1
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement 255, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat 255, DEWFORD_TOWN
	call DewfordTown_EventScript_2720A0
	applymovement 4, DewfordTown_Movement_1E9865
	applymovement 255, DewfordTown_Movement_1E9865
	waitmovement 0
	call DewfordTown_EventScript_2720A8
	showobjectat 255, ROUTE_109
	applymovement 255, DewfordTown_Movement_1E9918
	waitmovement 0
	setobjectxyperm 2, 21, 26
	addobject 2
	setobjectpriority 2, ROUTE_109, 0
	applymovement 2, DewfordTown_Movement_1E991F
	waitmovement 0
	clearflag FLAG_0x2E5
	addobject 1
	clearflag FLAG_0x2E8
	setflag FLAG_0x2E7
	hideobjectat 4, DEWFORD_TOWN
	checkflag FLAG_0x095
	call_if 0, DewfordTown_EventScript_1E9790
	checkflag FLAG_0x095
	call_if 1, DewfordTown_EventScript_1E9799
	closemessage
	copyvar VAR_0x4096, VAR_0x8008
	resetobjectpriority 255, DEWFORD_TOWN
	resetobjectpriority 2, ROUTE_109
	moveobjectoffscreen 2
	release
	end

DewfordTown_EventScript_1E9790:: @ 81E9790
	msgbox DewfordTown_Text_1EEC1D, 4
	return

DewfordTown_EventScript_1E9799:: @ 81E9799
	msgbox DewfordTown_Text_1EEDA7, 4
	return

DewfordTown_Movement_1E97A2: @ 81E97A2
	step_up
	step_up
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_up
	step_up
	step_left
	step_left
	step_17
	step_17
	step_17
	step_17
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_17
	step_17
	step_17
	step_17
	step_16
	step_16
	step_16
	step_16
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_16
	step_16
	step_16
	step_16
	step_17
	step_17
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_17
	step_17
	step_16
	step_16
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_16
	step_16
	step_16
	step_16
	step_up
	step_up
	step_up
	step_up
	step_end

DewfordTown_Movement_1E9865: @ 81E9865
	step_right
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
	step_16
	step_16
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_2e
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

DewfordTown_Movement_1E9911: @ 81E9911
	step_right
	step_up
	step_end

DewfordTown_Movement_1E9914: @ 81E9914
	step_up
	step_up
	step_up
	step_end

DewfordTown_Movement_1E9918: @ 81E9918
	step_up
	step_up
	step_up
	step_25
	step_end

DewfordTown_Movement_1E991D: @ 81E991D
	step_up
	step_end

DewfordTown_Movement_1E991F: @ 81E991F
	step_up
	step_up
	step_end

DewfordTown_EventScript_1E9922:: @ 81E9922
	lock
	faceplayer
	call DewfordTown_EventScript_271E8B
	msgbox DewfordTown_Text_1EA136, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq DewfordTown_EventScript_1E9948
	compare_var_to_value VAR_RESULT, 0
	goto_eq DewfordTown_EventScript_1E9952
	end

DewfordTown_EventScript_1E9948:: @ 81E9948
	msgbox DewfordTown_Text_1EA491, 4
	release
	end

DewfordTown_EventScript_1E9952:: @ 81E9952
	msgbox DewfordTown_Text_1EA242, 4
	setvar VAR_0x8004, 9
	call DewfordTown_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 1
	goto_eq DewfordTown_EventScript_1E997D
	compare_var_to_value VAR_RESULT, 0
	goto_eq DewfordTown_EventScript_1E9994
	end

DewfordTown_EventScript_1E997D:: @ 81E997D
	incrementgamestat 2
	compare_var_to_value VAR_0x8004, 0
	goto_eq DewfordTown_EventScript_1E999E
	msgbox DewfordTown_Text_1EA2AA, 4
	release
	end

DewfordTown_EventScript_1E9994:: @ 81E9994
	msgbox DewfordTown_Text_1EA443, 4
	release
	end

DewfordTown_EventScript_1E999E:: @ 81E999E
	msgbox DewfordTown_Text_1EA3FE, 4
	release
	end

DewfordTown_Text_1E99A8: @ 81E99A8
	.string "DEWFORD is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"

DewfordTown_Text_1E9A0F: @ 81E9A0F
	.string "DEWFORD TOWN\n"
	.string "“A tiny island in the blue sea.”$"

DewfordTown_Text_1E9A3D: @ 81E9A3D
	.string "DEWFORD TOWN POKéMON GYM\n"
	.string "LEADER: BRAWLY\l"
	.string "“A big wave in fighting!”$"

DewfordTown_Text_1E9A7F: @ 81E9A7F
	.string "DEWFORD HALL\n"
	.string "“Everyone’s information exchange!”$"

