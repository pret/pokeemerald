PetalburgWoods_MapScripts:: @ 822DFD6
	.byte 0

PetalburgWoods_EventScript_22DFD7:: @ 822DFD7
	lockall
	call PetalburgWoods_EventScript_22E124
	applymovement 4, PetalburgWoods_Movement_22E1CB
	waitmovement 0
	msgbox PetalburgWoods_Text_22E34F, 4
	closemessage
	playbgm BGM_AQA_0, 0
	applymovement 3, PetalburgWoods_Movement_22E209
	waitmovement 0
	msgbox PetalburgWoods_Text_22E3AA, 4
	closemessage
	applymovement 3, PetalburgWoods_Movement_22E1F6
	waitmovement 0
	applymovement 4, PetalburgWoods_Movement_2725A6
	waitmovement 0
	msgbox PetalburgWoods_Text_22E428, 4
	closemessage
	applymovement 4, PetalburgWoods_Movement_22E1E4
	waitmovement 0
	msgbox PetalburgWoods_Text_22E457, 4
	closemessage
	applymovement 3, PetalburgWoods_Movement_22E20E
	waitmovement 0
	msgbox PetalburgWoods_Text_22E4A5, 4
	trainerbattle 3, TRAINER_GRUNT_8, 0, PetalburgWoods_Text_22E542
	applymovement 3, PetalburgWoods_Movement_22E1F9
	waitmovement 0
	call PetalburgWoods_EventScript_22E138
	applymovement 255, PetalburgWoods_Movement_22E1E0
	applymovement 4, PetalburgWoods_Movement_22E1C2
	waitmovement 0
	goto PetalburgWoods_EventScript_22E1A7
	end

PetalburgWoods_EventScript_22E079:: @ 822E079
	lockall
	call PetalburgWoods_EventScript_22E124
	applymovement 4, PetalburgWoods_Movement_22E1D0
	waitmovement 0
	applymovement 255, PetalburgWoods_Movement_2725A4
	waitmovement 0
	msgbox PetalburgWoods_Text_22E34F, 4
	closemessage
	playbgm BGM_AQA_0, 0
	applymovement 3, PetalburgWoods_Movement_22E209
	waitmovement 0
	msgbox PetalburgWoods_Text_22E3AA, 4
	closemessage
	applymovement 3, PetalburgWoods_Movement_22E205
	waitmovement 0
	applymovement 4, PetalburgWoods_Movement_2725A6
	waitmovement 0
	msgbox PetalburgWoods_Text_22E428, 4
	closemessage
	applymovement 4, PetalburgWoods_Movement_22E1EA
	waitmovement 0
	msgbox PetalburgWoods_Text_22E457, 4
	applymovement 255, PetalburgWoods_Movement_2725A6
	waitmovement 0
	msgbox PetalburgWoods_Text_22E4A5, 4
	trainerbattle 3, TRAINER_GRUNT_8, 0, PetalburgWoods_Text_22E542
	applymovement 3, PetalburgWoods_Movement_22E1F9
	waitmovement 0
	call PetalburgWoods_EventScript_22E138
	applymovement 255, PetalburgWoods_Movement_22E1E0
	applymovement 4, PetalburgWoods_Movement_22E1D7
	waitmovement 0
	goto PetalburgWoods_EventScript_22E1A7
	end

PetalburgWoods_EventScript_22E124:: @ 822E124
	applymovement 4, PetalburgWoods_Movement_22E1B1
	waitmovement 0
	msgbox PetalburgWoods_Text_22E332, 4
	closemessage
	return

PetalburgWoods_EventScript_22E138:: @ 822E138
	msgbox PetalburgWoods_Text_22E563, 4
	closemessage
	applymovement 3, PetalburgWoods_Movement_22E1FD
	waitmovement 0
	removeobject 3
	applymovement 255, PetalburgWoods_Movement_2725AA
	waitmovement 0
	msgbox PetalburgWoods_Text_22E63D, 4
	giveitem_std ITEM_GREAT_BALL
	compare VAR_RESULT, 0
	goto_eq PetalburgWoods_EventScript_22E17D
	goto PetalburgWoods_EventScript_22E18B
	end

PetalburgWoods_EventScript_22E17D:: @ 822E17D
	msgbox PetalburgWoods_Text_22E741, 4
	goto PetalburgWoods_EventScript_22E18B
	end

PetalburgWoods_EventScript_22E18B:: @ 822E18B
	msgbox PetalburgWoods_Text_22E6C7, 4
	applymovement 4, PetalburgWoods_Movement_22E1EE
	waitmovement 0
	msgbox PetalburgWoods_Text_22E712, 4
	closemessage
	return

PetalburgWoods_EventScript_22E1A7:: @ 822E1A7
	removeobject 4
	setvar VAR_0x4098, 1
	releaseall
	end

PetalburgWoods_Movement_22E1B1: @ 822E1B1
	step_01
	step_14
	step_12
	step_03
	step_14
	step_13
	step_02
	step_14
	step_13
	step_00
	step_14
	step_03
	step_14
	step_13
	step_01
	step_14
	step_end

PetalburgWoods_Movement_22E1C2: @ 822E1C2
	step_18
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

PetalburgWoods_Movement_22E1CB: @ 822E1CB
	step_14
	step_3e
	step_down
	step_down
	step_end

PetalburgWoods_Movement_22E1D0: @ 822E1D0
	step_14
	step_3e
	step_down
	step_down
	step_down
	step_28
	step_end

PetalburgWoods_Movement_22E1D7: @ 822E1D7
	step_17
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

PetalburgWoods_Movement_22E1E0: @ 822E1E0
	step_14
	step_14
	step_26
	step_end

PetalburgWoods_Movement_22E1E4: @ 822E1E4
	step_18
	step_15
	step_15
	step_17
	step_26
	step_end

PetalburgWoods_Movement_22E1EA: @ 822E1EA
	step_15
	step_18
	step_26
	step_end

PetalburgWoods_Movement_22E1EE: @ 822E1EE
	step_25
	step_14
	step_14
	step_14
	step_14
	step_14
	step_01
	step_end

PetalburgWoods_Movement_22E1F6: @ 822E1F6
	step_15
	step_15
	step_end

PetalburgWoods_Movement_22E1F9: @ 822E1F9
	step_40
	step_up
	step_41
	step_end

PetalburgWoods_Movement_22E1FD: @ 822E1FD
	step_16
	step_16
	step_16
	step_16
	step_16
	step_14
	step_14
	step_end

PetalburgWoods_Movement_22E205: @ 822E205
	step_15
	step_15
	step_15
	step_end

PetalburgWoods_Movement_22E209: @ 822E209
	step_down
	step_down
	step_14
	step_14
	step_end

PetalburgWoods_Movement_22E20E: @ 822E20E
	step_down
	step_end

PetalburgWoods_EventScript_22E210:: @ 822E210
	msgbox PetalburgWoods_Text_22EA0C, 2
	end

PetalburgWoods_EventScript_22E219:: @ 822E219
	msgbox PetalburgWoods_Text_22EA8B, 2
	end

PetalburgWoods_EventScript_22E222:: @ 822E222
	lock
	faceplayer
	checkflag FLAG_0x129
	goto_eq PetalburgWoods_EventScript_22E251
	msgbox PetalburgWoods_Text_22EAFE, 4
	giveitem_std ITEM_MIRACLE_SEED
	compare VAR_RESULT, 0
	goto_eq PetalburgWoods_EventScript_272054
	setflag FLAG_0x129
	release
	end

PetalburgWoods_EventScript_22E251:: @ 822E251
	msgbox PetalburgWoods_Text_22EB63, 4
	release
	end

PetalburgWoods_EventScript_22E25B:: @ 822E25B
	msgbox PetalburgWoods_Text_22EC10, 3
	end

PetalburgWoods_EventScript_22E264:: @ 822E264
	msgbox PetalburgWoods_Text_22ED07, 3
	end

PetalburgWoods_EventScript_22E26D:: @ 822E26D
	trainerbattle 0, TRAINER_LYLE, 0, PetalburgWoods_Text_22E77D, PetalburgWoods_Text_22E7C1
	msgbox PetalburgWoods_Text_22E7EF, 6
	end

PetalburgWoods_EventScript_22E284:: @ 822E284
	trainerbattle 2, TRAINER_JAMES_1, 0, PetalburgWoods_Text_22E827, PetalburgWoods_Text_22E86B, PetalburgWoods_EventScript_22E2C5
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq PetalburgWoods_EventScript_22E31B
	setvar VAR_0x8004, 621
	specialvar VAR_RESULT, sub_813B4E0
	compare VAR_RESULT, 0
	goto_eq PetalburgWoods_EventScript_22E2EF
	msgbox PetalburgWoods_Text_22E889, 4
	release
	end

PetalburgWoods_EventScript_22E2C5:: @ 822E2C5
	special sub_80B4808
	waitmovement 0
	checkflag FLAG_HAS_MATCH_CALL
	goto_eq PetalburgWoods_EventScript_22E2D6
	release
	end

PetalburgWoods_EventScript_22E2D6:: @ 822E2D6
	msgbox PetalburgWoods_Text_22E8C3, 4
	setvar VAR_0x8004, 621
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 621
	callstd 8
	release
	end

PetalburgWoods_EventScript_22E2EF:: @ 822E2EF
	checkflag FLAG_HAS_MATCH_CALL
	goto_eq PetalburgWoods_EventScript_22E302
	msgbox PetalburgWoods_Text_22E889, 4
	release
	end

PetalburgWoods_EventScript_22E302:: @ 822E302
	msgbox PetalburgWoods_Text_22E914, 4
	setvar VAR_0x8004, 621
	special sub_81D1C20
	setorcopyvar VAR_0x8000, 621
	callstd 8
	release
	end

PetalburgWoods_EventScript_22E31B:: @ 822E31B
	trainerbattle 5, TRAINER_JAMES_1, 0, PetalburgWoods_Text_22E966, PetalburgWoods_Text_22E998
	msgbox PetalburgWoods_Text_22E9B6, 6
	end

PetalburgWoods_Text_22E332: @ 822E332
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_22E34F: @ 822E34F
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"

PetalburgWoods_Text_22E3AA: @ 822E3AA
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in PETALBURG WOODS\l"
	.string "forever, didn’t you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_22E428: @ 822E428
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_22E457: @ 822E457
	.string "Aiyeeeh!\p"
	.string "You’re a POKéMON TRAINER, aren’t you?\n"
	.string "You’ve got to help me, please!$"

PetalburgWoods_Text_22E4A5: @ 822E4A5
	.string "Hunh? What do you think you’re doing?\n"
	.string "What, you’re going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_22E542: @ 822E542
	.string "You’re kidding me! You’re tough!$"

PetalburgWoods_Text_22E563: @ 822E563
	.string "Grrr… You’ve got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I’m out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I’ll let you go today!$"

PetalburgWoods_Text_22E63D: @ 822E63D
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn’t rob me of\n"
	.string "these important papers.\p"
	.string "I know, I’ll give you a GREAT BALL as\n"
	.string "my thanks!$"

PetalburgWoods_Text_22E6C7: @ 822E6C7
	.string "Didn’t that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"

PetalburgWoods_Text_22E712: @ 822E712
	.string "Uh-oh! It’s a crisis!\n"
	.string "I can’t be wasting time!$"

PetalburgWoods_Text_22E741: @ 822E741
	.string "You’re loaded with items.\n"
	.string "I can’t give you this GREAT BALL.$"

PetalburgWoods_Text_22E77D: @ 822E77D
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

PetalburgWoods_Text_22E7C1: @ 822E7C1
	.string "I have all these POKéMON,\n"
	.string "but I couldn’t win…$"

PetalburgWoods_Text_22E7EF: @ 822E7EF
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I’m out of POKé BALLS.$"

PetalburgWoods_Text_22E827: @ 822E827
	.string "If you take BUG POKéMON to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_22E86B: @ 822E86B
	.string "I can’t be popular if I lose.$"

PetalburgWoods_Text_22E889: @ 822E889
	.string "If you have a big BUG POKéMON,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_22E8C3: @ 822E8C3
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I’m registering you in my POKéNAV!$"

PetalburgWoods_Text_22E914: @ 822E914
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I’m registering you in my POKéNAV!$"

PetalburgWoods_Text_22E966: @ 822E966
	.string "My BUG POKéMON have grown.\n"
	.string "I’ll be popular again.$"

PetalburgWoods_Text_22E998: @ 822E998
	.string "I can’t be popular if I lose.$"

PetalburgWoods_Text_22E9B6: @ 822E9B6
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I’ve been training hard.$"

PetalburgWoods_Text_22EA0C: @ 822EA0C
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_22EA8B: @ 822EA8B
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can’t see them.\p"
	.string "That’s why I always check where I’m\n"
	.string "walking.$"

PetalburgWoods_Text_22EAFE: @ 822EAFE
	.string "Oh, neat!\n"
	.string "That’s the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_22EB63: @ 822EB63
	.string "It’s a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"

PetalburgWoods_Text_22EC10: @ 822EC10
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_22ED07: @ 822ED07
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), POKéMON\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a POKéMON runs out of PP, it must be\n"
	.string "taken to a POKéMON CENTER.$"

