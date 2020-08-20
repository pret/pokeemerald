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
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist:: @ 8279CC5
	lock
	faceplayer
	compare VAR_CONTEST_PRIZE_PICKUP, 0
	goto_if_ne LilycoveCity_ContestLobby_EventScript_PickUpPrize
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
	goto LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ReceptionWelcome:: @ 8279CEA
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_GivePokeblockCase:: @ 8279CF3
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_PickUpPrize:: @ 8279D13
	msgbox LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter
	end

LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter:: @ 8279D2C
	giveitem ITEM_LUXURY_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter:: @ 8279D4B
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_AskEnterContest:: @ 8279D5A
	message LilycoveCity_ContestLobby_Text_EnterContest1
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ChooseContestRank
	case 1, LilycoveCity_ContestLobby_EventScript_ContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ContestInfo:: @ 8279D97
	message LilycoveCity_ContestLobby_Text_WhichTopic1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainContests
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainContestTypes
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainContestRanks
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainContests:: @ 8279DDF
	msgbox LilycoveCity_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestTypes:: @ 8279DED
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestRanks:: @ 8279DFB
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelEnterContest:: @ 8279E09
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestMon:: @ 8279E13
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

LilycoveCity_ContestLobby_EventScript_ChooseContestRank:: @ 8279E62
	message LilycoveCity_ContestLobby_Text_EnterWhichRank
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EnterNormalRank
	case 1, LilycoveCity_ContestLobby_EventScript_EnterSuperRank
	case 2, LilycoveCity_ContestLobby_EventScript_EnterHyperRank
	case 3, LilycoveCity_ContestLobby_EventScript_EnterMasterRank
	case 4, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_EnterNormalRank:: @ 8279EB5
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterSuperRank:: @ 8279EC0
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterHyperRank:: @ 8279ECB
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterMasterRank:: @ 8279ED6
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

@ The multichoice selection IDs are equal to the CATEGORY values
@ So rather than list the cases they just copy VAR_RESULT for a valid selection into VAR_CONTEST_CATEGORY
LilycoveCity_ContestLobby_EventScript_ChooseContestType:: @ 8279EE1
	message LilycoveCity_ContestLobby_Text_EnterWhichContest1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, 0
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterLowRank:: @ 8279F12
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ Unused
LilycoveCity_ContestLobby_EventScript_ConfirmEntry:: @ 8279F21
	msgbox LilycoveCity_ContestLobby_Text_ConfirmContestMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon:: @ 8279F45
	msgbox LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterEgg:: @ 8279F69
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

LilycoveCity_ContestLobby_EventScript_CantEnterFainted:: @ 8279F78
	msgbox LilycoveCity_ContestLobby_Text_MonInNoConditionForContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ The return here is back to LilycoveCity_ContestLobby_EventScript_ContestReceptionist
LilycoveCity_ContestLobby_EventScript_EnterMon:: @ 8279F87
	msgbox LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_CONTEST_HALL_STATE, 1
	return

ContestHall_EventScript_DoContest:: @ 8279F97
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

ContestHall_EventScript_GetContestRankStringId:: @ 8279FF2
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, ContestHall_EventScript_GetNormalStringId
	case CONTEST_RANK_SUPER, ContestHall_EventScript_GetSuperStringId
	case CONTEST_RANK_HYPER, ContestHall_EventScript_GetHyperStringId
	case CONTEST_RANK_MASTER, ContestHall_EventScript_GetMasterStringId
	return

ContestHall_EventScript_GetNormalStringId:: @ 827A024
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

ContestHall_EventScript_GetSuperStringId:: @ 827A02A
	setvar VAR_0x8009, STDSTRING_SUPER
	return

ContestHall_EventScript_GetHyperStringId:: @ 827A030
	setvar VAR_0x8009, STDSTRING_HYPER
	return

ContestHall_EventScript_GetMasterStringId:: @ 827A036
	setvar VAR_0x8009, STDSTRING_MASTER
	return

@ This whole switch is equivalent to copyvar VAR_0x8008, VAR_CONTEST_CATEGORY
ContestHall_EventScript_GetContestCategory:: @ 827A03C
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_GetCategoryCool
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_GetCategoryBeauty
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_GetCategoryCute
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_GetCategorySmart
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_GetCategoryTough
	return

ContestHall_EventScript_GetCategoryCool:: @ 827A079
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

ContestHall_EventScript_GetCategoryBeauty:: @ 827A07F
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

ContestHall_EventScript_GetCategoryCute:: @ 827A085
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

ContestHall_EventScript_GetCategorySmart:: @ 827A08B
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

ContestHall_EventScript_GetCategoryTough:: @ 827A091
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

ContestHall_EventScript_ContestGettingStarted:: @ 827A097
	buffercontesttypestring 1, VAR_0x8008
	bufferstdstring 2, VAR_0x8009
	call ContestHall_EventScript_GettingStarted
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_MCBackUp
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_GettingStarted:: @ 827A0B1
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_GettingStartedLink
	lockall
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GettingStartedLink:: @ 827A0C7
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_GettingStartedWireless
	messageautoscroll ContestHall_Text_GettingStartedParticipantsAsFollowsLink
	waitmessage
	return

ContestHall_EventScript_GettingStartedWireless:: @ 827A0DE
	messageautoscroll ContestHall_Text_GettingStartedWireless
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ParticipantsAsFollows
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ShowContestMons:: @ 827A0F5
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

ContestHall_EventScript_TryWaitForLink:: @ 827A133
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_WaitForLink
	return

ContestHall_EventScript_WaitForLink:: @ 827A144
	special LinkContestWaitForConnection
	waitstate
	return

ContestHall_EventScript_ContestantWalkToCenter:: @ 827A149
	compare VAR_0x8006, 0
	goto_if_eq ContestHall_EventScript_Player1WalkToCenter
	compare VAR_0x8006, 1
	goto_if_eq ContestHall_EventScript_Player2WalkToCenter
	compare VAR_0x8006, 2
	goto_if_eq ContestHall_EventScript_Player3WalkToCenter
	compare VAR_0x8006, 3
	goto_if_eq ContestHall_EventScript_Player4WalkToCenter
	return

ContestHall_EventScript_Player1WalkToCenter:: @ 827A176
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_1, ContestHall_Movement_Player1WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_Player2WalkToCenter:: @ 827A18D
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_2, ContestHall_Movement_Player2WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_Player3WalkToCenter:: @ 827A1A4
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_3, ContestHall_Movement_Player3WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_Player4WalkToCenter:: @ 827A1BB
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_ShowContestMonPic:: @ 827A1D2
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

ContestHall_EventScript_EntryXTrainersMon:: @ 827A217
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_EntryXTrainersMonLink
	message ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_EntryXTrainersMonLink:: @ 827A229
	messageautoscroll ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_AudienceVote:: @ 827A230
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

ContestHall_EventScript_AudienceWillVote:: @ 827A26C
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_AudienceWillVoteLink
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
	return

ContestHall_EventScript_AudienceWillVoteLink:: @ 827A280
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_AudienceWillVoteWireless
	messageautoscroll ContestHall_Text_SeenContestantsAudienceWillVote
	waitmessage
	return

ContestHall_EventScript_AudienceWillVoteWireless:: @ 827A297
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

ContestHall_EventScript_VotingUnderWay:: @ 827A2B9
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_VotingUnderWayLink
	message ContestHall_Text_VotingUnderWay
	return

ContestHall_EventScript_VotingUnderWayLink:: @ 827A2CA
	messageautoscroll ContestHall_Text_VotingUnderWay
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_AudienceReactToContestant:: @ 827A2D5
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
ContestHall_EventScript_AudienceHeartEmotes:: @ 827A34F
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

ContestHall_EventScript_DisplayHearts:: @ 827A3E5
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

ContestHall_EventScript_GetNumberOfHeartsNormal:: @ 827A454
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

ContestHall_EventScript_GetNumberOfHeartsSuper:: @ 827A4B2
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

ContestHall_EventScript_GetNumberOfHeartsHyper:: @ 827A510
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

ContestHall_EventScript_GetNumberOfHeartsMaster:: @ 827A56E
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

ContestHall_EventScript_GetNumberOfHeartsLink:: @ 827A5CC
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

ContestHall_EventScript_Set1Heart:: @ 827A62A
	setvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_Set2Hearts:: @ 827A630
	setvar VAR_TEMP_0, 2
	return

ContestHall_EventScript_Set3Hearts:: @ 827A636
	setvar VAR_TEMP_0, 3
	return

ContestHall_EventScript_Set4Hearts:: @ 827A63C
	setvar VAR_TEMP_0, 4
	return

ContestHall_EventScript_Set5Hearts:: @ 827A642
	setvar VAR_TEMP_0, 5
	return

ContestHall_EventScript_Set6Hearts:: @ 827A648
	setvar VAR_TEMP_0, 6
	return

ContestHall_EventScript_Set7Hearts:: @ 827A64E
	setvar VAR_TEMP_0, 7
	return

ContestHall_EventScript_Set8Hearts:: @ 827A654
	setvar VAR_TEMP_0, 8
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember1:: @ 827A65A
	compare VAR_TEMP_1, 1
	goto_if_eq ContestHall_EventScript_AudienceMember1AlreadyEmoted
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember1AlreadyEmoted:: @ 827A67D
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember2:: @ 827A67E
	compare VAR_TEMP_2, 1
	goto_if_eq ContestHall_EventScript_AudienceMember2AlreadyEmoted
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember2AlreadyEmoted:: @ 827A6A1
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember3:: @ 827A6A2
	compare VAR_TEMP_3, 1
	goto_if_eq ContestHall_EventScript_AudienceMember3AlreadyEmoted
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember3AlreadyEmoted:: @ 827A6C5
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember4:: @ 827A6C6
	compare VAR_TEMP_4, 1
	goto_if_eq ContestHall_EventScript_Audience4MemberAlreadyEmoted
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_Audience4MemberAlreadyEmoted:: @ 827A6E9
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember5:: @ 827A6EA
	compare VAR_TEMP_5, 1
	goto_if_eq ContestHall_EventScript_AudienceMember5AlreadyEmoted
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember5AlreadyEmoted:: @ 827A70D
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember6:: @ 827A70E
	compare VAR_TEMP_6, 1
	goto_if_eq ContestHall_EventScript_AudienceMember6AlreadyEmoted
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember6AlreadyEmoted:: @ 827A731
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember7:: @ 827A732
	compare VAR_TEMP_7, 1
	goto_if_eq ContestHall_EventScript_AudienceMember7AlreadyEmoted
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember7AlreadyEmoted:: @ 827A755
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember8:: @ 827A756
	compare VAR_TEMP_8, 1
	goto_if_eq ContestHall_EventScript_AudienceMember8AlreadyEmoted
	applymovement LOCALID_ARTIST, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember8AlreadyEmoted:: @ 827A779
	return

ContestHall_EventScript_ContestantReturn:: @ 827A77A
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

ContestHall_EventScript_Player1WalkBack:: @ 827A7B9
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player1WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2WalkBack:: @ 827A7CB
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player2WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3WalkBack:: @ 827A7DD
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player3WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4WalkBack:: @ 827A7EF
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player4WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_DoContestAppeals:: @ 827A801
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

ContestHall_EventScript_LetsAppeal:: @ 827A853
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_LetsAppealLink
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
	return

ContestHall_EventScript_LetsAppealLink:: @ 827A867
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_LetsAppealWireless
	messageautoscroll ContestHall_Text_VotingCompleteLetsAppeal
	waitmessage
	return

ContestHall_EventScript_LetsAppealWireless:: @ 827A87E
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

ContestHall_EventScript_ContestResults:: @ 827A8A5
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
	playbgm MUS_CONTEST_WINNER, 0
	return

ContestHall_EventScript_ThatsItForJudging:: @ 827A8FB
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_ThatsItForJudgingLink
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThatsItForJudgingLink:: @ 827A90F
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThatsItForJudging
	waitmessage
	delay 30
	return

ContestHall_EventScript_ThankYouForAppeals:: @ 827A91E
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_ThankYouForAppealsLink
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThankYouForAppealsLink:: @ 827A932
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThankYouForAppeals
	waitmessage
	delay 30
	return

ContestHall_EventScript_JudgeLooksReady:: @ 827A941
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_JudgeLooksReadyLink
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
	return

ContestHall_EventScript_JudgeLooksReadyLink:: @ 827A955
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_JudgeLooksReady
	waitmessage
	delay 30
	return

ContestHall_EventScript_WeWillDeclareWinner:: @ 827A964
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_WeWillDeclareWinnerLink
	msgbox ContestHall_Text_WeWillNowDeclareWinner, MSGBOX_DEFAULT
	return

ContestHall_EventScript_WeWillDeclareWinnerLink:: @ 827A978
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_WeWillNowDeclareWinner
	waitmessage
	delay 30
	return

ContestHall_EventScript_GetWinnerObjEventId:: @ 827A987
	special GetContestWinnerId
	switch VAR_0x8005
	case 0, ContestHall_EventScript_GetPlayer1ObjEventId
	case 1, ContestHall_EventScript_GetPlayer2ObjEventId
	case 2, ContestHall_EventScript_GetPlayer3ObjEventId
	case 3, ContestHall_EventScript_GetPlayer4ObjEventId
	return

ContestHall_EventScript_GetPlayer1ObjEventId:: @ 827A9BC
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_GetPlayer2ObjEventId:: @ 827A9C2
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_GetPlayer3ObjEventId:: @ 827A9C8
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_GetPlayer4ObjEventId:: @ 827A9CE
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_CongratulateWinner:: @ 827A9D4
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

ContestHall_EventScript_CongratsWinner:: @ 827AA00
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_CongratsWinnerLink
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
	return

ContestHall_EventScript_CongratsWinnerLink:: @ 827AA14
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
	waitmessage
	return

ContestHall_EventScript_AudienceLookAround:: @ 827AA1B
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

ContestHall_EventScript_VObjectAudienceLookAround:: @ 827AA6F
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

ContestHall_EventScript_GiveWinnerPrize:: @ 827AB36
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

ContestHall_EventScript_SkipPrize:: @ 827AB82
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	delay 90
	special ShouldReadyContestArtist
	compare VAR_0x8004, TRUE
	goto_if_eq ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_CheckShouldSkipPrize:: @ 827AB9E
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_CheckPlayerWon
	return

ContestHall_EventScript_CheckPlayerWon:: @ 827ABAF
	special GetContestWinnerId
	compare VAR_0x8005, 3
	goto_if_eq ContestHall_EventScript_CheckRankIsMaster
	return

ContestHall_EventScript_CheckRankIsMaster:: @ 827ABBE
	compare VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto_if_eq ContestHall_EventScript_DontSkipPrize
	setflag FLAG_TEMP_2
	return

ContestHall_EventScript_DontSkipPrize:: @ 827ABCD
	return

@ This flag is never read
ContestHall_EventScript_SetSketchFlag:: @ 827ABCE
	setflag FLAG_CONTEST_SKETCH_CREATED
	return

ContestHall_EventScript_SetReadyForContestArtist:: @ 827ABD2
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

ContestHall_EventScript_EndLinkContest:: @ 827ABD8
	delay 60
	special GetContestPlayerId
	special GetContestWinnerId
	special ShouldReadyContestArtist
	compare VAR_0x8004, TRUE
	goto_if_eq ContestHall_EventScript_SetReadyForLinkContestArtist
	closemessage
	return

ContestHall_EventScript_SetReadyForLinkContestArtist:: @ 827ABF1
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

@ Unused
ContestHall_EventScript_Ret:: @ 827ABF7
	return

ContestHall_EventScript_WinnerApproachForPrize:: @ 827ABF8
	switch VAR_0x8005
	case 0, ContestHall_EventScript_Player1ApproachForPrize
	case 1, ContestHall_EventScript_Player2ApproachForPrize
	case 2, ContestHall_EventScript_Player3ApproachForPrize
	case 3, ContestHall_EventScript_Player4ApproachForPrize
	return

ContestHall_EventScript_Player1ApproachForPrize:: @ 827AC2A
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player1ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2ApproachForPrize:: @ 827AC37
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player2ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3ApproachForPrize:: @ 827AC44
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player3ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4ApproachForPrize:: @ 827AC51
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player4ApproachForPrize
	waitmovement 0
	releaseall
	return

@ In NPC Contests, the player is always entry 4 (id number 3)
ContestHall_EventScript_GivePrizeIfWinner:: @ 827AC5E
	special GetContestWinnerId
	compare VAR_0x8005, 3
	goto_if_eq ContestHall_EventScript_GiveContestPrizes
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GiveContestPrizes:: @ 827AC77
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

ContestHall_EventScript_NoRoomForLuxuryBall:: @ 827ACA8
	lockall
	call Common_EventScript_BagIsFull
	msgbox ContestHall_Text_PickUpPrizeAtCounterLater, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

ContestHall_EventScript_GiveLuxuryBall:: @ 827ACBD
	giveitem ITEM_LUXURY_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq ContestHall_EventScript_NoRoomForLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_ReceiveContestRibbon:: @ 827ACDF
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

ContestHall_Movement_MCWalkDown: @ 827AD09
	walk_down
	step_end

ContestHall_Movement_MCBackUp: @ 827AD0B
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ContestHall_Movement_MCFaceJudge: @ 827AD0F
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_Heart: @ 827AD11
	emote_heart
	step_end

ContestHall_Movement_FaceContestants: @ 827AD13
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WalkStageLeft: @ 827AD15
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WalkStageRight: @ 827AD19
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_WinningPlayerWalkUp: @ 827AD1D
	walk_up
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_ContestantDelay32: @ 827AD20
	delay_16
	delay_16
	step_end

ContestHall_Movement_MCFaceJudge2: @ 827AD23
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_JudgeFaceMC: @ 827AD25
	walk_in_place_fastest_left
	step_end

ContestHall_Movement_FaceContestants2: @ 827AD27
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_Player3ApproachForPrize: @ 827AD29
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_Player4ApproachForPrize: @ 827AD2D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_AudienceMemberLookLeft: @ 827AD33
	face_left
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookUp: @ 827AD37
	face_up
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookRight: @ 827AD3B
	face_right
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookDown: @ 827AD3F
	face_down
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_Player4FaceUp: @ 827AD43
	face_up
	step_end

ContestHall_Movement_MCLookAtJudge: @ 827AD45
	face_up
	delay_16
	walk_in_place_fastest_right
	step_end

ContestHall_Movement_JudgeLookAtMC: @ 827AD49
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_MCWalkInPlaceDown: @ 827AD4E
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

ContestHall_Movement_Player1WalkToCenter: @ 827AD52
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player1WalkBack: @ 827AD58
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player2WalkToCenter: @ 827AD5E
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player2WalkBack: @ 827AD62
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player3WalkToCenter: @ 827AD66
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player3WalkBack: @ 827AD6A
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player4WalkToCenter: @ 827AD6E
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player4WalkBack: @ 827AD74
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

ContestHall_Movement_Player1ApproachForPrize: @ 827AD7A
	walk_right
	walk_right
	walk_up
	step_end

ContestHall_Movement_Player2ApproachForPrize: @ 827AD7E
	walk_up
	step_end

@ IsContestWithRSPlayer has no side effect, so this is nop
ContestHall_EventScript_CheckIfContestWithRSPlayer:: @ 827AD80
	specialvar VAR_RESULT, IsContestWithRSPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_RetRSPlayer
	return

ContestHall_EventScript_RetRSPlayer:: @ 827AD91
	return

LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer:: @ 827AD92
	specialvar VAR_RESULT, IsContestWithRSPlayer
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
	return

LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer:: @ 827ADA3
	delay 9
	return

LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase: @ 827ADA7
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.\p"
	.string "Oh? It appears that you don't have\n"
	.string "a {POKEBLOCK} CASE yet.\p"
	.string "In that case, we need to provide you\n"
	.string "with this!$"

LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp: @ 827AE47
	.string "Okay, now that we've cleared that\n"
	.string "up…\p"
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_ContestReception: @ 827AEA8
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

@ Unused
LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests: @ 827AEE3
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_EnterContest1: @ 827AF28
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"

LilycoveCity_ContestLobby_Text_WhichTopic1: @ 827AF5E
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_ExplainContests: @ 827AF7A
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"

LilycoveCity_ContestLobby_Text_ExplainContestTypes: @ 827B17D
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"

LilycoveCity_ContestLobby_Text_ExplainContestRanks: @ 827B221
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER, and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up to the SUPER Rank\l"
	.string "in the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and\l"
	.string "a HYPER Rank winner can advance to\l"
	.string "the MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"

LilycoveCity_ContestLobby_Text_EnterWhichRank: @ 827B3FF
	.string "Which Rank would you like to enter?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest1: @ 827B423
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon1: @ 827B44A
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank: @ 827B471
	.string "I'm terribly sorry, but your POKéMON\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart: @ 827B4C4
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_MonInNoConditionForContest: @ 827B501
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway: @ 827B547
	.string "Oh, but that RIBBON…\p"
	.string "Your POKéMON has won this CONTEST\n"
	.string "before, hasn't it?\p"
	.string "Would you like to enter it in this\n"
	.string "CONTEST anyway?$"

LilycoveCity_ContestLobby_Text_ConfirmContestMon: @ 827B5C4
	.string "Is that your CONTEST POKéMON?$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4: @ 827B5E2
	.string "Okay, your POKéMON will be entered\n"
	.string "in this CONTEST.\p"
	.string "Your POKéMON is Entry No. 4.\n"
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_ComeThroughHere: @ 827B653
	.string "Please come in through here.\n"
	.string "Good luck!$"

LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize: @ 827B67B
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"

LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater: @ 827B6E7
	.string "Please come back for your prize\n"
	.string "later on.$"

ContestHall_Text_GettingStartedParticipantsAsFollows: @ 827B711
	.string "MC: Hello! We're just getting started\n"
	.string "with a {STR_VAR_3} Rank POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

ContestHall_Text_GettingStartedParticipantsAsFollowsLink: @ 827B78F
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

ContestHall_Text_EntryXTrainersMon: @ 827B815
	.string "MC: Entry No. {STR_VAR_2}!\n"
	.string "{STR_VAR_1}'s {STR_VAR_3}!$"

ContestHall_Text_SeenContestantsAudienceWillVote: @ 827B830
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!\p"
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.\p"
	.string "Without any further ado, let the\n"
	.string "voting begin!$"

ContestHall_Text_VotingUnderWay: @ 827B8F2
	.string "Voting under way…$"

ContestHall_Text_VotingCompleteLetsAppeal: @ 827B904
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!\p"
	.string "The second stage of judging is the\n"
	.string "much anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!\p"
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"

ContestHall_Text_ThatsItForJudging: @ 827BA15
	.string "MC: That's it for judging!$"

ContestHall_Text_ThankYouForAppeals: @ 827BA30
	.string "Thank you all for a most wonderful\n"
	.string "display of quality appeals!\p"
	.string "This concludes all judging!\n"
	.string "Thank you for your fine efforts!$"

ContestHall_Text_JudgeLooksReady: @ 827BAAC
	.string "Now, all that remains is the pulse-\n"
	.string "pounding proclamation of the winner.\p"
	.string "The JUDGE looks ready to make\n"
	.string "the announcement!$"

ContestHall_Text_WeWillNowDeclareWinner: @ 827BB25
	.string "JUDGE: We will now declare the winner!$"

ContestHall_Text_CongratsTrainerXandMon: @ 827BB4C
	.string "MC: Entry No. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
	.string "congratulations!$"

ContestHall_Text_CongratsPleaseCompeteAgain: @ 827BB7A
	.string "MC: Congratulations!\n"
	.string "Please do compete again!$"

ContestHall_Text_AcceptYourPrize: @ 827BBA8
	.string "MC: Here you are!\n"
	.string "Please accept your prize!$"

ContestHall_Text_ConferRibbonAsPrize: @ 827BBD4
	.string "We confer on you this RIBBON\n"
	.string "as your prize!$"

ContestHall_Text_ReceivedRibbon: @ 827BC00
	.string "{PLAYER} received a RIBBON.$"

ContestHall_Text_PutRibbonOnMon: @ 827BC16
	.string "{PLAYER} put the RIBBON on\n"
	.string "{STR_VAR_1}.$"

ContestHall_Text_PickUpPrizeAtCounterLater: @ 827BC2F
	.string "Please pick up your prize at\n"
	.string "the reception counter later.\l"
	.string "Please do compete again!$"

@ Unused
ContestHall_Text_OnlyRegister4Players: @ 827BC82
	.string "I only register four players for\n"
	.string "POKéMON CONTESTS.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same CONTEST.\p"
	.string "Would you like to take part?$"

LilycoveCity_ContestLobby_Text_ProgressWillBeSaved: @ 827BD17
	.string "Before entering a CONTEST, your\n"
	.string "progress will be saved.$"

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime: @ 827BD4F
	.string "We hope you will participate another\n"
	.string "time.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterContest2: @ 827BD7A
	.string "Would you like to enter a CONTEST?$"

@ Unused
LilycoveCity_ContestLobby_Text_Explain4PlayerContest: @ 827BD9D
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same CONTEST\n"
	.string "as your fellow contestants.\p"
	.string "The CONTEST begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual CONTEST rules\n"
	.string "apply.$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichContest2: @ 827BE9E
	.string "Which CONTEST would you like to enter?$"

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichPokemon2: @ 827BEC5
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_Transmitting: @ 827BEEC
	.string "Transmitting…$"

LilycoveCity_ContestLobby_Text_TransmissionError: @ 827BEFA
	.string "Transmission error…$"

LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest: @ 827BF0E
	.string "You may have chosen a different\n"
	.string "CONTEST than another player.$"

LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice: @ 827BF4B
	.string "You may have made a different\n"
	.string "choice than another player.$"

LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel: @ 827BF85
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

@ Unused
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2: @ 827BFA7
	.string "We hope you will participate another\n"
	.string "time.$"

@ Unused
LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain: @ 827BFD2
	.string "Transmission error.\n"
	.string "Please try again.$"

LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX: @ 827BFF8
	.string "Your POKéMON will be entered in\n"
	.string "the CONTEST.\p"
	.string "Your POKéMON is Entry No. {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_ContestBeginShortly: @ 827C043
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_LinkContestReception: @ 827C063
	.string "Welcome! This is the POKéMON CONTEST\n"
	.string "link reception counter.\p"
	.string "You may enter CONTESTS together with\n"
	.string "one or more friends.$"

LilycoveCity_ContestLobby_Text_WhichTopic2: @ 827C0DA
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_EnterContest3: @ 827C0F6
	.string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_EnterWhichContest3: @ 827C119
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_MonInNoCondition2: @ 827C140
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_EggCannotTakePart2: @ 827C186
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_EnterWhichPokemon3: @ 827C1C3
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader: @ 827C1EA
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode: @ 827C254
	.string "At least one player has entered using\n"
	.string "the 4-player reception counter.\p"
	.string "There must be four players connected\n"
	.string "using a GBA Game Link cable.\p"
	.string "When the four players are ready,\n"
	.string "select G-MODE (GLOBAL MODE),\l"
	.string "then register to enter again, please.$"

LilycoveCity_ContestLobby_Text_ExplainLinkContest: @ 827C340
	.string "This is a CONTEST for two to four\n"
	.string "players linked using a Wireless\l"
	.string "Adapter or a GBA Game Link cable.\p"
	.string "Participants are first asked to choose\n"
	.string "the mode they wish to enter.\p"
	.string "There are two different modes.\p"
	.string "E-MODE (EMERALD MODE) is for\n"
	.string "two to four players, each with a\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "G-MODE (GLOBAL MODE) is only for\n"
	.string "four players, each with a POKéMON\l"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The players should discuss which mode\n"
	.string "they want, then choose the same mode.\p"
	.string "Once all the players have chosen\n"
	.string "the same CONTEST in the same mode,\l"
	.string "the entry registration is complete.\p"
	.string "After that, a CONTEST will start in\n"
	.string "the usual manner.$"

LilycoveCity_ContestLobby_Text_ExplainEMode: @ 827C5B1
	.string "In E-MODE (EMERALD MODE),\n"
	.string "a LINK CONTEST can be held with\l"
	.string "two to four players. Each player must\l"
	.string "have a POKéMON Emerald Game Pak.\p"
	.string "The players must be linked with each\n"
	.string "other using Wireless Adapters or\l"
	.string "GBA Game Link cables.\p"
	.string "If there are fewer than four players,\n"
	.string "TRAINERS in the hall will join to fill\l"
	.string "the 4-player CONTEST lineup.\p"
	.string "Please be aware that E-MODE is not\n"
	.string "available in POKéMON Ruby or Sapphire.$"

LilycoveCity_ContestLobby_Text_ExplainGMode: @ 827C742
	.string "G-MODE (GLOBAL MODE) is specifically\n"
	.string "for four players who are linked using\l"
	.string "GBA Game Link cables.\p"
	.string "Each player must have a POKéMON\n"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The CONTEST starts after all players\n"
	.string "choose G-MODE (POKéMON Emerald) or\l"
	.string "enter through the 4-player reception\l"
	.string "counter (POKéMON Ruby or Sapphire).$"

LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode: @ 827C879
	.string "I'm terribly sorry.\p"
	.string "G-MODE does not function\n"
	.string "with Wireless Adapters.\p"
	.string "Please select E-MODE or try\n"
	.string "again using a GBA Game Link cable.$"

LilycoveCity_ContestLobby_Text_WhichContestMode: @ 827C8FD
	.string "Which CONTEST MODE would you like\n"
	.string "to enter?$"

ContestHall_Text_GettingStartedWireless: @ 827C929
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!$"

ContestHall_Text_ParticipantsAsFollows: @ 827C972
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

ContestHall_Text_WeveSeenContestants: @ 827C9AF
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!$"

ContestHall_Text_AudienceWillVote: @ 827CA04
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.$"

ContestHall_Text_LetVotingBegin: @ 827CA42
	.string "Without any further ado,\n"
	.string "let the voting begin!$"

ContestHall_Text_VotingComplete: @ 827CA71
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!$"

ContestHall_Text_SecondStageOfJudging: @ 827CAD0
	.string "The second stage of judging is\n"
	.string "the much-anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!$"

ContestHall_Text_LetsAppeal: @ 827CB55
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"
