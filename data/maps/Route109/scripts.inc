Route109_MapScripts:: @ 81EE75F
	.byte 0

Route109_EventScript_1EE760:: @ 81EE760
	call Route109_EventScript_271E95
	setobjectpriority 2, MAP_ROUTE109, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE109, 0
	applymovement 2, Route109_Movement_1EE90B
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case 1, Route109_EventScript_1EE7A5
	case 3, Route109_EventScript_1EE7C5
	case 4, Route109_EventScript_1EE7B5
	end

Route109_EventScript_1EE7A5:: @ 81EE7A5
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE8FD
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7B5:: @ 81EE7B5
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE905
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7C5:: @ 81EE7C5
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE908
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7D5:: @ 81EE7D5
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	call Route109_EventScript_2720A0
	applymovement 1, Route109_Movement_1EE84F
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE84F
	waitmovement 0
	delay 50
	call Route109_EventScript_2720A8
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE900
	waitmovement 0
	addobject 4
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	applymovement 2, Route109_Movement_1EE90D
	waitmovement 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	hideobjectat 1, MAP_ROUTE109
	msgbox Route109_Text_1E9C1D, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	resetobjectpriority 2, MAP_DEWFORD_TOWN
	moveobjectoffscreen 2
	release
	end

Route109_Movement_1EE84F: @ 81EE84F
	walk_in_place_fastest_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
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
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

Route109_Movement_1EE8FD: @ 81EE8FD
	walk_down
	walk_down
	step_end

Route109_Movement_1EE900: @ 81EE900
	walk_down
	walk_down
	walk_left
	walk_in_place_fastest_right
	step_end

Route109_Movement_1EE905: @ 81EE905
	walk_right
	walk_down
	step_end

Route109_Movement_1EE908: @ 81EE908
	walk_left
	walk_down
	step_end

Route109_Movement_1EE90B: @ 81EE90B
	walk_down
	step_end

Route109_Movement_1EE90D: @ 81EE90D
	walk_down
	walk_in_place_fastest_left
	step_end

Route109_EventScript_1EE910:: @ 81EE910
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_1EE921
	goto Route109_EventScript_1EE93F
	end

Route109_EventScript_1EE921:: @ 81EE921
	message Route109_Text_1EEC96
	msgbox Route109_Text_1EEC96, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route109_EventScript_1EE981
	goto Route109_EventScript_1EE972
	end

Route109_EventScript_1EE93F:: @ 81EE93F
	message Route109_Text_1EEE17
	waitmessage
	multichoicedefault 21, 8, 14, 1, 0
	switch VAR_RESULT
	case 0, Route109_EventScript_1EE972
	case 1, Route109_EventScript_1EE98B
	case 127, Route109_EventScript_1EE98B
	end

Route109_EventScript_1EE972:: @ 81EE972
	msgbox Route109_Text_1EED06, MSGBOX_DEFAULT
	closemessage
	goto Route109_EventScript_1EE760
	end

Route109_EventScript_1EE981:: @ 81EE981
	msgbox Route109_Text_1EED5E, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_1EE98B:: @ 81EE98B
	msgbox Route109_Text_1EEE72, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_1EE995:: @ 81EE995
	msgbox Route109_Text_1EEEB4, MSGBOX_NPC
	end

Route109_EventScript_1EE99E:: @ 81EE99E
	lock
	faceplayer
	msgbox Route109_Text_1EEFB0, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_1EE9B5:: @ 81EE9B5
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_1EE9F2
	msgbox Route109_Text_1EEFDE, MSGBOX_DEFAULT
	giveitem_std ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route109_EventScript_1EE9F2:: @ 81EE9F2
	msgbox Route109_Text_1EEFF1, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_1EEA06:: @ 81EEA06
	msgbox Route109_Text_1EEF08, MSGBOX_NPC
	end

Route109_EventScript_1EEA0F:: @ 81EEA0F
	msgbox Route109_Text_1EF080, MSGBOX_NPC
	end

Route109_EventScript_1EEA18:: @ 81EEA18
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox Route109_Text_1EF173, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route109_EventScript_1EEA2B:: @ 81EEA2B
	msgbox Route109_Text_1EF185, MSGBOX_SIGN
	end

Route109_EventScript_1EEA34:: @ 81EEA34
	msgbox Route109_Text_1EF1D5, MSGBOX_SIGN
	end

Route109_EventScript_1EEA3D:: @ 81EEA3D
	trainerbattle_single TRAINER_DAVID, Route109_Text_297140, Route109_Text_29717D
	msgbox Route109_Text_297191, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEA54:: @ 81EEA54
	trainerbattle_single TRAINER_ALICE, Route109_Text_2971D1, Route109_Text_2971FD
	msgbox Route109_Text_29720F, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEA6B:: @ 81EEA6B
	trainerbattle_single TRAINER_HUEY, Route109_Text_297235, Route109_Text_29727B
	msgbox Route109_Text_29728C, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEA82:: @ 81EEA82
	trainerbattle_single TRAINER_EDMOND, Route109_Text_2972B3, Route109_Text_2972CE
	msgbox Route109_Text_2972ED, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEA99:: @ 81EEA99
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_29733B, Route109_Text_297379, Route109_EventScript_1EEAC5
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route109_EventScript_1EEAE4
	msgbox Route109_Text_297380, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_1EEAC5:: @ 81EEAC5
	special sub_80B4808
	waitmovement 0
	msgbox Route109_Text_2973C1, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route109_EventScript_1EEAE4:: @ 81EEAE4
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_2973FF, Route109_Text_297437
	msgbox Route109_Text_297458, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEAFB:: @ 81EEAFB
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_29749C, Route109_Text_2974CF, Route109_EventScript_1EEB27
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route109_EventScript_1EEB46
	msgbox Route109_Text_2974D6, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_1EEB27:: @ 81EEB27
	special sub_80B4808
	waitmovement 0
	msgbox Route109_Text_297520, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route109_EventScript_1EEB46:: @ 81EEB46
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_297538, Route109_Text_297576
	msgbox Route109_Text_29757D, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEB5D:: @ 81EEB5D
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_2975C0, Route109_Text_297601
	msgbox Route109_Text_29762A, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEB74:: @ 81EEB74
	trainerbattle_single TRAINER_GWEN, Route109_Text_297667, Route109_Text_297691
	msgbox Route109_Text_2976A4, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEB8B:: @ 81EEB8B
	trainerbattle_single TRAINER_CARTER, Route109_Text_2976C5, Route109_Text_2976FC
	msgbox Route109_Text_297715, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEBA2:: @ 81EEBA2
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_297754, Route109_Text_2977B0, Route109_Text_29781D
	msgbox Route109_Text_2977C7, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEBBD:: @ 81EEBBD
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_297872, Route109_Text_2978BD, Route109_Text_29792E
	msgbox Route109_Text_2978F1, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEBD8:: @ 81EEBD8
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_29798A, Route109_Text_2979AE
	msgbox Route109_Text_2979BF, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEBEF:: @ 81EEBEF
	trainerbattle_single TRAINER_HAILEY, Route109_Text_2979EC, Route109_Text_297A15
	msgbox Route109_Text_297A40, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_1EEC06:: @ 81EEC06
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_297A82, Route109_Text_297AC7
	msgbox Route109_Text_297AE5, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_1EEC1D: @ 81EEC1D
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've made land in SLATEPORT!\p"
	.string "I suppose you're going to visit CAPT.\n"
	.string "STERN and deliver the DEVON GOODS?$"

Route109_Text_1EEC96: @ 81EEC96
	.string "MR. BRINEY: I thought you're supposed\n"
	.string "to deliver the DEVON GOODS.\p"
	.string "Would you like to sail back to\n"
	.string "DEWFORD, then?$"

Route109_Text_1EED06: @ 81EED06
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Route109_Text_1EED5E: @ 81EED5E
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the DEVON GOODS. I'll be waiting.$"

DewfordTown_Text_1EEDA7: @ 81EEDA7
	.string "MR. BRINEY: Ahoy! We've made land in\n"
	.string "SLATEPORT!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

Route109_Text_1EEE17: @ 81EEE17
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

Route109_Text_1EEE72: @ 81EEE72
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route109_Text_1EEEB4: @ 81EEEB4
	.string "Yo, TRAINERS!\n"
	.string "Whether you're hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa's spot!$"

Route109_Text_1EEF08: @ 81EEF08
	.string "Little kids can dart around so quickly…\p"
	.string "You don't dare take your eyes off them\n"
	.string "for an instant. It's very taxing.\p"
	.string "Mine are with my POKéMON, so they\n"
	.string "should be okay, but…$"

Route109_Text_1EEFB0: @ 81EEFB0
	.string "Our sand castle's taking a long time\n"
	.string "to make.$"

Route109_Text_1EEFDE: @ 81EEFDE
	.string "You can have this!$"

Route109_Text_1EEFF1: @ 81EEFF1
	.string "We're going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we're going to be a king and\n"
	.string "queen.\p"
	.string "We'll let you be a servant.$"

Route109_Text_1EF080: @ 81EF080
	.string "The water around these parts is clean.\p"
	.string "But, I get my ZIGZAGOON to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route109_Text_1EF173: @ 81EF173
	.string "ZIGZAGOON: Guguu?$"

Route109_Text_1EF185: @ 81EF185
	.string "SEASHORE HOUSE\p"
	.string "“May hot battles rage on hot sands!\n"
	.string "The place for hot TRAINERS!”$"

Route109_Text_1EF1D5: @ 81EF1D5
	.string "TRAINER TIPS\p"
	.string "POKéMON at the same level may not\n"
	.string "always have identical stats.\p"
	.string "POKéMON raised by TRAINERS are said\n"
	.string "to grow stronger than wild POKéMON.$"
