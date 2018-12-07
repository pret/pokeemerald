BattleFrontier_BattlePyramidEmptySquare_MapScripts:: @ 8252A33
	map_script 5, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2
	map_script 2, BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43
	map_script 3, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA
	.byte 0

BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43: @ 8252A43
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F
	.2byte 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D:: @ 8252A5D
	lockall
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	setvar VAR_0x8007, 55
	setvar VAR_RESULT, 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77:: @ 8252A77
	special CallBattlePyramidFunction
	delay 2
	compare VAR_RESULT, 2
	goto_if 5, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F:: @ 8252A8F
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98:: @ 8252A98
	playbgm MUS_PYRAMID, 0
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2: @ 8252AA2
	setvar VAR_0x8004, 15
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	case 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66
	case 2, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special CallFrontierUtilFunc
	compare VAR_RESULT, 4
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 5
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, 3
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, 9
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	special CallFrontierUtilFunc
	setvar VAR_TEMP_D, 1

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39:: @ 8252B39
	setvar VAR_0x8004, 17
	special CallBattlePyramidFunction
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42:: @ 8252B42
BattleFrontier_BattlePyramidTop_EventScript_252B42:: @ 8252B42
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 255
	special CallBattlePyramidFunction

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66:: @ 8252B66
BattleFrontier_BattlePyramidTop_EventScript_252B66:: @ 8252B66
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 14
	special CallBattlePyramidFunction
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D:: @ 8252B8D
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special CallBattlePyramidFunction
	special SavePlayerParty
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 9
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA: @ 8252BCA
	call BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5:: @ 8252BD5
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 32
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	return

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BE8:: @ 8252BE8
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_241EBA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	compare VAR_RESULT, 7
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45
	setvar VAR_0x8004, 6
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45:: @ 8252C45
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C4F:: @ 8252C4F
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D
	setvar VAR_0x8004, 10
	special CallBattlePyramidFunction
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C6A:: @ 8252C6A
	setvar VAR_0x8004, 7
	special CallBattlePyramidFunction
	callstd STD_FIND_ITEM
	compare VAR_0x8007, 0
	goto_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C87
	setvar VAR_0x8004, 8
	special CallBattlePyramidFunction

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C87:: @ 8252C87
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88:: @ 8252C88
	goto BattleFrontier_BattlePyramidTop_EventScript_252B42

BattleFrontier_BattlePyramidEmptySquare_Text_252C8D: @ 8252C8D
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest:: @ 8252CA7
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"

gText_BattlePyramidConfirmRetire:: @ 8252CFB
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

BattleFrontier_BattlePyramidEmptySquare_Text_252D2D:: @ 8252D2D
	.string "This floor's exit is in\n"
	.string "that direction: {UP_ARROW}$"

BattleFrontier_BattlePyramidEmptySquare_Text_252D57:: @ 8252D57
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

BattleFrontier_BattlePyramidEmptySquare_Text_252D81:: @ 8252D81
	.string "This floor's exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"

BattleFrontier_BattlePyramidEmptySquare_Text_252DAB:: @ 8252DAB
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

BattleFrontier_BattlePyramidEmptySquare_Text_252DD5:: @ 8252DD5
	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252E03:: @ 8252E03
	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252E31:: @ 8252E31
	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252E5F:: @ 8252E5F
	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252E8D:: @ 8252E8D
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252EAA:: @ 8252EAA
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252EC7:: @ 8252EC7
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252EE4:: @ 8252EE4
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252F01:: @ 8252F01
	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252F3A:: @ 8252F3A
	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252F73:: @ 8252F73
	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252FAC:: @ 8252FAC
	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_252FE5:: @ 8252FE5
	.string "The exit?\n"
	.string "It's that {UP_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253000:: @ 8253000
	.string "The exit?\n"
	.string "It's that {LEFT_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25301B:: @ 825301B
	.string "The exit?\n"
	.string "It's that {RIGHT_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253036:: @ 8253036
	.string "The exit?\n"
	.string "It's that {DOWN_ARROW} way.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253051:: @ 8253051
	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25307C:: @ 825307C
	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2530A7:: @ 82530A7
	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2530D2:: @ 82530D2
	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2530FD:: @ 82530FD
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253140:: @ 8253140
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253183:: @ 8253183
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2531C4:: @ 82531C4
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253206:: @ 8253206
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253248:: @ 8253248
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25328B:: @ 825328B
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2532CC:: @ 82532CC
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25330B:: @ 825330B
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25334D:: @ 825334D
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2533A6:: @ 82533A6
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253404:: @ 8253404
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253460:: @ 8253460
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2534BD:: @ 82534BD
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25351A:: @ 825351A
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253578:: @ 8253578
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2535D4:: @ 82535D4
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25362E:: @ 825362E
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25368B:: @ 825368B
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2536F8:: @ 82536F8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253765:: @ 8253765
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2537D0:: @ 82537D0
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25383C:: @ 825383C
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2538A8:: @ 82538A8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253915:: @ 8253915
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253980:: @ 8253980
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2539EC:: @ 82539EC
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

BattleFrontier_BattlePyramidEmptySquare_Text_253A69:: @ 8253A69
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253AC4:: @ 8253AC4
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253B1F:: @ 8253B1F
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253B78:: @ 8253B78
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253BD2:: @ 8253BD2
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253C2C:: @ 8253C2C
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253C87:: @ 8253C87
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253CE0:: @ 8253CE0
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253D3E:: @ 8253D3E
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253D96:: @ 8253D96
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253DD2:: @ 8253DD2
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253E0E:: @ 8253E0E
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253E48:: @ 8253E48
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253E83:: @ 8253E83
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253EBE:: @ 8253EBE
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253EFA:: @ 8253EFA
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253F34:: @ 8253F34
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253F6C:: @ 8253F6C
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"

BattleFrontier_BattlePyramidEmptySquare_Text_253FA5:: @ 8253FA5
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_253FF7:: @ 8253FF7
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254049:: @ 8254049
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254099:: @ 8254099
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2540EA:: @ 82540EA
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25413B:: @ 825413B
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25418D:: @ 825418D
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_2541DD:: @ 82541DD
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25422B:: @ 825422B
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_25427A:: @ 825427A
	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2542CB:: @ 82542CB
	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25431A:: @ 825431A
	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25436A:: @ 825436A
	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2543BA:: @ 82543BA
	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25440B:: @ 825440B
	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25445A:: @ 825445A
	.string "You were really awesome!\p"
	.string "But there's still one tough\n"
	.string "TRAINER other than me!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2544A6:: @ 82544A6
	.string "You were really awesome!\p"
	.string "There's no one left that\n"
	.string "can beat you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2544E6:: @ 82544E6
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_254538:: @ 8254538
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_254588:: @ 8254588
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2545D9:: @ 82545D9
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25462A:: @ 825462A
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25467C:: @ 825467C
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_2546CC:: @ 82546CC
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattleFrontier_BattlePyramidEmptySquare_Text_25471E:: @ 825471E
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattleFrontier_BattlePyramidEmptySquare_Text_254767:: @ 8254767
	.string "That's pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattleFrontier_BattlePyramidEmptySquare_Text_2547C9:: @ 82547C9
	.string "That's pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254829:: @ 8254829
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattleFrontier_BattlePyramidEmptySquare_Text_25488A:: @ 825488A
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattleFrontier_BattlePyramidEmptySquare_Text_2548EB:: @ 82548EB
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattleFrontier_BattlePyramidEmptySquare_Text_25494D:: @ 825494D
	.string "That's pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"

BattleFrontier_BattlePyramidEmptySquare_Text_2549AE:: @ 82549AE
	.string "That's pretty impressive!\p"
	.string "But there's still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254A0B:: @ 8254A0B
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254A59:: @ 8254A59
	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254A9E:: @ 8254A9E
	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254AE1:: @ 8254AE1
	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254B25:: @ 8254B25
	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254B69:: @ 8254B69
	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254BAE:: @ 8254BAE
	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254BF1:: @ 8254BF1
	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254C3E:: @ 8254C3E
	.string "There isn't a single person left who\n"
	.string "can defeat you now…$"

BattleFrontier_BattlePyramidEmptySquare_Text_254C77:: @ 8254C77
	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254CC0:: @ 8254CC0
	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254D07:: @ 8254D07
	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254D4F:: @ 8254D4F
	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254D97:: @ 8254D97
	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254DE0:: @ 8254DE0
	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254E27:: @ 8254E27
	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254E6E:: @ 8254E6E
	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"

BattleFrontier_BattlePyramidEmptySquare_Text_254ED3:: @ 8254ED3
	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254F0E:: @ 8254F0E
	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254F47:: @ 8254F47
	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254F81:: @ 8254F81
	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254FBB:: @ 8254FBB
	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_254FF6:: @ 8254FF6
	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"

BattleFrontier_BattlePyramidEmptySquare_Text_25502F:: @ 825502F
	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"

BattleFrontier_BattlePyramidEmptySquare_Text_255068:: @ 8255068
	.string "There aren't any TRAINERS left that\n"
	.string "can take you on now…$"
