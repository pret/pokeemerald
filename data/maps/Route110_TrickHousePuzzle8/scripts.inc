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

Route110_TrickHousePuzzle8_EventScript_WroteSecretCodeLockOpened::
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“J’aime le MAITRE DES PIEGES.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s’ouvre!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Peu de DRESSEURS sont arrivés\n"
	.string "aussi loin.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Ça doit vouloir dire que tu es balèze…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Tu as battu le MAITRE de la LIGUE\n"
	.string "POKéMON? Les bras m’en tombent!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "C’est une sacrée chance de se battre\n"
	.string "contre moi!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "C’est impossible!\n"
	.string "Je ne peux pas perdre!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Ta victoire tient du miracle.\n"
	.string "Tu vas pouvoir frimer.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Toi aussi, tu luttes pour relever le défi\n"
	.string "de la MAISON DES PIEGES.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Mmmh. Je vois…\n"
	.string "Ton style est très impressionnant.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Tu devrais plaire au MAITRE DES PIEGES.$"

