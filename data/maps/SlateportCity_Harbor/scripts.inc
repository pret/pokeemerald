SlateportCity_Harbor_MapScripts:: @ 820C97D
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition: @ 820C983
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
	setvar VAR_TEMP_1, 0
	compare VAR_SLATEPORT_HARBOR_STATE, 1
	call_if_eq SlateportCity_Harbor_EventScript_20C9A9
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20C9A5
	end

SlateportCity_Harbor_EventScript_20C9A5:: @ 820C9A5
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_20C9A9:: @ 820C9A9
	savebgm MUS_AQA_0
	setobjectxyperm 4, 12, 13
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_20C9BB:: @ 820C9BB
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9C7:: @ 820C9C7
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9D3:: @ 820C9D3
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9DF:: @ 820C9DF
	lockall
	setvar VAR_0x8008, 3
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CAEF
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9F5:: @ 820C9F5
	applymovement 7, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_20D291, MSGBOX_DEFAULT
	closemessage
	applymovement 6, SlateportCity_Harbor_Movement_20CAC8
	applymovement 7, SlateportCity_Harbor_Movement_20CAC8
	applymovement 8, SlateportCity_Harbor_Movement_20CAD2
	waitmovement 0
	removeobject 6
	removeobject 7
	removeobject 8
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILCOVE_MOTEL_SCOTT
	compare VAR_0x8008, 0
	call_if_eq SlateportCity_Harbor_EventScript_20CA89
	compare VAR_0x8008, 1
	call_if_eq SlateportCity_Harbor_EventScript_20CA9E
	compare VAR_0x8008, 2
	call_if_eq SlateportCity_Harbor_EventScript_20CAB3
	compare VAR_0x8008, 3
	call_if_eq SlateportCity_Harbor_EventScript_20CAB3
	msgbox SlateportCity_Harbor_Text_20D35A, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm 4
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_20CA89:: @ 820CA89
	applymovement 4, SlateportCity_Harbor_Movement_20CAE0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CA9E:: @ 820CA9E
	applymovement 4, SlateportCity_Harbor_Movement_20CAE6
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CAB3:: @ 820CAB3
	applymovement 4, SlateportCity_Harbor_Movement_20CAEB
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_20CAC8: @ 820CAC8
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_20CACD: @ 820CACD
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_20CAD2: @ 820CAD2
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_20CAE0: @ 820CAE0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_20CAE6: @ 820CAE6
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_20CAEB: @ 820CAEB
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_20CAEF: @ 820CAEF
	walk_up
	step_end

SlateportCity_Harbor_EventScript_20CAF1:: @ 820CAF1
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CB06
	msgbox SlateportCity_Harbor_Text_20CE20, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CB06:: @ 820CB06
	msgbox SlateportCity_Harbor_Text_20CE87, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_20CF1C
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CB1A
	end

SlateportCity_Harbor_EventScript_20CB1A:: @ 820CB1A
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_20CB50
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CB92
	case 1, SlateportCity_Harbor_EventScript_20CC2D
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CC2D
	end

SlateportCity_Harbor_EventScript_20CB50:: @ 820CB50
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CB92
	case 1, SlateportCity_Harbor_EventScript_20CBBA
	case 2, SlateportCity_Harbor_EventScript_20CC2D
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CC2D
	end

SlateportCity_Harbor_EventScript_20CB88:: @ 820CB88
	msgbox SlateportCity_Harbor_Text_20CEC1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CB92:: @ 820CB92
	msgbox SlateportCity_Harbor_Text_20CF93, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CBDD
	setvar VAR_PORTHOLE_STATE, 1
	call SlateportCity_Harbor_EventScript_20CBE9
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_20CBBA:: @ 820CBBA
	msgbox SlateportCity_Harbor_Text_20CFAE, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CBDD
	call SlateportCity_Harbor_EventScript_20CBE9
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_20CBDD:: @ 820CBDD
	message SlateportCity_Harbor_Text_20CFFA
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CB1A
	end

SlateportCity_Harbor_EventScript_20CBE9:: @ 820CBE9
	msgbox SlateportCity_Harbor_Text_20CFCB, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	compare VAR_FACING, 2
	call_if_eq SlateportCity_Harbor_EventScript_20CC42
	compare VAR_FACING, 4
	call_if_eq SlateportCity_Harbor_EventScript_20CC37
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 5
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_20CC2D:: @ 820CC2D
	msgbox SlateportCity_Harbor_Text_20CF71, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC37:: @ 820CC37
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CC4D
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CC42:: @ 820CC42
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CC50
	waitmovement 0
	return

SlateportCity_Harbor_Movement_20CC4D: @ 820CC4D
	walk_right
	walk_in_place_fastest_up
	step_end

SlateportCity_Harbor_Movement_20CC50: @ 820CC50
	walk_up
	step_end

SlateportCity_Harbor_EventScript_20CC52:: @ 820CC52
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CC89
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_20CC93
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_20CC93
	compare VAR_0x8004, 2
	goto_if_eq SlateportCity_Harbor_EventScript_20CC89
	msgbox SlateportCity_Harbor_Text_20D08E, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC89:: @ 820CC89
	msgbox SlateportCity_Harbor_Text_20D01C, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC93:: @ 820CC93
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_20CC99:: @ 820CC99
	msgbox SlateportCity_Harbor_Text_20D194, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_20CCA2:: @ 820CCA2
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_20CD00
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_20CCF6
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_20CCE9
	compare VAR_SLATEPORT_HARBOR_STATE, 2
	goto_if_eq SlateportCity_Harbor_EventScript_20CCDF
	msgbox SlateportCity_Harbor_Text_20D232, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_20CCDF:: @ 820CCDF
	msgbox SlateportCity_Harbor_Text_20D35A, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CCE9:: @ 820CCE9
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_20D42B, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CCF6:: @ 820CCF6
	msgbox SlateportCity_Harbor_Text_20D58A, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD00:: @ 820CD00
	compare VAR_TEMP_1, 1
	goto_if_eq SlateportCity_Harbor_EventScript_20CE11
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Harbor_EventScript_20CD38
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CD2E
	msgbox SlateportCity_Harbor_Text_20D65C, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD2E:: @ 820CD2E
	msgbox SlateportCity_Harbor_Text_20D6CB, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD38:: @ 820CD38
	message SlateportCity_Harbor_Text_20D76C
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CD44
	end

SlateportCity_Harbor_EventScript_20CD44:: @ 820CD44
	multichoice 0, 0, MULTI_STERN_DEEPSEA, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CD7B
	case 1, SlateportCity_Harbor_EventScript_20CDBB
	case 2, SlateportCity_Harbor_EventScript_20CDFB
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CDFB
	end

SlateportCity_Harbor_EventScript_20CD7B:: @ 820CD7B
	msgbox SlateportCity_Harbor_Text_20D8BC, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CE05
	giveitem_std ITEM_DEEP_SEA_TOOTH
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	takeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_20D94A, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_20CE11
	end

SlateportCity_Harbor_EventScript_20CDBB:: @ 820CDBB
	msgbox SlateportCity_Harbor_Text_20D8F1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CE05
	giveitem_std ITEM_DEEP_SEA_SCALE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	takeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_20D94A, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_20CE11
	end

SlateportCity_Harbor_EventScript_20CDFB:: @ 820CDFB
	msgbox SlateportCity_Harbor_Text_20D841, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CE05:: @ 820CE05
	message SlateportCity_Harbor_Text_20D926
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CD44
	end

SlateportCity_Harbor_EventScript_20CE11:: @ 820CE11
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_20D970, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_20CE20: @ 820CE20
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

SlateportCity_Harbor_Text_20CE87: @ 820CE87
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"


SlateportCity_Harbor_Text_20CEC1: @ 820CEC1
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

SlateportCity_Harbor_Text_20CF1C: @ 820CF1C
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

SlateportCity_Harbor_Text_20CF71: @ 820CF71
	.string "Please sail with us another time!$"

SlateportCity_Harbor_Text_20CF93: @ 820CF93
	.string "LILYCOVE CITY it is, then!$"

SlateportCity_Harbor_Text_20CFAE: @ 820CFAE
	.string "BATTLE FRONTIER it is, then!$"

SlateportCity_Harbor_Text_20CFCB: @ 820CFCB
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

SlateportCity_Harbor_Text_20CFFA: @ 820CFFA
	.string "Then, where would you like to go?$"

SlateportCity_Harbor_Text_20D01C: @ 820D01C
	.string "A journey to the bottom of the sea…\n"
	.string "I wonder what it'd be like?\p"
	.string "I'd love to go deep underwater like\n"
	.string "that someday.$"

SlateportCity_Harbor_Text_20D08E: @ 820D08E
	.string "For a ship to sail safely, we need to\n"
	.string "know about the weather!\p"
	.string "Speaking of weather, I heard something\n"
	.string "from a guy at the WEATHER INSTITUTE.\p"
	.string "He was saying abnormal weather has\n"
	.string "been reported all over the place!\p"
	.string "You should visit the WEATHER INSTITUTE\n"
	.string "and ask around!$"

SlateportCity_Harbor_Text_20D194: @ 820D194
	.string "I wanted to go with CAPT. STERN on\n"
	.string "the ocean floor exploration.\p"
	.string "But the sub's too small for me.\p"
	.string "If I squeezed in, there wouldn't be\n"
	.string "any room for the CAPTAIN…$"

SlateportCity_Harbor_Text_20D232: @ 820D232
	.string "CAPT. STERN: Those thugs…\p"
	.string "They're the same lot who tried to rob\n"
	.string "the DEVON GOODS at the MUSEUM.$"

SlateportCity_Harbor_Text_20D291: @ 820D291
	.string "ARCHIE: Oh?\n"
	.string "Not you again…\p"
	.string "You are tenacious to track us here,\n"
	.string "that much I will give you.\p"
	.string "But now…\n"
	.string "No one can stop us! No one!\p"
	.string "Or, will you follow us back to our\n"
	.string "HIDEOUT in LILYCOVE CITY?\p"
	.string "Fwahahahaha…$"

SlateportCity_Harbor_Text_20D35A: @ 820D35A
	.string "CAPT. STERN: Why…\p"
	.string "Why would TEAM AQUA steal my\n"
	.string "SUBMARINE EXPLORER 1?\p"
	.string "They can't be after the slumbering\n"
	.string "POKéMON at the bottom of the sea…\p"
	.string "But even if I were to chase them,\n"
	.string "I don't stand a chance against them…$"

SlateportCity_Harbor_Text_20D42B: @ 820D42B
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
	.string "Okay… So TEAM AQUA left before you\n"
	.string "could stop them…\p"
	.string "Oh, no, don't blame yourself.\n"
	.string "You're not responsible for this.\p"
	.string "Trying to catch a submarine…\n"
	.string "It's impossible for most people.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"

SlateportCity_Harbor_Text_20D58A: @ 820D58A
	.string "CAPT. STERN: Trying to catch a\n"
	.string "submarine… It's impossible.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"

SlateportCity_Harbor_Text_20D65C: @ 820D65C
	.string "CAPT. STERN: Oh, yes.\n"
	.string "MR. BRINEY came to our SHIPYARD.\p"
	.string "It won't be long now before we finish\n"
	.string "making the ferry!$"

SlateportCity_Harbor_Text_20D6CB: @ 820D6CB
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
	.string "We finally finished making the ferry\n"
	.string "S.S. TIDAL!\p"
	.string "We couldn't have done it without\n"
	.string "your friend MR. BRINEY.\p"
	.string "Please go for a short cruise on it!$"

SlateportCity_Harbor_Text_20D76C: @ 820D76C
	.string "CAPT. STERN: Oh?\n"
	.string "{PLAYER}{KUN}, that item you have…\p"
	.string "That's a SCANNER! That would sure\n"
	.string "help us on our explorations.\p"
	.string "{PLAYER}{KUN}, would you trade your\n"
	.string "SCANNER for something?\p"
	.string "Like, say, a DEEPSEATOOTH or\n"
	.string "a DEEPSEASCALE that I have?$"

SlateportCity_Harbor_Text_20D841: @ 820D841
	.string "CAPT. STERN: Are you certain?\n"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
	.string "Well, okay, then. If you want to trade\n"
	.string "your SCANNER, let me know.$"

SlateportCity_Harbor_Text_20D8BC: @ 820D8BC
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEATOOTH?$"

SlateportCity_Harbor_Text_20D8F1: @ 820D8F1
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEASCALE?$"

SlateportCity_Harbor_Text_20D926: @ 820D926
	.string "CAPT. STERN: Which one do you want?$"

SlateportCity_Harbor_Text_20D94A: @ 820D94A
	.string "{PLAYER} handed the SCANNER to\n"
	.string "CAPT. STERN.$"

SlateportCity_Harbor_Text_20D970: @ 820D970
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
	.string "This will help our research a lot!$"
