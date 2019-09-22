Route110_TrickHousePuzzle5_MapScripts:: @ 826CAF0
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
	.byte 0

Route110_TrickHousePuzzle5_OnTransition: @ 826CAF6
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_8, 0
	end

Route110_TrickHousePuzzle5_EventScript_26CB15:: @ 826CB15
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26CB27
	goto Route110_TrickHousePuzzle5_EventScript_26A3DB
	end

Route110_TrickHousePuzzle5_EventScript_26CB27:: @ 826CB27
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
	goto Route110_TrickHousePuzzle5_EventScript_26A3E5
	end

Route110_TrickHousePuzzle5_EventScript_26CB32:: @ 826CB32
	lockall
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_1, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CB53:: @ 826CB53
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_2, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CB74:: @ 826CB74
	lockall
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_3, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CB95:: @ 826CB95
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_4, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CBB6:: @ 826CBB6
	lockall
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_5, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_26D1AA
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CEF2
	end

Route110_TrickHousePuzzle5_EventScript_26CBD7:: @ 826CBD7
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBE3:: @ 826CBE3
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBEF:: @ 826CBEF
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CBFB:: @ 826CBFB
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CC07:: @ 826CC07
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CCEB
	end

Route110_TrickHousePuzzle5_EventScript_26CC13:: @ 826CC13
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC1F:: @ 826CC1F
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC2B:: @ 826CC2B
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC37:: @ 826CC37
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC43:: @ 826CC43
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC4F:: @ 826CC4F
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_26CD6A
	end

Route110_TrickHousePuzzle5_EventScript_26CC5B:: @ 826CC5B
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC67:: @ 826CC67
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC73:: @ 826CC73
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC7F:: @ 826CC7F
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC8B:: @ 826CC8B
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CDF4
	end

Route110_TrickHousePuzzle5_EventScript_26CC97:: @ 826CC97
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCA3:: @ 826CCA3
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCAF:: @ 826CCAF
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCBB:: @ 826CCBB
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCC7:: @ 826CCC7
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCD3:: @ 826CCD3
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_26CE73
	end

Route110_TrickHousePuzzle5_EventScript_26CCDF:: @ 826CCDF
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_26CEF2
	end

Route110_TrickHousePuzzle5_EventScript_26CCEB:: @ 826CCEB
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_8, 1
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D224
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26D6CE, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26CF45
	case 1, Route110_TrickHousePuzzle5_EventScript_26CF68
	case 2, Route110_TrickHousePuzzle5_EventScript_26CF8B
	end

Route110_TrickHousePuzzle5_EventScript_26CD6A:: @ 826CD6A
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_8, 2
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D2CC
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D304
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D33C
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D374
	compare VAR_TEMP_9, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D3AC
	msgbox Route110_TrickHousePuzzle5_Text_26D8EA, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26CFAE
	case 1, Route110_TrickHousePuzzle5_EventScript_26CFD1
	case 2, Route110_TrickHousePuzzle5_EventScript_26CFF4
	end

Route110_TrickHousePuzzle5_EventScript_26CDF4:: @ 826CDF4
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_8, 3
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D224
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26DA1E, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D017
	case 1, Route110_TrickHousePuzzle5_EventScript_26D03A
	case 2, Route110_TrickHousePuzzle5_EventScript_26D05D
	end

Route110_TrickHousePuzzle5_EventScript_26CE73:: @ 826CE73
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_8, 4
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1B4
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D1EC
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D224
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D25C
	msgbox Route110_TrickHousePuzzle5_Text_26DB4C, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D080
	case 1, Route110_TrickHousePuzzle5_EventScript_26D0A3
	case 2, Route110_TrickHousePuzzle5_EventScript_26D0C6
	end

Route110_TrickHousePuzzle5_EventScript_26CEF2:: @ 826CEF2
	setvar VAR_TEMP_5, 1
	setvar VAR_TEMP_8, 5
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_26DC78, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D0E9
	case 1, Route110_TrickHousePuzzle5_EventScript_26D10C
	case 2, Route110_TrickHousePuzzle5_EventScript_26D12F
	end

Route110_TrickHousePuzzle5_EventScript_26CF45:: @ 826CF45
	msgbox Route110_TrickHousePuzzle5_Text_26D757, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CF68:: @ 826CF68
	msgbox Route110_TrickHousePuzzle5_Text_26D7AA, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CF8B:: @ 826CF8B
	msgbox Route110_TrickHousePuzzle5_Text_26D7FC, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFAE:: @ 826CFAE
	msgbox Route110_TrickHousePuzzle5_Text_26D940, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFD1:: @ 826CFD1
	msgbox Route110_TrickHousePuzzle5_Text_26D98C, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26CFF4:: @ 826CFF4
	msgbox Route110_TrickHousePuzzle5_Text_26D9CE, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D017:: @ 826D017
	msgbox Route110_TrickHousePuzzle5_Text_26DA64, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D03A:: @ 826D03A
	msgbox Route110_TrickHousePuzzle5_Text_26DAAD, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D05D:: @ 826D05D
	msgbox Route110_TrickHousePuzzle5_Text_26DAFF, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D080:: @ 826D080
	msgbox Route110_TrickHousePuzzle5_Text_26DB94, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0A3:: @ 826D0A3
	msgbox Route110_TrickHousePuzzle5_Text_26DBD7, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0C6:: @ 826D0C6
	msgbox Route110_TrickHousePuzzle5_Text_26DC2A, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D0E9:: @ 826D0E9
	msgbox Route110_TrickHousePuzzle5_Text_26DCCB, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D10C:: @ 826D10C
	msgbox Route110_TrickHousePuzzle5_Text_26DD1B, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D12F:: @ 826D12F
	msgbox Route110_TrickHousePuzzle5_Text_26DD5F, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_26D1A0
	goto Route110_TrickHousePuzzle5_EventScript_26D152
	end

Route110_TrickHousePuzzle5_EventScript_26D152:: @ 826D152
	waitse
	playse SE_HAZURE
	msgbox Route110_TrickHousePuzzle5_Text_26D883, MSGBOX_DEFAULT
	applymovement 1, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 2, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 3, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 4, Route110_TrickHousePuzzle5_Movement_26D632
	applymovement 5, Route110_TrickHousePuzzle5_Movement_26D632
	msgbox Route110_TrickHousePuzzle5_Text_26D8A1, MSGBOX_DEFAULT
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_26D8C9, MSGBOX_DEFAULT
	closemessage
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_26D1A0:: @ 826D1A0
	waitse
	playse SE_SEIKAI
	goto Route110_TrickHousePuzzle5_EventScript_26D1AA
	end

Route110_TrickHousePuzzle5_EventScript_26D1AA:: @ 826D1AA
	msgbox Route110_TrickHousePuzzle5_Text_26D84D, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_26D1B4:: @ 826D1B4
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D3E4
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D3EF
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D3FA
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D405
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D410
	return

Route110_TrickHousePuzzle5_EventScript_26D1EC:: @ 826D1EC
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D41B
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D426
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D431
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D43C
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D447
	return

Route110_TrickHousePuzzle5_EventScript_26D224:: @ 826D224
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D452
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D45D
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D468
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D473
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D47E
	return

Route110_TrickHousePuzzle5_EventScript_26D25C:: @ 826D25C
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D489
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D494
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D49F
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4AA
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4B5
	return

Route110_TrickHousePuzzle5_EventScript_26D294:: @ 826D294
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4C0
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4CB
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4D6
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4E1
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4EC
	return

Route110_TrickHousePuzzle5_EventScript_26D2CC:: @ 826D2CC
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D4F7
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D502
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D50D
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D518
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D523
	return

Route110_TrickHousePuzzle5_EventScript_26D304:: @ 826D304
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D52E
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D539
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D544
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D54F
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D55A
	return

Route110_TrickHousePuzzle5_EventScript_26D33C:: @ 826D33C
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D565
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D570
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D57B
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D586
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D591
	return

Route110_TrickHousePuzzle5_EventScript_26D374:: @ 826D374
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D59C
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5A7
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5B2
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5BD
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5C8
	return

Route110_TrickHousePuzzle5_EventScript_26D3AC:: @ 826D3AC
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5D3
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5DE
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5E9
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5F4
	compare VAR_TEMP_8, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_26D5FF
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

Route110_TrickHousePuzzle5_EventScript_26D4C0:: @ 826D4C0
	applymovement 1, Movement_26D618
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4CB:: @ 826D4CB
	applymovement 2, Movement_26D618
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4D6:: @ 826D4D6
	applymovement 3, Movement_26D618
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4E1:: @ 826D4E1
	applymovement 4, Movement_26D618
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_26D4EC:: @ 826D4EC
	applymovement 5, Movement_26D618
	waitmovement 0
	return

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
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D60C: @ 826D60C
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D60F: @ 826D60F
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D613: @ 826D613
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


Movement_26D618: @ 826D618
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_26D61E: @ 826D61E
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D620: @ 826D620
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D623: @ 826D623
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D627: @ 826D627
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_26D62C: @ 826D62C
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHouseEntrance_Movement_26D632: @ 826D632
Route110_TrickHousePuzzle5_Movement_26D632: @ 826D632
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_down
	step_end

Route110_TrickHousePuzzle5_Text_26D660: @ 826D660
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is a genius.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle5_Text_26D6CE: @ 826D6CE
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 1 AM I!\p"
	.string "IF YOU ANSWER QUIZZES CORRECTLY,\n"
	.string "THEN YOU WILL GO TO MECHADOLL 5.\l"
	.string "THEN YOU CAN OBTAIN THE SECRET CODE.$"

Route110_TrickHousePuzzle5_Text_26D757: @ 826D757
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON is not found\n"
	.string "on ROUTE 110. Which one is it?$"

Route110_TrickHousePuzzle5_Text_26D7AA: @ 826D7AA
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON is not of the\n"
	.string "WATER type. Which one is it?$"

Route110_TrickHousePuzzle5_Text_26D7FC: @ 826D7FC
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON does not use\n"
	.string "LEECH LIFE. Which one is it?$"

Route110_TrickHousePuzzle5_Text_26D84D: @ 826D84D
	.string "CONGRATULATIONS. CORRECT YOU ARE.\n"
	.string "GO THROUGH. PLEASE.$"

Route110_TrickHousePuzzle5_Text_26D883: @ 826D883
	.string "BZZZT. DISAPPOINTMENT.\n"
	.string "ERROR.$"

Route110_TrickHousePuzzle5_Text_26D8A1: @ 826D8A1
	.string "WAHAHAHAHA! WAHAHAHAHA!\n"
	.string "CLICKETY-CLACK!$"

Route110_TrickHousePuzzle5_Text_26D8C9: @ 826D8C9
	.string "YOUR NEXT CHALLENGE WE WAIT FOR.$"

Route110_TrickHousePuzzle5_Text_26D8EA: @ 826D8EA
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 2 AM I!\p"
	.string "MECHADOLL 1'S QUIZ DIFFICULTY LEVEL\n"
	.string "IS SET TOO LOW.$"

Route110_TrickHousePuzzle5_Text_26D940: @ 826D940
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON did WALLY\n"
	.string "borrow from your father?$"

Route110_TrickHousePuzzle5_Text_26D98C: @ 826D98C
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON was chasing\n"
	.string "PROF. BIRCH?$"

Route110_TrickHousePuzzle5_Text_26D9CE: @ 826D9CE
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON did TEAM AQUA\n"
	.string "use in PETALBURG FOREST?$"

Route110_TrickHousePuzzle5_Text_26DA1E: @ 826DA1E
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 3 AM I!\p"
	.string "MATTERS OF MONEY ARE MY SOLE FOCUS.$"

Route110_TrickHousePuzzle5_Text_26DA64: @ 826DA64
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Which costs more?\n"
	.string "Three HARBOR MAILS or one BURN HEAL?$"

Route110_TrickHousePuzzle5_Text_26DAAD: @ 826DAAD
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Sell one GREAT BALL and buy\n"
	.string "one POTION. How much money remains?$"

Route110_TrickHousePuzzle5_Text_26DAFF: @ 826DAFF
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Do one REPEL and SODA POP cost\n"
	.string "more than one SUPER POTION?$"

Route110_TrickHousePuzzle5_Text_26DB4C: @ 826DB4C
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 4 THAT IS ME!\p"
	.string "MY QUIZ IS AN OBJECT OF BEAUTY.$"

Route110_TrickHousePuzzle5_Text_26DB94: @ 826DB94
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In SEASHORE HOUSE, were there more men\n"
	.string "or women?$"

Route110_TrickHousePuzzle5_Text_26DBD7: @ 826DBD7
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In LAVARIDGE TOWN, were there more\n"
	.string "elderly men or elderly women?$"

Route110_TrickHousePuzzle5_Text_26DC2A: @ 826DC2A
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In the TRAINER'S SCHOOL, how many\n"
	.string "girl students were there?$"

Route110_TrickHousePuzzle5_Text_26DC78: @ 826DC78
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 5 AM I!\p"
	.string "THE MASTER'S BEST AND PROUDEST\n"
	.string "ACHIEVEMENT AM I.$"

Route110_TrickHousePuzzle5_Text_26DCCB: @ 826DCCB
	.string "MECHADOLL 5 QUIZ.\p"
	.string "In SLATEPORT's POKéMON FAN CLUB,\n"
	.string "how many POKéMON were there?$"

Route110_TrickHousePuzzle5_Text_26DD1B: @ 826DD1B
	.string "MECHADOLL 5 QUIZ.\p"
	.string "In FORTREE CITY, how many\n"
	.string "tree houses were there?$"

Route110_TrickHousePuzzle5_Text_26DD5F: @ 826DD5F
	.string "MECHADOLL 5 QUIZ.\p"
	.string "On the CYCLING ROAD, how many\n"
	.string "TRIATHLETES were there?$"
