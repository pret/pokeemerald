SSTidalCorridor_MapScripts:: @ 823BFCF
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_MapScript2_23BFD5
	.byte 0

SSTidalCorridor_MapScript2_23BFD5: @ 823BFD5
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_23C219
	map_script_2 VAR_PORTHOLE_STATE, 1, SSTidalCorridor_EventScript_23BFFF
	map_script_2 VAR_PORTHOLE_STATE, 5, SSTidalCorridor_EventScript_23C015
	map_script_2 VAR_PORTHOLE_STATE, 9, SSTidalCorridor_EventScript_23C067
	map_script_2 VAR_PORTHOLE_STATE, 10, SSTidalCorridor_EventScript_23C07D
	.2byte 0

SSTidalCorridor_EventScript_23BFFF:: @ 823BFFF
	special SetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 2
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C462, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C015:: @ 823C015
	setvar VAR_PORTHOLE_STATE, 6
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C4E3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_23C028:: @ 823C028
	special SetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 7
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C462, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_23C03C:: @ 823C03C
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 4
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C553, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_23C050:: @ 823C050
	compare VAR_PORTHOLE_STATE, 2
	goto_if_eq SSTidalCorridor_EventScript_23C067
	compare VAR_PORTHOLE_STATE, 7
	goto_if_eq SSTidalCorridor_EventScript_23C07D
	end

SSTidalCorridor_EventScript_23C067:: @ 823C067
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 3
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C4E3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C07D:: @ 823C07D
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 8
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C50F, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_23C093:: @ 823C093
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 8
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C50F, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_23C0A7:: @ 823C0A7
	switch VAR_PORTHOLE_STATE
	case 2, SSTidalRooms_EventScript_23C03C
	case 3, SSTidalRooms_EventScript_23C03C
	case 6, SSTidalRooms_EventScript_23C028
	case 7, SSTidalRooms_EventScript_23C093
	return

SSTidalCorridor_EventScript_23C0D9:: @ 823C0D9
	msgbox SSTidalCorridor_Text_23C6EC, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_23C0E2:: @ 823C0E2
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox SSTidalCorridor_Text_23C7E1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_23C0F5:: @ 823C0F5
	msgbox SSTidalCorridor_Text_23C7F8, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C0FE:: @ 823C0FE
	msgbox SSTidalCorridor_Text_23C800, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C107:: @ 823C107
	msgbox SSTidalCorridor_Text_23C808, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C110:: @ 823C110
	msgbox SSTidalCorridor_Text_23C810, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C119:: @ 823C119
	lock
	faceplayer
	compare VAR_PORTHOLE_STATE, 4
	goto_if_eq SSTidalCorridor_EventScript_23C13B
	compare VAR_PORTHOLE_STATE, 8
	goto_if_eq SSTidalCorridor_EventScript_23C15A
	msgbox SSTidalCorridor_Text_23C596, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C13B:: @ 823C13B
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_23C64F, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_23C179
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_23C15A:: @ 823C15A
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_23C64F, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_23C179
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_23C179:: @ 823C179
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_23C17D:: @ 823C17D
	lockall
	compare VAR_PORTHOLE_STATE, 2
	goto_if_eq SSTidalCorridor_EventScript_23C19E
	compare VAR_PORTHOLE_STATE, 7
	goto_if_eq SSTidalCorridor_EventScript_23C19E
	msgbox SSTidalCorridor_Text_23C6C3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C19E:: @ 823C19E
	special sub_80FB7A4
	waitstate
	end

SSTidalCorridor_EventScript_23C1A3:: @ 823C1A3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_23C1BD
	call SSTidalCorridor_EventScript_23C1C7
	msgbox SSTidalCorridor_Text_23C65E, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C1BD:: @ 823C1BD
	msgbox SSTidalCorridor_Text_23C6B0, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C1C7:: @ 823C1C7
	checktrainerflag TRAINER_PHILLIP
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_LEONARD
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_COLTON
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_MICAH
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_THOMAS
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_LEA_AND_JED
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_GARRET
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_NAOMI
	goto_if_lt SSTidalCorridor_EventScript_23C218
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_23C1BD
	return

SSTidalCorridor_EventScript_23C218:: @ 823C218
	return

SSTidalCorridor_EventScript_23C219:: @ 823C219
	lockall
	applymovement 5, SSTidalCorridor_Movement_23C26D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_23C28F, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, SSTidalCorridor_Movement_23C27D
	applymovement 1, SSTidalCorridor_Movement_23C284
	applymovement 5, SSTidalCorridor_Movement_23C275
	waitmovement 0
	playse SE_KAIDAN
	waitse
	removeobject 5
	applymovement 1, SSTidalCorridor_Movement_23C28B
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_23C26D: @ 823C26D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_23C275: @ 823C275
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_23C27D: @ 823C27D
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

SSTidalCorridor_Movement_23C284: @ 823C284
	delay_16
	walk_right
	walk_right
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_left
	step_end

SSTidalCorridor_Movement_23C28B: @ 823C28B
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

SSTidalCorridor_Text_23C28F: @ 823C28F
	.string "SCOTT: Well, hi, hi!\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
	.string "Something's come up, so I have to\n"
	.string "disembark, but am I glad to see you!\p"
	.string "Congratulations, LEAGUE CHAMPION!\p"
	.string "There's a place I'd like to invite\n"
	.string "someone like you.\p"
	.string "It's the…\n"
	.string "BATTLE FRONTIER!\p"
	.string "What's the place like?\n"
	.string "You'll understand when you see it!\p"
	.string "I've spoken with the ship's CAPTAIN\n"
	.string "about this.\p"
	.string "The next time you take a ferry,\n"
	.string "you should be able to sail to\l"
	.string "the BATTLE FRONTIER.\p"
	.string "Okay, {PLAYER}{KUN}, I'll be waiting for you\n"
	.string "at the BATTLE FRONTIER!$"

SSTidalCorridor_Text_23C462: @ 823C462
SSTidalRooms_Text_23C462: @ 823C462
	.string "This ferry is built to plow through\n"
	.string "fast-running currents.\p"
	.string "We hope you enjoy your voyage with us.\n"
	.string "Feel free to explore the ship.$"

SSTidalCorridor_Text_23C4E3: @ 823C4E3
	.string "We hope you enjoy your voyage on\n"
	.string "our ferry.$"

SSTidalCorridor_Text_23C50F: @ 823C50F
SSTidalRooms_Text_23C50F: @ 823C50F
	.string "We have made land in SLATEPORT CITY.\n"
	.string "Thank you for sailing with us.$"

SSTidalRooms_Text_23C553: @ 823C553
	.string "We have made land in LILYCOVE CITY.\n"
	.string "Thank you for sailing with us.$"

SSTidalCorridor_Text_23C596: @ 823C596
	.string "It'll be some time before we make land,\n"
	.string "I reckon.\p"
	.string "You can rest up in your cabin if you'd\n"
	.string "like. Your cabin's No. 2.\p"
	.string "The bed in there is soft and plushy.\n"
	.string "I can attest to how comfy it is!$"

SSTidalCorridor_Text_23C64F: @ 823C64F
	.string "We've arrived!$"

SSTidalCorridor_Text_23C65E: @ 823C65E
	.string "Go visit other cabins.\n"
	.string "TRAINERS bored of the boat trip will\l"
	.string "be itching to battle.$"

SSTidalCorridor_Text_23C6B0: @ 823C6B0
	.string "Enjoy your cruise!$"

SSTidalCorridor_Text_23C6C3: @ 823C6C3
	.string "The horizon spreads beyond\n"
	.string "the porthole.$"

SSTidalCorridor_Text_23C6EC: @ 823C6EC
	.string "MR. BRINEY: Welcome aboard, {PLAYER}{KUN}!\p"
	.string "They made me honorary captain of\n"
	.string "the S.S. TIDAL!\p"
	.string "You can call me CAPTAIN BRINEY now!\p"
	.string "You know, I retired once before,\n"
	.string "but when I saw this majestic ship…\p"
	.string "Let me just say, it stirred my sleeping\n"
	.string "soul as a sailor!$"

SSTidalCorridor_Text_23C7E1: @ 823C7E1
	.string "PEEKO: Pihyo pihyohyo…$"

SSTidalCorridor_Text_23C7F8: @ 823C7F8
	.string "Cabin 1$"

SSTidalCorridor_Text_23C800: @ 823C800
	.string "Cabin 2$"

SSTidalCorridor_Text_23C808: @ 823C808
	.string "Cabin 3$"

SSTidalCorridor_Text_23C810: @ 823C810
	.string "Cabin 4$"
