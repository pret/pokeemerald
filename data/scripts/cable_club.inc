CableClub_MapScript_OnTransition: @ 8276ACF
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan:: @ 8276AD5
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_ShowMysteryGiftMan
	specialvar VAR_RESULT, ValidateReceivedWonderCard
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_HideMysteryGiftMan
	goto CableClub_EventScript_ShowMysteryGiftMan
	end

CableClub_EventScript_ShowMysteryGiftMan:: @ 8276AFB
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_HideMysteryGiftMan:: @ 8276AFF
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_MysteryGiftMan:: @ 8276B03
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_DistributeEonTicket
	goto CableClub_EventScript_AlreadyGotEonTicket
	end

CableClub_EventScript_AlreadyGotEonTicket:: @ 8276B19
	gotoram

@ Unused?
CableClub_EventScript_MysteryGiftThankYou:: @ 8276B1A
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_EventScript_DistributeEonTicket:: @ 8276B23
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_AlreadyGotEonTicket
	goto_if_set FLAG_SYS_HAS_EON_TICKET, CableClub_EventScript_AlreadyGotEonTicket
	msgbox Mevent_Text_TheresATicketForYou, MSGBOX_DEFAULT
	giveitem_std ITEM_EON_TICKET
	setflag FLAG_SYS_HAS_EON_TICKET
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox Mevent_Text_TryUsingItAtLilycovePort, MSGBOX_DEFAULT
	release
	end

@ Unused?
OldaleTown_PokemonCenter_2F_EventScript_276B62:: @ 8276B62
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
	release
	end

CableClub_MapScript2_OnWarp: @ 8276B6C
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

CableClub_EventScript_CheckTurnAttendant:: @ 8276BAE
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_DontTurnAttendant
	turnobject VAR_0x8007, DIR_WEST
CableClub_EventScript_DontTurnAttendant:: @ 8276BBD
	end

CableClub_MapScript1_OnLoad: @ 8276BBE
	compare VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
	compare VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	goto_if_eq CableClub_EventScript_OnLoadFromTradeCenter
	compare VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER
	goto_if_eq CableClub_EventScript_OnLoadFromRecordCorner
	compare VAR_CABLE_CLUB_STATE, USING_UNION_ROOM
	goto_if_eq CableClub_EventScript_OnLoadFromUnionRoom
	compare VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH
	goto_if_eq CableClub_EventScript_OnLoadFromBerryCrush
	compare VAR_CABLE_CLUB_STATE, USING_MINIGAME
	goto_if_eq CableClub_EventScript_OnLoadFromGameCorner
	end

CableClub_EventScript_OnLoadFromColosseum:: @ 8276C17
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromTradeCenter:: @ 8276C1D
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromRecordCorner:: @ 8276C23
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromUnionRoom:: @ 8276C29
	call CableClub_EventScript_OpenUnionRoomBarrier
	end

CableClub_EventScript_OnLoadFromBerryCrush:: @ 8276C2F
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromGameCorner:: @ 8276C35
	call EventScript_OpenMossdeepGameCornerBarrier
	end

CableClub_MapScript2_OnFrame: @ 8276C3B
	map_script_2 VAR_CABLE_CLUB_TUTORIAL_STATE, 1, CableClub_EventScript_Tutorial
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_ExitRecordCorner
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

CableClub_EventScript_ExitLinkRoom:: @ 8276C85
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom:: @ 8276C9D
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call EventScript_CloseMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom:: @ 8276CB5
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter:: @ 8276CE7
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter:: @ 8276CFF
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitRecordCorner:: @ 8276D2C
	lockall
	call CableClub_EventScript_PlayerExitRecordCorner
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitRecordCorner:: @ 8276D44
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_ExitRecordCornerRet
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
CableClub_EventScript_ExitRecordCornerRet:: @ 8276D6B
	return

CableClub_EventScript_ExitUnionRoom:: @ 8276D6C
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom:: @ 8276D84
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten:: @ 8276DAE
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	delay 60
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom:: @ 8276DD5
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial:: @ 8276DE0
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, CableClub_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime, MSGBOX_DEFAULT
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	releaseall
	end

CableClub_Movement_PlayerApproachCounter: @ 8276E10
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub:: @ 8276E13
	message CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 28
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub:: @ 8276E22
	msgbox CableClub_Text_WhichService, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom:: @ 8276E30
	setvar VAR_0x8004, 0
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_CableClubUnlockedRecordCorner
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_CableClubUnlockedRecordCorner:: @ 8276E75
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_RecordCorner
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum:: @ 8276EB7
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode:: @ 8276EC2
	message CableClub_Text_WhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo:: @ 8276F15
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode:: @ 8276F23
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode:: @ 8276F2E
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle:: @ 8276F47
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode:: @ 8276F55
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum:: @ 8276F60
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterColosseum
	compare VAR_RESULT, 2
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, 3
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, 4
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, 6
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum:: @ 8276FBD
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	compare VAR_0x8004, USING_MULTI_BATTLE
	goto_if_eq CableClub_EventScript_WarpToDoubleColosseum
	special SetCableClubWarp
	warp MAP_SINGLE_BATTLE_COLOSSEUM, 255, 6, 8
	special sub_80AF948
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight:: @ 827702B
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpToDoubleColosseum:: @ 8277036
	special SetCableClubWarp
	warp MAP_DOUBLE_BATTLE_COLOSSEUM, 255, 5, 8
	special sub_80AF948
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers:: @ 8277046
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE,  CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers:: @ 8277072
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle:: @ 8277083
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle:: @ 8277094
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart:: @ 82770A5
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_TradeCenter:: @ 82770B2
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterTradeCenter
	compare VAR_RESULT, 2
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, 3
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, 4
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, 6
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	compare VAR_RESULT, 7
	goto_if_eq CableClub_EventScript_AbortLinkPlayerNotReady
	compare VAR_RESULT, 9
	goto_if_eq CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter:: @ 827713A
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 255, 5, 8
	special sub_80AF948
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements:: @ 8277199
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 2
	goto_if_lt CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsToTrade:: @ 82771BF
	msgbox CableClub_Text_NeedTwoMonsToTrade, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_CantTradeEnigmaBerry:: @ 82771CD
	msgbox CableClub_Text_CantTradeEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_RecordCorner:: @ 82771DB
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special sub_80B2E74
	waitstate
	special sub_80B2EA8
	waitstate
	compare VAR_RESULT, 12
	goto_if_eq CableClub_EventScript_AbortLinkForeignGame
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterRecordCorner
	compare VAR_RESULT, 2
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
	compare VAR_RESULT, 3
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
	compare VAR_RESULT, 4
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_AbortLink
	compare VAR_RESULT, 6
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterRecordCorner:: @ 827724C
	setvar VAR_0x8004, USING_RECORD_CORNER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_RECORD_CORNER, 255, 8, 9
	special sub_80AF948
	waitstate
	end

CableClub_EventScript_AbortLinkPlayerNotReady:: @ 82772AB
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady:: @ 82772B8
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkConnectionError:: @ 82772C5
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady:: @ 82772D2
	special CloseLink
	msgbox Text_SomeoneIsNotReadyToLink, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections:: @ 82772DF
	special CloseLink
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLink:: @ 82772EC
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_AbortMinigame:: @ 82772F9
	special CloseLink
	msgbox MossdeepCity_GameCorner_1F_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp:: @ 8277306
	special SetCableClubWarp
	special sub_80AF948
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants:: @ 827730E
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg:: @ 827731B
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkForeignGame:: @ 8277328
	special CloseLink
	msgbox CableClub_Text_CantMixWithJapaneseGame, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_WirelessClubAdjustements:: @ 8277335
	msgbox gText_SorryWirelessClubAdjustments, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_NotReadyYet:: @ 827733F
	msgbox gText_UndergoingAdjustments, MSGBOX_DEFAULT
	releaseall
	end

Movement_AttendantFaceDown: @ 8277349
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight: @ 827734B
	face_right
	step_end

Movement_AttendantFaceLeft: @ 827734D
	face_left
	step_end

Movement_PlayerExitLinkRoom: @ 827734F
	walk_down
	walk_down
	step_end

@ Functionally unused
Movement_PlayerApproachLinkRoomRight: @ 8277352
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft: @ 8277356
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom: @ 827735A
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft: @ 827735C
	face_left
	step_end

Movement_PlayerFaceAttendantRight: @ 827735E
	face_right
	step_end

Movement_PlayerEnterMinigameRoom: @ 8277360
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

EventScript_CableBoxResults:: @ 8277365
	lockall
	setvar VAR_0x8004, 0
	special ShowLinkBattleRecords
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

EventScript_SingleBattleColosseum_PlayerSpot0:: @ 8277374
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_SingleBattleColosseum_PlayerSpot1:: @ 827737E
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot0:: @ 8277388
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot1:: @ 82773A3
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot2:: @ 82773BE
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 2
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot3:: @ 82773D9
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 3
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_CancelSpotTrigger:: @ 82773F4
	end

EventScript_TradeCenter_Chair0:: @ 82773F5
	setvar VAR_0x8005, 0
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_TradeCenter_Chair1:: @ 82773FF
	setvar VAR_0x8005, 1
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair2:: @ 8277409
	setvar VAR_0x8005, 2
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair3:: @ 8277413
	setvar VAR_0x8005, 3
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_RecordCenter_Spot0:: @ 827741D
	setvar VAR_0x8005, 0
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot1:: @ 8277432
	setvar VAR_0x8005, 1
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot2:: @ 8277447
	setvar VAR_0x8005, 2
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot3:: @ 827745C
	setvar VAR_0x8005, 3
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

RecordCorner_EventScript_277471:: @ 8277471
	bufferitemname 1, VAR_TEMP_1
	message RecordCorner_Text_PlayerSentOverOneX
	waitmessage
	waitbuttonpress
	releaseall
	end

CableClub_EventScript_ReadTrainerCard:: @ 827747E
	msgbox CableClub_Text_GotToLookAtTrainerCard, MSGBOX_DEFAULT
	fadescreen 1
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored:: @ 827748D
	msgbox CableClub_Text_GotToLookAtColoredTrainerCard, MSGBOX_DEFAULT
	fadescreen 1
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice:: @ 827749C
	msgbox CableClub_Text_TooBusyToNotice, MSGBOX_DEFAULT
	closemessage
	end

SingleBattleColosseum_EventScript_Attendant:: @ 82774A6
	special Script_FacePlayer
	msgbox SingleBattleColosseum_Text_TakePlaceStartBattle, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant:: @ 82774B6
	special Script_FacePlayer
	msgbox TradeCenter_Text_TakeSeatStartTrade, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_2774C6:: @ 82774C6
	compare VAR_TEMP_0, 0
	goto_if_ne RecordCorner_EventScript_AlreadyMixed
	special Script_FacePlayer
	message RecordCorner_Text_TakeSeatAndWait
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_AlreadyMixed:: @ 82774E0
	special Script_FacePlayer
	message RecordCorner_Text_ThanksForComing
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

EventScript_ConfirmLeaveTradeRoom:: @ 82774EF
	msgbox Text_TerminateLinkConfirmation, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_TerminateLink
	erasebox 0, 0, 29, 19
	releaseall
	end

EventScript_TerminateLink:: @ 8277509
	messageautoscroll Text_TerminateLinkPleaseWait
	waitmessage
	special ExitLinkRoom
	end

EventScript_DoLinkRoomExit:: @ 8277513
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant:: @ 827751B
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 8
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_AbortLinkPlayerHasBadEgg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_UnionRoomAdapterNotConnected
	message CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_UnionRoomSelect:: @ 827755C
	multichoice 17, 6, MULTI_YESNOINFO, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo:: @ 8277593
	message CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_EnterUnionRoom:: @ 827759F
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	msgbox CableClub_Text_EnjoyUnionRoom, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpteleport2 MAP_UNION_ROOM, 255, 7, 11
	waitstate
	special UnionRoomSpecial
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements:: @ 8277626
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 2
	goto_if_lt CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom:: @ 827764C
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom:: @ 827765A
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_UnionRoomAdapterNotConnected:: @ 8277668
	msgbox CableClub_Text_UnionRoomAdapterNotConnected, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_WirelessClubAttendant:: @ 8277672
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_DontAskAboutLinking
	msgbox CableClub_Text_ExplainWirelessClub, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DontAskAboutLinking:: @ 827769A
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DirectCornerAttendant:: @ 82776A4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 9
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	compare VAR_RESULT, TRUE
	goto_if_eq CableClub_EventScript_AbortLinkPlayerHasBadEgg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_WelcomeToCableClub
	message CableClub_Text_WelcomeWhichDirectCornerRoom
	waitmessage
	delay 28
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_DirectCornerSelectService:: @ 82776E3
	checkitem ITEM_POWDER_JAR, 1
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_DirectCornerNoBerry
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerSelectAllServices
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessBerryCrush
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerSelectAllServices:: @ 827773E
	multichoice 0, 0, MULTI_WIRELESS_ALL_SERVICES, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_WirelessBerryCrush
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerNoBerry:: @ 827778B
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerHasRecordMix
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerHasRecordMix:: @ 82777CB
	multichoice 0, 0, MULTI_WIRELESS_NO_BERRY, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessTrade:: @ 827780D
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	call CableClub_EventScript_CheckPartyTradeRequirements
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	setvar VAR_0x8004, 3
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleSelect:: @ 827783B
	message CableClub_Text_WhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle
	case 1, CableClub_EventScript_WirelessDoubleBattle
	case 2, CableClub_EventScript_WirelessMultiBattle
	case 3, CableClub_EventScript_WirelessBattleInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessSingleBattle:: @ 827788E
	setvar VAR_0x8004, 0
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessDoubleBattle:: @ 8277899
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
	setvar VAR_0x8004, 1
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle:: @ 82778B2
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessMultiBattle:: @ 82778C0
	setvar VAR_0x8004, 2
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleInfo:: @ 82778CB
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessRecordMix:: @ 82778D9
	msgbox CableClub_Text_AccessRecordCorner, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	setvar VAR_0x8004, 12
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBerryCrush:: @ 82778F7
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	special HasAtLeastOneBerry
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_NeedBerryForBerryCrush
	setvar VAR_0x8004, 5
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_NeedBerryForBerryCrush:: @ 8277923
	msgbox CableClub_Text_NeedBerryForBerryCrush, MSGBOX_DEFAULT
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_SaveAndChooseLinkLeader:: @ 8277931
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq CableClub_EventScript_AbortLink
	switch VAR_0x8004
	case 3, CableClub_EventScript_ChooseLinkLeaderFrom2
	case 0, CableClub_EventScript_ChooseLinkLeaderFrom2
	case 1, CableClub_EventScript_ChooseLinkLeaderFrom2
	case 2, CableClub_EventScript_ChooseLinkLeaderFrom4
	case 5, CableClub_EventScript_ChooseLinkLeader
	case 12, CableClub_EventScript_ChooseLinkLeader
	end

CableClub_EventScript_ChooseLinkLeaderFrom2:: @ 8277989
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players
	case 1, CableClub_EventScript_TryLeadGroup2Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup2Players:: @ 82779C6
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryLeadGroup2Players
	release
	return

CableClub_EventScript_TryJoinGroup2Players:: @ 82779EE
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryJoinGroup2Players
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4:: @ 8277A16
	message CableClub_Text_ChooseGroupLeaderOfFour
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players
	case 1, CableClub_EventScript_TryLeadGroup4Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup4Players:: @ 8277A53
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryLeadGroup4Players
	release
	return

CableClub_EventScript_TryJoinGroup4Players:: @ 8277A7B
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryJoinGroup4Players
	release
	return

CableClub_EventScript_ChooseLinkLeader:: @ 8277AA3
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroupXPlayers:: @ 8277AE0
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryLeadGroupXPlayers
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers:: @ 8277B08
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, 1
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
	compare VAR_RESULT, 5
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
	compare VAR_RESULT, 8
	goto_if_eq CableClub_EventScript_TryJoinGroupXPlayers
	release
	return

CableClub_EventScript_TryBecomeLinkLeader:: @ 8277B30
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup:: @ 8277B35
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom:: @ 8277B3A
	messageautoscroll CableClub_Text_DirectYouToYourRoom
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

EventScript_WirelessBoxResults:: @ 8277B8A
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq CableClub_EventScript_AdapterNotConnected
	fadescreen 1
	special sub_801A42C
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_AdapterNotConnected:: @ 8277BB4
	msgbox CableClub_Text_AdapterNotConnected, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier:: @ 8277BBE
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier:: @ 8277BD1
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier:: @ 8277BE4
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier:: @ 8277BF7
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

EventScript_OpenMossdeepGameCornerBarrier:: @ 8277C0A
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterOpen_Top, 0
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterOpen_Bottom, 0
	return

EventScript_CloseMossdeepGameCornerBarrier:: @ 8277C1D
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterClosed_Top, 1
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterClosed_Bottom, 1
	return

CableClub_MapScript1_InitUnionRoom: @ 8277C30
	special InitUnionRoom
	end

MossdeepCity_GameCorner_1F_EventScript_InfoMan2:: @ 8277C34
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_DescribeWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo
	case 1, MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo
	case 2, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	end

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo:: @ 8277C73
	msgbox MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo:: @ 8277C7D
	msgbox MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit:: @ 8277C87
	msgbox MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_OldMan2:: @ 8277C91
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected
	delay 60
	message MossdeepCity_GameCorner_1F_Text_PlayWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump
	case 1, MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump:: @ 8277CE9
	setvar VAR_0x8005, 0
	special DoesPartyHavePokemonJumpSpecies
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, 4
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking:: @ 8277D35
	setvar VAR_0x8005, 1
	special DoesPartyHaveDodrio
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, 6
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader:: @ 8277D81
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	case 1, MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader:: @ 8277DBE
	call CableClub_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	compare VAR_RESULT, 5
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	compare VAR_RESULT, 8
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	release
	return

MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup:: @ 8277DE6
	call CableClub_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	compare VAR_RESULT, 5
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	compare VAR_RESULT, 8
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	release
	return

MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom:: @ 8277E0E
	messageautoscroll MossdeepCity_GameCorner_1F_Text_AllGoodToGo
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call EventScript_OpenMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	release
	waitstate
	end

MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected:: @ 8277E48
	delay 60
	msgbox MossdeepCity_GameCorner_1F_Text_AdapterNotConnected, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon:: @ 8277E55
	msgbox MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	compare VAR_0x8005, 0
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements
	compare VAR_0x8005, 1
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements
	goto MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements:: @ 8277E84
	msgbox MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements:: @ 8277E8D
	msgbox MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpRecords:: @ 8277E96
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingRecords:: @ 8277E9D
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService: @ 8277EA4
	.string "Welcome to the POKéMON CABLE\n"
	.string "CLUB.\p"
	.string "Which of our services do you wish\n"
	.string "to use?$"

CableClub_Text_WhichService: @ 8277EF1
	.string "Which of our services do you wish\n"
	.string "to use?$"

CableClub_Text_TradeUsingLinkCable:: @ 8277F1B
	.string "Trade POKéMON with another player\n"
	.string "using a GBA Game Link cable.$"

CableClub_Text_BattleUsingLinkCable:: @ 8277F5A
	.string "You may battle another TRAINER\n"
	.string "using a GBA Game Link cable.$"

CableClub_Text_RecordCornerUsingLinkCable:: @ 8277F96
	.string "You can use the RECORD CORNER with\n"
	.string "others using a GBA Game Link cable.$"

@ Unused
CableClub_Text_CloseThisMenu: @ 8277FDD
	.string "Close this menu.$"

CableClub_Text_NeedTwoMonsForDoubleBattle: @ 8277FEE
	.string "For a DOUBLE BATTLE, you must\n"
	.string "have at least two POKéMON.$"

CableClub_Text_NeedTwoMonsToTrade: @ 8278027
	.string "For trading, you must have at\n"
	.string "least two POKéMON with you.$"

CableClub_Text_CantTradeEnigmaBerry: @ 8278061
	.string "A POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY can't be traded.$"

gText_PleaseWaitForLink:: @ 8278091
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

gText_ConfirmLinkWhenPlayersReady:: @ 82780B3
	.string "When all players are ready…\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_ConfirmStartLinkWithXPlayers:: @ 82780F2
	.string "Start link with {STR_VAR_1} players.\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_AwaitingLinkup:: @ 8278131
	.string "Awaiting linkup…\n"
	.string "… … B Button: Cancel$"

@ Unused
CableClub_Text_OkayToSaveProgress:: @ 8278157
	.string "Your progress must be saved before\n"
	.string "linking. Is it okay to save?$"

CableClub_Text_PleaseEnter: @ 8278197
	.string "Please enter.$"

CableClub_Text_DirectYouToYourRoom: @ 82781A5
	.string "I'll direct you to your room now.$"

Text_SomeoneIsNotReadyToLink: @ 82781C7
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"

Text_LinkErrorPleaseReset: @ 827821C
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"

Text_PlayersMadeDifferentSelections: @ 8278255
	.string "The link partners appear to have\n"
	.string "made different selections.$"

CableClub_Text_PleaseVisitAgain: @ 8278291
	.string "Please do visit again.$"

CableClub_Text_IncorrectNumberOfParticipants: @ 82782A8
	.string "The number of participants is\n"
	.string "incorrect.$"

CableClub_Text_CantSingleBattleWithXPlayers: @ 82782D1
	.string "The SINGLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

CableClub_Text_CantDoubleBattleWithXPlayers: @ 8278307
	.string "The DOUBLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

CableClub_Text_NeedFourPlayers: @ 827833D
	.string "There must be four players to play\n"
	.string "this Battle Mode.$"

CableClub_Text_PleaseConfirmNumberAndRestart: @ 8278372
	.string "Please confirm the number of\n"
	.string "players and start again.$"

Text_TerminateLinkConfirmation: @ 82783A8
	.string "The link will be terminated if you\n"
	.string "leave the room. Is that okay?$"

Text_TerminateLinkPleaseWait: @ 82783E9
	.string "Terminating link…\n"
	.string "You will be escorted out of\l"
	.string "the room. Please wait.$"

CableClub_Text_TooBusyToNotice: @ 827842E
	.string "This TRAINER is too busy to\n"
	.string "notice…$"

CableClub_Text_GotToLookAtTrainerCard: @ 8278452
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!$"

CableClub_Text_GotToLookAtColoredTrainerCard: @ 827847B
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"

SingleBattleColosseum_Text_TakePlaceStartBattle: @ 82784B4
	.string "Please take your place and start\n"
	.string "your battle.$"

TradeCenter_Text_TakeSeatStartTrade: @ 82784E2
	.string "Please take your seat and start\n"
	.string "your trade.$"

RecordCorner_Text_ThanksForComing: @ 827850E
	.string "Thanks for coming.$"

CableClub_Text_TrainerCardDataOverwritten: @ 8278521
	.string "The TRAINER CARD data will\n"
	.string "be overwritten.$"

CableClub_Text_HopeToSeeYouAgain: @ 827854C
	.string "I hope to see you again!$"

CableClub_Text_NotSetUpForFarAwayRegion: @ 8278565
	.string "I'm awfully sorry.\p"
	.string "We're not set up to conduct trades\n"
	.string "with TRAINERS far away in another\l"
	.string "region yet…$"

CableClub_Text_OtherTrainerNotReady: @ 82785C9
	.string "The other TRAINER is not ready.$"

CableClub_Text_YouHaveAMonThatCantBeTaken: @ 82785E9
	.string "You have at least one POKéMON\n"
	.string "that can't be taken.$"

RecordCorner_Text_TakeSeatAndWait: @ 827861C
	.string "Please take your seat and wait.$"

RecordCorner_Text_PlayerSentOverOneX: @ 827863C
	.string "{STR_VAR_1} sent over one\n"
	.string "{STR_VAR_2}.$"

CableClub_Text_CantMixWithJapaneseGame: @ 8278651
	.string "Sorry, there is a transmission error.\p"
	.string "You may not mix records with  \n"
	.string "Japanese Ruby or Sapphire games.\p"
	.string "Also, you can't mix records with\n"
	.string "Japanese Emerald and overseas Ruby\l"
	.string "or Sapphire games at the same time.$"

CableClub_Text_AdapterNotConnected: @ 827871F
	.string "The Wireless Adapter is not\n"
	.string "connected properly.$"

CableClub_Text_ParticipantsStepUpToCounter: @ 827874F
	.string "Participants are asked to step up\n"
	.string "to the reception counter.$"

@ Unused
CableClub_Text_Hello: @ 827878B
	.string "Hello!$"

@ Unused
CableClub_Text_PleaseWait: @ 8278792
	.string "Please wait.$"

CableClub_Text_YouMayTradeHere:: @ 827879F
	.string "You may trade your POKéMON here\n"
	.string "with another TRAINER.$"

CableClub_Text_YouMayBattleHere:: @ 82787D5
	.string "You may battle with your friends\n"
	.string "here.$"

CableClub_Text_CanMakeBerryPowder:: @ 82787FC
	.string "Two to five TRAINERS can make\n"
	.string "BERRY POWDER together.$"

CableClub_Text_CanMixRecords:: @ 8278831
	.string "The records of two to four players\n"
	.string "can be mixed together.$"

OldaleTown_PokemonCenter_2F_Text_27886B: @ 827886B
	.string "A guide to the WIRELESS CLUB's\n"
	.string "various services.$"

CableClub_Text_CancelSelectedItem:: @ 827889C
	.string "Cancels the selected MENU item.$"

OldaleTown_PokemonCenter_2F_Text_2788BC: @ 82788BC
	.string "Which battle mode would you like?$"

@ Unused
CableClub_Text_ReturnsToPreviousStep: @ 82788DE
	.string "Returns to the previous step.$"

CableClub_Text_NeedBerryForBerryCrush: @ 82788FC
	.string "To use the BERRY CRUSH service,\n"
	.string "you must have at least one BERRY.$"

CableClub_Text_NeedTwoMonsForUnionRoom: @ 827893E
	.string "To enter the UNION ROOM, you must\n"
	.string "have at least two POKéMON.$"

CableClub_Text_NoEnigmaBerryInUnionRoom: @ 827897B
	.string "No POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY may enter the UNION ROOM.$"

CableClub_Text_UnionRoomAdapterNotConnected: @ 82789B5
	.string "This is the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM.\p"
	.string "Unfortunately, your Wireless\n"
	.string "Adapter is not connected properly.\p"
	.string "Please do come again.$"

@ Unused
CableClub_Text_OhExcuseMe: @ 8278A39
	.string "Oh…\n"
	.string "Excuse me!$"

CableClub_Text_PlayerIsWaiting: @ 8278A48
	.string "It appears as if {STR_VAR_1} is playing\n"
	.string "right now.\l"
	.string "Go for it!$"

MossdeepCity_GameCorner_1F_Text_DescribeWhichGame: @ 8278A7D
	.string "I can explain game rules to you,\n"
	.string "if you'd like.\p"
	.string "Which game should I describe?$"

MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo: @ 8278ACB
	.string "“POKéMON JUMP”\p"
	.string "Make your POKéMON skip the VINE WHIP\n"
	.string "rope with the A Button.\p"
	.string "Only mini POKéMON around 28 inches\n"
	.string "or less may participate.\p"
	.string "POKéMON that only swim, burrow,\n"
	.string "or fly are not good at jumping.\p"
	.string "As a result, those POKéMON may not\n"
	.string "participate.\p"
	.string "Good things happen if everyone\n"
	.string "jumps in time.$"

MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo: @ 8278BF1
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Command DODRIO's three heads to\n"
	.string "catch falling BERRIES.\p"
	.string "Press right, up, or left on the\n"
	.string "{PLUS} Control Pad to move the heads.\p"
	.string "To play this game, you must have\n"
	.string "a DODRIO.$"

MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay: @ 8278CAC
	.string "If you want to play a game,\n"
	.string "please tell the old man beside me.$"

MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait: @ 8278CEB
	.string "Hi, welcome!\n"
	.string "Are you here to play games using\l"
	.string "Wireless Communication?\p"
	.string "Can you wait just a little bit?$"

MossdeepCity_GameCorner_1F_Text_ComeAgain: @ 8278D51
	.string "All right, come again!$"

MossdeepCity_GameCorner_1F_Text_AdapterNotConnected: @ 8278D68
	.string "The Wireless Adapter isn't connected.\n"
	.string "Come back when it's hooked up!$"

MossdeepCity_GameCorner_1F_Text_PlayWhichGame: @ 8278DAD
	.string "All right, which game did you want\n"
	.string "to play?$"

MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon: @ 8278DD9
	.string "Which POKéMON would you like to\n"
	.string "enter?$"

MossdeepCity_GameCorner_1F_Text_AllGoodToGo: @ 8278E00
	.string "Okay, you're all good to go.\n"
	.string "Don't let the others beat you!$"

@ Unused
MossdeepCity_GameCorner_1F_Text_LeavingDoComeAgain: @ 8278E3C
	.string "Are you leaving now?\n"
	.string "Do come again!$"

MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon: @ 8278E60
	.string "It doesn't look like you have any\n"
	.string "POKéMON that you can enter…\p"
	.string "Would you like me to explain what\n"
	.string "kinds of POKéMON can enter?$"

MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed: @ 8278EDC
	.string "“POKéMON JUMP” is open to POKéMON\n"
	.string "around 28 inches or less.\p"
	.string "What you can't enter are those\n"
	.string "POKéMON that can't jump.\p"
	.string "You know, like POKéMON that only\n"
	.string "swim, burrow, or fly.\p"
	.string "That's all you need to know.$"

MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed: @ 8278FA4
	.string "DODRIO BERRY-PICKING is a game that \n"
	.string "only DODRIO may enter.$"

@ Unused
MossdeepCity_GameCorner_1F_Text_RetryPlease: @ 8278FE0
	.string "Could you retry this from the start\n"
	.string "again, please?$"

CableClub_Text_WelcomeWhichDirectCornerRoom: @ 8279013
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB DIRECT CORNER.\p"
	.string "You may interact directly with\n"
	.string "your friends here.\p"
	.string "Which room would you like to\n"
	.string "enter?$"

CableClub_Text_TradePokemon: @ 827909D
	.string "Would you like to trade POKéMON?$"

CableClub_Text_WhichBattleMode: @ 82790BE
	.string "Which Battle Mode would you like\n"
	.string "to play?$"

CableClub_Text_AccessRecordCorner: @ 82790E8
	.string "Would you like to access\n"
	.string "the RECORD CORNER?$"

CableClub_Text_UseBerryCrush: @ 8279114
	.string "Would you like to use the\n"
	.string "BERRY CRUSH System?$"

CableClub_Text_ExplainBattleModes: @ 8279142
	.string "There are three Battle Modes.\p"
	.string "SINGLE BATTLE is for two TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.\p"
	.string "DOUBLE BATTLE is for two TRAINERS\n"
	.string "with two or more POKéMON each.\p"
	.string "Each TRAINER will send out two\n"
	.string "POKéMON in battle at a time.\p"
	.string "MULTI BATTLE is for four TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.$"

CableClub_Text_ChooseGroupLeaderOfTwo: @ 82792CD
	.string "Please decide which of you two\n"
	.string "will become the LEADER.\p"
	.string "The other player must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_ChooseGroupLeaderOfFour: @ 8279334
	.string "Please decide which of you four\n"
	.string "will become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_ChooseGroupLeader: @ 82793A3
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_WelcomeUnionRoomEnter: @ 827940D
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB UNION ROOM.\p"
	.string "You may interact directly with\n"
	.string "other TRAINERS here, some of\l"
	.string "whom you may not even know.\p"
	.string "Would you like to enter the ROOM?$"

CableClub_Text_UnionRoomInfo: @ 82794B8
	.string "The TRAINERS in the UNION ROOM\n"
	.string "will be those players around you\l"
	.string "who have also entered the ROOM.\p"
	.string "You may do all sorts of things\n"
	.string "here, such as exchanging greetings.\p"
	.string "You may enter two POKéMON up to\n"
	.string "Lv. 30 for a one-on-one battle.\p"
	.string "You may take part in a chat with\n"
	.string "two to five people.\p"
	.string "Or, you may register a POKéMON for\n"
	.string "trade.\p"
	.string "Would you like to enter the ROOM?$"

CableClub_Text_EnjoyUnionRoom: @ 827961C
	.string "I hope you enjoy your time in\n"
	.string "the UNION ROOM.$"

CableClub_Text_FirstTimeRightThisWay: @ 827964A
	.string "Hello!\n"
	.string "My name is TEALA.\p"
	.string "This must be your first time\n"
	.string "up here.\p"
	.string "I'll show you how the Wireless\n"
	.string "Communication System works.\p"
	.string "First, I need to show you this\n"
	.string "floor of our POKéMON CENTER.\p"
	.string "Right this way, please.$"

CableClub_Text_ExplainWirelessClubFirstTime: @ 8279718
	.string "On the top floor, there are two\n"
	.string "rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

CableClub_Text_AskAboutLinking: @ 8279937
	.string "Hello, {PLAYER}!\p"
	.string "It's me, TEALA, the POKéMON\n"
	.string "CENTER 2F attendant.\p"
	.string "Is there something you needed to\n"
	.string "ask me about linking?$"

CableClub_Text_ExplainWirelessClub: @ 82799AA
	.string "Let me explain how the POKéMON\n"
	.string "WIRELESS CLUB works.\p"
	.string "On this, the top floor, there are\n"
	.string "two rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "Sometimes, you may not be able to\n"
	.string "find your friends in the UNION ROOM\l"
	.string "or the DIRECT CORNER.\p"
	.string "In that case, please move closer\n"
	.string "to your friends.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

CableClub_Text_HopeYouEnjoyWirelessSystem: @ 8279C91
	.string "I hope you enjoy the Wireless\n"
	.string "Communication System.$"
