Route109_MapScripts:: @ 81EE75F
	.byte 0

Route109_EventScript_1EE760:: @ 81EE760
	call Route109_EventScript_271E95
	setobjectpriority 2, ROUTE_109, 0
	setobjectpriority 255, ROUTE_109, 0
	applymovement 2, Route109_Movement_1EE90B
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case 1, Route109_EventScript_1EE7A5
	case 3, Route109_EventScript_1EE7C5
	case 4, Route109_EventScript_1EE7B5
	end

Route109_EventScript_1EE7A5:: @ 81EE7A5
	applymovement 255, Route109_Movement_1EE8FD
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7B5:: @ 81EE7B5
	applymovement 255, Route109_Movement_1EE905
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7C5:: @ 81EE7C5
	applymovement 255, Route109_Movement_1EE908
	waitmovement 0
	goto Route109_EventScript_1EE7D5
	end

Route109_EventScript_1EE7D5:: @ 81EE7D5
	hideobjectat 255, ROUTE_109
	call Route109_EventScript_2720A0
	applymovement 1, Route109_Movement_1EE84F
	applymovement 255, Route109_Movement_1EE84F
	waitmovement 0
	delay 50
	call Route109_EventScript_2720A8
	showobjectat 255, DEWFORD_TOWN
	applymovement 255, Route109_Movement_1EE900
	waitmovement 0
	addobject 4
	clearflag FLAG_0x2E7
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, DEWFORD_TOWN, 0
	applymovement 2, Route109_Movement_1EE90D
	waitmovement 0
	clearflag FLAG_0x2E4
	setflag FLAG_0x2E8
	hideobjectat 1, ROUTE_109
	msgbox Route109_Text_1E9C1D, 4
	closemessage
	copyvar VAR_0x4096, VAR_0x8008
	resetobjectpriority 255, ROUTE_109
	resetobjectpriority 2, DEWFORD_TOWN
	moveobjectoffscreen 2
	release
	end

Route109_Movement_1EE84F: @ 81EE84F
	step_25
	step_down
	step_down
	step_15
	step_15
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_2d
	step_15
	step_15
	step_17
	step_17
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_2f
	step_17
	step_17
	step_17
	step_17
	step_17
	step_17
	step_17
	step_17
	step_17
	step_left
	step_left
	step_25
	step_end

Route109_Movement_1EE8FD: @ 81EE8FD
	step_down
	step_down
	step_end

Route109_Movement_1EE900: @ 81EE900
	step_down
	step_down
	step_left
	step_28
	step_end

Route109_Movement_1EE905: @ 81EE905
	step_right
	step_down
	step_end

Route109_Movement_1EE908: @ 81EE908
	step_left
	step_down
	step_end

Route109_Movement_1EE90B: @ 81EE90B
	step_down
	step_end

Route109_Movement_1EE90D: @ 81EE90D
	step_down
	step_27
	step_end

Route109_EventScript_1EE910:: @ 81EE910
	lock
	faceplayer
	checkflag FLAG_0x095
	goto_if 0, Route109_EventScript_1EE921
	goto Route109_EventScript_1EE93F
	end

Route109_EventScript_1EE921:: @ 81EE921
	message Route109_Text_1EEC96
	msgbox Route109_Text_1EEC96, 5
	compare VAR_RESULT, 0
	goto_eq Route109_EventScript_1EE981
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
	msgbox Route109_Text_1EED06, 4
	closemessage
	goto Route109_EventScript_1EE760
	end

Route109_EventScript_1EE981:: @ 81EE981
	msgbox Route109_Text_1EED5E, 4
	release
	end

Route109_EventScript_1EE98B:: @ 81EE98B
	msgbox Route109_Text_1EEE72, 4
	release
	end

Route109_EventScript_1EE995:: @ 81EE995
	msgbox Route109_Text_1EEEB4, 2
	end

Route109_EventScript_1EE99E:: @ 81EE99E
	lock
	faceplayer
	msgbox Route109_Text_1EEFB0, 4
	closemessage
	applymovement VAR_LAST_TALKED, Route109_Movement_2725A2
	waitmovement 0
	release
	end

Route109_EventScript_1EE9B5:: @ 81EE9B5
	lock
	faceplayer
	special sub_8138B10
	checkflag FLAG_0x118
	goto_eq Route109_EventScript_1EE9F2
	msgbox Route109_Text_1EEFDE, 4
	giveitem_std ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_eq Route109_EventScript_272054
	closemessage
	applymovement VAR_LAST_TALKED, Route109_Movement_2725A2
	waitmovement 0
	setflag FLAG_0x118
	release
	end

Route109_EventScript_1EE9F2:: @ 81EE9F2
	msgbox Route109_Text_1EEFF1, 4
	applymovement VAR_LAST_TALKED, Route109_Movement_2725A2
	waitmovement 0
	release
	end

Route109_EventScript_1EEA06:: @ 81EEA06
	msgbox Route109_Text_1EEF08, 2
	end

Route109_EventScript_1EEA0F:: @ 81EEA0F
	msgbox Route109_Text_1EF080, 2
	end

Route109_EventScript_1EEA18:: @ 81EEA18
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox Route109_Text_1EF173, 4
	waitmoncry
	release
	end

Route109_EventScript_1EEA2B:: @ 81EEA2B
	msgbox Route109_Text_1EF185, 3
	end

Route109_EventScript_1EEA34:: @ 81EEA34
	msgbox Route109_Text_1EF1D5, 3
	end

Route109_EventScript_1EEA3D:: @ 81EEA3D
	trainerbattle 0, TRAINER_DAVID, 0, Route109_Text_297140, Route109_Text_29717D
	msgbox Route109_Text_297191, 6
	end

Route109_EventScript_1EEA54:: @ 81EEA54
	trainerbattle 0, TRAINER_ALICE, 0, Route109_Text_2971D1, Route109_Text_2971FD
	msgbox Route109_Text_29720F, 6
	end

Route109_EventScript_1EEA6B:: @ 81EEA6B
	trainerbattle 0, TRAINER_HUEY, 0, Route109_Text_297235, Route109_Text_29727B
	msgbox Route109_Text_29728C, 6
	end

Route109_EventScript_1EEA82:: @ 81EEA82
	trainerbattle 0, TRAINER_EDMOND, 0, Route109_Text_2972B3, Route109_Text_2972CE
	msgbox Route109_Text_2972ED, 6
	end

Route109_EventScript_1EEA99:: @ 81EEA99
	trainerbattle 2, TRAINER_RICKY_1, 0, Route109_Text_29733B, Route109_Text_297379, Route109_EventScript_1EEAC5
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route109_EventScript_1EEAE4
	msgbox Route109_Text_297380, 4
	release
	end

Route109_EventScript_1EEAC5:: @ 81EEAC5
	special sub_80B4808
	waitmovement 0
	msgbox Route109_Text_2973C1, 4
	setvar VAR_0x8004, 64
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 64
	callstd 8
	release
	end

Route109_EventScript_1EEAE4:: @ 81EEAE4
	trainerbattle 5, TRAINER_RICKY_1, 0, Route109_Text_2973FF, Route109_Text_297437
	msgbox Route109_Text_297458, 6
	end

Route109_EventScript_1EEAFB:: @ 81EEAFB
	trainerbattle 2, TRAINER_LOLA_1, 0, Route109_Text_29749C, Route109_Text_2974CF, Route109_EventScript_1EEB27
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route109_EventScript_1EEB46
	msgbox Route109_Text_2974D6, 4
	release
	end

Route109_EventScript_1EEB27:: @ 81EEB27
	special sub_80B4808
	waitmovement 0
	msgbox Route109_Text_297520, 4
	setvar VAR_0x8004, 57
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 57
	callstd 8
	release
	end

Route109_EventScript_1EEB46:: @ 81EEB46
	trainerbattle 5, TRAINER_LOLA_1, 0, Route109_Text_297538, Route109_Text_297576
	msgbox Route109_Text_29757D, 6
	end

Route109_EventScript_1EEB5D:: @ 81EEB5D
	trainerbattle 0, TRAINER_AUSTINA, 0, Route109_Text_2975C0, Route109_Text_297601
	msgbox Route109_Text_29762A, 6
	end

Route109_EventScript_1EEB74:: @ 81EEB74
	trainerbattle 0, TRAINER_GWEN, 0, Route109_Text_297667, Route109_Text_297691
	msgbox Route109_Text_2976A4, 6
	end

Route109_EventScript_1EEB8B:: @ 81EEB8B
	trainerbattle 0, TRAINER_CARTER, 0, Route109_Text_2976C5, Route109_Text_2976FC
	msgbox Route109_Text_297715, 6
	end

Route109_EventScript_1EEBA2:: @ 81EEBA2
	trainerbattle 4, TRAINER_MEL_AND_PAUL, 0, Route109_Text_297754, Route109_Text_2977B0, Route109_Text_29781D
	msgbox Route109_Text_2977C7, 6
	end

Route109_EventScript_1EEBBD:: @ 81EEBBD
	trainerbattle 4, TRAINER_MEL_AND_PAUL, 0, Route109_Text_297872, Route109_Text_2978BD, Route109_Text_29792E
	msgbox Route109_Text_2978F1, 6
	end

Route109_EventScript_1EEBD8:: @ 81EEBD8
	trainerbattle 0, TRAINER_CHANDLER, 0, Route109_Text_29798A, Route109_Text_2979AE
	msgbox Route109_Text_2979BF, 6
	end

Route109_EventScript_1EEBEF:: @ 81EEBEF
	trainerbattle 0, TRAINER_HAILEY, 0, Route109_Text_2979EC, Route109_Text_297A15
	msgbox Route109_Text_297A40, 6
	end

Route109_EventScript_1EEC06:: @ 81EEC06
	trainerbattle 0, TRAINER_ELIJAH, 0, Route109_Text_297A82, Route109_Text_297AC7
	msgbox Route109_Text_297AE5, 6
	end

DewfordTown_Text_1EEC1D: @ 81EEC1D
	.string "MR. BRINEY: Ahoy!\n"
	.string "We’ve made land in SLATEPORT!\p"
	.string "I suppose you’re going to visit CAPT.\n"
	.string "STERN and deliver the DEVON GOODS?$"

Route109_Text_1EEC96: @ 81EEC96
	.string "MR. BRINEY: I thought you’re supposed\n"
	.string "to deliver the DEVON GOODS.\p"
	.string "Would you like to sail back to\n"
	.string "DEWFORD, then?$"

Route109_Text_1EED06: @ 81EED06
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we’re setting sail, my darling!$"

Route109_Text_1EED5E: @ 81EED5E
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the DEVON GOODS. I’ll be waiting.$"

DewfordTown_Text_1EEDA7: @ 81EEDA7
	.string "MR. BRINEY: Ahoy! We’ve made land in\n"
	.string "SLATEPORT!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

Route109_Text_1EEE17: @ 81EEE17
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I’ll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

Route109_Text_1EEE72: @ 81EEE72
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route109_Text_1EEEB4: @ 81EEEB4
	.string "Yo, TRAINERS!\n"
	.string "Whether you’re hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa’s spot!$"

Route109_Text_1EEF08: @ 81EEF08
	.string "Little kids can dart around so quickly…\p"
	.string "You don’t dare take your eyes off them\n"
	.string "for an instant. It’s very taxing.\p"
	.string "Mine are with my POKéMON, so they\n"
	.string "should be okay, but…$"

Route109_Text_1EEFB0: @ 81EEFB0
	.string "Our sand castle’s taking a long time\n"
	.string "to make.$"

Route109_Text_1EEFDE: @ 81EEFDE
	.string "You can have this!$"

Route109_Text_1EEFF1: @ 81EEFF1
	.string "We’re going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we’re going to be a king and\n"
	.string "queen.\p"
	.string "We’ll let you be a servant.$"

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
