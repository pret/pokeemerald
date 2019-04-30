Route110_TrickHousePuzzle3_MapScripts:: @ 826BED8
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_MapScript1_26BEE3
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
	.byte 0

Route110_TrickHousePuzzle3_MapScript1_26BEE3: @ 826BEE3
	call Route110_TrickHousePuzzle3_EventScript_26BF1E
	compare VAR_TEMP_9, 0
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF97
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C232
	end

Route110_TrickHousePuzzle3_OnTransition: @ 826BEFF
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	end

Route110_TrickHousePuzzle3_EventScript_26BF1E:: @ 826BF1E
	setmetatile 4, 14, 600, 0
	setmetatile 3, 11, 600, 0
	setmetatile 12, 5, 600, 0
	setmetatile 8, 2, 600, 0
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF6F
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF79
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF83
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF8D
	return

Route110_TrickHousePuzzle3_EventScript_26BF6F:: @ 826BF6F
	setmetatile 4, 14, 601, 0
	return

Route110_TrickHousePuzzle3_EventScript_26BF79:: @ 826BF79
	setmetatile 3, 11, 601, 0
	return

Route110_TrickHousePuzzle3_EventScript_26BF83:: @ 826BF83
	setmetatile 12, 5, 601, 0
	return

Route110_TrickHousePuzzle3_EventScript_26BF8D:: @ 826BF8D
	setmetatile 8, 2, 601, 0
	return

Route110_TrickHousePuzzle3_EventScript_26BF97:: @ 826BF97
	setmetatile 1, 6, 587, 0
	setmetatile 2, 6, 588, 0
	setmetatile 1, 7, 595, 0
	setmetatile 2, 7, 596, 0
	setmetatile 1, 9, 587, 0
	setmetatile 2, 9, 588, 0
	setmetatile 1, 10, 595, 0
	setmetatile 2, 10, 596, 0
	setmetatile 4, 15, 587, 0
	setmetatile 5, 15, 588, 0
	setmetatile 4, 16, 595, 0
	setmetatile 5, 16, 596, 0
	setmetatile 13, 9, 587, 0
	setmetatile 14, 9, 588, 0
	setmetatile 13, 10, 595, 0
	setmetatile 14, 10, 596, 0
	setmetatile 13, 15, 587, 0
	setmetatile 14, 15, 588, 0
	setmetatile 13, 16, 595, 0
	setmetatile 14, 16, 596, 0
	setmetatile 3, 7, 589, 1
	setmetatile 3, 8, 597, 0
	setmetatile 3, 13, 589, 1
	setmetatile 3, 14, 597, 0
	setmetatile 6, 4, 589, 1
	setmetatile 6, 5, 597, 0
	setmetatile 9, 16, 589, 1
	setmetatile 9, 17, 597, 0
	setmetatile 12, 7, 589, 1
	setmetatile 12, 8, 597, 0
	setmetatile 1, 3, 568, 0
	setmetatile 2, 3, 569, 0
	setmetatile 1, 4, 576, 1
	setmetatile 2, 4, 577, 1
	setmetatile 1, 12, 568, 0
	setmetatile 2, 12, 569, 0
	setmetatile 1, 13, 576, 1
	setmetatile 2, 13, 577, 1
	setmetatile 4, 6, 568, 0
	setmetatile 5, 6, 569, 0
	setmetatile 4, 7, 576, 1
	setmetatile 5, 7, 577, 1
	setmetatile 4, 12, 568, 0
	setmetatile 5, 12, 569, 0
	setmetatile 4, 13, 576, 1
	setmetatile 5, 13, 577, 1
	setmetatile 4, 18, 568, 0
	setmetatile 5, 18, 569, 0
	setmetatile 4, 19, 576, 1
	setmetatile 5, 19, 577, 1
	setmetatile 7, 9, 568, 0
	setmetatile 8, 9, 569, 0
	setmetatile 7, 10, 576, 1
	setmetatile 8, 10, 577, 1
	setmetatile 10, 6, 568, 0
	setmetatile 11, 6, 569, 0
	setmetatile 10, 7, 576, 1
	setmetatile 11, 7, 577, 1
	setmetatile 10, 12, 568, 0
	setmetatile 11, 12, 569, 0
	setmetatile 10, 13, 576, 1
	setmetatile 11, 13, 577, 1
	setmetatile 10, 18, 568, 0
	setmetatile 11, 18, 569, 0
	setmetatile 10, 19, 576, 1
	setmetatile 11, 19, 577, 1
	setmetatile 13, 3, 568, 0
	setmetatile 14, 3, 569, 0
	setmetatile 13, 4, 576, 1
	setmetatile 14, 4, 577, 1
	setmetatile 3, 16, 570, 1
	setmetatile 3, 17, 578, 1
	setmetatile 9, 4, 570, 1
	setmetatile 9, 5, 578, 1
	return

Route110_TrickHousePuzzle3_EventScript_26C232:: @ 826C232
	setmetatile 1, 6, 571, 0
	setmetatile 2, 6, 572, 0
	setmetatile 1, 7, 579, 1
	setmetatile 2, 7, 580, 1
	setmetatile 1, 9, 571, 0
	setmetatile 2, 9, 572, 0
	setmetatile 1, 10, 579, 1
	setmetatile 2, 10, 580, 1
	setmetatile 4, 15, 571, 0
	setmetatile 5, 15, 572, 0
	setmetatile 4, 16, 579, 1
	setmetatile 5, 16, 580, 1
	setmetatile 13, 9, 571, 0
	setmetatile 14, 9, 572, 0
	setmetatile 13, 10, 579, 1
	setmetatile 14, 10, 580, 1
	setmetatile 13, 15, 571, 0
	setmetatile 14, 15, 572, 0
	setmetatile 13, 16, 579, 1
	setmetatile 14, 16, 580, 1
	setmetatile 3, 7, 573, 1
	setmetatile 3, 8, 581, 1
	setmetatile 3, 13, 573, 1
	setmetatile 3, 14, 581, 1
	setmetatile 6, 4, 573, 1
	setmetatile 6, 5, 581, 1
	setmetatile 9, 16, 573, 1
	setmetatile 9, 17, 581, 1
	setmetatile 12, 7, 573, 1
	setmetatile 12, 8, 581, 1
	setmetatile 1, 3, 584, 0
	setmetatile 2, 3, 585, 0
	setmetatile 1, 4, 592, 0
	setmetatile 2, 4, 593, 0
	setmetatile 1, 12, 584, 0
	setmetatile 2, 12, 585, 0
	setmetatile 1, 13, 592, 0
	setmetatile 2, 13, 593, 0
	setmetatile 4, 6, 584, 0
	setmetatile 5, 6, 585, 0
	setmetatile 4, 7, 592, 0
	setmetatile 5, 7, 593, 0
	setmetatile 4, 12, 584, 0
	setmetatile 5, 12, 585, 0
	setmetatile 4, 13, 592, 0
	setmetatile 5, 13, 593, 0
	setmetatile 4, 18, 584, 0
	setmetatile 5, 18, 585, 0
	setmetatile 4, 19, 592, 0
	setmetatile 5, 19, 593, 0
	setmetatile 7, 9, 584, 0
	setmetatile 8, 9, 585, 0
	setmetatile 7, 10, 592, 0
	setmetatile 8, 10, 593, 0
	setmetatile 10, 6, 584, 0
	setmetatile 11, 6, 585, 0
	setmetatile 10, 7, 592, 0
	setmetatile 11, 7, 593, 0
	setmetatile 10, 12, 584, 0
	setmetatile 11, 12, 585, 0
	setmetatile 10, 13, 592, 0
	setmetatile 11, 13, 593, 0
	setmetatile 10, 18, 584, 0
	setmetatile 11, 18, 585, 0
	setmetatile 10, 19, 592, 0
	setmetatile 11, 19, 593, 0
	setmetatile 13, 3, 584, 0
	setmetatile 14, 3, 585, 0
	setmetatile 13, 4, 592, 0
	setmetatile 14, 4, 593, 0
	setmetatile 3, 16, 586, 1
	setmetatile 3, 17, 594, 0
	setmetatile 9, 4, 586, 1
	setmetatile 9, 5, 594, 0
	return

Route110_TrickHousePuzzle3_EventScript_26C4CD:: @ 826C4CD
	lockall
	setvar VAR_TEMP_8, 1
	goto Route110_TrickHousePuzzle3_EventScript_26C4FD
	end

Route110_TrickHousePuzzle3_EventScript_26C4D9:: @ 826C4D9
	lockall
	setvar VAR_TEMP_8, 2
	goto Route110_TrickHousePuzzle3_EventScript_26C4FD
	end

Route110_TrickHousePuzzle3_EventScript_26C4E5:: @ 826C4E5
	lockall
	setvar VAR_TEMP_8, 3
	goto Route110_TrickHousePuzzle3_EventScript_26C4FD
	end

Route110_TrickHousePuzzle3_EventScript_26C4F1:: @ 826C4F1
	lockall
	setvar VAR_TEMP_8, 4
	goto Route110_TrickHousePuzzle3_EventScript_26C4FD
	end

Route110_TrickHousePuzzle3_EventScript_26C4FD:: @ 826C4FD
	call Route110_TrickHousePuzzle3_EventScript_26C510
	playse SE_PIN
	call Route110_TrickHousePuzzle3_EventScript_26BF1E
	goto Route110_TrickHousePuzzle3_EventScript_26C569
	end

Route110_TrickHousePuzzle3_EventScript_26C510:: @ 826C510
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C551
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C557
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C55D
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C563
	return

Route110_TrickHousePuzzle3_EventScript_26C551:: @ 826C551
	setvar VAR_TEMP_1, 1
	return

Route110_TrickHousePuzzle3_EventScript_26C557:: @ 826C557
	setvar VAR_TEMP_2, 1
	return

Route110_TrickHousePuzzle3_EventScript_26C55D:: @ 826C55D
	setvar VAR_TEMP_3, 1
	return

Route110_TrickHousePuzzle3_EventScript_26C563:: @ 826C563
	setvar VAR_TEMP_4, 1
	return

Route110_TrickHousePuzzle3_EventScript_26C569:: @ 826C569
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26BF97
	compare VAR_TEMP_9, 0
	call_if_eq Route110_TrickHousePuzzle3_EventScript_26C232
	special DrawWholeMapView
	compare VAR_TEMP_9, 1
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_26C599
	compare VAR_TEMP_9, 0
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_26C5A0
	end

Route110_TrickHousePuzzle3_EventScript_26C599:: @ 826C599
	setvar VAR_TEMP_9, 0
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_26C5A0:: @ 826C5A0
	setvar VAR_TEMP_9, 1
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_26C5A7:: @ 826C5A7
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_26C5B9
	goto Route110_TrickHousePuzzle3_EventScript_26A3DB
	end

Route110_TrickHousePuzzle3_EventScript_26C5B9:: @ 826C5B9
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
	goto Route110_TrickHousePuzzle3_EventScript_26A3E5
	end

Route110_TrickHousePuzzle3_EventScript_26C5C4:: @ 826C5C4
	trainerbattle_single TRAINER_JUSTIN, Route110_TrickHousePuzzle3_Text_26C676, Route110_TrickHousePuzzle3_Text_26C69D
	msgbox Route110_TrickHousePuzzle3_Text_26C6E6, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_26C5DB:: @ 826C5DB
	trainerbattle_single TRAINER_MARTHA, Route110_TrickHousePuzzle3_Text_26C726, Route110_TrickHousePuzzle3_Text_26C763
	msgbox Route110_TrickHousePuzzle3_Text_26C776, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_26C5F2:: @ 826C5F2
	trainerbattle_single TRAINER_ALAN, Route110_TrickHousePuzzle3_Text_26C7AA, Route110_TrickHousePuzzle3_Text_26C7EC
	msgbox Route110_TrickHousePuzzle3_Text_26C80C, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_Text_26C609: @ 826C609
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is coveted.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle3_Text_26C676: @ 826C676
	.string "I keep coming back to this same place!$"

Route110_TrickHousePuzzle3_Text_26C69D: @ 826C69D
	.string "I'm already having trouble, and then\n"
	.string "you have to beat me? It's not fair!$"

Route110_TrickHousePuzzle3_Text_26C6E6: @ 826C6E6
	.string "It's full of doors here!\n"
	.string "It's too small and dark in here! Help!$"

Route110_TrickHousePuzzle3_Text_26C726: @ 826C726
	.string "I don't know what's going on here.\n"
	.string "I'm starting to feel sad…$"

Route110_TrickHousePuzzle3_Text_26C763: @ 826C763
	.string "You… You're awful!$"

Route110_TrickHousePuzzle3_Text_26C776: @ 826C776
	.string "I know I'm weak!\n"
	.string "And, I have no sense of direction!$"

Route110_TrickHousePuzzle3_Text_26C7AA: @ 826C7AA
	.string "I don't get it. What would anyone want\n"
	.string "with a house this bizarre?$"

Route110_TrickHousePuzzle3_Text_26C7EC: @ 826C7EC
	.string "I don't get it.\n"
	.string "How did I lose?$"

Route110_TrickHousePuzzle3_Text_26C80C: @ 826C80C
	.string "I don't get it.\n"
	.string "How many traps are in this house?\p"
	.string "You may be the one to solve that.$"

