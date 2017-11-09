BattleFrontier_BattlePalaceBattleRoom_MapScripts:: @ 824F815
	map_script 3, BattleFrontier_BattlePalaceBattleRoom_MapScript1_24F825
	map_script 2, BattleFrontier_BattlePalaceBattleRoom_MapScript2_24F861
	map_script 4, BattleFrontier_BattlePalaceBattleRoom_MapScript2_24FE34
	.byte 0

BattleFrontier_BattlePalaceBattleRoom_MapScript1_24F825: @ 824F825
	setvar VAR_0x8004, 5
	special sub_81A1780
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833:: @ 824F833
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F84B
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F856
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F84B:: @ 824F84B
	setvar VAR_0x4011, 100
	setvar VAR_0x4010, 100
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F856:: @ 824F856
	setvar VAR_0x4011, 105
	setvar VAR_0x4010, 105
	return

BattleFrontier_BattlePalaceBattleRoom_MapScript2_24F861: @ 824F861
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F86B
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F86B:: @ 824F86B
	showobjectat 1, BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8B5
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE9B
	waitmovement 0
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	setvar VAR_0x4002, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_81A1780
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8B5:: @ 824F8B5
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE92
	waitmovement 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8BF:: @ 824F8BF
	setvar VAR_0x8004, 3
	special sub_8161F74
	addobject 2
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA1
	waitmovement 0
	setvar VAR_0x8004, 5
	special sub_8195960
	msgbox 0x2021fc4, 4
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F911

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA:: @ 824F8FA
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A1780
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F911:: @ 824F911
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_241EBA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	switch VAR_RESULT
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA7
	waitmovement 0
	removeobject 2
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_24FF00, 4
	special copy_player_party_from_sav1
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	playfanfare BGM_ME_ASA
	waitfanfare
	special sp000_heal_pokemon

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A:: @ 824F98A
	setvar VAR_0x8004, 9
	special sub_81A1780
	copyvar VAR_0x400F, VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB61
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE66
	compare_var_to_value VAR_RESULT, 2
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE6D
	compare_var_to_value VAR_RESULT, 3
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE74
	compare_var_to_value VAR_RESULT, 4
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE7B
	compare_var_to_value VAR_RESULT, 5
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE82
	compare_var_to_value VAR_RESULT, 6
	call_if 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE89
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8E0
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA42
	multichoice 19, 4, 103, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA42:: @ 824FA42
	multichoice 20, 6, 104, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78:: @ 824FA78
	message BattleFrontier_BattlePalaceBattleRoom_Text_25009E
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAAA
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAAA:: @ 824FAAA
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8B4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4:: @ 824FAB4
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250030, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB3F
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2:: @ 824FAE2
	message BattleFrontier_BattlePalaceBattleRoom_Text_25005A
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14:: @ 824FB14
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8BF

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28:: @ 824FB28
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special sub_81A1780
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB3F:: @ 824FB3F
	message BattleFrontier_BattlePalaceBattleRoom_Text_25007E
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	special sub_8195960
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special sub_81A1780
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB61:: @ 824FB61
	compare_var_to_value VAR_0x4002, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2500DD, 4
	setvar VAR_0x4002, 1

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79:: @ 824FB79
	message BattleFrontier_BattlePalaceBattleRoom_Text_25014A
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8E0
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FBD0
	multichoice 19, 4, 103, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FBD0:: @ 824FBD0
	multichoice 20, 6, 104, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06:: @ 824FC06
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_242170
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25017C, 4
	closemessage
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	setobjectxyperm 2, 15, 1
	addobject 2
	hideobjectat 2, BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setobjectxy 2, 13, 1
	setobjectxyperm 2, 13, 1
	applymovement 4, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEDF
	applymovement 5, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEE7
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEF2
	waitmovement 0
	switch VAR_0x400F
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD3A
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA
	case 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2501C1, 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special sub_81A1780

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA:: @ 824FCAA
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2502C4, 4
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCC7
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCC7:: @ 824FCC7
	setvar VAR_0x8004, 6
	special sub_8195960
	setvar VAR_0x8004, 12
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2502FF, 4
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25036D, 4
	playfanfare BGM_ME_BATTLE_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_2503DC
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special sub_81A1780
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_2725B6
	waitmovement 0
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_2725A8
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_2725A8
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250412, 4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD3A:: @ 824FD3A
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250485, 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special sub_81A1780

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67:: @ 824FD67
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250572, 4
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD84
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD84:: @ 824FD84
	setvar VAR_0x8004, 6
	special sub_8195960
	setvar VAR_0x8004, 12
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25057E, 4
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250629, 4
	playfanfare BGM_ME_BATTLE_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_250699
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special sub_81A1780
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_2725B6
	waitmovement 0
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_2725A8
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_2725A8
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2506C4, 4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7:: @ 824FDF7
VerdanturfTown_BattleTentBattleRoom_EventScript_24FDF7:: @ 824FDF7
	closemessage
	setvar VAR_0x4002, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special sub_81A1780
	special sp000_heal_pokemon
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 0
	special sub_8163AC4
	waitstate
	setvar VAR_0x8004, 18
	special sub_81A1780
	special sp000_heal_pokemon
	setvar VAR_0x8004, 21
	special sub_81A1780
	return

BattleFrontier_BattlePalaceBattleRoom_MapScript2_24FE34: @ 824FE34
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE3E
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE3E:: @ 824FE3E
	hideobjectat 1, BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833
	setvar VAR_0x4001, 1
	applymovement 255, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	removeobject 2
	applymovement 4, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	applymovement 5, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE66:: @ 824FE66
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF28
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE6D:: @ 824FE6D
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF54
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE74:: @ 824FE74
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF80
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE7B:: @ 824FE7B
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FFAC
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE82:: @ 824FE82
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FFD8
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE89:: @ 824FE89
	message BattleFrontier_BattlePalaceBattleRoom_Text_250004
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90: @ 824FE90
	step_54
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE92: @ 824FE92
	step_55
	step_up
	step_up
	step_up
	step_up

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97: @ 824FE97
	step_03
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99: @ 824FE99
	step_01
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE9B: @ 824FE9B
	step_55
	step_up
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA1: @ 824FEA1
	step_down
	step_down
	step_down
	step_down
	step_02
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA7: @ 824FEA7
	step_up
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC: @ 824FEAC
	step_00
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAE: @ 824FEAE
	step_55
	slow_step_down
	slow_step_down
	step_02
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEB3: @ 824FEB3
	step_55
	slow_step_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEB6: @ 824FEB6
	slow_step_down
	slow_step_down
	slow_step_down
	step_02
	step_end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB:: @ 824FEBB
	copyvar VAR_RESULT, VAR_0x40CE
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FED5
	warp BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 5, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FED5:: @ 824FED5
	warp BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 19, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEDF: @ 824FEDF
	step_14
	step_14
	step_55
	step_down
	step_right
	step_down
	step_27
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEE7: @ 824FEE7
	step_55
	step_15
	step_18
	step_15
	step_15
	step_15
	step_15
	step_15
	step_27
	step_14
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEF2: @ 824FEF2
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_14
	step_55
	slow_step_down
	slow_step_down
	slow_step_down
	slow_step_down
	step_02
	step_end

BattleFrontier_BattlePalaceBattleRoom_Text_24FF00: @ 824FF00
