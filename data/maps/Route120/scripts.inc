Route120_MapScripts:: @ 81F53EC
	map_script 5, Route120_MapScript1_1F53FC
	map_script 3, Route120_MapScript1_1F54CD
	map_script 1, Route120_MapScript1_1F5474
	.byte 0

Route120_MapScript1_1F53FC: @ 81F53FC
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, Route120_EventScript_1F5406
	end

Route120_EventScript_1F5406:: @ 81F5406
	compare VAR_0x8009, 0
	call_if 1, Route120_EventScript_1F5449
	compare VAR_0x8009, 1
	call_if 1, Route120_EventScript_1F5460
	compare VAR_0x8009, 2
	call_if 1, Route120_EventScript_1F5460
	compare VAR_0x8009, 3
	call_if 1, Route120_EventScript_1F5460
	compare VAR_0x8009, 4
	call_if 1, Route120_EventScript_1F5460
	compare VAR_0x8009, 5
	call_if 1, Route120_EventScript_1F5460
	return

Route120_EventScript_1F5449:: @ 81F5449
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 7
	goto_if 5, Route120_EventScript_27374E
	removeobject 30
	removeobject 36
	return

Route120_EventScript_1F5460:: @ 81F5460
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 7
	goto_if 5, Route120_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

Route120_MapScript1_1F5474: @ 81F5474
	checkflag FLAG_0x0E4
	call_if 0, Route120_EventScript_1F5490
	checkflag FLAG_0x11D
	call_if 1, Route120_EventScript_1F54A3
	checkflag FLAG_0x11D
	call_if 0, Route120_EventScript_1F54C8
	end

Route120_EventScript_1F5490:: @ 81F5490
	setmetatile 7, 54, 124, 1
	setmetatile 7, 55, 145, 1
	return

Route120_EventScript_1F54A3:: @ 81F54A3
	setmetatile 13, 15, 663, 0
	setmetatile 12, 16, 671, 0
	setmetatile 12, 17, 161, 0
	setmetatile 13, 17, 161, 0
	return

Route120_EventScript_1F54C8:: @ 81F54C8
	setobjectmovementtype 36, 10
	return

Route120_MapScript1_1F54CD: @ 81F54CD
	call Route120_EventScript_28CCC7
	call Route120_EventScript_1F54D8
	end

Route120_EventScript_1F54D8:: @ 81F54D8
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 14
	goto_if 3, Route120_EventScript_1F5503
	compare VAR_TEMP_1, 60
	goto_if 3, Route120_EventScript_1F5507
	compare VAR_TEMP_1, 61
	goto_if 4, Route120_EventScript_1F54FF
	return

Route120_EventScript_1F54FF:: @ 81F54FF
	setweather 1
	return

Route120_EventScript_1F5503:: @ 81F5503
	setweather 2
	return

Route120_EventScript_1F5507:: @ 81F5507
	compare VAR_TEMP_0, 7
	goto_if 3, Route120_EventScript_1F5523
	compare VAR_TEMP_0, 19
	goto_if 3, Route120_EventScript_1F5503
	goto Route120_EventScript_1F5523
	end

Route120_EventScript_1F5523:: @ 81F5523
	setweather 3
	return

Route120_EventScript_1F5527:: @ 81F5527
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_0x92E
	goto_eq Route120_EventScript_1F5625
	msgbox Route120_Text_2A70C7, 5
	compare VAR_RESULT, 1
	call_if 1, Route120_EventScript_1F562F
	compare VAR_RESULT, 0
	call_if 1, Route120_EventScript_1F5638
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, Route120_EventScript_1F55CA
	case 5, Route120_EventScript_1F55CA
	case 1, Route120_EventScript_1F55D5
	case 6, Route120_EventScript_1F55D5
	case 2, Route120_EventScript_1F55E0
	case 7, Route120_EventScript_1F55E0
	case 3, Route120_EventScript_1F55EB
	case 8, Route120_EventScript_1F55EB
	case 4, Route120_EventScript_1F55F6
	case 9, Route120_EventScript_1F55F6
	end

Route120_EventScript_1F55CA:: @ 81F55CA
	setvar VAR_0x8004, 143
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55D5:: @ 81F55D5
	setvar VAR_0x8004, 144
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55E0:: @ 81F55E0
	setvar VAR_0x8004, 145
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55EB:: @ 81F55EB
	setvar VAR_0x8004, 146
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55F6:: @ 81F55F6
	setvar VAR_0x8004, 147
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F5601:: @ 81F5601
	giveitem_std VAR_0x8004
	compare VAR_RESULT, 0
	goto_eq Route120_EventScript_272054
	setflag FLAG_0x92E
	msgbox Route120_Text_2A71D5, 4
	release
	end

Route120_EventScript_1F5625:: @ 81F5625
	msgbox Route120_Text_2A7217, 4
	release
	end

Route120_EventScript_1F562F:: @ 81F562F
	msgbox Route120_Text_2A7147, 4
	return

Route120_EventScript_1F5638:: @ 81F5638
	msgbox Route120_Text_2A7183, 4
	return

Route120_EventScript_1F5641:: @ 81F5641
	lock
	faceplayer
	checkflag FLAG_0x122
	goto_eq Route120_EventScript_1F5672
	msgbox Route120_Text_1F5998, 5
	compare VAR_RESULT, 0
	goto_eq Route120_EventScript_1F5665
	goto Route120_EventScript_1F568B
	end

Route120_EventScript_1F5665:: @ 81F5665
	msgbox Route120_Text_1F5AAC, 4
	setflag FLAG_0x122
	release
	end

Route120_EventScript_1F5672:: @ 81F5672
	msgbox Route120_Text_1F5ADE, 5
	compare VAR_RESULT, 0
	goto_eq Route120_EventScript_1F5665
	goto Route120_EventScript_1F568B
	end

Route120_EventScript_1F568B:: @ 81F568B
	msgbox Route120_Text_1F5B0F, 4
	closemessage
	compare VAR_FACING, 2
	call_if 1, Route120_EventScript_1F57A3
	compare VAR_FACING, 3
	call_if 1, Route120_EventScript_1F57AE
	applymovement 31, Route120_Movement_2725A4
	waitmovement 0
	delay 20
	msgbox Route120_Text_1F5B43, 4
	closemessage
	applymovement 30, Route120_Movement_2725A8
	waitmovement 0
	applymovement 30, Route120_Movement_2723C7
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30, ITEM_NONE
	setvar VAR_0x8009, 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 1
	goto_eq Route120_EventScript_1F571C
	compare VAR_RESULT, 4
	goto_eq Route120_EventScript_1F571C
	compare VAR_RESULT, 5
	goto_eq Route120_EventScript_1F571C
	goto Route120_EventScript_1F572C
	end

Route120_EventScript_1F571C:: @ 81F571C
	fadescreenswapbuffers 1
	removeobject 30
	removeobject 36
	fadescreenswapbuffers 0
	goto Route120_EventScript_1F572C
	end

Route120_EventScript_1F572C:: @ 81F572C
	applymovement 31, Route120_Movement_2725AA
	applymovement 255, Route120_Movement_2725A6
	waitmovement 0
	msgbox Route120_Text_1F5BAF, 4
	giveitem_std ITEM_DEVON_SCOPE
	setflag FLAG_0x11D
	msgbox Route120_Text_1F5C7B, 4
	closemessage
	applymovement 31, Route120_Movement_2725AA
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect 30
	delay 15
	removeobject 31
	waitfieldeffect 30
	setmetatile 13, 15, 663, 0
	setmetatile 12, 16, 671, 0
	setmetatile 12, 17, 161, 0
	setmetatile 13, 17, 161, 0
	special DrawWholeMapView
	release
	end

Route120_EventScript_1F57A3:: @ 81F57A3
	applymovement 255, Route120_Movement_2725A4
	waitmovement 0
	return

Route120_EventScript_1F57AE:: @ 81F57AE
	applymovement 255, Route120_Movement_1F57B9
	waitmovement 0
	return

Route120_Movement_1F57B9: @ 81F57B9
	walk_down
	walk_left
	step_end

Route120_EventScript_1F57BC:: @ 81F57BC
	msgbox Route120_Text_1F5D00, 2
	end

Route120_EventScript_1F57C5:: @ 81F57C5
	msgbox Route120_Text_1F5DCB, 3
	end

Route120_EventScript_1F57CE:: @ 81F57CE
	msgbox Route120_Text_1F5DE4, 3
	end

Route120_EventScript_1F57D7:: @ 81F57D7
	trainerbattle 0, TRAINER_COLIN, 0, Route120_Text_29E62D, Route120_Text_29E665
	msgbox Route120_Text_29E67A, 6
	end

Route120_EventScript_1F57EE:: @ 81F57EE
	trainerbattle 2, TRAINER_ROBERT_1, 0, Route120_Text_29E6E3, Route120_Text_29E70A, Route120_EventScript_1F581A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route120_EventScript_1F5839
	msgbox Route120_Text_29E726, 4
	release
	end

Route120_EventScript_1F581A:: @ 81F581A
	special sub_80B4808
	waitmovement 0
	msgbox Route120_Text_29E75D, 4
	setvar VAR_0x8004, 406
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 406
	callstd 8
	release
	end

Route120_EventScript_1F5839:: @ 81F5839
	trainerbattle 5, TRAINER_ROBERT_1, 0, Route120_Text_29E7AA, Route120_Text_29E7E1
	msgbox Route120_Text_29E804, 6
	end

Route120_EventScript_1F5850:: @ 81F5850
	trainerbattle 0, TRAINER_LORENZO, 0, Route120_Text_29E843, Route120_Text_29E884
	msgbox Route120_Text_29E8C5, 6
	end

Route120_EventScript_1F5867:: @ 81F5867
	trainerbattle 0, TRAINER_JENNA, 0, Route120_Text_29E91C, Route120_Text_29E980
	msgbox Route120_Text_29E996, 6
	end

Route120_EventScript_1F587E:: @ 81F587E
	trainerbattle 2, TRAINER_JEFFREY_1, 0, Route120_Text_29E9D7, Route120_Text_29E9FF, Route120_EventScript_1F58AA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route120_EventScript_1F58C9
	msgbox Route120_Text_29EA08, 4
	release
	end

Route120_EventScript_1F58AA:: @ 81F58AA
	special sub_80B4808
	waitmovement 0
	msgbox Route120_Text_29EA31, 4
	setvar VAR_0x8004, 226
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 226
	callstd 8
	release
	end

Route120_EventScript_1F58C9:: @ 81F58C9
	trainerbattle 5, TRAINER_JEFFREY_1, 0, Route120_Text_29EA61, Route120_Text_29EA8F
	msgbox Route120_Text_29EAA9, 6
	end

Route120_EventScript_1F58E0:: @ 81F58E0
	trainerbattle 0, TRAINER_JENNIFER, 0, Route120_Text_29EAEF, Route120_Text_29EB53
	msgbox Route120_Text_29EB6E, 6
	end

Route120_EventScript_1F58F7:: @ 81F58F7
	trainerbattle 0, TRAINER_CHIP, 0, Route120_Text_29EBAF, Route120_Text_29EC25
	msgbox Route120_Text_29EC41, 6
	end

Route120_EventScript_1F590E:: @ 81F590E
	trainerbattle 0, TRAINER_CLARISSA, 0, Route120_Text_29ECA6, Route120_Text_29ECEF
	msgbox Route120_Text_29ED19, 6
	end

Route120_EventScript_1F5925:: @ 81F5925
	trainerbattle 0, TRAINER_ANGELICA, 0, Route120_Text_29ED71, Route120_Text_29EDD3
	msgbox Route120_Text_29EDF7, 6
	end

Route120_EventScript_1F593C:: @ 81F593C
	trainerbattle 0, TRAINER_KEIGO, 0, Route120_Text_29EE50, Route120_Text_29EE97
	msgbox Route120_Text_29EED4, 6
	end

Route120_EventScript_1F5953:: @ 81F5953
	trainerbattle 0, TRAINER_RILEY, 0, Route120_Text_29EF08, Route120_Text_29EF63
	msgbox Route120_Text_29EF89, 6
	end

Route120_EventScript_1F596A:: @ 81F596A
	trainerbattle 0, TRAINER_LEONEL, 0, Route120_Text_29F04F, Route120_Text_29F080
	msgbox Route120_Text_29F0A1, 6
	end

Route120_EventScript_1F5981:: @ 81F5981
	trainerbattle 0, TRAINER_CALLIE, 0, Route120_Text_29EFB1, Route120_Text_29EFE1
	msgbox Route120_Text_29F002, 6
	end

Route120_Text_1F5998: @ 81F5998
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
	.string "It’s been a while.\p"
	.string "There’s something here that you can’t\n"
	.string "see, right?\p"
	.string "Now, if I were to use this device on\n"
	.string "the invisible obstacle…\p"
	.string "No, no. Rather than describing it,\n"
	.string "I should just show you.\l"
	.string "That would be more fun.\p"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
	.string "battle?$"

Route120_Text_1F5AAC: @ 81F5AAC
	.string "STEVEN: No?\p"
	.string "I’ll wait here, so you can get ready.$"

Route120_Text_1F5ADE: @ 81F5ADE
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
	.string "ready for battle?$"

Route120_Text_1F5B0F: @ 81F5B0F
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
	.string "power as a TRAINER!$"

Route120_Text_1F5B43: @ 81F5B43
	.string "STEVEN used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_1F5BAF: @ 81F5BAF
	.string "STEVEN: I see…\n"
	.string "Your battle style is intriguing.\p"
	.string "Your POKéMON have obviously grown\n"
	.string "since I first met you in DEWFORD.\p"
	.string "I’d like you to have this\n"
	.string "DEVON SCOPE.\p"
	.string "Who knows, there may be other\n"
	.string "concealed POKéMON.$"

Route120_Text_1F5C7B: @ 81F5C7B
	.string "STEVEN: {PLAYER}{KUN}.\p"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
	.string "who strive together.\p"
	.string "I think you’re doing great.\p"
	.string "Well, let’s meet again somewhere.$"

Route119_Text_1F5D00: @ 81F5D00
Route120_Text_1F5D00: @ 81F5D00
	.string "Something unseeable is in the way.$"

Route119_Text_1F5D23: @ 81F5D23
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

Route119_Text_1F5D63: @ 81F5D63
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_1F5DCB: @ 81F5DCB
	.string "ROUTE 120\n"
	.string "{LEFT_ARROW} FORTREE CITY$"

Route120_Text_1F5DE4: @ 81F5DE4
	.string "{RIGHT_ARROW} ROUTE 121\n"
	.string "{LEFT_ARROW} ROUTE 120$"
