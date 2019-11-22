BattleFrontier_BattleArenaBattleRoom_MapScripts:: @ 8257487
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_MapScript1_2574A0
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScript2_2574D2
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScript2_257C0C
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_MapScript1_25749C
	.byte 0

BattleFrontier_BattleArenaBattleRoom_MapScript1_25749C: @ 825749C
	special OffsetCameraForBattle
	end

BattleFrontier_BattleArenaBattleRoom_MapScript1_2574A0: @ 82574A0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_FRONTIER_TRAINERS
	special CallFrontierUtilFunc
	call BattleFrontier_BattleArenaBattleRoom_EventScript_2574AE
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_2574AE:: @ 82574AE
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2574C6
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2574CC
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_2574C6:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_2574CC:: @ 82574CC
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleArenaBattleRoom_MapScript2_2574D2: @ 82574D2
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_2574DC
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_2574DC:: @ 82574DC
	lockall
	showobjectat 8, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE2
	waitmovement 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25752E
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257C08
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BEB
	setvar VAR_TEMP_2, 1
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25752E:: @ 825752E
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_CHOOSE_TRAINER
	special CallBattleTowerFunc
	addobject 7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BEF
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C3D, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE5
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	setvar VAR_0x8004, 6
	special CallBattleArenaFunction
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C68, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C93, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE5
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	setvar VAR_0x8004, 5
	special CallBattlePalaceFunction
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_257630

BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB:: @ 82575DB
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 1, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 2, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 3, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	applymovement 4, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	playse SE_W173
	waitse
	waitmovement 0
	setvar VAR_0x8004, 6
	special CallBattleArenaFunction
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CCE, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257615:: @ 8257615
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257630:: @ 8257630
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	switch VAR_RESULT
	case 7, BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BFA
	waitmovement 0
	removeobject 7
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257C08
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BEB
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CE9, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_LOAD_SELECTED_PARTY
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0:: @ 82576B0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_9
	special CallFrontierUtilFunc
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_2578BC
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257870
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257877
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25787E
	compare VAR_RESULT, 4
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257885
	compare VAR_RESULT, 5
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25788C
	compare VAR_RESULT, 6
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257893
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257768
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_25783A
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_25779E
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_257768:: @ 8257768
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_25783A
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25779E:: @ 825779E
	message BattleFrontier_BattleArenaBattleRoom_Text_257F04
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_2577D0
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_2577D0:: @ 82577D0
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8B4
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA:: @ 82577DA
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257E6B, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case YES, BattleFrontier_BattleArenaBattleRoom_EventScript_25789A
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_257808:: @ 8257808
	message BattleFrontier_BattleArenaBattleRoom_Text_257E9E
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257615
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25783A:: @ 825783A
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	waitmovement 0
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_25752E
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257852:: @ 8257852
	delay 60
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257870:: @ 8257870
	message BattleFrontier_BattleArenaBattleRoom_Text_257D17
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257877:: @ 8257877
	message BattleFrontier_BattleArenaBattleRoom_Text_257D50
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25787E:: @ 825787E
	message BattleFrontier_BattleArenaBattleRoom_Text_257D88
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257885:: @ 8257885
	message BattleFrontier_BattleArenaBattleRoom_Text_257DC1
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25788C:: @ 825788C
	message BattleFrontier_BattleArenaBattleRoom_Text_257DF9
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257893:: @ 8257893
	message BattleFrontier_BattleArenaBattleRoom_Text_257E31
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25789A:: @ 825789A
	message BattleFrontier_BattleArenaBattleRoom_Text_257EDB
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SOFT_RESET
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_2578BC:: @ 82578BC
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257F45, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1

BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4:: @ 82578D4
	message BattleFrontier_BattleArenaBattleRoom_Text_257FBB
	waitmessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25792B
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257961
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_25779E
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4

BattleFrontier_BattleArenaBattleRoom_EventScript_25792B:: @ 825792B
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257961
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4

BattleFrontier_BattleArenaBattleRoom_EventScript_257961:: @ 8257961
	call BattleFrontier_BattleArenaBattleRoom_EventScript_242170
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C3D, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE4
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257FED, MSGBOX_DEFAULT
	closemessage
	addobject 7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF4
	waitmovement 0
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	switch VAR_TEMP_F
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257AA5
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F
	case 4, BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25801C, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C30
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25804E, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C3A
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258068, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F:: @ 8257A3F
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25810D, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257A5C
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB

BattleFrontier_BattleArenaBattleRoom_EventScript_257A5C:: @ 8257A5C
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF1
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25813F, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleArenaBattleRoom_Text_25819C
	waitmessage
	waitfanfare
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2581CF, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_257852

BattleFrontier_BattleArenaBattleRoom_EventScript_257AA5:: @ 8257AA5
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258213, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C30
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582A2, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C3A
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582BB, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8:: @ 8257AF8
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582F9, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257B15
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB

BattleFrontier_BattleArenaBattleRoom_EventScript_257B15:: @ 8257B15
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS
	special CallFrontierUtilFunc
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF1
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258323, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleArenaBattleRoom_Text_25835B
	waitmessage
	waitfanfare
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258383, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_257852

BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E:: @ 8257B5E
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C93, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C:: @ 8257B6C
FallarborTown_BattleTentBattleRoom_EventScript_257B6C:: @ 8257B6C
	closemessage
	setvar VAR_TEMP_2, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_ARENA
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_18
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_21
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9:: @ 8257BA9
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 1, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 2, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 3, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	applymovement 4, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	playse SE_BAN
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CB3, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_241EBA
	return

BattleFrontier_BattleArenaBattleRoom_Movement_257BE2: @ 8257BE2
	walk_right
	walk_right

BattleFrontier_BattleArenaBattleRoom_Movement_257BE4: @ 8257BE4
	walk_right

BattleFrontier_BattleArenaBattleRoom_Movement_257BE5: @ 8257BE5
	walk_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BE7: @ 8257BE7
	walk_left
	walk_left
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BEB: @ 8257BEB
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BED: @ 8257BED
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BEF: @ 8257BEF
	walk_left
	walk_left

BattleFrontier_BattleArenaBattleRoom_Movement_257BF1: @ 8257BF1
	walk_left

BattleFrontier_BattleArenaBattleRoom_Movement_257BF2: @ 8257BF2
	walk_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BF4: @ 8257BF4
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BFA: @ 8257BFA
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C02: @ 8257C02
	disable_jump_landing_ground_effect
	jump_in_place_down
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C05: @ 8257C05
	disable_jump_landing_ground_effect
	jump_in_place_up
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C08: @ 8257C08
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C0A: @ 8257C0A
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_MapScript2_257C0C: @ 8257C0C
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257C16
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_257C16:: @ 8257C16
	hideobjectat 8, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
	removeobject 7
	call BattleFrontier_BattleArenaBattleRoom_EventScript_24BCDC
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_24C773
	setvar VAR_TEMP_1, 1
	end

BattleFrontier_BattleArenaBattleRoom_Movement_257C30: @ 8257C30
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C3A: @ 8257C3A
	walk_down
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Text_257C3D: @ 8257C3D
	.string "REFEREE: TRAINER {PLAYER}!\n"
	.string "Step forward, please!$"

BattleFrontier_BattleArenaBattleRoom_Text_257C68: @ 8257C68
	.string "REFEREE: TRAINER {STR_VAR_1}!\n"
	.string "Step forward, please!$"

BattleFrontier_BattleArenaBattleRoom_Text_257C93: @ 8257C93
FallarborTown_BattleTentBattleRoom_Text_257C93: @ 8257C93
	.string "REFEREE: Set KO Tourney!\n"
	.string "Begin!$"

BattleFrontier_BattleArenaBattleRoom_Text_257CB3: @ 8257CB3
FallarborTown_BattleTentBattleRoom_Text_257CB3: @ 8257CB3
	.string "REFEREE: The winner is {PLAYER}!$"

BattleFrontier_BattleArenaBattleRoom_Text_257CCE: @ 8257CCE
FallarborTown_BattleTentBattleRoom_Text_257CCE: @ 8257CCE
	.string "REFEREE: The winner is {STR_VAR_1}!$"

BattleFrontier_BattleArenaBattleRoom_Text_257CE9: @ 8257CE9
FallarborTown_BattleTentBattleRoom_Text_257CE9: @ 8257CE9
	.string "Your POKéMON will be restored to\n"
	.string "full health.$"

BattleFrontier_BattleArenaBattleRoom_Text_257D17: @ 8257D17
FallarborTown_BattleTentBattleRoom_Text_257D17: @ 8257D17
	.string "Next up, your second opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257D50: @ 8257D50
FallarborTown_BattleTentBattleRoom_Text_257D50: @ 8257D50
	.string "Next up, your third opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257D88: @ 8257D88
	.string "Next up, your fourth opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257DC1: @ 8257DC1
	.string "Next up, your fifth opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257DF9: @ 8257DF9
	.string "Next up, your sixth opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257E31: @ 8257E31
	.string "Next up, your seventh opponent!\n"
	.string "Are you ready to move on?$"

BattleFrontier_BattleArenaBattleRoom_Text_257E6B: @ 8257E6B
FallarborTown_BattleTentBattleRoom_Text_257E6B: @ 8257E6B
	.string "Would you like to save the game and\n"
	.string "shut down now?$"

BattleFrontier_BattleArenaBattleRoom_Text_257E9E: @ 8257E9E
FallarborTown_BattleTentBattleRoom_Text_257E9E: @ 8257E9E
	.string "Would you like to retire from your\n"
	.string "Set KO Tourney challenge?$"

BattleFrontier_BattleArenaBattleRoom_Text_257EDB: @ 8257EDB
FallarborTown_BattleTentBattleRoom_Text_257EDB: @ 8257EDB
	.string "I am saving your game data.\n"
	.string "Please wait.$"

BattleFrontier_BattleArenaBattleRoom_Text_257F04: @ 8257F04
	.string "Would you like to record your last\n"
	.string "battle on your FRONTIER PASS?$"

BattleFrontier_BattleArenaBattleRoom_Text_257F45: @ 8257F45
	.string "My dear challenger!\p"
	.string "Your skill level is truly astounding!\p"
	.string "We now would like you to face our\n"
	.string "leader, the ARENA TYCOON!$"

BattleFrontier_BattleArenaBattleRoom_Text_257FBB: @ 8257FBB
	.string "A battle with the ARENA TYCOON!\n"
	.string "Are you prepared?$"

BattleFrontier_BattleArenaBattleRoom_Text_257FED: @ 8257FED
	.string "REFEREE: The ARENA TYCOON!\n"
	.string "Make way for GRETA!$"

BattleFrontier_BattleArenaBattleRoom_Text_25801C: @ 825801C
	.string "GRETA: Hey!\n"
	.string "Howdy!\p"
	.string "…Wait, are you the challenger?$"

BattleFrontier_BattleArenaBattleRoom_Text_25804E: @ 825804E
	.string "Is that right? Hmm…\n"
	.string "Hmhm…$"

BattleFrontier_BattleArenaBattleRoom_Text_258068: @ 8258068
	.string "I don't know how to say it, but…\n"
	.string "To put it bluntly, you look pretty weak.\l"
	.string "Are you sure you're up for me?\p"
	.string "Hmm…\p"
	.string "Well, all right!\n"
	.string "We'll take things easy to start with!$"

BattleFrontier_BattleArenaBattleRoom_Text_25810D: @ 825810D
	.string "Okay! Let's see you ignite my passion\n"
	.string "for battle!$"

BattleFrontier_BattleArenaBattleRoom_Text_25813F: @ 825813F
	.string "GRETA: Ow, wait a second!\n"
	.string "You are tough after all!\p"
	.string "I like you!\n"
	.string "Let's see your FRONTIER PASS.$"

BattleFrontier_BattleArenaBattleRoom_Text_25819C: @ 825819C
	.string "The Guts Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleArenaBattleRoom_Text_2581CF: @ 82581CF
	.string "Hmm…\p"
	.string "It's going to be fun the next time!\n"
	.string "I'm looking forward to it!$"

BattleFrontier_BattleArenaBattleRoom_Text_258213: @ 8258213
	.string "GRETA: Hey! Howdy!\n"
	.string "You finally won your way up to me!\p"
	.string "I was getting worried waiting for you!\n"
	.string "I was really looking forward to seeing\l"
	.string "you again!$"

BattleFrontier_BattleArenaBattleRoom_Text_2582A2: @ 82582A2
	.string "… … …\n"
	.string "So, are you ready?$"

BattleFrontier_BattleArenaBattleRoom_Text_2582BB: @ 82582BB
	.string "I won't allow a halfhearted effort!\n"
	.string "Be ready for a thrashing!$"

BattleFrontier_BattleArenaBattleRoom_Text_2582F9: @ 82582F9
	.string "Come on, REFEREE!\n"
	.string "Let's get this started!$"

BattleFrontier_BattleArenaBattleRoom_Text_258323: @ 8258323
	.string "GRETA: Gaaah! Blown away!\n"
	.string "Let's see your FRONTIER PASS!$"

BattleFrontier_BattleArenaBattleRoom_Text_25835B: @ 825835B
	.string "The Guts Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleArenaBattleRoom_Text_258383: @ 8258383
	.string "Arrrgh!\n"
	.string "This is so infuriating!\p"
	.string "If we ever battle again, I won't lose!\n"
	.string "Don't you forget it! Bye-bye!$"
