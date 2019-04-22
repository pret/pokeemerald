OldaleTown_MapScripts:: @ 81E8EA2
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition: @ 81E8EA8
	call Common_EventScript_SetupRivalGender
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_1E8ED2
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_1E8EDE
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_1E8ECC
	end

OldaleTown_EventScript_1E8ECC:: @ 81E8ECC
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	return

OldaleTown_EventScript_1E8ED2:: @ 81E8ED2
	setobjectxyperm 3, 1, 11
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_1E8EDE:: @ 81E8EDE
	setobjectxyperm 2, 13, 14
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_1E8EEA:: @ 81E8EEA
	msgbox OldaleTown_Text_1E94DA, MSGBOX_SIGN
	end

OldaleTown_EventScript_1E8EF3:: @ 81E8EF3
	msgbox OldaleTown_Text_1E918E, MSGBOX_NPC
	end

OldaleTown_EventScript_1E8EFC:: @ 81E8EFC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_1E8FB9
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_1E8FB9
	setflag FLAG_TEMP_1
	playbgm MUS_TSURETEK, 0
	msgbox OldaleTown_Text_1E91C0, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case 1, OldaleTown_EventScript_1E8F47
	case 2, OldaleTown_EventScript_1E8F5E
	case 4, OldaleTown_EventScript_1E8F75
	end

OldaleTown_EventScript_1E8F47:: @ 81E8F47
	applymovement 2, OldaleTown_Movement_1E8FD7
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E9001
	waitmovement 0
	goto OldaleTown_EventScript_1E8F8C
	end

OldaleTown_EventScript_1E8F5E:: @ 81E8F5E
	applymovement 2, OldaleTown_Movement_1E8FE2
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E900B
	waitmovement 0
	goto OldaleTown_EventScript_1E8F8C
	end

OldaleTown_EventScript_1E8F75:: @ 81E8F75
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E8FF9
	applymovement 2, OldaleTown_Movement_1E8FCE
	waitmovement 0
	goto OldaleTown_EventScript_1E8F8C
	end

OldaleTown_EventScript_1E8F8C:: @ 81E8F8C
	msgbox OldaleTown_Text_1E91FD, MSGBOX_DEFAULT
	giveitem_std ITEM_POTION
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_1E8FC3
	msgbox OldaleTown_Text_1E92AF, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_1E8FB9:: @ 81E8FB9
	msgbox OldaleTown_Text_1E92AF, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_1E8FC3:: @ 81E8FC3
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_1E8FCE: @ 81E8FCE
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_1E8FD7: @ 81E8FD7
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_1E8FE2: @ 81E8FE2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_1E8FEB: @ 81E8FEB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_1E8FF9: @ 81E8FF9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_1E9001: @ 81E9001
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_1E900B: @ 81E900B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_1E9013: @ 81E9013
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_1E901F:: @ 81E901F
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_1E9066
	msgbox OldaleTown_Text_1E939A, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_1E903F:: @ 81E903F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E9182
	applymovement 3, OldaleTown_Movement_1E9185
	waitmovement 0
	msgbox OldaleTown_Text_1E9313, MSGBOX_DEFAULT
	closemessage
	applymovement 3, OldaleTown_Movement_1E918B
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_1E9066:: @ 81E9066
	msgbox OldaleTown_Text_1E93F8, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_1E9070:: @ 81E9070
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_1E90E6
	end

OldaleTown_EventScript_1E9086:: @ 81E9086
	lockall
	applymovement 4, OldaleTown_Movement_1E9170
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_1E90E6
	end

OldaleTown_EventScript_1E90A6:: @ 81E90A6
	lockall
	applymovement 4, OldaleTown_Movement_1E9173
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_1E90E6
	end

OldaleTown_EventScript_1E90C6:: @ 81E90C6
	lockall
	applymovement 4, OldaleTown_Movement_1E9175
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_1E90E6
	end

OldaleTown_EventScript_1E90E6:: @ 81E90E6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq OldaleTown_EventScript_1E90FE
	compare VAR_RESULT, FEMALE
	goto_if_eq OldaleTown_EventScript_1E910C
	end

OldaleTown_EventScript_1E90FE:: @ 81E90FE
	msgbox OldaleTown_Text_1E9462, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_1E911A
	end

OldaleTown_EventScript_1E910C:: @ 81E910C
	msgbox OldaleTown_Text_1E948A, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_1E911A
	end

OldaleTown_EventScript_1E911A:: @ 81E911A
	closemessage
	compare VAR_0x8009, 0
	call_if_eq OldaleTown_EventScript_1E9148
	compare VAR_0x8009, 1
	call_if_eq OldaleTown_EventScript_1E915E
	applymovement 4, OldaleTown_Movement_1E9177
	waitmovement 0
	removeobject 4
	setvar VAR_OLDALE_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_1E9148:: @ 81E9148
	compare VAR_FACING, 1
	goto_if_ne OldaleTown_EventScript_1E915E
	applymovement 4, OldaleTown_Movement_1E9177
	waitmovement 0
	return

OldaleTown_EventScript_1E915E:: @ 81E915E
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E917E
	applymovement 4, OldaleTown_Movement_1E9177
	waitmovement 0
	return

OldaleTown_Movement_1E9170: @ 81E9170
	walk_left
	walk_left
	step_end

OldaleTown_Movement_1E9173: @ 81E9173
	walk_left
	step_end

OldaleTown_Movement_1E9175: @ 81E9175
	face_left
	step_end

OldaleTown_Movement_1E9177: @ 81E9177
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_1E917E: @ 81E917E
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_1E9182: @ 81E9182
	delay_8
	walk_right
	step_end

OldaleTown_Movement_1E9185: @ 81E9185
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_1E918B: @ 81E918B
	walk_down
	walk_left
	step_end

OldaleTown_Text_1E918E: @ 81E918E
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_1E91C0: @ 81E91C0
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_1E91FD: @ 81E91FD
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"

OldaleTown_Text_1E92AF: @ 81E92AF
	.string "A POTION can be used anytime, so it's\n"
	.string "even more useful than a POKéMON CENTER\l"
	.string "in certain situations.$"

OldaleTown_Text_1E9313: @ 81E9313
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_1E939A: @ 81E939A
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_1E93F8: @ 81E93F8
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_1E9462: @ 81E9462
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

OldaleTown_Text_1E948A: @ 81E948A
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_1E94DA: @ 81E94DA
	.string "OLDALE TOWN\n"
	.string "“Where things start off scarce.”$"

