Route107_MapScripts:: @ 81EE594
	.byte 0

Route107_EventScript_1EE595:: @ 81EE595
	trainerbattle_single TRAINER_DARRIN, Route107_Text_2966E5, Route107_Text_29672F
	msgbox Route107_Text_29675B, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE5AC:: @ 81EE5AC
	trainerbattle_single TRAINER_TONY_1, Route107_Text_2967AD, Route107_Text_2967D8, Route107_EventScript_1EE5D8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route107_EventScript_1EE5F7
	msgbox Route107_Text_2967FF, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_1EE5D8:: @ 81EE5D8
	special sub_80B4808
	waitmovement 0
	msgbox Route107_Text_29685A, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route107_EventScript_1EE5F7:: @ 81EE5F7
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_296897, Route107_Text_2968D5
	msgbox Route107_Text_296923, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE60E:: @ 81EE60E
	trainerbattle_single TRAINER_DENISE, Route107_Text_296974, Route107_Text_29699E
	msgbox Route107_Text_2969AB, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE625:: @ 81EE625
	trainerbattle_single TRAINER_BETH, Route107_Text_2969E4, Route107_Text_296A17
	msgbox Route107_Text_296A35, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE63C:: @ 81EE63C
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296A77, Route107_Text_296AA7, Route107_Text_296B1E
	msgbox Route107_Text_296ADC, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE657:: @ 81EE657
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296B57, Route107_Text_296BB3, Route107_Text_296C34
	msgbox Route107_Text_296BE1, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE672:: @ 81EE672
	trainerbattle_single TRAINER_CAMRON, Route107_Text_296C6F, Route107_Text_296CAD
	msgbox Route107_Text_296CC0, MSGBOX_AUTOCLOSE
	end

