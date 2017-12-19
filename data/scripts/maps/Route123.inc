Route123_MapScripts:: @ 81F6147
	map_script 3, Route123_MapScript1_1F614D
	.byte 0

Route123_MapScript1_1F614D: @ 81F614D
	special sub_8139668
	end

Route123_EventScript_1F6151:: @ 81F6151
	lock
	faceplayer
	checkflag FLAG_0x0E8
	goto_eq Route123_EventScript_1F61A0
	msgbox Route123_Text_1F641E, 4
	special sub_81390E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_EventScript_1F619E
	msgbox Route123_Text_1F645D, 4
	giveitem_std ITEM_TM19
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_EventScript_272054
	setflag FLAG_0x0E8
	msgbox Route123_Text_1F64CF, 4
	release
	end

Route123_EventScript_1F619E:: @ 81F619E
	release
	end

Route123_EventScript_1F61A0:: @ 81F61A0
	msgbox Route123_Text_1F64CF, 4
	release
	end

Route123_EventScript_1F61AA:: @ 81F61AA
	msgbox Route123_Text_1F6511, 3
	end

Route123_EventScript_1F61B3:: @ 81F61B3
	msgbox Route123_Text_1F6529, 3
	end

Route123_EventScript_1F61BC:: @ 81F61BC
	msgbox Route123_Text_1F6557, 3
	end

Route123_EventScript_1F61C5:: @ 81F61C5
	trainerbattle 0, TRAINER_WENDY, 0, Route123_Text_29FBEB, Route123_Text_29FC23
	msgbox Route123_Text_29FC42, 6
	end

Route123_EventScript_1F61DC:: @ 81F61DC
	trainerbattle 0, TRAINER_BRAXTON, 0, Route123_Text_29FC6F, Route123_Text_29FCD6
	msgbox Route123_Text_29FCF4, 6
	end

Route123_EventScript_1F61F3:: @ 81F61F3
	trainerbattle 0, TRAINER_VIOLET, 0, Route123_Text_29FD1D, Route123_Text_29FD53
	msgbox Route123_Text_29FD7B, 6
	end

Route123_EventScript_1F620A:: @ 81F620A
	trainerbattle 2, TRAINER_CAMERON_1, 0, Route123_Text_29FDBA, Route123_Text_29FE1E, Route123_EventScript_1F6236
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route123_EventScript_1F6255
	msgbox Route123_Text_29FE2A, 4
	release
	end

Route123_EventScript_1F6236:: @ 81F6236
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_29FE70, 4
	setvar VAR_0x8004, 238
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 238
	callstd 8
	release
	end

Route123_EventScript_1F6255:: @ 81F6255
	trainerbattle 5, TRAINER_CAMERON_1, 0, Route123_Text_29FED4, Route123_Text_29FF1B
	msgbox Route123_Text_29FF27, 6
	end

Route123_EventScript_1F626C:: @ 81F626C
	trainerbattle 2, TRAINER_JACKI_1, 0, Route123_Text_29FF61, Route123_Text_29FFD8, Route123_EventScript_1F6298
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route123_EventScript_1F62B7
	msgbox Route123_Text_29FFE5, 4
	release
	end

Route123_EventScript_1F6298:: @ 81F6298
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_2A0027, 4
	setvar VAR_0x8004, 249
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 249
	callstd 8
	release
	end

Route123_EventScript_1F62B7:: @ 81F62B7
	trainerbattle 5, TRAINER_JACKI_1, 0, Route123_Text_2A005E, Route123_Text_2A008D
	msgbox Route123_Text_2A0099, 6
	end

Route123_EventScript_1F62CE:: @ 81F62CE
	trainerbattle 4, TRAINER_MIU_AND_YUKI, 0, Route123_Text_2A00D6, Route123_Text_2A0119, Route123_Text_2A016D
	msgbox Route123_Text_2A012E, 6
	end

Route123_EventScript_1F62E9:: @ 81F62E9
	trainerbattle 4, TRAINER_MIU_AND_YUKI, 0, Route123_Text_2A01A7, Route123_Text_2A01D8, Route123_Text_2A0224
	msgbox Route123_Text_2A01EE, 6
	end

Route123_EventScript_1F6304:: @ 81F6304
	trainerbattle 0, TRAINER_KINDRA, 0, Route123_Text_2A025F, Route123_Text_2A02A6
	msgbox Route123_Text_2A02C1, 6
	end

Route123_EventScript_1F631B:: @ 81F631B
	trainerbattle 0, TRAINER_FREDRICK, 0, Route123_Text_2A060A, Route123_Text_2A0631
	msgbox Route123_Text_2A0672, 6
	end

Route123_EventScript_1F6332:: @ 81F6332
	trainerbattle 0, TRAINER_ALBERTO, 0, Route123_Text_2A06AF, Route123_Text_2A0704
	msgbox Route123_Text_2A072B, 6
	end

Route123_EventScript_1F6349:: @ 81F6349
	trainerbattle 0, TRAINER_ED, 0, Route123_Text_2A079B, Route123_Text_2A07F0
	msgbox Route123_Text_2A080D, 6
	end

Route123_EventScript_1F6360:: @ 81F6360
	trainerbattle 0, TRAINER_KAYLEY, 0, Route123_Text_2A0902, Route123_Text_2A0943
	msgbox Route123_Text_2A096E, 6
	end

Route123_EventScript_1F6377:: @ 81F6377
	trainerbattle 0, TRAINER_JONAS, 0, Route123_Text_2A0854, Route123_Text_2A088A
	msgbox Route123_Text_2A08CA, 6
	end

Route123_EventScript_1F638E:: @ 81F638E
	trainerbattle 0, TRAINER_JAZMYN, 0, Route123_Text_2A054E, Route123_Text_2A0592
	msgbox Route123_Text_2A05AC, 6
	end

Route123_EventScript_1F63A5:: @ 81F63A5
	trainerbattle 0, TRAINER_DAVIS, 0, Route123_Text_2A04C0, Route123_Text_2A04FE
	msgbox Route123_Text_2A0512, 6
	end

Route123_EventScript_1F63BC:: @ 81F63BC
	trainerbattle 2, TRAINER_FERNANDO_1, 0, Route123_Text_2A0323, Route123_Text_2A035C, Route123_EventScript_1F63E8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route123_EventScript_1F6407
	msgbox Route123_Text_2A0389, 4
	release
	end

Route123_EventScript_1F63E8:: @ 81F63E8
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_2A03C1, 4
	setvar VAR_0x8004, 195
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 195
	callstd 8
	release
	end

Route123_EventScript_1F6407:: @ 81F6407
	trainerbattle 5, TRAINER_FERNANDO_1, 0, Route123_Text_2A03FB, Route123_Text_2A045A
	msgbox Route123_Text_2A0487, 6
	end

Route123_Text_1F641E: @ 81F641E
	.string "I love GRASS-type POKéMON!\p"
	.string "Do you have any GRASS-type POKéMON?$"

Route123_Text_1F645D: @ 81F645D
	.string "Oh?\p"
	.string "You like GRASS-type POKéMON, too,\n"
	.string "don’t you?\p"
	.string "I’m so happy, you can have this!\n"
	.string "It’s a token of our friendship.$"

Route123_Text_1F64CF: @ 81F64CF
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I’m like a tree doctor.$"

Route123_Text_1F6511: @ 81F6511
	.string "{0x7C} ROUTE 123\n"
	.string "{0x7B} ROUTE 118$"

Route123_Text_1F6529: @ 81F6529
	.string "{0x79} MT. PYRE\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_1F6557: @ 81F6557
	.string "BERRY MASTER’S HOUSE$"

