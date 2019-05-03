Route110_TrickHousePuzzle7_MapScripts:: @ 826E091
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_MapScript1_26E0A6
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_MapScript1_26E1B4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_MapScript2_26E1C0
	.byte 0

Route110_TrickHousePuzzle7_MapScript1_26E0A6: @ 826E0A6
	call Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_EventScript_26E0AC:: @ 826E0AC
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E0DA
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E0ED
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E100
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E113
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E126
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

Route110_TrickHousePuzzle7_EventScript_26E139:: @ 826E139
	setmetatile 13, 17, 611, 0
	setmetatile 12, 16, 574, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E14C:: @ 826E14C
	setmetatile 12, 13, 609, 0
	setmetatile 12, 11, 574, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E15F:: @ 826E15F
	setmetatile 7, 12, 611, 0
	setmetatile 5, 10, 574, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E172:: @ 826E172
	setmetatile 6, 6, 635, 0
	setmetatile 4, 4, 574, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E185:: @ 826E185
	setmetatile 8, 4, 608, 0
	setmetatile 7, 5, 574, 1
	return

Route110_TrickHousePuzzle7_OnTransition: @ 826E198
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_26E1B3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	end

Route110_TrickHousePuzzle7_EventScript_26E1B3:: @ 826E1B3
	end

Route110_TrickHousePuzzle7_MapScript1_26E1B4: @ 826E1B4
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	call_if_eq Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_MapScript2_26E1C0: @ 826E1C0
	map_script_2 VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_26E1CA
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_26E1CA:: @ 826E1CA
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 0
	end

Route110_TrickHousePuzzle7_EventScript_26E1D0:: @ 826E1D0
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_26E1E2
	goto Route110_TrickHousePuzzle7_EventScript_26A3DB
	end

Route110_TrickHousePuzzle7_EventScript_26E1E2:: @ 826E1E2
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto Route110_TrickHousePuzzle7_EventScript_26A3E5
	end

Route110_TrickHousePuzzle7_EventScript_26E1ED:: @ 826E1ED
	lockall
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 255, 3, 19
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E1FE:: @ 826E1FE
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E0DA
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E139
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E2E9
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E2EE
	end

Route110_TrickHousePuzzle7_EventScript_26E22D:: @ 826E22D
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E0ED
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E14C
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E2F3
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E2F8
	end

Route110_TrickHousePuzzle7_EventScript_26E25C:: @ 826E25C
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E100
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E15F
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E2FD
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E302
	end

Route110_TrickHousePuzzle7_EventScript_26E28B:: @ 826E28B
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E113
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E172
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E307
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E30C
	end

Route110_TrickHousePuzzle7_EventScript_26E2BA:: @ 826E2BA
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E126
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E185
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E311
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E316
	end

Route110_TrickHousePuzzle7_EventScript_26E2E9:: @ 826E2E9
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2EE:: @ 826E2EE
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2F3:: @ 826E2F3
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2F8:: @ 826E2F8
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2FD:: @ 826E2FD
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E302:: @ 826E302
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E307:: @ 826E307
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E30C:: @ 826E30C
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E311:: @ 826E311
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E316:: @ 826E316
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

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

Route110_TrickHousePuzzle7_EventScript_26E373:: @ 826E373
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 1
	mossdeepgym1 4
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

Route110_TrickHousePuzzle7_EventScript_26E389:: @ 826E389
	trainerbattle_single TRAINER_JOSHUA, Route110_TrickHousePuzzle7_Text_26E481, Route110_TrickHousePuzzle7_Text_26E4C1
	msgbox Route110_TrickHousePuzzle7_Text_26E4F4, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3A0:: @ 826E3A0
	trainerbattle_single TRAINER_PATRICIA, Route110_TrickHousePuzzle7_Text_26E531, Route110_TrickHousePuzzle7_Text_26E564
	msgbox Route110_TrickHousePuzzle7_Text_26E57F, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3B7:: @ 826E3B7
	trainerbattle_single TRAINER_ALEXIS, Route110_TrickHousePuzzle7_Text_26E5C0, Route110_TrickHousePuzzle7_Text_26E604
	msgbox Route110_TrickHousePuzzle7_Text_26E61E, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3CE:: @ 826E3CE
	trainerbattle_single TRAINER_MARIELA, Route110_TrickHousePuzzle7_Text_26E66B, Route110_TrickHousePuzzle7_Text_26E69C
	msgbox Route110_TrickHousePuzzle7_Text_26E6BC, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3E5:: @ 826E3E5
	trainerbattle_single TRAINER_ALVARO, Route110_TrickHousePuzzle7_Text_26E6DA, Route110_TrickHousePuzzle7_Text_26E700
	msgbox Route110_TrickHousePuzzle7_Text_26E722, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3FC:: @ 826E3FC
	trainerbattle_single TRAINER_EVERETT, Route110_TrickHousePuzzle7_Text_26E78D, Route110_TrickHousePuzzle7_Text_26E7AB
	msgbox Route110_TrickHousePuzzle7_Text_26E7C4, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E413:: @ 826E413
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is huggable.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle7_Text_26E481: @ 826E481
	.string "The TRICK MASTER always vanishes\n"
	.string "like smoke. How does he do it?$"

Route110_TrickHousePuzzle7_Text_26E4C1: @ 826E4C1
	.string "Aiyeeeh! You're much too strong!\n"
	.string "How do you do it?$"

Route110_TrickHousePuzzle7_Text_26E4F4: @ 826E4F4
	.string "I wish I could appear and disappear as\n"
	.string "if I were smoke, too.$"

Route110_TrickHousePuzzle7_Text_26E531: @ 826E531
	.string "Going around the same spot…\n"
	.string "It begets ill fortune…$"

Route110_TrickHousePuzzle7_Text_26E564: @ 826E564
	.string "Defeated!\n"
	.string "It's a bad sign…$"

Route110_TrickHousePuzzle7_Text_26E57F: @ 826E57F
	.string "I've circled the same spot over ten\n"
	.string "times now… It's ill fortune…$"

Route110_TrickHousePuzzle7_Text_26E5C0: @ 826E5C0
	.string "Whoever wins will get through here\n"
	.string "first. That's the feeling I get.$"

Route110_TrickHousePuzzle7_Text_26E604: @ 826E604
	.string "Oh!\n"
	.string "Well, go ahead, then!$"

Route110_TrickHousePuzzle7_Text_26E61E: @ 826E61E
	.string "You're solving all the puzzles in the\n"
	.string "TRICK HOUSE. That's the feeling I get.$"

Route110_TrickHousePuzzle7_Text_26E66B: @ 826E66B
	.string "Nufufufu, here at last!\n"
	.string "Let's get right with it!$"

Route110_TrickHousePuzzle7_Text_26E69C: @ 826E69C
	.string "You're so casual about winning!$"

Route110_TrickHousePuzzle7_Text_26E6BC: @ 826E6BC
	.string "Humph! I'm not upset!\n"
	.string "Not me!$"

Route110_TrickHousePuzzle7_Text_26E6DA: @ 826E6DA
	.string "I ever so closely watched you coming!$"

Route110_TrickHousePuzzle7_Text_26E700: @ 826E700
	.string "This outcome I didn't see coming…$"

Route110_TrickHousePuzzle7_Text_26E722: @ 826E722
	.string "Well, anyway, we both picked a weird\n"
	.string "place to get acquainted.\p"
	.string "As one weirdo to another,\n"
	.string "let's do our best!$"

Route110_TrickHousePuzzle7_Text_26E78D: @ 826E78D
	.string "It's awfully cramped in here…$"

Route110_TrickHousePuzzle7_Text_26E7AB: @ 826E7AB
	.string "Oh, yes, strong you are.$"

Route110_TrickHousePuzzle7_Text_26E7C4: @ 826E7C4
	.string "I was hoping to switch places with you\n"
	.string "when I beat you, but…$"

