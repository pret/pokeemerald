BattleFrontier_BattlePyramidEmptySquare_MapScripts:: @ 8252A33
	map_script 5, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2
	map_script 2, BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43
	map_script 3, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA
	.byte 0

BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43: @ 8252A43
	map_script_2 VAR_0x400D, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D
	map_script_2 VAR_0x400E, 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98
	map_script_2 VAR_0x400F, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F
	.2byte 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D:: @ 8252A5D
	lockall
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	setvar VAR_0x8007, 55
	setvar VAR_RESULT, 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77:: @ 8252A77
	special sub_81A8E7C
	delay 2
	compare_var_to_value VAR_RESULT, 2
	goto_if 5, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77
	setvar VAR_0x400D, 0
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F:: @ 8252A8F
	special AddMapNamePopUpWindowTask
	setvar VAR_0x400F, 0
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98:: @ 8252A98
	playbgm BGM_BATTLE_PYRAMID, 0
	setvar VAR_0x400E, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2: @ 8252AA2
	setvar VAR_0x8004, 15
	special sub_81A8E7C
	setvar VAR_0x8004, 0
	special sub_81A1780
	switch VAR_0x4000
	case 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	case 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66
	case 2, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 4
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 5
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare_var_to_value VAR_RESULT, 3
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare_var_to_value VAR_RESULT, 9
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	special sub_81A1780
	setvar VAR_0x400D, 1

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39:: @ 8252B39
	setvar VAR_0x8004, 17
	special sub_81A8E7C
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42:: @ 8252B42
BattleFrontier_BattlePyramidTop_EventScript_252B42:: @ 8252B42
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 255
	special sub_81A8E7C

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66:: @ 8252B66
BattleFrontier_BattlePyramidTop_EventScript_252B66:: @ 8252B66
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A8E7C
	setvar VAR_0x8004, 14
	special sub_81A8E7C
	special sp000_heal_pokemon
	warpsilent BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D:: @ 8252B8D
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special sub_81A8E7C
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x8004, 9
	special sub_81A8E7C
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	setvar VAR_0x400F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA: @ 8252BCA
	call BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5
	setvar VAR_0x400F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5:: @ 8252BD5
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 32
	setvar VAR_0x8006, 0
	special sub_81A8E7C
	return

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BE8:: @ 8252BE8
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_241EBA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	compare_var_to_value VAR_RESULT, 7
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45
	setvar VAR_0x8004, 6
	special sub_81A8E7C
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_RESULT, 0
	warp BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45:: @ 8252C45
	warp BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C4F:: @ 8252C4F
	trainerbattle 9, TRAINER_PHILLIP, 0, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D
	setvar VAR_0x8004, 10
	special sub_81A8E7C
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C6A:: @ 8252C6A
	setvar VAR_0x8004, 7
	special sub_81A8E7C
	callstd 1
	compare_var_to_value VAR_0x8007, 0
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C87
	setvar VAR_0x8004, 8
	special sub_81A8E7C

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C87:: @ 8252C87
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88:: @ 8252C88
	goto BattleFrontier_BattlePyramidTop_EventScript_252B42

BattleFrontier_BattlePyramidEmptySquare_Text_252C8D: @ 8252C8D
	.string "This is a sample message.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252CA7:: @ 8252CA7
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"

BattleFrontier_BattlePyramidEmptySquare_Text_252CFB:: @ 8252CFB
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

	.string "This floor’s exit is in\n"
	.string "that direction: {UP_ARROW}$"

	.string "This floor’s exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

	.string "This floor’s exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"

	.string "This floor’s exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"

	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"

	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"

	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"

	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"

	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"

	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"

	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"

	.string "The exit?\n"
	.string "It’s that {UP_ARROW} way.$"

	.string "The exit?\n"
	.string "It’s that {LEFT_ARROW} way.$"

	.string "The exit?\n"
	.string "It’s that {RIGHT_ARROW} way.$"

	.string "The exit?\n"
	.string "It’s that {DOWN_ARROW} way.$"

	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"

	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"

	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"

	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"

	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

	.string "Are you looking for items?\p"
	.string "There isn’t anything left to\n"
	.string "be found!$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

	.string "Because you won, I’ll tell you\n"
	.string "a little secret!\p"
	.string "There isn’t anything left\n"
	.string "lying around here.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there’s but one item left\n"
	.string "waiting to be found on this floor.$"

	.string "How’s your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

	.string "You’re strong, so you’ve earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"

	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"

	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"

	.string "You were really awesome!\p"
	.string "But there’s still one tough\n"
	.string "TRAINER other than me!$"

	.string "You were really awesome!\p"
	.string "There’s no one left that\n"
	.string "can beat you!$"

	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

	.string "This is so upsetting!\p"
	.string "But there’s one TRAINER left!\n"
	.string "I’m sure you will be humbled!$"

	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

	.string "That’s pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

	.string "That’s pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

	.string "That’s pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

	.string "That’s pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

	.string "That’s pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

	.string "That’s pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"

	.string "That’s pretty impressive!\p"
	.string "But there’s still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"

	.string "That’s pretty impressive!\p"
	.string "You’ve gone through all the TRAINERS\n"
	.string "on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"

	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"

	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"

	.string "There isn’t a single person left who\n"
	.string "can defeat you now…$"

	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"

	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"

	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"

	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"

	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"

	.string "There aren’t any TRAINERS left that\n"
	.string "can take you on now…$"

