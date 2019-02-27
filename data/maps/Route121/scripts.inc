Route121_MapScripts:: @ 81F5DFC
	.byte 0

Route121_EventScript_1F5DFD:: @ 81F5DFD
	msgbox Route121_Text_1F607F, MSGBOX_NPC
	end

Route121_EventScript_1F5E06:: @ 81F5E06
	msgbox Route121_Text_1F60D3, MSGBOX_SIGN
	end

Route121_EventScript_1F5E0F:: @ 81F5E0F
	msgbox Route121_Text_1F611E, MSGBOX_SIGN
	end

Route121_EventScript_1F5E18:: @ 81F5E18
	lockall
	playbgm MUS_AQA_0, 0
	applymovement 13, Route121_Movement_2725B8
	waitmovement 0
	msgbox Route121_Text_1F605A, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Route121_Movement_1F5E59
	applymovement 13, Route121_Movement_1F5E62
	applymovement 14, Route121_Movement_1F5E6B
	waitmovement 0
	fadedefaultbgm
	removeobject 12
	removeobject 13
	removeobject 14
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_Movement_1F5E59: @ 81F5E59
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_1F5E62: @ 81F5E62
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_1F5E6B: @ 81F5E6B
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_EventScript_1F5E74:: @ 81F5E74
	trainerbattle_single TRAINER_VANESSA, Route121_Text_29F0EC, Route121_Text_29F11F
	msgbox Route121_Text_29F138, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5E8B:: @ 81F5E8B
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_29F199, Route121_Text_29F20D, Route121_EventScript_1F5EB7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route121_EventScript_1F5ED6
	msgbox Route121_Text_29F21E, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_1F5EB7:: @ 81F5EB7
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F25B, MSGBOX_DEFAULT
	register_matchcall TRAINER_WALTER_1
	release
	end

Route121_EventScript_1F5ED6:: @ 81F5ED6
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_29F2A6, Route121_Text_29F31A
	msgbox Route121_Text_29F32B, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5EED:: @ 81F5EED
	trainerbattle_single TRAINER_TAMMY, Route121_Text_29F381, Route121_Text_29F3B9
	msgbox Route121_Text_29F3C6, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5F04:: @ 81F5F04
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_29F3FB, Route121_Text_29F43F, Route121_Text_29F4C9
	msgbox Route121_Text_29F476, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5F1F:: @ 81F5F1F
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_29F521, Route121_Text_29F564, Route121_Text_29F5CE
	msgbox Route121_Text_29F582, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5F3A:: @ 81F5F3A
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_29F612, Route121_Text_29F641, Route121_EventScript_1F5F66
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route121_EventScript_1F5F85
	msgbox Route121_Text_29F66F, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_1F5F66:: @ 81F5F66
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F69F, MSGBOX_DEFAULT
	register_matchcall TRAINER_JESSICA_1
	release
	end

Route121_EventScript_1F5F85:: @ 81F5F85
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_29F6E4, Route121_Text_29F710
	msgbox Route121_Text_29F740, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5F9C:: @ 81F5F9C
	trainerbattle_single TRAINER_CALE, Route121_Text_29F91A, Route121_Text_29F97B
	msgbox Route121_Text_29F9AE, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5FB3:: @ 81F5FB3
	trainerbattle_single TRAINER_MYLES, Route121_Text_29FA1E, Route121_Text_29FA64
	msgbox Route121_Text_29FA73, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5FCA:: @ 81F5FCA
	trainerbattle_single TRAINER_PAT, Route121_Text_29FAA7, Route121_Text_29FAD8
	msgbox Route121_Text_29FAEA, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5FE1:: @ 81F5FE1
	trainerbattle_single TRAINER_MARCEL, Route121_Text_29FB35, Route121_Text_29FB8C
	msgbox Route121_Text_29FBA8, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_1F5FF8:: @ 81F5FF8
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_29F770, Route121_Text_29F7C1, Route121_EventScript_1F6024
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route121_EventScript_1F6043
	msgbox Route121_Text_29F7D4, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_1F6024:: @ 81F6024
	special sub_80B4808
	waitmovement 0
	msgbox Route121_Text_29F80D, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRISTIN_1
	release
	end

Route121_EventScript_1F6043:: @ 81F6043
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_29F855, Route121_Text_29F8A8
	msgbox Route121_Text_29F8D0, MSGBOX_AUTOCLOSE
	end

Route121_Text_1F605A: @ 81F605A
	.string "Okay!\n"
	.string "We're to move out to MT. PYRE!$"

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

