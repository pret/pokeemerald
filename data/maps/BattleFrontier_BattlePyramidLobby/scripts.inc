BattleFrontier_BattlePyramidLobby_MapScripts:: @ 8250716
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_MapScript2_250735
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidLobby_MapScript2_2497FB
	.byte 0

BattleFrontier_BattlePyramidLobby_MapScript2_250721: @ 8250721
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_25072B
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_25072B: @ 825072B
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_MapScript2_250735: @ 8250735
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePyramidLobby_EventScript_25075F
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_250768
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_2508AC
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_2507B1
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_250852
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_25075F:: @ 825075F
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_250768:: @ 8250768
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_2516D6
	waitmessage
	playse SE_EXPMAX
	waitse
	closemessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_2507B1:: @ 82507B1
	lockall
	frontier_isbrain
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_2507D2
	msgbox BattleFrontier_BattlePyramidLobby_Text_2517B5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_2507DA

BattleFrontier_BattlePyramidLobby_EventScript_2507D2:: @ 82507D2
	msgbox BattleFrontier_BattlePyramidLobby_Text_2525F4, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_2507DA:: @ 82507DA
	special DoBattlePyramidMonsHaveHeldItem
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250DDB
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_2519F8
	waitmessage
	playse SE_EXPMAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_252662, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_251A77
	waitmessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_REWARD
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 0
	special CallBattlePyramidFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251BB6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250852:: @ 8250852
	frontier_checkairshow
	special LoadPlayerParty
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_251B5A
	waitmessage
	playse SE_EXPMAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_251A77
	waitmessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 0
	special CallBattlePyramidFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251BB6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_2508AC:: @ 82508AC
	goto BattleFrontier_BattlePyramidLobby_EventScript_250A21

BattleFrontier_BattlePyramidLobby_EventScript_2508B1:: @ 82508B1
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_250F31, MSGBOX_DEFAULT

BattleFrontier_BattlePyramidLobby_EventScript_2508C8:: @ 82508C8
	message BattleFrontier_BattlePyramidLobby_Text_250FA7
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250904
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250A68
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250AC4

BattleFrontier_BattlePyramidLobby_EventScript_250904:: @ 8250904
	message BattleFrontier_BattlePyramidLobby_Text_251248
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250A75
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_251297, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250AC1
	msgbox BattleFrontier_BattlePyramidLobby_Text_2514E6, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_250AC1
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_2509A5
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250AC1

BattleFrontier_BattlePyramidLobby_EventScript_2509A5:: @ 82509A5
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_CHALLENGE
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattlePyramidFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SEED_FLOOR
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_TRAINERS
	special CallBattlePyramidFunction
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250AAA

BattleFrontier_BattlePyramidLobby_EventScript_250A21:: @ 8250A21
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_251531, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_250D56
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_250A68:: @ 8250A68
	msgbox BattleFrontier_BattlePyramidLobby_Text_25100C, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_2508C8

BattleFrontier_BattlePyramidLobby_EventScript_250A75:: @ 8250A75
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_250A90
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_250A9D

BattleFrontier_BattlePyramidLobby_EventScript_250A90:: @ 8250A90
	msgbox BattleFrontier_BattlePyramidLobby_Text_2513C1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250ACC

BattleFrontier_BattlePyramidLobby_EventScript_250A9D:: @ 8250A9D
	msgbox BattleFrontier_BattlePyramidLobby_Text_2512E2, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250ACC

BattleFrontier_BattlePyramidLobby_EventScript_250AAA:: @ 8250AAA
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_250AC4

BattleFrontier_BattlePyramidLobby_EventScript_250AC1:: @ 8250AC1
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_250AC4:: @ 8250AC4
	msgbox BattleFrontier_BattlePyramidLobby_Text_250FE5, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_250ACC:: @ 8250ACC
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_250ACE:: @ 8250ACE
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C3B, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_250AF0
	msgbox BattleFrontier_BattlePyramidLobby_Text_252461, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250AF0:: @ 8250AF0
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250B28
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250B66
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250B27
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250B27
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B27:: @ 8250B27
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B28:: @ 8250B28
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C8A, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 5
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_250B53
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B53:: @ 8250B53
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 3
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B66:: @ 8250B66
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C8A, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 6
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_250B91
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B91:: @ 8250B91
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 4
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250BA4:: @ 8250BA4
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250C8E
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250C97
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250CA0
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_250CA9
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_250CB2
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_250CBB
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_250CC4
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_250CCD
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_250CD6
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_250CDF
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_250CE8
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_250CF1
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_250CFA
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_250D03
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_250D0C
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_250D15
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_250D1E
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_250D27
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_250D30
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_250D39
	return

BattleFrontier_BattlePyramidLobby_EventScript_250C8E:: @ 8250C8E
	msgbox BattleFrontier_BattlePyramidLobby_Text_251CB3, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250C97:: @ 8250C97
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D07, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CA0:: @ 8250CA0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D54, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CA9:: @ 8250CA9
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D9C, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CB2:: @ 8250CB2
	msgbox BattleFrontier_BattlePyramidLobby_Text_251E3D, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CBB:: @ 8250CBB
	msgbox BattleFrontier_BattlePyramidLobby_Text_251EA1, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CC4:: @ 8250CC4
	msgbox BattleFrontier_BattlePyramidLobby_Text_251F17, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CCD:: @ 8250CCD
	msgbox BattleFrontier_BattlePyramidLobby_Text_251F6E, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CD6:: @ 8250CD6
	msgbox BattleFrontier_BattlePyramidLobby_Text_251FC7, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CDF:: @ 8250CDF
	msgbox BattleFrontier_BattlePyramidLobby_Text_25201B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CE8:: @ 8250CE8
	msgbox BattleFrontier_BattlePyramidLobby_Text_252068, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CF1:: @ 8250CF1
	msgbox BattleFrontier_BattlePyramidLobby_Text_2520BA, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CFA:: @ 8250CFA
	msgbox BattleFrontier_BattlePyramidLobby_Text_252158, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D03:: @ 8250D03
	msgbox BattleFrontier_BattlePyramidLobby_Text_2521B4, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D0C:: @ 8250D0C
	msgbox BattleFrontier_BattlePyramidLobby_Text_252206, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D15:: @ 8250D15
	msgbox BattleFrontier_BattlePyramidLobby_Text_25225A, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D1E:: @ 8250D1E
	msgbox BattleFrontier_BattlePyramidLobby_Text_2522AE, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D27:: @ 8250D27
	msgbox BattleFrontier_BattlePyramidLobby_Text_25230B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D30:: @ 8250D30
	msgbox BattleFrontier_BattlePyramidLobby_Text_252364, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D39:: @ 8250D39
	msgbox BattleFrontier_BattlePyramidLobby_Text_252403, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D42:: @ 8250D42
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250D56:: @ 8250D56
	applymovement 1, BattleFrontier_BattlePyramidLobby_Movement_250DC4
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_250DCD
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251569, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 1
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250D94
	msgbox BattleFrontier_BattlePyramidLobby_Text_2515AD, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250D9C

BattleFrontier_BattlePyramidLobby_EventScript_250D94:: @ 8250D94
	msgbox BattleFrontier_BattlePyramidLobby_Text_2515F4, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_250D9C:: @ 8250D9C
	message BattleFrontier_BattlePyramidLobby_Text_25161E
	waitmessage
	playse SE_EXPMAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251647, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattlePyramidLobby_Movement_250DD5
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_250DD8
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_250DC4: @ 8250DC4
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DCD: @ 8250DCD
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DD5: @ 8250DD5
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DD8: @ 8250DD8
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_250DDB:: @ 8250DDB
	msgbox BattleFrontier_BattlePyramidLobby_Text_2517FC, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250E00
	message BattleFrontier_BattlePyramidLobby_Text_2518C6
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E00:: @ 8250E00
	msgbox BattleFrontier_BattlePyramidLobby_Text_251881, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250E09:: @ 8250E09
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250E40
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250E50
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250E60
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250E60
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E40:: @ 8250E40
	special sub_81C4F24
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E50:: @ 8250E50
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E60:: @ 8250E60
	special DoBattlePyramidMonsHaveHeldItem
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250E6F
	return

BattleFrontier_BattlePyramidLobby_EventScript_250E6F:: @ 8250E6F
	msgbox BattleFrontier_BattlePyramidLobby_Text_25194F, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E83:: @ 8250E83
	msgbox BattleFrontier_BattlePyramidLobby_Text_2524DA, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E8C:: @ 8250E8C
	msgbox BattleFrontier_BattlePyramidLobby_Text_252595, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E95:: @ 8250E95
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_2526B6, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250EA4:: @ 8250EA4
	message BattleFrontier_BattlePyramidLobby_Text_2526D9
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250EF7
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250F05
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250F13
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_250F21
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_250F2F
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250F2F
	end

BattleFrontier_BattlePyramidLobby_EventScript_250EF7:: @ 8250EF7
	msgbox BattleFrontier_BattlePyramidLobby_Text_2526FC, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F05:: @ 8250F05
	msgbox BattleFrontier_BattlePyramidLobby_Text_2527A9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F13:: @ 8250F13
	msgbox BattleFrontier_BattlePyramidLobby_Text_25285A, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F21:: @ 8250F21
	msgbox BattleFrontier_BattlePyramidLobby_Text_252924, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F2F:: @ 8250F2F
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_250F31: @ 8250F31
	.string "Where the courage of TRAINERS\n"
	.string "is put to the test!\p"
	.string "Welcome to the BATTLE PYRAMID!\p"
	.string "I am your guide to\n"
	.string "the Battle Quest.$"

BattleFrontier_BattlePyramidLobby_Text_250FA7: @ 8250FA7
	.string "Have you the courage to embark on\n"
	.string "the Battle Quest challenge?$"

BattleFrontier_BattlePyramidLobby_Text_250FE5: @ 8250FE5
	.string "We await your challenge in the future!$"

BattleFrontier_BattlePyramidLobby_Text_25100C: @ 825100C
	.string "The Battle Quest is a battling\n"
	.string "event in which you must explore\l"
	.string "the PYRAMID and try to reach the top.\p"
	.string "In the PYRAMID are seven floors of\n"
	.string "mazes, all of them filled with not only\l"
	.string "skilled TRAINERS but also wild POKéMON.\p"
	.string "You must enter with three POKéMON,\n"
	.string "none of them holding an item.\p"
	.string "On your ascent, you will be provided\n"
	.string "with a BATTLE BAG for items.\p"
	.string "If you fail in your challenge, any item\n"
	.string "placed in the BATTLE BAG disappears.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must select “REST”\l"
	.string "and save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePyramidLobby_Text_251248: @ 8251248
	.string "The PYRAMID offers two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you enter?$"

BattleFrontier_BattlePyramidLobby_Text_251297: @ 8251297
	.string "Very good. Now, please select the three\n"
	.string "POKéMON you wish to accompany you.$"

BattleFrontier_BattlePyramidLobby_Text_2512E2: @ 82512E2
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you are ready, please have\n"
	.string "a word with me.$"

BattleFrontier_BattlePyramidLobby_Text_2513C1: @ 82513C1
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "The three POKéMON must be different\n"
	.string "and each no higher than Level 50.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you are ready, please have\n"
	.string "a word with me.$"

BattleFrontier_BattlePyramidLobby_Text_2514E6: @ 82514E6
	.string "Before you enter the BATTLE PYRAMID,\n"
	.string "the game must be saved. Is that okay?$"

BattleFrontier_BattlePyramidLobby_Text_251531: @ 8251531
	.string "Very good. I will now show you into\n"
	.string "the BATTLE PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_251569: @ 8251569
	.string "We will hold your BAG for safekeeping,\n"
	.string "{PLAYER}, while you are exploring.$"

BattleFrontier_BattlePyramidLobby_Text_2515AD: @ 82515AD
	.string "In exchange, please take this BATTLE\n"
	.string "BAG, the one you used previously.$"

BattleFrontier_BattlePyramidLobby_Text_2515F4: @ 82515F4
	.string "In exchange, please take this\n"
	.string "BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_25161E: @ 825161E
	.string "{PLAYER} exchanged the BAG for\n"
	.string "the BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_251647: @ 8251647
	.string "When you step on this floor panel,\n"
	.string "you will be transported to a higher\l"
	.string "floor in the PYRAMID.\p"
	.string "I hope for your sake that your\n"
	.string "quest goes safely!$"

BattleFrontier_BattlePyramidLobby_Text_2516D6: @ 82516D6
	.string "A major problem, explorer!\p"
	.string "You did not save before ending\n"
	.string "your challenge the last time.\p"
	.string "Consequently, your challenge has\n"
	.string "been disqualified, I'm sorry to say.\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_2517B5: @ 82517B5
	.string "Excellent to see you back!\p"
	.string "You've conquered the PYRAMID!\n"
	.string "How splendid!$"

BattleFrontier_BattlePyramidLobby_Text_2517FC: @ 82517FC
	.string "Ah, a slight problem.\p"
	.string "At least one POKéMON is holding\n"
	.string "an item.\p"
	.string "I'm sorry to say, items obtained in\n"
	.string "the PYRAMID cannot be taken away.$"

BattleFrontier_BattlePyramidLobby_Text_251881: @ 8251881
	.string "All items held by your POKéMON will be\n"
	.string "moved to your BATTLE BAG, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_2518C6: @ 82518C6
	.string "The BATTLE BAG cannot hold all your\n"
	.string "items, I'm sorry to say.\p"
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_25194F: @ 825194F
	.string "At least one POKéMON is still\n"
	.string "holding an item.$"

BattleFrontier_BattlePyramidLobby_Text_25197E: @ 825197E
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_2519CA: @ 82519CA
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"

BattleFrontier_BattlePyramidLobby_Text_2519F8: @ 82519F8
	.string "The BATTLE BAG you used will be kept\n"
	.string "in readiness for your next challenge.\p"
	.string "{PLAYER} turned the BATTLE BAG over\n"
	.string "for the BAG's return.$"

BattleFrontier_BattlePyramidLobby_Text_251A77: @ 8251A77
	.string "I must record your results.\n"
	.string "Please wait.$"

BattleFrontier_BattlePyramidLobby_Text_251AA0: @ 8251AA0
	.string "As a memento for conquering\n"
	.string "the BATTLE PYRAMID, please take this.$"

BattleFrontier_BattlePyramidLobby_Text_251AE2: @ 8251AE2
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_251AFC: @ 8251AFC
	.string "…Ah…\n"
	.string "Your BAG appears to be filled.\p"
	.string "Please return after you've organized\n"
	.string "your BAG's contents.$"

BattleFrontier_BattlePyramidLobby_Text_251B5A: @ 8251B5A
	.string "How disappointing for you…\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_251BB6: @ 8251BB6
	.string "We look forward to your\n"
	.string "next challenge!$"

BattleFrontier_BattlePyramidLobby_Text_251BDE: @ 8251BDE
	.string "We have been looking forward to\n"
	.string "your arrival!\p"
	.string "Here is your prize for conquering\n"
	.string "the PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_251C3B: @ 8251C3B
	.string "Welcome…\p"
	.string "I shall be pleased to tell you what\n"
	.string "misfortunes await in the PYRAMID…$"

BattleFrontier_BattlePyramidLobby_Text_251C8A: @ 8251C8A
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_251CB3: @ 8251CB3
	.string "I see a shower of sparks…\p"
	.string "…And in it, I see your POKéMON\n"
	.string "struggling with paralysis…$"

BattleFrontier_BattlePyramidLobby_Text_251D07: @ 8251D07
	.string "I see poison…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from the effects of poison…$"

BattleFrontier_BattlePyramidLobby_Text_251D54: @ 8251D54
	.string "I see bright red flames…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from burns…$"

BattleFrontier_BattlePyramidLobby_Text_251D9C: @ 8251D9C
	.string "I sense the tremendous pressure of\n"
	.string "unrequited anger…\p"
	.string "It is a curse…\p"
	.string "…And, I see your POKéMON drained of\n"
	.string "Power Points and having no recourse\l"
	.string "but to use STRUGGLE…$"

BattleFrontier_BattlePyramidLobby_Text_251E3D: @ 8251E3D
	.string "I see POKéMON loftily airborne…\p"
	.string "…And, I see your POKéMON frustrated\n"
	.string "by powerless GROUND-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_251EA1: @ 8251EA1
	.string "I sense terrific energy rising from\n"
	.string "the ground below…\p"
	.string "…And, I see your POKéMON unable to\n"
	.string "escape the power's clutches…$"

BattleFrontier_BattlePyramidLobby_Text_251F17: @ 8251F17
	.string "I see ICE-type POKéMON…\p"
	.string "…And, I see your POKéMON fighting\n"
	.string "the freezing effects of ice…$"

BattleFrontier_BattlePyramidLobby_Text_251F6E: @ 8251F6E
	.string "I see a flurry of moves that imperil\n"
	.string "the user…\p"
	.string "…And, I see your POKéMON falling\n"
	.string "to them…$"

BattleFrontier_BattlePyramidLobby_Text_251FC7: @ 8251FC7
	.string "I see PSYCHIC-type POKéMON…\p"
	.string "…And, I see your POKéMON in torment\n"
	.string "from PSYCHIC moves…$"

BattleFrontier_BattlePyramidLobby_Text_25201B: @ 825201B
	.string "I see ROCK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from ROCK moves…$"

BattleFrontier_BattlePyramidLobby_Text_252068: @ 8252068
	.string "I see FIGHTING-type POKéMON…\p"
	.string "…And, I see your POKéMON pummeled\n"
	.string "by FIGHTING moves…$"

BattleFrontier_BattlePyramidLobby_Text_2520BA: @ 82520BA
	.string "RAIN DANCE… SUNNY DAY…\n"
	.string "SANDSTORM… HAIL…\p"
	.string "I see POKéMON that become stronger\n"
	.string "with the weather…\p"
	.string "…And, I see your POKéMON confounded\n"
	.string "by different types of moves…$"

BattleFrontier_BattlePyramidLobby_Text_252158: @ 8252158
	.string "I see BUG-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from different kinds of attacks…$"

BattleFrontier_BattlePyramidLobby_Text_2521B4: @ 82521B4
	.string "I see DARK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from DARK-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_252206: @ 8252206
	.string "I see WATER-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from WATER-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_25225A: @ 825225A
	.string "I see GHOST-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from GHOST-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_2522AE: @ 82522AE
	.string "I see STEEL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_25230B: @ 825230B
	.string "I see flying POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_252364: @ 8252364
	.string "I see those that have evolved from\n"
	.string "the power of stones…\p"
	.string "I also sense fire, water,\n"
	.string "and electricity…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from those three powers…$"

BattleFrontier_BattlePyramidLobby_Text_252403: @ 8252403
	.string "I see NORMAL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_252461: @ 8252461
	.string "Whether you believe my fortunes\n"
	.string "or not, the choice is yours…\p"
	.string "The future can be changed anytime…\n"
	.string "I wish you safe passage…$"

BattleFrontier_BattlePyramidLobby_Text_2524DA: @ 82524DA
	.string "Did you know?\p"
	.string "If you run fast, TRAINERS may notice\n"
	.string "and come after you for a battle.\p"
	.string "So, if you want to avoid TRAINERS,\n"
	.string "don't catch their eyes, but sneak\l"
	.string "cautiously and quietly past them.$"

BattleFrontier_BattlePyramidLobby_Text_252595: @ 8252595
	.string "Awaaaaaaarrrrgh!\p"
	.string "I had a whole lot of items, but I lost\n"
	.string "them all when I lost!\p"
	.string "Awaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_2525F4: @ 82525F4
	.string "Welcome back!\n"
	.string "You've done the unthinkable!\p"
	.string "You've defeated the PYRAMID KING\n"
	.string "and conquered the BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_252662: @ 8252662
	.string "Young explorer!\n"
	.string "In commendation of your courage,\l"
	.string "we give you these Battle Point(s)!$"

BattleFrontier_BattlePyramidLobby_Text_2526B6: @ 82526B6
	.string "The Battle Quest rules are listed.$"

BattleFrontier_BattlePyramidLobby_Text_2526D9: @ 82526D9
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePyramidLobby_Text_2526FC: @ 82526FC
	.string "When the PYRAMID is conquered,\n"
	.string "the wild POKéMON that appear in it\l"
	.string "are replaced by different kinds.\p"
	.string "Explore, observe, and learn what kinds\n"
	.string "of wild POKéMON you may encounter.$"

BattleFrontier_BattlePyramidLobby_Text_2527A9: @ 82527A9
	.string "TRAINERS are lying in wait for you\n"
	.string "inside the PYRAMID.\p"
	.string "On each floor, there are up to\n"
	.string "eight TRAINERS.\p"
	.string "When you defeat a TRAINER, you will\n"
	.string "get a helpful hint for your adventure.$"

BattleFrontier_BattlePyramidLobby_Text_25285A: @ 825285A
	.string "The mazes in the PYRAMID rearrange\n"
	.string "themselves every time you enter it.\p"
	.string "The mazes are poorly lit.\n"
	.string "You must advance with caution.\p"
	.string "The light grows brighter whenever you\n"
	.string "defeat a wild POKéMON or a TRAINER.$"

BattleFrontier_BattlePyramidLobby_Text_252924: @ 8252924
	.string "The BATTLE BAG serves as your BAG\n"
	.string "while in the PYRAMID.\p"
	.string "There are two separate BATTLE BAGS--\n"
	.string "one each for the Level 50 and\l"
	.string "Open Level adventures.\p"
	.string "They each can hold up to 99 pieces\n"
	.string "of ten kinds of items.\p"
	.string "The contents of the BATTLE BAG are\n"
	.string "lost if you fail in your quest.$"

