MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special ScrSpecial_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special ScrSpecial_PlayBardSong
	delay 60
	special ScrSpecial_HasBardSongBeenChanged
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special ScrSpecial_PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special ScrSpecial_SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special ScrSpecial_GetHipsterSpokenFlag
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special ScrSpecial_HipsterTeachWord
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special ScrSpecial_SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special ScrSpecial_GetTraderTradedFlag
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special ScrSpecial_TraderMenuGetDecoration
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	compare VAR_0x8004, 0xFFFF
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special ScrSpecial_DoesPlayerHaveNoDecorations
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special ScrSpecial_TraderMenuGiveDecoration
	waitstate
	compare VAR_0x8006, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	compare VAR_0x8006, 0xFFFF
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special ScrSpecial_IsDecorationFull
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special ScrSpecial_TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "The Save-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Saved the game$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious TRAINER than\n"
	.string "{STR_VAR_3} one will never find!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "The Trendsetter TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Started trends$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the HOENN region!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
    .string "The BERRY-Planting TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Planted BERRIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER planted BERRIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "BERRIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "The BIKE-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Traded BIKES$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER swapped BIKES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love BIKES deeply\n"
	.string "and passionately!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "The Interviewed TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Got interviewed$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who's\n"
	.string "attracting much attention!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "The Battle-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Battled$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who can\n"
	.string "never refuse a chance to battle!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "The POKéMON-Catching TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Caught POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "The Fishing TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Caught POKéMON with a ROD$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "The EGG-Warming TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Hatched EGGS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER hatched {STR_VAR_1} POKéMON\n"
	.string "from EGGS!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of EGGS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "The Evolver TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Evolved POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {STR_VAR_1} POKéMON\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "The POKéMON CENTER-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Used POKéMON CENTERS$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at POKéMON CENTERS!\p"
	.string "There could be no greater lover of\n"
	.string "POKéMON CENTERS than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "The Homebody TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Rested POKéMON at home$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "The SAFARI-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entered the SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER went into the SAFARI ZONE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER whose wild side\n"
	.string "must come out in the SAFARI ZONE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "The CUT-Frenzy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Used CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used CUT\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who just must\n"
	.string "love to CUT!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "The ROCK-SMASHING TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Smashed rocks$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used ROCK SMASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "can't leave a stone unsmashed!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "The Move-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Moved the SECRET BASE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER moved the SECRET BASE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who loves\n"
	.string "to move houses often!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "The SPLASH-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Used SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used SPLASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who must love\n"
	.string "SPLASHING around!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "The Tenacious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Resorted to using STRUGGLE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER had to rely on STRUGGLE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious TRAINER\n"
	.string "who never gives in to adversity!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "The SLOT Champ$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Won the jackpot on the SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won the jackpot on\n"
	.string "the SLOTS {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a TRAINER who was lucky\n"
	.string "on the SLOTS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "The ROULETTE Champ$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Had consecutive ROULETTE wins of$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won in ROULETTE\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "The BATTLE TOWER Challenger$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Took the BATTLE TOWER challenge$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER took the BATTLE TOWER\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who aspires\n"
	.string "for excellence in the BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "The Blend-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Made {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {POKEBLOCK}S\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a BERRY\n"
	.string "BLENDER than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "The CONTEST-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Entered CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER entered CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "POKéMON to others!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "The CONTEST Master$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Won CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "CONTEST master!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "The Happy Shopper$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Shopped$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "The Item-Finding TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Used an ITEMFINDER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used an ITEMFINDER\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "The Rain-Soaked TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Got rained on$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "The Avid POKéDEX Reader$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Checked a POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked a POKéDEX\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "POKéMON in a POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "The RIBBON Collector$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Received RIBBONS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER received RIBBONS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "loves to collect RIBBONS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "The Ledge-Jumping TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Jumped down ledges$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "The Legendary TV Viewer$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Watched TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "The Time-Conscious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Checked the time$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual TRAINER\n"
	.string "who's conscious of the time.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "The POKéMON LOTTERY Wizard$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Won POKéMON LOTTERIES$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won POKéMON LOTTERIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade POKéMON with!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "The DAY CARE-Using Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Left POKéMON at the DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER left POKéMON with the\n"
	.string "DAY CARE {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises POKéMON aggressively!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "The CABLE CAR-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Rode the CABLE CAR$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER rode the CABLE CAR\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy TRAINER\n"
	.string "who's up and down all the time!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "The Hot Spring-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Bathed in hot springs$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER with\n"
	.string "baby-smooth skin!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, ScrSpecial_StorytellerGetFreeStorySlot
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special ScrSpecial_StorytellerStoryListMenu
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special ScrSpecial_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, ScrSpecial_StorytellerUpdateStat
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, ScrSpecial_HasStorytellerAlreadyRecorded
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, ScrSpecial_StorytellerInitializeRandomStat
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Also, I was thinking…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Regardless of whether yes or no is selected below, Giddy will continue to tell stories until he's told 10
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special ScrSpecial_GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Was that how you wanted your song\n"
	.string "to go?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
