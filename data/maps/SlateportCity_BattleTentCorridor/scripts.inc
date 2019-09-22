SlateportCity_BattleTentCorridor_MapScripts:: @ 8208E26
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_MapScript2_208E5B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_MapScript2_208E31
	.byte 0

SlateportCity_BattleTentCorridor_MapScript2_208E31: @ 8208E31
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_208E3B
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_208E3B:: @ 8208E3B
	setvar VAR_TEMP_1, 1
	compare VAR_0x8006, 1
	goto_if_ne SlateportCity_BattleTentCorridor_EventScript_208E56
	setobjectxy 1, 2, 2
	turnobject 1, DIR_SOUTH

SlateportCity_BattleTentCorridor_EventScript_208E56:: @ 8208E56
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_MapScript2_208E5B: @ 8208E5B
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_208E65
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_208E65:: @ 8208E65
	compare VAR_0x8006, 1
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_208EEE
	setvar VAR_TEMP_0, 1
	applymovement 1, SlateportCity_BattleTentCorridor_Movement_209062
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_209059
	waitmovement 0
	compare VAR_0x8006, 2
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_209044
	setvar VAR_0x8004, 9
	special sub_81B9D08
	setvar VAR_0x8004, 8
	special sub_81B9D08
	msgbox SlateportCity_BattleTentCorridor_Text_25A1C8, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8004, 6
	special sub_81B9D08
	waitstate

SlateportCity_BattleTentCorridor_EventScript_208EB4:: @ 8208EB4
	msgbox SlateportCity_BattleTentCorridor_Text_25AB96, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement 1, SlateportCity_BattleTentCorridor_Movement_209068
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_20905E
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 255, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_208EEE:: @ 8208EEE
	setvar VAR_0x8004, 9
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 16
	special CallBattleFactoryFunction
	msgbox SlateportCity_BattleTentCorridor_Text_25A22D, MSGBOX_DEFAULT
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

SlateportCity_BattleTentCorridor_EventScript_208F0D:: @ 8208F0D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_209014
	compare VAR_RESULT, 2
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_20901B
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208FBB
	case 1, SlateportCity_BattleTentCorridor_EventScript_208F5B
	case 2, SlateportCity_BattleTentCorridor_EventScript_208F89

SlateportCity_BattleTentCorridor_EventScript_208F5B:: @ 8208F5B
	msgbox SlateportCity_BattleTentCorridor_Text_25A350, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208F0D
	case 1, SlateportCity_BattleTentCorridor_EventScript_209022
	case 127, SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_EventScript_208F89:: @ 8208F89
	message SlateportCity_BattleTentCorridor_Text_25A37A
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_208F0D
	case 0, SlateportCity_BattleTentCorridor_EventScript_209A1B
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_EventScript_208FBB:: @ 8208FBB
	setvar VAR_0x8004, 8
	special sub_81B9D08
	msgbox SlateportCity_BattleTentCorridor_Text_25AB2E, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_208EB4
	case 1, SlateportCity_BattleTentCorridor_EventScript_208FF1
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_208EB4

SlateportCity_BattleTentCorridor_EventScript_208FF1:: @ 8208FF1
	fadescreen 1
	setvar VAR_0x8004, 7
	special sub_81B9D08
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_208EB4
	msgbox SlateportCity_BattleTentCorridor_Text_25AB6C, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_208EB4

SlateportCity_BattleTentCorridor_EventScript_209014:: @ 8209014
	message SlateportCity_BattleTentCorridor_Text_25A263
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_20901B:: @ 820901B
	message SlateportCity_BattleTentCorridor_Text_25A289
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_209022:: @ 8209022
	message SlateportCity_BattleTentCorridor_Text_25ABAE
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special sub_81B9D08
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special CallFrontierUtilFunc
	end

SlateportCity_BattleTentCorridor_EventScript_209044:: @ 8209044
	special SavePlayerParty
	setvar VAR_0x8004, 10
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	goto SlateportCity_BattleTentCorridor_EventScript_208F0D

SlateportCity_BattleTentCorridor_Movement_209059: @ 8209059
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_20905E: @ 820905E
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_209062: @ 8209062
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

SlateportCity_BattleTentCorridor_Movement_209068: @ 8209068
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Text_20906B: @ 820906B
	.string "Want a tasty little bit of advice\n"
	.string "for CONTESTS?\p"
	.string "Using a certain move after another\n"
	.string "certain kind of move sometimes gets\l"
	.string "you extra attention.\p"
	.string "If you know what you're doing,\n"
	.string "you can score big in appeal.\p"
	.string "Of course, your opponents might try\n"
	.string "disrupting your POKéMON's showing.$"

SlateportCity_BattleTentCorridor_Text_20917A: @ 820917A
	.string "My papa, he's a CONTEST JUDGE.\p"
	.string "I wonder what I should be when I\n"
	.string "grow up, a JUDGE or a GYM LEADER?$"

SlateportCity_BattleTentCorridor_Text_2091DC: @ 82091DC
	.string "Hey, man, I'm like majorly cheesed,\n"
	.string "you know. Like, you know, I just\l"
	.string "wanted to know why my POKéMON\l"
	.string "never won, you know, like, hey?\p"
	.string "So, like, I gave the JUDGE my two\n"
	.string "cents, you know, they're free.\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

SlateportCity_BattleTentCorridor_Text_209322: @ 8209322
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's TORMENT, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

SlateportCity_BattleTentCorridor_Text_2093ED: @ 82093ED
	.string "MC: Oh, my, my!\n"
	.string "Now isn't that a dandy of a POKéMON?\p"
	.string "Please! Do step right up and take\n"
	.string "part in our splendid CONTESTS!\p"
	.string "You'll do well! I'm sure of it!\n"
	.string "My eyes have never failed me!$"

SlateportCity_BattleTentCorridor_Text_2094A1: @ 82094A1
	.string "JUDGE: Well, hello there!\n"
	.string "I see that you're a TRAINER!\p"
	.string "Then, it just wouldn't do for you\n"
	.string "to miss a POKéMON CONTEST!\p"
	.string "Get a CONTEST PASS in VERDANTURF\n"
	.string "CITY and enter anytime!$"

SlateportCity_BattleTentCorridor_Text_20954E: @ 820954E
	.string "It's appeal time!\n"
	.string "What should I lead with?$"

SlateportCity_BattleTentCorridor_Text_209579: @ 8209579
	.string "They didn't pay much attention to\n"
	.string "my POKéMON's appeal…\p"
	.string "Humph, that JUDGE, he doesn't know\n"
	.string "a good thing when he sees it.$"

SlateportCity_BattleTentCorridor_Text_2095F1: @ 82095F1
	.string "Oh, hi! You must be a serious fan to get\n"
	.string "this close to the action.\p"
	.string "I'll reward your enthusiasm with\n"
	.string "this sage advice.\p"
	.string "If a move goes over really well,\n"
	.string "the audience will get excited.\p"
	.string "The POKéMON that makes its appeal\n"
	.string "right when everyone's excited…\p"
	.string "Well, you'd think something good has\n"
	.string "to happen!$"

SlateportCity_BattleTentCorridor_Text_209718: @ 8209718
	.string "I can't do this! I'm more freaked out\n"
	.string "than my POKéMON.\p"
	.string "I'm shivering and my heart is racing!$"

SlateportCity_BattleTentCorridor_Text_209775: @ 8209775
	.string "A battle and a CONTEST aren't the\n"
	.string "same, but they are alike, too.\p"
	.string "You need to work hard and believe\n"
	.string "in the POKéMON you've raised.$"

SlateportCity_BattleTentCorridor_Text_2097F6: @ 82097F6
	.string "That POKéMON looks like it's on top\n"
	.string "of its game, huh?\p"
	.string "A POKéMON that does good in the\n"
	.string "secondary judging seems to be more\l"
	.string "relaxed when it's doing appeals.$"

SlateportCity_BattleTentCorridor_Text_209890: @ 8209890
	.string "Will you look at that sorry sight?\p"
	.string "Heh, my POKéMON's absolutely better\n"
	.string "than that lot!$"

SlateportCity_BattleTentCorridor_Text_2098E6: @ 82098E6
	.string "Don't you get the urge to move with\n"
	.string "POKéMON if they're putting on an\l"
	.string "energetic appeal?$"

SlateportCity_BattleTentCorridor_Text_20993D: @ 820993D
	.string "POKéMON CONTESTS\n"
	.string "HYPER RANK STAGE!$"

