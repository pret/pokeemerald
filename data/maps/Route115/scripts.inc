Route115_MapScripts:: @ 81F2920
	map_script 1, Route115_MapScript1_1F2930
	map_script 3, Route115_MapScript1_1F2947
	map_script 2, Route115_MapScript2_1F2969
	.byte 0

Route115_MapScript1_1F2930: @ 81F2930
	compare VAR_0x4037, 3
	call_if 1, Route115_EventScript_273939
	compare VAR_0x4037, 4
	call_if 1, Route115_EventScript_27394C
	end

Route115_MapScript1_1F2947: @ 81F2947
	compare VAR_0x4039, 1
	call_if 1, Route115_EventScript_273D13
	compare VAR_0x4037, 3
	call_if 1, Route115_EventScript_273D1B
	compare VAR_0x4037, 4
	call_if 1, Route115_EventScript_273D1B
	end

Route115_MapScript2_1F2969: @ 81F2969
	map_script_2 VAR_0x4039, 1, gUnknown_08273D1F
	.2byte 0

Route115_EventScript_1F2973:: @ 81F2973
	msgbox Route115_Text_1F2B55, 2
	end

Route115_EventScript_1F297C:: @ 81F297C
	msgbox Route115_Text_1F2BC9, 3
	end

Route115_EventScript_1F2985:: @ 81F2985
	msgbox Route115_Text_1F2BE3, 3
	end

Route115_EventScript_1F298E:: @ 81F298E
	trainerbattle 2, TRAINER_TIMOTHY_1, 0, Route115_Text_29B1FA, Route115_Text_29B230, Route115_EventScript_1F29BA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route115_EventScript_1F29D9
	msgbox Route115_Text_29B258, 4
	release
	end

Route115_EventScript_1F29BA:: @ 81F29BA
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B2B3, 4
	setvar VAR_0x8004, 307
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 307
	callstd 8
	release
	end

Route115_EventScript_1F29D9:: @ 81F29D9
	trainerbattle 5, TRAINER_TIMOTHY_1, 0, Route115_Text_29B32C, Route115_Text_29B372
	msgbox Route115_Text_29B385, 6
	end

Route115_EventScript_1F29F0:: @ 81F29F0
	trainerbattle 0, TRAINER_KOICHI, 0, Route115_Text_29B3CC, Route115_Text_29B3ED
	msgbox Route115_Text_29B3FF, 6
	end

Route115_EventScript_1F2A07:: @ 81F2A07
	trainerbattle 2, TRAINER_NOB_1, 0, Route115_Text_29B449, Route115_Text_29B480, Route115_EventScript_1F2A33
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route115_EventScript_1F2A52
	msgbox Route115_Text_29B49D, 4
	release
	end

Route115_EventScript_1F2A33:: @ 81F2A33
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B50B, 4
	setvar VAR_0x8004, 183
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 183
	callstd 8
	release
	end

Route115_EventScript_1F2A52:: @ 81F2A52
	trainerbattle 5, TRAINER_NOB_1, 0, Route115_Text_29B547, Route115_Text_29B59D
	msgbox Route115_Text_29B5B5, 6
	end

Route115_EventScript_1F2A69:: @ 81F2A69
	trainerbattle 2, TRAINER_CYNDY_1, 0, Route115_Text_29B5EF, Route115_Text_29B62D, Route115_EventScript_1F2A95
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route115_EventScript_1F2AB4
	msgbox Route115_Text_29B647, 4
	release
	end

Route115_EventScript_1F2A95:: @ 81F2A95
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B6AB, 4
	setvar VAR_0x8004, 427
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 427
	callstd 8
	release
	end

Route115_EventScript_1F2AB4:: @ 81F2AB4
	trainerbattle 5, TRAINER_CYNDY_1, 0, Route115_Text_29B6FA, Route115_Text_29B71A
	msgbox Route115_Text_29B737, 6
	end

Route115_EventScript_1F2ACB:: @ 81F2ACB
	trainerbattle 0, TRAINER_HECTOR, 0, Route115_Text_29B78F, Route115_Text_29B7C5
	msgbox Route115_Text_29B7EA, 6
	end

Route115_EventScript_1F2AE2:: @ 81F2AE2
	trainerbattle 0, TRAINER_KYRA, 0, Route115_Text_29B826, Route115_Text_29B85D
	msgbox Route115_Text_29B869, 6
	end

Route115_EventScript_1F2AF9:: @ 81F2AF9
	trainerbattle 0, TRAINER_JAIDEN, 0, Route115_Text_29B8C1, Route115_Text_29B8E8
	msgbox Route115_Text_29B904, 6
	end

Route115_EventScript_1F2B10:: @ 81F2B10
	trainerbattle 0, TRAINER_ALIX, 0, Route115_Text_29B9CB, Route115_Text_29B9F6
	msgbox Route115_Text_29BA04, 6
	end

Route115_EventScript_1F2B27:: @ 81F2B27
	trainerbattle 0, TRAINER_HELENE, 0, Route115_Text_29B92D, Route115_Text_29B958
	msgbox Route115_Text_29B971, 6
	end

Route115_EventScript_1F2B3E:: @ 81F2B3E
	trainerbattle 0, TRAINER_MARLENE, 0, Route115_Text_29BA2C, Route115_Text_29BA67
	msgbox Route115_Text_29BA87, 6
	end

Route115_Text_1F2B55: @ 81F2B55
	.string "Exploring a cave isn’t like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It’s full of suspense.$"

Route115_Text_1F2BC9: @ 81F2BC9
	.string "ROUTE 115\n"
	.string "{0x7A} RUSTBORO CITY$"

Route115_Text_1F2BE3: @ 81F2BE3
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

