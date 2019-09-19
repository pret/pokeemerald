BattleFrontier_BattleFactoryPreBattleRoom_MapScripts:: @ 8259ABA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_MapScript2_259AEF
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_MapScript2_259AC5
	.byte 0

BattleFrontier_BattleFactoryPreBattleRoom_MapScript2_259AC5: @ 8259AC5
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259ACF
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259ACF:: @ 8259ACF
	setvar VAR_TEMP_1, 1
	compare VAR_0x8006, 1
	goto_if_ne BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259AEA
	setobjectxy 1, 8, 7
	turnobject 1, DIR_SOUTH

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259AEA:: @ 8259AEA
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryPreBattleRoom_MapScript2_259AEF: @ 8259AEF
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259AF9
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259AF9:: @ 8259AF9
	compare VAR_0x8006, 1
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259BA5
	setvar VAR_TEMP_0, 1
	applymovement 1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1AC
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A19A
	waitmovement 0
	compare VAR_0x8006, 2
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E69
	setvar VAR_0x8004, 13
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 12
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 14
	special CallBattleFactoryFunction
	setorcopyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, 15
	special CallBattleFactoryFunction
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E93
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A004
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A1C8, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8004, 8
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 6
	special CallBattleFactoryFunction
	waitstate

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74:: @ 8259B74
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB96, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23F2B7
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A17C
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A18B
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 255, 6, 11
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259BA5:: @ 8259BA5
	setvar VAR_0x8004, 9
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 16
	special CallBattleFactoryFunction
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A22D, MSGBOX_DEFAULT
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	setvar VAR_0x8004, 9
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C26
	playse 263
	waitse
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC15, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1BF
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC58, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1C3
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC89, MSGBOX_DEFAULT
	closemessage
	delay 16
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B9
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13:: @ 8259C13
	setvar VAR_0x8004, 9
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B9

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C26:: @ 8259C26
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E1D
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E24
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E2B
	compare VAR_RESULT, 4
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E32
	compare VAR_RESULT, 5
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E39
	compare VAR_RESULT, 6
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E40
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259CC6
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D98
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259CFC
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D38
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D66
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259CC6:: @ 8259CC6
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D98
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D38
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D66
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259CFC:: @ 8259CFC
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25ABD2
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D2E
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D2E:: @ 8259D2E
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23E8B4
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D38:: @ 8259D38
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A350, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E47
	case 127, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D66:: @ 8259D66
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A37A
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25AEF8
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D98:: @ 8259D98
	setvar VAR_0x8004, 12
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 14
	special CallBattleFactoryFunction
	setorcopyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, 15
	special CallBattleFactoryFunction
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E93
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A004
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB2E, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259DF2
	case 127, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259DF2:: @ 8259DF2
	fadescreen 1
	setvar VAR_0x8004, 7
	special CallBattleFactoryFunction
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74
	setvar VAR_0x8004, 8
	special CallBattleFactoryFunction
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB6C, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E1D:: @ 8259E1D
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A263
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E24:: @ 8259E24
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A289
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E2B:: @ 8259E2B
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2AF
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E32:: @ 8259E32
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2D5
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E39:: @ 8259E39
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2FB
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E40:: @ 8259E40
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25A321
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E47:: @ 8259E47
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25ABAE
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E69:: @ 8259E69
	special SavePlayerParty
	setvar VAR_0x8004, 10
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	special CalculatePlayerPartyCount
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259C13

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259E93:: @ 8259E93
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A3B4, MSGBOX_DEFAULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F62
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F6B
	compare VAR_0x8005, 2
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F74
	compare VAR_0x8005, 3
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F7D
	compare VAR_0x8005, 4
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F86
	compare VAR_0x8005, 5
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F8F
	compare VAR_0x8005, 6
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F98
	compare VAR_0x8005, 7
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FA1
	compare VAR_0x8005, 8
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FAA
	compare VAR_0x8005, 10
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FB3
	compare VAR_0x8005, 11
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FBC
	compare VAR_0x8005, 12
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FC5
	compare VAR_0x8005, 13
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FCE
	compare VAR_0x8005, 14
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FD7
	compare VAR_0x8005, 15
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FE0
	compare VAR_0x8005, 16
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FE9
	compare VAR_0x8005, 17
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FF2
	compare VAR_0x8005, 18
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FFB
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F62:: @ 8259F62
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A3F8, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F6B:: @ 8259F6B
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A597, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F74:: @ 8259F74
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A66B, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F7D:: @ 8259F7D
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A5DF, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F86:: @ 8259F86
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A625, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F8F:: @ 8259F8F
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A73B, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259F98:: @ 8259F98
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A6F8, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FA1:: @ 8259FA1
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A77F, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FAA:: @ 8259FAA
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A84E, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FB3:: @ 8259FB3
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A43E, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FBC:: @ 8259FBC
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A482, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FC5:: @ 8259FC5
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A50F, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FCE:: @ 8259FCE
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A4C7, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FD7:: @ 8259FD7
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A6B1, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FE0:: @ 8259FE0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A554, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FE9:: @ 8259FE9
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A7C4, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FF2:: @ 8259FF2
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A80A, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259FFB:: @ 8259FFB
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25A893, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A004:: @ 825A004
	compare VAR_0x8006, 0
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A068
	compare VAR_0x8006, 1
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A071
	compare VAR_0x8006, 2
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A07A
	compare VAR_0x8006, 3
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A083
	compare VAR_0x8006, 4
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A08C
	compare VAR_0x8006, 5
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A095
	compare VAR_0x8006, 6
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A09E
	compare VAR_0x8006, 7
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0A7
	compare VAR_0x8006, 8
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B0
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A068:: @ 825A068
	msgbox Text_StyleUnrestrained, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A071:: @ 825A071
	msgbox Text_StyleTotalPreparation, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A07A:: @ 825A07A
	msgbox Text_StyleSlowAndSteady, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A083:: @ 825A083
	msgbox Text_StyleEndurance, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A08C:: @ 825A08C
	msgbox Text_StyleHighRisk, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A095:: @ 825A095
	msgbox Text_StyleWeakenFoe, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A09E:: @ 825A09E
	msgbox Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0A7:: @ 825A0A7
	msgbox Text_StyleDependsOnFlow, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B0:: @ 825A0B0
	msgbox Text_StyleFlexible, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B9:: @ 825A0B9
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_25AD20
	waitmessage
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A110
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A146
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259CFC
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D38
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D66
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B9

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A110:: @ 825A110
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A146
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D38
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259D66
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A0B9

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A146:: @ 825A146
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AD61, MSGBOX_DEFAULT
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB2E, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259DF2
	case 127, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_259B74

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A17C:: @ 825A17C
	applymovement 1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1B3
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1A0
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25A18B:: @ 825A18B
	applymovement 1, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1B9
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1A6
	return

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A19A: @ 825A19A
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1A0: @ 825A1A0
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1A6: @ 825A1A6
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1AC: @ 825A1AC
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1B3: @ 825A1B3
	walk_left
	walk_left
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1B9: @ 825A1B9
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1BF: @ 825A1BF
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_25A1C3: @ 825A1C3
	walk_right
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A1C8: @ 825A1C8
SlateportCity_BattleTentCorridor_Text_25A1C8: @ 825A1C8
	.string "First, we will hold your POKéMON for\n"
	.string "safekeeping.\p"
	.string "You may then choose from our\n"
	.string "selection of POKéMON.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A22D: @ 825A22D
SlateportCity_BattleTentCorridor_Text_25A22D: @ 825A22D
	.string "Thank you for competing!\n"
	.string "Let us restore your POKéMON!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A263: @ 825A263
SlateportCity_BattleTentCorridor_Text_25A263: @ 825A263
	.string "The 2nd match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A289: @ 825A289
SlateportCity_BattleTentCorridor_Text_25A289: @ 825A289
	.string "The 3rd match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2AF: @ 825A2AF
	.string "The 4th match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2D5: @ 825A2D5
	.string "The 5th match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A2FB: @ 825A2FB
	.string "The 6th match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A321: @ 825A321
	.string "Finally, the 7th match is next!\n"
	.string "Are you ready?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A350: @ 825A350
SlateportCity_BattleTentCorridor_Text_25A350: @ 825A350
	.string "Would you like to save and quit\n"
	.string "the game?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A37A: @ 825A37A
SlateportCity_BattleTentCorridor_Text_25A37A: @ 825A37A
	.string "Would you like to retire from your\n"
	.string "Battle Swap challenge?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A3B4: @ 825A3B4
	.string "I've conducted a little investigation\n"
	.string "about your upcoming opponent.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A3F8: @ 825A3F8
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the NORMAL type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A43E: @ 825A43E
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FIRE type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A482: @ 825A482
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the WATER type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A4C7: @ 825A4C7
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ELECTRIC type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A50F: @ 825A50F
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GRASS type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A554: @ 825A554
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ICE type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A597: @ 825A597
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FIGHTING type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A5DF: @ 825A5DF
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the POISON type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A625: @ 825A625
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GROUND type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A66B: @ 825A66B
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FLYING type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A6B1: @ 825A6B1
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the PSYCHIC type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A6F8: @ 825A6F8
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the BUG type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A73B: @ 825A73B
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ROCK type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A77F: @ 825A77F
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GHOST type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A7C4: @ 825A7C4
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the DRAGON type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A80A: @ 825A80A
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the DARK type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A84E: @ 825A84E
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the STEEL type.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25A893: @ 825A893
	.string "The TRAINER appears to have no clear\n"
	.string "favorites when it comes to type.$"

Text_StyleSlowAndSteady: @ 825A8D9
	.string "The favorite battle style appears to\n"
	.string "be slow and steady.$"

Text_StyleEndurance: @ 825A912
	.string "The favorite battle style appears to\n"
	.string "be one of endurance.$"

Text_StyleHighRisk: @ 825A94C
	.string "The favorite battle style appears to\n"
	.string "be high risk, high return.$"

Text_StyleDependsOnFlow: @ 825A98C
	.string "The favorite battle style appears to\n"
	.string "depend on the battle's flow.$"

Text_StyleTotalPreparation: @ 825A9CE
	.string "The favorite battle style appears to\n"
	.string "be one based on total preparation.$"

Text_StyleWeakenFoe: @ 825AA16
	.string "The favorite battle style appears\n"
	.string "to be weakening the foe to start.$"

Text_StyleFlexible: @ 825AA5A
	.string "The favorite battle style appears to\n"
	.string "be flexibly adaptable to the situation.$"

Text_StyleImpossibleToPredict: @ 825AAA7
	.string "The favorite battle style appears to\n"
	.string "be impossible to predict.$"

Text_StyleUnrestrained: @ 825AAE6
	.string "The favorite battle style appears to\n"
	.string "be free-spirited and unrestrained.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB2E: @ 825AB2E
SlateportCity_BattleTentCorridor_Text_25AB2E: @ 825AB2E
	.string "Before starting the battle, would you\n"
	.string "like to swap a POKéMON?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB6C: @ 825AB6C
SlateportCity_BattleTentCorridor_Text_25AB6C: @ 825AB6C
	.string "Thank you!\n"
	.string "Your POKéMON swap is complete.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AB96: @ 825AB96
SlateportCity_BattleTentCorridor_Text_25AB96: @ 825AB96
	.string "Right this way, please!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25ABAE: @ 825ABAE
SlateportCity_BattleTentCorridor_Text_25ABAE: @ 825ABAE
	.string "I am saving your data.\n"
	.string "Please wait.$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25ABD2: @ 825ABD2
	.string "Would you like to record your latest\n"
	.string "battle on your FRONTIER PASS?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC15: @ 825AC15
	.string "Excuse me! Excuse me, please!\n"
	.string "May I get you to wait a few moments?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC58: @ 825AC58
	.string "…Uh-huh? What?! …Whoa!\n"
	.string "Understood, sir! Will do!$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AC89: @ 825AC89
	.string "Oh, my…\n"
	.string "Sorry to keep you waiting!\p"
	.string "I have a message from this facility's\n"
	.string "boss, the FACTORY HEAD.\p"
	.string "He says, “We're going to do it!\n"
	.string "Come here right now!”$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AD20: @ 825AD20
	.string "The FACTORY HEAD is demanding you.\n"
	.string "Are you prepared to face him?$"

BattleFrontier_BattleFactoryPreBattleRoom_Text_25AD61: @ 825AD61
	.string "I'm terribly sorry, but I can't tell you\n"
	.string "anything about the FACTORY HEAD.$"
