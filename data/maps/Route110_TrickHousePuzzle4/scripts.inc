Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} schrijft de geheime code\n"
	.string "op de deur.\p"
	.string "“TRICK MASTER is stoer.”\n"
	.string "… … … … … … … …\p"
	.string "Klik! Het slot gaat open!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Nadenken is me te veel moeite.\n"
	.string "Ik wilde alleen maar vechten!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Ik heb verloren, maar vechten\n"
	.string "vind ik nog steeds het leukst!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Vind je ook niet? Je gaat overal\n"
	.string "heen als er TRAINERS zijn.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Zulke rotsen duw ik met\n"
	.string "één vinger opzij!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Ik kan rotsen duwen, maar de\n"
	.string "puzzel snap ik niet…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Spierballen alleen zijn niet genoeg…\n"
	.string "Je moet ook je hoofd gebruiken!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "Het TRICK HOUSE wordt steeds\n"
	.string "lastiger, hè?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Is er al iemand tot het einde\n"
	.string "gekomen?$"

