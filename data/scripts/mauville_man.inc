MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan:: @ 828E066
	special ScrSpecial_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard:: @ 828E0A6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong:: @ 828E0C7
	setvar VAR_0x8004, 0
	special ScrSpecial_PlayBardSong
	delay 60
	special ScrSpecial_HasBardSongBeenChanged
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong:: @ 828E0EA
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics:: @ 828E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics:: @ 828E113
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

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics:: @ 828E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster:: @ 828E167
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

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord:: @ 828E18C
	special ScrSpecial_HipsterTeachWord
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord:: @ 828E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special ScrSpecial_SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor: @ 828E1B1
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues: @ 828E1E8
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded: @ 828E20E
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem: @ 828E23F
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything: @ 828E27F
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt: @ 828E2A9
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor: @ 828E2E3
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade: @ 828E323
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade: @ 828E356
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis: @ 828E380
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor: @ 828E3C4
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse: @ 828E3EC
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC: @ 828E424
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne: @ 828E45A
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader:: @ 828E4D4
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

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade:: @ 828E503
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded:: @ 828E50D
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive:: @ 828E517
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

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor:: @ 828E558
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor:: @ 828E562
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor:: @ 828E56E
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor:: @ 828E57A
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive:: @ 828E584
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

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor:: @ 828E5D4
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse:: @ 828E5DE
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor:: @ 828E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale: @ 828E5F6
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues: @ 828E64D
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell: @ 828E673
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales: @ 828E6AE
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes: @ 828E726
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends: @ 828E78A
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales: @ 828E7EE
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale: @ 828E844
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend: @ 828E881
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested: @ 828E8D9
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle:: @ 828E930
	.string "The Save-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction:: @ 828E947
	.string "Saved the game$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory:: @ 828E956
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious TRAINER than\n"
	.string "{STR_VAR_3} one will never find!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle:: @ 828E9D7
	.string "The Trendsetter TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction:: @ 828E9EF
	.string "Started trends$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory:: @ 828E9FE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the HOENN region!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle:: @ 828EA7D
    .string "The BERRY-Planting TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction:: @ 828EA98
	.string "Planted BERRIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory:: @ 828EAA8
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER planted BERRIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "BERRIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle:: @ 828EB19
	.string "The BIKE-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction:: @ 828EB31
	.string "Traded BIKES$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory:: @ 828EB3E
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER swapped BIKES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love BIKES deeply\n"
	.string "and passionately!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle:: @ 828EBB5
	.string "The Interviewed TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction:: @ 828EBCD
	.string "Got interviewed$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory:: @ 828EBDD
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who's\n"
	.string "attracting much attention!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle:: @ 828EC60
	.string "The Battle-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction:: @ 828EC79
	.string "Battled$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory:: @ 828EC81
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who can\n"
	.string "never refuse a chance to battle!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle:: @ 828ED04
	.string "The POKéMON-Catching TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction:: @ 828ED21
	.string "Caught POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory:: @ 828ED30
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle:: @ 828EDA1
	.string "The Fishing TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction:: @ 828EDB5
	.string "Caught POKéMON with a ROD$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory:: @ 828EDCF
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle:: @ 828EE45
	.string "The EGG-Warming TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction:: @ 828EE5D
	.string "Hatched EGGS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory:: @ 828EE6A
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER hatched {STR_VAR_1} POKéMON\n"
	.string "from EGGS!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of EGGS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle:: @ 828EEDD
	.string "The Evolver TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction:: @ 828EEF1
	.string "Evolved POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory:: @ 828EF01
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {STR_VAR_1} POKéMON\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle:: @ 828EF73
	.string "The POKéMON CENTER-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction:: @ 828EF95
	.string "Used POKéMON CENTERS$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory:: @ 828EFAA
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at POKéMON CENTERS!\p"
	.string "There could be no greater lover of\n"
	.string "POKéMON CENTERS than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle:: @ 828F045
	.string "The Homebody TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction:: @ 828F05A
	.string "Rested POKéMON at home$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory:: @ 828F071
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle:: @ 828F0F3
	.string "The SAFARI-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction:: @ 828F10D
	.string "Entered the SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory:: @ 828F125
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER went into the SAFARI ZONE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER whose wild side\n"
	.string "must come out in the SAFARI ZONE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle:: @ 828F1BE
	.string "The CUT-Frenzy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction:: @ 828F1D5
	.string "Used CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory:: @ 828F1DE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used CUT\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who just must\n"
	.string "love to CUT!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle:: @ 828F24F
	.string "The ROCK-SMASHING TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction:: @ 828F269
	.string "Smashed rocks$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory:: @ 828F277
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used ROCK SMASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "can't leave a stone unsmashed!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle:: @ 828F2FC
	.string "The Move-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction:: @ 828F314
	.string "Moved the SECRET BASE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory:: @ 828F32A
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER moved the SECRET BASE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who loves\n"
	.string "to move houses often!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle:: @ 828F3AD
	.string "The SPLASH-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction:: @ 828F3C6
	.string "Used SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory:: @ 828F3D2
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used SPLASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who must love\n"
	.string "SPLASHING around!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle:: @ 828F44B
	.string "The Tenacious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction:: @ 828F461
	.string "Resorted to using STRUGGLE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory:: @ 828F47C
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER had to rely on STRUGGLE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious TRAINER\n"
	.string "who never gives in to adversity!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle:: @ 828F50C
	.string "The SLOT Champ$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction:: @ 828F51B
	.string "Won the jackpot on the SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory:: @ 828F538
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won the jackpot on\n"
	.string "the SLOTS {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a TRAINER who was lucky\n"
	.string "on the SLOTS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle:: @ 828F5BE
	.string "The ROULETTE Champ$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction:: @ 828F5D1
	.string "Had consecutive ROULETTE wins of$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory:: @ 828F5F2
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won in ROULETTE\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle:: @ 828F678
	.string "The BATTLE TOWER Challenger$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction:: @ 828F694
	.string "Took the BATTLE TOWER challenge$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory:: @ 828F6B4
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER took the BATTLE TOWER\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who aspires\n"
	.string "for excellence in the BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle:: @ 828F751
	.string "The Blend-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction:: @ 828F76A
	.string "Made {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory:: @ 828F776
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {POKEBLOCK}S\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a BERRY\n"
	.string "BLENDER than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle:: @ 828F7F6
	.string "The CONTEST-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction:: @ 828F811
	.string "Entered CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory:: @ 828F822
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER entered CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "POKéMON to others!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle:: @ 828F89C
	.string "The CONTEST Master$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction:: @ 828F8AF
	.string "Won CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory:: @ 828F8BC
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "CONTEST master!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle:: @ 828F92F
	.string "The Happy Shopper$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction:: @ 828F941
	.string "Shopped$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory:: @ 828F949
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle:: @ 828F9D1
	.string "The Item-Finding TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction:: @ 828F9EA
	.string "Used an ITEMFINDER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory:: @ 828F9FD
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used an ITEMFINDER\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle:: @ 828FA81
	.string "The Rain-Soaked TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction:: @ 828FA99
	.string "Got rained on$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory:: @ 828FAA7
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle:: @ 828FB1D
	.string "The Avid POKéDEX Reader$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction:: @ 828FB35
	.string "Checked a POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory:: @ 828FB47
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked a POKéDEX\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "POKéMON in a POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle:: @ 828FBC4
	.string "The RIBBON Collector$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction:: @ 828FBD9
	.string "Received RIBBONS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory:: @ 828FBEA
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER received RIBBONS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "loves to collect RIBBONS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle:: @ 828FC6B
	.string "The Ledge-Jumping TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction:: @ 828FC85
	.string "Jumped down ledges$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory:: @ 828FC98
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle:: @ 828FD1D
	.string "The Legendary TV Viewer$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction:: @ 828FD35
	.string "Watched TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory:: @ 828FD40
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle:: @ 828FDA2
	.string "The Time-Conscious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction:: @ 828FDBD
	.string "Checked the time$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory:: @ 828FDCE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual TRAINER\n"
	.string "who's conscious of the time.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle:: @ 828FE57
	.string "The POKéMON LOTTERY Wizard$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction:: @ 828FE72
	.string "Won POKéMON LOTTERIES$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory:: @ 828FE88
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won POKéMON LOTTERIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade POKéMON with!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle:: @ 828FF0C
	.string "The DAY CARE-Using Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction:: @ 828FF27
	.string "Left POKéMON at the DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory:: @ 828FF44
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER left POKéMON with the\n"
	.string "DAY CARE {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises POKéMON aggressively!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle:: @ 828FFDD
	.string "The CABLE CAR-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction:: @ 828FFFA
	.string "Rode the CABLE CAR$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory:: @ 829000D
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER rode the CABLE CAR\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy TRAINER\n"
	.string "who's up and down all the time!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle:: @ 8290097
	.string "The Hot Spring-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction:: @ 82900B5
	.string "Bathed in hot springs$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory:: @ 82900CB
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER with\n"
	.string "baby-smooth skin!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller:: @ 829014A
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

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection:: @ 82901B7
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales:: @ 82901BD
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, ScrSpecial_HasStorytellerAlreadyRecorded
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales:: @ 82901DA
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales:: @ 82901E2
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, ScrSpecial_StorytellerInitializeRandomStat
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale:: @ 829020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller:: @ 8290219
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix:: @ 8290223
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd:: @ 829022D
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory: @ 829022F
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues: @ 8290281
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking: @ 82902A7
	.string "Also, I was thinking…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain: @ 82902BD
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy:: @ 82902F6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale:: @ 8290317
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale:: @ 8290331
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale:: @ 829034B
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Regardless of whether yes or no is selected below, Giddy will continue to tell stories until he's told 10
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale:: @ 8290359
	special ScrSpecial_GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy:: @ 829037A
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales:: @ 8290384
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong: @ 829038E
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1: @ 82903C0
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers: @ 82903E6
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics: @ 8290421
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2: @ 829049B
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou: @ 82904C1
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo: @ 82904EB
	.string "Was that how you wanted your song\n"
	.string "to go?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile: @ 8290514
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening: @ 829054C
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou: @ 8290598
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach: @ 8290602
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase: @ 8290666
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
