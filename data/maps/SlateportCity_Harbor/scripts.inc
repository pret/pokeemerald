.set LOCALID_CAPT_STERN, 4
.set LOCALID_SS_TIDAL, 5
.set LOCALID_GRUNT, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_SUBMARINE, 8

SlateportCity_Harbor_MapScripts:: @ 820C97D
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition: @ 820C983
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
	setvar VAR_TEMP_1, 0
	compare VAR_SLATEPORT_HARBOR_STATE, 1
	call_if_eq SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal:: @ 820C9A5
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene:: @ 820C9A9
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0:: @ 820C9BB
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1:: @ 820C9C7
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2:: @ 820C9D3
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3:: @ 820C9DF
	lockall
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene:: @ 820C9F5
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_GRUNT
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILCOVE_MOTEL_SCOTT
	compare VAR_0x8008, 0
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer
	compare VAR_0x8008, 3
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_CAPT_STERN
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0:: @ 820CA89
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1:: @ 820CA9E
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer:: @ 820CAB3
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub: @ 820CAC8
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub: @ 820CACD
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit: @ 820CAD2
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0: @ 820CAE0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1: @ 820CAE6
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer: @ 820CAEB
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp: @ 820CAEF
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant:: @ 820CAF1
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket:: @ 820CB06
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination:: @ 820CB1A
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier:: @ 820CB50
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket:: @ 820CB88
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove:: @ 820CB92
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier:: @ 820CBBA
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination:: @ 820CBDD
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry:: @ 820CBE9
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	compare VAR_FACING, DIR_NORTH
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect:: @ 820CC2D
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast:: @ 820CC37
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth:: @ 820CC42
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast: @ 820CC4D
	walk_right
	walk_in_place_fastest_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth: @ 820CC50
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor:: @ 820CC52
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	compare VAR_0x8004, 2  @ Defeated both
	goto_if_eq SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather:: @ 820CC89
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary:: @ 820CC93
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan:: @ 820CC99
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern:: @ 820CCA2
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	compare VAR_SLATEPORT_HARBOR_STATE, 2
	goto_if_eq SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine:: @ 820CCDF
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive:: @ 820CCE9
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive:: @ 820CCF6
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment:: @ 820CD00
	compare VAR_TEMP_1, 1
	goto_if_eq SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished:: @ 820CD2E
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner:: @ 820CD38
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade:: @ 820CD44
	multichoice 0, 0, MULTI_STERN_DEEPSEA, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth:: @ 820CD7B
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale:: @ 820CDBB
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade:: @ 820CDFB
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade:: @ 820CE05
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner:: @ 820CE11
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable: @ 820CE20
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

SlateportCity_Harbor_Text_MayISeeYourTicket: @ 820CE87
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

SlateportCity_Harbor_Text_YouMustHaveTicket: @ 820CEC1
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo: @ 820CF1C
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

SlateportCity_Harbor_Text_SailAnotherTime: @ 820CF71
	.string "Please sail with us another time!$"

SlateportCity_Harbor_Text_LilycoveItIs: @ 820CF93
	.string "LILYCOVE CITY it is, then!$"

SlateportCity_Harbor_Text_BattleFrontierItIs: @ 820CFAE
	.string "BATTLE FRONTIER it is, then!$"

SlateportCity_Harbor_Text_PleaseBoardFerry: @ 820CFCB
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo: @ 820CFFA
	.string "Then, where would you like to go?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday: @ 820D01C
	.string "A journey to the bottom of the sea…\n"
	.string "I wonder what it'd be like?\p"
	.string "I'd love to go deep underwater like\n"
	.string "that someday.$"

SlateportCity_Harbor_Text_AbnormalWeather: @ 820D08E
	.string "For a ship to sail safely, we need to\n"
	.string "know about the weather!\p"
	.string "Speaking of weather, I heard something\n"
	.string "from a guy at the WEATHER INSTITUTE.\p"
	.string "He was saying abnormal weather has\n"
	.string "been reported all over the place!\p"
	.string "You should visit the WEATHER INSTITUTE\n"
	.string "and ask around!$"

SlateportCity_Harbor_Text_SubTooSmallForMe: @ 820D194
	.string "I wanted to go with CAPT. STERN on\n"
	.string "the ocean floor exploration.\p"
	.string "But the sub's too small for me.\p"
	.string "If I squeezed in, there wouldn't be\n"
	.string "any room for the CAPTAIN…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum: @ 820D232
	.string "CAPT. STERN: Those thugs…\p"
	.string "They're the same lot who tried to rob\n"
	.string "the DEVON GOODS at the MUSEUM.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove: @ 820D291
	.string "ARCHIE: Oh?\n"
	.string "Not you again…\p"
	.string "You are tenacious to track us here,\n"
	.string "that much I will give you.\p"
	.string "But now…\n"
	.string "No one can stop us! No one!\p"
	.string "Or, will you follow us back to our\n"
	.string "HIDEOUT in LILYCOVE CITY?\p"
	.string "Fwahahahaha…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine: @ 820D35A
	.string "CAPT. STERN: Why…\p"
	.string "Why would TEAM AQUA steal my\n"
	.string "SUBMARINE EXPLORER 1?\p"
	.string "They can't be after the slumbering\n"
	.string "POKéMON at the bottom of the sea…\p"
	.string "But even if I were to chase them,\n"
	.string "I don't stand a chance against them…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive: @ 820D42B
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
	.string "Okay… So TEAM AQUA left before you\n"
	.string "could stop them…\p"
	.string "Oh, no, don't blame yourself.\n"
	.string "You're not responsible for this.\p"
	.string "Trying to catch a submarine…\n"
	.string "It's impossible for most people.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub: @ 820D58A
	.string "CAPT. STERN: Trying to catch a\n"
	.string "submarine… It's impossible.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry: @ 820D65C
	.string "CAPT. STERN: Oh, yes.\n"
	.string "MR. BRINEY came to our SHIPYARD.\p"
	.string "It won't be long now before we finish\n"
	.string "making the ferry!$"

SlateportCity_Harbor_Text_FinishedMakingFerry: @ 820D6CB
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
	.string "We finally finished making the ferry\n"
	.string "S.S. TIDAL!\p"
	.string "We couldn't have done it without\n"
	.string "your friend MR. BRINEY.\p"
	.string "Please go for a short cruise on it!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner: @ 820D76C
	.string "CAPT. STERN: Oh?\n"
	.string "{PLAYER}{KUN}, that item you have…\p"
	.string "That's a SCANNER! That would sure\n"
	.string "help us on our explorations.\p"
	.string "{PLAYER}{KUN}, would you trade your\n"
	.string "SCANNER for something?\p"
	.string "Like, say, a DEEPSEATOOTH or\n"
	.string "a DEEPSEASCALE that I have?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow: @ 820D841
	.string "CAPT. STERN: Are you certain?\n"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
	.string "Well, okay, then. If you want to trade\n"
	.string "your SCANNER, let me know.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth: @ 820D8BC
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEATOOTH?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale: @ 820D8F1
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEASCALE?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant: @ 820D926
	.string "CAPT. STERN: Which one do you want?$"

SlateportCity_Harbor_Text_HandedScannerToStern: @ 820D94A
	.string "{PLAYER} handed the SCANNER to\n"
	.string "CAPT. STERN.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch: @ 820D970
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
	.string "This will help our research a lot!$"
