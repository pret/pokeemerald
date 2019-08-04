Route110_TrickHouseEntrance_MapScripts:: @ 8269A50
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_MapScript2_269CEE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_MapScript2_269BD3
	.byte 0

Route110_TrickHouseEntrance_OnTransition: @ 8269A60
	setflag FLAG_LANDMARK_TRICK_HOUSE
	compare VAR_TRICK_HOUSE_STATE, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269AF3
	compare VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269AD7
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE_2, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269BB3
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 5
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B03
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 3
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B03
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 0
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B03
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE_3
	case 0, Route110_TrickHouseEntrance_EventScript_269BBB
	case 1, Route110_TrickHouseEntrance_EventScript_269BC1
	case 3, Route110_TrickHouseEntrance_EventScript_269BC7
	case 4, Route110_TrickHouseEntrance_EventScript_269BCD
	end

Route110_TrickHouseEntrance_EventScript_269AD7:: @ 8269AD7
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	compare VAR_TRICK_HOUSE_LEVEL, 8
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269AED
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 2
	end

Route110_TrickHouseEntrance_EventScript_269AED:: @ 8269AED
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 6
	end

Route110_TrickHouseEntrance_EventScript_269AF3:: @ 8269AF3
	setvar VAR_TRICK_HOUSE_STATE, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 5
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	end

Route110_TrickHouseEntrance_EventScript_269B03:: @ 8269B03
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 0
	compare VAR_TRICK_HOUSE_LEVEL, 1
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B61
	compare VAR_TRICK_HOUSE_LEVEL, 2
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B6B
	compare VAR_TRICK_HOUSE_LEVEL, 3
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B75
	compare VAR_TRICK_HOUSE_LEVEL, 4
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B7F
	compare VAR_TRICK_HOUSE_LEVEL, 5
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B89
	compare VAR_TRICK_HOUSE_LEVEL, 6
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B93
	compare VAR_TRICK_HOUSE_LEVEL, 7
	call_if_eq Route110_TrickHouseEntrance_EventScript_269B9D
	compare VAR_TRICK_HOUSE_LEVEL, 8
	call_if_eq Route110_TrickHouseEntrance_EventScript_269BA7
	return

Route110_TrickHouseEntrance_EventScript_269B61:: @ 8269B61
	call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B6B:: @ 8269B6B
	call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B75:: @ 8269B75
	call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B7F:: @ 8269B7F
	call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B89:: @ 8269B89
	call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B93:: @ 8269B93
	call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B9D:: @ 8269B9D
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269BA7:: @ 8269BA7
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 4
	return

Route110_TrickHouseEntrance_EventScript_269BAD:: @ 8269BAD
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 3
	return

Route110_TrickHouseEntrance_EventScript_269BB3:: @ 8269BB3
	setobjectxyperm 1, 5, 2
	end

Route110_TrickHouseEntrance_EventScript_269BBB:: @ 8269BBB
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 0
	end

Route110_TrickHouseEntrance_EventScript_269BC1:: @ 8269BC1
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	end

Route110_TrickHouseEntrance_EventScript_269BC7:: @ 8269BC7
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	end

Route110_TrickHouseEntrance_EventScript_269BCD:: @ 8269BCD
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	end

Route110_TrickHouseEntrance_MapScript2_269BD3: @ 8269BD3
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_2, 1, Route110_TrickHouseEntrance_EventScript_269C15
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 0, Route110_TrickHouseEntrance_EventScript_269C26
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 1, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 2, Route110_TrickHouseEntrance_EventScript_269CD0
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 3, Route110_TrickHouseEntrance_EventScript_269CD0
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 4, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 5, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 6, Route110_TrickHouseEntrance_EventScript_269CDF
	.2byte 0

Route110_TrickHouseEntrance_EventScript_269C15:: @ 8269C15
	addobject 1
	showobjectat 1, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	turnobject 1, 4
	turnobject EVENT_OBJ_ID_PLAYER, 3
	end

Route110_TrickHouseEntrance_EventScript_269C26:: @ 8269C26
	addobject 1
	hideobjectat 1, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_269C8C
	case 1, Route110_TrickHouseEntrance_EventScript_269C94
	case 2, Route110_TrickHouseEntrance_EventScript_269C9C
	case 3, Route110_TrickHouseEntrance_EventScript_269CA4
	case 4, Route110_TrickHouseEntrance_EventScript_269CAC
	case 5, Route110_TrickHouseEntrance_EventScript_269CB4
	case 6, Route110_TrickHouseEntrance_EventScript_269CBC
	case 7, Route110_TrickHouseEntrance_EventScript_269CC4
	end

Route110_TrickHouseEntrance_EventScript_269C8C:: @ 8269C8C
	setobjectxy 1, 6, 3
	end

Route110_TrickHouseEntrance_EventScript_269C94:: @ 8269C94
	setobjectxy 1, 11, 5
	end

Route110_TrickHouseEntrance_EventScript_269C9C:: @ 8269C9C
	setobjectxy 1, 9, 1
	end

Route110_TrickHouseEntrance_EventScript_269CA4:: @ 8269CA4
	setobjectxy 1, 3, 1
	end

Route110_TrickHouseEntrance_EventScript_269CAC:: @ 8269CAC
	setobjectxy 1, 0, 5
	end

Route110_TrickHouseEntrance_EventScript_269CB4:: @ 8269CB4
	setobjectxy 1, 11, 1
	end

Route110_TrickHouseEntrance_EventScript_269CBC:: @ 8269CBC
	setobjectxy 1, 8, 1
	end

Route110_TrickHouseEntrance_EventScript_269CC4:: @ 8269CC4
	setobjectxy 1, 4, 4
	end

Route110_TrickHouseEntrance_EventScript_269CCC:: @ 8269CCC
	removeobject 1
	end

Route110_TrickHouseEntrance_EventScript_269CD0:: @ 8269CD0
	addobject 1
	setobjectxy 1, 5, 2
	turnobject 1, 2
	end

Route110_TrickHouseEntrance_EventScript_269CDF:: @ 8269CDF
	addobject 1
	setobjectxy 1, 5, 2
	turnobject 1, 1
	end

Route110_TrickHouseEntrance_MapScript2_269CEE: @ 8269CEE
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE_2, 1, Route110_TrickHouseEntrance_EventScript_269CF8
	.2byte 0

Route110_TrickHouseEntrance_EventScript_269CF8:: @ 8269CF8
	lockall
	delay 20
	compare VAR_TRICK_HOUSE_LEVEL, 0
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E48
	msgbox Route110_TrickHouseEntrance_Text_26A78C, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E36
	waitmovement 0
	playse SE_W153
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E3F
	waitmovement 0
	removeobject 1
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 1
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_2, 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269D39:: @ 8269D39
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269D3B:: @ 8269D3B
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE_3
	case 0, Route110_TrickHouseEntrance_EventScript_269D6E
	case 2, Route110_TrickHouseEntrance_EventScript_269E8F
	case 3, Route110_TrickHouseEntrance_EventScript_269E51
	case 6, Route110_TrickHouseEntrance_EventScript_26A039
	end

Route110_TrickHouseEntrance_EventScript_269D6E:: @ 8269D6E
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TRICK_HOUSE_LEVEL, 0
	call_if_eq Route110_TrickHouseEntrance_EventScript_269DEE
	compare VAR_TRICK_HOUSE_LEVEL, 1
	call_if_eq Route110_TrickHouseEntrance_EventScript_269DF7
	compare VAR_TRICK_HOUSE_LEVEL, 2
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E00
	compare VAR_TRICK_HOUSE_LEVEL, 3
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E09
	compare VAR_TRICK_HOUSE_LEVEL, 4
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E12
	compare VAR_TRICK_HOUSE_LEVEL, 5
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E1B
	compare VAR_TRICK_HOUSE_LEVEL, 6
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E24
	compare VAR_TRICK_HOUSE_LEVEL, 7
	call_if_eq Route110_TrickHouseEntrance_EventScript_269E2D
	closemessage
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_2, 1
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 255, 6, 2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269DEE:: @ 8269DEE
	msgbox Route110_TrickHouseEntrance_Text_26A48A, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269DF7:: @ 8269DF7
	msgbox Route110_TrickHouseEntrance_Text_26A4DA, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E00:: @ 8269E00
	msgbox Route110_TrickHouseEntrance_Text_26A529, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E09:: @ 8269E09
	msgbox Route110_TrickHouseEntrance_Text_26A577, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E12:: @ 8269E12
	msgbox Route110_TrickHouseEntrance_Text_26A5C8, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E1B:: @ 8269E1B
	msgbox Route110_TrickHouseEntrance_Text_26A616, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E24:: @ 8269E24
	msgbox Route110_TrickHouseEntrance_Text_26A665, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E2D:: @ 8269E2D
	msgbox Route110_TrickHouseEntrance_Text_26A6B6, MSGBOX_DEFAULT
	return

Route110_TrickHouseEnd_Movement_269E36: @ 8269E36
Route110_TrickHouseEntrance_Movement_269E36: @ 8269E36
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Route110_TrickHouseEnd_Movement_269E3F: @ 8269E3F
Route110_TrickHouseEntrance_Movement_269E3F: @ 8269E3F
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

Route110_TrickHouseEntrance_EventScript_269E48:: @ 8269E48
	msgbox Route110_TrickHouseEntrance_Text_26A709, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_269E51:: @ 8269E51
	msgbox Route110_TrickHouseEntrance_Text_26A921, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_26A9AF, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269E8F:: @ 8269E8F
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_26AA82, MSGBOX_DEFAULT
	compare VAR_TRICK_HOUSE_LEVEL, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269EEF
	compare VAR_TRICK_HOUSE_LEVEL, 2
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269F1B
	compare VAR_TRICK_HOUSE_LEVEL, 3
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269F47
	compare VAR_TRICK_HOUSE_LEVEL, 4
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269F73
	compare VAR_TRICK_HOUSE_LEVEL, 5
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269F9F
	compare VAR_TRICK_HOUSE_LEVEL, 6
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269FCB
	compare VAR_TRICK_HOUSE_LEVEL, 7
	goto_if_eq Route110_TrickHouseEntrance_EventScript_269FF7
	end

Route110_TrickHouseEntrance_EventScript_269EEF:: @ 8269EEF
	giveitem_std ITEM_RARE_CANDY
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269F1B:: @ 8269F1B
	giveitem_std ITEM_TIMER_BALL
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269F47:: @ 8269F47
	giveitem_std ITEM_HARD_STONE
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269F73:: @ 8269F73
	giveitem_std ITEM_SMOKE_BALL
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269F9F:: @ 8269F9F
	giveitem_std ITEM_TM12
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269FCB:: @ 8269FCB
	giveitem_std ITEM_MAGNET
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269FF7:: @ 8269FF7
	giveitem_std ITEM_PP_MAX
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A023
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_26AB00, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A023:: @ 826A023
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 3
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A039:: @ 826A039
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_26AB2C, MSGBOX_DEFAULT
	call Route110_TrickHouseEntrance_EventScript_26A070
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A09A
	compare VAR_RESULT, 0
	call_if_eq Common_EventScript_NoRoomLeftForAnother
	msgbox Route110_TrickHouseEntrance_Text_26ABBD, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A070:: @ 826A070
	multichoice 0, 0, 88, 1
	switch VAR_RESULT
	case 0, Route110_TrickHouseEntrance_EventScript_26A08A
	goto Route110_TrickHouseEntrance_EventScript_26A092

Route110_TrickHouseEntrance_EventScript_26A08A:: @ 826A08A
	givedecoration_std 31
	return

Route110_TrickHouseEntrance_EventScript_26A092:: @ 826A092
	givedecoration_std 32
	return

Route110_TrickHouseEntrance_EventScript_26A09A:: @ 826A09A
	msgbox Route110_TrickHouseEntrance_Text_26ABAE, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Route110_TrickHouseEntrance_Movement_26D632
	waitmovement 0
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E36
	waitmovement 0
	playse SE_W153
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E3F
	waitmovement 0
	removeobject 1
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_3, 5
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A0D3:: @ 826A0D3
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE_3
	case 0, Route110_TrickHouseEntrance_EventScript_26A106
	case 1, Route110_TrickHouseEntrance_EventScript_26A110
	case 4, Route110_TrickHouseEntrance_EventScript_26A201
	case 5, Route110_TrickHouseEntrance_EventScript_26A20B
	end

Route110_TrickHouseEntrance_EventScript_26A106:: @ 826A106
	msgbox Route110_TrickHouseEntrance_Text_26A878, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A110:: @ 826A110
	msgbox Route110_TrickHouseEntrance_Text_26A887, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, 1
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A126
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A126:: @ 826A126
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, 0
	special DrawWholeMapView
	delay 20
	applymovement EVENT_OBJ_ID_PLAYER, Route110_TrickHouseEntrance_Movement_2725C9
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Route110_TrickHouseEntrance_Movement_26A1A7
	waitmovement 0
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_26A1A9
	case 1, Route110_TrickHouseEntrance_EventScript_26A1B4
	case 2, Route110_TrickHouseEntrance_EventScript_26A1BF
	case 3, Route110_TrickHouseEntrance_EventScript_26A1CA
	case 4, Route110_TrickHouseEntrance_EventScript_26A1D5
	case 5, Route110_TrickHouseEntrance_EventScript_26A1E0
	case 6, Route110_TrickHouseEntrance_EventScript_26A1EB
	case 7, Route110_TrickHouseEntrance_EventScript_26A1F6
	end

Route110_TrickHouseEntrance_Movement_26A1A7: @ 826A1A7
	set_invisible
	step_end

Route110_TrickHouseEntrance_EventScript_26A1A9:: @ 826A1A9
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1B4:: @ 826A1B4
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1BF:: @ 826A1BF
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1CA:: @ 826A1CA
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1D5:: @ 826A1D5
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1E0:: @ 826A1E0
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1EB:: @ 826A1EB
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A1F6:: @ 826A1F6
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A201:: @ 826A201
	msgbox Route110_TrickHouseEntrance_Text_26A8BD, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A20B:: @ 826A20B
	compare VAR_TRICK_HOUSE_LEVEL, 8
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A220
	msgbox Route110_TrickHouseEntrance_Text_26A878, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A220:: @ 826A220
	msgbox Route110_TrickHouseEntrance_Text_26A8BD, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A22A:: @ 826A22A
	lockall
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_26A289
	case 1, Route110_TrickHouseEntrance_EventScript_26A2B2
	case 2, Route110_TrickHouseEntrance_EventScript_26A2DB
	case 3, Route110_TrickHouseEntrance_EventScript_26A304
	case 4, Route110_TrickHouseEntrance_EventScript_26A32D
	case 5, Route110_TrickHouseEntrance_EventScript_26A356
	case 6, Route110_TrickHouseEntrance_EventScript_26A37F
	case 7, Route110_TrickHouseEntrance_EventScript_26A3A8
	end

Route110_TrickHouseEntrance_EventScript_26A289:: @ 826A289
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle1_Text_26B98D, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A2B2:: @ 826A2B2
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle2_Text_26BCBA, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A2DB:: @ 826A2DB
	compare VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle3_Text_26C609, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A304:: @ 826A304
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle4_Text_26C8C3, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A32D:: @ 826A32D
	compare VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle5_Text_26D660, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A356:: @ 826A356
	compare VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle6_Text_26DE26, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A37F:: @ 826A37F
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle7_EventScript_26E413, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A3A8:: @ 826A3A8
	compare VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0
	goto_if_eq Route110_TrickHouseEntrance_EventScript_26A3D1
	msgbox Route110_TrickHousePuzzle8_EventScript_26E864, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A3D1:: @ 826A3D1
	msgbox Route110_TrickHouseEntrance_Text_26AC4F, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle1_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle2_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle3_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle4_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle5_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle6_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle7_EventScript_26A3DB:: @ 826A3DB
Route110_TrickHousePuzzle8_EventScript_26A3DB:: @ 826A3DB
	msgbox Route110_TrickHousePuzzle1_Text_26AC2F, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle1_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle2_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle3_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle4_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle5_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle6_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle7_EventScript_26A3E5:: @ 826A3E5
Route110_TrickHousePuzzle8_EventScript_26A3E5:: @ 826A3E5
	playfanfare MUS_FANFA4
	message Route110_TrickHousePuzzle1_Text_26ABE8
	waitfanfare
	msgbox Route110_TrickHousePuzzle1_Text_26ABFB, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_26A3F8:: @ 826A3F8
	lockall
	msgbox Route110_TrickHouseEntrance_Text_26A474, MSGBOX_DEFAULT
	releaseall
	compare VAR_TRICK_HOUSE_LEVEL, 0
	call_if_eq Route110_TrickHouseEntrance_EventScript_26A429
	compare VAR_TRICK_HOUSE_LEVEL, 1
	call_if_eq Route110_TrickHouseEntrance_EventScript_26A439
	compare VAR_TRICK_HOUSE_LEVEL, 2
	call_if_eq Route110_TrickHouseEntrance_EventScript_26A449
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE_1, 1
	end

Route110_TrickHouseEntrance_EventScript_26A429:: @ 826A429
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 3
	call Route110_TrickHouseEntrance_EventScript_26A459
	return

Route110_TrickHouseEntrance_EventScript_26A439:: @ 826A439
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 5
	call Route110_TrickHouseEntrance_EventScript_26A459
	return

Route110_TrickHouseEntrance_EventScript_26A449:: @ 826A449
	setvar VAR_0x8004, 9
	setvar VAR_0x8005, 2
	call Route110_TrickHouseEntrance_EventScript_26A459
	return

Route110_TrickHouseEntrance_EventScript_26A459:: @ 826A459
	setvar VAR_0x8006, 0
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, VAR_0x8005
	setfieldeffectargument 2, VAR_0x8006
	dofieldeffect FLDEFF_SPARKLE
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	return

Route110_TrickHouseEntrance_Text_26A474: @ 826A474
	.string "You're being watched…$"

Route110_TrickHouseEntrance_Text_26A48A: @ 826A48A
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this desk? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A4DA: @ 826A4DA
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this tree? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A529: @ 826A529
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this dresser? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A577: @ 826A577
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beyond this window? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A5C8: @ 826A5C8
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this planter? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A616: @ 826A616
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this cupboard? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A665: @ 826A665
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this window? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A6B6: @ 826A6B6
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this cushion? You're sharp!$"

Route110_TrickHouseEntrance_Text_26A709: @ 826A709
	.string "Behold!\p"
	.string "For I am the greatest living mystery\n"
	.string "of a man in all of HOENN!\l"
	.string "They call me…\p"
	.string "The TRICK MASTER!\n"
	.string "Wahahaha! Glad to meet you!$"

Route110_TrickHouseEntrance_Text_26A78C: @ 826A78C
	.string "You, you've come to challenge\n"
	.string "my TRICK HOUSE, haven't you?\p"
	.string "That's why you're here, isn't it?\n"
	.string "Yes, it is!\p"
	.string "Consider your challenge accepted!\p"
	.string "Enter through the scroll there,\n"
	.string "and let your challenge commence!\p"
	.string "I shall be waiting in the back!$"

Route110_TrickHouseEntrance_Text_26A878: @ 826A878
	.string "It's a scroll.$"

Route110_TrickHouseEntrance_Text_26A887: @ 826A887
	.string "There is a big hole behind the scroll!\p"
	.string "Want to go in?$"

Route110_TrickHouseEntrance_Text_26A8BD: @ 826A8BD
	.string "There is a note affixed to the scroll…\p"
	.string "“I am leaving on a journey.\n"
	.string "Don't look for me. TRICK MASTER”$"

Route110_TrickHouseEntrance_Text_26A921: @ 826A921
	.string "For the next time, I'll use this trick,\n"
	.string "and that scheme, and those ruses…\p"
	.string "Mufufufu… If I may say so, it's\n"
	.string "brilliantly difficult, even for me!$"

Route110_TrickHouseEntrance_Text_26A9AF: @ 826A9AF
	.string "Hah? What?!\n"
	.string "Oh, it's you!\p"
	.string "I'm in the midst of devising new tricky\n"
	.string "challenges!\p"
	.string "It's not too much to ask for a bit more\n"
	.string "time for me to think, is it now?\l"
	.string "You wouldn't begrudge me that?\l"
	.string "Come back in a little while!$"

Route110_TrickHouseEntrance_Text_26AA82: @ 826AA82
	.string "Ah, it's you! You're here to accept the\n"
	.string "reward from before, isn't that right?\l"
	.string "Yes, right I am!\p"
	.string "Here!\n"
	.string "I'll give it to you now!$"

Route110_TrickHouseEntrance_Text_26AB00: @ 826AB00
	.string "Hah?\n"
	.string "Did you not come to claim your reward?$"

Route110_TrickHouseEntrance_Text_26AB2C: @ 826AB2C
	.string "MECHADOLL 5 I AM!\n"
	.string "IF REWARD IS NOT TAKEN BY YOU,\l"
	.string "THEN TRICK MASTER YOU CANNOT FOLLOW.\p"
	.string "RED TENT OR BLUE TENT,\n"
	.string "WHICH DO YOU PREFER?$"

Route110_TrickHouseEntrance_Text_26ABAE: @ 826ABAE
	.string "THEN FAREWELL.$"

Route110_TrickHouseEntrance_Text_26ABBD: @ 826ABBD
	.string "YOUR PC STATUS: FULL AGAIN.\n"
	.string "MEAN, YOU ARE.$"

Route110_TrickHousePuzzle1_Text_26ABE8: @ 826ABE8
	.string "{PLAYER} found a scroll.$"

Route110_TrickHousePuzzle1_Text_26ABFB: @ 826ABFB
	.string "{PLAYER} memorized the secret code\n"
	.string "written on the scroll.$"

Route110_TrickHousePuzzle1_Text_26AC2F: @ 826AC2F
	.string "A secret code is written on it.$"

Route110_TrickHouseEntrance_Text_26AC4F: @ 826AC4F
	.string "The door is locked.\p"
	.string "…On closer inspection, this is written\n"
	.string "on it: “Write the secret code here.”$"
