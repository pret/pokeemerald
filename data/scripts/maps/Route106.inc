Route106_MapScripts:: @ 81EE489
	.byte 0

Route106_EventScript_1EE48A:: @ 81EE48A
	msgbox Route106_Text_1EE53A, 3
	end

Route106_EventScript_1EE493:: @ 81EE493
	trainerbattle 0, TRAINER_DOUGLAS, 0, Route106_Text_2965BB, Route106_Text_2965FD
	msgbox Route106_Text_296608, 6
	end

Route106_EventScript_1EE4AA:: @ 81EE4AA
	trainerbattle 0, TRAINER_KYLA, 0, Route106_Text_296628, Route106_Text_296674
	msgbox Route106_Text_29669E, 6
	end

Route106_EventScript_1EE4C1:: @ 81EE4C1
	trainerbattle 2, TRAINER_ELLIOT_1, 0, Route106_Text_296327, Route106_Text_29635C, Route106_EventScript_1EE4ED
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route106_EventScript_1EE50C
	msgbox Route106_Text_29638C, 4
	release
	end

Route106_EventScript_1EE4ED:: @ 81EE4ED
	special sub_80B4808
	waitmovement 0
	msgbox Route106_Text_2963E3, 4
	setvar VAR_0x8004, 339
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 339
	callstd 8
	release
	end

Route106_EventScript_1EE50C:: @ 81EE50C
	trainerbattle 5, TRAINER_ELLIOT_1, 0, Route106_Text_29642E, Route106_Text_296477
	msgbox Route106_Text_296493, 6
	end

Route106_EventScript_1EE523:: @ 81EE523
	trainerbattle 0, TRAINER_NED, 0, Route106_Text_2964D4, Route106_Text_296553
	msgbox Route106_Text_296588, 6
	end

Route106_Text_1EE53A: @ 81EE53A
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

