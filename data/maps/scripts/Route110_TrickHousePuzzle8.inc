Route110_TrickHousePuzzle8_MapScripts:: @ 826E801
	.byte 0

Route110_TrickHousePuzzle8_EventScript_26E802:: @ 826E802
	lockall
	compare_var_to_value VAR_0x40B2, 0
	goto_eq Route110_TrickHousePuzzle8_EventScript_26E814
	goto Route110_TrickHousePuzzle8_EventScript_26A3DB
	end

Route110_TrickHousePuzzle8_EventScript_26E814:: @ 826E814
	setvar VAR_0x40B2, 1
	goto Route110_TrickHousePuzzle8_EventScript_26A3E5
	end

Route110_TrickHousePuzzle8_EventScript_26E81F:: @ 826E81F
	trainerbattle 0, TRAINER_VINCENT, 0, Route110_TrickHousePuzzle8_Text_26E8CD, Route110_TrickHousePuzzle8_Text_26E8F6
	msgbox Route110_TrickHousePuzzle8_Text_26E918, 6
	end

Route110_TrickHousePuzzle8_EventScript_26E836:: @ 826E836
	trainerbattle 0, TRAINER_KEIRA, 0, Route110_TrickHousePuzzle8_Text_26E954, Route110_TrickHousePuzzle8_Text_26E97F
	msgbox Route110_TrickHousePuzzle8_Text_26E99F, 6
	end

Route110_TrickHousePuzzle8_EventScript_26E84D:: @ 826E84D
	trainerbattle 0, TRAINER_LEROY, 0, Route110_TrickHousePuzzle8_Text_26E9D7, Route110_TrickHousePuzzle8_Text_26EA14
	msgbox Route110_TrickHousePuzzle8_Text_26EA3F, 6
	end

	.incbin "baserom.gba", 0x26e864, 0x69

Route110_TrickHousePuzzle8_Text_26E8CD: @ 826E8CD
	.string "Not many TRAINERS have made it\n"
	.string "this far.$"

Route110_TrickHousePuzzle8_Text_26E8F6: @ 826E8F6
	.string "That must mean you’re tough, too…$"

Route110_TrickHousePuzzle8_Text_26E918: @ 826E918
	.string "You’ve beaten the POKéMON LEAGUE\n"
	.string "CHAMPION? That’s too much!$"

Route110_TrickHousePuzzle8_Text_26E954: @ 826E954
	.string "Consider yourself lucky to be\n"
	.string "battling me!$"

Route110_TrickHousePuzzle8_Text_26E97F: @ 826E97F
	.string "This isn’t right!\n"
	.string "I can’t lose!$"

Route110_TrickHousePuzzle8_Text_26E99F: @ 826E99F
	.string "It’s a miracle that you beat me.\n"
	.string "You can brag about it.$"

Route110_TrickHousePuzzle8_Text_26E9D7: @ 826E9D7
	.string "You’ve been slugging through the TRICK\n"
	.string "HOUSE challenge, too.$"

Route110_TrickHousePuzzle8_Text_26EA14: @ 826EA14
	.string "I see…\n"
	.string "You possess an extraordinary style.$"

Route110_TrickHousePuzzle8_Text_26EA3F: @ 826EA3F
	.string "Seeing someone like you should please\n"
	.string "the TRICK MASTER.$"

