CableClub_OnTransition_Frlg::
	call CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg
	end

CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg::
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideMysteryGiftMan_Frlg
	clearflag FLAG_HIDE_MG_DELIVERYMEN
	return

EventScript_HideMysteryGiftMan_Frlg::
	setflag FLAG_HIDE_MG_DELIVERYMEN
	return

CableClub_EventScript_MysteryGiftMan_Frlg::
	trywondercardscript

@ Unused
EventScript_MysteryGiftThankYou_Frlg::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_OnWarp_Frlg::
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

EventScript_CheckTurnAttendant_Frlg::
	goto_if_eq VAR_0x8007, 0, EventScript_CheckTurnAttendantEnd
	turnobject VAR_0x8007, DIR_WEST
EventScript_CheckTurnAttendantEnd:
	end

CableClub_OnLoad_Frlg::
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_OnLoadFromTradeCenter_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_OnLoadFromUnionRoom_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_OnLoadFromBerryCrush_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_OnLoadFromGameCorner_Frlg
	end

EventScript_OnLoadFromColosseum_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromTradeCenter_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromUnionRoom_Frlg::
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	end

EventScript_OnLoadFromBerryCrush_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromGameCorner_Frlg::
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	end

CableClub_OnFrame_Frlg::
	map_script_2 VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1, CableClub_EventScript_Tutorial_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom_Frlg
	.2byte 0

CableClub_EventScript_ExitLinkRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter_Frlg::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_ExitUnionRoom_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom_Frlg
	call CableClub_EventScript_CloseUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_TrainerCardDataOverwritten_Frlg::
	message CableClub_Text_TrainerCardDataOverwritten_Frlg
	waitmessage
	playse SE_PIN
	message CableClub_Text_HopeToSeeYouAgain_Frlg
	waitmessage
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial_Frlg::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay_Frlg
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime_Frlg
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 2
	releaseall
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub_Frlg::
	message CableClub_Text_WelcomeWhichCableClubService_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_UnusedWelcomeToCableClub_Frlg::
	msgbox CableClub_Text_WhichService_Frlg
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_SelectCableClubRoom_Frlg::
	setvar VAR_0x8004, 0
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter_Frlg
	case 1, CableClub_EventScript_Colosseum_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_Colosseum_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SelectBattleMode_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode_Frlg
	case 1, CableClub_EventScript_DoubleBattleMode_Frlg
	case 2, CableClub_EventScript_MultiBattleMode_Frlg
	case 3, CableClub_EventScript_BattleModeInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_BattleModeInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SingleBattleMode_Frlg::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_DoubleBattleMode_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_MultiBattleMode_Frlg::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_TryEnterColosseum_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryBattleLinkup
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	end

CableClub_EventScript_EnterColosseum_Frlg::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum_Frlg
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P_FRLG, 6, 8
	special DoCableClubWarp
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum_Frlg::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P_FRLG, 5, 8
	special DoCableClubWarp
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	end

CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_ConfirmNumberAndRestart_Frlg::
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart_Frlg
	release
	end

CableClub_EventScript_TradeCenter_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryTradeLinkup
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg
	end

CableClub_EventScript_EnterTradeCenter_Frlg::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER_FRLG, 5, 8
	special DoCableClubWarp
	end

CableClub_EventScript_CheckPartyTradeRequirements_Frlg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade_Frlg::
	msgbox CableClub_Text_NeedTwoMonsToTrade_Frlg
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry_Frlg::
	msgbox CableClub_Text_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, FALSE
	return

@ Record Corner is nopped in FRLG
CableClub_EventScript_RecordCorner_Frlg::
	end

CableClub_EventScript_AbortLinkPlayerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion_Frlg
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady_Frlg
	release
	end

CableClub_EventScript_AbortLinkConnectionError_Frlg::
	special CloseLink
	msgbox CableClub_Text_LinkErrorPleaseReset_Frlg
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_SomeoneIsNotReadyToLink_Frlg
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections_Frlg::
	special CloseLink
	msgbox CableClub_Text_PlayersMadeDifferentSelections_Frlg
	release
	end

CableClub_EventScript_AbortLink_Frlg::
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain_Frlg
	release
	end

CableClub_EventScript_AbortMinigame_Frlg::
	special CloseLink
	msgbox CableClub_Text_ComeAgain_Frlg
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp_Frlg::
	special SetCableClubWarp
	special DoCableClubWarp
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg::
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants_Frlg
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg::
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg
	release
	end

CableClub_EventScript_WirelessClubAdjustements_Frlg::
	msgbox Text_WirelessClubUndergoingAdjustments
	release
	end

CableClub_EventScript_NotReadyYet_Frlg::
	msgbox Text_AppearsToBeUndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown_Frlg::
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight_Frlg::
	face_right
	step_end

Movement_AttendantFaceLeft_Frlg::
	face_left
	step_end

Movement_PlayerExitLinkRoom_Frlg::
	walk_down
	walk_down
	step_end

Movement_PlayerApproachLinkRoomRight_Frlg::
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft_Frlg::
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom_Frlg::
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft_Frlg::
	face_left
	step_end

Movement_PlayerFaceAttendantRight_Frlg::
	face_right
	step_end

Movement_PlayerEnterMinigameRoom_Frlg::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CableClub_EventScript_ShowBattleRecords_Frlg::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	releaseall
	end

BattleColosseum_2P_EventScript_PlayerSpot0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_2P_EventScript_PlayerSpot1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg::
	end

TradeCenter_EventScript_Chair0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

TradeCenter_EventScript_Chair1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Unused
TradeCenter_EventScript_Chair2_Frlg::
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Unused
TradeCenter_EventScript_Chair3_Frlg::
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Nop in FRLG
@ Separate labels to match GetDirectionForEventScript
RecordCorner_EventScript_Spot0::
RecordCorner_EventScript_Spot1::
RecordCorner_EventScript_Spot2::
RecordCorner_EventScript_Spot3::
	end

CableClub_EventScript_ReadTrainerCard_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCard_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	end

CableClub_EventScript_ReadTrainerCardColored_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCardColored_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	end

CableClub_EventScript_TooBusyToNotice_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TrainerTooBusyToNotice_Frlg
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartBattle_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartTrade_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

@ Nop in FRLG
RecordCorner_EventScript_Attendant_Frlg::
	end

TradeCenter_ConfirmLeaveRoom_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TerminateLinkIfYouLeaveRoom_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TradeCenter_TerminateLink_Frlg
	erasebox 0, 0, 29, 19
	releaseall
	end

TradeCenter_TerminateLink_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	messageautoscroll Text_TerminateLinkConfirmation
	waitmessage
	special ExitLinkRoom
	end

CableClub_EventScript_DoLinkRoomExit_Frlg::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	end

CableClub_EventScript_UnionRoomAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg
	message CableClub_Text_WelcomeUnionRoomEnter_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_AskEnterUnionRoom_Frlg::
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom_Frlg
	case 1, CableClub_EventScript_AbortLink_Frlg
	case 2, CableClub_EventScript_UnionRoomInfo_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_UnionRoomInfo_Frlg::
	message CableClub_Text_UnionRoomInfo_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_EnterUnionRoom_Frlg::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	msgbox CableClub_Text_EnjoyUnionRoom_Frlg
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM_FRLG, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected_Frlg
	release
	return

CableClub_EventScript_WirelessClubAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	msgbox CableClub_Text_AskAboutLinking_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking_Frlg
	msgbox CableClub_Text_ExplainWirelessClub_Frlg
	release
	return

CableClub_EventScript_DontAskAboutLinking_Frlg::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg
	release
	return

CableClub_EventScript_DirectCornerAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub_Frlg
	message CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_DirectCornerSelectService_Frlg::
	goto_if_unset FLAG_GOT_POWDER_JAR, CableClub_EventScript_DirectCornerNoBerry_Frlg
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_WirelessBerryCrush_Frlg
	case 3, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_DirectCornerNoBerry_Frlg::
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessTrade_Frlg::
	msgbox CableClub_Text_TradePokemon_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleSelect_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle_Frlg
	case 1, CableClub_EventScript_WirelessDoubleBattle_Frlg
	case 2, CableClub_EventScript_WirelessMultiBattle_Frlg
	case 3, CableClub_EventScript_WirelessBattleInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessSingleBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessDoubleBattle_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessMultiBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessBerryCrush_Frlg::
	msgbox CableClub_Text_UseBerryCrush_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_NeedBerryForBerryCrush_Frlg::
	msgbox CableClub_Text_NeedBerryForBerryCrush_Frlg
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_SaveAndChooseLinkLeader_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfTwo_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup2Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup2Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup2Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfFour_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup4Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup4Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup4Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeader_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	case 1, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroupXPlayers_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryBecomeLinkLeader_Frlg::
	special TryBecomeLinkLeader
	return

CableClub_EventScript_TryJoinLinkGroup_Frlg::
	special TryJoinLinkGroup
	return

CableClub_EventScript_EnterWirelessLinkRoom_Frlg::
	messageautoscroll CableClub_Text_DirectYouToYourRoom_Frlg
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

CableClub_EventScript_ShowWirelessCommunicationScreen_Frlg::
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected_Frlg
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	msgbox CableClub_Text_ParticipantsStepUpToCounter_Frlg
	releaseall
	end

CableClub_EventScript_AdapterNotConnected_Frlg::
	msgbox CableClub_Text_AdapterNotConnected_Frlg
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CheckeredFloor_ShadeLeft, 0
	return

CableClub_EventScript_CloseGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CounterBarrier, 1
	return

CableClub_OnResume_Frlg::
	special InitUnionRoom
	end

JoyfulGameCorner_EventScript_InfoMan2_Frlg::
	lock
	faceplayer
	message Text_DescribeWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PokemonJumpInfo_Frlg
	case 1, CableClub_EventScript_DodrioBerryPickingInfo_Frlg
	case 2, CableClub_EventScript_MinigameInfoExit_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_MinigameInfoExit_Frlg
	end

CableClub_EventScript_PokemonJumpInfo_Frlg::
	msgbox Text_PokemonJumpInfo_Frlg
	release
	end

CableClub_EventScript_DodrioBerryPickingInfo_Frlg::
	msgbox Text_DodrioBerryPickingInfo_Frlg
	release
	end

CableClub_EventScript_MinigameInfoExit_Frlg::
	msgbox Text_TalkToManToPlay_Frlg
	release
	end

JoyfulGameCorner_EventScript_MinigameAttendant_Frlg::
	lock
	faceplayer
	message Text_WelcomeCanYouWait_Frlg
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnectedMinigame_Frlg
	delay 60
	message Text_PlayWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PlayPokemonJump_Frlg
	case 1, CableClub_EventScript_PlayDodrioBerryPicking_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_PlayPokemonJump_Frlg::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_PlayDodrioBerryPicking_Frlg::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	case 1, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	release
	return

CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	release
	return

CableClub_EventScript_EnterMinigame_Frlg::
	messageautoscroll Text_AllGoodToGo_Frlg
	waitmessage
	delay 120
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideplayer
	release
	waitstate
	end

CableClub_EventScript_AdapterNotConnectedMinigame_Frlg::
	msgbox Text_AdapterNotConnectedMinigame_Frlg
	release
	end

CableClub_EventScript_NoEligiblePkmn_Frlg::
	msgbox EventScript_ExplainPokemonJumpRequirements_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortMinigame_Frlg
	call_if_eq VAR_0x8005, 0, CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg
	call_if_eq VAR_0x8005, 1, CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg
	goto CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg::
	msgbox Text_ShortJumpingPokemonAllowed_Frlg
	return

CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg::
	msgbox Text_OnlyDodrioAllowed_Frlg
	return

TwoIsland_JoyfulGameCorner_EventScript_ShowPokemonJumpRecords::
	lockall
	special ShowPokemonJumpRecords
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_ShowDodrioBerryPickingRecords::
	lockall
	special ShowDodrioBerryPickingRecords
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService_Frlg::
	.string "Welcome to the POKéMON CABLE\n"
	.string "CLUB.\p"
	.string "Which of our services do you wish\n"
	.string "to use?$"

CableClub_Text_WhichService_Frlg::
	.string "Which of our services do you wish\n"
	.string "to use?$"

CableClub_Text_TradeMonsUsingLinkCable_Frlg::
	.string "Trade POKéMON with another player\n"
	.string "using a GBA Game Link cable.$"

CableClub_Text_BattleUsingLinkCable_Frlg::
	.string "You may battle another TRAINER\n"
	.string "using a GBA Game Link cable.$"

@ Unused, translated in Emerald
CableClub_Text_CloseThisMenu_Frlg::
	.string "おわります$"

CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg::
	.string "For a DOUBLE BATTLE, you must\n"
	.string "have at least two POKéMON.$"

CableClub_Text_NeedTwoMonsToTrade_Frlg::
	.string "For trading, you must have at\n"
	.string "least two POKéMON with you.$"

CableClub_Text_CantTradeEnigmaBerry_Frlg::
	.string "A POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY can't be traded.$"

CableClub_Text_PleaseWaitBCancel_Frlg::
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

CableClub_Text_WhenAllPlayersReadyAConfirmBCancel_Frlg::
	.string "When all players are ready…\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

CableClub_Text_StartLinkWithXPlayersAConfirmBCancel_Frlg::
	.string "Start link with {STR_VAR_1} players.\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

CableClub_Text_AwaitingLinkupBCancel_Frlg::
	.string "Awaiting linkup…\n"
	.string "… … B Button: Cancel$"

@ Unused, translated in Emerald
CableClub_Text_OkayToSaveProgress_Frlg::
	.string "はじめる　まえに　レポートを\n"
	.string "かきますが　よろしいですか？$"

CableClub_Text_PleaseEnter_Frlg::
	.string "Please enter.$"

CableClub_Text_DirectYouToYourRoom_Frlg::
	.string "I'll direct you to your room now.$"

CableClub_Text_SomeoneIsNotReadyToLink_Frlg::
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"

CableClub_Text_LinkErrorPleaseReset_Frlg::
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"

CableClub_Text_PlayersMadeDifferentSelections_Frlg::
	.string "The link partners appear to have\n"
	.string "made different selections.$"

CableClub_Text_PleaseVisitAgain_Frlg::
	.string "Please do visit again.$"

CableClub_Text_IncorrectNumberOfParticipants_Frlg::
	.string "The number of participants is\n"
	.string "incorrect.$"

CableClub_Text_CantSingleBattleWithXPlayers_Frlg::
	.string "The SINGLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

CableClub_Text_CantDoubleBattleWithXPlayers_Frlg::
	.string "The DOUBLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

CableClub_Text_NeedFourPlayers_Frlg::
	.string "There must be four players to play\n"
	.string "this Battle Mode.$"

CableClub_Text_PleaseConfirmNumberAndRestart_Frlg::
	.string "Please confirm the number of\n"
	.string "players and start again.$"

Text_TerminateLinkIfYouLeaveRoom_Frlg::
	.string "The link will be terminated if you\n"
	.string "leave the room. Is that okay?$"

Text_TerminateLinkConfirmation_Frlg::
	.string "Terminating link…\n"
	.string "You will be escorted out of\l"
	.string "the room. Please wait.$"

Text_TrainerTooBusyToNotice_Frlg::
	.string "This TRAINER is too busy to\n"
	.string "notice…$"

Text_LookedAtPlayersTrainerCard_Frlg::
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!$"

Text_LookedAtPlayersTrainerCardColored_Frlg::
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"

Text_TakeSeatStartBattle_Frlg::
	.string "Please take your seat and start\n"
	.string "your battle.$"

Text_TakeSeatStartTrade_Frlg::
	.string "Please take your seat and start\n"
	.string "your trade.$"

@ Unused, leftover from RS
RecordCorner_Text_ThanksForComing_Frlg::
	.string "ごりよう　ありがとう　ございました$"

CableClub_Text_TrainerCardDataOverwritten_Frlg::
	.string "The TRAINER CARD data will\n"
	.string "be overwritten.$"

CableClub_Text_HopeToSeeYouAgain_Frlg::
	.string "I hope to see you again!$"

CableClub_Text_NotSetUpForFarAwayRegion_Frlg::
	.string "I'm awfully sorry.\p"
	.string "We're not set up to conduct trades\n"
	.string "with TRAINERS far away in another\l"
	.string "region yet…$"

CableClub_Text_OtherTrainerNotReady_Frlg::
	.string "The other TRAINER is not ready.$"

CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg::
	.string "You have at least one POKéMON\n"
	.string "that can't be taken.$"

CableClub_Text_AdapterNotConnected_Frlg::
	.string "The Wireless Adapter is not\n"
	.string "connected properly.$"

CableClub_Text_ParticipantsStepUpToCounter_Frlg::
	.string "Participants are asked to step up\n"
	.string "to the reception counter.$"

@ Unused, translated in Emerald
CableClub_Text_Hello_Frlg::
	.string "こんにちは！$"

@ Unused, translated in Emerald
CableClub_Text_PleaseWait_Frlg::
	.string "しょうしょう　おまちください$"

CableClub_Text_YouMayTradeHere_Frlg::
	.string "You may trade your POKéMON here\n"
	.string "with another TRAINER.$"

CableClub_Text_YouMayBattleHere_Frlg::
	.string "You may battle with your friends\n"
	.string "here.$"

CableClub_Text_CanMakeBerryPowder_Frlg::
	.string "Two to five TRAINERS can make\n"
	.string "BERRY POWDER together.$"

@ Unused, Record Mix nopped
CableClub_Text_CanMixRecords_Frlg::
	.string "ワイヤレス　クラブでの\n"
	.string "あそびかたを　せつめいします$"

CableClub_Text_CancelSelectedItem_Frlg::
	.string "Cancels the selected MENU item.$"

@ Unused, translated in Emerald
CableClub_Text_WhichBattleMode_Frlg::
	.string "どちらの　しょうぶに　しますか？$"

@ Unused, translated in Emerald
CableClub_Text_ReturnsToPreviousStep_Frlg::
	.string "ひとつ　まえに　もどります$"

CableClub_Text_NeedBerryForBerryCrush_Frlg::
	.string "To use the BERRY CRUSH service,\n"
	.string "you must have at least one BERRY.$"

CableClub_Text_NeedTwoMonsForUnionRoom_Frlg::
	.string "To enter the UNION ROOM, you must\n"
	.string "have at least two POKéMON.$"

CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg::
	.string "No POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY may enter the UNION ROOM.$"

CableClub_Text_UnionRoomAdapterNotConnected_Frlg::
	.string "This is the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM.\p"
	.string "Unfortunately, your Wireless\n"
	.string "Adapter is not connected properly.\p"
	.string "Please do come again.$"

Text_PlayerIsPlayingRightNowGoForIt_Frlg::
	.string "It appears as if {STR_VAR_1} is playing\n"
	.string "right now.\l"
	.string "Go for it!$"

Text_DescribeWhichGame_Frlg::
	.string "I can explain game rules to you,\n"
	.string "if you'd like.\p"
	.string "Which game should I describe?$"

Text_PokemonJumpInfo_Frlg::
	.string "“POKéMON JUMP”\p"
	.string "Make your POKéMON skip the\n"
	.string "VINE WHIP rope with the A Button.\p"
	.string "Only mini POKéMON around 28 inches\n"
	.string "or less may participate.\p"
	.string "POKéMON that only swim, burrow, or\n"
	.string "fly are not good at jumping.\p"
	.string "As a result, those POKéMON may not\n"
	.string "participate.\p"
	.string "Good things happen if everyone\n"
	.string "jumps in time.$"

Text_DodrioBerryPickingInfo_Frlg::
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Command DODRIO's three heads to\n"
	.string "catch falling BERRIES.\p"
	.string "Press right, up, or left on the\n"
	.string "{PLUS} Control Pad to move the heads.\p"
	.string "To play this game, you must have\n"
	.string "a DODRIO.$"

Text_TalkToManToPlay_Frlg::
	.string "If you want to play a game,\n"
	.string "please tell the man beside me.$"

Text_WelcomeCanYouWait_Frlg::
	.string "Hi, welcome!\n"
	.string "You can play games over the\l"
	.string "Wireless Communication System.\p"
	.string "Can you wait just a little bit?$"

CableClub_Text_ComeAgain_Frlg::
	.string "All right, come again!$"

Text_AdapterNotConnectedMinigame_Frlg::
	.string "The Wireless Adapter isn't\n"
	.string "connected.\p"
	.string "Come back when it's hooked up!$"

Text_PlayWhichGame_Frlg::
	.string "All right, which game did you want\n"
	.string "to play?$"

Text_EnterWhichPokemon_Frlg::
	.string "Which POKéMON would you like to\n"
	.string "enter?$"

Text_AllGoodToGo_Frlg::
	.string "Okay, you're all good to go.\n"
	.string "Don't let the others beat you!$"

@ Unused, translated in Emerald
Text_LeavingDoComeAgain_Frlg::
	.string "きょうは　けえるのか？\n"
	.string "またこいよ！$"

EventScript_ExplainPokemonJumpRequirements_Frlg::
	.string "It doesn't look like you have any\n"
	.string "POKéMON that you can enter…\p"
	.string "Would you like me to explain what\n"
	.string "kinds of POKéMON can enter?$"

Text_ShortJumpingPokemonAllowed_Frlg::
	.string "“POKéMON JUMP” is open to POKéMON\n"
	.string "around 28 inches or less.\p"
	.string "What you can't enter are those\n"
	.string "POKéMON that can't jump.\p"
	.string "You know, like POKéMON that only\n"
	.string "swim, burrow, or fly.\p"
	.string "That's all you need to know.$"

Text_OnlyDodrioAllowed_Frlg::
	.string "“DODRIO BERRY-PICKING”…\n"
	.string "Well, the name says it all.\p"
	.string "You have to have a DODRIO to play\n"
	.string "this game.$"

@ Unused, translated in Emerald
Text_RetryFromStartPlease_Frlg::
	.string "もういちど　はじめから\n"
	.string "やりなおして　みて　くれ$"

CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg::
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB DIRECT CORNER.\p"
	.string "You may interact directly with\n"
	.string "your friends here.\p"
	.string "Which room would you like to\n"
	.string "enter?$"

CableClub_Text_TradePokemon_Frlg::
	.string "Would you like to trade POKéMON?$"

CableClub_Text_PlayWhichBattleMode_Frlg::
	.string "Which Battle Mode would you like\n"
	.string "to play?$"

CableClub_Text_UseBerryCrush_Frlg::
	.string "Would you like to use the\n"
	.string "BERRY CRUSH System?$"

CableClub_Text_ExplainBattleModes_Frlg::
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

CableClub_Text_ChooseGroupLeaderOfTwo_Frlg::
	.string "Please decide which of you two\n"
	.string "will become the LEADER.\p"
	.string "The other player must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_ChooseGroupLeaderOfFour_Frlg::
	.string "Please decide which of you four\n"
	.string "will become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_ChooseGroupLeader_Frlg::
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

CableClub_Text_WelcomeUnionRoomEnter_Frlg::
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB UNION ROOM.\p"
	.string "You may interact directly with\n"
	.string "other TRAINERS here, some of\l"
	.string "whom you may not even know.\p"
	.string "Would you like to enter the ROOM?$"

CableClub_Text_UnionRoomInfo_Frlg::
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

CableClub_Text_EnjoyUnionRoom_Frlg::
	.string "I hope you enjoy your time in\n"
	.string "the UNION ROOM.$"

CableClub_Text_FirstTimeRightThisWay_Frlg::
	.string "Hello!\n"
	.string "My name is TEALA.\p"
	.string "This must be your first time\n"
	.string "up here.\p"
	.string "I'll show you how the Wireless\n"
	.string "Communication System works.\p"
	.string "First, I need to show you this\n"
	.string "floor of our POKéMON CENTER.\p"
	.string "Right this way, please.$"

CableClub_Text_ExplainWirelessClubFirstTime_Frlg::
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

CableClub_Text_AskAboutLinking_Frlg::
	.string "Hello, {PLAYER}!\p"
	.string "It's me, TEALA, the POKéMON\n"
	.string "CENTER 2F attendant.\p"
	.string "Is there something you needed to\n"
	.string "ask me about linking?$"

CableClub_Text_ExplainWirelessClub_Frlg::
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

CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg::
	.string "I hope you enjoy the Wireless\n"
	.string "Communication System.$"

Text_WirelessClubUndergoingAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The POKéMON WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

Text_AppearsToBeUndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"
