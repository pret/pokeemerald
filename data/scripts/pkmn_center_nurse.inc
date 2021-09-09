Common_EventScript_PkmnCenterNurse::
    lock
    faceplayer
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, CountPlayerTrainerStars
    compare VAR_RESULT, 4
    goto_if_eq EventScript_PkmnCenterNurse_GoldCard
    msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_HealPkmn
    compare VAR_RESULT, NO
    goto_if_eq EventScript_PkmnCenterNurse_Goodbye
    end

EventScript_PkmnCenterNurse_Goodbye::
    message gText_WeHopeToSeeYouAgain
    return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
    incrementgamestat GAME_STAT_USED_POKECENTER
    compare VAR_0x8004, 0
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn
    compare VAR_0x8004, 1
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn2
    waitmessage
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
    goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
    message gText_IllTakeYourPkmn
    return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
    message gText_IllTakeYourPkmn2
    return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    waitfieldeffect FLDEFF_POKECENTER_HEAL
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
    waitmovement 0
    special HealPlayerParty
    return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    compare VAR_RESULT, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    compare VAR_0x8008, 1
    goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
    compare VAR_0x8004, 1
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn2
    message gText_RestoredPkmnToFullHealth
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_ReturnPkmn2::
    message gText_ThankYouForWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
    msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_CheckPokerus::
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_ExplainPokerus::
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    return

EventScript_PkmnCenterNurse_GoldCard::
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_0x800B, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_0x800B, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_AskForUsual::
    msgbox gText_YouWantTheUsual, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

Movement_PkmnCenterNurse_Bow:
    nurse_joy_bow
    delay_4
    step_end
