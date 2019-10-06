Route110_TrickHouseEnd_MapScripts:: @ 826ACAF
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_MapScript1_26ACC4
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_MapScript2_26ACF5
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_MapScript2_26ACDE
	.byte 0

Route110_TrickHouseEnd_MapScript1_26ACC4: @ 826ACC4
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHouseEnd_EventScript_26AD0D
	end

Route110_TrickHouseEnd_OnTransition: @ 826ACD0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseEndRoomFlag
	end

Route110_TrickHouseEnd_MapScript2_26ACDE: @ 826ACDE
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_26ACE8
	.2byte 0

Route110_TrickHouseEnd_EventScript_26ACE8:: @ 826ACE8
	addobject 1
	showobjectat 1, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject 1, DIR_EAST
	end

Route110_TrickHouseEnd_MapScript2_26ACF5: @ 826ACF5
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_26ACFF
	.2byte 0

Route110_TrickHouseEnd_EventScript_26ACFF:: @ 826ACFF
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_26AD0D
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_26AD0D:: @ 826AD0D
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, 1
	return

Route110_TrickHouseEnd_EventScript_26AD17:: @ 826AD17
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_26B08D, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_26AD84
	case 1, Route110_TrickHouseEnd_EventScript_26ADC0
	case 2, Route110_TrickHouseEnd_EventScript_26ADFC
	case 3, Route110_TrickHouseEnd_EventScript_26AE38
	case 4, Route110_TrickHouseEnd_EventScript_26AE74
	case 5, Route110_TrickHouseEnd_EventScript_26AEB0
	case 6, Route110_TrickHouseEnd_EventScript_26AEEC
	case 7, Route110_TrickHouseEnd_EventScript_26AF28
	end

Route110_TrickHouseEnd_EventScript_26AD84:: @ 826AD84
	msgbox Route110_TrickHouseEnd_Text_26B0BC, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_RARE_CANDY
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26ADC0:: @ 826ADC0
	msgbox Route110_TrickHouseEnd_Text_26B13B, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_TIMER_BALL
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26ADFC:: @ 826ADFC
	msgbox Route110_TrickHouseEnd_Text_26B1AD, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_HARD_STONE
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AE38:: @ 826AE38
	msgbox Route110_TrickHouseEnd_Text_26B223, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_SMOKE_BALL
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AE74:: @ 826AE74
	msgbox Route110_TrickHouseEnd_Text_26B293, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_TM12
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AEB0:: @ 826AEB0
	msgbox Route110_TrickHouseEnd_Text_26B315, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_MAGNET
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AEEC:: @ 826AEEC
	msgbox Route110_TrickHouseEnd_Text_26B365, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_PP_MAX
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AF28:: @ 826AF28
	msgbox Route110_TrickHouseEnd_Text_26B3AB, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 1
	call_if_eq Route110_TrickHouseEnd_EventScript_26B015
	compare VAR_FACING, 2
	call_if_eq Route110_TrickHouseEnd_EventScript_26B020
	compare VAR_FACING, 3
	call_if_eq Route110_TrickHouseEnd_EventScript_26B02B
	compare VAR_FACING, 4
	call_if_eq Route110_TrickHouseEnd_EventScript_26B036
	delay 30
	msgbox Route110_TrickHouseEnd_Text_26B3FA, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_26B485, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_26AFA5
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26B002
	msgbox Route110_TrickHouseEnd_Text_26B69A, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_26AFCF
	special ResetTrickHouseEndRoomFlag
	release
	end

Route110_TrickHouseEnd_EventScript_26AFA5:: @ 826AFA5
	multichoice 0, 0, MULTI_TENT, 1
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_26AFBF
	goto Route110_TrickHouseEnd_EventScript_26AFC7

Route110_TrickHouseEnd_EventScript_26AFBF:: @ 826AFBF
	givedecoration_std DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_26AFC7:: @ 826AFC7
	givedecoration_std DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_26AFCF:: @ 826AFCF
	applymovement 1, Route110_TrickHouseEnd_Movement_269E36
	waitmovement 0
	playse SE_W153
	applymovement 1, Route110_TrickHouseEnd_Movement_269E3F
	waitmovement 0
	removeobject 1
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_26AFEF:: @ 826AFEF
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_26B760, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_26B002:: @ 826B002
	call Common_EventScript_NoRoomLeftForAnother
	msgbox Route110_TrickHouseEnd_Text_26B615, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_26B015:: @ 826B015
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B020:: @ 826B020
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B02B:: @ 826B02B
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B036:: @ 826B036
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B041:: @ 826B041
	lockall
	turnobject 1, DIR_WEST
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement 1, Route110_TrickHouseEnd_Movement_26B08B
	waitmovement 0
	playse SE_W153
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_26B8BD, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route110_TrickHouseEnd_Movement_26B089
	waitmovement 0
	delay 4
	turnobject 1, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_26B089: @ 826B089
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_26B08B: @ 826B08B
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_26B08D: @ 826B08D
	.string "Aak!\n"
	.string "You've made it to me?\l"
	.string "Hmmm… You're sharp!$"

Route110_TrickHouseEnd_Text_26B0BC: @ 826B0BC
	.string "It took me all night to plant all those\n"
	.string "trees…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five, six places!$"

Route110_TrickHouseEnd_Text_26B13B: @ 826B13B
	.string "It took me all night to make the maze…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five places!$"

Route110_TrickHouseEnd_Text_26B1AD: @ 826B1AD
	.string "It took me all night to prepare\n"
	.string "the wall panels…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four places!$"

Route110_TrickHouseEnd_Text_26B223: @ 826B223
	.string "It took me all night to shove in those\n"
	.string "boulders…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three places!$"

Route110_TrickHouseEnd_Text_26B293: @ 826B293
	.string "It took me all night to make MECHADOLLS\n"
	.string "and another to think up the quiz…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two places!$"

Route110_TrickHouseEnd_Text_26B315: @ 826B315
	.string "It took me all night to install\n"
	.string "the doors…\p"
	.string "You're almost my equal in greatness!$"

Route110_TrickHouseEnd_Text_26B365: @ 826B365
	.string "It took me all night setting up arrows…\p"
	.string "You're my equal in greatness!$"

Route110_TrickHouseEnd_Text_26B3AB: @ 826B3AB
	.string "It took me all night polishing floors…\p"
	.string "You're above me in greatness!\n"
	.string "Possibly…$"

Route110_TrickHouseEnd_Text_26B3FA: @ 826B3FA
	.string "Wh-what should I do?\n"
	.string "My fountain of ideas for tricks has\l"
	.string "run dry…\p"
	.string "Perhaps it is time I toured the country\n"
	.string "on a quest to devise new tricks…$"

Route110_TrickHouseEnd_Text_26B485: @ 826B485
	.string "I hate to admit defeat, but you have\n"
	.string "bested me!\p"
	.string "Still, you must have been reeled in by\n"
	.string "my charisma for you to visit me again\l"
	.string "and again. Yes, you must have!\p"
	.string "But that has nothing to do with my\n"
	.string "losing!\p"
	.string "In recognition of the friendship\n"
	.string "between you, the driven, and the genius\l"
	.string "that is myself, I demand that you take\l"
	.string "this keepsake!\p"
	.string "Actually there are two--\n"
	.string "a RED TENT and a BLUE TENT.\l"
	.string "Which do you prefer?$"

Route110_TrickHouseEnd_Text_26B615: @ 826B615
	.string "What? No room in your PC?\n"
	.string "What am I to make of that?\p"
	.string "I wish I could say that, but I am much\n"
	.string "too kind and caring, so come back later!$"

Route110_TrickHouseEnd_Text_26B69A: @ 826B69A
	.string "… … … … … …\p"
	.string "I am leaving on a journey of discovery.\n"
	.string "A quest in search of new tricks.\p"
	.string "I wish that you will one day visit and\n"
	.string "entertain me again.\p"
	.string "And now, farewell!$"

Route110_TrickHouseEnd_Text_26B73D: @ 826B73D
	.string "Fine!\n"
	.string "You have earned this reward!$"

Route110_TrickHouseEnd_Text_26B760: @ 826B760
	.string "What? Have you no room for this?\n"
	.string "What manner of items do you carry?\p"
	.string "But fine, since you've reached me,\n"
	.string "your reward will be with me till later.$"

Route110_TrickHouseEnd_Text_26B7EF: @ 826B7EF
	.string "Scrub that smug smirk from your face!\n"
	.string "It's much too early to think you've won!\p"
	.string "I'll make new tricks to stump you, I will.\n"
	.string "You may mock me only when you're done.\p"
	.string "Come back for the next exciting\n"
	.string "installment!$"

Route110_TrickHouseEnd_Text_26B8BD: @ 826B8BD
	.string "Now, now! You're ignoring me now?\n"
	.string "Now that, I consider heartbreaking!$"

