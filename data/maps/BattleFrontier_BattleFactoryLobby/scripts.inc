BattleFrontier_BattleFactoryLobby_MapScripts:: @ 82583E8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_MapScript2_258407
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_MapScript2_2583F3
	.byte 0

BattleFrontier_BattleFactoryLobby_MapScript2_2583F3: @ 82583F3
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_2583FD
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_2583FD:: @ 82583FD
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_MapScript2_258407: @ 8258407
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258431
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleFactoryLobby_EventScript_25843A
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleFactoryLobby_EventScript_258592
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleFactoryLobby_EventScript_25849B
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleFactoryLobby_EventScript_258506
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_258431:: @ 8258431
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryLobby_EventScript_25843A:: @ 825843A
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_258ECA, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 8
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_25849B:: @ 825849B
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2584BD
	msgbox BattleFrontier_BattleFactoryLobby_Text_258D93, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_2584C6

BattleFrontier_BattleFactoryLobby_EventScript_2584BD:: @ 82584BD
	msgbox BattleFrontier_BattleFactoryLobby_Text_25926A, MSGBOX_DEFAULT
	waitmessage

BattleFrontier_BattleFactoryLobby_EventScript_2584C6:: @ 82584C6
	msgbox BattleFrontier_BattleFactoryLobby_Text_2592BD, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryLobby_Text_241520, 9
	message BattleFrontier_BattleFactoryLobby_Text_259323
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_25853B
	end

BattleFrontier_BattleFactoryLobby_EventScript_258506:: @ 8258506
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_258CC7
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_25853B:: @ 825853B
	call BattleFrontier_BattleFactoryLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258582
	message BattleFrontier_BattleFactoryLobby_Text_259388
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_258582
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_25857D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_258582

BattleFrontier_BattleFactoryLobby_EventScript_25857D:: @ 825857D
	call BattleFrontier_BattleFactoryLobby_EventScript_23E8B4

BattleFrontier_BattleFactoryLobby_EventScript_258582:: @ 8258582
	msgbox BattleFrontier_BattleFactoryLobby_Text_258BC5, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_258592:: @ 8258592
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_258E77
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_25871A

BattleFrontier_BattleFactoryLobby_EventScript_2585CB:: @ 82585CB
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 4
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_2585ED
	end

BattleFrontier_BattleFactoryLobby_EventScript_2585DD:: @ 82585DD
	setvar VAR_FRONTIER_FACILITY, 4
	setvar VAR_FRONTIER_BATTLE_MODE, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_2585ED
	end

BattleFrontier_BattleFactoryLobby_EventScript_2585ED:: @ 82585ED
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587B1
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587BA

BattleFrontier_BattleFactoryLobby_EventScript_258606:: @ 8258606
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587C3
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587C9
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_258653
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_258768
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_25879D

BattleFrontier_BattleFactoryLobby_EventScript_258653:: @ 8258653
	message BattleFrontier_BattleFactoryLobby_Text_258BE9
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryLobby_Text_258C27, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_25879A
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_2586B9
	case 127, BattleFrontier_BattleFactoryLobby_EventScript_25879A

BattleFrontier_BattleFactoryLobby_EventScript_2586B9:: @ 82586B9
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258783
	setvar VAR_0x8006, 0

BattleFrontier_BattleFactoryLobby_EventScript_25871A:: @ 825871A
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_258CB1, MSGBOX_DEFAULT
	closemessage
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_25875C
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258762
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_2587A7
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_2587AC
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 255, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_25875C:: @ 825875C
	setvar VAR_LAST_TALKED, 1
	return

BattleFrontier_BattleFactoryLobby_EventScript_258762:: @ 8258762
	setvar VAR_LAST_TALKED, 6
	return

BattleFrontier_BattleFactoryLobby_EventScript_258768:: @ 8258768
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587CF
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587D8
	goto BattleFrontier_BattleFactoryLobby_EventScript_258606

BattleFrontier_BattleFactoryLobby_EventScript_258783:: @ 8258783
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryLobby_EventScript_25879D

BattleFrontier_BattleFactoryLobby_EventScript_25879A:: @ 825879A
	special LoadPlayerParty

BattleFrontier_BattleFactoryLobby_EventScript_25879D:: @ 825879D
	msgbox BattleFrontier_BattleFactoryLobby_Text_258BC5, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_2587A7: @ 82587A7
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_2587AC: @ 82587AC
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_2587B1:: @ 82587B1
	msgbox BattleFrontier_BattleFactoryLobby_Text_2588EE, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587BA:: @ 82587BA
	msgbox BattleFrontier_BattleFactoryLobby_Text_258F93, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587C3:: @ 82587C3
	message BattleFrontier_BattleFactoryLobby_Text_25897A
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587C9:: @ 82587C9
	message BattleFrontier_BattleFactoryLobby_Text_25901F
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587CF:: @ 82587CF
	msgbox BattleFrontier_BattleFactoryLobby_Text_2589B3, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587D8:: @ 82587D8
	msgbox BattleFrontier_BattleFactoryLobby_Text_259058, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587E1:: @ 82587E1
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_2587FA:: @ 82587FA
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_258813:: @ 8258813
	msgbox BattleFrontier_BattleFactoryLobby_Text_2593D7, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_25881C:: @ 825881C
	msgbox BattleFrontier_BattleFactoryLobby_Text_2594E5, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_258825:: @ 8258825
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_259547, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_258830:: @ 8258830
	msgbox BattleFrontier_BattleFactoryLobby_Text_2595C4, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_258839:: @ 8258839
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_259721, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_258848:: @ 8258848
	message BattleFrontier_BattleFactoryLobby_Text_259743
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_2588A6
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_2588B4
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_2588C2
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_2588D0
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_2588DE
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_2588EC
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_2588EC
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588A6:: @ 82588A6
	msgbox BattleFrontier_BattleFactoryLobby_Text_259766, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588B4:: @ 82588B4
	msgbox BattleFrontier_BattleFactoryLobby_Text_2597FB, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588C2:: @ 82588C2
	msgbox BattleFrontier_BattleFactoryLobby_Text_25987E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588D0:: @ 82588D0
	msgbox BattleFrontier_BattleFactoryLobby_Text_259920, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588DE:: @ 82588DE
	msgbox BattleFrontier_BattleFactoryLobby_Text_259A5E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588EC:: @ 82588EC
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_2588EE: @ 82588EE
	.string "Where the intelligence of TRAINERS\n"
	.string "is put to the test!\p"
	.string "Welcome to the BATTLE FACTORY!\p"
	.string "I am your guide to the Battle Swap\n"
	.string "Single Tournament.$"

BattleFrontier_BattleFactoryLobby_Text_25897A: @ 825897A
	.string "Would you like to take the Battle\n"
	.string "Swap Single challenge?$"

BattleFrontier_BattleFactoryLobby_Text_2589B3: @ 82589B3
	.string "The Battle Swap Single Tournament\n"
	.string "is a SINGLE BATTLE competition using\l"
	.string "only rental POKéMON.\p"
	.string "First, you will be loaned three\n"
	.string "POKéMON specifically for this event.\p"
	.string "Using the supplied rental POKéMON,\n"
	.string "you must conduct a SINGLE BATTLE.\p"
	.string "If you win, you are permitted to trade\n"
	.string "one of your rental POKéMON.\p"
	.string "Repeat this cycle of battling and\n"
	.string "trading--if you win seven times in\l"
	.string "a row, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save, you will be\n"
	.string "disqualified from your challenge.$"

BattleFrontier_BattleFactoryLobby_Text_258BC5: @ 8258BC5
	.string "We look forward to your next visit.$"

BattleFrontier_BattleFactoryLobby_Text_258BE9: @ 8258BE9
	.string "Which level do you wish to challenge?\n"
	.string "Level 50 or Open Level?$"

BattleFrontier_BattleFactoryLobby_Text_258C27: @ 8258C27
	.string "Before you begin your challenge,\n"
	.string "I need to save the game. Is that okay?$"

BattleFrontier_BattleFactoryLobby_Text_258C6F: @ 8258C6F
	.string "Okay, I will hold your POKéMON for\n"
	.string "safekeeping while you compete.$"

BattleFrontier_BattleFactoryLobby_Text_258CB1: @ 8258CB1
	.string "Please step this way.$"

BattleFrontier_BattleFactoryLobby_Text_258CC7: @ 8258CC7
	.string "Thank you for participating!\p"
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.\p"
	.string "I must also save the event results.\n"
	.string "Please wait.$"

BattleFrontier_BattleFactoryLobby_Text_258D54: @ 8258D54
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_258D93: @ 8258D93
	.string "Congratulations! You've won seven\n"
	.string "straight Battle Swap matches!$"

BattleFrontier_BattleFactoryLobby_Text_258DD3: @ 8258DD3
	.string "In recognition of your 7-win streak,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleFactoryLobby_Text_258E1C: @ 8258E1C
	.string "Oh, oh, oh!\p"
	.string "Your Battle Points are maxed.\p"
	.string "Please come back after using\n"
	.string "some Battle Points.$"

BattleFrontier_BattleFactoryLobby_Text_258E77: @ 8258E77
	.string "We've been waiting for you!\p"
	.string "Before we resume your challenge,\n"
	.string "I must save the game.$"

BattleFrontier_BattleFactoryLobby_Text_258ECA: @ 8258ECA
	.string "I'm sorry to say this, but you didn't\n"
	.string "save before you quit playing last time.\p"
	.string "As a result, you have been disqualified\n"
	.string "from your challenge.$"

BattleFrontier_BattleFactoryLobby_Text_258F55: @ 8258F55
	.string "We'll return your personal POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_258F79: @ 8258F79
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_258F93: @ 8258F93
	.string "Where the intelligence of TRAINERS\n"
	.string "is put to the test!\p"
	.string "Welcome to the BATTLE FACTORY!\p"
	.string "I am your guide to the Battle Swap\n"
	.string "Double Tournament.$"

BattleFrontier_BattleFactoryLobby_Text_25901F: @ 825901F
	.string "Would you like to take the Battle\n"
	.string "Swap Double challenge?$"

BattleFrontier_BattleFactoryLobby_Text_259058: @ 8259058
	.string "The Battle Swap Double Tournament\n"
	.string "is a DOUBLE BATTLE competition using\l"
	.string "only rental POKéMON.\p"
	.string "First, you will be loaned three\n"
	.string "POKéMON specifically for this event.\p"
	.string "Using the supplied rental POKéMON,\n"
	.string "you must conduct a DOUBLE BATTLE.\p"
	.string "If you win, you are permitted to trade\n"
	.string "one of your rental POKéMON.\p"
	.string "Repeat this cycle of battling and\n"
	.string "trading--if you win seven times in\l"
	.string "a row, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleFactoryLobby_Text_25926A: @ 825926A
	.string "Congratulations for defeating\n"
	.string "the FACTORY HEAD and winning\l"
	.string "seven matches in a row!$"

BattleFrontier_BattleFactoryLobby_Text_2592BD: @ 82592BD
	.string "In recognition of your wealth of\n"
	.string "knowledge and keen intelligence,\l"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleFactoryLobby_Text_259323: @ 8259323
	.string "Let me exchange your POKéMON\n"
	.string "for our rental POKéMON.\p"
	.string "I need to save the battle data,\n"
	.string "so please wait.$"

BattleFrontier_BattleFactoryLobby_Text_259388: @ 8259388
	.string "Would you like to record your last\n"
	.string "BATTLE FACTORY match on your\l"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleFactoryLobby_Text_2593D7: @ 82593D7
	.string "Hi!\n"
	.string "You, there!\p"
	.string "Are you thinking that the events here\n"
	.string "are easy since you don't need to have\l"
	.string "a raised team of POKéMON?\p"
	.string "I wouldn't be too sure about winning\n"
	.string "that easily.\p"
	.string "If you don't have thorough knowledge\n"
	.string "about POKéMON and their moves,\l"
	.string "it will be tough to keep winning.$"

BattleFrontier_BattleFactoryLobby_Text_2594E5: @ 82594E5
	.string "I swapped for a weak POKéMON…\n"
	.string "I thought it was a good kind to have…\p"
	.string "They wiped the floor with us…$"

BattleFrontier_BattleFactoryLobby_Text_259547: @ 8259547
	.string "Things haven't been going my way\n"
	.string "at all.\p"
	.string "You need to check your opponent's\n"
	.string "POKéMON during battle to see if\l"
	.string "they're any good.$"

BattleFrontier_BattleFactoryLobby_Text_2595C4: @ 82595C4
	.string "You know how the staff here give you\n"
	.string "a few hints about your next opponent?\p"
	.string "Well, I'm a full-grown man, but I have\n"
	.string "trouble figuring out their hints.$"

BattleFrontier_BattleFactoryLobby_Text_259658: @ 8259658
	.string "Like, I'm really tough, but I get bored\n"
	.string "really easily, so I just kept swapping\l"
	.string "and battling over and over.\p"
	.string "So anyway, when I kept entering\n"
	.string "Battle Swap events, I noticed they\l"
	.string "varied the rental POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_259721: @ 8259721
SlateportCity_BattleTentLobby_Text_259721: @ 8259721
	.string "The Battle Swap rules are listed.$"

BattleFrontier_BattleFactoryLobby_Text_259743: @ 8259743
SlateportCity_BattleTentLobby_Text_259743: @ 8259743
	.string "Which heading do you want to read?$"

BattleFrontier_BattleFactoryLobby_Text_259766: @ 8259766
	.string "In a Battle Swap event, you may use\n"
	.string "only three POKéMON.\p"
	.string "Whether you are renting or swapping,\n"
	.string "your team may not have two or more\l"
	.string "of the same POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_2597FB: @ 82597FB
	.string "You may swap POKéMON only with\n"
	.string "the TRAINER you have just defeated.\p"
	.string "You may swap for only those POKéMON\n"
	.string "used by the beaten TRAINER.$"

BattleFrontier_BattleFactoryLobby_Text_25987E: @ 825987E
	.string "After every battle you win, you may\n"
	.string "swap for one of your defeated\l"
	.string "opponent's POKéMON.\p"
	.string "You will not be able to swap POKéMON\n"
	.string "with the seventh TRAINER in the event.$"

BattleFrontier_BattleFactoryLobby_Text_259920: @ 8259920
	.string "There are two key points to be aware\n"
	.string "of when swapping POKéMON.\p"
	.string "First, when swapping, you can't check\n"
	.string "the stats of the POKéMON you are\l"
	.string "about to receive.\p"
	.string "Second, the POKéMON on your team\n"
	.string "are lined up in sequence, depending on\l"
	.string "the order in which you rented them.\p"
	.string "This sequence remains unchanged\n"
	.string "even when swaps are made.$"

BattleFrontier_BattleFactoryLobby_Text_259A5E: @ 8259A5E
	.string "In the Open Level, the rental POKéMON\n"
	.string "and the opposing TRAINERS' POKéMON\l"
	.string "are all Level 100.$"
