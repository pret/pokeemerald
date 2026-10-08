Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
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

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} schrijft de geheime code\n"
	.string "op de deur.\p"
	.string "“TRICK MASTER, ik hou van je.”\n"
	.string "… … … … … … … …\p"
	.string "Klik! Het slot gaat open!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Niet veel TRAINERS komen\n"
	.string "zo ver.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Dan ben jij dus ook sterk…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Heb jij de KAMPIOEN van de POKéMON\n"
	.string "LEAGUE verslagen? Niet te geloven!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Je mag blij zijn dat je tegen\n"
	.string "mij mag vechten!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Dit klopt niet!\n"
	.string "Ik kan niet verliezen!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Het is een wonder dat je won.\n"
	.string "Daar mag je over opscheppen.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Jij ploetert ook door de\n"
	.string "TRICK HOUSE-uitdaging.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Ik snap het…\n"
	.string "Jij hebt een heel bijzondere stijl.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Iemand zoals jij maakt de\n"
	.string "TRICK MASTER vast blij.$"

