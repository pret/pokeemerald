Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est\n"
	.string "tout pour moi.”\l"
	.string "… … … … … … … …\p"
	.string "La porte s’ouvre!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quand on m’a parlé d’une maison bizarre,\n"
	.string "je me suis sentie obligée d’y aller.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "J’ai découvert un DRESSEUR balèze!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Je suis sûre de m’amuser quand\n"
	.string "je viens ici.\p"
	.string "Je ne me lasse pas de ce défi.\n"
	.string "C’est toujours aussi bien!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Je pourrais demander à mes POKéMON\n"
	.string "OISEAU de voler au-dessus du mur…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gniiiii! J’ai tout raté!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Hé, hé, hé… Je suppose que j’ai perdu\n"
	.string "parce que j’ai essayé de tricher.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Toutes ces portes pivotantes me\n"
	.string "donnent le tournis…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Tout tourne autour de moi! Je ne vais\n"
	.string "pas le supporter plus longtemps…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Ça n’a pas l’air de te déranger.\n"
	.string "Ou bien est-ce juste du bluff?$"

