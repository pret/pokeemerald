CeladonCity_GameCorner_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CeladonCity_GameCorner_OnLoad
	.byte 0

CeladonCity_GameCorner_OnLoad::
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_HideRocketHideout
	end

CeladonCity_GameCorner_EventScript_HideRocketHideout::
	setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	return

CeladonCity_GameCorner_EventScript_InfoClerk::
	msgbox CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	showmoneybox 0, 0
	showcoinsbox 0, 5
	message CeladonCity_GameCorner_Text_WelcomeBuySomeCoins
	waitmessage
	multichoice 13, 0, MULTI_GAME_CORNER_COIN_PURCHASE_COUNTER, FALSE
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_EventScript_BuyCoins
	case 1, CeladonCity_GameCorner_EventScript_BuyCoins
	case 2, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
	case 127, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
	end

CeladonCity_GameCorner_EventScript_BuyCoins::
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_ClerkNoCoinCase
	goto_if_eq VAR_0x8009, 0, CeladonCity_GameCorner_EventScript_Buy50Coins
	goto_if_eq VAR_0x8009, 1, CeladonCity_GameCorner_EventScript_Buy500Coins
	end

CeladonCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 500, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
	addcoins 500
	removemoney 10000
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
	end

CeladonCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 50, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
	addcoins 50
	removemoney 1000
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
	end

CeladonCity_GameCorner_EventScript_BoughtCoins::
	updatemoneybox
	updatecoinsbox
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_HereAreYourCoins
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end

CeladonCity_GameCorner_EventScript_ClerkEnd::
	hidemoneybox
	hidecoinsbox
	release
	end

CeladonCity_GameCorner_EventScript_ClerkDeclineBuy::
	msgbox CeladonCity_GameCorner_Text_ComePlaySometime
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end

CeladonCity_GameCorner_EventScript_ClerkNoCoinCase::
	msgbox CeladonCity_GameCorner_Text_SorryDontHaveCoinCase
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end

CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins::
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsFull
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end

CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney::
	msgbox CeladonCity_GameCorner_Text_CantAffordCoins
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end

CeladonCity_GameCorner_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_RumoredTeamRocketRunsThisPlace
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_FaceSlotMachine::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_GameCorner_EventScript_Woman1::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins
	msgbox CeladonCity_GameCorner_Text_DoYouWantToPlay
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 10, CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins
	addcoins 10
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_Text_Received10CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_10_COINS_FROM_GAMBLER
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins::
	msgbox CeladonCity_GameCorner_Text_DontNeedMyCoins
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_GamblerNoCoinCase::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_Text_DontHaveCoinCase
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins::
	msgbox CeladonCity_GameCorner_Text_WinsComeAndGo
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ERIKA, CeladonCity_GameCorner_EventScript_GymGuyPostVictory
	msgbox CeladonCity_GameCorner_Text_GymGuyAdvice
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_GymGuyPostVictory::
	msgbox CeladonCity_GameCorner_Text_RareMonsForCoins
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_Woman2::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_SoEasyToGetHooked
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins
	msgbox CeladonCity_GameCorner_Text_WantSomeCoins
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 20, CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins
	addcoins 20
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_Text_Received20CoinsFromNiceGuy
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins::
	msgbox CeladonCity_GameCorner_Text_YouHaveLotsOfCoins
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins::
	msgbox CeladonCity_GameCorner_Text_NeedMoreCoinsForMonIWant
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER_2, CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins
	msgbox CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 20, CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins
	addcoins 20
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_Text_Received20CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER_2
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins::
	msgbox CeladonCity_GameCorner_Text_YouveGotPlentyCoins
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins::
	msgbox CeladonCity_GameCorner_Text_WatchReelsClosely
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine0::
	lockall
	setvar VAR_0x8004, 0
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_DontPlaySlotMachine::
	releaseall
	end

CeladonCity_GameCorner_EventScript_SlotMachine::
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase
	msgbox CeladonCity_GameCorner_Text_SlotMachineWantToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_DontPlaySlotMachine
	setfieldeffectargument 0, LOCALID_PLAYER
#ifdef BUGFIX
	setfieldeffectargument 1, MAP_NUM(MAP_CELADON_CITY_GAME_CORNER)
	setfieldeffectargument 2, MAP_GROUP(MAP_CELADON_CITY_GAME_CORNER)
#else
	@ Map num/group were provided in the wrong order
	setfieldeffectargument 1, MAP_GROUP(MAP_CELADON_CITY_GAME_CORNER)
	setfieldeffectargument 2, MAP_NUM(MAP_CELADON_CITY_GAME_CORNER)
#endif
	dofieldeffect FLDEFF_SMILEY_FACE_ICON
	waitfieldeffect FLDEFF_SMILEY_FACE_ICON
	specialvar VAR_RESULT, GetRandomSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

CeladonCity_GameCorner_EventScript_SlotMachine1::
	lockall
	setvar VAR_0x8004, 1
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine2::
	lockall
	setvar VAR_0x8004, 2
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine3::
	lockall
	setvar VAR_0x8004, 3
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine4::
	lockall
	setvar VAR_0x8004, 4
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine5::
	lockall
	setvar VAR_0x8004, 5
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine6::
	lockall
	setvar VAR_0x8004, 6
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine7::
	lockall
	setvar VAR_0x8004, 7
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine8::
	lockall
	setvar VAR_0x8004, 8
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine9::
	lockall
	setvar VAR_0x8004, 9
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine10::
	lockall
	setvar VAR_0x8004, 10
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine11::
	lockall
	setvar VAR_0x8004, 11
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine12::
	lockall
	setvar VAR_0x8004, 12
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine13::
	lockall
	setvar VAR_0x8004, 13
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine14::
	lockall
	setvar VAR_0x8004, 14
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine15::
	lockall
	setvar VAR_0x8004, 15
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine16::
	lockall
	setvar VAR_0x8004, 16
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine17::
	lockall
	setvar VAR_0x8004, 17
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine18::
	lockall
	setvar VAR_0x8004, 18
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine19::
	lockall
	setvar VAR_0x8004, 19
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine20::
	lockall
	setvar VAR_0x8004, 20
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachine21::
	lockall
	setvar VAR_0x8004, 21
	goto CeladonCity_GameCorner_EventScript_SlotMachine
	end

CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase::
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsRequired
	releaseall
	end

CeladonCity_GameCorner_EventScript_Poster::
	lockall
	msgbox CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_OpenRocketHideout
	releaseall
	end

CeladonCity_GameCorner_EventScript_OpenRocketHideout::
	playse SE_UNLOCK
	setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
	setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
	setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_stairsBottom, 1
	special DrawWholeMapView
	setflag FLAG_OPENED_ROCKET_HIDEOUT
	return

CeladonCity_GameCorner_EventScript_RocketGrunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, CeladonCity_GameCorner_Text_GruntIntro, CeladonCity_GameCorner_Text_GruntDefeat, CeladonCity_GameCorner_Text_DefeatedGrunt
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_GameCorner_Text_DefeatedGrunt::
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, CeladonCity_GameCorner_Text_GruntExitWest
	call_if_ne VAR_FACING, DIR_WEST, CeladonCity_GameCorner_Text_GruntExit
	removeobject LOCALID_GAME_CORNER_GRUNT
	release
	end

CeladonCity_GameCorner_Text_GruntExitWest::
	applymovement LOCALID_GAME_CORNER_GRUNT, CeladonCity_GameCorner_Movement_GruntExitWest
	waitmovement 0
	return

CeladonCity_GameCorner_Text_GruntExit::
	applymovement LOCALID_GAME_CORNER_GRUNT, CeladonCity_GameCorner_Movement_GruntExit
	waitmovement 0
	return

CeladonCity_GameCorner_Movement_GruntExitWest::
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_GameCorner_Movement_GruntExit::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
	msgbox CeladonCity_GameCorner_Text_OutOfOrder, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
	msgbox CeladonCity_GameCorner_Text_OutToLunch, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
	msgbox CeladonCity_GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
	end

CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor::
	.string "Welcome!\p"
	.string "You can exchange your COINS for\n"
	.string "fabulous prizes next door.$"

CeladonCity_GameCorner_Text_WelcomeBuySomeCoins::
	.string "Welcome to ROCKET GAME CORNER!\p"
	.string "Do you need some game COINS?\n"
	.string "Would you like to buy some?$"

CeladonCity_GameCorner_Text_ComePlaySometime::
	.string "No?\n"
	.string "Please come play sometime!$"

CeladonCity_GameCorner_Text_SorryDontHaveCoinCase::
	.string "Oh, I'm sorry.\n"
	.string "You don't have a COIN CASE.$"

CeladonCity_GameCorner_Text_CoinCaseIsFull::
	.string "Whoops!\n"
	.string "Your COIN CASE is full.$"

CeladonCity_GameCorner_Text_CantAffordCoins::
	.string "You can't afford the COINS.$"

CeladonCity_GameCorner_Text_HereAreYourCoins::
	.string "Thank you.\n"
	.string "Here are your COINS!$"

CeladonCity_GameCorner_Text_RumoredTeamRocketRunsThisPlace::
	.string "Keep this quiet.\p"
	.string "It's rumored that this place is run\n"
	.string "by TEAM ROCKET.$"

CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds::
	.string "I think these machines have\n"
	.string "different odds.$"

CeladonCity_GameCorner_Text_DoYouWantToPlay::
	.string "Kid, do you want to play?$"

CeladonCity_GameCorner_Text_Received10CoinsFromMan::
	.string "{PLAYER} received 10 COINS\n"
	.string "from the man.$"

CeladonCity_GameCorner_Text_DontNeedMyCoins::
	.string "You don't need my COINS!$"

CeladonCity_GameCorner_Text_WinsComeAndGo::
	.string "Wins seem to come and go.\n"
	.string "Nothing's a sure thing.$"

CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck::
	.string "These slot games…\n"
	.string "Win or lose, it's only by luck.$"

CeladonCity_GameCorner_Text_GymGuyAdvice::
	.string "Hey!\p"
	.string "You have better things to do,\n"
	.string "champ in the making!\p"
	.string "CELADON GYM's LEADER is ERIKA.\p"
	.string "She is a user of GRASS-type\n"
	.string "POKéMON, and at one with nature.\p"
	.string "She might appear docile because of\n"
	.string "her flower arranging…\p"
	.string "But she's not one to be taken\n"
	.string "lightly!$"

CeladonCity_GameCorner_Text_RareMonsForCoins::
	.string "They offer rare POKéMON that can\n"
	.string "be exchanged for your COINS.\p"
	.string "But, I just can't seem to win!$"

CeladonCity_GameCorner_Text_SoEasyToGetHooked::
	.string "Games are scary!\n"
	.string "It's so easy to get hooked!$"

CeladonCity_GameCorner_Text_WantSomeCoins::
	.string "What's up?\n"
	.string "Want some COINS?$"

CeladonCity_GameCorner_Text_Received20CoinsFromNiceGuy::
	.string "{PLAYER} received 20 COINS\n"
	.string "from the nice guy.$"

CeladonCity_GameCorner_Text_YouHaveLotsOfCoins::
	.string "You have lots of COINS!$"

CeladonCity_GameCorner_Text_NeedMoreCoinsForMonIWant::
	.string "Darn! I need more COINS for the\n"
	.string "POKéMON I want!$"

CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo::
	.string "Hey, what? You're throwing me off!\n"
	.string "Here are some COINS, so shoo!$"

CeladonCity_GameCorner_Text_Received20CoinsFromMan::
	.string "{PLAYER} received 20 COINS\n"
	.string "from the man.$"

CeladonCity_GameCorner_Text_YouveGotPlentyCoins::
	.string "You've got plenty of your own\n"
	.string "COINS!$"

CeladonCity_GameCorner_Text_WatchReelsClosely::
	.string "The trick is to watch the reels\n"
	.string "closely.$"

CeladonCity_GameCorner_Text_GruntIntro::
	.string "I'm guarding this poster!\n"
	.string "Go away, or else!$"

CeladonCity_GameCorner_Text_GruntDefeat::
	.string "Dang!$"

CeladonCity_GameCorner_Text_GruntPostBattle::
	.string "The TEAM ROCKET HIDEOUT might\n"
	.string "be discovered!\p"
	.string "I better tell BOSS!$"

CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt::
	.string "Hey!\p"
	.string "A switch behind the poster!?\n"
	.string "Let's push it!$"

CeladonCity_GameCorner_Text_CoinCaseIsRequired::
	.string "A COIN CASE is required…$"

CeladonCity_GameCorner_Text_DontHaveCoinCase::
	.string "Oops!\n"
	.string "Don't have the COIN CASE!$"

CeladonCity_GameCorner_Text_SlotMachineWantToPlay::
	.string "A slot machine!\n"
	.string "Want to play?$"

CeladonCity_GameCorner_Text_OutOfOrder::
	.string "OUT OF ORDER\n"
	.string "This is broken.$"

CeladonCity_GameCorner_Text_OutToLunch::
	.string "OUT TO LUNCH\n"
	.string "This is reserved.$"

CeladonCity_GameCorner_Text_SomeonesKeys::
	.string "Someone's keys!\n"
	.string "They'll be back.$"

