CableClub_OnTransition:
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan::
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_ShowMysteryGiftMan
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_HideMysteryGiftMan
	goto CableClub_EventScript_ShowMysteryGiftMan
	end

CableClub_EventScript_ShowMysteryGiftMan::
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_HideMysteryGiftMan::
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

CableClub_EventScript_MysteryGiftMan::
	specialvar VAR_RESULT, ShouldDistributeEonTicket
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_DistributeEonTicket
	goto CableClub_EventScript_TryWonderCardScript
	end

CableClub_EventScript_TryWonderCardScript::
	trywondercardscript
CableClub_EventScript_MysteryGiftThankYou::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_EventScript_DistributeEonTicket::
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_TryWonderCardScript
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, CableClub_EventScript_TryWonderCardScript
	msgbox MysteryGift_Text_TheresATicketForYou, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox MysteryGift_Text_TryUsingItAtLilycovePort, MSGBOX_DEFAULT
	release
	end

@ Unused?
CableClub_EventScript_MysteryGiftThankYou2::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
	release
	end

CableClub_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

CableClub_EventScript_CheckTurnAttendant::
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_DontTurnAttendant
	turnobject VAR_0x8007, DIR_WEST
CableClub_EventScript_DontTurnAttendant::
	end

CableClub_OnLoad:
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_OnLoadFromTradeCenter
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_OnLoadFromRecordCorner
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_OnLoadFromUnionRoom
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_OnLoadFromBerryCrush
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_OnLoadFromGameCorner
	end

CableClub_EventScript_OnLoadFromColosseum::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromTradeCenter::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromRecordCorner::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromUnionRoom::
	call CableClub_EventScript_OpenUnionRoomBarrier
	end

CableClub_EventScript_OnLoadFromBerryCrush::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

CableClub_EventScript_OnLoadFromGameCorner::
	call EventScript_OpenMossdeepGameCornerBarrier
	end

CableClub_OnFrame:
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

CableClub_EventScript_ExitLinkRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call EventScript_CloseMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitRecordCorner::
	lockall
	call CableClub_EventScript_PlayerExitRecordCorner
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitRecordCorner::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_ExitRecordCornerRet
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
CableClub_EventScript_ExitRecordCornerRet::
	return

CableClub_EventScript_ExitUnionRoom::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom::
	setvar VAR_CABLE_CLUB_STATE, 0
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten::
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	delay 60
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CableClub_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime, MSGBOX_DEFAULT
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	releaseall
	end

CableClub_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub::
	message CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 28
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub::
	msgbox CableClub_Text_WhichService, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom::
	setvar VAR_0x8004, 0
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_CableClubUnlockedRecordCorner
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_CableClubUnlockedRecordCorner::
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_RecordCorner
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo::
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE,  CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers, MSGBOX_DEFAULT
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart::
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_TradeCenter::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsToTrade::
	msgbox CableClub_Text_NeedTwoMonsToTrade, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_CantTradeEnigmaBerry::
	msgbox CableClub_Text_CantTradeEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

CableClub_EventScript_RecordCorner::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special TryRecordMixLinkup
	waitstate
	special ValidateMixingGameLanguage
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_FOREIGN_GAME, CableClub_EventScript_AbortLinkForeignGame
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterRecordCorner
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterRecordCorner::
	setvar VAR_0x8004, USING_RECORD_CORNER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_RECORD_CORNER, 8, 9
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkPlayerNotReady::
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady::
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkConnectionError::
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady::
	special CloseLink
	msgbox Text_SomeoneIsNotReadyToLink, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLink::
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_AbortMinigame::
	special CloseLink
	msgbox MossdeepCity_GameCorner_1F_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp::
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants::
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg::
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_AbortLinkForeignGame::
	special CloseLink
	msgbox CableClub_Text_CantMixWithJapaneseGame, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_WirelessClubAdjustements::
	msgbox gText_SorryWirelessClubAdjustments, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_NotReadyYet::
	msgbox gText_UndergoingAdjustments, MSGBOX_DEFAULT
	releaseall
	end

Movement_AttendantFaceDown:
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight:
	face_right
	step_end

Movement_AttendantFaceLeft:
	face_left
	step_end

Movement_PlayerExitLinkRoom:
	walk_down
	walk_down
	step_end

@ Functionally unused
Movement_PlayerApproachLinkRoomRight:
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft:
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom:
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft:
	face_left
	step_end

Movement_PlayerFaceAttendantRight:
	face_right
	step_end

Movement_PlayerEnterMinigameRoom:
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

EventScript_CableBoxResults::
	lockall
	setvar VAR_0x8004, 0
	special ShowLinkBattleRecords
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

EventScript_BattleColosseum_2P_PlayerSpot0::
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_2P_PlayerSpot1::
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 2
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_BattleColosseum_4P_CancelSpotTrigger
	setvar VAR_0x8005, 3
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_BattleColosseum_4P_CancelSpotTrigger::
	end

EventScript_TradeCenter_Chair0::
	setvar VAR_0x8005, 0
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_TradeCenter_Chair1::
	setvar VAR_0x8005, 1
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair2::
	setvar VAR_0x8005, 2
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair3::
	setvar VAR_0x8005, 3
	special PlayerEnteredTradeSeat
	waitstate
	end

@ VAR_TEMP_1 for below scripts set by ReceiveGiftItem
EventScript_RecordCenter_Spot0::
	setvar VAR_0x8005, 0
	special RecordMixingPlayerSpotTriggered
	waitstate
	goto_if_ne VAR_TEMP_1, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot1::
	setvar VAR_0x8005, 1
	special RecordMixingPlayerSpotTriggered
	waitstate
	goto_if_ne VAR_TEMP_1, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot2::
	setvar VAR_0x8005, 2
	special RecordMixingPlayerSpotTriggered
	waitstate
	goto_if_ne VAR_TEMP_1, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

EventScript_RecordCenter_Spot3::
	setvar VAR_0x8005, 3
	special RecordMixingPlayerSpotTriggered
	waitstate
	goto_if_ne VAR_TEMP_1, ITEM_NONE, RecordCorner_EventScript_ReceivedGiftItem
	end

RecordCorner_EventScript_ReceivedGiftItem::
	bufferitemname STR_VAR_2, VAR_TEMP_1
	message RecordCorner_Text_PlayerSentOverOneX
	waitmessage
	waitbuttonpress
	releaseall
	end

CableClub_EventScript_ReadTrainerCard::
	msgbox CableClub_Text_GotToLookAtTrainerCard, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored::
	msgbox CableClub_Text_GotToLookAtColoredTrainerCard, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice::
	msgbox CableClub_Text_TooBusyToNotice, MSGBOX_DEFAULT
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant::
	special Script_FacePlayer
	msgbox BattleColosseum_2P_Text_TakePlaceStartBattle, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant::
	special Script_FacePlayer
	msgbox TradeCenter_Text_TakeSeatStartTrade, MSGBOX_DEFAULT
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_Attendant::
	goto_if_ne VAR_TEMP_0, 0, RecordCorner_EventScript_AlreadyMixed
	special Script_FacePlayer
	message RecordCorner_Text_TakeSeatAndWait
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

RecordCorner_EventScript_AlreadyMixed::
	special Script_FacePlayer
	message RecordCorner_Text_ThanksForComing
	waitmessage
	waitbuttonpress
	special Script_ClearHeldMovement
	closemessage
	end

EventScript_ConfirmLeaveCableClubRoom::
	msgbox Text_TerminateLinkConfirmation, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_TerminateLink
	erasebox 0, 0, 29, 19
	releaseall
	end

EventScript_TerminateLink::
	messageautoscroll Text_TerminateLinkPleaseWait
	waitmessage
	special ExitLinkRoom
	end

EventScript_DoLinkRoomExit::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FACILITY_UNION_ROOM
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected
	message CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_UnionRoomSelect::
	multichoice 17, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo::
	message CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_UnionRoomSelect
	end

CableClub_EventScript_EnterUnionRoom::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	msgbox CableClub_Text_EnjoyUnionRoom, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, 1
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

CableClub_EventScript_UnionRoomAdapterNotConnected::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_WirelessClubAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking
	msgbox CableClub_Text_ExplainWirelessClub, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DontAskAboutLinking::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem, MSGBOX_DEFAULT
	release
	return

CableClub_EventScript_DirectCornerAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER  @ Set preemptively for multi battles, ignored otherwise
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub
	message CableClub_Text_WelcomeWhichDirectCornerRoom
	waitmessage
	delay 28
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_DirectCornerSelectService::
	checkitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_DirectCornerNoBerry
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerSelectAllServices
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessBerryCrush
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerSelectAllServices::
	multichoice 0, 0, MULTI_WIRELESS_ALL_SERVICES, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_WirelessBerryCrush
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerNoBerry::
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerHasRecordMix
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerHasRecordMix::
	multichoice 0, 0, MULTI_WIRELESS_NO_BERRY, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessRecordMix
	case 3, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessTrade::
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleSelect::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle
	case 1, CableClub_EventScript_WirelessDoubleBattle
	case 2, CableClub_EventScript_WirelessMultiBattle
	case 3, CableClub_EventScript_WirelessBattleInfo
	case 4, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessSingleBattle::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessDoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessMultiBattle::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleInfo::
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessRecordMix::
	msgbox CableClub_Text_AccessRecordCorner, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_RECORD_CORNER
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBerryCrush::
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_NeedBerryForBerryCrush::
	msgbox CableClub_Text_NeedBerryForBerryCrush, MSGBOX_DEFAULT
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_SaveAndChooseLinkLeader::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader
	case LINK_GROUP_RECORD_CORNER, CableClub_EventScript_ChooseLinkLeader
	end

CableClub_EventScript_ChooseLinkLeaderFrom2::
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players
	case 1, CableClub_EventScript_TryLeadGroup2Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup2Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players
	release
	return

CableClub_EventScript_TryJoinGroup2Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4::
	message CableClub_Text_ChooseGroupLeaderOfFour
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players
	case 1, CableClub_EventScript_TryLeadGroup4Players
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup4Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players
	release
	return

CableClub_EventScript_TryJoinGroup4Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players
	release
	return

CableClub_EventScript_ChooseLinkLeader::
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
	case 2, CableClub_EventScript_AbortLink
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroupXPlayers::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers
	release
	return

CableClub_EventScript_TryBecomeLinkLeader::
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup::
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom::
	messageautoscroll CableClub_Text_DirectYouToYourRoom
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

EventScript_WirelessBoxResults::
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_AdapterNotConnected::
	msgbox CableClub_Text_AdapterNotConnected, MSGBOX_DEFAULT
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier::
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, FALSE
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	return

CableClub_EventScript_CloseUnionRoomBarrier::
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop, TRUE
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, TRUE
	return

CableClub_EventScript_OpenDirectCornerBarrier::
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, FALSE
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	return

CableClub_EventScript_CloseDirectCornerBarrier::
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop, TRUE
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, TRUE
	return

EventScript_OpenMossdeepGameCornerBarrier::
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterOpen_Top, FALSE
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterOpen_Bottom, FALSE
	return

EventScript_CloseMossdeepGameCornerBarrier::
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterClosed_Top, TRUE
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterClosed_Bottom, TRUE
	return

CableClub_OnResume:
	special InitUnionRoom
	end

MossdeepCity_GameCorner_1F_EventScript_InfoMan2::
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_DescribeWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo
	case 1, MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo
	case 2, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	end

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo::
	msgbox MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo::
	msgbox MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit::
	msgbox MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_OldMan2::
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected
	delay 60
	message MossdeepCity_GameCorner_1F_Text_PlayWhichGame
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump
	case 1, MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	end

MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader::
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	case 1, MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
	release
	return

MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
	release
	return

MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom::
	messageautoscroll MossdeepCity_GameCorner_1F_Text_AllGoodToGo
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call EventScript_OpenMossdeepGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	release
	waitstate
	end

MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected::
	delay 60
	msgbox MossdeepCity_GameCorner_1F_Text_AdapterNotConnected, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon::
	msgbox MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	call_if_eq VAR_0x8005, 0, MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements
	call_if_eq VAR_0x8005, 1, MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements
	goto MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
	end

MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements::
	msgbox MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements::
	msgbox MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_PokemonJumpRecords::
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingRecords::
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end
