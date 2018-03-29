Route128_MapScripts:: @ 81F6B38
	map_script 3, Route128_MapScript1_1F6B43
	map_script 2, Route128_MapScript2_1F6B4D
	.byte 0

Route128_MapScript1_1F6B43: @ 81F6B43
	checkflag FLAG_SYS_WEATHER_CTRL
	call_if 1, Route128_EventScript_27207A
	end

Route128_MapScript2_1F6B4D: @ 81F6B4D
	map_script_2 VAR_0x407B, 1, Route128_EventScript_1F6B57
	.2byte 0

Route128_EventScript_1F6B57:: @ 81F6B57
	lockall
	delay 20
	applymovement 4, Route128_Movement_1F6C89
	waitmovement 0
	msgbox Route128_Text_1F6DF5, 4
	closemessage
	applymovement 4, Route128_Movement_1F6C91
	waitmovement 0
	msgbox Route128_Text_1F6E48, 4
	closemessage
	applymovement 5, Route128_Movement_1F6CAD
	waitmovement 0
	applymovement 4, Route128_Movement_2725A6
	waitmovement 0
	msgbox Route128_Text_1F6E5A, 4
	closemessage
	applymovement 5, Route128_Movement_1F6CBB
	waitmovement 0
	applymovement 255, Route128_Movement_2725A6
	waitmovement 0
	msgbox Route128_Text_1F6F1E, 4
	closemessage
	applymovement 4, Route128_Movement_1F6C96
	applymovement 255, Route128_Movement_2725A4
	applymovement 5, Route128_Movement_1F6CA8
	waitmovement 0
	msgbox Route128_Text_1F704F, 4
	closemessage
	delay 40
	applymovement 5, Route128_Movement_1F6CB0
	applymovement 4, Route128_Movement_1F6C9B
	waitmovement 0
	removeobject 5
	removeobject 4
	delay 100
	setfieldeffectargument 0, 1
	dofieldeffect 30
	waitfieldeffect 30
	addobject 3
	applymovement 3, Route128_Movement_1F6C87
	waitmovement 0
	applymovement 255, Route128_Movement_2725A8
	waitmovement 0
	msgbox Route128_Text_1F70C9, 4
	closemessage
	applymovement 3, Route128_Movement_1F6C85
	applymovement 255, Route128_Movement_2725A6
	waitmovement 0
	msgbox Route128_Text_1F70EA, 4
	applymovement 3, Route128_Movement_2725AA
	waitmovement 0
	msgbox Route128_Text_1F721B, 4
	closemessage
	applymovement 3, Route128_Movement_2725AA
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect 30
	delay 15
	removeobject 3
	waitfieldeffect 30
	clearflag FLAG_SPECIAL_FLAG_0x4000
	setvar VAR_0x407B, 2
	releaseall
	end

Route128_Movement_1F6C76: @ 81F6C76
	step_17
	step_end

Route128_Movement_1F6C78: @ 81F6C78
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

Route128_Movement_1F6C85: @ 81F6C85
	step_up
	step_end

Route128_Movement_1F6C87: @ 81F6C87
	step_17
	step_end

Route128_Movement_1F6C89: @ 81F6C89
	step_15
	step_27
	step_14
	step_28
	step_14
	step_14
	step_25
	step_end

Route128_Movement_1F6C91: @ 81F6C91
	step_40
	slow_step_up
	step_14
	step_41
	step_end

Route128_Movement_1F6C96: @ 81F6C96
	step_17
	step_17
	step_17
	step_28
	step_end

Route128_Movement_1F6C9B: @ 81F6C9B
	step_14
	step_14
	step_16
	step_17
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

Route128_Movement_1F6CA8: @ 81F6CA8
	step_left
	step_left
	step_13
	step_12
	step_end

Route128_Movement_1F6CAD: @ 81F6CAD
	step_left
	step_25
	step_end

Route128_Movement_1F6CB0: @ 81F6CB0
	step_17
	step_17
	step_17
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

Route128_Movement_1F6CBB: @ 81F6CBB
	step_right
	step_25
	step_end

Route128_EventScript_1F6CBE:: @ 81F6CBE
	trainerbattle 2, TRAINER_ISAIAH_1, 0, Route128_Text_2A287F, Route128_Text_2A28AB, Route128_EventScript_1F6CEA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route128_EventScript_1F6D09
	msgbox Route128_Text_2A28D7, 4
	release
	end

Route128_EventScript_1F6CEA:: @ 81F6CEA
	special sub_80B4808
	waitmovement 0
	msgbox Route128_Text_2A2916, 4
	setvar VAR_0x8004, 376
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 376
	callstd 8
	release
	end

Route128_EventScript_1F6D09:: @ 81F6D09
	trainerbattle 5, TRAINER_ISAIAH_1, 0, Route128_Text_2A2975, Route128_Text_2A29B8
	msgbox Route128_Text_2A29DC, 6
	end

Route128_EventScript_1F6D20:: @ 81F6D20
	trainerbattle 2, TRAINER_KATELYN_1, 0, Route128_Text_2A2A1F, Route128_Text_2A2A94, Route128_EventScript_1F6D4C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route128_EventScript_1F6D6B
	msgbox Route128_Text_2A2AB7, 4
	release
	end

Route128_EventScript_1F6D4C:: @ 81F6D4C
	special sub_80B4808
	waitmovement 0
	msgbox Route128_Text_2A2AF9, 4
	setvar VAR_0x8004, 386
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 386
	callstd 8
	release
	end

Route128_EventScript_1F6D6B:: @ 81F6D6B
	trainerbattle 5, TRAINER_KATELYN_1, 0, Route128_Text_2A2B41, Route128_Text_2A2BAB
	msgbox Route128_Text_2A2BDD, 6
	end

Route128_EventScript_1F6D82:: @ 81F6D82
	trainerbattle 0, TRAINER_ALEXA, 0, Route128_Text_2A2C1C, Route128_Text_2A2C79
	msgbox Route128_Text_2A2C95, 6
	end

Route128_EventScript_1F6D99:: @ 81F6D99
	trainerbattle 0, TRAINER_RUBEN, 0, Route128_Text_2A2CD9, Route128_Text_2A2CFE
	msgbox Route128_Text_2A2D0D, 6
	end

Route128_EventScript_1F6DB0:: @ 81F6DB0
	trainerbattle 0, TRAINER_WAYNE, 0, Route128_Text_2A2D3D, Route128_Text_2A2DA9
	msgbox Route128_Text_2A2DBA, 6
	end

Route128_EventScript_1F6DC7:: @ 81F6DC7
	trainerbattle 0, TRAINER_HARRISON, 0, Route128_Text_2A2E0F, Route128_Text_2A2E44
	msgbox Route128_Text_2A2E6C, 6
	end

Route128_EventScript_1F6DDE:: @ 81F6DDE
	trainerbattle 0, TRAINER_CARLEE, 0, Route128_Text_2A2EC8, Route128_Text_2A2EFA
	msgbox Route128_Text_2A2F2F, 6
	end

Route128_Text_1F6DF5: @ 81F6DF5
	.string "ARCHIE: What happened…\n"
	.string "What is this wretched scene…\p"
	.string "Did I…make a horrible mistake?$"

Route128_Text_1F6E48: @ 81F6E48
	.string "I…\n"
	.string "I only wanted…$"

Route128_Text_1F6E5A: @ 81F6E5A
	.string "MAXIE: Do you understand now,\n"
	.string "ARCHIE?\p"
	.string "Do you finally see how disastrous\n"
	.string "your dream turned out to be?\p"
	.string "We have to hurry! We have to do\n"
	.string "something before the situation goes\l"
	.string "completely out of control!$"

Route128_Text_1F6F1E: @ 81F6F1E
	.string "MAXIE: {PLAYER}, don’t say anything.\p"
	.string "I know that I have no right to be\n"
	.string "critical of ARCHIE…\p"
	.string "But the way things are now, I doubt\n"
	.string "that we humans will be capable of\l"
	.string "doing anything about it.\p"
	.string "But neither can we stand by and\n"
	.string "just watch helplessly.\p"
	.string "The responsibility for putting an end\n"
	.string "to this falls to ARCHIE and me…$"

Route128_Text_1F704F: @ 81F704F
	.string "MAXIE: This defies belief…\p"
	.string "Those super-ancient POKéMON…\p"
	.string "Their power is unbelievable.\n"
	.string "They’ve upset the balance of nature…$"

Route128_Text_1F70C9: @ 81F70C9
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "What is happening?$"

Route128_Text_1F70EA: @ 81F70EA
	.string "This is terrible…\p"
	.string "After the scorching heat wave ended,\n"
	.string "this deluge began.\p"
	.string "If this doesn’t stop, all of HOENN…\n"
	.string "No, the whole world will drown.\p"
	.string "This huge rain cloud is spreading\n"
	.string "from above SOOTOPOLIS…\p"
	.string "What in the world is taking place there?\p"
	.string "There’s no point arguing here…\n"
	.string "SOOTOPOLIS might provide answers…$"

Route128_Text_1F721B: @ 81F721B
	.string "{PLAYER}{KUN}…\n"
	.string "I don’t know what you intend to do,\l"
	.string "but don’t do anything reckless.\p"
	.string "Okay.\n"
	.string "I’m going to SOOTOPOLIS.$"

