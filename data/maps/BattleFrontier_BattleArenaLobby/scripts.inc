BattleFrontier_BattleArenaLobby_MapScripts:: @ 8255C36
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_MapScript2_255C55
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_MapScript2_255C41
	.byte 0

BattleFrontier_BattleArenaLobby_MapScript2_255C41: @ 8255C41
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_255C4B
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_255C4B:: @ 8255C4B
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_MapScript2_255C55: @ 8255C55
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaLobby_EventScript_255C7F
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleArenaLobby_EventScript_255C88
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleArenaLobby_EventScript_255DC0
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleArenaLobby_EventScript_255CCF
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleArenaLobby_EventScript_255D2B
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_255C7F:: @ 8255C7F
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaLobby_EventScript_255C88:: @ 8255C88
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_256811, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255CCF:: @ 8255CCF
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255CF0
	msgbox BattleFrontier_BattleArenaLobby_Text_2568E7, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_255CF8

BattleFrontier_BattleArenaLobby_EventScript_255CF0:: @ 8255CF0
	msgbox BattleFrontier_BattleArenaLobby_Text_2572D9, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_255CF8:: @ 8255CF8
	msgbox BattleFrontier_BattleArenaLobby_Text_257353, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_241520, 9
	message BattleFrontier_BattleArenaLobby_Text_256931
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_255D59
	msgbox BattleFrontier_BattleArenaLobby_Text_256A74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255D2B:: @ 8255D2B
	lockall
	message BattleFrontier_BattleArenaLobby_Text_256A2C
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	call BattleFrontier_BattleArenaLobby_EventScript_255D59
	msgbox BattleFrontier_BattleArenaLobby_Text_256A74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255D59:: @ 8255D59
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleArenaLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255DBF
	message BattleFrontier_BattleArenaLobby_Text_256B19
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255DBF
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255DBA
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255DBF

BattleFrontier_BattleArenaLobby_EventScript_255DBA:: @ 8255DBA
	call BattleFrontier_BattleArenaLobby_EventScript_23E8B4

BattleFrontier_BattleArenaLobby_EventScript_255DBF:: @ 8255DBF
	return

BattleFrontier_BattleArenaLobby_EventScript_255DC0:: @ 8255DC0
	lockall
	message BattleFrontier_BattleArenaLobby_Text_256AA1
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_255F54

BattleFrontier_BattleArenaLobby_EventScript_255DF4:: @ 8255DF4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 3
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_256166, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_255E0B:: @ 8255E0B
	message BattleFrontier_BattleArenaLobby_Text_2561EA
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255E47
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255F9F
	case 2, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255FFB

BattleFrontier_BattleArenaLobby_EventScript_255E47:: @ 8255E47
	message BattleFrontier_BattleArenaLobby_Text_256513
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FAC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_256573, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleArenaLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FF8
	msgbox BattleFrontier_BattleArenaLobby_Text_2564CE, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255FF8
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255EE8
	case 127, BattleFrontier_BattleArenaLobby_EventScript_255FF8

BattleFrontier_BattleArenaLobby_EventScript_255EE8:: @ 8255EE8
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
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
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FE1

BattleFrontier_BattleArenaLobby_EventScript_255F54:: @ 8255F54
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_2567E6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleArenaLobby_EventScript_256005
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleArenaLobby_EventScript_256050
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 255, 9, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_255F9F:: @ 8255F9F
	msgbox BattleFrontier_BattleArenaLobby_Text_25624C, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_255E0B

BattleFrontier_BattleArenaLobby_EventScript_255FAC:: @ 8255FAC
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255FC7
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255FD4

BattleFrontier_BattleArenaLobby_EventScript_255FC7:: @ 8255FC7
	msgbox BattleFrontier_BattleArenaLobby_Text_2566A8, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_256003

BattleFrontier_BattleArenaLobby_EventScript_255FD4:: @ 8255FD4
	msgbox BattleFrontier_BattleArenaLobby_Text_2565A5, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_256003

BattleFrontier_BattleArenaLobby_EventScript_255FE1:: @ 8255FE1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaLobby_EventScript_255FFB

BattleFrontier_BattleArenaLobby_EventScript_255FF8:: @ 8255FF8
	special LoadPlayerParty

BattleFrontier_BattleArenaLobby_EventScript_255FFB:: @ 8255FFB
	msgbox BattleFrontier_BattleArenaLobby_Text_25621F, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_256003:: @ 8256003
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_256005:: @ 8256005
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_256034
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_256041
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25603E
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_25604C
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_256034: @ 8256034
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_25603E: @ 825603E
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_256041: @ 8256041
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_25604C: @ 825604C
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_256050:: @ 8256050
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25607F
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_256088
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25603E
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_25604C
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_25607F: @ 825607F
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_256088: @ 8256088
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_256092:: @ 8256092
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_2560A6:: @ 82560A6
	msgbox BattleFrontier_BattleArenaLobby_Text_256B5C, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560AF:: @ 82560AF
	msgbox BattleFrontier_BattleArenaLobby_Text_256BCB, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560B8:: @ 82560B8
	msgbox BattleFrontier_BattleArenaLobby_Text_256C19, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560C1:: @ 82560C1
	msgbox BattleFrontier_BattleArenaLobby_Text_256C9A, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560CA:: @ 82560CA
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_256DB8, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_2560D9:: @ 82560D9
	message BattleFrontier_BattleArenaLobby_Text_256DDF
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_25612C
	case 1, BattleFrontier_BattleArenaLobby_EventScript_25613A
	case 2, BattleFrontier_BattleArenaLobby_EventScript_256148
	case 3, BattleFrontier_BattleArenaLobby_EventScript_256156
	case 4, BattleFrontier_BattleArenaLobby_EventScript_256164
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_256164
	end

BattleFrontier_BattleArenaLobby_EventScript_25612C:: @ 825612C
	msgbox BattleFrontier_BattleArenaLobby_Text_256E02, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_25613A:: @ 825613A
	msgbox BattleFrontier_BattleArenaLobby_Text_256F43, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256148:: @ 8256148
	msgbox BattleFrontier_BattleArenaLobby_Text_256FF2, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256156:: @ 8256156
	msgbox BattleFrontier_BattleArenaLobby_Text_257202, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256164:: @ 8256164
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_256166: @ 8256166
	.string "Where the battling spirit of TRAINERS\n"
	.string "is put to the test!\p"
	.string "I welcome you to the BATTLE ARENA!\p"
	.string "I am your guide to the Set KO Tourney!$"

BattleFrontier_BattleArenaLobby_Text_2561EA: @ 82561EA
	.string "Now, do you wish to take\n"
	.string "the BATTLE ARENA challenge?$"

BattleFrontier_BattleArenaLobby_Text_25621F: @ 825621F
	.string "We await your challenge on\n"
	.string "another occasion!$"

BattleFrontier_BattleArenaLobby_Text_25624C: @ 825624C
	.string "In the BATTLE ARENA, we undertake\n"
	.string "the Set KO Tourney.\p"
	.string "All participants enter with a team of\n"
	.string "three POKéMON.\p"
	.string "The three POKéMON must be lined up in\n"
	.string "the order in which they are to appear.\p"
	.string "During battle, the POKéMON will appear\n"
	.string "one at a time in the preset order.\p"
	.string "Once a POKéMON enters battle, it must\n"
	.string "remain out until the match is decided.\p"
	.string "If a match remains undecided in\n"
	.string "three turns, it goes to judging.\p"
	.string "If you wish to interrupt your challenge,\n"
	.string "please save the game.\p"
	.string "If you don't save, you will not be able\n"
	.string "to continue with your challenge.\p"
	.string "If you pull off the feat of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.$"

BattleFrontier_BattleArenaLobby_Text_2564CE: @ 82564CE
	.string "Before showing you to the BATTLE\n"
	.string "ARENA, you must save. Is that okay?$"

BattleFrontier_BattleArenaLobby_Text_256513: @ 8256513
	.string "The BATTLE ARENA offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleArenaLobby_Text_256573: @ 8256573
	.string "Very well, now select your\n"
	.string "three POKéMON, please.$"

BattleFrontier_BattleArenaLobby_Text_2565A5: @ 82565A5
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

BattleFrontier_BattleArenaLobby_Text_2566A8: @ 82566A8
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "The three different POKéMON\n"
	.string "must all be Level 50 or lower.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

BattleFrontier_BattleArenaLobby_Text_2567E6: @ 82567E6
	.string "I shall now guide you to\n"
	.string "the BATTLE ARENA.$"

BattleFrontier_BattleArenaLobby_Text_256811: @ 8256811
	.string "My dear challenger!\p"
	.string "You did not save the game before\n"
	.string "shutting down, did you?\p"
	.string "It is unfortunate, but that has\n"
	.string "resulted in your disqualification\l"
	.string "from your challenge.\p"
	.string "You may, of course, start with a fresh\n"
	.string "challenge.$"

BattleFrontier_BattleArenaLobby_Text_2568E7: @ 82568E7
	.string "We congratulate you for your splendid\n"
	.string "string of wins over seven TRAINERS!$"

BattleFrontier_BattleArenaLobby_Text_256931: @ 8256931
	.string "Your achievement will be recorded.\n"
	.string "Please wait while I save the game.$"

BattleFrontier_BattleArenaLobby_Text_256977: @ 8256977
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"

BattleFrontier_BattleArenaLobby_Text_2569BE: @ 82569BE
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_2569D8: @ 82569D8
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"

BattleFrontier_BattleArenaLobby_Text_256A2C: @ 8256A2C
	.string "Thank you so much for participating!\p"
	.string "Please wait while I save the game.$"

BattleFrontier_BattleArenaLobby_Text_256A74: @ 8256A74
	.string "We await your challenge on\n"
	.string "another occasion!$"

BattleFrontier_BattleArenaLobby_Text_256AA1: @ 8256AA1
	.string "We have been looking forward to\n"
	.string "your arrival.\p"
	.string "Before I show you to the BATTLE\n"
	.string "ARENA, I must save the game.\l"
	.string "Please wait.$"

BattleFrontier_BattleArenaLobby_Text_256B19: @ 8256B19
	.string "Shall I record your last BATTLE ARENA\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattleArenaLobby_Text_256B5C: @ 8256B5C
	.string "I lost on the REFEREE's decision…\p"
	.string "I don't think it was a good idea to only\n"
	.string "use defensive moves and not attack…$"

BattleFrontier_BattleArenaLobby_Text_256BCB: @ 8256BCB
	.string "I won in judging!\p"
	.string "Landing hits consistently on\n"
	.string "the opponent's POKéMON worked!$"

BattleFrontier_BattleArenaLobby_Text_256C19: @ 8256C19
	.string "Our match was declared a draw.\p"
	.string "When we ran out of time, both my\n"
	.string "POKéMON and the opponent's had about\l"
	.string "the same amount of HP left.$"

BattleFrontier_BattleArenaLobby_Text_256C9A: @ 8256C9A
	.string "In the BATTLE ARENA, the order of\n"
	.string "POKéMON is totally important.\p"
	.string "For example, if your first POKéMON\n"
	.string "has certain type disadvantages,\l"
	.string "try making your second POKéMON one\l"
	.string "with moves that are super effective\l"
	.string "against the first one.\p"
	.string "I think that will be a good way of\n"
	.string "making an effective team.$"

BattleFrontier_BattleArenaLobby_Text_256DB8: @ 8256DB8
FallarborTown_BattleTentLobby_Text_256DB8: @ 8256DB8
	.string "The Set KO Tourney's rules are listed.$"

BattleFrontier_BattleArenaLobby_Text_256DDF: @ 8256DDF
FallarborTown_BattleTentLobby_Text_256DDF: @ 8256DDF
	.string "Which heading do you want to read?$"

BattleFrontier_BattleArenaLobby_Text_256E02: @ 8256E02
FallarborTown_BattleTentLobby_Text_256E02: @ 8256E02
	.string "The Set KO Tourney has special rules,\n"
	.string "unlike standard battles.\p"
	.string "First, one battle lasts only\n"
	.string "three turns.\p"
	.string "If the outcome is not decided after\n"
	.string "three turns, it goes to judging.\p"
	.string "The REFEREE will choose the winner\n"
	.string "based on how the POKéMON battled.\p"
	.string "Also, a POKéMON cannot be switched out\n"
	.string "until its battle's outcome is decided.$"

BattleFrontier_BattleArenaLobby_Text_256F43: @ 8256F43
FallarborTown_BattleTentLobby_Text_256F43: @ 8256F43
	.string "The first judging factor is “Mind.”\n"
	.string "This factor evaluates how aggressive\l"
	.string "the battlers were.\p"
	.string "The judging is based on how often\n"
	.string "the TRAINERS ordered the use of\l"
	.string "offensive moves.$"

BattleFrontier_BattleArenaLobby_Text_256FF2: @ 8256FF2
FallarborTown_BattleTentLobby_Text_256FF2: @ 8256FF2
	.string "The second judging factor is “Skill.”\n"
	.string "This factor evaluates how effectively\l"
	.string "POKéMON moves were used.\p"
	.string "If a move worked successfully,\n"
	.string "the Skill rating goes up.\p"
	.string "If a move failed, the Skill rating\n"
	.string "is lowered.\p"
	.string "If it was an offensive move, the Skill\n"
	.string "rating goes up if the move was “super\l"
	.string "effective” and goes down if it was\l"
	.string "“not very effective.”\p"
	.string "The Skill rating will not go up for\n"
	.string "moves such as PROTECT and DETECT.\p"
	.string "If the opponent used PROTECT or\n"
	.string "DETECT, and your POKéMON failed to\l"
	.string "hit with a move, its Skill rating will not\l"
	.string "go down.$"

BattleFrontier_BattleArenaLobby_Text_257202: @ 8257202
FallarborTown_BattleTentLobby_Text_257202: @ 8257202
	.string "The third judging factor is “Body.”\n"
	.string "This factor is based on how much HP\l"
	.string "remained at the end of a battle.\p"
	.string "The rating takes into account how much\n"
	.string "HP a POKéMON had at the start of\l"
	.string "battle, and what remained at the end.$"

BattleFrontier_BattleArenaLobby_Text_2572D9: @ 82572D9
	.string "A victory snatched from the ARENA\n"
	.string "TYCOON, and a seven-TRAINER sweep!\p"
	.string "We congratulate you on your most\n"
	.string "splendid challenge!$"

BattleFrontier_BattleArenaLobby_Text_257353: @ 8257353
	.string "My dear challenger, in recognition of\n"
	.string "your indefatigable spirit, please\l"
	.string "accept these Battle Point(s).$"
