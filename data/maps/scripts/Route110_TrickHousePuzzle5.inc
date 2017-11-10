Route110_TrickHousePuzzle5_MapScripts:: @ 826CAF0
	map_script 3, Route110_TrickHousePuzzle5_MapScript1_26CAF6
	.byte 0

Route110_TrickHousePuzzle5_MapScript1_26CAF6: @ 826CAF6
	setvar VAR_0x4001, 0
	setvar VAR_0x4002, 0
	setvar VAR_0x4003, 0
	setvar VAR_0x4004, 0
	setvar VAR_0x4005, 0
	setvar VAR_0x4008, 0
	end

Route110_TrickHousePuzzle5_EventScript_26CB15:: @ 826CB15
	lockall
	compare_var_to_value VAR_0x40AF, 0
	goto_eq Route110_TrickHousePuzzle5_EventScript_26CB27
	goto Route110_TrickHousePuzzle5_EventScript_26A3DB
	end

Route110_TrickHousePuzzle5_EventScript_26CB27:: @ 826CB27
	setvar VAR_0x40AF, 1
	goto Route110_TrickHousePuzzle5_EventScript_26A3E5
	end

Route110_TrickHousePuzzle5_EventScript_26CB32:: @ 826CB32
	lockall
	applymovement 1, Route110_TrickHousePuzzle5_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x4001, 1
	goto_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CB53:: @ 826CB53
	lockall
	applymovement 2, Route110_TrickHousePuzzle5_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x4002, 1
	goto_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CB74:: @ 826CB74
	lockall
	applymovement 3, Route110_TrickHousePuzzle5_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x4003, 1
	goto_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CB95:: @ 826CB95
	lockall
	applymovement 4, Route110_TrickHousePuzzle5_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x4004, 1
	goto_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CBB6:: @ 826CBB6
	lockall
	applymovement 5, Route110_TrickHousePuzzle5_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x4005, 1
	goto_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CEF2
	end

Route110_TrickHousePuzzle5_EventScript_26CBD7:: @ 826CBD7
	lockall
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBE3:: @ 826CBE3
	lockall
	setvar VAR_0x4009, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBEF:: @ 826CBEF
	lockall
	setvar VAR_0x4009, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBFB:: @ 826CBFB
	lockall
	setvar VAR_0x4009, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CC07:: @ 826CC07
	lockall
	setvar VAR_0x4009, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CC13:: @ 826CC13
	lockall
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC1F:: @ 826CC1F
	lockall
	setvar VAR_0x4009, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC2B:: @ 826CC2B
	lockall
	setvar VAR_0x4009, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC37:: @ 826CC37
	lockall
	setvar VAR_0x4009, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC43:: @ 826CC43
	lockall
	setvar VAR_0x4009, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC4F:: @ 826CC4F
	lockall
	setvar VAR_0x4009, 5
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC5B:: @ 826CC5B
	lockall
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC67:: @ 826CC67
	lockall
	setvar VAR_0x4009, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC73:: @ 826CC73
	lockall
	setvar VAR_0x4009, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC7F:: @ 826CC7F
	lockall
	setvar VAR_0x4009, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC8B:: @ 826CC8B
	lockall
	setvar VAR_0x4009, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC97:: @ 826CC97
	lockall
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCA3:: @ 826CCA3
	lockall
	setvar VAR_0x4009, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCAF:: @ 826CCAF
	lockall
	setvar VAR_0x4009, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCBB:: @ 826CCBB
	lockall
	setvar VAR_0x4009, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCC7:: @ 826CCC7
	lockall
	setvar VAR_0x4009, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

	.incbin "baserom.gba", 0x26ccd3, 0xc

Route110_TrickHousePuzzle5_EventScript_26CCDF:: @ 826CCDF
	lockall
	setvar VAR_0x4009, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CEF2
	end

Route110_TrickHousePuzzle5_EventScript_26CCEB:: @ 826CCEB
	setvar VAR_0x4001, 1
	setvar VAR_0x4008, 1
	playse SE_PIN
	applymovement 1, Route110_TrickHousePuzzle5_Movement_272598
	waitmovement 0
	applymovement 1, Route110_TrickHousePuzzle5_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x4009, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare_var_to_value VAR_0x4009, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare_var_to_value VAR_0x4009, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D224
	compare_var_to_value VAR_0x4009, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26D6CE, 4
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26CF45
	case 1, Route110_TrickHousePuzzle5_EventScript_26CF68
	case 2, Route110_TrickHousePuzzle5_EventScript_26CF8B
	end

Route110_TrickHousePuzzle5_EventScript_26CD6A:: @ 826CD6A
	setvar VAR_0x4002, 1
	setvar VAR_0x4008, 2
	playse SE_PIN
	applymovement 2, Route110_TrickHousePuzzle5_Movement_272598
	waitmovement 0
	applymovement 2, Route110_TrickHousePuzzle5_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x4009, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D2CC
	compare_var_to_value VAR_0x4009, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D304
	compare_var_to_value VAR_0x4009, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D33C
	compare_var_to_value VAR_0x4009, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D374
	compare_var_to_value VAR_0x4009, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D3AC
	msgbox Route110_TrickHousePuzzle5_Text_26D8EA, 4
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26CFAE
	case 1, Route110_TrickHousePuzzle5_EventScript_26CFD1
	case 2, Route110_TrickHousePuzzle5_EventScript_26CFF4
	end

Route110_TrickHousePuzzle5_EventScript_26CDF4:: @ 826CDF4
	setvar VAR_0x4003, 1
	setvar VAR_0x4008, 3
	playse SE_PIN
	applymovement 3, Route110_TrickHousePuzzle5_Movement_272598
	waitmovement 0
	applymovement 3, Route110_TrickHousePuzzle5_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x4009, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare_var_to_value VAR_0x4009, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare_var_to_value VAR_0x4009, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D224
	compare_var_to_value VAR_0x4009, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26DA1E, 4
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D017
	case 1, Route110_TrickHousePuzzle5_EventScript_26D03A
	case 2, Route110_TrickHousePuzzle5_EventScript_26D05D
	end

Route110_TrickHousePuzzle5_EventScript_26CE73:: @ 826CE73
	setvar VAR_0x4004, 1
	setvar VAR_0x4008, 4
	playse SE_PIN
	applymovement 4, Route110_TrickHousePuzzle5_Movement_272598
	waitmovement 0
	applymovement 4, Route110_TrickHousePuzzle5_Movement_27259A
	waitmovement 0
	compare_var_to_value VAR_0x4009, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare_var_to_value VAR_0x4009, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare_var_to_value VAR_0x4009, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D224
	compare_var_to_value VAR_0x4009, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26DB4C, 4
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D080
	case 1, Route110_TrickHousePuzzle5_EventScript_26D0A3
	case 2, Route110_TrickHousePuzzle5_EventScript_26D0C6
	end

Route110_TrickHousePuzzle5_EventScript_26CEF2:: @ 826CEF2
	setvar VAR_0x4005, 1
	setvar VAR_0x4008, 5
	playse SE_PIN
	applymovement 5, Route110_TrickHousePuzzle5_Movement_272598
	waitmovement 0
	applymovement 5, Route110_TrickHousePuzzle5_Movement_27259A
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_26DC78, 4
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D0E9
	case 1, Route110_TrickHousePuzzle5_EventScript_26D10C
	case 2, Route110_TrickHousePuzzle5_EventScript_26D12F
	end

Route110_TrickHousePuzzle5_EventScript_26CF45:: @ 826CF45
	msgbox Route110_TrickHousePuzzle5_Text_26D757, 4
	multichoice 0, 0, 25, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CF68:: @ 826CF68
	msgbox Route110_TrickHousePuzzle5_Text_26D7AA, 4
	multichoice 0, 0, 26, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CF8B:: @ 826CF8B
	msgbox Route110_TrickHousePuzzle5_Text_26D7FC, 4
	multichoice 0, 0, 27, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFAE:: @ 826CFAE
	msgbox Route110_TrickHousePuzzle5_Text_26D940, 4
	multichoice 0, 0, 28, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFD1:: @ 826CFD1
	msgbox Route110_TrickHousePuzzle5_Text_26D98C, 4
	multichoice 0, 0, 29, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFF4:: @ 826CFF4
	msgbox Route110_TrickHousePuzzle5_Text_26D9CE, 4
	multichoice 0, 0, 30, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D017:: @ 826D017
	msgbox Route110_TrickHousePuzzle5_Text_26DA64, 4
	multichoice 0, 0, 31, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D03A:: @ 826D03A
	msgbox Route110_TrickHousePuzzle5_Text_26DAAD, 4
	multichoice 0, 0, 32, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D05D:: @ 826D05D
	msgbox Route110_TrickHousePuzzle5_Text_26DAFF, 4
	multichoice 0, 0, 33, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D080:: @ 826D080
	msgbox Route110_TrickHousePuzzle5_Text_26DB94, 4
	multichoice 0, 0, 34, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0A3:: @ 826D0A3
	msgbox Route110_TrickHousePuzzle5_Text_26DBD7, 4
	multichoice 0, 0, 35, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0C6:: @ 826D0C6
	msgbox Route110_TrickHousePuzzle5_Text_26DC2A, 4
	multichoice 0, 0, 36, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0E9:: @ 826D0E9
	msgbox Route110_TrickHousePuzzle5_Text_26DCCB, 4
	multichoice 0, 0, 37, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D10C:: @ 826D10C
	msgbox Route110_TrickHousePuzzle5_Text_26DD1B, 4
	multichoice 0, 0, 38, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D12F:: @ 826D12F
	msgbox Route110_TrickHousePuzzle5_Text_26DD5F, 4
	multichoice 0, 0, 39, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D152:: @ 826D152
	waitse
	playse SE_HAZURE
	msgbox Route110_TrickHousePuzzle5_Text_26D883, 4
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D632
	msgbox Route110_TrickHousePuzzle5_Text_26D8A1, 4
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_26D8C9, 4
	closemessage
	warp ROUTE_110_TRICK_HOUSE_PUZZLE_5, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_26D1A0:: @ 826D1A0
	waitse
	playse SE_SEIKAI
	goto Route110_TrickHousePuzzle5_EventScript_26D1AA
	end

Route110_TrickHousePuzzle5_EventScript_26D1AA:: @ 826D1AA
	msgbox Route110_TrickHousePuzzle5_Text_26D84D, 4
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_26D1B4:: @ 826D1B4
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D3E4
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D3EF
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D3FA
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D405
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D410
	return

Route110_TrickHousePuzzle5_EventScript_26D1EC:: @ 826D1EC
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D41B
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D426
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D431
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D43C
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D447
	return

Route110_TrickHousePuzzle5_EventScript_26D224:: @ 826D224
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D452
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D45D
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D468
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D473
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D47E
	return

Route110_TrickHousePuzzle5_EventScript_26D25C:: @ 826D25C
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D489
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D494
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D49F
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D4AA
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D4B5
	return

	.incbin "baserom.gba", 0x26d294, 0x38

Route110_TrickHousePuzzle5_EventScript_26D2CC:: @ 826D2CC
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D4F7
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D502
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D50D
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D518
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D523
	return

Route110_TrickHousePuzzle5_EventScript_26D304:: @ 826D304
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D52E
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D539
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D544
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D54F
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D55A
	return

Route110_TrickHousePuzzle5_EventScript_26D33C:: @ 826D33C
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D565
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D570
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D57B
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D586
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D591
	return

Route110_TrickHousePuzzle5_EventScript_26D374:: @ 826D374
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D59C
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5A7
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5B2
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5BD
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5C8
	return

Route110_TrickHousePuzzle5_EventScript_26D3AC:: @ 826D3AC
	compare_var_to_value VAR_0x4008, 1
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5D3
	compare_var_to_value VAR_0x4008, 2
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5DE
	compare_var_to_value VAR_0x4008, 3
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5E9
	compare_var_to_value VAR_0x4008, 4
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5F4
	compare_var_to_value VAR_0x4008, 5
	call_if 1, Route110_TrickHousePuzzle5_EventScript_26D5FF
	return

Route110_TrickHousePuzzle5_EventScript_26D3E4:: @ 826D3E4
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D60A
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D3EF:: @ 826D3EF
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D60A
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D3FA:: @ 826D3FA
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D60A
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D405:: @ 826D405
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D60A
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D410:: @ 826D410
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D60A
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D41B:: @ 826D41B
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D60C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D426:: @ 826D426
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D60C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D431:: @ 826D431
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D60C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D43C:: @ 826D43C
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D60C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D447:: @ 826D447
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D60C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D452:: @ 826D452
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D60F
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D45D:: @ 826D45D
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D60F
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D468:: @ 826D468
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D60F
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D473:: @ 826D473
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D60F
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D47E:: @ 826D47E
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D60F
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D489:: @ 826D489
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D613
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D494:: @ 826D494
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D613
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D49F:: @ 826D49F
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D613
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4AA:: @ 826D4AA
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D613
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4B5:: @ 826D4B5
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D613
	waitmovement 0
	return

	.incbin "baserom.gba", 0x26d4c0, 0x37

Route110_TrickHousePuzzle5_EventScript_26D4F7:: @ 826D4F7
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D61E
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D502:: @ 826D502
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D61E
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D50D:: @ 826D50D
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D61E
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D518:: @ 826D518
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D61E
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D523:: @ 826D523
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D61E
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D52E:: @ 826D52E
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D620
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D539:: @ 826D539
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D620
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D544:: @ 826D544
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D620
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D54F:: @ 826D54F
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D620
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D55A:: @ 826D55A
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D620
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D565:: @ 826D565
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D623
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D570:: @ 826D570
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D623
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D57B:: @ 826D57B
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D623
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D586:: @ 826D586
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D623
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D591:: @ 826D591
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D623
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D59C:: @ 826D59C
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D627
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5A7:: @ 826D5A7
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D627
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5B2:: @ 826D5B2
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D627
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5BD:: @ 826D5BD
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D627
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5C8:: @ 826D5C8
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D627
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5D3:: @ 826D5D3
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D62C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5DE:: @ 826D5DE
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D62C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5E9:: @ 826D5E9
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D62C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5F4:: @ 826D5F4
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D62C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D5FF:: @ 826D5FF
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D62C
	waitmovement 0
	return

Route110_TrickHousePuzzle5_Movement_26D60A: @ 826D60A
	step_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D60C: @ 826D60C
	step_left
	step_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D60F: @ 826D60F
	step_left
	step_left
	step_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D613: @ 826D613
	step_left
	step_left
	step_left
	step_left
	step_end

	.incbin "baserom.gba", 0x26d618, 0x6

Route110_TrickHousePuzzle5_Movement_26D61E: @ 826D61E
	step_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D620: @ 826D620
	step_right
	step_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D623: @ 826D623
	step_right
	step_right
	step_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D627: @ 826D627
	step_right
	step_right
	step_right
	step_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D62C: @ 826D62C
	step_right
	step_right
	step_right
	step_right
	step_right
	step_end

