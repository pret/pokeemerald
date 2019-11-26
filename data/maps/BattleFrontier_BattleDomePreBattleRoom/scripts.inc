BattleFrontier_BattleDomePreBattleRoom_MapScripts:: @ 824B1F9
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_MapScript2_24B218
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_MapScript2_24B204
	.byte 0

BattleFrontier_BattleDomePreBattleRoom_MapScript2_24B204: @ 824B204
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B20E
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B20E:: @ 824B20E
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomePreBattleRoom_MapScript2_24B218: @ 824B218
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B222
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B222:: @ 824B222
	compare VAR_0x8006, 1
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5C7
	frontier_set FRONTIER_DATA_6, 1
	setvar VAR_TEMP_0, 1
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_24B652
	waitmovement 0
	lockall

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F:: @ 824B24F
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_24B4FB
	waitmessage
	switch VAR_RESULT
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_24B2C1
	multichoice 16, 0, MULTI_TOURNEY_WITH_RECORD, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3DD
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3F5
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B46D
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B30D
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B349
	case 5, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B377
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B2C1:: @ 824B2C1
	multichoice 16, 2, MULTI_TOURNEY_NO_RECORD, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3DD
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3F5
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B46D
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B349
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B377
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B30D:: @ 824B30D
	message BattleFrontier_BattleDomePreBattleRoom_Text_24BAF7
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B33F
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B33F:: @ 824B33F
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B349:: @ 824B349
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BA69, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F
	case YES, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3BB
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B377:: @ 824B377
	message BattleFrontier_BattleDomePreBattleRoom_Text_24BA93
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3A9
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3A9:: @ 824B3A9
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 9
	special CallBattleDomeFunction
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24BE9A

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3BB:: @ 824B3BB
	message BattleFrontier_BattleDomePreBattleRoom_Text_24BAD3
	waitmessage
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 2
	special CallBattleDomeFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	frontier_reset
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3DD:: @ 824B3DD
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B9B5, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8004, 6
	special CallBattleDomeFunction
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B3F5:: @ 824B3F5
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_24B40A
	fadescreen 1
	setvar VAR_0x8004, 7
	special CallBattleDomeFunction
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B40A:: @ 824B40A
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B449
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B452
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B45B
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B464
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B449:: @ 824B449
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B9D9, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B452:: @ 824B452
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B9FD, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B45B:: @ 824B45B
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BA21, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B464:: @ 824B464
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BA46, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B46D:: @ 824B46D
	message BattleFrontier_BattleDomePreBattleRoom_Text_24B70C
	waitmessage
	waitbuttonpress
	fadescreen 1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 2  @ 2 of the 3 party mons are selected for battle
	special ChoosePartyForBattleFrontier
	waitstate
	frontier_resetsketch
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 8
	special CallBattleDomeFunction
	setvar VAR_0x8004, 18
	special CallBattleDomeFunction
	setvar VAR_0x8004, 9
	special CallBattleDomeFunction
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B748, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattleDomePreBattleRoom_Movement_24B64F
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_24B657
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_24B659
	waitmovement 0
	closedoor 5, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM, 255, 9, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B4FB:: @ 824B4FB
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B53A
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B540
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B546
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B54C
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B53A:: @ 824B53A
	message BattleFrontier_BattleDomePreBattleRoom_Text_24B65C
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B540:: @ 824B540
	message BattleFrontier_BattleDomePreBattleRoom_Text_24B689
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B546:: @ 824B546
	message BattleFrontier_BattleDomePreBattleRoom_Text_24B6B6
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B54C:: @ 824B54C
	frontier_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B58B
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5A0
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B58B
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5A0
	message BattleFrontier_BattleDomePreBattleRoom_Text_24B6E3
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B58B:: @ 824B58B
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5B5
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BB2E, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5A0:: @ 824B5A0
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5BE
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BBAC, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5B5:: @ 824B5B5
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BC2A, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5BE:: @ 824B5BE
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24BC63, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B5C7:: @ 824B5C7
	setvar VAR_TEMP_0, 1
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B760, MSGBOX_DEFAULT
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_24B600
	fadescreen 1
	setvar VAR_0x8004, 11
	special CallBattleDomeFunction
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24B24F

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B600:: @ 824B600
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B634
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B63D
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_24B646
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B634:: @ 824B634
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B7A3, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B63D:: @ 824B63D
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B7F1, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_24B646:: @ 824B646
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_24B83F, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_Movement_24B64F: @ 824B64F
	walk_right
	face_left
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_24B652: @ 824B652
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_24B657: @ 824B657
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_24B659: @ 824B659
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomePreBattleRoom_Text_24B65C: @ 824B65C
	.string "Your 1st-round match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B689: @ 824B689
	.string "Your 2nd-round match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B6B6: @ 824B6B6
	.string "Your semifinal match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B6E3: @ 824B6E3
	.string "Your final match is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B70C: @ 824B70C
	.string "Please choose the two POKéMON\n"
	.string "that are to appear in battle.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B748: @ 824B748
	.string "Right this way, please.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B760: @ 824B760
	.string "Thank you for competing!\p"
	.string "I'll restore your POKéMON to\n"
	.string "full health.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B7A3: @ 824B7A3
	.string "All 1st-round matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B7F1: @ 824B7F1
	.string "All 2nd-round matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B83F: @ 824B83F
	.string "All semifinal matches have been\n"
	.string "completed.\p"
	.string "These are the teams that advanced!$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B88D: @ 824B88D
	.string "Congratulations for getting through\n"
	.string "the 1st round.\p"
	.string "The 2nd round is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B8E6: @ 824B8E6
	.string "Congratulations for advancing\n"
	.string "to the semifinals.\p"
	.string "The best four teams meet in this round.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B94E: @ 824B94E
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "You're one win from the championship.\n"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B9B5: @ 824B9B5
	.string "{PLAYER}'s next opponent\n"
	.string "is this TRAINER.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B9D9: @ 824B9D9
	.string "The tournament is in the 1st round.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24B9FD: @ 824B9FD
	.string "The tournament is in the 2nd round.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BA21: @ 824BA21
	.string "The tournament is in the semifinals.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BA46: @ 824BA46
	.string "The tournament is up to the final.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BA69: @ 824BA69
	.string "Would you like to save and\n"
	.string "quit the game?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BA93: @ 824BA93
	.string "Would you like to retire from your\n"
	.string "Battle Tournament challenge?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BAD3: @ 824BAD3
	.string "I am saving your data.\n"
	.string "Please wait.$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BAF7: @ 824BAF7
	.string "Should I record your last match\n"
	.string "on your FRONTIER PASS?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BB2E: @ 824BB2E
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "For the final match, you will challenge\n"
	.string "the DOME ACE TUCKER.\p"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BBAC: @ 824BBAC
	.string "Congratulations for advancing\n"
	.string "to the final match.\p"
	.string "For the final match, you will challenge\n"
	.string "the DOME ACE TUCKER.\p"
	.string "Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BC2A: @ 824BC2A
	.string "Your final battle against TUCKER is\n"
	.string "next. Are you ready?$"

BattleFrontier_BattleDomePreBattleRoom_Text_24BC63: @ 824BC63
	.string "Your final battle against TUCKER is\n"
	.string "next. Are you ready?$"

