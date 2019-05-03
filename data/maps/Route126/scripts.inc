Route126_MapScripts:: @ 81F68C6
	map_script MAP_SCRIPT_ON_TRANSITION, Route126_OnTransition
	.byte 0

Route126_OnTransition: @ 81F68CC
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

Route126_EventScript_1F68D6:: @ 81F68D6
	trainerbattle_single TRAINER_BARRY, Route126_Text_2A1C95, Route126_Text_2A1CC8
	msgbox Route126_Text_2A1CDD, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F68ED:: @ 81F68ED
	trainerbattle_single TRAINER_DEAN, Route126_Text_2A1D2A, Route126_Text_2A1D63
	msgbox Route126_Text_2A1D72, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F6904:: @ 81F6904
	trainerbattle_single TRAINER_NIKKI, Route126_Text_2A1DAE, Route126_Text_2A1DC8
	msgbox Route126_Text_2A1E03, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F691B:: @ 81F691B
	trainerbattle_single TRAINER_BRENDA, Route126_Text_2A1E3E, Route126_Text_2A1E63
	msgbox Route126_Text_2A1E70, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F6932:: @ 81F6932
	trainerbattle_single TRAINER_LEONARDO, Route126_Text_2A2063, Route126_Text_2A20C6
	msgbox Route126_Text_2A20F7, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F6949:: @ 81F6949
	trainerbattle_single TRAINER_ISOBEL, Route126_Text_2A216A, Route126_Text_2A21A3
	msgbox Route126_Text_2A21B8, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F6960:: @ 81F6960
	trainerbattle_single TRAINER_SIENNA, Route126_Text_2A21EF, Route126_Text_2A2216
	msgbox Route126_Text_2A222A, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_1F6977:: @ 81F6977
	trainerbattle_single TRAINER_PABLO_1, Route126_Text_2A1EA5, Route126_Text_2A1EE3, Route126_EventScript_1F69A3
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route126_EventScript_1F69C2
	msgbox Route126_Text_2A1F10, MSGBOX_DEFAULT
	release
	end

Route126_EventScript_1F69A3:: @ 81F69A3
	special sub_80B4808
	waitmovement 0
	msgbox Route126_Text_2A1F5A, MSGBOX_DEFAULT
	register_matchcall TRAINER_PABLO_1
	release
	end

Route126_EventScript_1F69C2:: @ 81F69C2
	trainerbattle_rematch TRAINER_PABLO_1, Route126_Text_2A1F98, Route126_Text_2A1FD8
	msgbox Route126_Text_2A200C, MSGBOX_AUTOCLOSE
	end

