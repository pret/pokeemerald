BattleFrontier_BattleDomeLobby_MapScripts:: @ 82497E2
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_MapScript1_2497F2
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_MapScript2_24980F
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

BattleFrontier_BattleDomeLobby_MapScript1_2497F2: @ 82497F2
	dome_21
	end

BattleFrontier_BattleDomeLobby_OnWarp: @ 82497FB
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_249805
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249805:: @ 8249805
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_MapScript2_24980F: @ 824980F
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeLobby_EventScript_249839
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_249842
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_2499F9
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_24989B
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_249940
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249839:: @ 8249839
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_249842:: @ 8249842
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A45F, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_6, 1
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_24989B:: @ 824989B
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_2498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24A4E9, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_2498C9

BattleFrontier_BattleDomeLobby_EventScript_2498C1:: @ 82498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24AD67, MSGBOX_DEFAULT

BattleFrontier_BattleDomeLobby_EventScript_2498C9:: @ 82498C9
	msgbox BattleFrontier_BattleDomeLobby_Text_24ADB1, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_6, 1
	dome_set DOME_DATA_7, 1
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	goto BattleFrontier_BattleDomeLobby_EventScript_249991

BattleFrontier_BattleDomeLobby_EventScript_249940:: @ 8249940
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5BF, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_6, 1
	special LoadPlayerParty
	special HealPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_249991:: @ 8249991
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_2499E9
	message BattleFrontier_BattleDomeLobby_Text_24AE17
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_2499E9
	case 0, BattleFrontier_BattleDomeLobby_EventScript_2499E4
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_2499E9

BattleFrontier_BattleDomeLobby_EventScript_2499E4:: @ 82499E4
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_2499E9:: @ 82499E9
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_2499F9:: @ 82499F9
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5FE, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_24A61A
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_249BC2

BattleFrontier_BattleDomeLobby_EventScript_249A35:: @ 8249A35
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A47:: @ 8249A47
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A59:: @ 8249A59
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CFD
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D06

BattleFrontier_BattleDomeLobby_EventScript_249A72:: @ 8249A72
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D0F
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D15
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249ABF
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249BFA
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249ABF:: @ 8249ABF
	message BattleFrontier_BattleDomeLobby_Text_24A210
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249C64
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C15
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_24A26E, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C61
	msgbox BattleFrontier_BattleDomeLobby_Text_24A1C6, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_249C61
	case YES, BattleFrontier_BattleDomeLobby_EventScript_249B60
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249C61

BattleFrontier_BattleDomeLobby_EventScript_249B60:: @ 8249B60
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C4A
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_249BC2:: @ 8249BC2
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_24A437, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_249C6E
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 255, 23, 6
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249BFA:: @ 8249BFA
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D1B
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D24
	goto BattleFrontier_BattleDomeLobby_EventScript_249A72

BattleFrontier_BattleDomeLobby_EventScript_249C15:: @ 8249C15
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_249C30
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_249C3D

BattleFrontier_BattleDomeLobby_EventScript_249C30:: @ 8249C30
	msgbox BattleFrontier_BattleDomeLobby_Text_24A353, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C3D:: @ 8249C3D
	msgbox BattleFrontier_BattleDomeLobby_Text_24A2AB, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C4A:: @ 8249C4A
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249C61:: @ 8249C61
	special LoadPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_249C64:: @ 8249C64
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, MSGBOX_DEFAULT

BattleFrontier_BattleDomeLobby_EventScript_249C6C:: @ 8249C6C
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_249C6E:: @ 8249C6E
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CDD
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CE5
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_249D45
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D2D
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D33
	waitdooranim
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CED
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CF5
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_249D4E
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D39
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D3F
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
	msgbox BattleFrontier_BattleDomeLobby_Text_249EB7, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D06:: @ 8249D06
	msgbox BattleFrontier_BattleDomeLobby_Text_24A664, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D0F:: @ 8249D0F
	message BattleFrontier_BattleDomeLobby_Text_249F3A
	return

BattleFrontier_BattleDomeLobby_EventScript_249D15:: @ 8249D15
	message BattleFrontier_BattleDomeLobby_Text_24A6E7
	return

BattleFrontier_BattleDomeLobby_EventScript_249D1B:: @ 8249D1B
	msgbox BattleFrontier_BattleDomeLobby_Text_249F8E, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D24:: @ 8249D24
	msgbox BattleFrontier_BattleDomeLobby_Text_24A721, MSGBOX_DEFAULT
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
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4B: @ 8249D4B
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4E: @ 8249D4E
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_249D52:: @ 8249D52
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D6B:: @ 8249D6B
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D84:: @ 8249D84
	dome_get DOME_DATA_9
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DC9
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DD2
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DDB
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DE4
	fadescreen FADE_TO_BLACK
	dome_showresultstree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249DC9:: @ 8249DC9
	msgbox BattleFrontier_BattleDomeLobby_Text_24A966, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DD2:: @ 8249DD2
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9A9, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DDB:: @ 8249DDB
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9EC, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DE4:: @ 8249DE4
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA31, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DED:: @ 8249DED
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA76, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249DFE:: @ 8249DFE
	msgbox BattleFrontier_BattleDomeLobby_Text_24AB94, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E07:: @ 8249E07
	msgbox BattleFrontier_BattleDomeLobby_Text_24AC76, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E10:: @ 8249E10
	msgbox BattleFrontier_BattleDomeLobby_Text_24ACD3, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3:: @ 8249E19
	msgbox BattleFrontier_OutsideWest_Text_24AB06, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign2:: @ 8249E22
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_UnderConstructionSign:: @ 8249E2B
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E34:: @ 8249E34
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24AE63, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E43:: @ 8249E43
	message BattleFrontier_BattleDomeLobby_Text_24AE8B
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249E8B
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249E99
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249EA7
	case 3, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	end

BattleFrontier_BattleDomeLobby_EventScript_249E8B:: @ 8249E8B
	msgbox BattleFrontier_BattleDomeLobby_Text_24AEAE, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E99:: @ 8249E99
	msgbox BattleFrontier_BattleDomeLobby_Text_24AF4C, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249EA7:: @ 8249EA7
	msgbox BattleFrontier_BattleDomeLobby_Text_24B073, MSGBOX_DEFAULT
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
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to\n"
	.string "the tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
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
	.string "You don't have three eligible POKéMON.\p"
	.string "Also, the POKéMON must be holding\n"
	.string "different kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleDomeLobby_Text_24A353: @ 824A353
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
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
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleDomeLobby_Text_24A4E9: @ 824A4E9
	.string "Congratulations for winning\n"
	.string "your Battle Tournament!$"

BattleFrontier_BattleDomeLobby_Text_24A51D: @ 824A51D
	.string "Here is your prize for your Battle\n"
	.string "Tournament victory.$"

BattleFrontier_BattleDomeLobby_Text_ReceivedPrize: @ 824A554
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom: @ 824A56E
	.string "Oh, your BAG appears to be full.\p"
	.string "Please make room in your BAG, then come\n"
	.string "see me.$"

BattleFrontier_BattleDomeLobby_Text_24A5BF: @ 824A5BF
	.string "Thank you for playing!$"

BattleFrontier_BattleDomeLobby_Text_24A5D6: @ 824A5D6
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleDomeLobby_Text_24A5FE: @ 824A5FE
	.string "We've been waiting for you!$"

BattleFrontier_BattleDomeLobby_Text_24A61A: @ 824A61A
	.string "Before I show you to the BATTLE DOME,\n"
	.string "I must save the data. Is that okay?$"

BattleFrontier_BattleDomeLobby_Text_24A664: @ 824A664
	.string "Where the strategies of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE DOME!\p"
	.string "I am your guide to the DOUBLE BATTLE\n"
	.string "Tournament.$"

BattleFrontier_BattleDomeLobby_Text_24A6E7: @ 824A6E7
	.string "Would you like to challenge\n"
	.string "the DOUBLE BATTLE Tournament?$"

BattleFrontier_BattleDomeLobby_Text_24A721: @ 824A721
	.string "The DOUBLE BATTLE Tournament\n"
	.string "is exactly as the name suggests--\l"
	.string "a tournament of DOUBLE BATTLES.\p"
	.string "All participating TRAINERS must\n"
	.string "enter three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The remaining two POKéMON must take\n"
	.string "part in a DOUBLE BATTLE.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to\n"
	.string "the tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_24A966: @ 824A966
	.string "They're the results of the last\n"
	.string "Level 50 SINGLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_24A9A9: @ 824A9A9
	.string "They're the results of the last\n"
	.string "Level 50 DOUBLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_24A9EC: @ 824A9EC
	.string "They're the results of the last\n"
	.string "Open Level SINGLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_24AA31: @ 824AA31
	.string "They're the results of the last\n"
	.string "Open Level DOUBLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_24AA76: @ 824AA76
	.string "Did you see it?\n"
	.string "The last Battle Tournament?\p"
	.string "The winner, {STR_VAR_1}, was seriously\n"
	.string "tough.\p"
	.string "You should check out the results\n"
	.string "on the monitor beside the PC.$"

BattleFrontier_OutsideWest_Text_24AB06: @ 824AB06
	.string "The BATTLE FRONTIER…\n"
	.string "I've long dreamed about a place like it.$"

BattleFrontier_OutsideWest_Text_BattleDomeSign2: @ 824AB44
	.string "The BATTLE DOME\n"
	.string "Become the Unbeatable Superstar!$"

BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction: @ 824AB75
	.string "The ??????\n"
	.string "Under Construction!$"

BattleFrontier_BattleDomeLobby_Text_24AB94: @ 824AB94
	.string "When a TRAINER chains tournament\n"
	.string "wins at the BATTLE DOME, he or she\l"
	.string "gains a reputation as a star.\p"
	.string "Tough TRAINERS are drawn by that\n"
	.string "reputation to the BATTLE DOME.\p"
	.string "A true superstar is a TRAINER who\n"
	.string "can keep winning tournaments.$"

BattleFrontier_BattleDomeLobby_Text_24AC76: @ 824AC76
	.string "I ran into one of the tournament\n"
	.string "favorites in the very first round.\p"
	.string "Of course I got trashed…$"

BattleFrontier_BattleDomeLobby_Text_24ACD3: @ 824ACD3
	.string "I would've won if I'd kept this POKéMON\n"
	.string "held in reserve.\p"
	.string "You need to check your opponent's\n"
	.string "POKéMON carefully before choosing\l"
	.string "your battling POKéMON.$"

BattleFrontier_BattleDomeLobby_Text_24AD67: @ 824AD67
	.string "Congratulations!\p"
	.string "You defeated the DOME ACE and won\n"
	.string "the Battle Tournament!$"

BattleFrontier_BattleDomeLobby_Text_24ADB1: @ 824ADB1
	.string "In recognition of your strategy--\n"
	.string "a thing of beauty it was, too--\l"
	.string "we award you these Battle Point(s)!$"

BattleFrontier_BattleDomeLobby_Text_24AE17: @ 824AE17
	.string "Would you like to record your\n"
	.string "last BATTLE DOME match on your\l"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleDomeLobby_Text_24AE63: @ 824AE63
	.string "The Battle Tournament rules\n"
	.string "are listed.$"

BattleFrontier_BattleDomeLobby_Text_24AE8B: @ 824AE8B
	.string "Which heading do you want to read?$"

BattleFrontier_BattleDomeLobby_Text_24AEAE: @ 824AEAE
	.string "The tournament matchups are drawn up\n"
	.string "based on the toughness of POKéMON\l"
	.string "held by TRAINERS.\p"
	.string "The matchups avoid having tough\n"
	.string "TRAINERS face each other right away.$"

BattleFrontier_BattleDomeLobby_Text_24AF4C: @ 824AF4C
	.string "The tournament chart, or as we call it,\n"
	.string "the “Tree,” is available for viewing\l"
	.string "in the Waiting Room from any guide.\p"
	.string "The Tournament Tree will provide\n"
	.string "several kinds of data.\p"
	.string "The data on view includes the previous\n"
	.string "tournament's results, the POKéMON held\l"
	.string "by TRAINERS, and the battle styles of\l"
	.string "TRAINERS.$"

BattleFrontier_BattleDomeLobby_Text_24B073: @ 824B073
	.string "If battling POKéMON faint at the same\n"
	.string "time--a double KO--in a tournament\l"
	.string "match, the REFEREES will review\l"
	.string "the match and declare the winner.$"
