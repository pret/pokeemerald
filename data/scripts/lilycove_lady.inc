.set LOCALID_LILYCOVE_LADY, 4
.set LOCALID_LADYS_MON, 5

LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady:: @ 82A836B
    special Script_GetLilycoveLadyId
    switch VAR_RESULT
    case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
    case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
    case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady:: @ 82A8395
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetFavorLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted:: @ 82A83C6
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady:: @ 82A83D0
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem:: @ 82A83F7
    special BufferFavorLadyItemName
    special BufferFavorLadyPlayerName
    specialvar VAR_RESULT, DidFavorLadyLikeItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing:: @ 82A8419
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing:: @ 82A8427
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem:: @ 82A8435
    msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor:: @ 82A8454
    msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor:: @ 82A845E
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem:: @ 82A846C
    fadescreen FADE_TO_BLACK
    setvar VAR_RESULT, 0
    special Script_FavorLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem:: @ 82A848E
    msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem:: @ 82A84AD
    specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem:: @ 82A84C9
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem:: @ 82A84D6
    specialvar VAR_RESULT, IsFavorLadyThresholdMet
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem:: @ 82A84F2
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem:: @ 82A84FF
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize:: @ 82A8510
    setvar VAR_0x8004, 0
    specialvar VAR_0x8004, FavorLadyGetPrize
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
    giveitem VAR_0x8004
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize:: @ 82A8545
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize:: @ 82A854F
    special SetFavorLadyState_Complete
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady:: @ 82A8554
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetQuizLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz:: @ 82A8585
    specialvar VAR_RESULT, GetQuizAuthor
    compare VAR_RESULT, QUIZ_AUTHOR_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
    compare VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
    compare VAR_RESULT, QUIZ_AUTHOR_LADY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz:: @ 82A85AC
    specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz:: @ 82A85C8
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady:: @ 82A85D2
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady:: @ 82A85E0
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz:: @ 82A85EE
    setvar VAR_0x8004, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz:: @ 82A8612
    msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz:: @ 82A861C
    special ClearQuizLadyPlayerAnswer
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
    compare VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState:: @ 82A8635
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
    end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion:: @ 82A864C
    special QuizLadyShowQuizQuestion
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
    end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer:: @ 82A8656
    special QuizLadyGetPlayerAnswer
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz:: @ 82A8660
    msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz:: @ 82A867F
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse:: @ 82A8689
    special SetQuizLadyState_Complete
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
    specialvar VAR_RESULT, IsQuizAnswerCorrect
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
    end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse:: @ 82A86B0
    playse SE_SUCCESS
    delay 10
    playse SE_SUCCESS
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse:: @ 82A86C7
    special BufferQuizCorrectAnswer
    special BufferQuizPrizeName
    playse SE_FAILURE
    delay 10
    playse SE_FAILURE
    msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
    msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize:: @ 82A86EC
    specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1:: @ 82A8708
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0:: @ 82A8716
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize:: @ 82A8724
    setvar VAR_0x8005, 0
    special BufferQuizPrizeItem
    special SetQuizLadyState_Complete
    giveitem VAR_0x8005
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize:: @ 82A874C
    msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
    special SetQuizLadyState_GivePrize
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz:: @ 82A8759
    msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz:: @ 82A8778
    special QuizLadyPickNewQuestion
    msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz:: @ 82A8785
    msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize:: @ 82A878D
    fadescreen FADE_TO_BLACK
    setvar VAR_RESULT, 0
    special Script_QuizLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize:: @ 82A87AF
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz:: @ 82A87CE
    msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
    special ClearQuizLadyQuestionAndAnswer
    special ClearQuizLadyPlayerAnswer
    setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion:: @ 82A87E1
    fadescreen FADE_TO_BLACK
    special QuizLadySetCustomQuestion
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion:: @ 82A87F8
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
    end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz:: @ 82A8817
    special QuizLadyTakePrizeForCustomQuiz
    special QuizLadyRecordCustomQuizData
    special QuizLadySetWaitingForChallenger
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady:: @ 82A882A
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
    end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock:: @ 82A8850
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock:: @ 82A886C
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock:: @ 82A8876
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
    checkitem ITEM_POKEBLOCK_CASE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
    msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock:: @ 82A88B0
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock:: @ 82A88BA
    fadescreen FADE_TO_BLACK
    special OpenPokeblockCaseForContestLady
    waitstate
    compare VAR_RESULT, 0xFFFF
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
    compare VAR_RESULT, 0xFFFF
    goto_if_ne LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock:: @ 82A88D7
    msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
    compare VAR_RESULT, NO
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock:: @ 82A88F6
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
    special SetContestLadyGivenPokeblock
    special GetContestLadyMonSpecies
    goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
    end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock:: @ 82A890A
    applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
    waitmovement 0
    delay 60
    applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
    waitmovement 0
    delay 60
    waitse
    playmoncry VAR_0x8005, 0
    delay 120
    waitmoncry
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
    end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock:: @ 82A893F
    applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
    waitmovement 0
    delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock:: @ 82A894C
    applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
    waitmovement 0
    delay 60
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock:: @ 82A8970
    msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
    end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock:: @ 82A897E
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow:: @ 82A898F
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow:: @ 82A89A1
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
    special PutLilycoveContestLadyShowOnTheAir
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase:: @ 82A89AE
    msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon: @ 82A89B8
    face_right
    delay_8
    step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady: @ 82A89BB
    face_left
    delay_8
    step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown: @ 82A89BE
    face_down
    step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer: @ 82A89C0
    face_player
    step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump: @ 82A89C2
    disable_jump_landing_ground_effect
    jump_in_place_left
    disable_jump_landing_ground_effect
    jump_in_place_left
    step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon:: @ 82A89C7
    specialvar VAR_RESULT, GetContestLadyCategory
    special Script_BufferContestLadyCategoryAndMonName
    special GetContestLadyMonSpecies
    compare VAR_RESULT, CONTEST_CATEGORY_COOL
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
    compare VAR_RESULT, CONTEST_CATEGORY_BEAUTY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Skitty
    compare VAR_RESULT, CONTEST_CATEGORY_CUTE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
    compare VAR_RESULT, CONTEST_CATEGORY_SMART
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
    compare VAR_RESULT, CONTEST_CATEGORY_TOUGH
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
    end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon:: @ 82A8A0A
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty:: @ 82A8A1D
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena:: @ 82A8A30
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon:: @ 82A8A43
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu:: @ 82A8A56
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady: @ 82A8A69
    .string "I'm the FAVOR LADY…$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing: @ 82A8A7D
    .string "I've recently developed an obsession\n"
    .string "for {STR_VAR_1} things…$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime: @ 82A8AB1
    .string "Oh…\n"
    .string "Thank you for last time…$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing: @ 82A8ACE
    .string "Before, I think it was {STR_VAR_3}…\p"
    .string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
    .string "saying it was {STR_VAR_1}.\p"
    .string "But it wasn't {STR_VAR_1}.\n"
    .string "Not in the least bit.$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing: @ 82A8B36
    .string "Before, {STR_VAR_3} gave me a very\n"
    .string "{STR_VAR_1} {STR_VAR_2}.\p"
    .string "I cherish it now.$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing: @ 82A8B69
    .string "Listen, if you have anything that\n"
    .string "is {STR_VAR_1}, will you share it\l"
    .string "with me?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe: @ 82A8BAD
    .string "…Really?\n"
    .string "What will you give me?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye: @ 82A8BCD
    .string "Is that so?\n"
    .string "Then, it's good-bye…$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare: @ 82A8BEE
    .string "Oh…\n"
    .string "You're not willing to share?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt: @ 82A8C0F
    .string "Oh?\n"
    .string "That {STR_VAR_2} is {STR_VAR_1}?\p"
    .string "…Oh, is that right?\p"
    .string "Well, I owe you a thanks anyway.\n"
    .string "I'll try to cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis: @ 82A8C6F
    .string "Oh…\p"
    .string "That's a quite {STR_VAR_1}\n"
    .string "{STR_VAR_2}…\p"
    .string "Isn't it nice?\n"
    .string "It's so dreamy…\p"
    .string "Thank you…\n"
    .string "I will cherish this…$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis: @ 82A8CC8
    .string "…Oh, oh, oh…\p"
    .string "This is amazing!\n"
    .string "This really is {STR_VAR_1}!\p"
    .string "I never knew that one {STR_VAR_2}\n"
    .string "could be this {STR_VAR_1}!\p"
    .string "Thank you!\p"
    .string "I will treasure this for the rest\n"
    .string "of my life!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn: @ 82A8D5D
    .string "I'll give you this wonderful item in\n"
    .string "return for your fabulous gift.\p"
    .string "I hope you will cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt: @ 82A8DBD
    .string "Oh, you can't have it if you don't have\n"
    .string "the space for it.\p"
    .string "Please come see me when you get\n"
    .string "your BAG organized…$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady: @ 82A8E2B
    .string "I'm the QUIZ LADY!\n"
    .string "I love quizzes!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz: @ 82A8E4E
    .string "Oh?\p"
    .string "I'm waiting for a challenger to answer\n"
    .string "the quiz you made.\p"
    .string "We can chat another time, okay?$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger: @ 82A8EAC
    .string "I'm waiting for someone to challenge\n"
    .string "a quiz this {STR_VAR_1} thought up!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge: @ 82A8EEC
    .string "If you answer correctly, you can win\n"
    .string "fabulous prizes!\p"
    .string "Would you like to take the quiz\n"
    .string "challenge?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer: @ 82A8F4D
    .string "… … … … … …\n"
    .string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye: @ 82A8F65
    .string "Oh, how boring!\n"
    .string "Bye-bye!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit: @ 82A8F7E
    .string "Awww!\n"
    .string "You're going to quit?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime: @ 82A8F9A
    .string "Please take the quiz challenge\n"
    .string "another time!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight: @ 82A8FC7
    .string "You're amazing! You've got it right!\n"
    .string "You're one sharp customer!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize: @ 82A9007
    .string "Congratulations!\n"
    .string "You've got the quiz right!\p"
    .string "You've won a prize provided by\n"
    .string "{STR_VAR_1}!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY: @ 82A9056
    .string "{STR_VAR_1} received\n"
    .string "one {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp: @ 82A906A
    .string "Oh? Your BAG is filled up!\n"
    .string "Come see me when you have room.$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs: @ 82A90A5
    .string "Hmm… Wrong!\n"
    .string "The correct answer is “{STR_VAR_3}”!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize: @ 82A90CD
    .string "Too bad!\p"
    .string "I get to keep the quiz prize\n"
    .string "{STR_VAR_1} now!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz: @ 82A90FB
    .string "Listen, listen!\n"
    .string "Would you like to make your own quiz?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime: @ 82A9131
    .string "Oh, I see…\n"
    .string "Well, maybe next time!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize: @ 82A9153
    .string "Okay, the first thing you have to do\n"
    .string "is pick the prize for the person that\l"
    .string "answers your quiz correctly.\p"
    .string "But beware, if the person taking\n"
    .string "the quiz can't get it right, I get to\l"
    .string "keep the prize!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize: @ 82A9212
    .string "If you don't choose a prize,\n"
    .string "your quiz can't be made.\p"
    .string "Are you going to quit making\n"
    .string "your quiz?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz: @ 82A9270
    .string "Oh, how nice!\n"
    .string "That's a wonderful prize!\p"
    .string "Next, you need to write your quiz\n"
    .string "question and its answer.$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion: @ 82A92D3
    .string "Are you going to quit writing\n"
    .string "your quiz question?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer: @ 82A9305
    .string "Are you going to quit choosing\n"
    .string "your quiz answer?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger: @ 82A9336
    .string "Thank you!\n"
    .string "You've put together a nice quiz.\p"
    .string "I'll go look for someone who'll take\n"
    .string "your quiz challenge right away.$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady: @ 82A93A7
    .string "I'm the CONTEST LADY!\n"
    .string "I sure do love CONTESTS!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock: @ 82A93D6
    .string "Thanks for your {POKEBLOCK} before!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality: @ 82A93F4
    .string "This is my friend {STR_VAR_1}!\n"
    .string "It's the epitome of {STR_VAR_2}!\p"
    .string "But I think that it will display\n"
    .string "even more {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase: @ 82A9451
    .string "So, I need your help!\p"
    .string "Please, may I have one {POKEBLOCK}?\n"
    .string "All I'm asking for is one!\p"
    .string "…Oh, but…\n"
    .string "Don't you have a {POKEBLOCK} CASE?\l"
    .string "That's no good. Next time, then!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock: @ 82A94E8
    .string "So, I need your help!\p"
    .string "Please, may I have one {POKEBLOCK}?\n"
    .string "All I'm asking for is one!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock: @ 82A9537
    .string "Awww!\n"
    .string "I can't have one {POKEBLOCK}?!$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate: @ 82A9556
    .string "Sheesh!\n"
    .string "What a cheapskate!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock: @ 82A9571
    .string "Yay!\n"
    .string "Thank you!\p"
    .string "I'll feed my POKéMON your {POKEBLOCK}\n"
    .string "right away.$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks: @ 82A95AD
    .string "…It doesn't seem to have changed\n"
    .string "in any way at all…\p"
    .string "Hmm…\p"
    .string "Oh, well!\n"
    .string "Thank you very much!$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks: @ 82A9605
    .string "Oh, yay!\n"
    .string "It's really delighted!\p"
    .string "I think it really improved {STR_VAR_1}'s\n"
    .string "{STR_VAR_2} quality, too.\p"
    .string "Thank you so much!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests: @ 82A9669
    .string "Hmm…\p"
    .string "I think we may be ready to enter\n"
    .string "some CONTESTS.\p"
    .string "If you see us in one somewhere,\n"
    .string "I hope you'll cheer for us.$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon: @ 82A96DA
    .string "{STR_VAR_1}: Guguuh!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon: @ 82A96E6
    .string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena: @ 82A96F6
    .string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu: @ 82A9703
    .string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty: @ 82A970E
    .string "{STR_VAR_1}: Umyaaaan!$"
