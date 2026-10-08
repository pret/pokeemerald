Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} schrijft de geheime code\n"
	.string "op de deur.\p"
	.string "“TRICK MASTER is fantastisch.”\n"
	.string "… … … … … … … …\p"
	.string "Klik! Het slot gaat open!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Ik hak me een weg naar de winst\n"
	.string "met SNIJDEN, net geleerd!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Waarom ben je zo serieus?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Ik word nooit moe van hakken\n"
	.string "en snijden!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Ik liep per ongeluk dit rare\n"
	.string "huis binnen…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "En nu heb ik ook nog verloren…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Ik ben verdwaald, ik heb verloren en\n"
	.string "nu ben ik nog meer de weg kwijt…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Wie is die TRICK MASTER nou?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Ik verloor terwijl ik in\n"
	.string "gedachten was!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Jij bent sterk!\n"
	.string "Wie ben jij eigenlijk?$"

