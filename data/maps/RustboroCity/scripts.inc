RustboroCity_MapScripts:: @ 81E06BD
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_MapScript2_1E070B
	.byte 0

RustboroCity_OnTransition: @ 81E06C8
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	compare VAR_RUSTBORO_CITY_STATE, 6
	call_if_eq RustboroCity_EventScript_1E0707
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_RUSTBORO_CITY_STATE, 6
	goto_if_eq RustboroCity_EventScript_1E06EC
	end

RustboroCity_EventScript_1E06EC:: @ 81E06EC
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_1E06FF
	setobjectxyperm 15, 12, 15
	end

RustboroCity_EventScript_1E06FF:: @ 81E06FF
	setobjectxyperm 15, 11, 15
	end

RustboroCity_EventScript_1E0707:: @ 81E0707
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_MapScript2_1E070B: @ 81E070B
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_1E0715
	.2byte 0

RustboroCity_EventScript_1E0715:: @ 81E0715
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_1E0850
	waitmovement 0
	playse SE_KAIDAN
	delay 10
	addobject 15
	applymovement 15, RustboroCity_Movement_1E0852
	waitmovement 0
	playse SE_PIN
	applymovement 15, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 15, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement 15, RustboroCity_Movement_1E084E
	waitmovement 0
	msgbox RustboroCity_Text_1E22A5, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement 15, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 20
	applymovement 15, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_1E2331, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_1E07BD

RustboroCity_EventScript_1E07AC:: @ 81E07AC
	msgbox RustboroCity_Text_1E2449, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_1E07BD

RustboroCity_EventScript_1E07BD:: @ 81E07BD
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_1E07AC
	case 1, RustboroCity_EventScript_1E07AC
	case 2, RustboroCity_EventScript_1E07AC
	case 4, RustboroCity_EventScript_1E07AC
	case 5, RustboroCity_EventScript_1E07AC
	case 6, RustboroCity_EventScript_1E07AC
	case 7, RustboroCity_EventScript_1E07AC
	case MULTI_B_PRESSED, RustboroCity_EventScript_1E07AC
	special sub_81C72A4
	waitstate
	delay 20
	msgbox RustboroCity_Text_1E2464, MSGBOX_DEFAULT
	closemessage
	applymovement 15, RustboroCity_Movement_1E085D
	waitmovement 0
	playse SE_KAIDAN
	removeobject 15
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_1E084E: @ 81E084E
	walk_in_place_down
	step_end

RustboroCity_Movement_1E0850: @ 81E0850
	walk_down
	step_end

RustboroCity_Movement_1E0852: @ 81E0852
	walk_down
	delay_16
	step_end

RustboroCity_Movement_1E0855: @ 81E0855
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_up
	delay_16
	step_end

RustboroCity_Movement_1E085D: @ 81E085D
	walk_up
	step_end

RustboroCity_EventScript_1E085F:: @ 81E085F
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_1E0874
	msgbox RustboroCity_Text_1E123F, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E0874:: @ 81E0874
	msgbox RustboroCity_Text_1E12AC, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E087E:: @ 81E087E
	lock
	faceplayer
	msgbox RustboroCity_Text_1E1407, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E088A:: @ 81E088A
	msgbox RustboroCity_Text_1E1480, MSGBOX_NPC
	end

RustboroCity_EventScript_1E0893:: @ 81E0893
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_1E08A8
	msgbox RustboroCity_Text_1E130D, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E08A8:: @ 81E08A8
	msgbox RustboroCity_Text_1E139E, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E08B2:: @ 81E08B2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_1E08C7
	msgbox RustboroCity_Text_1E1520, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E08C7:: @ 81E08C7
	msgbox RustboroCity_Text_1E1589, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E08D1:: @ 81E08D1
	msgbox RustboroCity_Text_1E1633, MSGBOX_NPC
	end

RustboroCity_EventScript_1E08DA:: @ 81E08DA
	msgbox RustboroCity_Text_1E1695, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E08E3:: @ 81E08E3
	msgbox RustboroCity_Text_1E20A6, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E08EC:: @ 81E08EC
	msgbox RustboroCity_Text_1E2128, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E08F5:: @ 81E08F5
	msgbox RustboroCity_Text_1E2167, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E08FE:: @ 81E08FE
	msgbox RustboroCity_Text_1E21B3, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E0907:: @ 81E0907
	msgbox RustboroCity_Text_1E220B, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E0910:: @ 81E0910
	msgbox RustboroCity_Text_1E2253, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E0919:: @ 81E0919
	msgbox RustboroCity_Text_1E2296, MSGBOX_SIGN
	end

RustboroCity_EventScript_1E0922:: @ 81E0922
	lock
	faceplayer
	msgbox RustboroCity_Text_1E16F4, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_1E0938:: @ 81E0938
	lock
	faceplayer
	msgbox RustboroCity_Text_1E174B, MSGBOX_DEFAULT
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_1E094E:: @ 81E094E
	lock
	faceplayer
	msgbox RustboroCity_Text_1E1789, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E095A:: @ 81E095A
	lockall
	setobjectxyperm 9, 14, 21
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_1E09CD
	end

RustboroCity_EventScript_1E0971:: @ 81E0971
	lockall
	setobjectxyperm 9, 14, 21
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_1E09CD
	end

RustboroCity_EventScript_1E0988:: @ 81E0988
	lockall
	setobjectxyperm 9, 14, 21
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_1E09CD
	end

RustboroCity_EventScript_1E099F:: @ 81E099F
	lockall
	setobjectxyperm 9, 14, 21
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_1E09CD
	end

RustboroCity_EventScript_1E09B6:: @ 81E09B6
	lockall
	setobjectxyperm 9, 14, 21
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_1E09CD
	end

RustboroCity_EventScript_1E09CD:: @ 81E09CD
	msgbox RustboroCity_Text_1E17FE, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 0
	addobject 10
	addobject 9
	applymovement 10, RustboroCity_Movement_1E0AA0
	waitmovement 0
	removeobject 10
	applymovement 9, RustboroCity_Movement_1E0AB1
	waitmovement 0
	msgbox RustboroCity_Text_1E1817, MSGBOX_DEFAULT
	closemessage
	applymovement 9, RustboroCity_Movement_1E0AB9
	waitmovement 0
	fadedefaultbgm
	removeobject 9
	setobjectxyperm 9, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

RustboroCity_EventScript_1E0A3B:: @ 81E0A3B
	msgbox RustboroCity_Text_1E1904, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0A44:: @ 81E0A44
	msgbox RustboroCity_Text_1E194D, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0A4D:: @ 81E0A4D
	applymovement 9, RustboroCity_Movement_1E0AC1
	waitmovement 0
	return

RustboroCity_EventScript_1E0A58:: @ 81E0A58
	applymovement 9, RustboroCity_Movement_1E0AC5
	waitmovement 0
	return

RustboroCity_EventScript_1E0A63:: @ 81E0A63
	applymovement 9, RustboroCity_Movement_1E0ACA
	waitmovement 0
	return

RustboroCity_EventScript_1E0A6E:: @ 81E0A6E
	applymovement 9, RustboroCity_Movement_1E0ACF
	waitmovement 0
	return

RustboroCity_EventScript_1E0A79:: @ 81E0A79
	applymovement 9, RustboroCity_Movement_1E0AD5
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_Movement_1E0A8E: @ 81E0A8E
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_1E0AA0: @ 81E0AA0
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_1E0AB1: @ 81E0AB1
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

RustboroCity_Movement_1E0AB9: @ 81E0AB9
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_Movement_1E0AC1: @ 81E0AC1
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0AC5: @ 81E0AC5
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0ACA: @ 81E0ACA
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0ACF: @ 81E0ACF
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0AD5: @ 81E0AD5
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

RustboroCity_EventScript_1E0ADD:: @ 81E0ADD
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_1E0AF2
	msgbox RustboroCity_Text_1E1904, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_1E0AF2:: @ 81E0AF2
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0AFE:: @ 81E0AFE
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B0A:: @ 81E0B0A
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B16:: @ 81E0B16
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B22:: @ 81E0B22
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B2E:: @ 81E0B2E
	compare VAR_TEMP_1, 0
	call_if_eq RustboroCity_EventScript_1E0B6F
	compare VAR_TEMP_1, 1
	call_if_eq RustboroCity_EventScript_1E0B9B
	compare VAR_TEMP_1, 2
	call_if_eq RustboroCity_EventScript_1E0BC7
	compare VAR_TEMP_1, 3
	call_if_eq RustboroCity_EventScript_1E0BF3
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm 9
	msgbox RustboroCity_Text_1E183E, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E0B6F:: @ 81E0B6F
	applymovement 9, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RustboroCity_EventScript_1E0B9B:: @ 81E0B9B
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_2725AC
	waitmovement 0
	return

RustboroCity_EventScript_1E0BC7:: @ 81E0BC7
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0BF3:: @ 81E0BF3
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, RustboroCity_Movement_1E0C29
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_Movement_1E0C29: @ 81E0C29
	walk_down
	step_end

RustboroCity_EventScript_1E0C2B:: @ 81E0C2B
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C37:: @ 81E0C37
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C43:: @ 81E0C43
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C4F:: @ 81E0C4F
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C5B:: @ 81E0C5B
	compare VAR_TEMP_1, 0
	call_if_eq RustboroCity_EventScript_1E0CDC
	compare VAR_TEMP_1, 1
	call_if_eq RustboroCity_EventScript_1E0D08
	compare VAR_TEMP_1, 2
	call_if_eq RustboroCity_EventScript_1E0D34
	compare VAR_TEMP_1, 3
	call_if_eq RustboroCity_EventScript_1E0D60
	compare VAR_TEMP_1, 4
	call_if_eq RustboroCity_EventScript_1E0D96
	msgbox RustboroCity_Text_1E194D, MSGBOX_DEFAULT
	giveitem_std ITEM_GREAT_BALL
	compare VAR_RESULT, 0
	call_if_eq RustboroCity_EventScript_1E0CD3
	msgbox RustboroCity_Text_1E1A21, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 255, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_1E0CD3:: @ 81E0CD3
	msgbox RustboroCity_Text_1E19E5, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0CDC:: @ 81E0CDC
	applymovement 9, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RustboroCity_EventScript_1E0D08:: @ 81E0D08
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_2725AE
	waitmovement 0
	return

RustboroCity_EventScript_1E0D34:: @ 81E0D34
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0D60:: @ 81E0D60
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, RustboroCity_Movement_1E0C29
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0D96:: @ 81E0D96
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_1E0DB8:: @ 81E0DB8
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

Route104_EventScript_1E0DD1:: @ 81E0DD1
RustboroCity_EventScript_1E0DD1:: @ 81E0DD1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_1E0DE9
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_1E0DEE
	return

RustboroCity_EventScript_1E0DE9:: @ 81E0DE9
	playbgm MUS_GIRL_SUP, 1
	return

RustboroCity_EventScript_1E0DEE:: @ 81E0DEE
	playbgm MUS_BOY_SUP, 1
	return

RustboroCity_EventScript_1E0DF3:: @ 81E0DF3
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E120E
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0E33:: @ 81E0E33
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1215
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0E73:: @ 81E0E73
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E121B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0EB3:: @ 81E0EB3
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1220
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0EF3:: @ 81E0EF3
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1224
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0F33:: @ 81E0F33
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1227
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0F73:: @ 81E0F73
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E122B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0FB3:: @ 81E0FB3
	lockall
	call RustboroCity_EventScript_1E0DD1
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1230
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0FF3:: @ 81E0FF3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_1E100B
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_1E1114
	end

RustboroCity_EventScript_1E100B:: @ 81E100B
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_1E10C1
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_1E1070
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_1E1A49, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Text_1E1ADB, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_1E1AFA, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1092
	msgbox RustboroCity_Text_1E1BD3, MSGBOX_DEFAULT
	call RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E1070:: @ 81E1070
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_1E1C48, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1092
	msgbox RustboroCity_Text_1E1BD3, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E1092:: @ 81E1092
	msgbox RustboroCity_Text_1E1C84, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_1E10DB
	case 1, RustboroCity_EventScript_1E10EE
	case 2, RustboroCity_EventScript_1E1101
	end

RustboroCity_EventScript_1E10C1:: @ 81E10C1
	msgbox RustboroCity_Text_1E1CE7, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E10D6:: @ 81E10D6
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_1E10DB:: @ 81E10DB
	trainerbattle_no_intro TRAINER_MAY_14, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E10EE:: @ 81E10EE
	trainerbattle_no_intro TRAINER_MAY_15, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E1101:: @ 81E1101
	trainerbattle_no_intro TRAINER_MAY_10, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E1114:: @ 81E1114
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_1E11C0
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_1E1174
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_1E1D7D, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Text_1E1E11, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_1E1E34, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1191
	msgbox RustboroCity_Text_1E1F2F, MSGBOX_DEFAULT
	call RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E1174:: @ 81E1174
	msgbox RustboroCity_Text_1E1F76, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1191
	msgbox RustboroCity_Text_1E1F2F, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E1191:: @ 81E1191
	msgbox RustboroCity_Text_1E1FA9, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_1E11D5
	case 1, RustboroCity_EventScript_1E11E8
	case 2, RustboroCity_EventScript_1E11FB
	end

RustboroCity_EventScript_1E11C0:: @ 81E11C0
	msgbox RustboroCity_Text_1E2002, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E11D5:: @ 81E11D5
	trainerbattle_no_intro TRAINER_BRENDAN_10, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_EventScript_1E11E8:: @ 81E11E8
	trainerbattle_no_intro TRAINER_BRENDAN_12, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_EventScript_1E11FB:: @ 81E11FB
	trainerbattle_no_intro TRAINER_BRENDAN_11, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_Movement_1E120E: @ 81E120E
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1215: @ 81E1215
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E121B: @ 81E121B
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1220: @ 81E1220
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1224: @ 81E1224
	walk_down
	walk_down
	step_end

RustboroCity_Movement_1E1227: @ 81E1227
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_1E122B: @ 81E122B
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_1E1230: @ 81E1230
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_1E1236:: @ 81E1236
	msgbox RustboroCity_Text_1E249D, MSGBOX_NPC
	end

RustboroCity_Text_1E123F: @ 81E123F
	.string "The Devon Corporation…\n"
	.string "We all just shorten it to Devon.\p"
	.string "That company makes all sorts of\n"
	.string "convenient products.$"

RustboroCity_Text_1E12AC: @ 81E12AC
	.string "Hm? A sneaky-looking man?\p"
	.string "Come to think of it, yes, a shady-\n"
	.string "looking guy went around the corner.$"

RustboroCity_Text_1E130D: @ 81E130D
	.string "Have you taken the Pokémon Gym\n"
	.string "challenge?\p"
	.string "When you get that shiny Gym Badge\n"
	.string "in hand, I guess Trainers begin to\l"
	.string "realize what is required of them.$"

RustboroCity_Text_1E139E: @ 81E139E
	.string "Hey, that's Rustboro's Gym Badge!\p"
	.string "Out of all the Pokémon Gym Badges,\n"
	.string "Rustboro's is the coolest, I'd say.$"

RustboroCity_Text_1E1407: @ 81E1407
	.string "Oh? Who might you be?\n"
	.string "You're a new face around these parts.\p"
	.string "Have you just transferred into the\n"
	.string "Pokémon Trainer's School?$"

RustboroCity_Text_1E1480: @ 81E1480
	.string "I challenged the Gym Leader, but…\p"
	.string "It's not going to be easy winning with\n"
	.string "my Fire-type Pokémon…\p"
	.string "Fire-type Pokémon don't match up\n"
	.string "well against Rock-type Pokémon…$"

RustboroCity_Text_1E1520: @ 81E1520
	.string "The old sailor Mr. Briney lives in\n"
	.string "a cottage by the sea.\p"
	.string "He goes for walks in the tunnel every\n"
	.string "so often.$"

RustboroCity_Text_1E1589: @ 81E1589
	.string "The old sailor Mr. Briney lives in\n"
	.string "a cottage by the sea.\p"
	.string "He said he was going shopping in\n"
	.string "Slateport for his pet, Peeko.\p"
	.string "That old sea dog, he must really love\n"
	.string "that Peeko.$"

RustboroCity_Text_1E1633: @ 81E1633
	.string "Wow, you have Pokémon with you, too.\p"
	.string "When I get bigger, I'm going to go\n"
	.string "places with Pokémon, too.$"

RustboroCity_Text_1E1695: @ 81E1695
	.string "Pokémon Trainer's School!\p"
	.string "If I go to this school, will I be able\n"
	.string "to catch rare Pokémon easily?$"

RustboroCity_Text_1E16F4: @ 81E16F4
	.string "If a Pokémon gains experience in\n"
	.string "battles, it can sometimes change in\l"
	.string "the way it looks.$"

RustboroCity_Text_1E174B: @ 81E174B
	.string "A Pokémon changes shape?\n"
	.string "If one did that, I would be shocked!$"

RustboroCity_Text_1E1789: @ 81E1789
	.string "A Pokémon you get in a trade from\n"
	.string "someone grows fast.\p"
	.string "But if you don't have certain Gym\n"
	.string "Badges, it may not obey you…$"

RustboroCity_Text_1E17FE: @ 81E17FE
	.string "Get out!\n"
	.string "Out of the way!$"

RustboroCity_Text_1E1817: @ 81E1817
	.string "Wait! Pleeeaaase!\p"
	.string "Don't take my Goods!$"

RustboroCity_Text_1E183E: @ 81E183E
	.string "Oh, it's you!\p"
	.string "You're that fantastic Trainer who\n"
	.string "helped me in Petalburg Woods!\p"
	.string "Help me! I was robbed by Team Aqua!\n"
	.string "I have to get the Devon Goods back!\p"
	.string "If I don't…\n"
	.string "I'm going to be in serious trouble.$"

RustboroCity_Text_1E1904: @ 81E1904
	.string "That shady character, I think he took\n"
	.string "off towards the tunnel over there.$"

RustboroCity_Text_1E194D: @ 81E194D
	.string "Oh! How did it go?\n"
	.string "The Devon Goods?\p"
	.string "You did!\n"
	.string "You got them back!\p"
	.string "You really are a great Trainer!\p"
	.string "I know! As my thanks, I'll give you\n"
	.string "another Great Ball!$"

RustboroCity_Text_1E19E5: @ 81E19E5
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"

RustboroCity_Text_1E1A21: @ 81E1A21
	.string "Excuse me, please!\n"
	.string "Please come with me!$"

RustboroCity_Text_1E1A49: @ 81E1A49
	.string "May: Oh, hi, {PLAYER}{KUN}!\p"
	.string "You had a Match Call feature put\n"
	.string "on your Pokénav!\p"
	.string "Let's register each other so we can\n"
	.string "contact one another anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_1E1ADB: @ 81E1ADB
	.string "Registered May\n"
	.string "in the Pokénav.$"

RustboroCity_Text_1E1AFA: @ 81E1AFA
	.string "May: Oh, by the way, I passed\n"
	.string "Mr. Briney in Petalburg Woods.\p"
	.string "I guess he's on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "How's your Pokédex coming along,\n"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
	.string "So…\n"
	.string "How about a little battle?$"

RustboroCity_Text_1E1BD3: @ 81E1BD3
	.string "May: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "Pokémon very much?\p"
	.string "That's not very good for a Trainer!$"

RustboroCity_Text_1E1C48: @ 81E1C48
	.string "May: So, what do you think?\n"
	.string "How about a little battle here?$"

RustboroCity_Text_1E1C84: @ 81E1C84
	.string "May: You just became a Trainer,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"

RustboroCity_Text_1E1CC1: @ 81E1CC1
	.string "Yikes!\n"
	.string "You're better than I expected!$"

RustboroCity_Text_1E1CE7: @ 81E1CE7
	.string "May: Oh, by the way, Mr. Briney, who\n"
	.string "I just passed…\p"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
	.string "might not know this, but Mr. Briney\l"
	.string "was once a revered seafarer.$"

RustboroCity_Text_1E1D7D: @ 81E1D7D
	.string "Brendan: Oh, hey, {PLAYER}!\p"
	.string "You had a Match Call feature put\n"
	.string "on your Pokénav! Cool!\p"
	.string "Let's register each other so we can\n"
	.string "get in touch anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_1E1E11: @ 81E1E11
	.string "Registered Brendan\n"
	.string "in the Pokénav.$"

RustboroCity_Text_1E1E34: @ 81E1E34
	.string "Brendan: By the way, {PLAYER}, I walked\n"
	.string "by Mr. Briney in Petalburg Woods.\p"
	.string "I bet he was on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "{PLAYER}, how's your Pokédex?\n"
	.string "Have you filled in any pages yet?\p"
	.string "Mine rules.\p"
	.string "Want to have a battle to test how\n"
	.string "far you've progressed?$"

RustboroCity_Text_1E1F2F: @ 81E1F2F
	.string "Brendan: What's the matter? Don't have\n"
	.string "any confidence in your Pokémon?$"

RustboroCity_Text_1E1F76: @ 81E1F76
	.string "Brendan: What's up?\n"
	.string "Want to have a battle with me?$"

RustboroCity_Text_1E1FA9: @ 81E1FA9
	.string "Brendan: I know you just became\n"
	.string "a Trainer, but I won't go easy!$"

RustboroCity_Text_1E1FE9: @ 81E1FE9
	.string "Hmm…\n"
	.string "You're pretty good.$"

RustboroCity_Text_1E2002: @ 81E2002
	.string "Brendan: By the way, you know\n"
	.string "Mr. Briney? The guy I just passed?\p"
	.string "I bet you didn't know this, since you\n"
	.string "just moved here, {PLAYER}, but\l"
	.string "Mr. Briney was once a great sailor.$"

RustboroCity_Text_1E20A6: @ 81E20A6
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”\p"
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"

RustboroCity_Text_1E2128: @ 81E2128
	.string "Devon Corporation\p"
	.string "“For all your living needs, we make\n"
	.string "it all.”$"

RustboroCity_Text_1E2167: @ 81E2167
	.string "Rustboro City Pokémon Gym\n"
	.string "Leader: Roxanne\p"
	.string "“The Rock-loving honors student!”$"

RustboroCity_Text_1E21B3: @ 81E21B3
	.string "Devon Corp. Branch Office\p"
	.string "“Access limited to Devon employees\n"
	.string "and authorized personnel.”$"

RustboroCity_Text_1E220B: @ 81E220B
	.string "Rustboro City\p"
	.string "“The city probing the integration of\n"
	.string "nature and science.”$"

RustboroCity_Text_1E2253: @ 81E2253
	.string "Pokémon Trainer's School\p"
	.string "“We'll teach you anything about\n"
	.string "Pokémon!”$"

RustboroCity_Text_1E2296: @ 81E2296
	.string "Cutter's House$"

RustboroCity_Text_1E22A5: @ 81E22A5
	.string "I've been developing an added feature\n"
	.string "for the Pokénav…\p"
	.string "And it turned out great!\p"
	.string "{PLAYER}, may I see that Pokénav?\n"
	.string "The one our President gave you?$"

RustboroCity_Text_1E2331: @ 81E2331
	.string "There you go, {PLAYER}!\p"
	.string "I added a new feature named\n"
	.string "Match Call to your Pokénav.\p"
	.string "Using the Match Call feature,\n"
	.string "you can chat with people who have\l"
	.string "been registered in your Pokénav.\p"
	.string "{PLAYER}, our President Stone should\n"
	.string "be registered in your Pokénav.\p"
	.string "Test it out.\n"
	.string "Please give our President a call.$"

RustboroCity_Text_1E2449: @ 81E2449
	.string "Please select the Pokénav.$"

RustboroCity_Text_1E2464: @ 81E2464
	.string "Okay, I'd better get back to work.\n"
	.string "Please take care, {PLAYER}!$"

RustboroCity_Text_1E249D: @ 81E249D
	.string "Did you know this?\p"
	.string "You can have a 2-on-2 battle even\n"
	.string "if you're not with another Trainer.\p"
	.string "If you catch the eyes of two Trainers\n"
	.string "when you have two or more Pokémon,\l"
	.string "they'll both challenge you.\p"
	.string "Don't you think it'd be cool if you\n"
	.string "could beat two Trainers by yourself?$"
