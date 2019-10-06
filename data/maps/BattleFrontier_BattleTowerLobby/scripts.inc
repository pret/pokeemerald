BattleFrontier_BattleTowerLobby_MapScripts:: @ 823E67B
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_MapScript1_23E690
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_MapScript1_23E694
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_MapScript2_23E6DD
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_MapScript2_23E6C9
	.byte 0

BattleFrontier_BattleTowerLobby_MapScript1_23E690: @ 823E690
	special sub_81653CC
	end

BattleFrontier_BattleTowerLobby_MapScript1_23E694: @ 823E694
	call BattleFrontier_BattleTowerLobby_EventScript_28CC84
	setvar VAR_0x8004, 10
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E6B5
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_23E6C1

BattleFrontier_BattleTowerLobby_EventScript_23E6B5:: @ 823E6B5
	clearflag FLAG_HIDE_APPRENTICE
	setvar VAR_0x8004, 23
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_23E6C0:: @ 823E6C0
	end

BattleFrontier_BattleTowerLobby_EventScript_23E6C1:: @ 823E6C1
	setflag FLAG_HIDE_APPRENTICE
	goto BattleFrontier_BattleTowerLobby_EventScript_23E6C0

BattleFrontier_BattleTowerLobby_MapScript2_23E6C9: @ 823E6C9
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_23E6D3
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_23E6D3:: @ 823E6D3
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerLobby_MapScript2_23E6DD: @ 823E6DD
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerLobby_EventScript_23E707
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleTowerLobby_EventScript_23E710
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleTowerLobby_EventScript_23E8EE
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleTowerLobby_EventScript_23E758
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleTowerLobby_EventScript_23E7F2
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_23E707:: @ 823E707
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerLobby_EventScript_23E710:: @ 823E710
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_23F583, MSGBOX_DEFAULT
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
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E758:: @ 823E758
	lock
	faceplayer
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E778
	message BattleFrontier_BattleTowerLobby_Text_23F60D
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_23E780

BattleFrontier_BattleTowerLobby_EventScript_23E778:: @ 823E778
	msgbox BattleFrontier_BattleTowerLobby_Text_241486, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23E780:: @ 823E780
	setvar VAR_0x8004, 5
	special sub_8161F74
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E7A5
	message BattleFrontier_BattleTowerLobby_Text_23F844
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox BattleFrontier_BattleTowerLobby_Text_23F89F, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23E7A5:: @ 823E7A5
	msgbox BattleFrontier_BattleTowerLobby_Text_2414D4, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleTowerLobby_Text_241520, 9
	call BattleFrontier_BattleTowerLobby_EventScript_23E84D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 49
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_23E7E2
	msgbox BattleFrontier_BattleTowerLobby_Text_23F79D, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23E7E2:: @ 823E7E2
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E7F2:: @ 823E7F2
	compare VAR_FRONTIER_BATTLE_MODE, 2
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_23E81E
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_23E81E
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_23E830

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
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23E84D:: @ 823E84D
	message BattleFrontier_BattleTowerLobby_Text_23F70F
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 0
	special sub_8161F74
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleTowerLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E8DF
	message BattleFrontier_BattleTowerLobby_Text_23FE3C
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23E8DF
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23E8B4
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23E8DF

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
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E8D7
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_2423CD, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23E8DF

BattleFrontier_BattleTowerLobby_EventScript_23E8D7:: @ 823E8D7
	msgbox gText_BattleRecordCouldntBeSaved, MSGBOX_DEFAULT

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
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_23E8EE:: @ 823E8EE
	lock
	faceplayer
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23E930
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
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23E930:: @ 823E930
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_23E936:: @ 823E936
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_240537, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23E948:: @ 823E948
	message BattleFrontier_BattleTowerLobby_Text_2405B3
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23E984
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EA91
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23E984:: @ 823E984
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleTowerLobby_Text_2407A6, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EA2A
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EA2A:: @ 823EA2A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 1
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23EA91:: @ 823EA91
	msgbox BattleFrontier_BattleTowerLobby_Text_2405EC, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23E948
	end

BattleFrontier_BattleTowerLobby_EventScript_23EA9F:: @ 823EA9F
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_2407E2, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23EAB1:: @ 823EAB1
	message BattleFrontier_BattleTowerLobby_Text_24085E
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EAED
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EBFA
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EAED:: @ 823EAED
	setvar VAR_FRONTIER_BATTLE_MODE, 1
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleTowerLobby_Text_240A50, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 4
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EB93
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EB93:: @ 823EB93
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23EBFA:: @ 823EBFA
	msgbox BattleFrontier_BattleTowerLobby_Text_240897, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23EAB1
	end

BattleFrontier_BattleTowerLobby_EventScript_23EC08:: @ 823EC08
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_240A8B, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23EC1D:: @ 823EC1D
	message BattleFrontier_BattleTowerLobby_Text_240B06
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EC59
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23ED66
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EC59:: @ 823EC59
	setvar VAR_FRONTIER_BATTLE_MODE, 2
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleTowerLobby_Text_240DDB, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 2
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23ECFF
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23ECFF:: @ 823ECFF
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23ED66:: @ 823ED66
	msgbox BattleFrontier_BattleTowerLobby_Text_240B3E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23EC1D
	end

BattleFrontier_BattleTowerLobby_EventScript_23ED74:: @ 823ED74
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_240E15, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23ED86:: @ 823ED86
	message BattleFrontier_BattleTowerLobby_Text_240E95
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EDC2
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F3DA
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6

BattleFrontier_BattleTowerLobby_EventScript_23EDC2:: @ 823EDC2
	setvar VAR_FRONTIER_BATTLE_MODE, 3
	message BattleFrontier_BattleTowerLobby_Text_23FD3B
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F02B
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleTowerLobby_Text_24115E, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleTowerLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 2
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	msgbox BattleFrontier_BattleTowerLobby_Text_23FDC7, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0E3
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EE68
	case 127, BattleFrontier_BattleTowerLobby_EventScript_23F0E3

BattleFrontier_BattleTowerLobby_EventScript_23EE68:: @ 823EE68
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special sub_8161F74
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 0
	special sub_8161F74
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0D0
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F3E8
	goto BattleFrontier_BattleTowerLobby_EventScript_23F2C5
	end

BattleFrontier_BattleTowerLobby_EventScript_23EEE7:: @ 823EEE7
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_23F8CD
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_TOWER_FEELINGS, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23EF32
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23EF4C
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23EF66
	case 3, BattleFrontier_BattleTowerLobby_EventScript_23EF80
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23EF80
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF32:: @ 823EF32
	msgbox BattleFrontier_BattleTowerLobby_Text_23F969, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_START
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF4C:: @ 823EF4C
	msgbox BattleFrontier_BattleTowerLobby_Text_23F9AA, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_WON
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF66:: @ 823EF66
	msgbox BattleFrontier_BattleTowerLobby_Text_23F9D4, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_LOST
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_23EF8A
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF80:: @ 823EF80
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA0F, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EF8A:: @ 823EF8A
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23EFA1
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23EFAB
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFA1:: @ 823EFA1
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA4F, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFAB:: @ 823EFAB
	msgbox BattleFrontier_BattleTowerLobby_Text_23FA83, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFB5:: @ 823EFB5
	msgbox BattleFrontier_BattleTowerLobby_Text_23FAC0, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFBE:: @ 823EFBE
	msgbox BattleFrontier_BattleTowerLobby_Text_23FB26, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFC7:: @ 823EFC7
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFE0:: @ 823EFE0
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23EFF9:: @ 823EFF9
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23F012:: @ 823F012
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23F02B:: @ 823F02B
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F046
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F08B

BattleFrontier_BattleTowerLobby_EventScript_23F046:: @ 823F046
	switch VAR_FRONTIER_BATTLE_MODE
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F06F
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F07D
	msgbox BattleFrontier_BattleTowerLobby_Text_24038B, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F06F:: @ 823F06F
	msgbox BattleFrontier_BattleTowerLobby_Text_240027, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F07D:: @ 823F07D
	msgbox BattleFrontier_BattleTowerLobby_Text_2401DB, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F08B:: @ 823F08B
	switch VAR_FRONTIER_BATTLE_MODE
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F0B4
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F0C2
	msgbox BattleFrontier_BattleTowerLobby_Text_24046B, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0B4:: @ 823F0B4
	msgbox BattleFrontier_BattleTowerLobby_Text_24010B, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0C2:: @ 823F0C2
	msgbox BattleFrontier_BattleTowerLobby_Text_2402BD, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0F1
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0D0:: @ 823F0D0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0E3:: @ 823F0E3
	special LoadPlayerParty

BattleFrontier_BattleTowerLobby_EventScript_23F0E6:: @ 823F0E6
	special CloseLink
	msgbox BattleFrontier_BattleTowerLobby_Text_23FD07, MSGBOX_DEFAULT

BattleFrontier_BattleTowerLobby_EventScript_23F0F1:: @ 823F0F1
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F0F3:: @ 823F0F3
	special SavePlayerParty
	setvar VAR_0x8004, 3
	call BattleFrontier_BattleTowerLobby_EventScript_23F272
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0

BattleFrontier_BattleTowerLobby_EventScript_23F108:: @ 823F108
	setvar VAR_0x8004, 12
	special sub_8161F74
	delay 1
	compare VAR_RESULT, 6
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_23F108
	call BattleFrontier_BattleTowerLobby_EventScript_23F135
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_23F135:: @ 823F135
	call BattleFrontier_BattleTowerLobby_EventScript_23F1A7
	compare VAR_FRONTIER_BATTLE_MODE, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F152
	msgbox BattleFrontier_BattleTowerLobby_Text_23FE11, MSGBOX_DEFAULT
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
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_23F195
	waitmovement 0
	opendoor VAR_0x8004, 1
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_23F199
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_23F19C
	waitmovement 0
	closedoor VAR_0x8004, 1
	waitdooranim
	return

BattleFrontier_BattleTowerLobby_Movement_23F195: @ 823F195
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_23F199: @ 823F199
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_23F19C: @ 823F19C
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_23F1A0: @ 823F1A0
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_EventScript_23F1A7:: @ 823F1A7
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F1D4
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F1D9
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F1DE
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F1E3
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1D4:: @ 823F1D4
	bufferstdstring 0, STDSTRING_SINGLE
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1D9:: @ 823F1D9
	bufferstdstring 0, STDSTRING_DOUBLE
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1DE:: @ 823F1DE
	bufferstdstring 0, STDSTRING_MULTI
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1E3:: @ 823F1E3
	bufferstdstring 0, STDSTRING_MULTI_LINK
	return

BattleFrontier_BattleTowerLobby_EventScript_23F1E8:: @ 823F1E8
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F215
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F21B
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F221
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F227
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
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F25A
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F260
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F266
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F26C
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
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F29F
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F2A5
	compare VAR_FRONTIER_BATTLE_MODE, 2
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F2AB
	compare VAR_FRONTIER_BATTLE_MODE, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F2B1
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
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_23F2C5:: @ 823F2C5
	setvar VAR_0x8004, 9
	message gText_PleaseWaitForLink
	waitmessage
	setvar VAR_0x8005, 0
	special sub_80B2DA4
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F3AF
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2772D2
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F327
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F351
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	compare VAR_RESULT, 6
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2772C5
	compare VAR_RESULT, 11
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	end

BattleFrontier_BattleTowerLobby_EventScript_23F327:: @ 823F327
	special CloseLink
	compare VAR_0x8005, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F33F
	msgbox BattleFrontier_BattleTowerLobby_Text_278255, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F33F:: @ 823F33F
	msgbox BattleFrontier_BattleTowerLobby_Text_2412E8, MSGBOX_DEFAULT
	msgbox BattleFrontier_BattleTowerLobby_Text_2413DE, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F351:: @ 823F351
	msgbox BattleFrontier_BattleTowerLobby_Text_241240, MSGBOX_DEFAULT
	special CloseLink
	msgbox BattleFrontier_BattleTowerLobby_Text_2782A8, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F366:: @ 823F366
	special CloseLink
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F394
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F39D
	compare VAR_0x8005, 2
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F3A6
	msgbox BattleFrontier_BattleTowerLobby_Text_2413DE, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_23F394:: @ 823F394
	msgbox BattleFrontier_BattleTowerLobby_Text_2412E8, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_23F39D:: @ 823F39D
	msgbox BattleFrontier_BattleTowerLobby_Text_241285, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_23F3A6:: @ 823F3A6
	msgbox BattleFrontier_BattleTowerLobby_Text_2412B3, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_23F3AF:: @ 823F3AF
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
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
	msgbox BattleFrontier_BattleTowerLobby_Text_240ED2, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23ED86
	end

BattleFrontier_BattleTowerLobby_EventScript_23F3E8:: @ 823F3E8
	setvar VAR_0x8004, 20
	goto BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	end

BattleFrontier_BattleTowerLobby_EventScript_23F3F3:: @ 823F3F3
	message BattleFrontier_BattleTowerLobby_Text_2792CD
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F463
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F430
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F0E6
	end

BattleFrontier_BattleTowerLobby_EventScript_23F430:: @ 823F430
	call BattleFrontier_BattleTowerLobby_EventScript_277B30
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F496
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	compare VAR_RESULT, 8
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F430
	compare VAR_RESULT, 11
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_23F463:: @ 823F463
	call BattleFrontier_BattleTowerLobby_EventScript_277B35
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F496
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F3F3
	compare VAR_RESULT, 8
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F463
	compare VAR_RESULT, 11
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_23F366
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_23F496:: @ 823F496
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
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
	msgbox BattleFrontier_BattleTowerLobby_Text_241540, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F4CD:: @ 823F4CD
	message BattleFrontier_BattleTowerLobby_Text_241563
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_23F520
	case 1, BattleFrontier_BattleTowerLobby_EventScript_23F52E
	case 2, BattleFrontier_BattleTowerLobby_EventScript_23F53C
	case 3, BattleFrontier_BattleTowerLobby_EventScript_23F54A
	case 4, BattleFrontier_BattleTowerLobby_EventScript_23F558
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_23F558
	end

BattleFrontier_BattleTowerLobby_EventScript_23F520:: @ 823F520
	msgbox BattleFrontier_BattleTowerLobby_Text_241586, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F52E:: @ 823F52E
	msgbox BattleFrontier_BattleTowerLobby_Text_241693, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F53C:: @ 823F53C
	msgbox BattleFrontier_BattleTowerLobby_Text_241777, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F54A:: @ 823F54A
	msgbox BattleFrontier_BattleTowerLobby_Text_24187E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_23F4CD
	end

BattleFrontier_BattleTowerLobby_EventScript_23F558:: @ 823F558
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_23F55A: @ 823F55A
	.string "I'll direct you to your BATTLE ROOM now.$"

BattleFrontier_BattleTowerLobby_Text_23F583: @ 823F583
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleTowerLobby_Text_23F60D: @ 823F60D
	.string "Congratulations!\n"
	.string "You've beaten all seven TRAINERS!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_23F641: @ 823F641
	.string "For beating seven TRAINERS in a row,\n"
	.string "you have earned this fabulous prize!\p"
	.string "$"

SlateportCity_BattleTentLobby_Text_23F68C: @ 823F68C
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

SlateportCity_BattleTentLobby_Text_23F6A6: @ 823F6A6
	.string "Oh, your BAG appears to be full.\p"
	.string "Please make room in your BAG, then come\n"
	.string "see me.$"

BattleFrontier_BattleTowerLobby_Text_23F6F7: @ 823F6F7
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_23F70F: @ 823F70F
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerLobby_Text_23F737: @ 823F737
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_23F754: @ 823F754
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_23F79D: @ 823F79D
	.string "You're finally about to face the\n"
	.string "50th TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleFrontier_BattleTowerLobby_Text_23F844: @ 823F844
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleTowerLobby_Text_23F89F: @ 823F89F
	.string "{PLAYER} put the RIBBONS on\n"
	.string "the challenger POKéMON.$"

BattleFrontier_BattleTowerLobby_Text_23F8CD: @ 823F8CD
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE TOWER\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleFrontier_BattleTowerLobby_Text_23F969: @ 823F969
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleFrontier_BattleTowerLobby_Text_23F9AA: @ 823F9AA
	.string "What do you feel when you've won\n"
	.string "a match?$"

BattleFrontier_BattleTowerLobby_Text_23F9D4: @ 823F9D4
	.string "Can I hear about your feelings when\n"
	.string "you have lost a match?$"

BattleFrontier_BattleTowerLobby_Text_23FA0F: @ 823FA0F
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleFrontier_BattleTowerLobby_Text_23FA4F: @ 823FA4F
	.string "Hunh? You changed your mind?\n"
	.string "I guess you're fickle.$"

BattleFrontier_BattleTowerLobby_Text_23FA83: @ 823FA83
	.string "Okay, so that's how you feel?\n"
	.string "That's quite original.\p"
	.string "Thanks!$"

BattleFrontier_BattleTowerLobby_Text_23FAC0: @ 823FAC0
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleTowerLobby_Text_23FB26: @ 823FB26
	.string "Once you've entered the BATTLE TOWER,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

BattleFrontier_BattleTowerLobby_Text_23FBCE: @ 823FBCE
	.string "Welcome to the BATTLE TOWER\n"
	.string "DOUBLE BATTLE CORNER!\p"
	.string "Unfortunately, the BATTLE ROOMS\n"
	.string "are still under construction.\p"
	.string "Please come back when the work\n"
	.string "is completed.$"

BattleFrontier_BattleTowerLobby_Text_23FC6B: @ 823FC6B
	.string "Welcome to the BATTLE TOWER\n"
	.string "MULTI BATTLE CORNER!\p"
	.string "Unfortunately, the BATTLE ROOMS\n"
	.string "are still under construction.\p"
	.string "Please come back when the work\n"
	.string "is completed.$"

BattleFrontier_BattleTowerLobby_Text_23FD07: @ 823FD07
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleTowerLobby_Text_23FD3B: @ 823FD3B
	.string "The BATTLE ROOM offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleTowerLobby_Text_23FD9A: @ 823FD9A
	.string "Please select the POKéMON you wish\n"
	.string "to enter.$"

BattleFrontier_BattleTowerLobby_Text_23FDC7: @ 823FDC7
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleTowerLobby_Text_23FE11: @ 823FE11
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleTowerLobby_Text_23FE3C: @ 823FE3C
	.string "Shall I record your last BATTLE TOWER\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattleTowerLobby_Text_23FE7F: @ 823FE7F
	.string "Excuse me!\p"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
	.string "You must have {STR_VAR_2} different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_23FF5D: @ 823FF5D
	.string "Excuse me!\p"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
	.string "You must have {STR_VAR_2} different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_240027: @ 8240027
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_24010B: @ 824010B
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_2401DB: @ 82401DB
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_2402BD: @ 82402BD
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_24038B: @ 824038B
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_24046B: @ 824046B
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_240537: @ 8240537
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the SINGLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_2405B3: @ 82405B3
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_2405EC: @ 82405EC
	.string "The BATTLE TOWER's SINGLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "SINGLE BATTLES with three POKéMON.\p"
	.string "There are many SINGLE BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_2407A6: @ 82407A6
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_2407E2: @ 82407E2
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the DOUBLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_24085E: @ 824085E
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_240897: @ 8240897
	.string "The BATTLE TOWER's DOUBLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "DOUBLE BATTLES with four POKéMON.\p"
	.string "There are many DOUBLE BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In each of the DOUBLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_240A50: @ 8240A50
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_240A8B: @ 8240A8B
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_240B06: @ 8240B06
	.string "Would you like to take the MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_240B3E: @ 8240B3E
	.string "The BATTLE TOWER's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES.\p"
	.string "For MULTI BATTLES, you must partner\n"
	.string "with a TRAINER in the TOWER and enter\l"
	.string "with two POKéMON each.\p"
	.string "Inside the TOWER is a room named\n"
	.string "the BATTLE SALON where you may meet\l"
	.string "other TRAINERS.\p"
	.string "There, you must find a TRAINER to act\n"
	.string "as your partner in MULTI BATTLES.\p"
	.string "Once you have partnered up, you will\n"
	.string "be shown to a MULTI BATTLE ROOM.\p"
	.string "In the MULTI BATTLE ROOM, seven\n"
	.string "tag teams await your challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_240DDB: @ 8240DDB
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_240E15: @ 8240E15
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_240E95: @ 8240E95
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_240ED2: @ 8240ED2
	.string "The BATTLE TOWER's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES with a friend.\p"
	.string "You must link with your friend using\n"
	.string "Wireless Adapters or a Game Boy\l"
	.string "Advance Game Link cable.\p"
	.string "You must partner with your friend and\n"
	.string "enter two different kinds of POKéMON.\p"
	.string "There are many MULTI BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In a MULTI BATTLE ROOM, seven\n"
	.string "tag teams await you and your friend\l"
	.string "to make a tag-team challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "Please beware that unlike other ROOMS,\n"
	.string "you may not interrupt your challenge.\p"
	.string "Once you start, you must battle seven\n"
	.string "MULTI BATTLES in a row nonstop.$"

BattleFrontier_BattleTowerLobby_Text_24115E: @ 824115E
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_241198: @ 8241198
	.string "You have chosen the same kind of\n"
	.string "POKéMON as your friend.\p"
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleTowerLobby_Text_241240: @ 8241240
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleFrontier_BattleTowerLobby_Text_241285: @ 8241285
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_2412B3: @ 82412B3
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"

BattleFrontier_BattleTowerLobby_Text_2412E8: @ 82412E8
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

BattleFrontier_BattleTowerLobby_Text_241319: @ 8241319
	.string "Your friend has chosen a different\n"
	.string "battle level.\p"
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_241378: @ 8241378
	.string "Your friend has chosen a different\n"
	.string "battle level.\p"
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"

BattleFrontier_BattleTowerLobby_Text_2413DE: @ 82413DE
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleTowerLobby_Text_24144D: @ 824144D
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_241486: @ 8241486
	.string "Congratulations!\n"
	.string "You have defeated the SALON MAIDEN\l"
	.string "and swept seven TRAINERS!$"

BattleFrontier_BattleTowerLobby_Text_2414D4: @ 82414D4
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleArenaLobby_Text_241520: @ 8241520
BattleFrontier_BattleDomeLobby_Text_241520: @ 8241520
BattleFrontier_BattleFactoryLobby_Text_241520: @ 8241520
BattleFrontier_BattlePalaceLobby_Text_241520: @ 8241520
BattleFrontier_BattlePikeLobby_Text_241520: @ 8241520
BattleFrontier_BattlePyramidLobby_Text_241520: @ 8241520
BattleFrontier_BattleTowerLobby_Text_241520: @ 8241520
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleFrontier_BattleTowerLobby_Text_241540: @ 8241540
	.string "The BATTLE TOWER rules are listed.$"

BattleFrontier_BattleTowerLobby_Text_241563: @ 8241563
	.string "Which heading do you want to read?$"

BattleFrontier_BattleTowerLobby_Text_241586: @ 8241586
	.string "The BATTLE TOWER is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
	.string "For each of these types, there are\n"
	.string "separate BATTLE ROOMS.\p"
	.string "Please speak with a guide offering\n"
	.string "the type of battle you wish to enter.$"

BattleFrontier_BattleTowerLobby_Text_241693: @ 8241693
	.string "Depending on the BATTLE ROOM you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of POKéMON.\p"
	.string "The SINGLE BATTLE mode requires\n"
	.string "three POKéMON.\p"
	.string "The DOUBLE BATTLE mode requires four,\n"
	.string "and the MULTI modes both require two.$"

BattleFrontier_BattleTowerLobby_Text_241777: @ 8241777
	.string "The BATTLE SALON is where you must\n"
	.string "find a partner to form a tag team for\l"
	.string "the MULTI BATTLE ROOM challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other TRAINERS'\l"
	.string "POKéMON and their moves.\p"
	.string "You may choose a new tag partner\n"
	.string "after winning seven straight matches.$"

BattleFrontier_BattleTowerLobby_Text_24187E: @ 824187E
	.string "The LINK MULTI BATTLE Mode is for two\n"
	.string "friends to mount a challenge together.\p"
	.string "You and your friend must be linked with\n"
	.string "Wireless Adapters or a GBA Game Link\l"
	.string "cable.\p"
	.string "You must choose two POKéMON at\n"
	.string "the registration counter.\p"
	.string "These POKéMON must be different\n"
	.string "from those of your friend.\p"
	.string "You may not interrupt this challenge\n"
	.string "in the middle, unlike other modes.$"
