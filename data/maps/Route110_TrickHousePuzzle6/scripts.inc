Route110_TrickHousePuzzle6_MapScripts:: @ 826DDA7
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_MapScript2_26DDB6
	.byte 0

Route110_TrickHousePuzzle6_OnTransition: @ 826DDB2
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_MapScript2_26DDB6: @ 826DDB6
	map_script_2 VAR_TEMP_0, 16384, Route110_TrickHousePuzzle6_EventScript_26DDC0
	.2byte 0

Route110_TrickHousePuzzle6_EventScript_26DDC0:: @ 826DDC0
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_26DDC4:: @ 826DDC4
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle6_EventScript_26DDD6
	goto Route110_TrickHousePuzzle6_EventScript_26A3DB
	end

Route110_TrickHousePuzzle6_EventScript_26DDD6:: @ 826DDD6
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle6_EventScript_26A3E5
	end

Route110_TrickHousePuzzle6_EventScript_26DDE1:: @ 826DDE1
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_26DE93, Route110_TrickHousePuzzle6_Text_26DED2
	msgbox Route110_TrickHousePuzzle6_Text_26DEF3, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_26DDF8:: @ 826DDF8
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_26DF55, Route110_TrickHousePuzzle6_Text_26DF8D
	msgbox Route110_TrickHousePuzzle6_Text_26DFA0, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_26DE0F:: @ 826DE0F
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_26DFD7, Route110_TrickHousePuzzle6_Text_26E004
	msgbox Route110_TrickHousePuzzle6_Text_26E048, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_26DE26: @ 826DE26
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is my life.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle6_Text_26DE93: @ 826DE93
	.string "When I heard there was a strange\n"
	.string "house, I had to check it out.$"

Route110_TrickHousePuzzle6_Text_26DED2: @ 826DED2
	.string "I've discovered a tough TRAINER!$"

Route110_TrickHousePuzzle6_Text_26DEF3: @ 826DEF3
	.string "I'm sure having a good time checking\n"
	.string "this place out.\p"
	.string "It's a challenge I've found worth\n"
	.string "repeating!$"

Route110_TrickHousePuzzle6_Text_26DF55: @ 826DF55
	.string "Maybe I could get my BIRD POKéMON\n"
	.string "to fly over the wall…$"

Route110_TrickHousePuzzle6_Text_26DF8D: @ 826DF8D
	.string "Gwaaah! I blew it!$"

Route110_TrickHousePuzzle6_Text_26DFA0: @ 826DFA0
	.string "Ehehehe… I guess I lost because\n"
	.string "I was trying to cheat.$"

Route110_TrickHousePuzzle6_Text_26DFD7: @ 826DFD7
	.string "I'm getting dizzy from these rotating\n"
	.string "doors…$"

Route110_TrickHousePuzzle6_Text_26E004: @ 826E004
	.string "Everything's spinning around and\n"
	.string "around. I can't take this anymore…$"

Route110_TrickHousePuzzle6_Text_26E048: @ 826E048
	.string "You don't seem to be affected at all.\n"
	.string "Or do you have your poker face on?$"

