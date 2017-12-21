Route114_MapScripts:: @ 81F252F
	map_script 3, Route114_MapScript1_1F253F
	map_script 1, Route114_MapScript1_1F2561
	map_script 2, Route114_MapScript2_1F2578
	.byte 0

Route114_MapScript1_1F253F: @ 81F253F
	compare VAR_0x4039, 1
	call_if 1, Route114_EventScript_273D13
	compare VAR_0x4037, 1
	call_if 1, Route114_EventScript_273D1B
	compare VAR_0x4037, 2
	call_if 1, Route114_EventScript_273D1B
	end

Route114_MapScript1_1F2561: @ 81F2561
	compare VAR_0x4037, 1
	call_if 1, Route114_EventScript_273913
	compare VAR_0x4037, 2
	call_if 1, Route114_EventScript_273926
	end

Route114_MapScript2_1F2578: @ 81F2578
	map_script_2 VAR_0x4039, 1, gUnknown_08273D1F
	.2byte 0

Route114_EventScript_1F2582:: @ 81F2582
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_0x92B
	goto_eq Route114_EventScript_1F25C7
	msgbox Route114_Text_2A6FCB, 4
	random 5
	addvar VAR_RESULT, 15
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_eq Route114_EventScript_272054
	setflag FLAG_0x92B
	msgbox Route114_Text_2A7034, 4
	release
	end

Route114_EventScript_1F25C7:: @ 81F25C7
	msgbox Route114_Text_2A706E, 4
	release
	end

Route114_EventScript_1F25D1:: @ 81F25D1
	lock
	faceplayer
	checkflag FLAG_0x0E7
	goto_eq Route114_EventScript_1F2608
	msgbox Route114_Text_1F2809, 4
	giveitem_std ITEM_TM05
	compare VAR_RESULT, 0
	goto_eq Route114_EventScript_272054
	setflag FLAG_0x0E7
	msgbox Route114_Text_1F2872, 4
	release
	end

Route114_EventScript_1F2608:: @ 81F2608
	msgbox Route114_Text_1F2872, 4
	release
	end

Route114_EventScript_1F2612:: @ 81F2612
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, 2
	msgbox Route114_Text_1F28A6, 4
	waitmoncry
	release
	end

Route114_EventScript_1F2625:: @ 81F2625
	msgbox Route114_Text_1F28B3, 3
	end

Route114_EventScript_1F262E:: @ 81F262E
	msgbox Route114_Text_1F28DB, 3
	end

Route114_EventScript_1F2637:: @ 81F2637
	msgbox Route114_Text_1F2910, 3
	end

Route114_EventScript_1F2640:: @ 81F2640
	trainerbattle 0, TRAINER_LENNY, 0, Route114_Text_29A6B1, Route114_Text_29A707
	msgbox Route114_Text_29A715, 6
	end

Route114_EventScript_1F2657:: @ 81F2657
	trainerbattle 0, TRAINER_LUCAS_1, 0, Route114_Text_29A777, Route114_Text_29A7B5
	msgbox Route114_Text_29A7D4, 6
	end

Route114_EventScript_1F266E:: @ 81F266E
	trainerbattle 0, TRAINER_SHANE, 0, Route114_Text_29A818, Route114_Text_29A88F
	msgbox Route114_Text_29A89F, 6
	end

Route114_EventScript_1F2685:: @ 81F2685
	trainerbattle 0, TRAINER_NANCY, 0, Route114_Text_29A8D9, Route114_Text_29A90E
	msgbox Route114_Text_29A916, 6
	end

Route114_EventScript_1F269C:: @ 81F269C
	trainerbattle 2, TRAINER_STEVE_1, 0, Route114_Text_29A943, Route114_Text_29A973, Route114_EventScript_1F26C8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route114_EventScript_1F26E7
	msgbox Route114_Text_29A981, 4
	release
	end

Route114_EventScript_1F26C8:: @ 81F26C8
	special sub_80B4808
	waitmovement 0
	msgbox Route114_Text_29A9F7, 4
	setvar VAR_0x8004, 143
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 143
	callstd 8
	release
	end

Route114_EventScript_1F26E7:: @ 81F26E7
	trainerbattle 5, TRAINER_STEVE_1, 0, Route114_Text_29AA3E, Route114_Text_29AA67
	msgbox Route114_Text_29AA94, 6
	end

Route114_EventScript_1F26FE:: @ 81F26FE
	trainerbattle 2, TRAINER_BERNIE_1, 0, Route114_Text_29AADB, Route114_Text_29AB1A, Route114_EventScript_1F272A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route114_EventScript_1F2749
	msgbox Route114_Text_29AB36, 4
	release
	end

Route114_EventScript_1F272A:: @ 81F272A
	special sub_80B4808
	waitmovement 0
	msgbox Route114_Text_29ABA6, 4
	setvar VAR_0x8004, 206
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 206
	callstd 8
	release
	end

Route114_EventScript_1F2749:: @ 81F2749
	trainerbattle 5, TRAINER_BERNIE_1, 0, Route114_Text_29ABDC, Route114_Text_29AC10
	msgbox Route114_Text_29AC43, 6
	end

Route114_EventScript_1F2760:: @ 81F2760
	trainerbattle 0, TRAINER_CLAUDE, 0, Route114_Text_29ACB3, Route114_Text_29AD0A
	msgbox Route114_Text_29AD2E, 6
	end

Route114_EventScript_1F2777:: @ 81F2777
	trainerbattle 0, TRAINER_NOLAN, 0, Route114_Text_29ADA1, Route114_Text_29AE05
	msgbox Route114_Text_29AE3D, 6
	end

Route114_EventScript_1F278E:: @ 81F278E
	trainerbattle 4, TRAINER_TYRA_AND_IVY, 0, Route114_Text_29AE96, Route114_Text_29AEE7, Route114_Text_29AF3D
	msgbox Route114_Text_29AF0B, 6
	end

Route114_EventScript_1F27A9:: @ 81F27A9
	trainerbattle 4, TRAINER_TYRA_AND_IVY, 0, Route114_Text_29AF89, Route114_Text_29AFAC, Route114_Text_29B01B
	msgbox Route114_Text_29AFCF, 6
	end

Route114_EventScript_1F27C4:: @ 81F27C4
	trainerbattle 0, TRAINER_ANGELINA, 0, Route114_Text_29B16F, Route114_Text_29B19C
	msgbox Route114_Text_29B1BC, 6
	end

Route114_EventScript_1F27DB:: @ 81F27DB
	trainerbattle 0, TRAINER_CHARLOTTE, 0, Route114_Text_29B0DB, Route114_Text_29B0FB
	msgbox Route114_Text_29B11A, 6
	end

Route114_EventScript_1F27F2:: @ 81F27F2
	trainerbattle 0, TRAINER_KAI, 0, Route114_Text_29B05D, Route114_Text_29B089
	msgbox Route114_Text_29B0B5, 6
	end

Route114_Text_1F2809: @ 81F2809
	.string "All my POKéMON does is ROAR…\n"
	.string "No one dares to come near me…\p"
	.string "Sigh… If you would, please take\n"
	.string "this TM away…$"

Route114_Text_1F2872: @ 81F2872
	.string "TM05 contains ROAR.\n"
	.string "A ROAR sends POKéMON scurrying.$"

Route114_Text_1F28A6: @ 81F28A6
	.string "Bow! Bowwow!$"

Route114_Text_1F28B3: @ 81F28B3
	.string "METEOR FALLS\n"
	.string "RUSTBORO CITY THROUGH HERE$"

Route114_Text_1F28DB: @ 81F28DB
	.string "FOSSIL MANIAC’S HOUSE\n"
	.string "“Fossils gratefully accepted!”$"

Route114_Text_1F2910: @ 81F2910
	.string "LANETTE’S HOUSE$"

