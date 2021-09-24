Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master I love.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Not many Trainers have made it\n"
	.string "this far.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "That must mean you're tough, too…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "You've beaten the Pokémon League\n"
	.string "Champion? That's too much!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Consider yourself lucky to be\n"
	.string "battling me!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "This isn't right!\n"
	.string "I can't lose!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "It's a miracle that you beat me.\n"
	.string "You can brag about it.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "You've been slugging through the Trick\n"
	.string "House challenge, too.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "I see…\n"
	.string "You possess an extraordinary style.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Seeing someone like you should please\n"
	.string "the Trick Master.$"

