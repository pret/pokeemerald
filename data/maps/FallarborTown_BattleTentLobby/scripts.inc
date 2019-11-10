FallarborTown_BattleTentLobby_MapScripts:: @ 81FFE66
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentLobby_MapScript2_1FFE85
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentLobby_MapScript2_1FFE71
	.byte 0

FallarborTown_BattleTentLobby_MapScript2_1FFE71: @ 81FFE71
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentLobby_EventScript_1FFE7B
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_1FFE7B:: @ 81FFE7B
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

FallarborTown_BattleTentLobby_MapScript2_1FFE85: @ 81FFE85
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentLobby_EventScript_1FFEAF
	map_script_2 VAR_TEMP_0, 1, FallarborTown_BattleTentLobby_EventScript_1FFEB8
	map_script_2 VAR_TEMP_0, 2, FallarborTown_BattleTentLobby_EventScript_1FFFCD
	map_script_2 VAR_TEMP_0, 3, FallarborTown_BattleTentLobby_EventScript_1FFEED
	map_script_2 VAR_TEMP_0, 4, FallarborTown_BattleTentLobby_EventScript_1FFF93
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_1FFEAF:: @ 81FFEAF
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_0
	special CallFrontierUtilFunc
	end

FallarborTown_BattleTentLobby_EventScript_1FFEB8:: @ 81FFEB8
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4DED, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFEED:: @ 81FFEED
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4EC3, MSGBOX_DEFAULT
	message FallarborTown_BattleTentLobby_Text_2C4EFF
	waitmessage
	setvar VAR_0x8004, 4
	special sub_81B9B80
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special sub_81B9B80
	playse SE_SAVE
	waitse

FallarborTown_BattleTentLobby_EventScript_1FFF27:: @ 81FFF27
	msgbox FallarborTown_BattleTentLobby_Text_2C4F22, MSGBOX_DEFAULT
	setvar VAR_0x8004, 5
	special sub_81B9B80
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_1FFF73
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	message FallarborTown_BattleTentLobby_Text_2C4F69
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox FallarborTown_BattleTentLobby_Text_2C501F, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFF73:: @ 81FFF73
	msgbox FallarborTown_BattleTentLobby_Text_2C4F83, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFF84:: @ 81FFF84
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4EC3, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_1FFF27
	end

FallarborTown_BattleTentLobby_EventScript_1FFF93:: @ 81FFF93
	lockall
	message FallarborTown_BattleTentLobby_Text_2C4FD7
	waitmessage
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special sub_81B9B80
	playse SE_SAVE
	waitse
	msgbox FallarborTown_BattleTentLobby_Text_2C501F, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFFCD:: @ 81FFFCD
	lockall
	message FallarborTown_BattleTentLobby_Text_2C504C
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special sub_81B9B80
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	goto FallarborTown_BattleTentLobby_EventScript_20013C

FallarborTown_BattleTentLobby_EventScript_200001:: @ 8200001
	lock
	faceplayer
	setvar VAR_0x8004, 1
	special sub_81B9B80
	compare VAR_RESULT, 0
	goto_if_ne FallarborTown_BattleTentLobby_EventScript_1FFF84
	special SavePlayerParty
	msgbox FallarborTown_BattleTentLobby_Text_2C47EB, MSGBOX_DEFAULT

FallarborTown_BattleTentLobby_EventScript_200021:: @ 8200021
	message FallarborTown_BattleTentLobby_Text_2C4843
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_20005D
	case 1, FallarborTown_BattleTentLobby_EventScript_200169
	case 2, FallarborTown_BattleTentLobby_EventScript_2001C5
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_2001C5

FallarborTown_BattleTentLobby_EventScript_20005D:: @ 820005D
	setvar VAR_FRONTIER_FACILITY, 3
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	setvar VAR_RESULT, 2
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_200176
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 2
	special CallFrontierUtilFunc
	msgbox FallarborTown_BattleTentLobby_Text_2C4BC8, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_2001C2
	msgbox FallarborTown_BattleTentLobby_Text_2C4B35, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_BattleTentLobby_EventScript_2001C2
	case YES, FallarborTown_BattleTentLobby_EventScript_2000E2
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_2001C2

FallarborTown_BattleTentLobby_EventScript_2000E2:: @ 82000E2
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 0
	special sub_81B9B80
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_2001AB

FallarborTown_BattleTentLobby_EventScript_20013C:: @ 820013C
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_LOAD_SELECTED_PARTY
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	msgbox FallarborTown_BattleTentLobby_Text_2C4DC3, MSGBOX_DEFAULT
	closemessage
	call FallarborTown_BattleTentLobby_EventScript_2001CF
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

FallarborTown_BattleTentLobby_EventScript_200169:: @ 8200169
	msgbox FallarborTown_BattleTentLobby_Text_2C48AC, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_200021

FallarborTown_BattleTentLobby_EventScript_200176:: @ 8200176
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_200191
	case 1, FallarborTown_BattleTentLobby_EventScript_20019E

FallarborTown_BattleTentLobby_EventScript_200191:: @ 8200191
	msgbox FallarborTown_BattleTentLobby_Text_2C4BFA, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_2001CD

FallarborTown_BattleTentLobby_EventScript_20019E:: @ 820019E
	msgbox FallarborTown_BattleTentLobby_Text_2C4CC0, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_2001CD

FallarborTown_BattleTentLobby_EventScript_2001AB:: @ 82001AB
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto FallarborTown_BattleTentLobby_EventScript_2001C5

FallarborTown_BattleTentLobby_EventScript_2001C2:: @ 82001C2
	special LoadPlayerParty

FallarborTown_BattleTentLobby_EventScript_2001C5:: @ 82001C5
	msgbox FallarborTown_BattleTentLobby_Text_2C487F, MSGBOX_DEFAULT

FallarborTown_BattleTentLobby_EventScript_2001CD:: @ 82001CD
	release
	end

FallarborTown_BattleTentLobby_EventScript_2001CF:: @ 82001CF
	applymovement 1, FallarborTown_BattleTentLobby_Movement_2001FE
	applymovement EVENT_OBJ_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_200205
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement 1, FallarborTown_BattleTentLobby_Movement_200202
	applymovement EVENT_OBJ_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_200209
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

FallarborTown_BattleTentLobby_Movement_2001FE: @ 82001FE
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_200202: @ 8200202
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_Movement_200205: @ 8200205
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_200209: @ 8200209
	walk_up
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_EventScript_20020D:: @ 820020D
	msgbox FallarborTown_BattleTentLobby_Text_20045A, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_200216:: @ 8200216
	msgbox FallarborTown_BattleTentLobby_Text_200304, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_20021F:: @ 820021F
	msgbox FallarborTown_BattleTentLobby_Text_200382, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_200228:: @ 8200228
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_FALLARBOR, FallarborTown_BattleTentLobby_EventScript_200245
	msgbox FallarborTown_BattleTentLobby_Text_200501, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_FALLARBOR
	release
	end

FallarborTown_BattleTentLobby_EventScript_200245:: @ 8200245
	msgbox FallarborTown_BattleTentLobby_Text_200653, MSGBOX_DEFAULT
	release
	end

FallarborTown_BattleTentLobby_EventScript_20024F:: @ 820024F
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_256DB8, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_20025E:: @ 820025E
	message FallarborTown_BattleTentLobby_Text_256DDF
	waitmessage
	multichoice 17, 0, MULTI_FALLARBOR_TENT_RULES, 0
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_2002BC
	case 1, FallarborTown_BattleTentLobby_EventScript_2002CA
	case 2, FallarborTown_BattleTentLobby_EventScript_2002D8
	case 3, FallarborTown_BattleTentLobby_EventScript_2002E6
	case 4, FallarborTown_BattleTentLobby_EventScript_2002F4
	case 5, FallarborTown_BattleTentLobby_EventScript_200302
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_200302
	end

FallarborTown_BattleTentLobby_EventScript_2002BC:: @ 82002BC
	msgbox FallarborTown_BattleTentLobby_Text_2C67CD, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002CA:: @ 82002CA
	msgbox FallarborTown_BattleTentLobby_Text_256E02, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002D8:: @ 82002D8
	msgbox FallarborTown_BattleTentLobby_Text_256F43, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002E6:: @ 82002E6
	msgbox FallarborTown_BattleTentLobby_Text_256FF2, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002F4:: @ 82002F4
	msgbox FallarborTown_BattleTentLobby_Text_257202, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_200302:: @ 8200302
	releaseall
	end

FallarborTown_BattleTentLobby_Text_200304: @ 8200304
	.string "Fufufufufu.\p"
	.string "I'm going to make everyone think\n"
	.string "I'm just a kid and let them play down.\p"
	.string "Then, I'll shock them and grab\n"
	.string "the title!$"

FallarborTown_BattleTentLobby_Text_200382: @ 8200382
	.string "You know how BATTLE TENTS offer\n"
	.string "different events in different towns?\p"
	.string "My favorite is definitely the BATTLE\n"
	.string "TENT in FALLARBOR TOWN.\p"
	.string "I think it's fantastic how TRAINERS\n"
	.string "try to win with all their faith in\l"
	.string "their POKéMON.$"

FallarborTown_BattleTentLobby_Text_20045A: @ 820045A
	.string "I heard something about some tent,\n"
	.string "so I came to camp out.\p"
	.string "I didn't know that tents these days\n"
	.string "are so luxurious!\p"
	.string "Since I'm here, I may as well try\n"
	.string "my hand at battling!$"

FallarborTown_BattleTentLobby_Text_200501: @ 8200501
	.string "SCOTT: Hi, {PLAYER}{KUN}!\n"
	.string "So you came out to this BATTLE TENT!\p"
	.string "The people in these parts tend to be\n"
	.string "easygoing and laid-back.\p"
	.string "But, you see, what I'm looking for are\n"
	.string "people with…\p"
	.string "How should I say this?\p"
	.string "Someone bursting with the desire\n"
	.string "and the drive to win.\p"
	.string "If there were a TRAINER like that,\n"
	.string "I'd immediately…\p"
	.string "Whoops! Never mind!\n"
	.string "Keep working at it!$"

FallarborTown_BattleTentLobby_Text_200653: @ 8200653
	.string "SCOTT: Instead of wasting your\n"
	.string "time with the likes of me, why not\l"
	.string "make a challenge?$"

