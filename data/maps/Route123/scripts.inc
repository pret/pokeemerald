Route123_MapScripts:: @ 81F6147
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition: @ 81F614D
	special SetRoute123Weather
	end

Route123_EventScript_1F6151:: @ 81F6151
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM19, Route123_EventScript_1F61A0
	msgbox Route123_Text_1F641E, MSGBOX_DEFAULT
	special IsGrassTypeInParty
	compare VAR_RESULT, 0
	goto_if_eq Route123_EventScript_1F619E
	msgbox Route123_Text_1F645D, MSGBOX_DEFAULT
	giveitem_std ITEM_TM19
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM19
	msgbox Route123_Text_1F64CF, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_1F619E:: @ 81F619E
	release
	end

Route123_EventScript_1F61A0:: @ 81F61A0
	msgbox Route123_Text_1F64CF, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_1F61AA:: @ 81F61AA
	msgbox Route123_Text_1F6511, MSGBOX_SIGN
	end

Route123_EventScript_1F61B3:: @ 81F61B3
	msgbox Route123_Text_1F6529, MSGBOX_SIGN
	end

Route123_EventScript_1F61BC:: @ 81F61BC
	msgbox Route123_Text_1F6557, MSGBOX_SIGN
	end

Route123_EventScript_1F61C5:: @ 81F61C5
	trainerbattle_single TRAINER_WENDY, Route123_Text_29FBEB, Route123_Text_29FC23
	msgbox Route123_Text_29FC42, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F61DC:: @ 81F61DC
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_29FC6F, Route123_Text_29FCD6
	msgbox Route123_Text_29FCF4, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F61F3:: @ 81F61F3
	trainerbattle_single TRAINER_VIOLET, Route123_Text_29FD1D, Route123_Text_29FD53
	msgbox Route123_Text_29FD7B, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F620A:: @ 81F620A
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_29FDBA, Route123_Text_29FE1E, Route123_EventScript_1F6236
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_1F6255
	msgbox Route123_Text_29FE2A, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_1F6236:: @ 81F6236
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_29FE70, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMERON_1
	release
	end

Route123_EventScript_1F6255:: @ 81F6255
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_29FED4, Route123_Text_29FF1B
	msgbox Route123_Text_29FF27, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F626C:: @ 81F626C
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_29FF61, Route123_Text_29FFD8, Route123_EventScript_1F6298
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_1F62B7
	msgbox Route123_Text_29FFE5, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_1F6298:: @ 81F6298
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_2A0027, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKI_1
	release
	end

Route123_EventScript_1F62B7:: @ 81F62B7
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_2A005E, Route123_Text_2A008D
	msgbox Route123_Text_2A0099, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F62CE:: @ 81F62CE
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_2A00D6, Route123_Text_2A0119, Route123_Text_2A016D
	msgbox Route123_Text_2A012E, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F62E9:: @ 81F62E9
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_2A01A7, Route123_Text_2A01D8, Route123_Text_2A0224
	msgbox Route123_Text_2A01EE, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F6304:: @ 81F6304
	trainerbattle_single TRAINER_KINDRA, Route123_Text_2A025F, Route123_Text_2A02A6
	msgbox Route123_Text_2A02C1, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F631B:: @ 81F631B
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_2A060A, Route123_Text_2A0631
	msgbox Route123_Text_2A0672, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F6332:: @ 81F6332
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_2A06AF, Route123_Text_2A0704
	msgbox Route123_Text_2A072B, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F6349:: @ 81F6349
	trainerbattle_single TRAINER_ED, Route123_Text_2A079B, Route123_Text_2A07F0
	msgbox Route123_Text_2A080D, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F6360:: @ 81F6360
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_2A0902, Route123_Text_2A0943
	msgbox Route123_Text_2A096E, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F6377:: @ 81F6377
	trainerbattle_single TRAINER_JONAS, Route123_Text_2A0854, Route123_Text_2A088A
	msgbox Route123_Text_2A08CA, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F638E:: @ 81F638E
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_2A054E, Route123_Text_2A0592
	msgbox Route123_Text_2A05AC, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F63A5:: @ 81F63A5
	trainerbattle_single TRAINER_DAVIS, Route123_Text_2A04C0, Route123_Text_2A04FE
	msgbox Route123_Text_2A0512, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_1F63BC:: @ 81F63BC
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_2A0323, Route123_Text_2A035C, Route123_EventScript_1F63E8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_1F6407
	msgbox Route123_Text_2A0389, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_1F63E8:: @ 81F63E8
	special sub_80B4808
	waitmovement 0
	msgbox Route123_Text_2A03C1, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_1F6407:: @ 81F6407
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_2A03FB, Route123_Text_2A045A
	msgbox Route123_Text_2A0487, MSGBOX_AUTOCLOSE
	end

Route123_Text_1F641E: @ 81F641E
	.string "I love GRASS-type POKéMON!\p"
	.string "Do you have any GRASS-type POKéMON?$"

Route123_Text_1F645D: @ 81F645D
	.string "Oh?\p"
	.string "You like GRASS-type POKéMON, too,\n"
	.string "don't you?\p"
	.string "I'm so happy, you can have this!\n"
	.string "It's a token of our friendship.$"

Route123_Text_1F64CF: @ 81F64CF
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I'm like a tree doctor.$"

Route123_Text_1F6511: @ 81F6511
	.string "{RIGHT_ARROW} ROUTE 123\n"
	.string "{LEFT_ARROW} ROUTE 118$"

Route123_Text_1F6529: @ 81F6529
	.string "{UP_ARROW} MT. PYRE\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_1F6557: @ 81F6557
	.string "BERRY MASTER'S HOUSE$"

