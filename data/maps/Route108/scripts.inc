Route108_MapScripts:: @ 81EE689
	.byte 0

Route108_EventScript_1EE68A:: @ 81EE68A
	trainerbattle 0, TRAINER_JEROME, 0, Route108_Text_296D10, Route108_Text_296D3C
	msgbox Route108_Text_296D6E, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_1EE6A1:: @ 81EE6A1
	trainerbattle 0, TRAINER_MATTHEW, 0, Route108_Text_296DAF, Route108_Text_296DEA
	msgbox Route108_Text_296E03, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_1EE6B8:: @ 81EE6B8
	trainerbattle 0, TRAINER_TARA, 0, Route108_Text_296E33, Route108_Text_296E71
	msgbox Route108_Text_296E7A, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_1EE6CF:: @ 81EE6CF
	trainerbattle 0, TRAINER_MISSY, 0, Route108_Text_296EC7, Route108_Text_296EFC
	msgbox Route108_Text_296F2A, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_1EE6E6:: @ 81EE6E6
	trainerbattle 0, TRAINER_CAROLINA, 0, Route108_Text_297094, Route108_Text_2970D7
	msgbox Route108_Text_2970F0, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_1EE6FD:: @ 81EE6FD
	trainerbattle 2, TRAINER_CORY_1, 0, Route108_Text_296F5D, Route108_Text_296F93, Route108_EventScript_1EE729
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route108_EventScript_1EE748
	msgbox Route108_Text_296FB0, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_1EE729:: @ 81EE729
	special sub_80B4808
	waitmovement 0
	msgbox Route108_Text_296FD8, MSGBOX_DEFAULT
	setvar VAR_0x8004, 740
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 740
	callstd STD_REGISTER_MATCH_CALL
	release
	end

Route108_EventScript_1EE748:: @ 81EE748
	trainerbattle 5, TRAINER_CORY_1, 0, Route108_Text_297011, Route108_Text_297036
	msgbox Route108_Text_297059, MSGBOX_AUTOCLOSE
	end

