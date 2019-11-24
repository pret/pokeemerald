VerdanturfTown_BattleTentBattleRoom_MapScripts:: @ 82022FA
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentBattleRoom_MapScript2_20233E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentBattleRoom_MapScript2_202541
	.byte 0

VerdanturfTown_BattleTentBattleRoom_OnTransition: @ 820230A
	call VerdanturfTown_BattleTentBattleRoom_EventScript_202310
	end

VerdanturfTown_BattleTentBattleRoom_EventScript_202310:: @ 8202310
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_202328
	compare VAR_RESULT, FEMALE
	goto_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_202333
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_202328:: @ 8202328
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_202333:: @ 8202333
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

VerdanturfTown_BattleTentBattleRoom_MapScript2_20233E: @ 820233E
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_202348
	.2byte 0

VerdanturfTown_BattleTentBattleRoom_EventScript_202348:: @ 8202348
	showobjectat 1, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
	applymovement 1, VerdanturfTown_BattleTentBattleRoom_Movement_202575
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 0
	goto_if_ne VerdanturfTown_BattleTentBattleRoom_EventScript_20243C

VerdanturfTown_BattleTentBattleRoom_EventScript_20236F:: @ 820236F
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_CHOOSE_TRAINER
	special CallBattleTowerFunc
	addobject 2
	applymovement 2, VerdanturfTown_BattleTentBattleRoom_Movement_20257B
	waitmovement 0
	setvar VAR_0x8004, 4
	special CallVerdanturfTentFunction
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call VerdanturfTown_BattleTentBattleRoom_EventScript_24FDF7
	switch VAR_RESULT
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_2023C8

VerdanturfTown_BattleTentBattleRoom_EventScript_2023AA:: @ 82023AA
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	special LoadPlayerParty
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
	waitstate

VerdanturfTown_BattleTentBattleRoom_EventScript_2023C8:: @ 82023C8
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 3, VerdanturfTown_BattleTentBattleRoom_EventScript_202501
	applymovement 2, VerdanturfTown_BattleTentBattleRoom_Movement_202581
	waitmovement 0
	removeobject 2
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox VerdanturfTown_BattleTentBattleRoom_Text_24FF00, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

VerdanturfTown_BattleTentBattleRoom_EventScript_20243C:: @ 820243C
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 1
	call_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_202565
	compare VAR_RESULT, 2
	call_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_20256C
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_2024EA
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_20248A
	case 2, VerdanturfTown_BattleTentBattleRoom_EventScript_2024B8

VerdanturfTown_BattleTentBattleRoom_EventScript_20248A:: @ 820248A
	msgbox VerdanturfTown_BattleTentBattleRoom_Text_250030, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, VerdanturfTown_BattleTentBattleRoom_EventScript_20243C
	case YES, VerdanturfTown_BattleTentBattleRoom_EventScript_20251F
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_20243C

VerdanturfTown_BattleTentBattleRoom_EventScript_2024B8:: @ 82024B8
	message VerdanturfTown_BattleTentBattleRoom_Text_25005A
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_20243C
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_2023AA
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_20243C

VerdanturfTown_BattleTentBattleRoom_EventScript_2024EA:: @ 82024EA
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	closemessage
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_20236F

VerdanturfTown_BattleTentBattleRoom_EventScript_202501:: @ 8202501
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	special LoadPlayerParty
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
	waitstate

VerdanturfTown_BattleTentBattleRoom_EventScript_20251F:: @ 820251F
	message VerdanturfTown_BattleTentBattleRoom_Text_25007E
	waitmessage
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 2
	special CallVerdanturfTentFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	frontier_reset
	end

VerdanturfTown_BattleTentBattleRoom_MapScript2_202541: @ 8202541
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_20254B
	.2byte 0

VerdanturfTown_BattleTentBattleRoom_EventScript_20254B:: @ 820254B
	hideobjectat 1, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
	call VerdanturfTown_BattleTentBattleRoom_EventScript_202310
	setvar VAR_TEMP_1, 1
	applymovement EVENT_OBJ_ID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_202573
	removeobject 2
	end

VerdanturfTown_BattleTentBattleRoom_EventScript_202565:: @ 8202565
	message VerdanturfTown_BattleTentBattleRoom_Text_24FF28
	waitmessage
	return

VerdanturfTown_BattleTentBattleRoom_EventScript_20256C:: @ 820256C
	message VerdanturfTown_BattleTentBattleRoom_Text_24FF54
	waitmessage
	return

VerdanturfTown_BattleTentBattleRoom_Movement_202573: @ 8202573
	set_invisible
	step_end

VerdanturfTown_BattleTentBattleRoom_Movement_202575: @ 8202575
	set_visible
	walk_up
	walk_up
	walk_up
	face_right
	step_end

VerdanturfTown_BattleTentBattleRoom_Movement_20257B: @ 820257B
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

VerdanturfTown_BattleTentBattleRoom_Movement_202581: @ 8202581
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

