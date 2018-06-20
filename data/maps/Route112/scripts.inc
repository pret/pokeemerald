Route112_MapScripts:: @ 81F1DA8
	map_script 3, Route112_MapScript1_1F1DAE
	.byte 0

Route112_MapScript1_1F1DAE: @ 81F1DAE
	clearflag FLAG_0x09D
	setvar VAR_0x40BD, 0
	end

Route112_EventScript_1F1DB7:: @ 81F1DB7
	lockall
	delay 40
	applymovement 1, Route112_Movement_2725A8
	waitmovement 0
	delay 20
	msgbox Route112_Text_1F1F3F, 4
	closemessage
	applymovement 1, Route112_Movement_2725A2
	waitmovement 0
	delay 40
	applymovement 6, Route112_Movement_2725A4
	waitmovement 0
	delay 20
	msgbox Route112_Text_1F1F7A, 4
	closemessage
	applymovement 6, Route112_Movement_2725A2
	waitmovement 0
	delay 40
	applymovement 1, Route112_Movement_2725A8
	waitmovement 0
	delay 20
	msgbox Route112_Text_1F1FBA, 4
	closemessage
	applymovement 1, Route112_Movement_2725A2
	waitmovement 0
	delay 40
	applymovement 6, Route112_Movement_2725A4
	waitmovement 0
	delay 20
	msgbox Route112_Text_1F2003, 4
	closemessage
	applymovement 6, Route112_Movement_2725A2
	waitmovement 0
	releaseall
	end

Route112_EventScript_1F1E46:: @ 81F1E46
	msgbox Route112_Text_1F20C1, 3
	end

Route112_EventScript_1F1E4F:: @ 81F1E4F
	msgbox Route112_Text_1F20ED, 3
	end

Route112_EventScript_1F1E58:: @ 81F1E58
	msgbox Route112_Text_1F2138, 3
	end

Route112_EventScript_1F1E61:: @ 81F1E61
	msgbox Route112_Text_1F204E, 2
	end

Route112_EventScript_1F1E6A:: @ 81F1E6A
	trainerbattle 0, TRAINER_BRICE, 0, Route112_Text_29978E, Route112_Text_2997CA
	msgbox Route112_Text_2997DC, 6
	end

Route112_EventScript_1F1E81:: @ 81F1E81
	trainerbattle 2, TRAINER_TRENT_1, 0, Route112_Text_299815, Route112_Text_29987C, Route112_EventScript_1F1EAD
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route112_EventScript_1F1ECC
	msgbox Route112_Text_299896, 4
	release
	end

Route112_EventScript_1F1EAD:: @ 81F1EAD
	special sub_80B4808
	waitmovement 0
	msgbox Route112_Text_29993C, 4
	setvar VAR_0x8004, 627
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 627
	callstd 8
	release
	end

Route112_EventScript_1F1ECC:: @ 81F1ECC
	trainerbattle 5, TRAINER_TRENT_1, 0, Route112_Text_2999BD, Route112_Text_2999F7
	msgbox Route112_Text_299A0F, 6
	end

Route112_EventScript_1F1EE3:: @ 81F1EE3
	trainerbattle 0, TRAINER_LARRY, 0, Route112_Text_299A89, Route112_Text_299AAC
	msgbox Route112_Text_299AB4, 6
	end

Route112_EventScript_1F1EFA:: @ 81F1EFA
	trainerbattle 0, TRAINER_CAROL, 0, Route112_Text_299AE4, Route112_Text_299B36
	msgbox Route112_Text_299B4C, 6
	end

Route112_EventScript_1F1F11:: @ 81F1F11
	trainerbattle 0, TRAINER_BRYANT, 0, Route112_Text_299BAE, Route112_Text_299BDF
	msgbox Route112_Text_299BFB, 6
	end

Route112_EventScript_1F1F28:: @ 81F1F28
	trainerbattle 0, TRAINER_SHAYLA, 0, Route112_Text_299C34, Route112_Text_299C8F
	msgbox Route112_Text_299CC6, 6
	end

Route112_Text_1F1F3F: @ 81F1F3F
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_1F1F7A: @ 81F1F7A
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a METEORITE to do it.$"

Route112_Text_1F1FBA: @ 81F1FBA
	.string "Oh, I get it now. That’s why the rest\n"
	.string "of the crew went out to FALLARBOR.$"

Route112_Text_1F2003: @ 81F2003
	.string "You got it. And until they come back,\n"
	.string "we’re not to let anyone pass, right.$"

Route112_Text_1F204E: @ 81F204E
	.string "Eh, I’d like to get to MAUVILLE, but if\n"
	.string "I went down these ledges, it’d be no\l"
	.string "easy matter to get back to LAVARIDGE.$"

Route112_Text_1F20C1: @ 81F20C1
	.string "MT. CHIMNEY CABLE CAR\n"
	.string "“A short walk {0x79} way!”$"

Route112_Text_1F20ED: @ 81F20ED
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"

Route112_Text_1F2138: @ 81F2138
	.string "ROUTE 112\n"
	.string "{0x7B} LAVARIDGE TOWN$"

