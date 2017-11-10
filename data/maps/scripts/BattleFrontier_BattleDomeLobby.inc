BattleFrontier_BattleDomeLobby_MapScripts:: @ 82497E2
	map_script 5, BattleFrontier_BattleDomeLobby_MapScript1_2497F2
	map_script 2, BattleFrontier_BattleDomeLobby_MapScript2_24980F
	map_script 4, BattleFrontier_BattleDomeLobby_MapScript2_2497FB
	.byte 0

BattleFrontier_BattleDomeLobby_MapScript1_2497F2: @ 82497F2
	setvar VAR_0x8004, 21
	special sub_818E9AC
	end

BattleFrontier_BattleDomeLobby_MapScript2_2497FB: @ 82497FB
BattleFrontier_BattlePyramidLobby_MapScript2_2497FB: @ 82497FB
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattleDomeLobby_EventScript_249805
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249805:: @ 8249805
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

BattleFrontier_BattleDomeLobby_MapScript2_24980F: @ 824980F
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattleDomeLobby_EventScript_249839
	map_script_2 VAR_0x4000, 1, BattleFrontier_BattleDomeLobby_EventScript_249842
	map_script_2 VAR_0x4000, 2, BattleFrontier_BattleDomeLobby_EventScript_2499F9
	map_script_2 VAR_0x4000, 3, BattleFrontier_BattleDomeLobby_EventScript_24989B
	map_script_2 VAR_0x4000, 4, BattleFrontier_BattleDomeLobby_EventScript_249940
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249839:: @ 8249839
	setvar VAR_0x8004, 0
	special sub_81A1780
	end

BattleFrontier_BattleDomeLobby_EventScript_249842:: @ 8249842
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A45F, 4
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_24989B:: @ 824989B
	call BattleFrontier_BattleDomeLobby_EventScript_241EBA
	lockall
	setvar VAR_0x8004, 10
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleDomeLobby_EventScript_2498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24A4E9, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_2498C9

BattleFrontier_BattleDomeLobby_EventScript_2498C1:: @ 82498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24AD67, 4

BattleFrontier_BattleDomeLobby_EventScript_2498C9:: @ 82498C9
	msgbox BattleFrontier_BattleDomeLobby_Text_24ADB1, 4
	setvar VAR_0x8004, 11
	special sub_81A1780
	msgbox BattleFrontier_BattleDomeLobby_Text_241520, 9
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special copy_player_party_from_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	setvar VAR_0x8004, 8
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 1
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special sub_818E9AC
	special copy_player_party_from_sav1
	special sp000_heal_pokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_249991

BattleFrontier_BattleDomeLobby_EventScript_249940:: @ 8249940
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5BF, 4
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special copy_player_party_from_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	setvar VAR_0x8004, 8
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_818E9AC
	special copy_player_party_from_sav1
	special sp000_heal_pokemon

BattleFrontier_BattleDomeLobby_EventScript_249991:: @ 8249991
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	special sub_818E9AC
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleDomeLobby_EventScript_23E8E0
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleDomeLobby_EventScript_2499E9
	message BattleFrontier_BattleDomeLobby_Text_24AE17
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_2499E9
	case 0, BattleFrontier_BattleDomeLobby_EventScript_2499E4
	case 127, BattleFrontier_BattleDomeLobby_EventScript_2499E9

BattleFrontier_BattleDomeLobby_EventScript_2499E4:: @ 82499E4
	call BattleFrontier_BattleDomeLobby_EventScript_23E8B4

BattleFrontier_BattleDomeLobby_EventScript_2499E9:: @ 82499E9
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, 4
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_2499F9:: @ 82499F9
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5FE, 4
	message BattleFrontier_BattleDomeLobby_Text_24A61A
	waitmessage
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 1
	special sub_818E9AC
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_249BC2

BattleFrontier_BattleDomeLobby_EventScript_249A35:: @ 8249A35
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 1
	setvar VAR_0x40CE, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A47:: @ 8249A47
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 1
	setvar VAR_0x40CE, 1
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A59:: @ 8249A59
	special copy_player_party_to_sav1
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249CFD
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D06

BattleFrontier_BattleDomeLobby_EventScript_249A72:: @ 8249A72
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D0F
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D15
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249ABF
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249BFA
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case 127, BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249ABF:: @ 8249ABF
	message BattleFrontier_BattleDomeLobby_Text_24A210
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case 127, BattleFrontier_BattleDomeLobby_EventScript_249C64
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattleDomeLobby_EventScript_249C15
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattleDomeLobby_Text_24A26E, 4
	fadescreen 1
	call BattleFrontier_BattleDomeLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleDomeLobby_EventScript_249C61
	msgbox BattleFrontier_BattleDomeLobby_Text_24A1C6, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249C61
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249B60
	case 127, BattleFrontier_BattleDomeLobby_EventScript_249C61

BattleFrontier_BattleDomeLobby_EventScript_249B60:: @ 8249B60
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x8004, 0
	special sub_818E9AC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	call BattleFrontier_BattleDomeLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleDomeLobby_EventScript_249C4A
	setvar VAR_0x8004, 22
	special sub_818E9AC

BattleFrontier_BattleDomeLobby_EventScript_249BC2:: @ 8249BC2
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	setvar VAR_0x8004, 15
	special sub_818E9AC
	msgbox BattleFrontier_BattleDomeLobby_Text_24A437, 4
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_249C6E
	special sp000_heal_pokemon
	warp BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 255, 23, 6
	setvar VAR_0x4000, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249BFA:: @ 8249BFA
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D1B
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D24
	goto BattleFrontier_BattleDomeLobby_EventScript_249A72

BattleFrontier_BattleDomeLobby_EventScript_249C15:: @ 8249C15
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249C30
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249C3D

BattleFrontier_BattleDomeLobby_EventScript_249C30:: @ 8249C30
	msgbox BattleFrontier_BattleDomeLobby_Text_24A353, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C3D:: @ 8249C3D
	msgbox BattleFrontier_BattleDomeLobby_Text_24A2AB, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C4A:: @ 8249C4A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	goto BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249C61:: @ 8249C61
	special copy_player_party_from_sav1

BattleFrontier_BattleDomeLobby_EventScript_249C64:: @ 8249C64
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, 4

BattleFrontier_BattleDomeLobby_EventScript_249C6C:: @ 8249C6C
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_249C6E:: @ 8249C6E
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249CDD
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249CE5
	applymovement 255, BattleFrontier_BattleDomeLobby_Movement_249D45
	waitmovement 0
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D2D
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D33
	waitdooranim
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249CED
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249CF5
	applymovement 255, BattleFrontier_BattleDomeLobby_Movement_249D4E
	waitmovement 0
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D39
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249D3F
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_249CDD:: @ 8249CDD
	applymovement 1, BattleFrontier_BattleDomeLobby_Movement_249D45
	return

BattleFrontier_BattleDomeLobby_EventScript_249CE5:: @ 8249CE5
	applymovement 6, BattleFrontier_BattleDomeLobby_Movement_249D45
	return

BattleFrontier_BattleDomeLobby_EventScript_249CED:: @ 8249CED
	applymovement 1, BattleFrontier_BattleDomeLobby_Movement_249D4B
	return

BattleFrontier_BattleDomeLobby_EventScript_249CF5:: @ 8249CF5
	applymovement 6, BattleFrontier_BattleDomeLobby_Movement_249D4B
	return

BattleFrontier_BattleDomeLobby_EventScript_249CFD:: @ 8249CFD
	msgbox BattleFrontier_BattleDomeLobby_Text_249EB7, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D06:: @ 8249D06
	msgbox BattleFrontier_BattleDomeLobby_Text_24A664, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D0F:: @ 8249D0F
	message BattleFrontier_BattleDomeLobby_Text_249F3A
	return

BattleFrontier_BattleDomeLobby_EventScript_249D15:: @ 8249D15
	message BattleFrontier_BattleDomeLobby_Text_24A6E7
	return

BattleFrontier_BattleDomeLobby_EventScript_249D1B:: @ 8249D1B
	msgbox BattleFrontier_BattleDomeLobby_Text_249F8E, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D24:: @ 8249D24
	msgbox BattleFrontier_BattleDomeLobby_Text_24A721, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D2D:: @ 8249D2D
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D33:: @ 8249D33
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D39:: @ 8249D39
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D3F:: @ 8249D3F
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_249D45: @ 8249D45
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4B: @ 8249D4B
	step_up
	step_54
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4E: @ 8249D4E
	step_up
	step_up
	step_54
	step_end

BattleFrontier_BattleDomeLobby_EventScript_249D52:: @ 8249D52
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D6B:: @ 8249D6B
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D84:: @ 8249D84
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 9
	special sub_818E9AC
	compare_var_to_value VAR_RESULT, 0
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249DC9
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249DD2
	compare_var_to_value VAR_RESULT, 2
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249DDB
	compare_var_to_value VAR_RESULT, 3
	call_if 1, BattleFrontier_BattleDomeLobby_EventScript_249DE4
	fadescreen 1
	setvar VAR_0x8004, 8
	special sub_818E9AC
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249DC9:: @ 8249DC9
	msgbox BattleFrontier_BattleDomeLobby_Text_24A966, 3
	return

BattleFrontier_BattleDomeLobby_EventScript_249DD2:: @ 8249DD2
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9A9, 3
	return

BattleFrontier_BattleDomeLobby_EventScript_249DDB:: @ 8249DDB
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9EC, 3
	return

BattleFrontier_BattleDomeLobby_EventScript_249DE4:: @ 8249DE4
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA31, 3
	return

BattleFrontier_BattleDomeLobby_EventScript_249DED:: @ 8249DED
	setvar VAR_0x8004, 20
	special sub_818E9AC
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA76, 2
	end

BattleFrontier_BattleDomeLobby_EventScript_249DFE:: @ 8249DFE
	msgbox BattleFrontier_BattleDomeLobby_Text_24AB94, 2
	end

BattleFrontier_BattleDomeLobby_EventScript_249E07:: @ 8249E07
	msgbox BattleFrontier_BattleDomeLobby_Text_24AC76, 2
	end

BattleFrontier_BattleDomeLobby_EventScript_249E10:: @ 8249E10
	msgbox BattleFrontier_BattleDomeLobby_Text_24ACD3, 2
	end

BattleFrontier_OutsideWest_EventScript_249E19:: @ 8249E19
	msgbox BattleFrontier_OutsideWest_Text_24AB06, 2
	end

	.incbin "baserom.gba", 0x249e22, 0x12

BattleFrontier_BattleDomeLobby_EventScript_249E34:: @ 8249E34
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24AE63, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E43:: @ 8249E43
	message BattleFrontier_BattleDomeLobby_Text_24AE8B
	waitmessage
	multichoice 17, 4, 98, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249E8B
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249E99
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249EA7
	case 3, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	case 127, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	end

BattleFrontier_BattleDomeLobby_EventScript_249E8B:: @ 8249E8B
	msgbox BattleFrontier_BattleDomeLobby_Text_24AEAE, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E99:: @ 8249E99
	msgbox BattleFrontier_BattleDomeLobby_Text_24AF4C, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249EA7:: @ 8249EA7
	msgbox BattleFrontier_BattleDomeLobby_Text_24B073, 4
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249EB5:: @ 8249EB5
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_249EB7: @ 8249EB7
	.string "Where the strategies of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE DOME!\p"
	.string "I am your guide to the SINGLE BATTLE\n"
	.string "Tournament.$"

BattleFrontier_BattleDomeLobby_Text_249F3A: @ 8249F3A
	.string "Would you like to challenge\n"
	.string "the SINGLE BATTLE Tournament?$"

BattleFrontier_BattleDomeLobby_Text_249F74: @ 8249F74
	.string "We hope to see you again.$"

BattleFrontier_BattleDomeLobby_Text_249F8E: @ 8249F8E
	.string "The SINGLE BATTLE Tournament\n"
	.string "is exactly as the name suggests--\l"
	.string "a tournament of SINGLE BATTLES.\p"
	.string "All participating TRAINERS must\n"
	.string "enter three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The other two POKéMON can battle\n"
	.string "one at a time.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent’s trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to\n"
	.string "the tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don’t save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_24A1C6: @ 824A1C6
	.string "Before I show you to the BATTLE DOME,\n"
	.string "I must save the data. Is that okay?$"

BattleFrontier_BattleDomeLobby_Text_24A210: @ 824A210
	.string "The tournament offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleDomeLobby_Text_24A26E: @ 824A26E
	.string "Now select the three POKéMON that\n"
	.string "you wish to enter, please.$"

BattleFrontier_BattleDomeLobby_Text_24A2AB: @ 824A2AB
	.string "Excuse me!\p"
	.string "You don’t have three eligible POKéMON.\p"
	.string "Also, the POKéMON must be holding\n"
	.string "different kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleDomeLobby_Text_24A353: @ 824A353
	.string "Excuse me!\p"
	.string "You don’t have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleDomeLobby_Text_24A437: @ 824A437
	.string "I will now show you to\n"
	.string "the BATTLE DOME.$"

BattleFrontier_BattleDomeLobby_Text_24A45F: @ 824A45F
	.string "Excuse me!\p"
	.string "You didn’t save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleDomeLobby_Text_24A4E9: @ 824A4E9
	.string "Congratulations for winning\n"
	.string "your Battle Tournament!$"

	.incbin "baserom.gba", 0x24a51d, 0x37

