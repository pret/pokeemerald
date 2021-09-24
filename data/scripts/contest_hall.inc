.set LOCALID_MC, 1
.set LOCALID_JUDGE, 2
.set LOCALID_CONTESTANT_1, 3
.set LOCALID_CONTESTANT_2, 4
.set LOCALID_CONTESTANT_3, 5
.set LOCALID_AUDIENCE_1, 6
.set LOCALID_AUDIENCE_3, 7
.set LOCALID_AUDIENCE_4, 8
.set LOCALID_AUDIENCE_5, 9
.set LOCALID_AUDIENCE_6, 10
.set LOCALID_AUDIENCE_7, 11
.set LOCALID_AUDIENCE_2, 12
.set LOCALID_POKEBALL, 13
.set LOCALID_CONTESTANT_4, 14
.set LOCALID_ARTIST, 15

@ Either ends or returns to EventScript_ContestReceptionist after submitting a contest entry
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist::
	lock
	faceplayer
	compare VAR_CONTEST_PRIZE_PICKUP, 0
	goto_if_ne LilycoveCity_ContestLobby_EventScript_PickUpPrize
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
	goto LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ReceptionWelcome::
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_GivePokeblockCase::
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_PickUpPrize::
	msgbox LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter
	end

LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter::
	giveitem ITEM_LUXURY_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter::
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_AskEnterContest::
	message LilycoveCity_ContestLobby_Text_EnterContest1
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ChooseContestRank
	case 1, LilycoveCity_ContestLobby_EventScript_ContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ContestInfo::
	message LilycoveCity_ContestLobby_Text_WhichTopic1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainContests
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainContestTypes
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainContestRanks
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainContests::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestTypes::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestRanks::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelEnterContest::
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestMon::
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon1, MSGBOX_DEFAULT
	choosecontestmon
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	special TryEnterContestMon
	compare VAR_RESULT, CANT_ENTER_CONTEST
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterLowRank
	compare VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMon
	compare VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon
	compare VAR_RESULT, CANT_ENTER_CONTEST_EGG
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterEgg
	compare VAR_RESULT, CANT_ENTER_CONTEST_FAINTED
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterFainted
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestRank::
	message LilycoveCity_ContestLobby_Text_EnterWhichRank
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EnterNormalRank
	case 1, LilycoveCity_ContestLobby_EventScript_EnterSuperRank
	case 2, LilycoveCity_ContestLobby_EventScript_EnterHyperRank
	case 3, LilycoveCity_ContestLobby_EventScript_EnterMasterRank
	case 4, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_EnterNormalRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterSuperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterHyperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterMasterRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

@ The multichoice selection IDs are equal to the CATEGORY values
@ So rather than list the cases they just copy VAR_RESULT for a valid selection into VAR_CONTEST_CATEGORY
LilycoveCity_ContestLobby_EventScript_ChooseContestType::
	message LilycoveCity_ContestLobby_Text_EnterWhichContest1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterLowRank::
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ Unused
LilycoveCity_ContestLobby_EventScript_ConfirmEntry::
	msgbox LilycoveCity_ContestLobby_Text_ConfirmContestMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon::
	msgbox LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterEgg::
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

LilycoveCity_ContestLobby_EventScript_CantEnterFainted::
	msgbox LilycoveCity_ContestLobby_Text_MonInNoConditionForContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ The return here is back to LilycoveCity_ContestLobby_EventScript_ContestReceptionist
LilycoveCity_ContestLobby_EventScript_EnterMon::
	msgbox LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_CONTEST_HALL_STATE, 1
	return

ContestHall_EventScript_DoContest::
	special LinkContestTryShowWirelessIndicator
	setvar VAR_0x8006, 0
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4FaceUp
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkDown
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_GetContestRankStringId
	call ContestHall_EventScript_GetContestCategory
	call ContestHall_EventScript_ContestGettingStarted
	call ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_DoContestAppeals
	call ContestHall_EventScript_ContestResults
	call ContestHall_EventScript_GetWinnerObjEventId
	call ContestHall_EventScript_CongratulateWinner
	call ContestHall_EventScript_AudienceLookAround
	call ContestHall_EventScript_GiveWinnerPrize
	setvar VAR_CONTEST_HALL_STATE, 2
	return

ContestHall_EventScript_GetContestRankStringId::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, ContestHall_EventScript_GetNormalStringId
	case CONTEST_RANK_SUPER, ContestHall_EventScript_GetSuperStringId
	case CONTEST_RANK_HYPER, ContestHall_EventScript_GetHyperStringId
	case CONTEST_RANK_MASTER, ContestHall_EventScript_GetMasterStringId
	return

ContestHall_EventScript_GetNormalStringId::
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

ContestHall_EventScript_GetSuperStringId::
	setvar VAR_0x8009, STDSTRING_SUPER
	return

ContestHall_EventScript_GetHyperStringId::
	setvar VAR_0x8009, STDSTRING_HYPER
	return

ContestHall_EventScript_GetMasterStringId::
	setvar VAR_0x8009, STDSTRING_MASTER
	return

@ This whole switch is equivalent to copyvar VAR_0x8008, VAR_CONTEST_CATEGORY
ContestHall_EventScript_GetContestCategory::
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_GetCategoryCool
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_GetCategoryBeauty
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_GetCategoryCute
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_GetCategorySmart
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_GetCategoryTough
	return

ContestHall_EventScript_GetCategoryCool::
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

ContestHall_EventScript_GetCategoryBeauty::
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

ContestHall_EventScript_GetCategoryCute::
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

ContestHall_EventScript_GetCategorySmart::
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

ContestHall_EventScript_GetCategoryTough::
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

ContestHall_EventScript_ContestGettingStarted::
	buffercontesttypestring 1, VAR_0x8008
	bufferstdstring 2, VAR_0x8009
	call ContestHall_EventScript_GettingStarted
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_MCBackUp
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_GettingStarted::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_GettingStartedLink
	lockall
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GettingStartedLink::
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_GettingStartedWireless
	messageautoscroll ContestHall_Text_GettingStartedParticipantsAsFollowsLink
	waitmessage
	return

ContestHall_EventScript_GettingStartedWireless::
	messageautoscroll ContestHall_Text_GettingStartedWireless
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ParticipantsAsFollows
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ShowContestMons::
	call ContestHall_EventScript_ContestantWalkToCenter
	call ContestHall_EventScript_ShowContestMonPic
	call ContestHall_EventScript_AudienceHeartEmotes
	call ContestHall_EventScript_AudienceReactToContestant
	call ContestHall_EventScript_ContestantReturn
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_TryWaitForLink
	addvar VAR_0x8006, 1
	compare VAR_0x8006, CONTESTANT_COUNT
	goto_if_ne ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_AudienceVote
	setvar VAR_TEMP_1, 6
	return

ContestHall_EventScript_TryWaitForLink::
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_WaitForLink
	return

ContestHall_EventScript_WaitForLink::
	special LinkContestWaitForConnection
	waitstate
	return

ContestHall_EventScript_ContestantWalkToCenter::
	compare VAR_0x8006, 0
	goto_if_eq ContestHall_EventScript_Player1WalkToCenter
	compare VAR_0x8006, 1
	goto_if_eq ContestHall_EventScript_Player2WalkToCenter
	compare VAR_0x8006, 2
	goto_if_eq ContestHall_EventScript_Player3WalkToCenter
	compare VAR_0x8006, 3
	goto_if_eq ContestHall_EventScript_Player4WalkToCenter
	return

ContestHall_EventScript_Player1WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_1, ContestHall_Movement_Player1WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_Player2WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_2, ContestHall_Movement_Player2WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_Player3WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_3, ContestHall_Movement_Player3WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_Player4WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_ShowContestMonPic::
	special BufferContestTrainerAndMonNames
	addvar VAR_0x8006, 1
	buffernumberstring 1, VAR_0x8006
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_CheckIfContestWithRSPlayer
	addobject LOCALID_POKEBALL
	playse SE_LEDGE
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	addvar VAR_0x8006, -1
	playse SE_BALL_OPEN
	special ShowContestEntryMonPic
	call ContestHall_EventScript_EntryXTrainersMon
	return

ContestHall_EventScript_EntryXTrainersMon::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_EntryXTrainersMonLink
	message ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_EntryXTrainersMonLink::
	messageautoscroll ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_AudienceVote::
	call ContestHall_EventScript_AudienceWillVote
	call ContestHall_EventScript_VotingUnderWay
	playse SE_M_ENCORE2
	waitmessage
	call ContestHall_EventScript_AudienceLookAround
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge2
	waitmovement 0
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeFaceMC
	waitmovement 0
	delay 20
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
	applymovement LOCALID_JUDGE, ContestHall_Movement_FaceContestants
	waitmovement 0
	return

ContestHall_EventScript_AudienceWillVote::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_AudienceWillVoteLink
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
	return

ContestHall_EventScript_AudienceWillVoteLink::
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_AudienceWillVoteWireless
	messageautoscroll ContestHall_Text_SeenContestantsAudienceWillVote
	waitmessage
	return

ContestHall_EventScript_AudienceWillVoteWireless::
	messageautoscroll ContestHall_Text_WeveSeenContestants
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_AudienceWillVote
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetVotingBegin
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_VotingUnderWay::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_VotingUnderWayLink
	message ContestHall_Text_VotingUnderWay
	return

ContestHall_EventScript_VotingUnderWayLink::
	messageautoscroll ContestHall_Text_VotingUnderWay
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_AudienceReactToContestant::
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	playse SE_M_ENCORE2
	call ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCLookAtJudge
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkInPlaceDown
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeLookAtMC
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	return

@ For below VAR_TEMP_0 is the number of heart emotes to try to display in the audience
@ The number of hearts to try to display is based on the condition of the presented pokemon and the rank
@ For each heart to display a random audience member is chosen, and a new one chosen if they already displayed a heart
@ VAR_TEMP_1 through VAR_TEMP_8 represent each of the 8 audience members that are actual object events
@    and are set to 9 if they havent displayed a heart yet, and 1 if they have
ContestHall_EventScript_AudienceHeartEmotes::
	special GetContestMonCondition
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsNormal
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsSuper
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsHyper
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsMaster
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsLink
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	compare VAR_TEMP_0, 0
	call_if_gt ContestHall_EventScript_DisplayHearts
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	return

ContestHall_EventScript_DisplayHearts::
	setvar VAR_RESULT, 8
	special GenerateContestRand
	compare VAR_RESULT, 0
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember1
	compare VAR_RESULT, 1
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember2
	compare VAR_RESULT, 2
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember3
	compare VAR_RESULT, 3
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember4
	compare VAR_RESULT, 4
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember5
	compare VAR_RESULT, 5
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember6
	compare VAR_RESULT, 6
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember7
	compare VAR_RESULT, 7
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember8
	compare VAR_TEMP_0, 0  @ Still more hearts to display
	goto_if_gt ContestHall_EventScript_DisplayHearts
	waitmovement 0
	return

ContestHall_EventScript_GetNumberOfHeartsNormal::
	compare VAR_0x8004, 80
	goto_if_gt ContestHall_EventScript_Set8Hearts
	compare VAR_0x8004, 70
	goto_if_gt ContestHall_EventScript_Set7Hearts
	compare VAR_0x8004, 60
	goto_if_gt ContestHall_EventScript_Set6Hearts
	compare VAR_0x8004, 50
	goto_if_gt ContestHall_EventScript_Set5Hearts
	compare VAR_0x8004, 40
	goto_if_gt ContestHall_EventScript_Set4Hearts
	compare VAR_0x8004, 30
	goto_if_gt ContestHall_EventScript_Set3Hearts
	compare VAR_0x8004, 20
	goto_if_gt ContestHall_EventScript_Set2Hearts
	compare VAR_0x8004, 10
	goto_if_gt ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsSuper::
	compare VAR_0x8004, 230
	goto_if_gt ContestHall_EventScript_Set8Hearts
	compare VAR_0x8004, 210
	goto_if_gt ContestHall_EventScript_Set7Hearts
	compare VAR_0x8004, 190
	goto_if_gt ContestHall_EventScript_Set6Hearts
	compare VAR_0x8004, 170
	goto_if_gt ContestHall_EventScript_Set5Hearts
	compare VAR_0x8004, 150
	goto_if_gt ContestHall_EventScript_Set4Hearts
	compare VAR_0x8004, 130
	goto_if_gt ContestHall_EventScript_Set3Hearts
	compare VAR_0x8004, 110
	goto_if_gt ContestHall_EventScript_Set2Hearts
	compare VAR_0x8004, 90
	goto_if_gt ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsHyper::
	compare VAR_0x8004, 380
	goto_if_gt ContestHall_EventScript_Set8Hearts
	compare VAR_0x8004, 350
	goto_if_gt ContestHall_EventScript_Set7Hearts
	compare VAR_0x8004, 320
	goto_if_gt ContestHall_EventScript_Set6Hearts
	compare VAR_0x8004, 290
	goto_if_gt ContestHall_EventScript_Set5Hearts
	compare VAR_0x8004, 260
	goto_if_gt ContestHall_EventScript_Set4Hearts
	compare VAR_0x8004, 230
	goto_if_gt ContestHall_EventScript_Set3Hearts
	compare VAR_0x8004, 200
	goto_if_gt ContestHall_EventScript_Set2Hearts
	compare VAR_0x8004, 170
	goto_if_gt ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsMaster::
	compare VAR_0x8004, 600
	goto_if_gt ContestHall_EventScript_Set8Hearts
	compare VAR_0x8004, 560
	goto_if_gt ContestHall_EventScript_Set7Hearts
	compare VAR_0x8004, 520
	goto_if_gt ContestHall_EventScript_Set6Hearts
	compare VAR_0x8004, 480
	goto_if_gt ContestHall_EventScript_Set5Hearts
	compare VAR_0x8004, 440
	goto_if_gt ContestHall_EventScript_Set4Hearts
	compare VAR_0x8004, 400
	goto_if_gt ContestHall_EventScript_Set3Hearts
	compare VAR_0x8004, 360
	goto_if_gt ContestHall_EventScript_Set2Hearts
	compare VAR_0x8004, 320
	goto_if_gt ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsLink::
	compare VAR_0x8004, 600
	goto_if_gt ContestHall_EventScript_Set8Hearts
	compare VAR_0x8004, 550
	goto_if_gt ContestHall_EventScript_Set7Hearts
	compare VAR_0x8004, 500
	goto_if_gt ContestHall_EventScript_Set6Hearts
	compare VAR_0x8004, 450
	goto_if_gt ContestHall_EventScript_Set5Hearts
	compare VAR_0x8004, 400
	goto_if_gt ContestHall_EventScript_Set4Hearts
	compare VAR_0x8004, 300
	goto_if_gt ContestHall_EventScript_Set3Hearts
	compare VAR_0x8004, 200
	goto_if_gt ContestHall_EventScript_Set2Hearts
	compare VAR_0x8004, 100
	goto_if_gt ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_Set1Heart::
	setvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_Set2Hearts::
	setvar VAR_TEMP_0, 2
	return

ContestHall_EventScript_Set3Hearts::
	setvar VAR_TEMP_0, 3
	return

ContestHall_EventScript_Set4Hearts::
	setvar VAR_TEMP_0, 4
	return

ContestHall_EventScript_Set5Hearts::
	setvar VAR_TEMP_0, 5
	return

ContestHall_EventScript_Set6Hearts::
	setvar VAR_TEMP_0, 6
	return

ContestHall_EventScript_Set7Hearts::
	setvar VAR_TEMP_0, 7
	return

ContestHall_EventScript_Set8Hearts::
	setvar VAR_TEMP_0, 8
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember1::
	compare VAR_TEMP_1, 1
	goto_if_eq ContestHall_EventScript_AudienceMember1AlreadyEmoted
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember1AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember2::
	compare VAR_TEMP_2, 1
	goto_if_eq ContestHall_EventScript_AudienceMember2AlreadyEmoted
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember2AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember3::
	compare VAR_TEMP_3, 1
	goto_if_eq ContestHall_EventScript_AudienceMember3AlreadyEmoted
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember3AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember4::
	compare VAR_TEMP_4, 1
	goto_if_eq ContestHall_EventScript_Audience4MemberAlreadyEmoted
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_Audience4MemberAlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember5::
	compare VAR_TEMP_5, 1
	goto_if_eq ContestHall_EventScript_AudienceMember5AlreadyEmoted
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember5AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember6::
	compare VAR_TEMP_6, 1
	goto_if_eq ContestHall_EventScript_AudienceMember6AlreadyEmoted
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember6AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember7::
	compare VAR_TEMP_7, 1
	goto_if_eq ContestHall_EventScript_AudienceMember7AlreadyEmoted
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember7AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember8::
	compare VAR_TEMP_8, 1
	goto_if_eq ContestHall_EventScript_AudienceMember8AlreadyEmoted
	applymovement LOCALID_ARTIST, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember8AlreadyEmoted::
	return

ContestHall_EventScript_ContestantReturn::
	closemessage
	release
	removeobject LOCALID_POKEBALL
	special HideContestEntryMonPic
	call ContestHall_EventScript_TryWaitForLink
	switch VAR_0x8006
	case 0, ContestHall_EventScript_Player1WalkBack
	case 1, ContestHall_EventScript_Player2WalkBack
	case 2, ContestHall_EventScript_Player3WalkBack
	case 3, ContestHall_EventScript_Player4WalkBack
	return

ContestHall_EventScript_Player1WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player1WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player2WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player3WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player4WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_DoContestAppeals::
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants2
	waitmovement 0
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_LetsAppeal
	waitmessage
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageLeft
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageRight
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	setvar VAR_TEMP_9, 1
	special LinkContestTryHideWirelessIndicator
	startcontest
	special LinkContestTryShowWirelessIndicator
	setvar VAR_TEMP_9, 0
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageRight
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageLeft
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_LetsAppeal::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_LetsAppealLink
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
	return

ContestHall_EventScript_LetsAppealLink::
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_LetsAppealWireless
	messageautoscroll ContestHall_Text_VotingCompleteLetsAppeal
	waitmessage
	return

ContestHall_EventScript_LetsAppealWireless::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_VotingComplete
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_SecondStageOfJudging
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetsAppeal
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ContestResults::
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThatsItForJudging
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThankYouForAppeals
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge
	waitmovement 0
	call ContestHall_EventScript_JudgeLooksReady
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_WeWillDeclareWinner
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
	waitmovement 0
	closemessage
	releaseall
	special LinkContestTryHideWirelessIndicator
	setvar VAR_TEMP_9, 1
	showcontestresults
	setvar VAR_TEMP_9, 0
	playbgm MUS_CONTEST_WINNER, FALSE
	return

ContestHall_EventScript_ThatsItForJudging::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_ThatsItForJudgingLink
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThatsItForJudgingLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThatsItForJudging
	waitmessage
	delay 30
	return

ContestHall_EventScript_ThankYouForAppeals::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_ThankYouForAppealsLink
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThankYouForAppealsLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThankYouForAppeals
	waitmessage
	delay 30
	return

ContestHall_EventScript_JudgeLooksReady::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_JudgeLooksReadyLink
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
	return

ContestHall_EventScript_JudgeLooksReadyLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_JudgeLooksReady
	waitmessage
	delay 30
	return

ContestHall_EventScript_WeWillDeclareWinner::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_WeWillDeclareWinnerLink
	msgbox ContestHall_Text_WeWillNowDeclareWinner, MSGBOX_DEFAULT
	return

ContestHall_EventScript_WeWillDeclareWinnerLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_WeWillNowDeclareWinner
	waitmessage
	delay 30
	return

ContestHall_EventScript_GetWinnerObjEventId::
	special GetContestWinnerId
	switch VAR_0x8005
	case 0, ContestHall_EventScript_GetPlayer1ObjEventId
	case 1, ContestHall_EventScript_GetPlayer2ObjEventId
	case 2, ContestHall_EventScript_GetPlayer3ObjEventId
	case 3, ContestHall_EventScript_GetPlayer4ObjEventId
	return

ContestHall_EventScript_GetPlayer1ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_GetPlayer2ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_GetPlayer3ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_GetPlayer4ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_CongratulateWinner::
	special BufferContestWinnerTrainerName
	special BufferContestWinnerMonName
	addvar VAR_0x8005, 1
	buffernumberstring 1, VAR_0x8005
	addvar VAR_0x8005, -1
	call ContestHall_EventScript_CongratsWinner
	applymovement VAR_TEMP_3, ContestHall_Movement_WinningPlayerWalkUp
	waitmovement 0
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	return

ContestHall_EventScript_CongratsWinner::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_CongratsWinnerLink
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
	return

ContestHall_EventScript_CongratsWinnerLink::
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
	waitmessage
	return

ContestHall_EventScript_AudienceLookAround::
	addvar VAR_TEMP_1, 1
	lockall
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	call_if_gt ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	delay 30
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	compare VAR_TEMP_1, 4
	goto_if_ne ContestHall_EventScript_AudienceLookAround
	delay 30
	return

ContestHall_EventScript_VObjectAudienceLookAround::
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 28, DIR_EAST
	delay 10
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 25, DIR_NORTH
	turnvobject 27, DIR_NORTH
	turnvobject 28, DIR_NORTH
	delay 10
	turnvobject 1, DIR_NORTH
	turnvobject 3, DIR_NORTH
	turnvobject 5, DIR_NORTH
	turnvobject 7, DIR_NORTH
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 13, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 19, DIR_NORTH
	turnvobject 21, DIR_WEST
	turnvobject 23, DIR_WEST
	turnvobject 24, DIR_WEST
	turnvobject 26, DIR_EAST
	turnvobject 29, DIR_WEST
	turnvobject 30, DIR_WEST
	delay 10
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_NORTH
	turnvobject 29, DIR_NORTH
	turnvobject 30, DIR_NORTH
	delay 10
	return

ContestHall_EventScript_GiveWinnerPrize::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_EndLinkContest
	call ContestHall_EventScript_CheckShouldSkipPrize
	goto_if_set FLAG_TEMP_2, ContestHall_EventScript_SkipPrize
	lockall
	msgbox ContestHall_Text_AcceptYourPrize, MSGBOX_DEFAULT
	releaseall
	call ContestHall_EventScript_WinnerApproachForPrize
	call ContestHall_EventScript_GivePrizeIfWinner
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	call ContestHall_EventScript_AudienceLookAround
	delay 30
	special ShouldReadyContestArtist
	compare VAR_0x8004, TRUE
	goto_if_eq ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_SkipPrize::
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	delay 90
	special ShouldReadyContestArtist
	compare VAR_0x8004, TRUE
	goto_if_eq ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_CheckShouldSkipPrize::
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_CheckPlayerWon
	return

ContestHall_EventScript_CheckPlayerWon::
	special GetContestWinnerId
	compare VAR_0x8005, 3
	goto_if_eq ContestHall_EventScript_CheckRankIsMaster
	return

ContestHall_EventScript_CheckRankIsMaster::
	compare VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto_if_eq ContestHall_EventScript_DontSkipPrize
	setflag FLAG_TEMP_2
	return

ContestHall_EventScript_DontSkipPrize::
	return

@ This flag is never read
ContestHall_EventScript_SetSketchFlag::
	setflag FLAG_CONTEST_SKETCH_CREATED
	return

ContestHall_EventScript_SetReadyForContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

ContestHall_EventScript_EndLinkContest::
	delay 60
	special GetContestPlayerId
	special GetContestWinnerId
	special ShouldReadyContestArtist
	compare VAR_0x8004, TRUE
	goto_if_eq ContestHall_EventScript_SetReadyForLinkContestArtist
	closemessage
	return

ContestHall_EventScript_SetReadyForLinkContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

@ Unused
ContestHall_EventScript_Ret::
	return

ContestHall_EventScript_WinnerApproachForPrize::
	switch VAR_0x8005
	case 0, ContestHall_EventScript_Player1ApproachForPrize
	case 1, ContestHall_EventScript_Player2ApproachForPrize
	case 2, ContestHall_EventScript_Player3ApproachForPrize
	case 3, ContestHall_EventScript_Player4ApproachForPrize
	return

ContestHall_EventScript_Player1ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player1ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player2ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player3ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player4ApproachForPrize
	waitmovement 0
	releaseall
	return

@ In NPC Contests, the player is always entry 4 (id number 3)
ContestHall_EventScript_GivePrizeIfWinner::
	special GetContestWinnerId
	compare VAR_0x8005, 3
	goto_if_eq ContestHall_EventScript_GiveContestPrizes
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GiveContestPrizes::
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	call_if_eq ContestHall_EventScript_SetSketchFlag
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	compare VAR_RESULT, FALSE
	goto_if_eq ContestHall_EventScript_ReceiveContestRibbon
	compare VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto_if_eq ContestHall_EventScript_GiveLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_NoRoomForLuxuryBall::
	lockall
	call Common_EventScript_BagIsFull
	msgbox ContestHall_Text_PickUpPrizeAtCounterLater, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

ContestHall_EventScript_GiveLuxuryBall::
	giveitem ITEM_LUXURY_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq ContestHall_EventScript_NoRoomForLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_ReceiveContestRibbon::
	special GiveMonContestRibbon
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox ContestHall_Text_ConferRibbonAsPrize, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox ContestHall_Text_ReceivedRibbon, MSGBOX_DEFAULT
	waitfanfare
	special BufferContestWinnerMonName
	msgbox ContestHall_Text_PutRibbonOnMon, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_Movement_MCWalkDown:
	walk_down
	step_end

ContestHall_Movement_MCBackUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ContestHall_Movement_MCFaceJudge:
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_Heart:
	emote_heart
	step_end

ContestHall_Movement_FaceContestants:
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WalkStageLeft:
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WalkStageRight:
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WinningPlayerWalkUp:
	walk_up
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_ContestantDelay32:
	delay_16
	delay_16
	step_end

ContestHall_Movement_MCFaceJudge2:
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_JudgeFaceMC:
	walk_in_place_fastest_left
	step_end

ContestHall_Movement_FaceContestants2:
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_Player3ApproachForPrize:
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_Player4ApproachForPrize:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_AudienceMemberLookLeft:
	face_left
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookUp:
	face_up
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookRight:
	face_right
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookDown:
	face_down
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_Player4FaceUp:
	face_up
	step_end

ContestHall_Movement_MCLookAtJudge:
	face_up
	delay_16
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_JudgeLookAtMC:
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_MCWalkInPlaceDown:
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_Player1WalkToCenter:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player1WalkBack:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player2WalkToCenter:
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player2WalkBack:
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player3WalkToCenter:
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player3WalkBack:
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player4WalkToCenter:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player4WalkBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player1ApproachForPrize:
	walk_right
	walk_right
	walk_up
	step_end

ContestHall_Movement_Player2ApproachForPrize:
	walk_up
	step_end

@ IsContestWithRSPlayer has no side effect, so this is nop
ContestHall_EventScript_CheckIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_RetRSPlayer
	return

ContestHall_EventScript_RetRSPlayer::
	return

LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
	return

LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer::
	delay 9
	return

LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase:
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "Pokémon Contests.\p"
	.string "Oh? It appears that you don't have\n"
	.string "a {POKEBLOCK} Case yet.\p"
	.string "In that case, we need to provide you\n"
	.string "with this!$"

LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp:
	.string "Okay, now that we've cleared that\n"
	.string "up…\p"
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "Pokémon Contests.$"

LilycoveCity_ContestLobby_Text_ContestReception:
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "Pokémon Contests.$"

@ Unused
LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests:
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player Pokémon Contests.$"

LilycoveCity_ContestLobby_Text_EnterContest1:
	.string "Would you like to enter your Pokémon\n"
	.string "in our Contests?$"

LilycoveCity_ContestLobby_Text_WhichTopic1:
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_ExplainContests:
	.string "A Pokémon Contest involves four\n"
	.string "Trainers entering one Pokémon each\l"
	.string "in competitive judging.\p"
	.string "A Contest has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the Pokémon using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the Judge and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The Pokémon garnering the highest\n"
	.string "score is declared the winner.$"

LilycoveCity_ContestLobby_Text_ExplainContestTypes:
	.string "There are five kinds of Contests.\p"
	.string "Cool, Beauty, Cute, Smart, and\n"
	.string "Tough are the five categories.\p"
	.string "Choose the Contest that is right for\n"
	.string "the Pokémon you plan to enter.$"

LilycoveCity_ContestLobby_Text_ExplainContestRanks:
	.string "There are four ranks of Pokémon\n"
	.string "Contests.\p"
	.string "Normal, Super, Hyper, and Master\n"
	.string "are the four ranks.\p"
	.string "In the Normal Rank, any Pokémon may\n"
	.string "enter.\p"
	.string "Any Pokémon that won a Normal Rank\n"
	.string "Contest may move up to the Super Rank\l"
	.string "in the same category.\p"
	.string "In the same way, a Super Rank winner\n"
	.string "can move up to the Hyper Rank, and\l"
	.string "a Hyper Rank winner can advance to\l"
	.string "the Master Rank in the same category.\p"
	.string "A Pokémon that won in the Master Rank\n"
	.string "may compete in the Master Rank as\l"
	.string "often as its Trainer wants.$"

LilycoveCity_ContestLobby_Text_EnterWhichRank:
	.string "Which Rank would you like to enter?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest1:
	.string "Which Contest would you like to enter?$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon1:
	.string "Which Pokémon would you like to enter?$"

LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank:
	.string "I'm terribly sorry, but your Pokémon\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart:
	.string "I'm sorry, but an Egg cannot take part\n"
	.string "in a Pokémon Contest.$"

LilycoveCity_ContestLobby_Text_MonInNoConditionForContest:
	.string "Your Pokémon appears to be in no\n"
	.string "condition to take part in a Contest…$"

LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway:
	.string "Oh, but that Ribbon…\p"
	.string "Your Pokémon has won this Contest\n"
	.string "before, hasn't it?\p"
	.string "Would you like to enter it in this\n"
	.string "Contest anyway?$"

LilycoveCity_ContestLobby_Text_ConfirmContestMon:
	.string "Is that your Contest Pokémon?$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4:
	.string "Okay, your Pokémon will be entered\n"
	.string "in this Contest.\p"
	.string "Your Pokémon is Entry No. 4.\n"
	.string "The Contest will begin shortly.$"

LilycoveCity_ContestLobby_Text_ComeThroughHere:
	.string "Please come in through here.\n"
	.string "Good luck!$"

LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize:
	.string "Congratulations! Your Pokémon is the\n"
	.string "Contest winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"

LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater:
	.string "Please come back for your prize\n"
	.string "later on.$"

ContestHall_Text_GettingStartedParticipantsAsFollows:
	.string "MC: Hello! We're just getting started\n"
	.string "with a {STR_VAR_3} Rank Pokémon\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating Trainers and their\n"
	.string "Pokémon are as follows:$"

ContestHall_Text_GettingStartedParticipantsAsFollowsLink:
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked Pokémon\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating Trainers and their\n"
	.string "Pokémon are as follows:$"

ContestHall_Text_EntryXTrainersMon:
	.string "MC: Entry No. {STR_VAR_2}!\n"
	.string "{STR_VAR_1}'s {STR_VAR_3}!$"

ContestHall_Text_SeenContestantsAudienceWillVote:
	.string "MC: We've just seen the four Pokémon\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!\p"
	.string "The audience will vote on their\n"
	.string "favorite Pokémon contestants.\p"
	.string "Without any further ado, let the\n"
	.string "voting begin!$"

ContestHall_Text_VotingUnderWay:
	.string "Voting under way…$"

ContestHall_Text_VotingCompleteLetsAppeal:
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!\p"
	.string "The second stage of judging is the\n"
	.string "much anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!\p"
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"

ContestHall_Text_ThatsItForJudging:
	.string "MC: That's it for judging!$"

ContestHall_Text_ThankYouForAppeals:
	.string "Thank you all for a most wonderful\n"
	.string "display of quality appeals!\p"
	.string "This concludes all judging!\n"
	.string "Thank you for your fine efforts!$"

ContestHall_Text_JudgeLooksReady:
	.string "Now, all that remains is the pulse-\n"
	.string "pounding proclamation of the winner.\p"
	.string "The Judge looks ready to make\n"
	.string "the announcement!$"

ContestHall_Text_WeWillNowDeclareWinner:
	.string "Judge: We will now declare the winner!$"

ContestHall_Text_CongratsTrainerXandMon:
	.string "MC: Entry No. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
	.string "congratulations!$"

ContestHall_Text_CongratsPleaseCompeteAgain:
	.string "MC: Congratulations!\n"
	.string "Please do compete again!$"

ContestHall_Text_AcceptYourPrize:
	.string "MC: Here you are!\n"
	.string "Please accept your prize!$"

ContestHall_Text_ConferRibbonAsPrize:
	.string "We confer on you this Ribbon\n"
	.string "as your prize!$"

ContestHall_Text_ReceivedRibbon:
	.string "{PLAYER} received a Ribbon.$"

ContestHall_Text_PutRibbonOnMon:
	.string "{PLAYER} put the Ribbon on\n"
	.string "{STR_VAR_1}.$"

ContestHall_Text_PickUpPrizeAtCounterLater:
	.string "Please pick up your prize at\n"
	.string "the reception counter later.\l"
	.string "Please do compete again!$"

@ Unused
ContestHall_Text_OnlyRegister4Players:
	.string "I only register four players for\n"
	.string "Pokémon Contests.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same Contest.\p"
	.string "Would you like to take part?$"

LilycoveCity_ContestLobby_Text_ProgressWillBeSaved:
	.string "Before entering a Contest, your\n"
	.string "progress will be saved.$"

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime:
	.string "We hope you will participate another\n"
	.string "time.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterContest2:
	.string "Would you like to enter a Contest?$"

@ Unused
LilycoveCity_ContestLobby_Text_Explain4PlayerContest:
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same Contest\n"
	.string "as your fellow contestants.\p"
	.string "The Contest begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual Contest rules\n"
	.string "apply.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichContest2:
	.string "Which Contest would you like to enter?$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichPokemon2:
	.string "Which Pokémon would you like to enter?$"

LilycoveCity_ContestLobby_Text_Transmitting:
	.string "Transmitting…$"

LilycoveCity_ContestLobby_Text_TransmissionError:
	.string "Transmission error…$"

LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest:
	.string "You may have chosen a different\n"
	.string "Contest than another player.$"

LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice:
	.string "You may have made a different\n"
	.string "choice than another player.$"

LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel:
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

@ Unused
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2:
	.string "We hope you will participate another\n"
	.string "time.$"

@ Unused
LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain:
	.string "Transmission error.\n"
	.string "Please try again.$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX:
	.string "Your Pokémon will be entered in\n"
	.string "the Contest.\p"
	.string "Your Pokémon is Entry No. {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_ContestBeginShortly:
	.string "The Contest will begin shortly.$"

LilycoveCity_ContestLobby_Text_LinkContestReception:
	.string "Welcome! This is the Pokémon Contest\n"
	.string "link reception counter.\p"
	.string "You may enter Contests together with\n"
	.string "one or more friends.$"

LilycoveCity_ContestLobby_Text_WhichTopic2:
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_EnterContest3:
	.string "Would you like to enter a Contest?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest3:
	.string "Which Contest would you like to enter?$"

LilycoveCity_ContestLobby_Text_MonInNoCondition2:
	.string "Your Pokémon appears to be in no\n"
	.string "condition to take part in a Contest…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart2:
	.string "I'm sorry, but an Egg cannot take part\n"
	.string "in a Pokémon Contest.$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon3:
	.string "Which Pokémon would you like to enter?$"

LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader:
	.string "Please decide which of you will\n"
	.string "become the Group Leader.\p"
	.string "The other players must then choose\n"
	.string "“Join Group.”$"

LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode:
	.string "At least one player has entered using\n"
	.string "the 4-player reception counter.\p"
	.string "There must be four players connected\n"
	.string "using a GBA Game Link cable.\p"
	.string "When the four players are ready,\n"
	.string "select G-Mode (Global Mode),\l"
	.string "then register to enter again, please.$"

LilycoveCity_ContestLobby_Text_ExplainLinkContest:
	.string "This is a Contest for two to four\n"
	.string "players linked using a Wireless\l"
	.string "Adapter or a GBA Game Link cable.\p"
	.string "Participants are first asked to choose\n"
	.string "the mode they wish to enter.\p"
	.string "There are two different modes.\p"
	.string "E-Mode (Emerald Mode) is for\n"
	.string "two to four players, each with a\l"
	.string "Pokémon Emerald Game Pak.\p"
	.string "G-Mode (Global Mode) is only for\n"
	.string "four players, each with a Pokémon\l"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The players should discuss which mode\n"
	.string "they want, then choose the same mode.\p"
	.string "Once all the players have chosen\n"
	.string "the same Contest in the same mode,\l"
	.string "the entry registration is complete.\p"
	.string "After that, a Contest will start in\n"
	.string "the usual manner.$"

LilycoveCity_ContestLobby_Text_ExplainEMode:
	.string "In E-Mode (Emerald Mode),\n"
	.string "a Link Contest can be held with\l"
	.string "two to four players. Each player must\l"
	.string "have a Pokémon Emerald Game Pak.\p"
	.string "The players must be linked with each\n"
	.string "other using Wireless Adapters or\l"
	.string "GBA Game Link cables.\p"
	.string "If there are fewer than four players,\n"
	.string "Trainers in the hall will join to fill\l"
	.string "the 4-player Contest lineup.\p"
	.string "Please be aware that E-Mode is not\n"
	.string "available in Pokémon Ruby or Sapphire.$"

LilycoveCity_ContestLobby_Text_ExplainGMode:
	.string "G-Mode (Global Mode) is specifically\n"
	.string "for four players who are linked using\l"
	.string "GBA Game Link cables.\p"
	.string "Each player must have a Pokémon\n"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The Contest starts after all players\n"
	.string "choose G-Mode (Pokémon Emerald) or\l"
	.string "enter through the 4-player reception\l"
	.string "counter (Pokémon Ruby or Sapphire).$"

LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode:
	.string "I'm terribly sorry.\p"
	.string "G-Mode does not function\n"
	.string "with Wireless Adapters.\p"
	.string "Please select E-Mode or try\n"
	.string "again using a GBA Game Link cable.$"

LilycoveCity_ContestLobby_Text_WhichContestMode:
	.string "Which Contest Mode would you like\n"
	.string "to enter?$"

ContestHall_Text_GettingStartedWireless:
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked Pokémon\l"
	.string "{STR_VAR_2}!$"

ContestHall_Text_ParticipantsAsFollows:
	.string "The participating Trainers and their\n"
	.string "Pokémon are as follows:$"

ContestHall_Text_WeveSeenContestants:
	.string "MC: We've just seen the four Pokémon\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!$"

ContestHall_Text_AudienceWillVote:
	.string "The audience will vote on their\n"
	.string "favorite Pokémon contestants.$"

ContestHall_Text_LetVotingBegin:
	.string "Without any further ado,\n"
	.string "let the voting begin!$"

ContestHall_Text_VotingComplete:
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!$"

ContestHall_Text_SecondStageOfJudging:
	.string "The second stage of judging is\n"
	.string "the much-anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!$"

ContestHall_Text_LetsAppeal:
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"
