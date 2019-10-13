LilycoveCity_PokemonCenter_1F_EventScript_2A836B:: @ 82A836B
    special Script_GetLilycoveLadyId
    switch VAR_RESULT
    case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_2A8554
    case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_2A8395
    case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_2A882A
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8395:: @ 82A8395
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8A69, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetFavorLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83D0
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83C6
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8510
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A83C6:: @ 82A83C6
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8AB1, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A83D0:: @ 82A83D0
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8A7D, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8435
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83F7
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A83F7:: @ 82A83F7
    special BufferFavorLadyItemName
    special BufferFavorLadyPlayerName
    specialvar VAR_RESULT, DidFavorLadyLikeItem
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8419
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8427
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8419:: @ 82A8419
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8ACE, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8435
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8427:: @ 82A8427
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8B36, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8435
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8435:: @ 82A8435
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8B69, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A845E
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8454:: @ 82A8454
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BCD, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A845E:: @ 82A845E
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BAD, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A846C
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A846C:: @ 82A846C
    fadescreen 1
    setvar VAR_RESULT, 0
    special Script_FavorLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A848E
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84AD
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A848E:: @ 82A848E
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BEE, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A846C
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A84AD:: @ 82A84AD
    specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84C9
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84D6
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A84C9:: @ 82A84C9
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8C0F, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A84D6:: @ 82A84D6
    specialvar VAR_RESULT, IsFavorLadyThresholdMet
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84F2
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84FF
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A84F2:: @ 82A84F2
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8C6F, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A84FF:: @ 82A84FF
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8CC8, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8510
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8510:: @ 82A8510
    setvar VAR_0x8004, 0
    specialvar VAR_0x8004, FavorLadyGetPrize
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8D5D, MSGBOX_DEFAULT
    giveitem_std VAR_0x8004
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8545
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A854F
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8545:: @ 82A8545
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8DBD, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A854F:: @ 82A854F
    special SetFavorLadyState_Complete
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8554:: @ 82A8554
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8E2B, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetQuizLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8585
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85AC
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86EC
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8585:: @ 82A8585
    specialvar VAR_RESULT, GetQuizAuthor
    compare VAR_RESULT, QUIZ_AUTHOR_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85C8
    compare VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85D2
    compare VAR_RESULT, QUIZ_AUTHOR_LADY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85E0
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A85AC:: @ 82A85AC
    specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8759
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85C8
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A85C8:: @ 82A85C8
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8E4E, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A85D2:: @ 82A85D2
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EAC, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A85EE
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A85E0:: @ 82A85E0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EAC, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A85EE
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A85EE:: @ 82A85EE
    setvar VAR_0x8004, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EEC, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A861C
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8612
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8612:: @ 82A8612
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F65, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A861C:: @ 82A861C
    special ClearQuizLadyPlayerAnswer
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A864C
    compare VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8656

LilycoveCity_PokemonCenter_1F_EventScript_2A8635:: @ 82A8635
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8660
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8689
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A864C:: @ 82A864C
    special QuizLadyShowQuizQuestion
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8635
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8656:: @ 82A8656
    special QuizLadyGetPlayerAnswer
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8635
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8660:: @ 82A8660
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F7E, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A867F
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A861C
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A867F:: @ 82A867F
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F9A, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8689:: @ 82A8689
    special SetQuizLadyState_Complete
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F4D, MSGBOX_DEFAULT
    specialvar VAR_RESULT, IsQuizAnswerCorrect
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86C7
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86B0
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A86B0:: @ 82A86B0
    playse SE_SEIKAI
    delay 10
    playse SE_SEIKAI
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A8FC7, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A86EC
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A86C7:: @ 82A86C7
    special BufferQuizCorrectAnswer
    special BufferQuizPrizeName
    playse SE_HAZURE
    delay 10
    playse SE_HAZURE
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A90A5, MSGBOX_DEFAULT
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A90CD, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8759
    end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_2A86EC:: @ 82A86EC
    specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8708
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8716
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8708:: @ 82A8708
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9007, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8724
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8716:: @ 82A8716
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9007, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8724
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8724:: @ 82A8724
    setvar VAR_0x8005, 0
    special BufferQuizPrizeItem
    special SetQuizLadyState_Complete
    giveitem_std VAR_0x8005
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A874C
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8759
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A874C:: @ 82A874C
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A906A, MSGBOX_DEFAULT
    special SetQuizLadyState_GivePrize
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8759:: @ 82A8759
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A90FB, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8785
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8778:: @ 82A8778
    special QuizLadyPickNewQuestion
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9131, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8785:: @ 82A8785
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9153, MSGBOX_DEFAULT

LilycoveCity_PokemonCenter_1F_EventScript_2A878D:: @ 82A878D
    fadescreen 1
    setvar VAR_RESULT, 0
    special Script_QuizLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87AF
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87CE
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A87AF:: @ 82A87AF
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9212, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A878D
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A87CE:: @ 82A87CE
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9270, MSGBOX_DEFAULT
    special ClearQuizLadyQuestionAndAnswer
    special ClearQuizLadyPlayerAnswer
    setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION

LilycoveCity_PokemonCenter_1F_EventScript_2A87E1:: @ 82A87E1
    fadescreen 1
    special QuizLadySetCustomQuestion
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87F8
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A8817
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A87F8:: @ 82A87F8
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A92D3, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87E1
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8817:: @ 82A8817
    special QuizLadyTakePrizeForCustomQuiz
    special QuizLadyRecordCustomQuizData
    special QuizLadySetWaitingForChallenger
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9336, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A882A:: @ 82A882A
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A93A7, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8850
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A886C
    end

@ Redundant with above script, VAR_RESULT will always be 0 here
LilycoveCity_PokemonCenter_1F_EventScript_2A8850:: @ 82A8850
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8876
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A886C
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A886C:: @ 82A886C
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A93D6, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8876:: @ 82A8876
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A93F4, MSGBOX_DEFAULT
    checkitem ITEM_POKEBLOCK_CASE, 1
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A89AE
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A94E8, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88BA
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A88B0:: @ 82A88B0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9556, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A88BA:: @ 82A88BA
    fadescreen 1
    special OpenPokeblockCaseForContestLady
    waitstate
    compare VAR_RESULT, 0xFFFF
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88D7
    compare VAR_RESULT, 0xFFFF
    goto_if_ne LilycoveCity_PokemonCenter_1F_EventScript_2A88F6
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A88D7:: @ 82A88D7
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9537, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88BA
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A88F6:: @ 82A88F6
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9571, MSGBOX_DEFAULT
    special SetContestLadyGivenPokeblock
    special GetContestLadyMonSpecies
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A890A
    end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_2A890A:: @ 82A890A
    applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_2A89B8
    waitmovement 0
    delay 60
    applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_2A89BB
    waitmovement 0
    delay 60
    waitse
    playmoncry VAR_0x8005, 0
    delay 120
    waitmoncry
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A893F
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A894C
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A893F:: @ 82A893F
    applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_2A89C2
    waitmovement 0
    delay 60

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_2A894C:: @ 82A894C
    applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_2A89C0
    waitmovement 0
    delay 60
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8970
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A897E
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8970:: @ 82A8970
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A95AD, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A898F
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A897E:: @ 82A897E
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9605, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_2A898F
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A898F:: @ 82A898F
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A89A1
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A89A1:: @ 82A89A1
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9669, MSGBOX_DEFAULT
    special PutLilycoveContestLadyShowOnTheAir
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A89AE:: @ 82A89AE
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9451, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_Movement_2A89B8: @ 82A89B8
    face_right
    delay_8
    step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89BB: @ 82A89BB
    face_left
    delay_8
    step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89BE: @ 82A89BE
    face_down
    step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89C0: @ 82A89C0
    face_player
    step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89C2: @ 82A89C2
    disable_jump_landing_ground_effect
    jump_in_place_left
    disable_jump_landing_ground_effect
    jump_in_place_left
    step_end

LilycoveCity_PokemonCenter_1F_EventScript_2A89C7:: @ 82A89C7
    specialvar VAR_RESULT, GetContestLadyCategory
    special Script_BufferContestLadyCategoryAndMonName
    special GetContestLadyMonSpecies
    compare VAR_RESULT, CONTEST_CATEGORY_COOL
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A0A
    compare VAR_RESULT, CONTEST_CATEGORY_BEAUTY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A1D
    compare VAR_RESULT, CONTEST_CATEGORY_CUTE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A30
    compare VAR_RESULT, CONTEST_CATEGORY_SMART
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A43
    compare VAR_RESULT, CONTEST_CATEGORY_TOUGH
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A56
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A0A:: @ 82A8A0A
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A96DA, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A1D:: @ 82A8A1D
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A970E, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A30:: @ 82A8A30
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A96F6, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A43:: @ 82A8A43
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A96E6, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A56:: @ 82A8A56
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_2A9703, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_Text_2A8A69: @ 82A8A69
    .string "I'm the FAVOR LADY…$"

LilycoveCity_PokemonCenter_1F_Text_2A8A7D: @ 82A8A7D
    .string "I've recently developed an obsession\n"
    .string "for {STR_VAR_1} things…$"

LilycoveCity_PokemonCenter_1F_Text_2A8AB1: @ 82A8AB1
    .string "Oh…\n"
    .string "Thank you for last time…$"

LilycoveCity_PokemonCenter_1F_Text_2A8ACE: @ 82A8ACE
    .string "Before, I think it was {STR_VAR_3}…\p"
    .string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
    .string "saying it was {STR_VAR_1}.\p"
    .string "But it wasn't {STR_VAR_1}.\n"
    .string "Not in the least bit.$"

LilycoveCity_PokemonCenter_1F_Text_2A8B36: @ 82A8B36
    .string "Before, {STR_VAR_3} gave me a very\n"
    .string "{STR_VAR_1} {STR_VAR_2}.\p"
    .string "I cherish it now.$"

LilycoveCity_PokemonCenter_1F_Text_2A8B69: @ 82A8B69
    .string "Listen, if you have anything that\n"
    .string "is {STR_VAR_1}, will you share it\l"
    .string "with me?$"

LilycoveCity_PokemonCenter_1F_Text_2A8BAD: @ 82A8BAD
    .string "…Really?\n"
    .string "What will you give me?$"

LilycoveCity_PokemonCenter_1F_Text_2A8BCD: @ 82A8BCD
    .string "Is that so?\n"
    .string "Then, it's good-bye…$"

LilycoveCity_PokemonCenter_1F_Text_2A8BEE: @ 82A8BEE
    .string "Oh…\n"
    .string "You're not willing to share?$"

LilycoveCity_PokemonCenter_1F_Text_2A8C0F: @ 82A8C0F
    .string "Oh?\n"
    .string "That {STR_VAR_2} is {STR_VAR_1}?\p"
    .string "…Oh, is that right?\p"
    .string "Well, I owe you a thanks anyway.\n"
    .string "I'll try to cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_2A8C6F: @ 82A8C6F
    .string "Oh…\p"
    .string "That's a quite {STR_VAR_1}\n"
    .string "{STR_VAR_2}…\p"
    .string "Isn't it nice?\n"
    .string "It's so dreamy…\p"
    .string "Thank you…\n"
    .string "I will cherish this…$"

LilycoveCity_PokemonCenter_1F_Text_2A8CC8: @ 82A8CC8
    .string "…Oh, oh, oh…\p"
    .string "This is amazing!\n"
    .string "This really is {STR_VAR_1}!\p"
    .string "I never knew that one {STR_VAR_2}\n"
    .string "could be this {STR_VAR_1}!\p"
    .string "Thank you!\p"
    .string "I will treasure this for the rest\n"
    .string "of my life!$"

LilycoveCity_PokemonCenter_1F_Text_2A8D5D: @ 82A8D5D
    .string "I'll give you this wonderful item in\n"
    .string "return for your fabulous gift.\p"
    .string "I hope you will cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_2A8DBD: @ 82A8DBD
    .string "Oh, you can't have it if you don't have\n"
    .string "the space for it.\p"
    .string "Please come see me when you get\n"
    .string "your BAG organized…$"

LilycoveCity_PokemonCenter_1F_Text_2A8E2B: @ 82A8E2B
    .string "I'm the QUIZ LADY!\n"
    .string "I love quizzes!$"

LilycoveCity_PokemonCenter_1F_Text_2A8E4E: @ 82A8E4E
    .string "Oh?\p"
    .string "I'm waiting for a challenger to answer\n"
    .string "the quiz you made.\p"
    .string "We can chat another time, okay?$"

LilycoveCity_PokemonCenter_1F_Text_2A8EAC: @ 82A8EAC
    .string "I'm waiting for someone to challenge\n"
    .string "a quiz this {STR_VAR_1} thought up!$"

LilycoveCity_PokemonCenter_1F_Text_2A8EEC: @ 82A8EEC
    .string "If you answer correctly, you can win\n"
    .string "fabulous prizes!\p"
    .string "Would you like to take the quiz\n"
    .string "challenge?$"

LilycoveCity_PokemonCenter_1F_Text_2A8F4D: @ 82A8F4D
    .string "… … … … … …\n"
    .string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_2A8F65: @ 82A8F65
    .string "Oh, how boring!\n"
    .string "Bye-bye!$"

LilycoveCity_PokemonCenter_1F_Text_2A8F7E: @ 82A8F7E
    .string "Awww!\n"
    .string "You're going to quit?$"

LilycoveCity_PokemonCenter_1F_Text_2A8F9A: @ 82A8F9A
    .string "Please take the quiz challenge\n"
    .string "another time!$"

LilycoveCity_PokemonCenter_1F_Text_2A8FC7: @ 82A8FC7
    .string "You're amazing! You've got it right!\n"
    .string "You're one sharp customer!$"

LilycoveCity_PokemonCenter_1F_Text_2A9007: @ 82A9007
    .string "Congratulations!\n"
    .string "You've got the quiz right!\p"
    .string "You've won a prize provided by\n"
    .string "{STR_VAR_1}!$"

LilycoveCity_PokemonCenter_1F_Text_2A9056: @ 82A9056
    .string "{STR_VAR_1} received\n"
    .string "one {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_2A906A: @ 82A906A
    .string "Oh? Your BAG is filled up!\n"
    .string "Come see me when you have room.$"

LilycoveCity_PokemonCenter_1F_Text_2A90A5: @ 82A90A5
    .string "Hmm… Wrong!\n"
    .string "The correct answer is “{STR_VAR_3}”!$"

LilycoveCity_PokemonCenter_1F_Text_2A90CD: @ 82A90CD
    .string "Too bad!\p"
    .string "I get to keep the quiz prize\n"
    .string "{STR_VAR_1} now!$"

LilycoveCity_PokemonCenter_1F_Text_2A90FB: @ 82A90FB
    .string "Listen, listen!\n"
    .string "Would you like to make your own quiz?$"

LilycoveCity_PokemonCenter_1F_Text_2A9131: @ 82A9131
    .string "Oh, I see…\n"
    .string "Well, maybe next time!$"

LilycoveCity_PokemonCenter_1F_Text_2A9153: @ 82A9153
    .string "Okay, the first thing you have to do\n"
    .string "is pick the prize for the person that\l"
    .string "answers your quiz correctly.\p"
    .string "But beware, if the person taking\n"
    .string "the quiz can't get it right, I get to\l"
    .string "keep the prize!$"

LilycoveCity_PokemonCenter_1F_Text_2A9212: @ 82A9212
    .string "If you don't choose a prize,\n"
    .string "your quiz can't be made.\p"
    .string "Are you going to quit making\n"
    .string "your quiz?$"

LilycoveCity_PokemonCenter_1F_Text_2A9270: @ 82A9270
    .string "Oh, how nice!\n"
    .string "That's a wonderful prize!\p"
    .string "Next, you need to write your quiz\n"
    .string "question and its answer.$"

LilycoveCity_PokemonCenter_1F_Text_2A92D3: @ 82A92D3
    .string "Are you going to quit writing\n"
    .string "your quiz question?$"

LilycoveCity_PokemonCenter_1F_Text_2A9305: @ 82A9305
    .string "Are you going to quit choosing\n"
    .string "your quiz answer?$"

LilycoveCity_PokemonCenter_1F_Text_2A9336: @ 82A9336
    .string "Thank you!\n"
    .string "You've put together a nice quiz.\p"
    .string "I'll go look for someone who'll take\n"
    .string "your quiz challenge right away.$"

LilycoveCity_PokemonCenter_1F_Text_2A93A7: @ 82A93A7
    .string "I'm the CONTEST LADY!\n"
    .string "I sure do love CONTESTS!$"

LilycoveCity_PokemonCenter_1F_Text_2A93D6: @ 82A93D6
    .string "Thanks for your {POKEBLOCK} before!$"

LilycoveCity_PokemonCenter_1F_Text_2A93F4: @ 82A93F4
    .string "This is my friend {STR_VAR_1}!\n"
    .string "It's the epitome of {STR_VAR_2}!\p"
    .string "But I think that it will display\n"
    .string "even more {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_2A9451: @ 82A9451
    .string "So, I need your help!\p"
    .string "Please, may I have one {POKEBLOCK}?\n"
    .string "All I'm asking for is one!\p"
    .string "…Oh, but…\n"
    .string "Don't you have a {POKEBLOCK} CASE?\l"
    .string "That's no good. Next time, then!$"

LilycoveCity_PokemonCenter_1F_Text_2A94E8: @ 82A94E8
    .string "So, I need your help!\p"
    .string "Please, may I have one {POKEBLOCK}?\n"
    .string "All I'm asking for is one!$"

LilycoveCity_PokemonCenter_1F_Text_2A9537: @ 82A9537
    .string "Awww!\n"
    .string "I can't have one {POKEBLOCK}?!$"

LilycoveCity_PokemonCenter_1F_Text_2A9556: @ 82A9556
    .string "Sheesh!\n"
    .string "What a cheapskate!$"

LilycoveCity_PokemonCenter_1F_Text_2A9571: @ 82A9571
    .string "Yay!\n"
    .string "Thank you!\p"
    .string "I'll feed my POKéMON your {POKEBLOCK}\n"
    .string "right away.$"

LilycoveCity_PokemonCenter_1F_Text_2A95AD: @ 82A95AD
    .string "…It doesn't seem to have changed\n"
    .string "in any way at all…\p"
    .string "Hmm…\p"
    .string "Oh, well!\n"
    .string "Thank you very much!$"

LilycoveCity_PokemonCenter_1F_Text_2A9605: @ 82A9605
    .string "Oh, yay!\n"
    .string "It's really delighted!\p"
    .string "I think it really improved {STR_VAR_1}'s\n"
    .string "{STR_VAR_2} quality, too.\p"
    .string "Thank you so much!$"

LilycoveCity_PokemonCenter_1F_Text_2A9669: @ 82A9669
    .string "Hmm…\p"
    .string "I think we may be ready to enter\n"
    .string "some CONTESTS.\p"
    .string "If you see us in one somewhere,\n"
    .string "I hope you'll cheer for us.$"

LilycoveCity_PokemonCenter_1F_Text_2A96DA: @ 82A96DA
    .string "{STR_VAR_1}: Guguuh!$"

LilycoveCity_PokemonCenter_1F_Text_2A96E6: @ 82A96E6
    .string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_2A96F6: @ 82A96F6
    .string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCenter_1F_Text_2A9703: @ 82A9703
    .string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCenter_1F_Text_2A970E: @ 82A970E
    .string "{STR_VAR_1}: Umyaaaan!$"
