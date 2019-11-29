VerdanturfTown_BattleTentLobby_MapScripts:: @ 82016D0
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentLobby_MapScript2_2016EF
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentLobby_MapScript2_2016DB
	.byte 0

VerdanturfTown_BattleTentLobby_MapScript2_2016DB: @ 82016DB
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentLobby_EventScript_2016E5
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_2016E5:: @ 82016E5
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

VerdanturfTown_BattleTentLobby_MapScript2_2016EF: @ 82016EF
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentLobby_EventScript_201719
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, VerdanturfTown_BattleTentLobby_EventScript_201722
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, VerdanturfTown_BattleTentLobby_EventScript_201837
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, VerdanturfTown_BattleTentLobby_EventScript_201757
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, VerdanturfTown_BattleTentLobby_EventScript_2017FD
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_201719:: @ 8201719
	frontier_getstatus
	end

VerdanturfTown_BattleTentLobby_EventScript_201722:: @ 8201722
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_24E636, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_201757:: @ 8201757
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5731, MSGBOX_DEFAULT
	message VerdanturfTown_BattleTentLobby_Text_2C5791
	waitmessage
	setvar VAR_0x8004, 6
	special CallVerdanturfTentFunction
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 0
	special CallVerdanturfTentFunction
	playse SE_SAVE
	waitse

VerdanturfTown_BattleTentLobby_EventScript_201791:: @ 8201791
	msgbox VerdanturfTown_BattleTentLobby_Text_2C57CD, MSGBOX_DEFAULT
	setvar VAR_0x8004, 7
	special CallVerdanturfTentFunction
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_2017DD
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message VerdanturfTown_BattleTentLobby_Text_24A554
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox VerdanturfTown_BattleTentLobby_Text_2C539A, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_2017DD:: @ 82017DD
	msgbox VerdanturfTown_BattleTentLobby_Text_24E57B, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_2017EE:: @ 82017EE
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5731, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201791
	end

VerdanturfTown_BattleTentLobby_EventScript_2017FD:: @ 82017FD
	lockall
	message VerdanturfTown_BattleTentLobby_Text_2C56B8
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 0
	special CallVerdanturfTentFunction
	playse SE_SAVE
	waitse
	msgbox VerdanturfTown_BattleTentLobby_Text_2C539A, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_201837:: @ 8201837
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_24E5D8, MSGBOX_DEFAULT
	message VerdanturfTown_BattleTentLobby_Text_24E5F6
	waitmessage
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 1
	special CallVerdanturfTentFunction
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto VerdanturfTown_BattleTentLobby_EventScript_2019AE

VerdanturfTown_BattleTentLobby_EventScript_201873:: @ 8201873
	lock
	faceplayer
	setvar VAR_0x8004, 1
	special CallVerdanturfTentFunction
	compare VAR_RESULT, 0
	goto_if_ne VerdanturfTown_BattleTentLobby_EventScript_2017EE
	special SavePlayerParty
	msgbox VerdanturfTown_BattleTentLobby_Text_2C50C3, MSGBOX_DEFAULT

VerdanturfTown_BattleTentLobby_EventScript_201893:: @ 8201893
	message VerdanturfTown_BattleTentLobby_Text_2C5129
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_2018CF
	case 1, VerdanturfTown_BattleTentLobby_EventScript_2019DB
	case 2, VerdanturfTown_BattleTentLobby_EventScript_201A37
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_201A37

VerdanturfTown_BattleTentLobby_EventScript_2018CF:: @ 82018CF
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_2019E8
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5633, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_201A34
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5662, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, VerdanturfTown_BattleTentLobby_EventScript_201A34
	case YES, VerdanturfTown_BattleTentLobby_EventScript_201954
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_201A34

VerdanturfTown_BattleTentLobby_EventScript_201954:: @ 8201954
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, 0
	special CallVerdanturfTentFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_201A1D

VerdanturfTown_BattleTentLobby_EventScript_2019AE:: @ 82019AE
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox VerdanturfTown_BattleTentLobby_Text_2C56A2, MSGBOX_DEFAULT
	closemessage
	call VerdanturfTown_BattleTentLobby_EventScript_201A41
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

VerdanturfTown_BattleTentLobby_EventScript_2019DB:: @ 82019DB
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5163, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201893

VerdanturfTown_BattleTentLobby_EventScript_2019E8:: @ 82019E8
	switch VAR_RESULT
	case FRONTIER_LVL_50, VerdanturfTown_BattleTentLobby_EventScript_201A03
	case FRONTIER_LVL_OPEN, VerdanturfTown_BattleTentLobby_EventScript_201A10

VerdanturfTown_BattleTentLobby_EventScript_201A03:: @ 8201A03
	msgbox VerdanturfTown_BattleTentLobby_Text_2C543D, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201A3F

VerdanturfTown_BattleTentLobby_EventScript_201A10:: @ 8201A10
	msgbox VerdanturfTown_BattleTentLobby_Text_2C5538, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201A3F

VerdanturfTown_BattleTentLobby_EventScript_201A1D:: @ 8201A1D
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto VerdanturfTown_BattleTentLobby_EventScript_201A37

VerdanturfTown_BattleTentLobby_EventScript_201A34:: @ 8201A34
	special LoadPlayerParty
VerdanturfTown_BattleTentLobby_EventScript_201A37:: @ 8201A37
	msgbox VerdanturfTown_BattleTentLobby_Text_2C539A, MSGBOX_DEFAULT
VerdanturfTown_BattleTentLobby_EventScript_201A3F:: @ 8201A3F
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201A41:: @ 8201A41
	applymovement 1, VerdanturfTown_BattleTentLobby_Movement_201A70
	applymovement EVENT_OBJ_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_201A70
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement 1, VerdanturfTown_BattleTentLobby_Movement_201A74
	applymovement EVENT_OBJ_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_201A77
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

VerdanturfTown_BattleTentLobby_Movement_201A70: @ 8201A70
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentLobby_Movement_201A74: @ 8201A74
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_Movement_201A77: @ 8201A77
	walk_up
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_EventScript_201A7B:: @ 8201A7B
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM45, VerdanturfTown_BattleTentLobby_EventScript_201AB2
	msgbox VerdanturfTown_BattleTentLobby_Text_201D9E, MSGBOX_DEFAULT
	giveitem_std ITEM_TM45
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM45
	msgbox VerdanturfTown_BattleTentLobby_Text_201E43, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201AB2:: @ 8201AB2
	msgbox VerdanturfTown_BattleTentLobby_Text_201E43, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201ABC:: @ 8201ABC
	msgbox VerdanturfTown_BattleTentLobby_Text_201EB1, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_201AC5:: @ 8201AC5
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_201BD4, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201AD0:: @ 8201AD0
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_VERDANTURF, VerdanturfTown_BattleTentLobby_EventScript_201AED
	msgbox VerdanturfTown_BattleTentLobby_Text_201F3F, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_VERDANTURF
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201AED:: @ 8201AED
	msgbox VerdanturfTown_BattleTentLobby_Text_202025, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201AF7:: @ 8201AF7
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_201D11, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_201B02:: @ 8201B02
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_2C6878, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201B11:: @ 8201B11
	message VerdanturfTown_BattleTentLobby_Text_24EF88
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_TENT_RULES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_201B7E
	case 1, VerdanturfTown_BattleTentLobby_EventScript_201B8C
	case 2, VerdanturfTown_BattleTentLobby_EventScript_201B9A
	case 3, VerdanturfTown_BattleTentLobby_EventScript_201BA8
	case 4, VerdanturfTown_BattleTentLobby_EventScript_201BB6
	case 5, VerdanturfTown_BattleTentLobby_EventScript_201BC4
	case 6, VerdanturfTown_BattleTentLobby_EventScript_201BD2
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_201BD2
	end

VerdanturfTown_BattleTentLobby_EventScript_201B7E:: @ 8201B7E
	msgbox VerdanturfTown_BattleTentLobby_Text_2C67CD, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201B8C:: @ 8201B8C
	msgbox VerdanturfTown_BattleTentLobby_Text_24EFAB, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201B9A:: @ 8201B9A
	msgbox VerdanturfTown_BattleTentLobby_Text_24F049, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201BA8:: @ 8201BA8
	msgbox VerdanturfTown_BattleTentLobby_Text_24F190, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201BB6:: @ 8201BB6
	msgbox VerdanturfTown_BattleTentLobby_Text_24F2E8, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201BC4:: @ 8201BC4
	msgbox VerdanturfTown_BattleTentLobby_Text_24F3F4, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_201B11
	end

VerdanturfTown_BattleTentLobby_EventScript_201BD2:: @ 8201BD2
	releaseall
	end

VerdanturfTown_BattleTentLobby_Text_201BD4: @ 8201BD4
	.string "If it doesn't like a certain move,\n"
	.string "a POKéMON will be reluctant to use it.\p"
	.string "It doesn't matter how strong it is,\n"
	.string "either.\p"
	.string "For example, a POKéMON with a GENTLE\n"
	.string "nature probably won't enjoy hurting\l"
	.string "its opponents.\p"
	.string "If it can't seem to live up to its\n"
	.string "potential, it's probably failing at\l"
	.string "using a disliked move against its will.$"

VerdanturfTown_BattleTentLobby_Text_201D11: @ 8201D11
	.string "My big sister is gentle usually.\n"
	.string "But when she gets angry,\l"
	.string "she's really, really scary!\p"
	.string "I bet a gentle POKéMON will be scary\n"
	.string "if it gets angry!$"

VerdanturfTown_BattleTentLobby_Text_201D9E: @ 8201D9E
	.string "My feelings toward my POKéMON…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "How would you like this TM for\n"
	.string "your POKéMON?$"

VerdanturfTown_BattleTentLobby_Text_201E43: @ 8201E43
	.string "My feelings toward my POKéMON…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"

VerdanturfTown_BattleTentLobby_Text_201EB1: @ 8201EB1
	.string "What kind of moves have you taught\n"
	.string "your POKéMON?\p"
	.string "I think you would give yourself\n"
	.string "an advantage if they knew how to\l"
	.string "heal or protect themselves.$"

VerdanturfTown_BattleTentLobby_Text_201F3F: @ 8201F3F
	.string "SCOTT: Hey there, {PLAYER}{KUN}!\n"
	.string "I thought I might see you here.\p"
	.string "A BATTLE TENT's a place where\n"
	.string "you can meet tough TRAINERS.\p"
	.string "It doesn't matter what the rules are,\n"
	.string "or how battles are waged, either.\p"
	.string "{PLAYER}{KUN}, I expect you to do\n"
	.string "the best you can!$"

VerdanturfTown_BattleTentLobby_Text_202025: @ 8202025
	.string "SCOTT: I visit here regularly in hopes\n"
	.string "of seeing tough TRAINERS in action\l"
	.string "in whatever the situation.$"
