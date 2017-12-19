Route121_MapScripts:: @ 81F5DFC
	.byte 0

Route121_EventScript_1F5DFD:: @ 81F5DFD
	msgbox Route121_Text_1F607F, 2
	end

Route121_EventScript_1F5E06:: @ 81F5E06
	msgbox Route121_Text_1F60D3, 3
	end

Route121_EventScript_1F5E0F:: @ 81F5E0F
	msgbox Route121_Text_1F611E, 3
	end

Route121_EventScript_1F5E18:: @ 81F5E18
	lockall
	playbgm BGM_AQA_0, 0
	applymovement 13, Route121_Movement_2725B8
	waitmovement 0
	msgbox Route121_Text_1F605A, 4
	closemessage
	applymovement 12, Route121_Movement_1F5E59
	applymovement 13, Route121_Movement_1F5E62
	applymovement 14, Route121_Movement_1F5E6B
	waitmovement 0
	fadedefaultbgm
	removeobject 12
	removeobject 13
	removeobject 14
	setvar VAR_0x4074, 1
	releaseall
	end

Route121_Movement_1F5E59: @ 81F5E59
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_end

Route121_Movement_1F5E62: @ 81F5E62
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_end

Route121_Movement_1F5E6B: @ 81F5E6B
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_down
	step_end

Route121_EventScript_1F5E74:: @ 81F5E74
	trainerbattle 0, TRAINER_VANESSA, 0, Route121_Text_29F0EC, Route121_Text_29F11F
	msgbox Route121_Text_29F138, 6
	end

Route121_EventScript_1F5E8B:: @ 81F5E8B
	trainerbattle 2, TRAINER_WALTER_1, 0, Route121_Text_29F199, Route121_Text_29F20D, Route121_EventScript_1F5EB7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route121_EventScript_1F5ED6
	msgbox Route121_Text_29F21E, 4
	release
	end

Route121_EventScript_1F5EB7:: @ 81F5EB7
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F25B, 4
	setvar VAR_0x8004, 254
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 254
	callstd 8
	release
	end

Route121_EventScript_1F5ED6:: @ 81F5ED6
	trainerbattle 5, TRAINER_WALTER_1, 0, Route121_Text_29F2A6, Route121_Text_29F31A
	msgbox Route121_Text_29F32B, 6
	end

Route121_EventScript_1F5EED:: @ 81F5EED
	trainerbattle 0, TRAINER_TAMMY, 0, Route121_Text_29F381, Route121_Text_29F3B9
	msgbox Route121_Text_29F3C6, 6
	end

Route121_EventScript_1F5F04:: @ 81F5F04
	trainerbattle 4, TRAINER_KATE_AND_JOY, 0, Route121_Text_29F3FB, Route121_Text_29F43F, Route121_Text_29F4C9
	msgbox Route121_Text_29F476, 6
	end

Route121_EventScript_1F5F1F:: @ 81F5F1F
	trainerbattle 4, TRAINER_KATE_AND_JOY, 0, Route121_Text_29F521, Route121_Text_29F564, Route121_Text_29F5CE
	msgbox Route121_Text_29F582, 6
	end

Route121_EventScript_1F5F3A:: @ 81F5F3A
	trainerbattle 2, TRAINER_JESSICA_1, 0, Route121_Text_29F612, Route121_Text_29F641, Route121_EventScript_1F5F66
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route121_EventScript_1F5F85
	msgbox Route121_Text_29F66F, 4
	release
	end

Route121_EventScript_1F5F66:: @ 81F5F66
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F69F, 4
	setvar VAR_0x8004, 127
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 127
	callstd 8
	release
	end

Route121_EventScript_1F5F85:: @ 81F5F85
	trainerbattle 5, TRAINER_JESSICA_1, 0, Route121_Text_29F6E4, Route121_Text_29F710
	msgbox Route121_Text_29F740, 6
	end

Route121_EventScript_1F5F9C:: @ 81F5F9C
	trainerbattle 0, TRAINER_CALE, 0, Route121_Text_29F91A, Route121_Text_29F97B
	msgbox Route121_Text_29F9AE, 6
	end

Route121_EventScript_1F5FB3:: @ 81F5FB3
	trainerbattle 0, TRAINER_MYLES, 0, Route121_Text_29FA1E, Route121_Text_29FA64
	msgbox Route121_Text_29FA73, 6
	end

Route121_EventScript_1F5FCA:: @ 81F5FCA
	trainerbattle 0, TRAINER_PAT, 0, Route121_Text_29FAA7, Route121_Text_29FAD8
	msgbox Route121_Text_29FAEA, 6
	end

Route121_EventScript_1F5FE1:: @ 81F5FE1
	trainerbattle 0, TRAINER_MARCEL, 0, Route121_Text_29FB35, Route121_Text_29FB8C
	msgbox Route121_Text_29FBA8, 6
	end

Route121_EventScript_1F5FF8:: @ 81F5FF8
	trainerbattle 2, TRAINER_CRISTIN_1, 0, Route121_Text_29F770, Route121_Text_29F7C1, Route121_EventScript_1F6024
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route121_EventScript_1F6043
	msgbox Route121_Text_29F7D4, 4
	release
	end

Route121_EventScript_1F6024:: @ 81F6024
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F80D, 4
	setvar VAR_0x8004, 767
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 767
	callstd 8
	release
	end

Route121_EventScript_1F6043:: @ 81F6043
	trainerbattle 5, TRAINER_CRISTIN_1, 0, Route121_Text_29F855, Route121_Text_29F8A8
	msgbox Route121_Text_29F8D0, 6
	end

Route121_Text_1F605A: @ 81F605A
	.string "Okay!\n"
	.string "We’re to move out to MT. PYRE!$"

Route121_Text_1F607F: @ 81F607F
	.string "Ahead looms MT. PYRE…\p"
	.string "It is a natural monument to the spirits \n"
	.string "of departed POKéMON…$"

Route121_Text_1F60D3: @ 81F60D3
	.string "MT. PYRE PIER\p"
	.string "…The sign is old and worn out.\n"
	.string "The words are barely legible…$"

Route121_Text_1F611E: @ 81F611E
	.string "“Filled with rare POKéMON!”\n"
	.string "SAFARI ZONE$"

