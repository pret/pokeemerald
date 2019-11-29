BattleFrontier_BattleTowerBattleRoom_MapScripts:: @ 8241B40
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_MapScript2_241B62
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_MapScript2_241B4B
	.byte 0

BattleFrontier_BattleTowerBattleRoom_MapScript2_241B4B: @ 8241B4B
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241B55
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_241B55:: @ 8241B55
	setvar VAR_TEMP_1, 1
	applymovement 3, BattleFrontier_BattleTowerBattleRoom_Movement_242198
	end

BattleFrontier_BattleTowerBattleRoom_MapScript2_241B62: @ 8241B62
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241B6C
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_241B6C:: @ 8241B6C
	setvar VAR_TEMP_0, 1
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_242179
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_241BC3
	applymovement 2, BattleFrontier_BattleTowerBattleRoom_Movement_24218D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_24217E
	waitmovement 0
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_6, 1
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241BC3:: @ 8241BC3
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_CHOOSE_TRAINER
	special CallBattleTowerFunc
	addobject 1
	applymovement 1, BattleFrontier_BattleTowerBattleRoom_Movement_242182
	waitmovement 0
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_7
	setvar VAR_0x8005, 0
	special CallBattleTowerFunc
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_24210E
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_241C2F
BattleFrontier_BattleTowerBattleRoom_EventScript_241C03:: @ 8241C03
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03:: @ 8241C03
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_2
	setvar VAR_0x8005, 3
	special CallBattleTowerFunc
	setvar VAR_0x8004, 3
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_2421B8

BattleFrontier_BattleTowerBattleRoom_EventScript_241C2F:: @ 8241C2F
	call BattleFrontier_EventScript_IncrementWinStreak
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_4
	special CallBattleTowerFunc
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6
	applymovement 1, BattleFrontier_BattleTowerBattleRoom_Movement_242188
	waitmovement 0
	removeobject 1
	frontier_getbrainstatus
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	call_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_241EC3
	applymovement 2, BattleFrontier_BattleTowerBattleRoom_Movement_24218D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_24217E
	waitmovement 0
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_242217, MSGBOX_DEFAULT
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F:: @ 8241C8F
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_241F0A
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerBattleRoom_EventScript_241E44
	call BattleFrontier_BattleTowerBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_241D0A
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241DDC
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241D40
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_241D7C
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_241DAA
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241D0A:: @ 8241D0A
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241DDC
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241D7C
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_241DAA
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241D40:: @ 8241D40
	message BattleFrontier_BattleTowerBattleRoom_Text_2423A3
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241D72
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241D72:: @ 8241D72
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241D7C:: @ 8241D7C
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2423FC, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_241E22
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241DAA:: @ 8241DAA
	message BattleFrontier_BattleTowerBattleRoom_Text_24244C
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_24220E
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241C8F

BattleFrontier_BattleTowerBattleRoom_EventScript_241DDC:: @ 8241DDC
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_242180
	waitmovement 0
	applymovement 2, BattleFrontier_BattleTowerBattleRoom_Movement_242192
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241BC3

BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6:: @ 8241DF6
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_2
	setvar VAR_0x8005, 3
	special CallBattleTowerFunc
	setvar VAR_0x8004, 3
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_2421B8

BattleFrontier_BattleTowerBattleRoom_EventScript_241E22:: @ 8241E22
	message BattleFrontier_BattleTowerBattleRoom_Text_242426
	waitmessage
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SAVE
	setvar VAR_0x8005, CHALLENGE_STATUS_PAUSED
	special CallBattleTowerFunc
	playse SE_SAVE
	waitse
	fadescreen 1
	frontier_reset
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_241E44:: @ 8241E44
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241E90
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_241E97
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_241E9E
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_241EA5
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_241EAC
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_241EB3

BattleFrontier_BattleTowerBattleRoom_EventScript_241E90:: @ 8241E90
	message BattleFrontier_BattleTowerBattleRoom_Text_242277
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241E97:: @ 8241E97
	message BattleFrontier_BattleTowerBattleRoom_Text_2422A9
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241E9E:: @ 8241E9E
	message BattleFrontier_BattleTowerBattleRoom_Text_2422DB
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241EA5:: @ 8241EA5
	message BattleFrontier_BattleTowerBattleRoom_Text_24230D
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241EAC:: @ 8241EAC
	message BattleFrontier_BattleTowerBattleRoom_Text_24233F
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241EB3:: @ 8241EB3
	message BattleFrontier_BattleTowerBattleRoom_Text_242371
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak:: @ 8241EBA
	frontier_incrementstreak
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241EC3:: @ 8241EC3
	applymovement 3, BattleFrontier_BattleTowerBattleRoom_Movement_24219A
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, BattleFrontier_BattleTowerBattleRoom_Movement_2421A6
	applymovement 2, BattleFrontier_BattleTowerBattleRoom_Movement_2421AB
	waitmovement 0
	applymovement 3, BattleFrontier_BattleTowerBattleRoom_Movement_2421A1
	waitmovement 0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_241F0A:: @ 8241F0A
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_241F22
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2424C2, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1

BattleFrontier_BattleTowerBattleRoom_EventScript_241F22:: @ 8241F22
	message BattleFrontier_BattleTowerBattleRoom_Text_242542
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_241F79
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241FAF
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241D40
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_241D7C
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_241DAA
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241F22

BattleFrontier_BattleTowerBattleRoom_EventScript_241F79:: @ 8241F79
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_241FAF
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_241D7C
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_241DAA
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_241F22

BattleFrontier_BattleTowerBattleRoom_EventScript_241FAF:: @ 8241FAF
	call BattleFrontier_EventScript_SetBrainObjectGfx
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_242180
	waitmovement 0
	applymovement 2, BattleFrontier_BattleTowerBattleRoom_Movement_242192
	waitmovement 0
	addobject 1
	applymovement 1, BattleFrontier_BattleTowerBattleRoom_Movement_2421B2
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_242085
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_242029
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_2420B2
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_242029
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_242579, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_242029:: @ 8242029
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_24268C, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_24210E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_242046
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241C03

BattleFrontier_BattleTowerBattleRoom_EventScript_242046:: @ 8242046
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2426B4, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleTowerBattleRoom_Text_24270E
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_242744, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6

BattleFrontier_BattleTowerBattleRoom_EventScript_242085:: @ 8242085
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	compare VAR_RESULT, FALSE
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_2420B2
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2427F9, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_2420B2:: @ 82420B2
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2428E0, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_24210E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_2420CF
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241C03

BattleFrontier_BattleTowerBattleRoom_EventScript_2420CF:: @ 82420CF
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_2428F7, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleTowerBattleRoom_Text_242932
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_24295D, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241DF6

BattleFrontier_BattleTowerBattleRoom2_EventScript_24210E:: @ 824210E
BattleFrontier_BattleTowerBattleRoom_EventScript_24210E:: @ 824210E
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_6, 0
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	compare VAR_0x8004, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_24215A
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
BattleFrontier_BattleTowerBattleRoom_EventScript_24215A:: @ 824215A
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_15
	special CallBattleTowerFunc
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleFrontier_EventScript_SetBrainObjectGfx:: @ 8242170
	frontier_setbrainobj
	return

BattleFrontier_BattleTowerBattleRoom_Movement_242179: @ 8242179
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_24217E: @ 824217E
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_242180: @ 8242180
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_242182: @ 8242182
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_242188: @ 8242188
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_24218D: @ 824218D
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_242192: @ 8242192
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_242198: @ 8242198
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_24219A: @ 824219A
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_2421A1: @ 82421A1
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_2421A6: @ 82421A6
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_2421AB: @ 82421AB
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_2421B2: @ 82421B2
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2421B8:: @ 82421B8
BattleFrontier_BattleTowerBattleRoom_EventScript_2421B8:: @ 82421B8
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_2421E8
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_2421F2
	compare VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_2421FC
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 6, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_2421E8:: @ 82421E8
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 10, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_2421F2:: @ 82421F2
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 14, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_2421FC:: @ 82421FC
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_13
	special CallBattleTowerFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 18, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_24220E:: @ 824220E
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerBattleRoom2_Text_242217: @ 8242217
BattleFrontier_BattleTowerBattleRoom_Text_242217: @ 8242217
	.string "We will restore your POKéMON to\n"
	.string "full health.$"

BattleFrontier_BattleTowerBattleRoom_Text_242244: @ 8242244
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_242277: @ 8242277
	.string "You will be facing opponent no. 2.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_2422A9: @ 82422A9
	.string "You will be facing opponent no. 3.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_2422DB: @ 82422DB
	.string "You will be facing opponent no. 4.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_24230D: @ 824230D
	.string "You will be facing opponent no. 5.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_24233F: @ 824233F
	.string "You will be facing opponent no. 6.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_242371: @ 8242371
	.string "You will be facing opponent no. 7.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_2423A3: @ 82423A3
BattleFrontier_BattleTowerBattleRoom_Text_2423A3: @ 82423A3
	.string "Record your battle on your\n"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleTowerLobby_Text_2423CD: @ 82423CD
	.string "{PLAYER}'s battle was recorded\n"
	.string "on the FRONTIER PASS.$"

BattleFrontier_BattleTowerBattleRoom2_Text_2423FC: @ 82423FC
BattleFrontier_BattleTowerBattleRoom_Text_2423FC: @ 82423FC
	.string "Would you like to save and\n"
	.string "quit the game?$"

BattleFrontier_BattleTowerBattleRoom2_Text_242426: @ 8242426
BattleFrontier_BattleTowerBattleRoom_Text_242426: @ 8242426
	.string "Saving your battle data.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerBattleRoom2_Text_24244C: @ 824244C
BattleFrontier_BattleTowerBattleRoom_Text_24244C: @ 824244C
	.string "Would you like to cancel your BATTLE\n"
	.string "ROOM challenge?$"

gText_BattleRecordCouldntBeSaved:: @ 8242481
	.string "There was an error of some sort.\n"
	.string "Your record could not be saved.$"

BattleFrontier_BattleTowerBattleRoom_Text_2424C2: @ 82424C2
	.string "Excuse me, but…\p"
	.string "Our leader, the SALON MAIDEN, is on\n"
	.string "her way here in hopes of battling you.\p"
	.string "She should be arriving very shortly.$"

BattleFrontier_BattleTowerBattleRoom_Text_242542: @ 8242542
	.string "You will be facing the SALON MAIDEN.\n"
	.string "Are you prepared?$"

BattleFrontier_BattleTowerBattleRoom_Text_242579: @ 8242579
	.string "Greetings…\n"
	.string "My name is ANABEL.\p"
	.string "I am the SALON MAIDEN, and I am in\n"
	.string "charge of running the BATTLE TOWER…\p"
	.string "I have heard several rumors\n"
	.string "about you…\p"
	.string "In all honesty, what I have heard does\n"
	.string "not seem attractive in any way…\p"
	.string "The reason I've come to see you…\n"
	.string "Well, there is but one reason…$"

BattleFrontier_BattleTowerBattleRoom_Text_24268C: @ 824268C
	.string "Let me see your talent in\n"
	.string "its entirety…$"

BattleFrontier_BattleTowerBattleRoom_Text_2426B4: @ 82426B4
	.string "ANABEL: Fufufu, nicely done…\p"
	.string "Your FRONTIER PASS, please…\n"
	.string "Your talent shall be recognized.$"

BattleFrontier_BattleTowerBattleRoom_Text_24270E: @ 824270E
	.string "The Ability Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleTowerBattleRoom_Text_242744: @ 8242744
	.string "… … … … … …\p"
	.string "You have confidence in your POKéMON\n"
	.string "battling talent, don't you?\p"
	.string "I urge you to keep battling and\n"
	.string "keep on winning.\p"
	.string "I will be waiting for you.\n"
	.string "Until the next time we meet…$"

BattleFrontier_BattleTowerBattleRoom_Text_2427F9: @ 82427F9
	.string "ANABEL: You really did come back to\n"
	.string "see me…\p"
	.string "… … … … … …\p"
	.string "You've won straight matches to see me…\n"
	.string "I won't have to hold back against you…\p"
	.string "It's been too long now…\p"
	.string "Too long since I've been able to battle\n"
	.string "without thinking about anything…$"

BattleFrontier_BattleTowerBattleRoom_Text_2428E0: @ 82428E0
	.string "Let's begin, shall we?$"

BattleFrontier_BattleTowerBattleRoom_Text_2428F7: @ 82428F7
	.string "ANABEL: Fufu, congratulations…\n"
	.string "Your FRONTIER PASS, please…$"

BattleFrontier_BattleTowerBattleRoom_Text_242932: @ 8242932
	.string "The Ability Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleTowerBattleRoom_Text_24295D: @ 824295D
	.string "That was fun…\p"
	.string "I have never had a POKéMON battle\n"
	.string "so enjoyable before…\p"
	.string "I wish I could battle with you again…$"

