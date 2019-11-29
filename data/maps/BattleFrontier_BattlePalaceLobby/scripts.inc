BattleFrontier_BattlePalaceLobby_MapScripts:: @ 824D77E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_MapScript2_24D79D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_MapScript2_24D789
	.byte 0

BattleFrontier_BattlePalaceLobby_MapScript2_24D789: @ 824D789
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D793
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D793:: @ 824D793
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_MapScript2_24D79D: @ 824D79D
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D7C7
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_24D7D0
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_24D908
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_24D817
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_24D873
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D7C7:: @ 824D7C7
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D7D0:: @ 824D7D0
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E636, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D817:: @ 824D817
	lockall
	frontier_isbrain
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E497, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D840

BattleFrontier_BattlePalaceLobby_EventScript_24D838:: @ 824D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EE81, MSGBOX_DEFAULT

BattleFrontier_BattlePalaceLobby_EventScript_24D840:: @ 824D840
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EEB9, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_24E4F7
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D873:: @ 824D873
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_24E41E
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D8A1:: @ 824D8A1
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special CallBattlePalaceFunction
	playse SE_SAVE
	waitse
	call BattleFrontier_BattlePalaceLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24D907
	message BattleFrontier_BattlePalaceLobby_Text_24EF16
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24D907
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D902
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24D907

BattleFrontier_BattlePalaceLobby_EventScript_24D902:: @ 824D902
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_24D907:: @ 824D907
	return

BattleFrontier_BattlePalaceLobby_EventScript_24D908:: @ 824D908
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E5D8, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_24E5F6
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special CallBattlePalaceFunction
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DAF3

BattleFrontier_BattlePalaceLobby_EventScript_24D944:: @ 824D944
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D956:: @ 824D956
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D968:: @ 824D968
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	special CallBattlePalaceFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceLobby_EventScript_24D817
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB9E
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBA7

BattleFrontier_BattlePalaceLobby_EventScript_24D999:: @ 824D999
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBB0
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBB6
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D9E6
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB20
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24D9E6:: @ 824D9E6
	message BattleFrontier_BattlePalaceLobby_Text_24E119
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB45
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E399, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E3C8, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_24DA87
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DB91

BattleFrontier_BattlePalaceLobby_EventScript_24DA87:: @ 824DA87
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, 0
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattlePalaceFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB7A

BattleFrontier_BattlePalaceLobby_EventScript_24DAF3:: @ 824DAF3
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E408, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24DBBC
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 255, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB20:: @ 824DB20
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DE17, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB38:: @ 824DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EBC2, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB45:: @ 824DB45
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_24DB60
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_24DB6D

BattleFrontier_BattlePalaceLobby_EventScript_24DB60:: @ 824DB60
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E173, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB6D:: @ 824DB6D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E29E, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB7A:: @ 824DB7A
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24DB91:: @ 824DB91
	special LoadPlayerParty

BattleFrontier_BattlePalaceLobby_EventScript_24DB94:: @ 824DB94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT

BattleFrontier_BattlePalaceLobby_EventScript_24DB9C:: @ 824DB9C
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB9E:: @ 824DB9E
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DD5B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBA7:: @ 824DBA7
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EB06, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB0:: @ 824DBB0
	message BattleFrontier_BattlePalaceLobby_Text_24DDE1
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB6:: @ 824DBB6
	message BattleFrontier_BattlePalaceLobby_Text_24EB8C
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBBC:: @ 824DBBC
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC23
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC29
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC2F
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC35
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC49
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_24DC4C
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC3B
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC41
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
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC49: @ 824DC49
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC4C: @ 824DC4C
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_24DC50:: @ 824DC50
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC69:: @ 824DC69
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC82:: @ 824DC82
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E6E3, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC8B:: @ 824DC8B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E851, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC94:: @ 824DC94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E992, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC9D:: @ 824DC9D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EA4B, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCA6:: @ 824DCA6
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EF66, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCB5:: @ 824DCB5
	message BattleFrontier_BattlePalaceLobby_Text_24EF88
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DD13
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DD21
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DD2F
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_24DD3D
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_24DD4B
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD13:: @ 824DD13
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EFAB, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD21:: @ 824DD21
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F049, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD2F:: @ 824DD2F
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F190, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD3D:: @ 824DD3D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F2E8, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD4B:: @ 824DD4B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F3F4, MSGBOX_DEFAULT
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
	.string "If you don't save before interrupting,\n"
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
	.string "your POKéMON's exploits.\p"
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

VerdanturfTown_BattleTentLobby_Text_24E57B: @ 824E57B
	.string "You seem to have no space for\n"
	.string "our prize.\p"
	.string "You should return when you have\n"
	.string "organized your BAG.$"

BattleFrontier_BattlePalaceLobby_Text_24E5D8: @ 824E5D8
VerdanturfTown_BattleTentLobby_Text_24E5D8: @ 824E5D8
	.string "We have been waiting for you…$"

BattleFrontier_BattlePalaceLobby_Text_24E5F6: @ 824E5F6
VerdanturfTown_BattleTentLobby_Text_24E5F6: @ 824E5F6
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"

BattleFrontier_BattlePalaceLobby_Text_24E636: @ 824E636
VerdanturfTown_BattleTentLobby_Text_24E636: @ 824E636
	.string "Sigh…\p"
	.string "You failed to save before you ended\n"
	.string "your challenge the last time.\p"
	.string "As a result, your challenge has been\n"
	.string "disqualified. It is most unfortunate.$"

BattleFrontier_BattlePalaceLobby_Text_24E6C9: @ 824E6C9
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_24E6E3: @ 824E6E3
	.string "For a hardy fellow like me,\n"
	.string "hardy POKéMON are the best.\p"
	.string "Offense is the best defense!\n"
	.string "A relentless attack is the ultimate!\p"
	.string "But that's not what I wanted to chat\n"
	.string "about.\p"
	.string "Every so often a really cute lady\n"
	.string "swings by here.\p"
	.string "She says that she can tell what\n"
	.string "POKéMON are thinking.\p"
	.string "I don't know about that part,\n"
	.string "but she is really cute.\p"
	.string "Huh?\n"
	.string "Why are you looking at me like that?$"

BattleFrontier_BattlePalaceLobby_Text_24E851: @ 824E851
	.string "Hmm…\p"
	.string "It appears that the nature of POKéMON\n"
	.string "and the moves that they have been\l"
	.string "taught are the keys to battle here.\p"
	.string "To be more precise, it's how well\n"
	.string "the moves match the nature of\l"
	.string "the POKéMON.\p"
	.string "If your POKéMON is in trouble and\n"
	.string "unable to live up to its potential,\l"
	.string "you may need to examine how well\l"
	.string "its moves match its nature.$"

BattleFrontier_BattlePalaceLobby_Text_24E992: @ 824E992
	.string "My POKéMON is usually very docile.\p"
	.string "But when it's in a BATTLE HALL,\n"
	.string "it sometimes seems to become\l"
	.string "transformed into something wicked!\p"
	.string "It becomes totally intimidating.\n"
	.string "It's shocking, even.$"

BattleFrontier_BattlePalaceLobby_Text_24EA4B: @ 824EA4B
	.string "I wonder what sort of nature a POKéMON\n"
	.string "would have if it favored enfeebling its\l"
	.string "opponents and chipping away slowly.\p"
	.string "I'd be surprised if it was a LAX nature.\p"
	.string "But, nah, that can't be right.$"

BattleFrontier_BattlePalaceLobby_Text_24EB06: @ 824EB06
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the DOUBLE\n"
	.string "BATTLE HALLS.$"

BattleFrontier_BattlePalaceLobby_Text_24EB8C: @ 824EB8C
	.string "Do you wish to take\n"
	.string "the DOUBLE BATTLE HALL challenge?$"

BattleFrontier_BattlePalaceLobby_Text_24EBC2: @ 824EBC2
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for DOUBLE BATTLES\l"
	.string "that are named DOUBLE BATTLE HALLS.\p"
	.string "The DOUBLE BATTLES are conducted in\n"
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
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePalaceLobby_Text_24EE81: @ 824EE81
	.string "To defeat the PALACE MAVEN\n"
	.string "and seven TRAINERS in a row…$"

BattleFrontier_BattlePalaceLobby_Text_24EEB9: @ 824EEB9
	.string "In honor of the bond you share with\n"
	.string "your POKéMON, we present you with\l"
	.string "these Battle Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_24EF16: @ 824EF16
	.string "Would you like to record your latest\n"
	.string "BATTLE PALACE match on your\l"
	.string "FRONTIER PASS?$"

BattleFrontier_BattlePalaceLobby_Text_24EF66: @ 824EF66
	.string "The BATTLE HALL rules are listed.$"

BattleFrontier_BattlePalaceLobby_Text_24EF88: @ 824EF88
VerdanturfTown_BattleTentLobby_Text_24EF88: @ 824EF88
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePalaceLobby_Text_24EFAB: @ 824EFAB
VerdanturfTown_BattleTentLobby_Text_24EFAB: @ 824EFAB
	.string "Here, POKéMON are required to think\n"
	.string "and battle by themselves.\p"
	.string "Unlike in the wild, POKéMON that live\n"
	.string "with people behave differently\l"
	.string "depending on their nature.$"

BattleFrontier_BattlePalaceLobby_Text_24F049: @ 824F049
VerdanturfTown_BattleTentLobby_Text_24F049: @ 824F049
	.string "Depending on its nature, a POKéMON\n"
	.string "may prefer to attack no matter what.\p"
	.string "Another POKéMON may prefer to protect\n"
	.string "itself from any harm.\p"
	.string "Yet another may enjoy vexing or\n"
	.string "confounding its foes.\p"
	.string "Due to its nature, a POKéMON\n"
	.string "will have favorite moves that it is good\l"
	.string "at using.\p"
	.string "It may also dislike certain moves that\n"
	.string "it has trouble using.$"

BattleFrontier_BattlePalaceLobby_Text_24F190: @ 824F190
VerdanturfTown_BattleTentLobby_Text_24F190: @ 824F190
	.string "There are offensive moves that inflict\n"
	.string "direct damage on the foe.\p"
	.string "There are defensive moves that are\n"
	.string "used to prepare for enemy attacks or\l"
	.string "used to heal HP and so on.\p"
	.string "There are also other somewhat-odd\n"
	.string "moves that may enfeeble the foes with\l"
	.string "stat problems including poison and \l"
	.string "paralysis.\p"
	.string "POKéMON will consider using moves in\n"
	.string "these three categories.$"

BattleFrontier_BattlePalaceLobby_Text_24F2E8: @ 824F2E8
VerdanturfTown_BattleTentLobby_Text_24F2E8: @ 824F2E8
	.string "When not under command by its TRAINER,\n"
	.string "a POKéMON may be unable to effectively\l"
	.string "use certain moves.\p"
	.string "A POKéMON is not good at using any\n"
	.string "move that it dislikes.\p"
	.string "If a POKéMON only knows moves that\n"
	.string "do not match its nature, it will often\l"
	.string "be unable to live up to its potential.$"

BattleFrontier_BattlePalaceLobby_Text_24F3F4: @ 824F3F4
VerdanturfTown_BattleTentLobby_Text_24F3F4: @ 824F3F4
	.string "Depending on its nature, a POKéMON may\n"
	.string "start using moves that don't match its\l"
	.string "nature when it is in trouble.\p"
	.string "If a POKéMON begins behaving oddly\n"
	.string "in a pinch, watch it carefully.$"

