Route110_TrickHouseEntrance_MapScripts:: @ 8269A50
	map_script 3, Route110_TrickHouseEntrance_MapScript1_269A60
	map_script 2, Route110_TrickHouseEntrance_MapScript2_269CEE
	map_script 4, Route110_TrickHouseEntrance_MapScript2_269BD3
	.byte 0

Route110_TrickHouseEntrance_MapScript1_269A60: @ 8269A60
	setflag FLAG_0x8A2
	compare_var_to_value VAR_0x40B5, 1
	goto_eq Route110_TrickHouseEntrance_EventScript_269AF3
	compare_var_to_value VAR_0x40C1, 1
	goto_eq Route110_TrickHouseEntrance_EventScript_269AD7
	compare_var_to_value VAR_0x40A6, 1
	goto_eq Route110_TrickHouseEntrance_EventScript_269BB3
	compare_var_to_value VAR_0x40A7, 5
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B03
	compare_var_to_value VAR_0x40A7, 3
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B03
	compare_var_to_value VAR_0x40A7, 0
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B03
	switch VAR_0x40A7
	case 0, Route110_TrickHouseEntrance_EventScript_269BBB
	case 1, Route110_TrickHouseEntrance_EventScript_269BC1
	case 3, Route110_TrickHouseEntrance_EventScript_269BC7
	case 4, Route110_TrickHouseEntrance_EventScript_269BCD
	end

Route110_TrickHouseEntrance_EventScript_269AD7:: @ 8269AD7
	setvar VAR_0x40A5, 1
	compare_var_to_value VAR_0x4044, 8
	goto_eq Route110_TrickHouseEntrance_EventScript_269AED
	setvar VAR_0x40A7, 2
	end

Route110_TrickHouseEntrance_EventScript_269AED:: @ 8269AED
	setvar VAR_0x40A7, 6
	end

Route110_TrickHouseEntrance_EventScript_269AF3:: @ 8269AF3
	setvar VAR_0x40B5, 0
	setvar VAR_0x40A7, 5
	setvar VAR_0x40A5, 1
	end

Route110_TrickHouseEntrance_EventScript_269B03:: @ 8269B03
	setvar VAR_0x40A7, 0
	compare_var_to_value VAR_0x4044, 1
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B61
	compare_var_to_value VAR_0x4044, 2
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B6B
	compare_var_to_value VAR_0x4044, 3
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B75
	compare_var_to_value VAR_0x4044, 4
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B7F
	compare_var_to_value VAR_0x4044, 5
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B89
	compare_var_to_value VAR_0x4044, 6
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B93
	compare_var_to_value VAR_0x4044, 7
	call_if 1, Route110_TrickHouseEntrance_EventScript_269B9D
	compare_var_to_value VAR_0x4044, 8
	call_if 1, Route110_TrickHouseEntrance_EventScript_269BA7
	return

Route110_TrickHouseEntrance_EventScript_269B61:: @ 8269B61
	checkflag FLAG_BADGE03_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B6B:: @ 8269B6B
	checkflag FLAG_BADGE04_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B75:: @ 8269B75
	checkflag FLAG_BADGE05_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B7F:: @ 8269B7F
	checkflag FLAG_BADGE06_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B89:: @ 8269B89
	checkflag FLAG_BADGE07_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B93:: @ 8269B93
	checkflag FLAG_BADGE08_GET
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269B9D:: @ 8269B9D
	checkflag FLAG_SYS_GAME_CLEAR
	call_if 0, Route110_TrickHouseEntrance_EventScript_269BAD
	return

Route110_TrickHouseEntrance_EventScript_269BA7:: @ 8269BA7
	setvar VAR_0x40A7, 4
	return

Route110_TrickHouseEntrance_EventScript_269BAD:: @ 8269BAD
	setvar VAR_0x40A7, 3
	return

Route110_TrickHouseEntrance_EventScript_269BB3:: @ 8269BB3
	setobjectxyperm 1, 5, 2
	end

Route110_TrickHouseEntrance_EventScript_269BBB:: @ 8269BBB
	setvar VAR_0x40A5, 0
	end

Route110_TrickHouseEntrance_EventScript_269BC1:: @ 8269BC1
	setvar VAR_0x40A5, 1
	end

Route110_TrickHouseEntrance_EventScript_269BC7:: @ 8269BC7
	setvar VAR_0x40A5, 1
	end

Route110_TrickHouseEntrance_EventScript_269BCD:: @ 8269BCD
	setvar VAR_0x40A5, 1
	end

Route110_TrickHouseEntrance_MapScript2_269BD3: @ 8269BD3
	map_script_2 VAR_0x40A6, 1, Route110_TrickHouseEntrance_EventScript_269C15
	map_script_2 VAR_0x40A7, 0, Route110_TrickHouseEntrance_EventScript_269C26
	map_script_2 VAR_0x40A7, 1, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_0x40A7, 2, Route110_TrickHouseEntrance_EventScript_269CD0
	map_script_2 VAR_0x40A7, 3, Route110_TrickHouseEntrance_EventScript_269CD0
	map_script_2 VAR_0x40A7, 4, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_0x40A7, 5, Route110_TrickHouseEntrance_EventScript_269CCC
	map_script_2 VAR_0x40A7, 6, Route110_TrickHouseEntrance_EventScript_269CDF
	.2byte 0

Route110_TrickHouseEntrance_EventScript_269C15:: @ 8269C15
	addobject 1
	showobjectat 1, ROUTE_110_TRICK_HOUSE_ENTRANCE
	turnobject 1, 4
	turnobject 255, 3
	end

Route110_TrickHouseEntrance_EventScript_269C26:: @ 8269C26
	addobject 1
	hideobjectat 1, ROUTE_110_TRICK_HOUSE_ENTRANCE
	switch VAR_0x4044
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
	map_script_2 VAR_0x40A6, 1, Route110_TrickHouseEntrance_EventScript_269CF8
	.2byte 0

Route110_TrickHouseEntrance_EventScript_269CF8:: @ 8269CF8
	lockall
	delay 20
	compare_var_to_value VAR_0x4044, 0
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E48
	msgbox Route110_TrickHouseEntrance_Text_26A78C, 4
	closemessage
	delay 20
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E36
	waitmovement 0
	playse SE_W153
	applymovement 1, Route110_TrickHouseEntrance_Movement_269E3F
	waitmovement 0
	removeobject 1
	setvar VAR_0x40A7, 1
	setvar VAR_0x40A6, 0
	releaseall
	end

	.incbin "baserom.gba", 0x269d39, 0x2

Route110_TrickHouseEntrance_EventScript_269D3B:: @ 8269D3B
	lockall
	switch VAR_0x40A7
	case 0, Route110_TrickHouseEntrance_EventScript_269D6E
	case 2, Route110_TrickHouseEntrance_EventScript_269E8F
	case 3, Route110_TrickHouseEntrance_EventScript_269E51
	case 6, Route110_TrickHouseEntrance_EventScript_26A039
	end

Route110_TrickHouseEntrance_EventScript_269D6E:: @ 8269D6E
	playse SE_PIN
	applymovement 255, Route110_TrickHouseEntrance_Movement_272598
	waitmovement 0
	applymovement 255, Route110_TrickHouseEntrance_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x4044, 0
	call_if 1, Route110_TrickHouseEntrance_EventScript_269DEE
	compare_var_to_value VAR_0x4044, 1
	call_if 1, Route110_TrickHouseEntrance_EventScript_269DF7
	compare_var_to_value VAR_0x4044, 2
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E00
	compare_var_to_value VAR_0x4044, 3
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E09
	compare_var_to_value VAR_0x4044, 4
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E12
	compare_var_to_value VAR_0x4044, 5
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E1B
	compare_var_to_value VAR_0x4044, 6
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E24
	compare_var_to_value VAR_0x4044, 7
	call_if 1, Route110_TrickHouseEntrance_EventScript_269E2D
	closemessage
	setvar VAR_0x40A6, 1
	warpsilent ROUTE_110_TRICK_HOUSE_ENTRANCE, 255, 6, 2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_269DEE:: @ 8269DEE
	msgbox Route110_TrickHouseEntrance_Text_26A48A, 4
	return

Route110_TrickHouseEntrance_EventScript_269DF7:: @ 8269DF7
	msgbox Route110_TrickHouseEntrance_Text_26A4DA, 4
	return

Route110_TrickHouseEntrance_EventScript_269E00:: @ 8269E00
	msgbox Route110_TrickHouseEntrance_Text_26A529, 4
	return

Route110_TrickHouseEntrance_EventScript_269E09:: @ 8269E09
	msgbox Route110_TrickHouseEntrance_Text_26A577, 4
	return

Route110_TrickHouseEntrance_EventScript_269E12:: @ 8269E12
	msgbox Route110_TrickHouseEntrance_Text_26A5C8, 4
	return

Route110_TrickHouseEntrance_EventScript_269E1B:: @ 8269E1B
	msgbox Route110_TrickHouseEntrance_Text_26A616, 4
	return

Route110_TrickHouseEntrance_EventScript_269E24:: @ 8269E24
	msgbox Route110_TrickHouseEntrance_Text_26A665, 4
	return

Route110_TrickHouseEntrance_EventScript_269E2D:: @ 8269E2D
	msgbox Route110_TrickHouseEntrance_Text_26A6B6, 4
	return

