BattleFrontier_BattlePyramidEmptySquare_MapScripts:: @ 8252A33
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA
	.byte 0

BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43: @ 8252A43
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F
	.2byte 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D:: @ 8252A5D
	lockall
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	setvar VAR_0x8007, 55
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77:: @ 8252A77
	special CallBattlePyramidFunction
	delay 2
	compare VAR_RESULT, 2
	goto_if_ne BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77
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
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_FLOOR_PALETTE
	special CallBattlePyramidFunction
	frontier_getstatus
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, B_OUTCOME_DREW
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39:: @ 8252B39
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
	special CallBattlePyramidFunction
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42:: @ 8252B42
BattleFrontier_BattlePyramidTop_EventScript_252B42:: @ 8252B42
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 255
	special CallBattlePyramidFunction

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66:: @ 8252B66
BattleFrontier_BattlePyramidTop_EventScript_252B66:: @ 8252B66
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D:: @ 8252B8D
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 1
	special CallBattlePyramidFunction
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_TRAINERS
	special CallBattlePyramidFunction
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA: @ 8252BCA
	call BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5:: @ 8252BD5
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 32
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	return

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BE8:: @ 8252BE8
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	compare VAR_RESULT, 7
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SEED_FLOOR
	special CallBattlePyramidFunction
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45:: @ 8252C45
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle:: @ 8252C4F
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SHOW_HINT_TEXT
	special CallBattlePyramidFunction
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall:: @ 8252C6A
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_ITEM
	special CallBattlePyramidFunction
	callstd STD_FIND_ITEM
	compare VAR_0x8007, 0
	goto_if_eq BattlePyramid_FindItemBall_End
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_HIDE_ITEM
	special CallBattlePyramidFunction

BattlePyramid_FindItemBall_End:: @ 8252C87
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88:: @ 8252C88
	goto BattleFrontier_BattlePyramidTop_EventScript_252B42

BattleFacility_TrainerBattle_PlaceholderText: @ 8252C8D
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest:: @ 8252CA7
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"

gText_BattlePyramidConfirmRetire:: @ 8252CFB
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

BattlePyramid_ExitHintUp_Text1:: @ 8252D2D
	.string "This floor's exit is in\n"
	.string "that direction: {UP_ARROW}$"

BattlePyramid_ExitHintLeft_Text1:: @ 8252D57
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

BattlePyramid_ExitHintRight_Text1:: @ 8252D81
	.string "This floor's exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"

BattlePyramid_ExitHintDown_Text1:: @ 8252DAB
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

BattlePyramid_ExitHintUp_Text2:: @ 8252DD5
	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_ExitHintLeft_Text2:: @ 8252E03
	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_ExitHintRight_Text2:: @ 8252E31
	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_ExitHintDown_Text2:: @ 8252E5F
	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_ExitHintUp_Text3:: @ 8252E8D
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

BattlePyramid_ExitHintLeft_Text3:: @ 8252EAA
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

BattlePyramid_ExitHintRight_Text3:: @ 8252EC7
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

BattlePyramid_ExitHintDown_Text3:: @ 8252EE4
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

BattlePyramid_ExitHintUp_Text4:: @ 8252F01
	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"

BattlePyramid_ExitHintLeft_Text4:: @ 8252F3A
	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"

BattlePyramid_ExitHintRight_Text4:: @ 8252F73
	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"

BattlePyramid_ExitHintDown_Text4:: @ 8252FAC
	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"

BattlePyramid_ExitHintUp_Text5:: @ 8252FE5
	.string "The exit?\n"
	.string "It's that {UP_ARROW} way.$"

BattlePyramid_ExitHintLeft_Text5:: @ 8253000
	.string "The exit?\n"
	.string "It's that {LEFT_ARROW} way.$"

BattlePyramid_ExitHintRight_Text5:: @ 825301B
	.string "The exit?\n"
	.string "It's that {RIGHT_ARROW} way.$"

BattlePyramid_ExitHintDown_Text5:: @ 8253036
	.string "The exit?\n"
	.string "It's that {DOWN_ARROW} way.$"

BattlePyramid_ExitHintUp_Text6:: @ 8253051
	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_ExitHintLeft_Text6:: @ 825307C
	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_ExitHintRight_Text6:: @ 82530A7
	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_ExitHintDown_Text6:: @ 82530D2
	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_EightItemsRemaining_Text1:: @ 82530FD
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

BattlePyramid_SevenItemsRemaining_Text1:: @ 8253140
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

BattlePyramid_SixItemsRemaining_Text1:: @ 8253183
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

BattlePyramid_FiveItemsRemaining_Text1:: @ 82531C4
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

BattlePyramid_FourItemsRemaining_Text1:: @ 8253206
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

BattlePyramid_ThreeItemsRemaining_Text1:: @ 8253248
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

BattlePyramid_TwoItemsRemaining_Text1:: @ 825328B
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

BattlePyramid_OneItemRemaining_Text1:: @ 82532CC
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

BattlePyramid_ZeroItemsRemaining_Text1:: @ 825330B
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"

BattlePyramid_EightItemsRemaining_Text2:: @ 825334D
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattlePyramid_SevenItemsRemaining_Text2:: @ 82533A6
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

BattlePyramid_SixItemsRemaining_Text2:: @ 8253404
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

BattlePyramid_FiveItemsRemaining_Text2:: @ 8253460
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

BattlePyramid_FourItemsRemaining_Text2:: @ 82534BD
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

BattlePyramid_ThreeItemsRemaining_Text2:: @ 825351A
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

BattlePyramid_TwoItemsRemaining_Text2:: @ 8253578
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

BattlePyramid_OneItemRemaining_Text2:: @ 82535D4
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

BattlePyramid_ZeroItemsRemaining_Text2:: @ 825362E
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattlePyramid_EightItemsRemaining_Text3:: @ 825368B
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_SevenItemsRemaining_Text3:: @ 82536F8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_SixItemsRemaining_Text3:: @ 8253765
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_FiveItemsRemaining_Text3:: @ 82537D0
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_FourItemsRemaining_Text3:: @ 825383C
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_ThreeItemsRemaining_Text3:: @ 82538A8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_TwoItemsRemaining_Text3:: @ 8253915
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_OneItemRemaining_Text3:: @ 8253980
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_ZeroItemsRemaining_Text3:: @ 82539EC
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

BattlePyramid_EightItemsRemaining_Text4:: @ 8253A69
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

BattlePyramid_SevenItemsRemaining_Text4:: @ 8253AC4
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

BattlePyramid_SixItemsRemaining_Text4:: @ 8253B1F
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

BattlePyramid_FiveItemsRemaining_Text4:: @ 8253B78
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

BattlePyramid_FourItemsRemaining_Text4:: @ 8253BD2
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

BattlePyramid_ThreeItemsRemaining_Text4:: @ 8253C2C
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

BattlePyramid_TwoItemsRemaining_Text4:: @ 8253C87
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

BattlePyramid_OneItemRemaining_Text4:: @ 8253CE0
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

BattlePyramid_ZeroItemsRemaining_Text4:: @ 8253D3E
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"

BattlePyramid_EightItemsRemaining_Text5:: @ 8253D96
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"

BattlePyramid_SevenItemsRemaining_Text5:: @ 8253DD2
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"

BattlePyramid_SixItemsRemaining_Text5:: @ 8253E0E
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"

BattlePyramid_FiveItemsRemaining_Text5:: @ 8253E48
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"

BattlePyramid_FourItemsRemaining_Text5:: @ 8253E83
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"

BattlePyramid_ThreeItemsRemaining_Text5:: @ 8253EBE
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"

BattlePyramid_TwoItemsRemaining_Text5:: @ 8253EFA
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"

BattlePyramid_OneItemRemaining_Text5:: @ 8253F34
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"

BattlePyramid_ZeroItemsRemaining_Text5:: @ 8253F6C
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"

BattlePyramid_EightItemsRemaining_Text6:: @ 8253FA5
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattlePyramid_SevenItemsRemaining_Text6:: @ 8253FF7
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

BattlePyramid_SixItemsRemaining_Text6:: @ 8254049
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

BattlePyramid_FiveItemsRemaining_Text6:: @ 8254099
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

BattlePyramid_FourItemsRemaining_Text6:: @ 82540EA
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

BattlePyramid_ThreeItemsRemaining_Text6:: @ 825413B
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

BattlePyramid_TwoItemsRemaining_Text6:: @ 825418D
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

BattlePyramid_OneItemRemaining_Text6:: @ 82541DD
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

BattlePyramid_ZeroItemsRemaining_Text6:: @ 825422B
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

BattlePyramid_SevenTrainersRemaining_Text1:: @ 825427A
	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_SixTrainersRemaining_Text1:: @ 82542CB
	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_FiveTrainersRemaining_Text1:: @ 825431A
	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_FourTrainersRemaining_Text1:: @ 825436A
	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_ThreeTrainersRemaining_Text1:: @ 82543BA
	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_TwoTrainersRemaining_Text1:: @ 825440B
	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_OneTrainersRemaining_Text1:: @ 825445A
	.string "You were really awesome!\p"
	.string "But there's still one tough\n"
	.string "TRAINER other than me!$"

BattlePyramid_ZeroTrainersRemaining_Text1:: @ 82544A6
	.string "You were really awesome!\p"
	.string "There's no one left that\n"
	.string "can beat you!$"

BattlePyramid_SevenTrainersRemaining_Text2:: @ 82544E6
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_SixTrainersRemaining_Text2:: @ 8254538
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_FiveTrainersRemaining_Text2:: @ 8254588
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_FourTrainersRemaining_Text2:: @ 82545D9
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_ThreeTrainersRemaining_Text2:: @ 825462A
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_TwoTrainersRemaining_Text2:: @ 825467C
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_OneTrainersRemaining_Text2:: @ 82546CC
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattlePyramid_ZeroTrainersRemaining_Text2:: @ 825471E
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattlePyramid_SevenTrainersRemaining_Text3:: @ 8254767
	.string "That's pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_SixTrainersRemaining_Text3:: @ 82547C9
	.string "That's pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_FiveTrainersRemaining_Text3:: @ 8254829
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_FourTrainersRemaining_Text3:: @ 825488A
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_ThreeTrainersRemaining_Text3:: @ 82548EB
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_TwoTrainersRemaining_Text3:: @ 825494D
	.string "That's pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"

BattlePyramid_OneTrainersRemaining_Text3:: @ 82549AE
	.string "That's pretty impressive!\p"
	.string "But there's still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"

BattlePyramid_ZeroTrainersRemaining_Text3:: @ 8254A0B
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"

BattlePyramid_SevenTrainersRemaining_Text4:: @ 8254A59
	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"

BattlePyramid_SixTrainersRemaining_Text4:: @ 8254A9E
	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"

BattlePyramid_FiveTrainersRemaining_Text4:: @ 8254AE1
	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"

BattlePyramid_FourTrainersRemaining_Text4:: @ 8254B25
	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"

BattlePyramid_ThreeTrainersRemaining_Text4:: @ 8254B69
	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"

BattlePyramid_TwoTrainersRemaining_Text4:: @ 8254BAE
	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"

BattlePyramid_OneTrainersRemaining_Text4:: @ 8254BF1
	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"

BattlePyramid_ZeroTrainersRemaining_Text4:: @ 8254C3E
	.string "There isn't a single person left who\n"
	.string "can defeat you now…$"

BattlePyramid_SevenTrainersRemaining_Text5:: @ 8254C77
	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"

BattlePyramid_SixTrainersRemaining_Text5:: @ 8254CC0
	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"

BattlePyramid_FiveTrainersRemaining_Text5:: @ 8254D07
	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"

BattlePyramid_FourTrainersRemaining_Text5:: @ 8254D4F
	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"

BattlePyramid_ThreeTrainersRemaining_Text5:: @ 8254D97
	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"

BattlePyramid_TwoTrainersRemaining_Text5:: @ 8254DE0
	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"

BattlePyramid_OneTrainersRemaining_Text5:: @ 8254E27
	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"

BattlePyramid_ZeroTrainersRemaining_Text5:: @ 8254E6E
	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"

BattlePyramid_SevenTrainersRemaining_Text6:: @ 8254ED3
	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"

BattlePyramid_SixTrainersRemaining_Text6:: @ 8254F0E
	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"

BattlePyramid_FiveTrainersRemaining_Text6:: @ 8254F47
	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"

BattlePyramid_FourTrainersRemaining_Text6:: @ 8254F81
	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"

BattlePyramid_ThreeTrainersRemaining_Text6:: @ 8254FBB
	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"

BattlePyramid_TwoTrainersRemaining_Text6:: @ 8254FF6
	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"

BattlePyramid_OneTrainersRemaining_Text6:: @ 825502F
	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"

BattlePyramid_ZeroTrainersRemaining_Text6:: @ 8255068
	.string "There aren't any TRAINERS left that\n"
	.string "can take you on now…$"
