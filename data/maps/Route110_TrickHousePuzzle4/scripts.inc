Route110_TrickHousePuzzle4_MapScripts:: @ 826C860
	.byte 0

Route110_TrickHousePuzzle4_EventScript_26C861:: @ 826C861
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle4_EventScript_26C873
	goto Route110_TrickHousePuzzle4_EventScript_26A3DB
	end

Route110_TrickHousePuzzle4_EventScript_26C873:: @ 826C873
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle4_EventScript_26A3E5
	end

Route110_TrickHousePuzzle4_EventScript_26C87E:: @ 826C87E
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_26C92D, Route110_TrickHousePuzzle4_Text_26C96E
	msgbox Route110_TrickHousePuzzle4_Text_26C9A2, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_26C895:: @ 826C895
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_26C9E4, Route110_TrickHousePuzzle4_Text_26CA20
	msgbox Route110_TrickHousePuzzle4_Text_26CA53, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_26C8AC:: @ 826C8AC
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_26CA9C, Route110_TrickHousePuzzle4_Text_26CACB
	msgbox Route110_TrickHousePuzzle4_Text_26CAD1, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_26C8C3: @ 826C8C3
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is cool.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle4_Text_26C92D: @ 826C92D
	.string "It's too much bother to think this out.\n"
	.string "I only wanted to battle!$"

Route110_TrickHousePuzzle4_Text_26C96E: @ 826C96E
	.string "Even though I lost, I still like battling\n"
	.string "the best!$"

Route110_TrickHousePuzzle4_Text_26C9A2: @ 826C9A2
	.string "Wouldn't you agree? You would go\n"
	.string "anywhere if TRAINERS were there.$"

Route110_TrickHousePuzzle4_Text_26C9E4: @ 826C9E4
	.string "Heh! Boulders like this, I can brush\n"
	.string "aside with one finger!$"

Route110_TrickHousePuzzle4_Text_26CA20: @ 826CA20
	.string "I can push boulders, but I can't solve\n"
	.string "the puzzle…$"

Route110_TrickHousePuzzle4_Text_26CA53: @ 826CA53
	.string "It's not good enough to be brawny…\n"
	.string "You have to use your head. Be brainy!$"

Route110_TrickHousePuzzle4_Text_26CA9C: @ 826CA9C
	.string "The TRICK HOUSE is getting trickier,\n"
	.string "isn't it?$"

Route110_TrickHousePuzzle4_Text_26CACB: @ 826CACB
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_26CAD1: @ 826CAD1
	.string "Has anyone made it to the end?$"

