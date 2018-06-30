Route126_MapScripts:: @ 81F68C6
	map_script 3, Route126_MapScript1_1F68CC
	.byte 0

Route126_MapScript1_1F68CC: @ 81F68CC
	checkflag FLAG_SYS_WEATHER_CTRL
	call_if 1, Route126_EventScript_27207A
	end

Route126_EventScript_1F68D6:: @ 81F68D6
	trainerbattle 0, TRAINER_BARRY, 0, Route126_Text_2A1C95, Route126_Text_2A1CC8
	msgbox Route126_Text_2A1CDD, 6
	end

Route126_EventScript_1F68ED:: @ 81F68ED
	trainerbattle 0, TRAINER_DEAN, 0, Route126_Text_2A1D2A, Route126_Text_2A1D63
	msgbox Route126_Text_2A1D72, 6
	end

Route126_EventScript_1F6904:: @ 81F6904
	trainerbattle 0, TRAINER_NIKKI, 0, Route126_Text_2A1DAE, Route126_Text_2A1DC8
	msgbox Route126_Text_2A1E03, 6
	end

Route126_EventScript_1F691B:: @ 81F691B
	trainerbattle 0, TRAINER_BRENDA, 0, Route126_Text_2A1E3E, Route126_Text_2A1E63
	msgbox Route126_Text_2A1E70, 6
	end

Route126_EventScript_1F6932:: @ 81F6932
	trainerbattle 0, TRAINER_LEONARDO, 0, Route126_Text_2A2063, Route126_Text_2A20C6
	msgbox Route126_Text_2A20F7, 6
	end

Route126_EventScript_1F6949:: @ 81F6949
	trainerbattle 0, TRAINER_ISOBEL, 0, Route126_Text_2A216A, Route126_Text_2A21A3
	msgbox Route126_Text_2A21B8, 6
	end

Route126_EventScript_1F6960:: @ 81F6960
	trainerbattle 0, TRAINER_SIENNA, 0, Route126_Text_2A21EF, Route126_Text_2A2216
	msgbox Route126_Text_2A222A, 6
	end

Route126_EventScript_1F6977:: @ 81F6977
	trainerbattle 2, TRAINER_PABLO_1, 0, Route126_Text_2A1EA5, Route126_Text_2A1EE3, Route126_EventScript_1F69A3
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route126_EventScript_1F69C2
	msgbox Route126_Text_2A1F10, 4
	release
	end

Route126_EventScript_1F69A3:: @ 81F69A3
	special sub_80B4808
	waitmovement 0
	msgbox Route126_Text_2A1F5A, 4
	setvar VAR_0x8004, 377
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 377
	callstd 8
	release
	end

Route126_EventScript_1F69C2:: @ 81F69C2
	trainerbattle 5, TRAINER_PABLO_1, 0, Route126_Text_2A1F98, Route126_Text_2A1FD8
	msgbox Route126_Text_2A200C, 6
	end

