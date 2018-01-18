Route107_MapScripts:: @ 81EE594
	.byte 0

Route107_EventScript_1EE595:: @ 81EE595
	trainerbattle 0, TRAINER_DARRIN, 0, Route107_Text_2966E5, Route107_Text_29672F
	msgbox Route107_Text_29675B, 6
	end

Route107_EventScript_1EE5AC:: @ 81EE5AC
	trainerbattle 2, TRAINER_TONY_1, 0, Route107_Text_2967AD, Route107_Text_2967D8, Route107_EventScript_1EE5D8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route107_EventScript_1EE5F7
	msgbox Route107_Text_2967FF, 4
	release
	end

Route107_EventScript_1EE5D8:: @ 81EE5D8
	special sub_80B4808
	waitmovement 0
	msgbox Route107_Text_29685A, 4
	setvar VAR_0x8004, 155
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 155
	callstd 8
	release
	end

Route107_EventScript_1EE5F7:: @ 81EE5F7
	trainerbattle 5, TRAINER_TONY_1, 0, Route107_Text_296897, Route107_Text_2968D5
	msgbox Route107_Text_296923, 6
	end

Route107_EventScript_1EE60E:: @ 81EE60E
	trainerbattle 0, TRAINER_DENISE, 0, Route107_Text_296974, Route107_Text_29699E
	msgbox Route107_Text_2969AB, 6
	end

Route107_EventScript_1EE625:: @ 81EE625
	trainerbattle 0, TRAINER_BETH, 0, Route107_Text_2969E4, Route107_Text_296A17
	msgbox Route107_Text_296A35, 6
	end

Route107_EventScript_1EE63C:: @ 81EE63C
	trainerbattle 4, TRAINER_LISA_AND_RAY, 0, Route107_Text_296A77, Route107_Text_296AA7, Route107_Text_296B1E
	msgbox Route107_Text_296ADC, 6
	end

Route107_EventScript_1EE657:: @ 81EE657
	trainerbattle 4, TRAINER_LISA_AND_RAY, 0, Route107_Text_296B57, Route107_Text_296BB3, Route107_Text_296C34
	msgbox Route107_Text_296BE1, 6
	end

Route107_EventScript_1EE672:: @ 81EE672
	trainerbattle 0, TRAINER_CAMRON, 0, Route107_Text_296C6F, Route107_Text_296CAD
	msgbox Route107_Text_296CC0, 6
	end

