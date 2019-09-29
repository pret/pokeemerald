DewfordTown_MapScripts:: @ 81E9507
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_1E9511:: @ 81E9511
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_1E9585
	message DewfordTown_Text_1E9C8A
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, 0
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_1E955A
	case 1, DewfordTown_EventScript_1E956A
	case 2, DewfordTown_EventScript_1E957A
	case MULTI_B_PRESSED, DewfordTown_EventScript_1E957A
	end

DewfordTown_EventScript_1E955A:: @ 81E955A
	msgbox DewfordTown_Text_1E9CE5, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E9660
	release
	end

DewfordTown_EventScript_1E956A:: @ 81E956A
	msgbox DewfordTown_Text_1E9D3A, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E96E7
	release
	end

DewfordTown_EventScript_1E957A:: @ 81E957A
	msgbox DewfordTown_Text_1E9D8F, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_1E9585:: @ 81E9585
	msgbox DewfordTown_Text_1E9B24, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E95A2
	msgbox DewfordTown_Text_1E9BD9, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E95A2:: @ 81E95A2
	msgbox DewfordTown_Text_1E9B7F, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E9660
	end

DewfordTown_EventScript_1E95B1:: @ 81E95B1
	msgbox DewfordTown_Text_1E99A8, MSGBOX_NPC
	end

DewfordTown_EventScript_1E95BA:: @ 81E95BA
	msgbox DewfordTown_Text_1E9A0F, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95C3:: @ 81E95C3
	msgbox DewfordTown_Text_1E9A3D, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95CC:: @ 81E95CC
	msgbox DewfordTown_Text_1E9A7F, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95D5:: @ 81E95D5
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_1E962A
	msgbox DewfordTown_Text_1E9DD1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E95FF
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9620
	end

DewfordTown_EventScript_1E95FF:: @ 81E95FF
	msgbox DewfordTown_Text_1E9E14, MSGBOX_DEFAULT
	giveitem_std ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_1E9E65, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9620:: @ 81E9620
	msgbox DewfordTown_Text_1E9F92, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E962A:: @ 81E962A
	message DewfordTown_Text_1E9FB8
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, 1
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E964C
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9656
	end

DewfordTown_EventScript_1E964C:: @ 81E964C
	msgbox DewfordTown_Text_1E9FD0, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9656:: @ 81E9656
	msgbox DewfordTown_Text_1EA004, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9660:: @ 81E9660
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement 4, DewfordTown_Movement_1E97A2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E97A2
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9914
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 255, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_1E96E7:: @ 81E96E7
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement 4, DewfordTown_Movement_1E9865
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9865
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9918
	waitmovement 0
	setobjectxyperm 2, 21, 26
	addobject 2
	setobjectpriority 2, MAP_ROUTE109, 0
	applymovement 2, DewfordTown_Movement_1E991F
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	addobject 1
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9790
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9799
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectpriority 2, MAP_ROUTE109
	copyobjectxytoperm 2
	release
	end

DewfordTown_EventScript_1E9790:: @ 81E9790
	msgbox DewfordTown_Text_1EEC1D, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_1E9799:: @ 81E9799
	msgbox DewfordTown_Text_1EEDA7, MSGBOX_DEFAULT
	return

DewfordTown_Movement_1E97A2: @ 81E97A2
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_1E9865: @ 81E9865
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_1E9911: @ 81E9911
	walk_right
	walk_up
	step_end

DewfordTown_Movement_1E9914: @ 81E9914
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_1E9918: @ 81E9918
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

DewfordTown_Movement_1E991D: @ 81E991D
	walk_up
	step_end

DewfordTown_Movement_1E991F: @ 81E991F
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_1E9922:: @ 81E9922
	lock
	faceplayer
	call DewfordTown_EventScript_271E8B
	msgbox DewfordTown_Text_1EA136, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9948
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9952
	end

DewfordTown_EventScript_1E9948:: @ 81E9948
	msgbox DewfordTown_Text_1EA491, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9952:: @ 81E9952
	msgbox DewfordTown_Text_1EA242, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E997D
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9994
	end

DewfordTown_EventScript_1E997D:: @ 81E997D
	incrementgamestat GAME_STAT_STARTED_TRENDS
	compare VAR_0x8004, 0
	goto_if_eq DewfordTown_EventScript_1E999E
	msgbox DewfordTown_Text_1EA2AA, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9994:: @ 81E9994
	msgbox DewfordTown_Text_1EA443, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E999E:: @ 81E999E
	msgbox DewfordTown_Text_1EA3FE, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_1E99A8: @ 81E99A8
	.string "DEWFORD is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"

DewfordTown_Text_1E9A0F: @ 81E9A0F
	.string "DEWFORD TOWN\n"
	.string "“A tiny island in the blue sea.”$"

DewfordTown_Text_1E9A3D: @ 81E9A3D
	.string "DEWFORD TOWN POKéMON GYM\n"
	.string "LEADER: BRAWLY\l"
	.string "“A big wave in fighting!”$"

DewfordTown_Text_1E9A7F: @ 81E9A7F
	.string "DEWFORD HALL\n"
	.string "“Everyone's information exchange!”$"

Route104_Text_1E9AAF: @ 81E9AAF
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've hit land in DEWFORD.\p"
	.string "I suppose you're off to deliver that\n"
	.string "LETTER to, who was it now, STEVEN!$"

DewfordTown_Text_1E9B24: @ 81E9B24
	.string "MR. BRINEY: Have you delivered your\n"
	.string "LETTER?\p"
	.string "Or were you meaning to sail back to\n"
	.string "PETALBURG?$"

DewfordTown_Text_1E9B7F: @ 81E9B7F
	.string "MR. BRINEY: PETALBURG it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

DewfordTown_Text_1E9BD9: @ 81E9BD9
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the LETTER. I'll be waiting.$"

Route104_Text_1E9C1D: @ 81E9C1D
Route109_Text_1E9C1D: @ 81E9C1D
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've hit land in DEWFORD!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

DewfordTown_Text_1E9C8A: @ 81E9C8A
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

DewfordTown_Text_1E9CE5: @ 81E9CE5
	.string "MR. BRINEY: PETALBURG, is it?\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

DewfordTown_Text_1E9D3A: @ 81E9D3A
	.string "MR. BRINEY: SLATEPORT, is it?\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

DewfordTown_Text_1E9D8F: @ 81E9D8F
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

DewfordTown_Text_1E9DD1: @ 81E9DD1
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"

DewfordTown_Text_1E9E14: @ 81E9E14
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing RODS.$"

DewfordTown_Text_1E9E65: @ 81E9E65
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

DewfordTown_Text_1E9F92: @ 81E9F92
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"

DewfordTown_Text_1E9FB8: @ 81E9FB8
	.string "Yo!\n"
	.string "How's your fishing?$"

DewfordTown_Text_1E9FD0: @ 81E9FD0
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"

DewfordTown_Text_1EA004: @ 81EA004
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

DewfordTown_Text_1EA136: @ 81EA136
	.string "I like what's hip, happening, and trendy.\n"
	.string "I'm always checking it out.\p"
	.string "Listen, have you heard about this new\n"
	.string "“{STR_VAR_1}”?\p"
	.string "That's right!\n"
	.string "Of course you know!\p"
	.string "I mean, sheesh,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "It's the hottest thing in cool!\p"
	.string "Wherever you're from,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is the biggest happening thing, right?$"

DewfordTown_Text_1EA242: @ 81EA242
	.string "Hunh?\n"
	.string "It's not the hip and happening thing?\p"
	.string "Well, hey, you have to tell me,\n"
	.string "what's new and what's “in”?$"

DewfordTown_Text_1EA2AA: @ 81EA2AA
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Yeah! That's right!\n"
	.string "Yeah, I knew that! Knew it all along!\p"
	.string "Of course I know about that!\n"
	.string "“{STR_VAR_2},” right?\p"
	.string "Yeah, that's it, it's there!\n"
	.string "Isn't “{STR_VAR_2}”\l"
	.string "the coolest, or what?\p"
	.string "It's the hippest thing in hip.\n"
	.string "You think I'd not know about it?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "It's, like, so five minutes ago.\p"
	.string "Now, “{STR_VAR_2}” is\n"
	.string "what's vital and in tune with the times!$"

DewfordTown_Text_1EA3FE: @ 81EA3FE
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” huh?\p"
	.string "But personally, I think\n"
	.string "“{STR_VAR_1}”\l"
	.string "is what's real in cool.$"

DewfordTown_Text_1EA443: @ 81EA443
	.string "Well, if you hear of any happening new\n"
	.string "trends, come share them with me, okay?$"

DewfordTown_Text_1EA491: @ 81EA491
	.string "Yeah, absolutely right!\p"
	.string "“{STR_VAR_1}” is the\n"
	.string "definition of “in” right now.$"
