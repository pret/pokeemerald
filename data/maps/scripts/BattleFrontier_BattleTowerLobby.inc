BattleFrontier_BattleTowerLobby_MapScripts:: @ 823E67B
	map_script 5, BattleFrontier_BattleTowerLobby_MapScript1_23E690
	map_script 3, BattleFrontier_BattleTowerLobby_MapScript1_23E694
	map_script 2, BattleFrontier_BattleTowerLobby_MapScript2_23E6DD
	map_script 4, BattleFrontier_BattleTowerLobby_MapScript2_23E6C9
	.byte 0

BattleFrontier_BattleTowerLobby_MapScript1_23E690: @ 823E690
	special sub_81653CC
	end

BattleFrontier_BattleTowerLobby_MapScript1_23E694: @ 823E694
	call BattleFrontier_BattleTowerLobby_EventScript_28CC84
	setvar VAR_0x8004, 10
	special sub_81A085C
	compare_var_to_value VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E6B5
	checkflag FLAG_0x934
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E6C1

BattleFrontier_BattleTowerLobby_EventScript_23E6B5:: @ 823E6B5
	clearflag FLAG_0x2BD
	setvar VAR_0x8004, 23
	special sub_81A085C

BattleFrontier_BattleTowerLobby_EventScript_23E6C0:: @ 823E6C0
	end

BattleFrontier_BattleTowerLobby_EventScript_23E6C1:: @ 823E6C1
	setflag FLAG_0x2BD
	goto BattleFrontier_BattleTowerLobby_EventScript_23E6C0

BattleFrontier_BattleTowerLobby_MapScript2_23E6C9: @ 823E6C9
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattleTowerLobby_EventScript_23E6D3
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_23E6D3:: @ 823E6D3
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

BattleFrontier_BattleTowerLobby_MapScript2_23E6DD: @ 823E6DD
	map_script_2 VAR_0x4000, 0, BattleFrontier_BattleTowerLobby_EventScript_23E707
	map_script_2 VAR_0x4000, 1, BattleFrontier_BattleTowerLobby_EventScript_23E710
	map_script_2 VAR_0x4000, 2, BattleFrontier_BattleTowerLobby_EventScript_23E8EE
	map_script_2 VAR_0x4000, 3, BattleFrontier_BattleTowerLobby_EventScript_23E758
	map_script_2 VAR_0x4000, 4, BattleFrontier_BattleTowerLobby_EventScript_23E7F2
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_23E707:: @ 823E707
	setvar VAR_0x8004, 0
	special sub_81A1780
	end

BattleFrontier_BattleTowerLobby_EventScript_23E710:: @ 823E710
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_23F583, 4
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E758:: @ 823E758
	lock
	faceplayer
	setvar VAR_0x8004, 10
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E778
	message BattleFrontier_BattleTowerLobby_Text_23F60D
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_23E780

BattleFrontier_BattleTowerLobby_EventScript_23E778:: @ 823E778
	msgbox BattleFrontier_BattleTowerLobby_Text_241486, 4

BattleFrontier_BattleTowerLobby_EventScript_23E780:: @ 823E780
	setvar VAR_0x8004, 5
	special sub_8161F74
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E7A5
	message BattleFrontier_BattleTowerLobby_Text_23F844
	waitmessage
	playfanfare BGM_FANFA4
	waitfanfare
	msgbox BattleFrontier_BattleTowerLobby_Text_23F89F, 4

BattleFrontier_BattleTowerLobby_EventScript_23E7A5:: @ 823E7A5
	msgbox BattleFrontier_BattleTowerLobby_Text_2414D4, 4
	setvar VAR_0x8004, 11
	special sub_81A1780
	msgbox BattleFrontier_BattleTowerLobby_Text_241520, 9
	call BattleFrontier_BattleTowerLobby_EventScript_23E84D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare_var_to_value VAR_RESULT, 49
	goto_if 5, BattleFrontier_BattleTowerLobby_EventScript_23E7E2
	msgbox BattleFrontier_BattleTowerLobby_Text_23F79D, 4

BattleFrontier_BattleTowerLobby_EventScript_23E7E2:: @ 823E7E2
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, 4
	closemessage
	setvar VAR_0x4000, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E7F2:: @ 823E7F2
	compare_var_to_value VAR_0x40CE, 2
	goto_if 5, BattleFrontier_BattleTowerLobby_EventScript_23E81E
	checkflag FLAG_0x152
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E81E
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattleTowerLobby_EventScript_23E830

BattleFrontier_BattleTowerLobby_EventScript_23E81E:: @ 823E81E
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special sub_8161F74

BattleFrontier_BattleTowerLobby_EventScript_23E830:: @ 823E830
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_23F6F7
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_23E84D
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, 4
	closemessage
	setvar VAR_0x4000, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E84D:: @ 823E84D
	message BattleFrontier_BattleTowerLobby_Text_23F70F
	waitmessage
	setvar VAR_0x8004, 8
	special sub_81A1780
	special copy_player_party_from_sav1
	special sp000_heal_pokemon
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 0
	special sub_8161F74
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleTowerLobby_EventScript_23E8E0
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E8DF
	message BattleFrontier_BattleTowerLobby_Text_23FE3C
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23E8DF
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23E8B4
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23E8DF

BattleFrontier_BattleArenaBattleRoom_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleArenaLobby_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleDomeLobby_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleDomePreBattleRoom_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleFactoryLobby_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattlePalaceLobby_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleTowerBattleRoom2_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleTowerBattleRoom_EventScript_23E8B4:: @ 823E8B4
BattleFrontier_BattleTowerLobby_EventScript_23E8B4:: @ 823E8B4
	setvar VAR_0x8004, 19
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23E8D7
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_2423CD, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23E8DF

BattleFrontier_BattleTowerLobby_EventScript_23E8D7:: @ 823E8D7
	msgbox gText_BattleRecordCouldntBeSaved, 4

BattleFrontier_BattleTowerLobby_EventScript_23E8DF:: @ 823E8DF
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleArenaLobby_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleDomeLobby_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleDomePreBattleRoom_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleFactoryLobby_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattlePalaceLobby_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleTowerBattleRoom2_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleTowerBattleRoom_EventScript_23E8E0:: @ 823E8E0
BattleFrontier_BattleTowerLobby_EventScript_23E8E0:: @ 823E8E0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 6
	special sub_81A1780
	return

BattleFrontier_BattleTowerLobby_EventScript_23E8EE:: @ 823E8EE
	lock
	faceplayer
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23E930
	message BattleFrontier_BattleTowerLobby_Text_23F737
	waitmessage
	message BattleFrontier_BattleTowerLobby_Text_23F754
	waitmessage
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 1
	special sub_8161F74
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23E930:: @ 823E930
	setvar VAR_0x40BC, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_23E936:: @ 823E936
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special copy_player_party_to_sav1
	msgbox BattleFrontier_BattleTowerLobby_Text_240537, 4

BattleFrontier_BattleTowerLobby_EventScript_23E948:: @ 823E948
	message BattleFrontier_BattleTowerLobby_Text_2405B3
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23E984
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EA91
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23E984:: @ 823E984
	setvar VAR_0x40CE, 0
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattleTowerLobby_Text_2407A6, 4
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EA2A
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EA2A:: @ 823EA2A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	call BattleFrontier_BattleTowerLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat 30
	setvar VAR_0x40BC, 1
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23EA91:: @ 823EA91
	msgbox BattleFrontier_BattleTowerLobby_Text_2405EC, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23E948
	end

BattleFrontier_BattleTowerLobby_EventScript_23EA9F:: @ 823EA9F
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special copy_player_party_to_sav1
	msgbox BattleFrontier_BattleTowerLobby_Text_2407E2, 4

BattleFrontier_BattleTowerLobby_EventScript_23EAB1:: @ 823EAB1
	message BattleFrontier_BattleTowerLobby_Text_24085E
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EAED
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EBFA
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EAED:: @ 823EAED
	setvar VAR_0x40CE, 1
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattleTowerLobby_Text_240A50, 4
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 4
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EB93
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EB93:: @ 823EB93
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	call BattleFrontier_BattleTowerLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat 30
	setvar VAR_0x40BC, 0
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23EBFA:: @ 823EBFA
	msgbox BattleFrontier_BattleTowerLobby_Text_240897, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23EAB1
	end

BattleFrontier_BattleTowerLobby_EventScript_23EC08:: @ 823EC08
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	clearflag FLAG_0x152
	special copy_player_party_to_sav1
	msgbox BattleFrontier_BattleTowerLobby_Text_240A8B, 4

BattleFrontier_BattleTowerLobby_EventScript_23EC1D:: @ 823EC1D
	message BattleFrontier_BattleTowerLobby_Text_240B06
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EC59
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23ED66
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EC59:: @ 823EC59
	setvar VAR_0x40CE, 2
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattleTowerLobby_Text_240DDB, 4
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 2
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23ECFF
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23ECFF:: @ 823ECFF
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	call BattleFrontier_BattleTowerLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat 30
	setvar VAR_0x40BC, 0
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23ED66:: @ 823ED66
	msgbox BattleFrontier_BattleTowerLobby_Text_240B3E, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23EC1D
	end

BattleFrontier_BattleTowerLobby_EventScript_23ED74:: @ 823ED74
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special copy_player_party_to_sav1
	msgbox BattleFrontier_BattleTowerLobby_Text_240E15, 4

BattleFrontier_BattleTowerLobby_EventScript_23ED86:: @ 823ED86
	message BattleFrontier_BattleTowerLobby_Text_240E95
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EDC2
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F3DA
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EDC2:: @ 823EDC2
	setvar VAR_0x40CE, 3
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, 24, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare_var_to_value VAR_0x8004, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	msgbox BattleFrontier_BattleTowerLobby_Text_24115E, 4
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 2
	special sub_80F9490
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EE68
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EE68:: @ 823EE68
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 0
	special sub_8161F74
	call BattleFrontier_BattleTowerLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat 30
	specialvar VAR_RESULT, sub_80093CC
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F3E8
	goto BattleFrontier_BattleTowerLobby_EventScript_23F2C5
	end

BattleFrontier_BattleTowerLobby_EventScript_23EEE7:: @ 823EEE7
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_23F8CD
	waitmessage
	multichoice 16, 4, 109, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EF32
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EF4C
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23EF66
	case 3, BattleFrontier_BattleTowerLobby_EventScript_23EF80
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23EF80
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF32:: @ 823EF32
	msgbox BattleFrontier_BattleTowerLobby_Text_23F969, 4
	setvar VAR_0x8004, 1
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF4C:: @ 823EF4C
	msgbox BattleFrontier_BattleTowerLobby_Text_23F9AA, 4
	setvar VAR_0x8004, 2
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF66:: @ 823EF66
	msgbox BattleFrontier_BattleTowerLobby_Text_23F9D4, 4
	setvar VAR_0x8004, 3
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF80:: @ 823EF80
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA0F, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF8A:: @ 823EF8A
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23EFA1
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23EFAB
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFA1:: @ 823EFA1
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA4F, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFAB:: @ 823EFAB
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA83, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFB5:: @ 823EFB5
	msgbox BattleFrontier_BattleTowerLobby_Text_23FAC0, 2
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFBE:: @ 823EFBE
	msgbox BattleFrontier_BattleTowerLobby_Text_23FB26, 2
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFC7:: @ 823EFC7
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFE0:: @ 823EFE0
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFF9:: @ 823EFF9
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23F012:: @ 823F012
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special sub_81A1780
	waitbuttonpress
	special sub_813C5A0
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23F02B:: @ 823F02B
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F046
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F08B

BattleFrontier_BattleTowerLobby_EventScript_23F046:: @ 823F046
	switch VAR_0x40CE
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F06F
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F07D
	msgbox BattleFrontier_BattleTowerLobby_Text_24038B, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F06F:: @ 823F06F
	msgbox BattleFrontier_BattleTowerLobby_Text_240027, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F07D:: @ 823F07D
	msgbox BattleFrontier_BattleTowerLobby_Text_2401DB, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F08B:: @ 823F08B
	switch VAR_0x40CE
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0B4
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F0C2
	msgbox BattleFrontier_BattleTowerLobby_Text_24046B, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0B4:: @ 823F0B4
	msgbox BattleFrontier_BattleTowerLobby_Text_24010B, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0C2:: @ 823F0C2
	msgbox BattleFrontier_BattleTowerLobby_Text_2402BD, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0D0:: @ 823F0D0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	special sub_81A1780
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0E3:: @ 823F0E3
	special copy_player_party_from_sav1

BattleFrontier_BattleTowerLobby_EventScript_23F0E6:: @ 823F0E6
	special sub_80097E8
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, 4

BattleFrontier_BattleTowerLobby_EventScript_23F0F1:: @ 823F0F1
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0F3:: @ 823F0F3
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 3
	call BattleFrontier_BattleTowerLobby_EventScript_23F272
	special sub_81A1780
	setvar VAR_RESULT, 0

BattleFrontier_BattleTowerLobby_EventScript_23F108:: @ 823F108
	setvar VAR_0x8004, 12
	special sub_8161F74
	delay 1
	compare_var_to_value VAR_RESULT, 6
	goto_if 5, BattleFrontier_BattleTowerLobby_EventScript_23F108
	call BattleFrontier_BattleTowerLobby_EventScript_23F135
	clearflag FLAG_0x077
	warp BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	setvar VAR_0x4000, 0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_23F135:: @ 823F135
	call BattleFrontier_BattleTowerLobby_EventScript_23F1A7
	compare_var_to_value VAR_0x40CE, 3
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F152
	msgbox BattleFrontier_BattleTowerLobby_Text_23FE11, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F15B

BattleFrontier_BattleTowerLobby_EventScript_23F152:: @ 823F152
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_23FE11
	waitmessage
	delay 48

BattleFrontier_BattleTowerLobby_EventScript_23F15B:: @ 823F15B
	closemessage
	call BattleFrontier_BattleTowerLobby_EventScript_23F1E8
	call BattleFrontier_BattleTowerLobby_EventScript_23F22D
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_23F195
	applymovement 255, BattleFrontier_BattleTowerLobby_Movement_23F195
	waitmovement 0
	opendoor VAR_0x8004, 1
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_23F199
	applymovement 255, BattleFrontier_BattleTowerLobby_Movement_23F19C
	waitmovement 0
	closedoor VAR_0x8004, 1
	waitdooranim
	return

BattleFrontier_BattleTowerLobby_Movement_23F195: @ 823F195
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_23F199: @ 823F199
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerLobby_Movement_23F19C: @ 823F19C
	step_up
	step_up
	step_54
	step_end

	.incbin "baserom.gba", 0x23f1a0, 0x7

BattleFrontier_BattleTowerLobby_EventScript_23F1A7:: @ 823F1A7
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F1D4
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F1D9
	compare_var_to_value VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F1DE
	compare_var_to_value VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F1E3
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1D4:: @ 823F1D4
	bufferstdstring 0, 19
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1D9:: @ 823F1D9
	bufferstdstring 0, 20
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1DE:: @ 823F1DE
	bufferstdstring 0, 21
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1E3:: @ 823F1E3
	bufferstdstring 0, 22
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1E8:: @ 823F1E8
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F215
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F21B
	compare_var_to_value VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F221
	compare_var_to_value VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F227
	return

BattleFrontier_BattleTowerLobby_EventScript_23F215:: @ 823F215
	setvar VAR_LAST_TALKED, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_23F21B:: @ 823F21B
	setvar VAR_LAST_TALKED, 7
	return

BattleFrontier_BattleTowerLobby_EventScript_23F221:: @ 823F221
	setvar VAR_LAST_TALKED, 8
	return

BattleFrontier_BattleTowerLobby_EventScript_23F227:: @ 823F227
	setvar VAR_LAST_TALKED, 9
	return

BattleFrontier_BattleTowerLobby_EventScript_23F22D:: @ 823F22D
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F25A
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F260
	compare_var_to_value VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F266
	compare_var_to_value VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F26C
	return

BattleFrontier_BattleTowerLobby_EventScript_23F25A:: @ 823F25A
	setvar VAR_0x8004, 6
	return

BattleFrontier_BattleTowerLobby_EventScript_23F260:: @ 823F260
	setvar VAR_0x8004, 10
	return

BattleFrontier_BattleTowerLobby_EventScript_23F266:: @ 823F266
	setvar VAR_0x8004, 14
	return

BattleFrontier_BattleTowerLobby_EventScript_23F26C:: @ 823F26C
	setvar VAR_0x8004, 18
	return

BattleFrontier_BattleTowerLobby_EventScript_23F272:: @ 823F272
	compare_var_to_value VAR_0x40CE, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F29F
	compare_var_to_value VAR_0x40CE, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F2A5
	compare_var_to_value VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F2AB
	compare_var_to_value VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F2B1
	return

BattleFrontier_BattleTowerLobby_EventScript_23F29F:: @ 823F29F
	setvar VAR_0x8005, 3
	return

BattleFrontier_BattleTowerLobby_EventScript_23F2A5:: @ 823F2A5
	setvar VAR_0x8005, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_23F2AB:: @ 823F2AB
	setvar VAR_0x8005, 2
	return

BattleFrontier_BattleTowerLobby_EventScript_23F2B1:: @ 823F2B1
	setvar VAR_0x8005, 2
	return

BattleFrontier_BattleArenaLobby_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattleDomeLobby_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattleDomePreBattleRoom_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattlePalaceLobby_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattlePikeLobby_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattlePyramidLobby_EventScript_23F2B7:: @ 823F2B7
BattleFrontier_BattleTowerLobby_EventScript_23F2B7:: @ 823F2B7
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_81A1780
	return

BattleFrontier_BattleTowerLobby_EventScript_23F2C5:: @ 823F2C5
	setvar VAR_0x8004, 9
	message gUnknown_08278091
	waitmessage
	setvar VAR_0x8005, 0
	special sub_80B2DA4
	waitstate
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F3AF
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2772D2
	compare_var_to_value VAR_RESULT, 3
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F327
	compare_var_to_value VAR_RESULT, 4
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F351
	compare_var_to_value VAR_RESULT, 5
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	compare_var_to_value VAR_RESULT, 6
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2772C5
	compare_var_to_value VAR_RESULT, 11
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	end

BattleFrontier_BattleTowerLobby_EventScript_23F327:: @ 823F327
	special sub_80097E8
	compare_var_to_value VAR_0x8005, 3
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F33F
	msgbox BattleFrontier_BattleTowerLobby_Text_278255, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F33F:: @ 823F33F
	msgbox BattleFrontier_BattleTowerLobby_Text_2412E8, 4
	msgbox BattleFrontier_BattleTowerLobby_Text_2413DE, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F351:: @ 823F351
	msgbox BattleFrontier_BattleTowerLobby_Text_241240, 4
	special sub_80097E8
	msgbox BattleFrontier_BattleTowerLobby_Text_2782A8, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F366:: @ 823F366
	special sub_80097E8
	compare_var_to_value VAR_0x8005, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F394
	compare_var_to_value VAR_0x8005, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F39D
	compare_var_to_value VAR_0x8005, 2
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_23F3A6
	msgbox BattleFrontier_BattleTowerLobby_Text_2413DE, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F394:: @ 823F394
	msgbox BattleFrontier_BattleTowerLobby_Text_2412E8, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_23F39D:: @ 823F39D
	msgbox BattleFrontier_BattleTowerLobby_Text_241285, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_23F3A6:: @ 823F3A6
	msgbox BattleFrontier_BattleTowerLobby_Text_2412B3, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_23F3AF:: @ 823F3AF
	incrementgamestat 30
	setvar VAR_0x40BC, 0
	message BattleFrontier_BattleTowerLobby_Text_24144D
	waitmessage
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 1
	special sub_8161F74
	special sub_80A08CC
	waitstate
	playse SE_SAVE
	waitse
	special sub_80B3BC4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23F3DA:: @ 823F3DA
	msgbox BattleFrontier_BattleTowerLobby_Text_240ED2, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23ED86
	end

BattleFrontier_BattleTowerLobby_EventScript_23F3E8:: @ 823F3E8
	setvar VAR_0x8004, 20
	goto BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23F3F3:: @ 823F3F3
	message BattleFrontier_BattleTowerLobby_Text_2792CD
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F463
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F430
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	end

BattleFrontier_BattleTowerLobby_EventScript_23F430:: @ 823F430
	call BattleFrontier_BattleTowerLobby_EventScript_277B30
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F496
	compare_var_to_value VAR_RESULT, 5
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	compare_var_to_value VAR_RESULT, 8
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F430
	compare_var_to_value VAR_RESULT, 11
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_23F463:: @ 823F463
	call BattleFrontier_BattleTowerLobby_EventScript_277B35
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F496
	compare_var_to_value VAR_RESULT, 5
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	compare_var_to_value VAR_RESULT, 8
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F463
	compare_var_to_value VAR_RESULT, 11
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_23F496:: @ 823F496
	incrementgamestat 30
	setvar VAR_0x40BC, 0
	message BattleFrontier_BattleTowerLobby_Text_24144D
	waitmessage
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 1
	special sub_8161F74
	special sub_80A08CC
	waitstate
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23F4BE:: @ 823F4BE
	lockall
	msgbox BattleFrontier_BattleTowerLobby_Text_241540, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F4CD:: @ 823F4CD
	message BattleFrontier_BattleTowerLobby_Text_241563
	waitmessage
	multichoice 17, 2, 97, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F520
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F52E
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F53C
	case 3, BattleFrontier_BattleTowerLobby_EventScript_23F54A
	case 4, BattleFrontier_BattleTowerLobby_EventScript_23F558
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F558
	end

BattleFrontier_BattleTowerLobby_EventScript_23F520:: @ 823F520
	msgbox BattleFrontier_BattleTowerLobby_Text_241586, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F52E:: @ 823F52E
	msgbox BattleFrontier_BattleTowerLobby_Text_241693, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F53C:: @ 823F53C
	msgbox BattleFrontier_BattleTowerLobby_Text_241777, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F54A:: @ 823F54A
	msgbox BattleFrontier_BattleTowerLobby_Text_24187E, 4
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F558:: @ 823F558
	releaseall
	end

	.incbin "baserom.gba", 0x23f55a, 0x29

BattleFrontier_BattleTowerLobby_Text_23F583: @ 823F583
	.string "Excuse me!\p"
	.string "You didn’t save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleTowerLobby_Text_23F60D: @ 823F60D
	.string "Congratulations!\n"
	.string "You’ve beaten all seven TRAINERS!\p"
	.string "$"

	.incbin "baserom.gba", 0x23f641, 0x4b

