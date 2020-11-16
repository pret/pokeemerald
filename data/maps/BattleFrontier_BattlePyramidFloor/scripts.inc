BattleFrontier_BattlePyramidFloor_MapScripts:: @ 8252A33
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame: @ 8252A43
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight:: @ 8252A5D
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop:: @ 8252A77
	special CallBattlePyramidFunction
	delay 2
	compare VAR_RESULT, 2
	goto_if_ne BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName:: @ 8252A8F
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic:: @ 8252A98
	playbgm MUS_B_PYRAMID, 0
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume: @ 8252AA2
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	compare VAR_RESULT, B_OUTCOME_DREW
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty:: @ 8252B39
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost:: @ 8252B42
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby:: @ 8252B66
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge:: @ 8252B8D
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition: @ 8252BCA
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius:: @ 8252BD5
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor:: @ 8252BE8
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	compare VAR_RESULT, 7
	goto_if_eq BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 255, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop:: @ 8252C45
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle:: @ 8252C4F
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall:: @ 8252C6A
	pyramid_setitem
	callstd STD_FIND_ITEM
	compare VAR_0x8007, 0
	goto_if_eq BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd:: @ 8252C87
	end

BattlePyramid_Retire:: @ 8252C88
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText: @ 8252C8D
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest:: @ 8252CA7
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"

gText_BattlePyramidConfirmRetire:: @ 8252CFB
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

BattlePyramid_Text_ExitHintUp1:: @ 8252D2D
	.string "This floor's exit is in\n"
	.string "that direction: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1:: @ 8252D57
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1:: @ 8252D81
	.string "This floor's exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1:: @ 8252DAB
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2:: @ 8252DD5
	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft2:: @ 8252E03
	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight2:: @ 8252E31
	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown2:: @ 8252E5F
	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_Text_ExitHintUp3:: @ 8252E8D
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

BattlePyramid_Text_ExitHintLeft3:: @ 8252EAA
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

BattlePyramid_Text_ExitHintRight3:: @ 8252EC7
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

BattlePyramid_Text_ExitHintDown3:: @ 8252EE4
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

BattlePyramid_Text_ExitHintUp4:: @ 8252F01
	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft4:: @ 8252F3A
	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight4:: @ 8252F73
	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown4:: @ 8252FAC
	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"

BattlePyramid_Text_ExitHintUp5:: @ 8252FE5
	.string "The exit?\n"
	.string "It's that {UP_ARROW} way.$"

BattlePyramid_Text_ExitHintLeft5:: @ 8253000
	.string "The exit?\n"
	.string "It's that {LEFT_ARROW} way.$"

BattlePyramid_Text_ExitHintRight5:: @ 825301B
	.string "The exit?\n"
	.string "It's that {RIGHT_ARROW} way.$"

BattlePyramid_Text_ExitHintDown5:: @ 8253036
	.string "The exit?\n"
	.string "It's that {DOWN_ARROW} way.$"

BattlePyramid_Text_ExitHintUp6:: @ 8253051
	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft6:: @ 825307C
	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight6:: @ 82530A7
	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown6:: @ 82530D2
	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_Text_EightItemsRemaining1:: @ 82530FD
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

BattlePyramid_Text_SevenItemsRemaining1:: @ 8253140
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

BattlePyramid_Text_SixItemsRemaining1:: @ 8253183
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

BattlePyramid_Text_FiveItemsRemaining1:: @ 82531C4
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

BattlePyramid_Text_FourItemsRemaining1:: @ 8253206
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

BattlePyramid_Text_ThreeItemsRemaining1:: @ 8253248
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

BattlePyramid_Text_TwoItemsRemaining1:: @ 825328B
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

BattlePyramid_Text_OneItemRemaining1:: @ 82532CC
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

BattlePyramid_Text_ZeroItemsRemaining1:: @ 825330B
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"

BattlePyramid_Text_EightItemsRemaining2:: @ 825334D
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattlePyramid_Text_SevenItemsRemaining2:: @ 82533A6
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

BattlePyramid_Text_SixItemsRemaining2:: @ 8253404
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FiveItemsRemaining2:: @ 8253460
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FourItemsRemaining2:: @ 82534BD
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

BattlePyramid_Text_ThreeItemsRemaining2:: @ 825351A
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

BattlePyramid_Text_TwoItemsRemaining2:: @ 8253578
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

BattlePyramid_Text_OneItemRemaining2:: @ 82535D4
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

BattlePyramid_Text_ZeroItemsRemaining2:: @ 825362E
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattlePyramid_Text_EightItemsRemaining3:: @ 825368B
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SevenItemsRemaining3:: @ 82536F8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SixItemsRemaining3:: @ 8253765
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FiveItemsRemaining3:: @ 82537D0
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FourItemsRemaining3:: @ 825383C
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining3:: @ 82538A8
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_TwoItemsRemaining3:: @ 8253915
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_OneItemRemaining3:: @ 8253980
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining3:: @ 82539EC
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

BattlePyramid_Text_EightItemsRemaining4:: @ 8253A69
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SevenItemsRemaining4:: @ 8253AC4
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SixItemsRemaining4:: @ 8253B1F
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FiveItemsRemaining4:: @ 8253B78
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FourItemsRemaining4:: @ 8253BD2
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

BattlePyramid_Text_ThreeItemsRemaining4:: @ 8253C2C
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

BattlePyramid_Text_TwoItemsRemaining4:: @ 8253C87
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

BattlePyramid_Text_OneItemRemaining4:: @ 8253CE0
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

BattlePyramid_Text_ZeroItemsRemaining4:: @ 8253D3E
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"

BattlePyramid_Text_EightItemsRemaining5:: @ 8253D96
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"

BattlePyramid_Text_SevenItemsRemaining5:: @ 8253DD2
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"

BattlePyramid_Text_SixItemsRemaining5:: @ 8253E0E
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"

BattlePyramid_Text_FiveItemsRemaining5:: @ 8253E48
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"

BattlePyramid_Text_FourItemsRemaining5:: @ 8253E83
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"

BattlePyramid_Text_ThreeItemsRemaining5:: @ 8253EBE
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"

BattlePyramid_Text_TwoItemsRemaining5:: @ 8253EFA
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"

BattlePyramid_Text_OneItemRemaining5:: @ 8253F34
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"

BattlePyramid_Text_ZeroItemsRemaining5:: @ 8253F6C
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"

BattlePyramid_Text_EightItemsRemaining6:: @ 8253FA5
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenItemsRemaining6:: @ 8253FF7
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SixItemsRemaining6:: @ 8254049
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FiveItemsRemaining6:: @ 8254099
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FourItemsRemaining6:: @ 82540EA
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining6:: @ 825413B
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

BattlePyramid_Text_TwoItemsRemaining6:: @ 825418D
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

BattlePyramid_Text_OneItemRemaining6:: @ 82541DD
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining6:: @ 825422B
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining1:: @ 825427A
	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_SixTrainersRemaining1:: @ 82542CB
	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_FiveTrainersRemaining1:: @ 825431A
	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_FourTrainersRemaining1:: @ 825436A
	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_ThreeTrainersRemaining1:: @ 82543BA
	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_TwoTrainersRemaining1:: @ 825440B
	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_OneTrainersRemaining1:: @ 825445A
	.string "You were really awesome!\p"
	.string "But there's still one tough\n"
	.string "TRAINER other than me!$"

BattlePyramid_Text_ZeroTrainersRemaining1:: @ 82544A6
	.string "You were really awesome!\p"
	.string "There's no one left that\n"
	.string "can beat you!$"

BattlePyramid_Text_SevenTrainersRemaining2:: @ 82544E6
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_SixTrainersRemaining2:: @ 8254538
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FiveTrainersRemaining2:: @ 8254588
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FourTrainersRemaining2:: @ 82545D9
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_ThreeTrainersRemaining2:: @ 825462A
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_TwoTrainersRemaining2:: @ 825467C
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_OneTrainersRemaining2:: @ 82546CC
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattlePyramid_Text_ZeroTrainersRemaining2:: @ 825471E
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattlePyramid_Text_SevenTrainersRemaining3:: @ 8254767
	.string "That's pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_SixTrainersRemaining3:: @ 82547C9
	.string "That's pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_FiveTrainersRemaining3:: @ 8254829
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_FourTrainersRemaining3:: @ 825488A
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_ThreeTrainersRemaining3:: @ 82548EB
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_TwoTrainersRemaining3:: @ 825494D
	.string "That's pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"

BattlePyramid_Text_OneTrainersRemaining3:: @ 82549AE
	.string "That's pretty impressive!\p"
	.string "But there's still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"

BattlePyramid_Text_ZeroTrainersRemaining3:: @ 8254A0B
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining4:: @ 8254A59
	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"

BattlePyramid_Text_SixTrainersRemaining4:: @ 8254A9E
	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"

BattlePyramid_Text_FiveTrainersRemaining4:: @ 8254AE1
	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"

BattlePyramid_Text_FourTrainersRemaining4:: @ 8254B25
	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"

BattlePyramid_Text_ThreeTrainersRemaining4:: @ 8254B69
	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"

BattlePyramid_Text_TwoTrainersRemaining4:: @ 8254BAE
	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"

BattlePyramid_Text_OneTrainersRemaining4:: @ 8254BF1
	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"

BattlePyramid_Text_ZeroTrainersRemaining4:: @ 8254C3E
	.string "There isn't a single person left who\n"
	.string "can defeat you now…$"

BattlePyramid_Text_SevenTrainersRemaining5:: @ 8254C77
	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"

BattlePyramid_Text_SixTrainersRemaining5:: @ 8254CC0
	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"

BattlePyramid_Text_FiveTrainersRemaining5:: @ 8254D07
	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"

BattlePyramid_Text_FourTrainersRemaining5:: @ 8254D4F
	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"

BattlePyramid_Text_ThreeTrainersRemaining5:: @ 8254D97
	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"

BattlePyramid_Text_TwoTrainersRemaining5:: @ 8254DE0
	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"

BattlePyramid_Text_OneTrainersRemaining5:: @ 8254E27
	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"

BattlePyramid_Text_ZeroTrainersRemaining5:: @ 8254E6E
	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"

BattlePyramid_Text_SevenTrainersRemaining6:: @ 8254ED3
	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"

BattlePyramid_Text_SixTrainersRemaining6:: @ 8254F0E
	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"

BattlePyramid_Text_FiveTrainersRemaining6:: @ 8254F47
	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"

BattlePyramid_Text_FourTrainersRemaining6:: @ 8254F81
	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"

BattlePyramid_Text_ThreeTrainersRemaining6:: @ 8254FBB
	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"

BattlePyramid_Text_TwoTrainersRemaining6:: @ 8254FF6
	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"

BattlePyramid_Text_OneTrainersRemaining6:: @ 825502F
	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"

BattlePyramid_Text_ZeroTrainersRemaining6:: @ 8255068
	.string "There aren't any TRAINERS left that\n"
	.string "can take you on now…$"
