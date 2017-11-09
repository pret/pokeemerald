BattleFrontier_BattlePalaceLobby_MapScripts:: @ 824D77E
	map_script 2, BattleFrontier_BattlePalaceLobby_MapScript2_24D79D
	map_script 4, BattleFrontier_BattlePalaceLobby_MapScript2_24D789
	.byte 0

BattleFrontier_BattlePalaceLobby_MapScript2_24D789: @ 824D789
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D793
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D793:: @ 824D793
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

BattleFrontier_BattlePalaceLobby_MapScript2_24D79D: @ 824D79D
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D7C7
	map_script_2 VAR_0x4000, 1, BattleFrontier_BattlePalaceLobby_EventScript_24D7D0
	map_script_2 VAR_0x4000, 2, BattleFrontier_BattlePalaceLobby_EventScript_24D908
	map_script_2 VAR_0x4000, 3, BattleFrontier_BattlePalaceLobby_EventScript_24D817
	map_script_2 VAR_0x4000, 4, BattleFrontier_BattlePalaceLobby_EventScript_24D873
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D7C7:: @ 824D7C7
	setvar VAR_0x8004, 0
	special sub_81A1780
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D7D0:: @ 824D7D0
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E636, 4
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_8195960
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special sub_8195960
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D817:: @ 824D817
	lockall
	setvar VAR_0x8004, 10
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E497, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D840

BattleFrontier_BattlePalaceLobby_EventScript_24D838:: @ 824D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EE81, 4

BattleFrontier_BattlePalaceLobby_EventScript_24D840:: @ 824D840
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EEB9, 4
	setvar VAR_0x8004, 11
	special sub_81A1780
	msgbox BattleFrontier_BattlePalaceLobby_Text_241520, 9
	message BattleFrontier_BattlePalaceLobby_Text_24E4F7
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, 4
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D873:: @ 824D873
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_24E41E
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special sub_8195960
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, 4
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D8A1:: @ 824D8A1
	setvar VAR_0x8004, 8
	special sub_81A1780
	special copy_player_party_from_sav1
	special sp000_heal_pokemon
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special sub_8195960
	playse SE_SAVE
	waitse
	call BattleFrontier_BattlePalaceLobby_EventScript_23E8E0
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24D907
	message BattleFrontier_BattlePalaceLobby_Text_24EF16
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24D907
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D902
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24D907

BattleFrontier_BattlePalaceLobby_EventScript_24D902:: @ 824D902
	call BattleFrontier_BattlePalaceLobby_EventScript_23E8B4

BattleFrontier_BattlePalaceLobby_EventScript_24D907:: @ 824D907
	return

BattleFrontier_BattlePalaceLobby_EventScript_24D908:: @ 824D908
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E5D8, 4
	message BattleFrontier_BattlePalaceLobby_Text_24E5F6
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special sub_8195960
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DAF3

BattleFrontier_BattlePalaceLobby_EventScript_24D944:: @ 824D944
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 2
	setvar VAR_0x40CE, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D956:: @ 824D956
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 2
	setvar VAR_0x40CE, 1
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D968:: @ 824D968
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	special sub_8195960
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattlePalaceLobby_EventScript_24D817
	special copy_player_party_to_sav1
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB9E
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DBA7

BattleFrontier_BattlePalaceLobby_EventScript_24D999:: @ 824D999
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DBB0
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DBB6
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D9E6
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB20
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24D9E6:: @ 824D9E6
	message BattleFrontier_BattlePalaceLobby_Text_24E119
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB45
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E399, 4
	fadescreen 1
	call BattleFrontier_BattlePalaceLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E3C8, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DA87
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24DB91

BattleFrontier_BattlePalaceLobby_EventScript_24DA87:: @ 824DA87
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x8004, 0
	special sub_8195960
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8195960
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
	call BattleFrontier_BattlePalaceLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB7A

BattleFrontier_BattlePalaceLobby_EventScript_24DAF3:: @ 824DAF3
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E408, 4
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24DBBC
	warp BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 255, 8, 13
	setvar VAR_0x4000, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB20:: @ 824DB20
	compare_var_to_value VAR_0x40CE, 1
	goto_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DE17, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB38:: @ 824DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EBC2, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB45:: @ 824DB45
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DB60
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB6D

BattleFrontier_BattlePalaceLobby_EventScript_24DB60:: @ 824DB60
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E173, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB6D:: @ 824DB6D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E29E, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB7A:: @ 824DB7A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24DB91:: @ 824DB91
	special copy_player_party_from_sav1

BattleFrontier_BattlePalaceLobby_EventScript_24DB94:: @ 824DB94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, 4

BattleFrontier_BattlePalaceLobby_EventScript_24DB9C:: @ 824DB9C
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB9E:: @ 824DB9E
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DD5B, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBA7:: @ 824DBA7
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EB06, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB0:: @ 824DBB0
	message BattleFrontier_BattlePalaceLobby_Text_24DDE1
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB6:: @ 824DBB6
	message BattleFrontier_BattlePalaceLobby_Text_24EB8C
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBBC:: @ 824DBBC
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC23
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC29
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	applymovement 255, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	waitmovement 0
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC2F
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC35
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC49
	applymovement 255, BattleFrontier_BattlePalaceLobby_Movement_24DC4C
	waitmovement 0
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC3B
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattlePalaceLobby_EventScript_24DC41
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC23:: @ 824DC23
	setvar VAR_LAST_TALKED, 1
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC29:: @ 824DC29
	setvar VAR_LAST_TALKED, 6
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC2F:: @ 824DC2F
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC35:: @ 824DC35
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC3B:: @ 824DC3B
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC41:: @ 824DC41
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_24DC47: @ 824DC47
	step_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC49: @ 824DC49
	step_up
	step_54
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC4C: @ 824DC4C
	step_up
	step_up
	step_54
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_24DC50:: @ 824DC50
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC69:: @ 824DC69
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC82:: @ 824DC82
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E6E3, 2
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC8B:: @ 824DC8B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E851, 2
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC94:: @ 824DC94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E992, 2
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC9D:: @ 824DC9D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EA4B, 2
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCA6:: @ 824DCA6
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EF66, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCB5:: @ 824DCB5
	message BattleFrontier_BattlePalaceLobby_Text_24EF88
	waitmessage
	multichoice 16, 0, 100, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DD13
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DD21
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DD2F
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_24DD3D
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_24DD4B
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD13:: @ 824DD13
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EFAB, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD21:: @ 824DD21
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F049, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD2F:: @ 824DD2F
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F190, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD3D:: @ 824DD3D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F2E8, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD4B:: @ 824DD4B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F3F4, 4
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD59:: @ 824DD59
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_24DD5B: @ 824DD5B
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the SINGLE\n"
	.string "BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_24DDE1: @ 824DDE1
	.string "Do you wish to take\n"
	.string "the SINGLE BATTLE HALL challenge?$"

BattleFrontier_BattlePalaceLobby_Text_24DE17: @ 824DE17
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for SINGLE BATTLES\l"
	.string "that are named SINGLE BATTLE HALLS.\p"
	.string "The SINGLE BATTLES are conducted in\n"
	.string "the usual way, except with one crucial\l"
	.string "rule that must be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must save the game.\p"
	.string "If you don’t save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePalaceLobby_Text_24E0D8: @ 824E0D8
	.string "When you have fortified your heart\n"
	.string "and POKéMON, you must return.$"

BattleFrontier_BattlePalaceLobby_Text_24E119: @ 824E119
	.string "There are two BATTLE HALLS,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which is your choice of a challenge?$"

BattleFrontier_BattlePalaceLobby_Text_24E173: @ 824E173
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "These POKéMON must all be of\n"
	.string "Level 50 or lower.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"

BattleFrontier_BattlePalaceLobby_Text_24E29E: @ 824E29E
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"

BattleFrontier_BattlePalaceLobby_Text_24E399: @ 824E399
	.string "Good. Now, you must select your\n"
	.string "three POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_24E3C8: @ 824E3C8
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"

BattleFrontier_BattlePalaceLobby_Text_24E408: @ 824E408
	.string "Good.\n"
	.string "Now, follow me.$"

BattleFrontier_BattlePalaceLobby_Text_24E41E: @ 824E41E
	.string "I feel privileged for having seen\n"
	.string "your POKéMON’s exploits.\p"
	.string "The results will be recorded.\n"
	.string "I must ask you to briefly wait.$"

BattleFrontier_BattlePalaceLobby_Text_24E497: @ 824E497
	.string "To achieve a 7-win streak…\p"
	.string "The bonds that bind your heart with\n"
	.string "your POKéMON seem firm and true.$"

BattleFrontier_BattlePalaceLobby_Text_24E4F7: @ 824E4F7
	.string "Your feat will be recorded.\n"
	.string "I must ask you to briefly wait.$"

BattleFrontier_BattlePalaceLobby_Text_24E533: @ 824E5333
    .string "For the feat of your 7-win streak,\n"
    .string "we present you with Battle Point(s).$"

