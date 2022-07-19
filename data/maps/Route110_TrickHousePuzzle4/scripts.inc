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
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est cool.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s’ouvre!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Tous ces trucs à résoudre, c’est trop\n"
	.string "compliqué. Je voulais juste me battre!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Même si j’ai perdu, je préfère me battre!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Tu n’es pas d’accord? Ce que tu\n"
	.string "cherches, c’est surtout des DRESSEURS.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Hé, hé! Des rochers comme ça, je peux\n"
	.string "les pousser avec un seul doigt!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Je peux pousser des rochers, mais je\n"
	.string "n’arrive pas à résoudre les énigmes…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Il ne suffit pas d’être musclé…\n"
	.string "Il faut utiliser sa tête et être malin!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La MAISON DES PIEGES est de plus en\n"
	.string "plus compliquée, n’est-ce pas?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaargh!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Quelqu’un est-il déjà arrivé à la fin?$"

