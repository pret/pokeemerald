Route106_MapScripts:: @ 81EE489
	.byte 0

Route106_EventScript_1EE48A:: @ 81EE48A
	msgbox Route106_Text_1EE53A, MSGBOX_SIGN
	end

Route106_EventScript_1EE493:: @ 81EE493
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_2965BB, Route106_Text_2965FD
	msgbox Route106_Text_296608, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_1EE4AA:: @ 81EE4AA
	trainerbattle_single TRAINER_KYLA, Route106_Text_296628, Route106_Text_296674
	msgbox Route106_Text_29669E, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_1EE4C1:: @ 81EE4C1
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_296327, Route106_Text_29635C, Route106_EventScript_1EE4ED
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route106_EventScript_1EE50C
	msgbox Route106_Text_29638C, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_1EE4ED:: @ 81EE4ED
	special sub_80B4808
	waitmovement 0
	msgbox Route106_Text_2963E3, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_1EE50C:: @ 81EE50C
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_29642E, Route106_Text_296477
	msgbox Route106_Text_296493, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_1EE523:: @ 81EE523
	trainerbattle_single TRAINER_NED, Route106_Text_2964D4, Route106_Text_296553
	msgbox Route106_Text_296588, MSGBOX_AUTOCLOSE
	end

Route106_Text_1EE53A: @ 81EE53A
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

