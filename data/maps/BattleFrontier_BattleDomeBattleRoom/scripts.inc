BattleFrontier_BattleDomeBattleRoom_MapScripts:: @ 824BC9C
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_MapScript1_24BCB1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_MapScript2_24BD00
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_MapScript2_24C481
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_MapScript1_24C4F0
	.byte 0

BattleFrontier_BattleDomeBattleRoom_MapScript1_24BCB1: @ 824BCB1
	setvar VAR_0x8004, 10
	special CallBattleDomeFunction
	frontier_get FRONTIER_DATA_BATTLE_NUM
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C919
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx:: @ 824BCDC
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale:: @ 824BCF4
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale:: @ 824BCFA
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_MapScript2_24BD00: @ 824BD00
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24BD0A
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_24BD0A:: @ 824BD0A
	lockall
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C938
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24BFD5
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24C970, MSGBOX_DEFAULT
	closemessage
	showobjectat 13, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
	compare VAR_TEMP_F, 3
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24BD4E
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24BD5A

BattleFrontier_BattleDomeBattleRoom_EventScript_24BD4E:: @ 824BD4E
	applymovement 13, BattleFrontier_BattleDomeBattleRoom_Movement_24C775
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BD61

BattleFrontier_BattleDomeBattleRoom_EventScript_24BD5A:: @ 824BD5A
	applymovement 13, BattleFrontier_BattleDomeBattleRoom_Movement_24C77F

BattleFrontier_BattleDomeBattleRoom_EventScript_24BD61:: @ 824BD61
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitmovement 0
	compare VAR_TEMP_F, 3
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24BD82
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24C1CB

BattleFrontier_BattleDomeBattleRoom_EventScript_24BD82:: @ 824BD82
	setvar VAR_0x8004, 4
	special CallBattleDomeFunction
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24C990, MSGBOX_DEFAULT
	closemessage
	applymovement 13, BattleFrontier_BattleDomeBattleRoom_Movement_24C77B
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C789
	waitmovement 0
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_7
	setvar VAR_0x8005, 0
	special CallBattleTowerFunc
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 5
	special CallBattleDomeFunction
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C440
	setvar VAR_TEMP_2, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24BEE0
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24BE4F
	case 9, BattleFrontier_BattleDomeBattleRoom_EventScript_24BE4F
	setvar VAR_TEMP_2, 1

BattleFrontier_BattleDomeBattleRoom_EventScript_24BDF7:: @ 824BDF7
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CA86, MSGBOX_DEFAULT
	closemessage
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	delay 60
	applymovement 9, BattleFrontier_BattleDomeBattleRoom_Movement_24C964
	waitmovement 0
	applymovement 1, BattleFrontier_BattleDomeBattleRoom_Movement_24C969
	waitmovement 0
	delay 180
	applymovement 9, BattleFrontier_BattleDomeBattleRoom_Movement_24C96B
	waitmovement 0
	compare VAR_TEMP_2, 2
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BE4F
	setvar VAR_0x8004, 19
	special CallBattleDomeFunction
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24BEE0

BattleFrontier_BattleDomeBattleRoom_EventScript_24BE4F:: @ 824BE4F
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	setvar VAR_0x8004, 4
	special CallBattleDomeFunction
	compare VAR_TEMP_2, 0
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BEB1
	compare VAR_TEMP_2, 1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BEC5
	compare VAR_TEMP_2, 2
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BED9
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	delay 60

BattleFrontier_BattleDomeBattleRoom_EventScript_24BE8D:: @ 824BE8D
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 2
	special CallBattleDomeFunction

BattleFrontier_BattleDomePreBattleRoom_EventScript_24BE9A:: @ 824BE9A
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24C8F5
@ 	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_24C8F5

BattleFrontier_BattleDomeBattleRoom_EventScript_24BEB1:: @ 824BEB1
	frontier_gettrainername 1
	message BattleFrontier_BattleDomeBattleRoom_Text_24C9E1
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24BEC5:: @ 824BEC5
	frontier_gettrainername 0
	message BattleFrontier_BattleDomeBattleRoom_Text_24CB34
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24BED9:: @ 824BED9
	message BattleFrontier_BattleDomeBattleRoom_Text_24D6BE
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24BEE0:: @ 824BEE0
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	compare VAR_TEMP_2, 0
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BFC3
	compare VAR_TEMP_2, 1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BFCC
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	delay 60
	setvar VAR_0x8004, 3
	special CallBattleDomeFunction
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 1
	special CallBattleDomeFunction
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 4, BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62
	setvar VAR_0x8006, 1
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 3
	waitstate

BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62:: @ 824BF62
	applymovement 13, BattleFrontier_BattleDomeBattleRoom_Movement_24C77D
	waitmovement 0
	frontier_get FRONTIER_DATA_LVL_MODE
	switch VAR_RESULT
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_24BF96
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CA04, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BF9E

BattleFrontier_BattleDomeBattleRoom_EventScript_24BF96:: @ 824BF96
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CA44, MSGBOX_DEFAULT

BattleFrontier_BattleDomeBattleRoom_EventScript_24BF9E:: @ 824BF9E
	special sub_8175280
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	delay 60
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24C8F5

BattleFrontier_BattleDomeBattleRoom_EventScript_24BFC3:: @ 824BFC3
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24C9BE, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24BFCC:: @ 824BFCC
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CB9D, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24BFD5:: @ 824BFD5
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 6
	special CallBattleDomeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C023
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallBattleDomeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C076
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special CallBattleDomeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C16A
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24C0C9
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C023:: @ 824C023
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24C05A
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24C061
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C068
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C06F
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C05A:: @ 824C05A
	message BattleFrontier_BattleDomeBattleRoom_Text_24CC06
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C061:: @ 824C061
	message BattleFrontier_BattleDomeBattleRoom_Text_24CC1C
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C068:: @ 824C068
	message BattleFrontier_BattleDomeBattleRoom_Text_24CC2E
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C06F:: @ 824C06F
	message BattleFrontier_BattleDomeBattleRoom_Text_24CC5B
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C076:: @ 824C076
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24C0AD
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24C0B4
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C0BB
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C0C2
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C0AD:: @ 824C0AD
	message BattleFrontier_BattleDomeBattleRoom_Text_24CC99
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C0B4:: @ 824C0B4
	message BattleFrontier_BattleDomeBattleRoom_Text_24CCC5
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C0BB:: @ 824C0BB
	message BattleFrontier_BattleDomeBattleRoom_Text_24CCFD
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C0C2:: @ 824C0C2
	message BattleFrontier_BattleDomeBattleRoom_Text_24CD33
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C0C9:: @ 824C0C9
	compare VAR_TEMP_F, 3
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24C105
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_24C158
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_24C161
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_24C158
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_24C161

BattleFrontier_BattleDomeBattleRoom_EventScript_24C105:: @ 824C105
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24C13C
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24C143
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C14A
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C151
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C13C:: @ 824C13C
	message BattleFrontier_BattleDomeBattleRoom_Text_24CD72
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C143:: @ 824C143
	message BattleFrontier_BattleDomeBattleRoom_Text_24CD8C
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C14A:: @ 824C14A
	message BattleFrontier_BattleDomeBattleRoom_Text_24CDB3
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C151:: @ 824C151
	message BattleFrontier_BattleDomeBattleRoom_Text_24CDDE
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C158:: @ 824C158
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CEBE, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C161:: @ 824C161
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D232, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C16A:: @ 824C16A
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1A1
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1A8
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1AF
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1B6
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1A1:: @ 824C1A1
	message BattleFrontier_BattleDomeBattleRoom_Text_24CE10
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1A8:: @ 824C1A8
	message BattleFrontier_BattleDomeBattleRoom_Text_24CE33
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1AF:: @ 824C1AF
	message BattleFrontier_BattleDomeBattleRoom_Text_24CE57
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1B6:: @ 824C1B6
	message BattleFrontier_BattleDomeBattleRoom_Text_24CE94
	waitmessage
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1BD:: @ 824C1BD
	frontier_get FRONTIER_DATA_BATTLE_NUM
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1CB:: @ 824C1CB
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1FC
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_24C209
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_24C1FC
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_24C209

BattleFrontier_BattleDomeBattleRoom_EventScript_24C1FC:: @ 824C1FC
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CEDE, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24C211

BattleFrontier_BattleDomeBattleRoom_EventScript_24C209:: @ 824C209
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D26C, MSGBOX_DEFAULT

BattleFrontier_BattleDomeBattleRoom_EventScript_24C211:: @ 824C211
	closemessage
	applymovement 2, BattleFrontier_BattleDomeBattleRoom_Movement_24C94B
	applymovement 1, BattleFrontier_BattleDomeBattleRoom_Movement_24C7F9
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C78E
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	waitmovement 0
	message BattleFrontier_BattleDomeBattleRoom_Text_24CF7A
	waitmessage
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	switch VAR_TEMP_E
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_24C346
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_24C2B9
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_24C373
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24C2B9
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24CFAE, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleDomeBattleRoom_EventScript_24C2B9:: @ 824C2B9
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D0D9, MSGBOX_DEFAULT
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C400
	switch VAR_RESULT
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C420
	case 9, BattleFrontier_BattleDomeBattleRoom_EventScript_24C420
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C436
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D0F6, MSGBOX_DEFAULT
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 1
	special CallBattleDomeFunction
	frontier_getsymbols
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62
	closemessage
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C82B
	waitmovement 0
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D172, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleDomeBattleRoom_Text_24D1AA
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D1E0, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62

BattleFrontier_BattleDomeBattleRoom_EventScript_24C346:: @ 824C346
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24C373
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D319, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleDomeBattleRoom_EventScript_24C373:: @ 824C373
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D43E, MSGBOX_DEFAULT
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C400
	switch VAR_RESULT
	case 2, BattleFrontier_BattleDomeBattleRoom_EventScript_24C420
	case 9, BattleFrontier_BattleDomeBattleRoom_EventScript_24C420
	case 3, BattleFrontier_BattleDomeBattleRoom_EventScript_24C436
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D0F6, MSGBOX_DEFAULT
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 1
	special CallBattleDomeFunction
	frontier_getsymbols
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62
	closemessage
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C82B
	waitmovement 0
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D47F, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleDomeBattleRoom_Text_24D522
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D54D, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BF62

BattleFrontier_BattleDomeBattleRoom_EventScript_24C400:: @ 824C400
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D677, MSGBOX_DEFAULT
	closemessage
	applymovement 13, BattleFrontier_BattleDomeBattleRoom_Movement_24C787
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C829
	waitmovement 0
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C440
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C420:: @ 824C420
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_24D127, MSGBOX_DEFAULT
	playse SE_W227B
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E
	waitse
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BE8D

BattleFrontier_BattleDomeBattleRoom_EventScript_24C436:: @ 824C436
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_24BDF7

BattleFrontier_BattleDomeBattleRoom_EventScript_24C440:: @ 824C440
	frontier_set FRONTIER_DATA_6, 0
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
	setvar VAR_0x8005, 0
	setvar VAR_TEMP_9, 1
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, 17
	special CallBattleDomeFunction
	special HealPlayerParty
	setvar VAR_0x8004, 16
	special CallBattleDomeFunction
	return

BattleFrontier_BattleDomeBattleRoom_MapScript2_24C481: @ 824C481
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_24C48B
	.2byte 0

BattleFrontier_BattleDomeBattleRoom_EventScript_24C48B:: @ 824C48B
	hideobjectat 13, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C502
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
	setvar VAR_TEMP_1, 1
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 3
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_24C4EF
	frontier_getbrainstatus
	copyvar VAR_TEMP_E, VAR_RESULT
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C4EF
	call BattleFrontier_EventScript_SetBrainObjectGfx
	setobjectxyperm 15, 13, 9
	removeobject 15
	addobject 15
	applymovement 15, BattleFrontier_BattleDomeBattleRoom_Movement_24C78B

BattleFrontier_BattleDomeBattleRoom_EventScript_24C4EF:: @ 824C4EF
	end

BattleFrontier_BattleDomeBattleRoom_MapScript1_24C4F0: @ 824C4F0
	compare VAR_TEMP_9, 1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C4FC
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_24C4FC:: @ 824C4FC
	call BattleFrontier_BattleDomeBattleRoom_EventScript_24C502
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C502:: @ 824C502
	compare VAR_TEMP_F, 0
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C52F
	compare VAR_TEMP_F, 1
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C530
	compare VAR_TEMP_F, 2
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C594
	compare VAR_TEMP_F, 3
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_24C652
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C52F:: @ 824C52F
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C530:: @ 824C530
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C594:: @ 824C594
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_5, 31, 8, 2, 3, 1
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C652:: @ 824C652
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 0, 2, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_BEAUTY, 2, 15, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAN_5, 3, 5, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 5, 7, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_3, 8, 10, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_BEAUTY, 12, 14, 0, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAN_5, 13, 15, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_HIKER, 14, 12, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_3, 18, 6, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAN_2, 21, 10, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_GENTLEMAN, 24, 14, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_FAT_MAN, 27, 3, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_WOMAN_5, 31, 8, 2, 3, DIR_SOUTH
	return

BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible: @ 824C773
	set_invisible
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C775: @ 824C775
	set_visible
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right

BattleFrontier_BattleDomeBattleRoom_Movement_24C77B: @ 824C77B
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C77D: @ 824C77D
	walk_up
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C77F: @ 824C77F
	set_visible
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C787: @ 824C787
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C789: @ 824C789
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C78B: @ 824C78B
	face_up
	set_invisible
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C78E: @ 824C78E
	set_visible
	walk_up
	walk_up
	walk_up
	face_left
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_left
	delay_16
	walk_fast_up
	walk_fast_up
	face_left
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_left
	jump_2_left
	unlock_facing_direction
	face_up
	lock_facing_direction
	jump_2_left
	jump_2_left
	unlock_facing_direction
	face_right
	lock_facing_direction
	jump_2_left
	unlock_facing_direction
	face_down
	delay_2
	face_left
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	lock_facing_direction
	walk_right
	walk_slow_right
	walk_right
	walk_slow_right
	unlock_facing_direction
	face_up
	delay_16
	jump_in_place_up
	jump_in_place_up
	delay_16
	walk_right
	walk_right
	walk_right
	jump_in_place_up
	delay_16
	walk_right
	walk_down
	walk_down
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_4
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C7F9: @ 824C7F9
	delay_16
	delay_16
	walk_left
	walk_left
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C829: @ 824C829
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C82B: @ 824C82B
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_EventScript_24C82E:: @ 824C82E
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 24, DIR_EAST
	turnvobject 26, DIR_EAST
	turnvobject 28, DIR_EAST
	turnvobject 30, DIR_EAST
	delay 20
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_SOUTH
	turnvobject 28, DIR_SOUTH
	turnvobject 30, DIR_SOUTH
	delay 20
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_EAST
	turnvobject 23, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 31, DIR_WEST
	delay 20
	turnvobject 1, DIR_SOUTH
	turnvobject 3, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 9, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 17, DIR_SOUTH
	turnvobject 19, DIR_SOUTH
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 25, DIR_SOUTH
	turnvobject 27, DIR_SOUTH
	turnvobject 31, DIR_SOUTH
	delay 20
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C8F5:: @ 824C8F5
BattleFrontier_BattleDomePreBattleRoom_EventScript_24C8F5:: @ 824C8F5
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_24C90F
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 5, 11
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_24C90F:: @ 824C90F
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 17, 11
	waitstate
	end

BattleFrontier_BattleDomeBattleRoom_EventScript_24C919:: @ 824C919
	random 2
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_TEMP_D, 0
	goto_if_eq Common_EventScript_NopReturn
	setobjectxyperm 6, 2, 0
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_24C938:: @ 824C938
	compare VAR_TEMP_D, 0
	goto_if_eq Common_EventScript_NopReturn
	applymovement 6, BattleFrontier_BattleDomeBattleRoom_Movement_24C95E
	return

BattleFrontier_BattleDomeBattleRoom_Movement_24C94B: @ 824C94B
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_down
	delay_4
	jump_in_place_down
	enable_jump_landing_ground_effect
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C95E: @ 824C95E
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C964: @ 824C964
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C969: @ 824C969
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_24C96B: @ 824C96B
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleDomeBattleRoom_Text_24C970: @ 824C970
	.string "{PLAYER} has entered the BATTLE DOME!$"

BattleFrontier_BattleDomeBattleRoom_Text_24C990: @ 824C990
	.string "{STR_VAR_1}\n"
	.string "match!\p"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
	.string "Let the battle begin!$"

BattleFrontier_BattleDomeBattleRoom_Text_24C9BE: @ 824C9BE
	.string "{PLAYER} is the winner!\n"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24C9E1: @ 824C9E1
	.string "{STR_VAR_2} is the winner!\n"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CA04: @ 824CA04
	.string "{PLAYER} is the Level 50\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CA44: @ 824CA44
	.string "{PLAYER} is the Open Level\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CA86: @ 824CA86
	.string "What an unbelievable finish!\n"
	.string "We have a double knockout!\p"
	.string "In this event, the Battle Tournament\n"
	.string "rules call for a REFEREE'S decision.\p"
	.string "Please wait while the judging\n"
	.string "is under way.$"

BattleFrontier_BattleDomeBattleRoom_Text_24CB34: @ 824CB34
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is {STR_VAR_1}!\l"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CB9D: @ 824CB9D
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is {PLAYER}!\l"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CC06: @ 824CC06
	.string "The bright new hope!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CC1C: @ 824CC1C
	.string "The rising star!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CC2E: @ 824CC2E
	.string "Will this TRAINER race to\n"
	.string "the championship?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CC5B: @ 824CC5B
	.string "Can the feat of a championship\n"
	.string "on the first try be achieved?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CC99: @ 824CC99
	.string "Can the loss of the last match\n"
	.string "be avenged?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CCC5: @ 824CCC5
	.string "The TRAINER is on fire for\n"
	.string "the first championship try!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CCFD: @ 824CCFD
	.string "A win here means this TRAINER\n"
	.string "advances to the final!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CD33: @ 824CD33
	.string "Will the long-held dream of\n"
	.string "a championship finally come true?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CD72: @ 824CD72
	.string "The invincible champion!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CD8C: @ 824CD8C
	.string "Can anyone hope to beat this\n"
	.string "TRAINER?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CDB3: @ 824CDB3
	.string "Do battles exist solely for\n"
	.string "this TRAINER?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CDDE: @ 824CDDE
	.string "The current champion aiming to\n"
	.string "retain the title!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CE10: @ 824CE10
	.string "The former champion has returned!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CE33: @ 824CE33
	.string "The former toughness has returned!\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CE57: @ 824CE57
	.string "Will this TRAINER do as expected\n"
	.string "and advance to the finals?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CE94: @ 824CE94
	.string "Will the former champ regain\n"
	.string "lost glory?\p"
	.string "$"

BattleFrontier_BattleDomeBattleRoom_Text_24CEBE: @ 824CEBE
	.string "Feel the glow of a true master!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CEDE: @ 824CEDE
	.string "And now… The TRAINER standing in\n"
	.string "{PLAYER}'s record-setting path…\p"
	.string "Yes! The one and only!\n"
	.string "The BATTLE DOME COMMISSIONER!\l"
	.string "Our very own DOME ACE!\l"
	.string "Make way for TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CF7A: @ 824CF7A
	.string "Spectators: TUCKER! TUCKER!\n"
	.string "TUCKER! TUCKER! TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_24CFAE: @ 824CFAE
	.string "TUCKER: Ahahah!\p"
	.string "Do you hear it? This crowd!\n"
	.string "They're all itching to see our match!\p"
	.string "Ahahah!\p"
	.string "I bet you're twitching all over from\n"
	.string "the tension of getting to battle me!\p"
	.string "But don't you worry about a thing!\p"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
	.string "in my brilliant glow!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D0D9: @ 824D0D9
	.string "Your strategy!\n"
	.string "Let's see it!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D0F6: @ 824D0F6
	.string "Unbelievable! It's incredible!\n"
	.string "The victor is {PLAYER}!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D127: @ 824D127
	.string "The winner is TUCKER!\n"
	.string "The DOME ACE has prevailed!\p"
	.string "Congratulations, TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D172: @ 824D172
	.string "TUCKER: Rules are rules!\n"
	.string "Let me see your FRONTIER PASS.$"

BattleFrontier_BattleDomeBattleRoom_Text_24D1AA: @ 824D1AA
	.string "The Tactics Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D1E0: @ 824D1E0
	.string "… … … … … …\p"
	.string "I sorely underestimated you. I won't\n"
	.string "make the same mistake next time…$"

BattleFrontier_BattleDomeBattleRoom_Text_24D232: @ 824D232
	.string "Can the win streak be stretched?\n"
	.string "The confidence is there!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D26C: @ 824D26C
	.string "Ladies and gentlemen!\n"
	.string "Boys, girls, and POKéMON!\p"
	.string "Finally!\n"
	.string "Finally, the legend has returned!\p"
	.string "Yes, the name of that legend!\n"
	.string "Our very own DOME ACE!\l"
	.string "It's none other than TUCKER!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D319: @ 824D319
	.string "TUCKER: Ah…\n"
	.string "The pummeling roar of the crowd…\l"
	.string "Their furnace-like heat of excitement…\l"
	.string "This is a wonderful place…\p"
	.string "To the crowd, I am the DOME ACE…\n"
	.string "I represent their hopes and dreams…\l"
	.string "I must never fade from their sight…\p"
	.string "I must burn!\n"
	.string "Brighter and more brilliant!\l"
	.string "I must light all that gather here!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D43E: @ 824D43E
	.string "I will unleash all the power that\n"
	.string "I possess! Right here and now!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D47F: @ 824D47F
	.string "TUCKER: You're genuinely fantastic!\p"
	.string "Never before! I haven't ever lost in the\n"
	.string "times I've had to unleash my power.\p"
	.string "Yes, quite fantastic!\n"
	.string "Your FRONTIER PASS, please?$"

BattleFrontier_BattleDomeBattleRoom_Text_24D522: @ 824D522
	.string "The Tactics Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D54D: @ 824D54D
	.string "You're strong, but above all,\n"
	.string "you have a unique charm!\p"
	.string "In you, I see a definite potential for\n"
	.string "a superstar like me.\p"
	.string "I will very much look forward to\n"
	.string "our next encounter!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D5F5: @ 824D5F5
	.string "{PLAYER} is the Level 50\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D635: @ 824D635
	.string "{PLAYER} is the Open Level\n"
	.string "Battle Tournament Champion!\p"
	.string "Congratulations!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D677: @ 824D677
	.string "The final match!\p"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
	.string "Let the battle begin!$"

BattleFrontier_BattleDomeBattleRoom_Text_24D6BE: @ 824D6BE
	.string "The REFEREES have reached\n"
	.string "a decision!\p"
	.string "The winner is…\n"
	.string "Oh, my goodness!\l"
	.string "The winner is our very own DOME ACE!\l"
	.string "It's TUCKER!\p"
	.string "Congratulations! And thank you!\n"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
