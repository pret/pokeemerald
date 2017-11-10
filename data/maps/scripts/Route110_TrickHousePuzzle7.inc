Route110_TrickHousePuzzle7_MapScripts:: @ 826E091
	map_script 5, Route110_TrickHousePuzzle7_MapScript1_26E0A6
	map_script 3, Route110_TrickHousePuzzle7_MapScript1_26E198
	map_script 1, Route110_TrickHousePuzzle7_MapScript1_26E1B4
	map_script 2, Route110_TrickHousePuzzle7_MapScript2_26E1C0
	.byte 0

Route110_TrickHousePuzzle7_MapScript1_26E0A6: @ 826E0A6
	call Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_EventScript_26E0AC:: @ 826E0AC
	checkflag FLAG_0x0C2
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E0DA
	checkflag FLAG_0x0C3
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E0ED
	checkflag FLAG_0x0C4
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E100
	checkflag FLAG_0x0C5
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E113
	checkflag FLAG_0x0C6
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E126
	return

Route110_TrickHousePuzzle7_EventScript_26E0DA:: @ 826E0DA
	setmetatile 13, 17, 610, 0
	setmetatile 12, 16, 575, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E0ED:: @ 826E0ED
	setmetatile 12, 13, 610, 0
	setmetatile 12, 11, 575, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E100:: @ 826E100
	setmetatile 7, 12, 610, 0
	setmetatile 5, 10, 575, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E113:: @ 826E113
	setmetatile 6, 6, 636, 0
	setmetatile 4, 4, 575, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E126:: @ 826E126
	setmetatile 8, 4, 609, 0
	setmetatile 7, 5, 575, 1
	return

	.incbin "baserom.gba", 0x26e139, 0x5f

Route110_TrickHousePuzzle7_MapScript1_26E198: @ 826E198
	compare_var_to_value VAR_0x40B6, 1
	goto_eq Route110_TrickHousePuzzle7_EventScript_26E1B3
	clearflag FLAG_0x0C2
	clearflag FLAG_0x0C3
	clearflag FLAG_0x0C4
	clearflag FLAG_0x0C5
	clearflag FLAG_0x0C6
	end

Route110_TrickHousePuzzle7_EventScript_26E1B3:: @ 826E1B3
	end

Route110_TrickHousePuzzle7_MapScript1_26E1B4: @ 826E1B4
	compare_var_to_value VAR_0x40B6, 1
	call_if 1, Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_MapScript2_26E1C0: @ 826E1C0
	map_script_2 VAR_0x40B6, 1, Route110_TrickHousePuzzle7_EventScript_26E1CA
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_26E1CA:: @ 826E1CA
	setvar VAR_0x40B6, 0
	end

Route110_TrickHousePuzzle7_EventScript_26E1D0:: @ 826E1D0
	lockall
	compare_var_to_value VAR_0x40B1, 0
	goto_eq Route110_TrickHousePuzzle7_EventScript_26E1E2
	goto Route110_TrickHousePuzzle7_EventScript_26A3DB
	end

Route110_TrickHousePuzzle7_EventScript_26E1E2:: @ 826E1E2
	setvar VAR_0x40B1, 1
	goto Route110_TrickHousePuzzle7_EventScript_26A3E5
	end

	.incbin "baserom.gba", 0x26e1ed, 0x12e

Route110_TrickHousePuzzle7_EventScript_26E31B:: @ 826E31B
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 1
	mossdeepgym1 0
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

Route110_TrickHousePuzzle7_EventScript_26E331:: @ 826E331
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 1
	mossdeepgym1 1
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

Route110_TrickHousePuzzle7_EventScript_26E347:: @ 826E347
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 1
	mossdeepgym1 2
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

Route110_TrickHousePuzzle7_EventScript_26E35D:: @ 826E35D
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 1
	mossdeepgym1 3
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

	.incbin "baserom.gba", 0x26e373, 0x16

Route110_TrickHousePuzzle7_EventScript_26E389:: @ 826E389
	trainerbattle 0, TRAINER_JOSHUA, 0, Route110_TrickHousePuzzle7_Text_26E481, Route110_TrickHousePuzzle7_Text_26E4C1
	msgbox Route110_TrickHousePuzzle7_Text_26E4F4, 6
	end

Route110_TrickHousePuzzle7_EventScript_26E3A0:: @ 826E3A0
	trainerbattle 0, TRAINER_PATRICIA, 0, Route110_TrickHousePuzzle7_Text_26E531, Route110_TrickHousePuzzle7_Text_26E564
	msgbox Route110_TrickHousePuzzle7_Text_26E57F, 6
	end

Route110_TrickHousePuzzle7_EventScript_26E3B7:: @ 826E3B7
	trainerbattle 0, TRAINER_ALEXIS, 0, Route110_TrickHousePuzzle7_Text_26E5C0, Route110_TrickHousePuzzle7_Text_26E604
	msgbox Route110_TrickHousePuzzle7_Text_26E61E, 6
	end

Route110_TrickHousePuzzle7_EventScript_26E3CE:: @ 826E3CE
	trainerbattle 0, TRAINER_MARIELA, 0, Route110_TrickHousePuzzle7_Text_26E66B, Route110_TrickHousePuzzle7_Text_26E69C
	msgbox Route110_TrickHousePuzzle7_Text_26E6BC, 6
	end

Route110_TrickHousePuzzle7_EventScript_26E3E5:: @ 826E3E5
	trainerbattle 0, TRAINER_ALVARO, 0, Route110_TrickHousePuzzle7_Text_26E6DA, Route110_TrickHousePuzzle7_Text_26E700
	msgbox Route110_TrickHousePuzzle7_Text_26E722, 6
	end

Route110_TrickHousePuzzle7_EventScript_26E3FC:: @ 826E3FC
	trainerbattle 0, TRAINER_EVERETT, 0, Route110_TrickHousePuzzle7_Text_26E78D, Route110_TrickHousePuzzle7_Text_26E7AB
	msgbox Route110_TrickHousePuzzle7_Text_26E7C4, 6
	end

	.incbin "baserom.gba", 0x26e413, 0x6e

Route110_TrickHousePuzzle7_Text_26E481: @ 826E481
	.string "The TRICK MASTER always vanishes\n"
	.string "like smoke. How does he do it?$"

Route110_TrickHousePuzzle7_Text_26E4C1: @ 826E4C1
	.string "Aiyeeeh! You’re much too strong!\n"
	.string "How do you do it?$"

Route110_TrickHousePuzzle7_Text_26E4F4: @ 826E4F4
	.string "I wish I could appear and disappear as\n"
	.string "if I were smoke, too.$"

Route110_TrickHousePuzzle7_Text_26E531: @ 826E531
	.string "Going around the same spot…\n"
	.string "It begets ill fortune…$"

Route110_TrickHousePuzzle7_Text_26E564: @ 826E564
	.string "Defeated!\n"
	.string "It’s a bad sign…$"

Route110_TrickHousePuzzle7_Text_26E57F: @ 826E57F
	.string "I’ve circled the same spot over ten\n"
	.string "times now… It’s ill fortune…$"

Route110_TrickHousePuzzle7_Text_26E5C0: @ 826E5C0
	.string "Whoever wins will get through here\n"
	.string "first. That’s the feeling I get.$"

Route110_TrickHousePuzzle7_Text_26E604: @ 826E604
	.string "Oh!\n"
	.string "Well, go ahead, then!$"

Route110_TrickHousePuzzle7_Text_26E61E: @ 826E61E
	.string "You’re solving all the puzzles in the\n"
	.string "TRICK HOUSE. That’s the feeling I get.$"

Route110_TrickHousePuzzle7_Text_26E66B: @ 826E66B
	.string "Nufufufu, here at last!\n"
	.string "Let’s get right with it!$"

Route110_TrickHousePuzzle7_Text_26E69C: @ 826E69C
	.string "You’re so casual about winning!$"

Route110_TrickHousePuzzle7_Text_26E6BC: @ 826E6BC
	.string "Humph! I’m not upset!\n"
	.string "Not me!$"

Route110_TrickHousePuzzle7_Text_26E6DA: @ 826E6DA
	.string "I ever so closely watched you coming!$"

Route110_TrickHousePuzzle7_Text_26E700: @ 826E700
	.string "This outcome I didn’t see coming…$"

Route110_TrickHousePuzzle7_Text_26E722: @ 826E722
	.string "Well, anyway, we both picked a weird\n"
	.string "place to get acquainted.\p"
	.string "As one weirdo to another,\n"
	.string "let’s do our best!$"

Route110_TrickHousePuzzle7_Text_26E78D: @ 826E78D
	.string "It’s awfully cramped in here…$"

Route110_TrickHousePuzzle7_Text_26E7AB: @ 826E7AB
	.string "Oh, yes, strong you are.$"

Route110_TrickHousePuzzle7_Text_26E7C4: @ 826E7C4
	.string "I was hoping to switch places with you\n"
	.string "when I beat you, but…$"

