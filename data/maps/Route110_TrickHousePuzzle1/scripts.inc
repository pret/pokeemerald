Route110_TrickHousePuzzle1_MapScripts:: @ 826B90F
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_MapScript1_26B915
	.byte 0

Route110_TrickHousePuzzle1_MapScript1_26B915: @ 826B915
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_26B921
	end

Route110_TrickHousePuzzle1_EventScript_26B921:: @ 826B921
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	end

Route110_TrickHousePuzzle1_EventScript_26B92B:: @ 826B92B
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_26B93D
	goto Route110_TrickHousePuzzle1_EventScript_26A3DB
	end

Route110_TrickHousePuzzle1_EventScript_26B93D:: @ 826B93D
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle1_EventScript_26A3E5
	end

Route110_TrickHousePuzzle1_EventScript_26B948:: @ 826B948
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_26B9FB, Route110_TrickHousePuzzle1_Text_26BA3F
	msgbox Route110_TrickHousePuzzle1_Text_26BA57, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_26B95F:: @ 826B95F
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_26BA82, Route110_TrickHousePuzzle1_Text_26BAB0
	msgbox Route110_TrickHousePuzzle1_Text_26BAC3, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_26B976:: @ 826B976
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_26BB10, Route110_TrickHousePuzzle1_Text_26BB2E
	msgbox Route110_TrickHousePuzzle1_Text_26BB52, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_26B98D:: @ 826B98D
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is fabulous.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle1_Text_26B9FB: @ 826B9FB
	.string "I'll hack and slash my way to victory\n"
	.string "with the CUT we just learned!$"

Route110_TrickHousePuzzle1_Text_26BA3F: @ 826BA3F
	.string "Why are you so serious?$"

Route110_TrickHousePuzzle1_Text_26BA57: @ 826BA57
	.string "I never get tired of hacking\n"
	.string "and slashing!$"

Route110_TrickHousePuzzle1_Text_26BA82: @ 826BA82
	.string "I wandered into this weird house\n"
	.string "by accident…$"

Route110_TrickHousePuzzle1_Text_26BAB0: @ 826BAB0
	.string "And now I've lost…$"

Route110_TrickHousePuzzle1_Text_26BAC3: @ 826BAC3
	.string "I lost my way, I lost a battle, and I'm\n"
	.string "now even more lost… I can't get out…$"

Route110_TrickHousePuzzle1_Text_26BB10: @ 826BB10
	.string "Just who is the TRICK MASTER?$"

Route110_TrickHousePuzzle1_Text_26BB2E: @ 826BB2E
	.string "I lost while I was lost in thought!$"

Route110_TrickHousePuzzle1_Text_26BB52: @ 826BB52
	.string "You're strong!\n"
	.string "Just who are you?$"

