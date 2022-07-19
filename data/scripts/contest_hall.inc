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
	goto_if_ne VAR_CONTEST_PRIZE_PICKUP, 0, LilycoveCity_ContestLobby_EventScript_PickUpPrize
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
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
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
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LilycoveCity_ContestLobby_EventScript_CantEnterLowRank
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, LilycoveCity_ContestLobby_EventScript_EnterMon
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LilycoveCity_ContestLobby_EventScript_CantEnterEgg
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LilycoveCity_ContestLobby_EventScript_CantEnterFainted
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
	buffercontestname STR_VAR_2, VAR_0x8008
	bufferstdstring STR_VAR_3, VAR_0x8009
	call ContestHall_EventScript_GettingStarted
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_MCBackUp
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_GettingStarted::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GettingStartedLink
	lockall
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GettingStartedLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_GettingStartedWireless
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
	goto_if_ne VAR_0x8006, CONTESTANT_COUNT, ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_AudienceVote
	setvar VAR_TEMP_1, 6
	return

ContestHall_EventScript_TryWaitForLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_WaitForLink
	return

ContestHall_EventScript_WaitForLink::
	special LinkContestWaitForConnection
	waitstate
	return

ContestHall_EventScript_ContestantWalkToCenter::
	goto_if_eq VAR_0x8006, 0, ContestHall_EventScript_Player1WalkToCenter
	goto_if_eq VAR_0x8006, 1, ContestHall_EventScript_Player2WalkToCenter
	goto_if_eq VAR_0x8006, 2, ContestHall_EventScript_Player3WalkToCenter
	goto_if_eq VAR_0x8006, 3, ContestHall_EventScript_Player4WalkToCenter
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
	buffernumberstring STR_VAR_2, VAR_0x8006
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EntryXTrainersMonLink
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_AudienceWillVoteLink
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
	return

ContestHall_EventScript_AudienceWillVoteLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_AudienceWillVoteWireless
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_VotingUnderWayLink
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
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_GetNumberOfHeartsNormal
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_GetNumberOfHeartsSuper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_GetNumberOfHeartsHyper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_GetNumberOfHeartsMaster
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GetNumberOfHeartsLink
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	call_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts
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
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_TryDisplayHeartAudienceMember1
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_TryDisplayHeartAudienceMember2
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_TryDisplayHeartAudienceMember3
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_TryDisplayHeartAudienceMember4
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_TryDisplayHeartAudienceMember5
	call_if_eq VAR_RESULT, 5, ContestHall_EventScript_TryDisplayHeartAudienceMember6
	call_if_eq VAR_RESULT, 6, ContestHall_EventScript_TryDisplayHeartAudienceMember7
	call_if_eq VAR_RESULT, 7, ContestHall_EventScript_TryDisplayHeartAudienceMember8
	goto_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts  @ Still more hearts to display
	waitmovement 0
	return

ContestHall_EventScript_GetNumberOfHeartsNormal::
	goto_if_gt VAR_0x8004, 80, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 70, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 60, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 50, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 40, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 30, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 20, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 10, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsSuper::
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 210, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 190, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 150, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 130, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 110, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 90, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsHyper::
	goto_if_gt VAR_0x8004, 380, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 350, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 290, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 260, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsMaster::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 560, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 520, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 480, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 440, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 360, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsLink::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 550, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 500, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 450, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 300, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 100, ContestHall_EventScript_Set1Heart
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
	goto_if_eq VAR_TEMP_1, 1, ContestHall_EventScript_AudienceMember1AlreadyEmoted
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember1AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember2::
	goto_if_eq VAR_TEMP_2, 1, ContestHall_EventScript_AudienceMember2AlreadyEmoted
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember2AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember3::
	goto_if_eq VAR_TEMP_3, 1, ContestHall_EventScript_AudienceMember3AlreadyEmoted
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember3AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember4::
	goto_if_eq VAR_TEMP_4, 1, ContestHall_EventScript_Audience4MemberAlreadyEmoted
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_Audience4MemberAlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember5::
	goto_if_eq VAR_TEMP_5, 1, ContestHall_EventScript_AudienceMember5AlreadyEmoted
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember5AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember6::
	goto_if_eq VAR_TEMP_6, 1, ContestHall_EventScript_AudienceMember6AlreadyEmoted
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember6AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember7::
	goto_if_eq VAR_TEMP_7, 1, ContestHall_EventScript_AudienceMember7AlreadyEmoted
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember7AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember8::
	goto_if_eq VAR_TEMP_8, 1, ContestHall_EventScript_AudienceMember8AlreadyEmoted
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_LetsAppealLink
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
	return

ContestHall_EventScript_LetsAppealLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_LetsAppealWireless
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThatsItForJudgingLink
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThatsItForJudgingLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThatsItForJudging
	waitmessage
	delay 30
	return

ContestHall_EventScript_ThankYouForAppeals::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThankYouForAppealsLink
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThankYouForAppealsLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThankYouForAppeals
	waitmessage
	delay 30
	return

ContestHall_EventScript_JudgeLooksReady::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_JudgeLooksReadyLink
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
	return

ContestHall_EventScript_JudgeLooksReadyLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_JudgeLooksReady
	waitmessage
	delay 30
	return

ContestHall_EventScript_WeWillDeclareWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_WeWillDeclareWinnerLink
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
	buffernumberstring STR_VAR_2, VAR_0x8005
	addvar VAR_0x8005, -1
	call ContestHall_EventScript_CongratsWinner
	applymovement VAR_TEMP_3, ContestHall_Movement_WinningPlayerWalkUp
	waitmovement 0
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	return

ContestHall_EventScript_CongratsWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_CongratsWinnerLink
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
	return

ContestHall_EventScript_CongratsWinnerLink::
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
	waitmessage
	return

ContestHall_EventScript_AudienceLookAround::
	addvar VAR_TEMP_1, 1
	lockall
	call_if_gt VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	delay 30
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	goto_if_ne VAR_TEMP_1, 4, ContestHall_EventScript_AudienceLookAround
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
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EndLinkContest
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
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_SkipPrize::
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	delay 90
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_CheckShouldSkipPrize::
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CheckPlayerWon
	return

ContestHall_EventScript_CheckPlayerWon::
	special GetContestWinnerId
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_CheckRankIsMaster
	return

ContestHall_EventScript_CheckRankIsMaster::
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_DontSkipPrize
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
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForLinkContestArtist
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
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_GiveContestPrizes
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GiveContestPrizes::
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetSketchFlag
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_ReceiveContestRibbon
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_GiveLuxuryBall
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
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_NoRoomForLuxuryBall
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
	walk_in_place_faster_right
	step_end

ContestHall_Movement_Heart:
	emote_heart
	step_end

ContestHall_Movement_FaceContestants:
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageLeft:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageRight:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WinningPlayerWalkUp:
	walk_up
	walk_in_place_faster_down
	step_end

ContestHall_Movement_ContestantDelay32:
	delay_16
	delay_16
	step_end

ContestHall_Movement_MCFaceJudge2:
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeFaceMC:
	walk_in_place_faster_left
	step_end

ContestHall_Movement_FaceContestants2:
	walk_in_place_faster_down
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
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeLookAtMC:
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_MCWalkInPlaceDown:
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_Player1WalkToCenter:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player1WalkBack:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkToCenter:
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkBack:
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkToCenter:
	walk_up
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkBack:
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkToCenter:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
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
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_RetRSPlayer
	return

ContestHall_EventScript_RetRSPlayer::
	return

LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
	return

LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer::
	delay 9
	return

LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase:
    .string "Bonjour!\p"
    .string "Vous êtes à la réception des\n"
    .string "CONCOURS POKéMON.\p"
    .string "Oh? Mais vous n’avez pas encore\n"
    .string "de BOITE {POKEBLOCK}.\p"
    .string "Dans ce cas, nous allons vous en\n"
    .string "fournir une!$"

LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp:
    .string "OK, maintenant que le problème\n"
    .string "est réglé…\p"
    .string "Bonjour!\p"
    .string "Vous êtes à la réception des\n"
    .string "CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_ContestReception:
    .string "Bonjour!\p"
    .string "Nous prenons les inscriptions aux\n"
    .string "CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests:
    .string "Hello!\p"
    .string "This reception counter is only\n"
    .string "for 4-player POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_EnterContest1:
    .string "Voulez-vous faire participer un de vos\n"
    .string "POKéMON à un CONCOURS?$"

LilycoveCity_ContestLobby_Text_WhichTopic1:
    .string "A quel sujet?$"

LilycoveCity_ContestLobby_Text_ExplainContests:
    .string "Dans un CONCOURS POKéMON, il y a quatre\n"
    .string "DRESSEURS qui font chacun participer\l"
    .string "un POKéMON.\p"
    .string "Un CONCOURS comporte un jugement\n"
    .string "préliminaire et un jugement secondaire.\p"
    .string "Le jugement préliminaire est un\n"
    .string "jugement auquel participe le public.\p"
    .string "Le jugement secondaire concerne les\n"
    .string "démonstrations de capacités.\p"
    .string "Il faut préparer ses démonstrations\n"
    .string "afin d’attirer l’attention du JUGE et\l"
    .string "d’enthousiasmer le public.\p"
    .string "Faites de votre mieux pour vous\n"
    .string "imposer.\p"
    .string "Les scores obtenus au premier tour et\n"
    .string "au second tour sont totalisés à la fin.\p"
    .string "Le POKéMON obtenant le score total le\n"
    .string "plus élevé est déclaré vainqueur.$"

LilycoveCity_ContestLobby_Text_ExplainContestTypes:
    .string "Il y a cinq types de CONCOURS:\p"
    .string "SANG-FROID, BEAUTE, GRACE,\n"
    .string "INTELLIGENCE et ROBUSTESSE.\p"
    .string "Il faut choisir le CONCOURS en fonction\n"
    .string "du POKéMON que vous voulez inscrire.$"

LilycoveCity_ContestLobby_Text_ExplainContestRanks:
    .string "Il y a quatre catégories de CONCOURS\n"
    .string "POKéMON:\p"
    .string "NORMAL, SUPER, HYPER et MASTER.\p"
    .string "Tous les POKéMON peuvent s’inscrire\n"
    .string "dans la catégorie NORMAL.\p"
    .string "Un POKéMON remportant un CONCOURS\n"
    .string "catégorie NORMAL peut passer à la\l"
    .string "catégorie SUPER du même CONCOURS.\p"
    .string "De même, gagner la catégorie\n"
    .string "SUPER permet de passer à la catégorie\l"
    .string "HYPER et gagner la catégorie HYPER\l"
    .string "permet de passer à la catégorie MASTER.\p"
    .string "Après une victoire dans la catégorie\n"
    .string "MASTER, le POKéMON peut être présenté\l"
    .string "dans cette catégorie à tout moment.$"

LilycoveCity_ContestLobby_Text_EnterWhichRank:
    .string "Dans quelle catégorie souhaitez-vous\n"
    .string "participer?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest1:
    .string "Quel CONCOURS choisissez-vous?$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon1:
    .string "Quel POKéMON choisissez-vous?$"

LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank:
    .string "Quel dommage, votre POKéMON n’est pas\n"
    .string "encore assez qualifié pour concourir\l"
    .string "dans cette catégorie…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart:
    .string "Un OEUF ne peut malheureusement pas\n"
    .string "participer à un CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_MonInNoConditionForContest:
    .string "Votre POKéMON n’est pas en \n"
    .string "état de participer à un CONCOURS…$"

LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway:
    .string "Oh, mais ce RUBAN…\p"
    .string "Votre POKéMON a déjà gagné ce\n"
    .string "CONCOURS, n’est-ce pas?\p"
    .string "Vous voulez quand même l’inscrire à\n"
    .string "ce CONCOURS?$"

LilycoveCity_ContestLobby_Text_ConfirmContestMon:
    .string "Est-ce votre POKéMON DE CONCOURS?$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4:
    .string "D’accord, je vais inscrire votre POKéMON\n"
    .string "au CONCOURS.\p"
    .string "Votre POKéMON sera le concurrent Nº 4.\n"
    .string "Le CONCOURS va bientôt débuter.$"

LilycoveCity_ContestLobby_Text_ComeThroughHere:
    .string "Veuillez entrer.\n"
    .string "Bonne chance!$"

LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize:
    .string "Félicitations! Votre POKéMON remporte\n"
    .string "le CONCOURS!\p"
    .string "Nous allons vous donner votre prix.\n"
    .string "Par ici, je vous en prie!$"

LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater:
    .string "Repassez plus tard pour prendre votre\n"
    .string "prix.$"

ContestHall_Text_GettingStartedParticipantsAsFollows:
    .string "ANIMATRICE: Votre attention! Je n’ai\n"
    .string "qu’un mot à dire: {STR_VAR_2}! Que le\l"
    .string "CONCOURS catégorie {STR_VAR_3} commence!\p"
    .string "Voici les DRESSEURS en compétition\n"
    .string "et leurs POKéMON.$"

ContestHall_Text_GettingStartedParticipantsAsFollowsLink:
    .string "ANIMATRICE: Votre attention! Je n’ai\n"
    .string "qu’un mot à dire: {STR_VAR_2}! Que le\l"
    .string "CONCOURS en link avec 4 joueurs\l"
    .string "commence!\p"
    .string "Voici les DRESSEURS en compétition\n"
    .string "et leurs POKéMON.$"

ContestHall_Text_EntryXTrainersMon:
    .string "ANIMATRICE: Concurrent Nº {STR_VAR_2}!\n"
    .string "{STR_VAR_3} de {STR_VAR_1}!$"

ContestHall_Text_SeenContestantsAudienceWillVote:
    .string "ANIMATRICE: Nous venons de voir les\n"
    .string "quatre concurrents POKéMON.\p"
    .string "Maintenant, c’est le jugement\n"
    .string "préliminaire!\p"
    .string "Les membres du public vont choisir\n"
    .string "leurs concurrents POKéMON préférés.\p"
    .string "N’attendons pas une minute de plus, que\n"
    .string "le vote commence!$"

ContestHall_Text_VotingUnderWay:
    .string "Vote en cours…$"

ContestHall_Text_VotingCompleteLetsAppeal:
    .string "Le vote est achevé!\p"
    .string "Pendant le comptage des voix, \n"
    .string "passons au jugement secondaire!\p"
    .string "Il s’agit du moment très attendu des\n"
    .string "démonstrations!\p"
    .string "Que les concurrents nous éblouissent!\p"
    .string "Un peu d’enthousiasme!\n"
    .string "Place aux démonstrations!$"

ContestHall_Text_ThatsItForJudging:
    .string "ANIMATRICE: Le second tour est\n"
    .string "terminé!$"

ContestHall_Text_ThankYouForAppeals:
    .string "Merci à tous pour ces démonstrations\n"
    .string "d’une rare qualité!\p"
    .string "Les délibérations touchent à leur fin!\n"
    .string "Merci pour vos efforts!$"

ContestHall_Text_JudgeLooksReady:
    .string "Maintenant il ne reste plus qu’à\n"
    .string "annoncer le grand gagnant.\p"
    .string "Le JUGE est prêt à faire son\n"
    .string "annonce!$"

ContestHall_Text_WeWillNowDeclareWinner:
    .string "JUGE: Je vais annoncer le vainqueur!$"

ContestHall_Text_CongratsTrainerXandMon:
    .string "ANIMATRICE: Concurrent Nº {STR_VAR_2}!\p"
    .string "Félicitations,\n"
    .string "{STR_VAR_3} et {STR_VAR_1}!$"

ContestHall_Text_CongratsPleaseCompeteAgain:
    .string "ANIMATRICE: Félicitations!\n"
    .string "J’espère vous revoir bientôt!$"

ContestHall_Text_AcceptYourPrize:
    .string "ANIMATRICE: Tenez!\n"
    .string "Voici votre prix!$"

ContestHall_Text_ConferRibbonAsPrize:
    .string "Pour récompenser votre victoire,\n"
    .string "voici ce RUBAN!$"

ContestHall_Text_ReceivedRibbon:
    .string "{PLAYER} reçoit un RUBAN.$"

ContestHall_Text_PutRibbonOnMon:
    .string "{PLAYER} met le RUBAN sur\n"
    .string "{STR_VAR_1}.$"

ContestHall_Text_PickUpPrizeAtCounterLater:
    .string "Venez chercher votre prix plus tard\n"
    .string "à l’accueil.\l"
    .string "J’espère vous revoir bientôt!$"

ContestHall_Text_OnlyRegister4Players:
    .string "I only register four players for\n"
    .string "POKéMON CONTESTS.\p"
    .string "If three other players link up, all\n"
    .string "four may enter the same CONTEST.\p"
    .string "Would you like to take part?$"

LilycoveCity_ContestLobby_Text_ProgressWillBeSaved:
    .string "Avant de débuter un CONCOURS,\n"
    .string "il faut sauvegarder sa partie.$"

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime:
    .string "Nous espérons vous compter parmi\n"
    .string "nos participants une prochaine fois.$"

LilycoveCity_ContestLobby_Text_EnterContest2:
    .string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_Explain4PlayerContest:
    .string "When four players are ready, connect\n"
    .string "over a Game Link cable, and register\l"
    .string "with me, please.\p"
    .string "Please choose the same CONTEST\n"
    .string "as your fellow contestants.\p"
    .string "The CONTEST begins as soon as all\n"
    .string "players register their entry.\p"
    .string "After that, the usual CONTEST rules\n"
    .string "apply.$"

LilycoveCity_ContestLobby_Text_EnterWhichContest2:
    .string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon2:
    .string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_Transmitting:
    .string "Transmission…$"

LilycoveCity_ContestLobby_Text_TransmissionError:
    .string "Erreur de transmission…$"

LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest:
    .string "Vous avez peut-être choisi un\n"
    .string "CONCOURS différent des autres joueurs.$"

LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice:
    .string "Vous avez peut-être fait un choix\n"
    .string "différent des autres joueurs.$"

LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel:
    .string "Veuillez patienter.\n"
    .string "Appuyez sur le bouton B pour annuler…$"

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2:
    .string "We hope you will participate another\n"
    .string "time.$"

LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain:
    .string "Transmission error.\n"
    .string "Please try again.$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX:
    .string "Je vais inscrire votre POKéMON au\n"
    .string "CONCOURS.\p"
    .string "Votre POKéMON sera le concurrent Nº {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_ContestBeginShortly:
    .string "Le CONCOURS va bientôt débuter.$"

LilycoveCity_ContestLobby_Text_LinkContestReception:
    .string "Bienvenue. Vous êtes à la réception\n"
    .string "des CONCOURS POKéMON en link.\p"
    .string "Vous pouvez participer aux CONCOURS\n"
    .string "avec un ou plusieurs amis.$"

LilycoveCity_ContestLobby_Text_WhichTopic2:
    .string "A quel sujet?$"

LilycoveCity_ContestLobby_Text_EnterContest3:
    .string "Voulez-vous participer à un CONCOURS?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest3:
    .string "Quel CONCOURS choisissez-vous?$"

LilycoveCity_ContestLobby_Text_MonInNoCondition2:
    .string "Votre POKéMON n’est pas en \n"
    .string "état de participer à un CONCOURS…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart2:
    .string "Un OEUF ne peut malheureusement pas\n"
    .string "participer à un CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon3:
    .string "Quel POKéMON choisissez-vous?$"

LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader:
    .string "Veuillez choisir lequel de vous\n"
    .string "deux sera le MENEUR.\p"
    .string "L’autre joueur devra ensuite\n"
    .string "choisir “JOINDRE”.$"

LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode:
    .string "Au moins un joueur est entré en\n"
    .string "utilisant la réception 4-joueurs.\p"
    .string "Quatre joueurs doivent être connectés\n"
    .string "avec des câbles GBA Game Link.\p"
    .string "Quand tous les joueurs sont prêts,\n"
    .string "sélectionnez MODE-G (MODE GLOBAL)\l"
    .string "et enregistrez-vous de nouveau.$"

LilycoveCity_ContestLobby_Text_ExplainLinkContest:
    .string "C’est un CONCOURS pour deux à quatre\n"
    .string "joueurs connectés avec des câbles GBA\l"
    .string "Game Link ou des adaptateurs sans fil.\p"
    .string "Les participants doivent d’abord\n"
    .string "choisir le mode auquel ils\l"
    .string "veulent jouer.\p"
    .string "Il y a deux modes différents.\p"
    .string "Le MODE-E (MODE EMERAUDE) est pour\n"
    .string "deux à quatre joueurs ayant chacun une\l"
    .string "cartouche de jeu POKéMON Emeraude.\p"
    .string "Le MODE-G (MODE GLOBAL) est seulement\n"
    .string "pour quatre joueurs ayant chacun une\p"
    .string "cartouche de jeu POKéMON Emeraude,\n"
    .string "Rubis ou Saphir.\p"
    .string "Les joueurs doivent discuter ensemble\n"
    .string "du mode qu’ils veulent utiliser et\l"
    .string "choisir ensuite le même.\p"
    .string "L’inscription se termine une fois que\n"
    .string "tous les joueurs ont choisi le même\l"
    .string "CONCOURS dans le même mode.\p"
    .string "Après ça, le CONCOURS débute\n"
    .string "normalement.$"

LilycoveCity_ContestLobby_Text_ExplainEMode:
    .string "Dans le MODE-E (MODE EMERAUDE),\n"
    .string "un CONCOURS LINK prend place avec\l"
    .string "deux à quatre joueurs ayant chacun\l"
    .string "une cartouche de jeu POKéMON Emeraude.\p"
    .string "Les joueurs doivent être connectés en\n"
    .string "utilisant des câbles GBA Game Link ou\l"
    .string "des adaptateurs sans fil.\p"
    .string "S’il y a moins de quatre joueurs, des\n"
    .string "DRESSEURS se trouvant dans le hall\l"
    .string "viendront pour compléter la partie.\p"
    .string "Veuillez noter que le MODE-E n’est\n"
    .string "pas disponible dans POKéMON Rubis\l"
    .string "ou Saphir.$"

LilycoveCity_ContestLobby_Text_ExplainGMode:
    .string "Le MODE-G (MODE GLOBAL) est\n"
    .string "spécifiquement conçu pour quatre\p"
    .string "joueurs connectés avec des\n"
    .string "câbles GBA Game Link.\p"
    .string "Chaque joueur doit utiliser une\n"
    .string "cartouche de jeu POKéMON Emeraude,\l"
    .string "Rubis ou Saphir.\p"
    .string "Le CONCOURS commence dès que\n"
    .string "tous les joueurs ont choisi MODE-G\l"
    .string "(POKéMON Emeraude) ou sont\l"
    .string "entrés en passant par la réception\l"
    .string "4-joueurs (POKéMON Rubis ou Saphir).$"

LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode:
    .string "Je suis terriblement désolée.\p"
    .string "Le MODE-G ne fonctionne pas avec\n"
    .string "les adaptateurs sans fil.\p"
    .string "Veuillez sélectionner le MODE-E ou\n"
    .string "essayez avec des câbles GBA Game Link.$"

LilycoveCity_ContestLobby_Text_WhichContestMode:
    .string "A quel MODE CONCOURS\n"
    .string "voulez-vous participer?$"

ContestHall_Text_GettingStartedWireless:
    .string "ANIMATRICE: Votre attention! Je n’ai\n"
    .string "qu’un mot à dire: {STR_VAR_2}! Que le\l"
    .string "CONCOURS en link avec 4 joueurs\l"
    .string "commence!$"

ContestHall_Text_ParticipantsAsFollows:
    .string "Voici les DRESSEURS en compétition\n"
    .string "et leurs POKéMON:$"

ContestHall_Text_WeveSeenContestants:
    .string "ANIMATRICE: Nous venons de voir les\n"
    .string "quatre concurrents POKéMON.\p"
    .string "Maintenant, c’est le jugement\n"
    .string "préliminaire!$"

ContestHall_Text_AudienceWillVote:
    .string "Les membres du public vont choisir\n"
    .string "leurs concurrents POKéMON préférés.$"

ContestHall_Text_LetVotingBegin:
    .string "N’attendons pas une minute de plus, que\n"
    .string "le vote commence!$"

ContestHall_Text_VotingComplete:
    .string "Le vote est achevé!\p"
    .string "Pendant le comptage des voix, \n"
    .string "passons au jugement secondaire!$"

ContestHall_Text_SecondStageOfJudging:
    .string "Il s’agit du moment très attendu des\n"
    .string "démonstrations!\p"
    .string "Que les concurrents nous éblouissent!$"

ContestHall_Text_LetsAppeal:
    .string "Un peu d’enthousiasme!\n"
    .string "Place aux démonstrations!$"

