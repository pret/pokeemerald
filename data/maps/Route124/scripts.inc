Route124_MapScripts:: @ 81F656C
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition: @ 81F6572
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

Route124_EventScript_1F657C:: @ 81F657C
	msgbox Route124_Text_1F6739, MSGBOX_SIGN
	end

Route124_EventScript_1F6585:: @ 81F6585
	trainerbattle_single TRAINER_SPENCER, Route124_Text_2A09B1, Route124_Text_2A0A02
	msgbox Route124_Text_2A0A20, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F659C:: @ 81F659C
	trainerbattle_single TRAINER_ROLAND, Route124_Text_2A0A84, Route124_Text_2A0ACC
	msgbox Route124_Text_2A0AD9, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F65B3:: @ 81F65B3
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_2A0B37, Route124_Text_2A0B7C, Route124_EventScript_1F65DF
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route124_EventScript_1F65FE
	msgbox Route124_Text_2A0B9A, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_1F65DF:: @ 81F65DF
	special sub_80B4808
	waitmovement 0
	msgbox Route124_Text_2A0C14, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_1F65FE:: @ 81F65FE
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_2A0C60, Route124_Text_2A0CA0
	msgbox Route124_Text_2A0CBE, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F6615:: @ 81F6615
	trainerbattle_single TRAINER_GRACE, Route124_Text_2A0D0A, Route124_Text_2A0D3D
	msgbox Route124_Text_2A0D66, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F662C:: @ 81F662C
	trainerbattle_single TRAINER_CHAD, Route124_Text_2A0DA0, Route124_Text_2A0DFF
	msgbox Route124_Text_2A0E1E, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F6643:: @ 81F6643
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_2A0E87, Route124_Text_2A0EFE, Route124_Text_2A0F8C, Route124_EventScript_1F6673
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route124_EventScript_1F668C
	msgbox Route124_Text_2A0F3A, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_1F6673:: @ 81F6673
	msgbox Route124_Text_2A109F, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_1F668C:: @ 81F668C
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_2A111E, Route124_Text_2A11B2, Route124_Text_2A1255
	msgbox Route124_Text_2A1203, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F66A7:: @ 81F66A7
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_2A0FD1, Route124_Text_2A1012, Route124_Text_2A10E5, Route124_EventScript_1F66D7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route124_EventScript_1F66F0
	msgbox Route124_Text_2A103E, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_1F66D7:: @ 81F66D7
	msgbox Route124_Text_2A109F, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_1F66F0:: @ 81F66F0
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_2A129A, Route124_Text_2A12DD, Route124_Text_2A1384
	msgbox Route124_Text_2A130F, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F670B:: @ 81F670B
	trainerbattle_single TRAINER_DECLAN, Route124_Text_2A13BD, Route124_Text_2A142C
	msgbox Route124_Text_2A144F, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_1F6722:: @ 81F6722
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_2A148E, Route124_Text_2A14BC
	msgbox Route124_Text_2A14ED, MSGBOX_AUTOCLOSE
	end

Route124_Text_1F6739: @ 81F6739
	.string "HUNTER'S HOUSE$"

