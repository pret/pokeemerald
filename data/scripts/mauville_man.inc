MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
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
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
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
	special GetHipsterSpokenFlag
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special SetHipsterSpokenFlag
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
	.string "You've got all the {STR_VAR_2}s that can\n"
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
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
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
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
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
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
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
	.string "I'm the Storyteller.\n"
	.string "I'll tell you tales of legendary\l"
	.string "Trainers.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "But, I know of no legendary Trainers.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a Trainer worthy\n"
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
	.string "other Trainers with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Are you a Trainer?\p"
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
	.string "Trainers.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "The Save-Happy Trainer$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Saved the game$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious Trainer than\n"
	.string "{STR_VAR_3} one will never find!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "The Trendsetter Trainer$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Started trends$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the Hoenn region!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
    .string "The Berry-Planting Trainer$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Planted Berries$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer planted Berries\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "Berries!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "The Bike-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Traded Bikes$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer swapped Bikes\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love Bikes deeply\n"
	.string "and passionately!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "The Interviewed Trainer$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Got interviewed$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a Trainer who's\n"
	.string "attracting much attention!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "The Battle-Happy Trainer$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Battled$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a Trainer who can\n"
	.string "never refuse a chance to battle!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "The Pokémon-Catching Trainer$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Caught Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer caught\n"
	.string "{STR_VAR_1} Pokémon!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild Pokémon!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "The Fishing Trainer$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Caught Pokémon with a Rod$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer caught\n"
	.string "{STR_VAR_1} Pokémon while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "The Egg-Warming Trainer$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Hatched Eggs$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer hatched {STR_VAR_1} Pokémon\n"
	.string "from Eggs!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of Eggs!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "The Evolver Trainer$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Evolved Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer made {STR_VAR_1} Pokémon\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of Pokémon!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "The Pokémon Center-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Used Pokémon Centers$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer healed Pokémon\n"
	.string "{STR_VAR_1} times at Pokémon Centers!\p"
	.string "There could be no greater lover of\n"
	.string "Pokémon Centers than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "The Homebody Trainer$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Rested Pokémon at home$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer healed Pokémon\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "The Safari-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entered the Safari Zone$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer went into the Safari Zone\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a Trainer whose wild side\n"
	.string "must come out in the Safari Zone!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "The Cut-Frenzy Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Used Cut$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer used Cut\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a Trainer who just must\n"
	.string "love to Cut!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "The Rock-Smashing Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Smashed rocks$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer used Rock Smash\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a Trainer who\n"
	.string "can't leave a stone unsmashed!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "The Move-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Moved the Secret Base$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer moved the Secret Base\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a Trainer who loves\n"
	.string "to move houses often!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "The Splash-Happy Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Used Splash$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer used Splash\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a Trainer who must love\n"
	.string "Splashing around!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "The Tenacious Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Resorted to using Struggle$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer had to rely on Struggle\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious Trainer\n"
	.string "who never gives in to adversity!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "The Slot Champ$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Won the jackpot on the Slots$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer won the jackpot on\n"
	.string "the Slots {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a Trainer who was lucky\n"
	.string "on the Slots!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "The Roulette Champ$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Had consecutive Roulette wins of$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer won in Roulette\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in Roulette!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "The Battle Tower Challenger$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Took the Battle Tower challenge$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer took the Battle Tower\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a Trainer who aspires\n"
	.string "for excellence in the Battle Tower!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "The Blend-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Made {POKEBLOCK}s$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer made {POKEBLOCK}s\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a Berry\n"
	.string "Blender than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "The Contest-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Entered Contests$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer entered Contests\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "Pokémon to others!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "The Contest Master$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Won Contests$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer won Contests\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "Contest master!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "The Happy Shopper$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Shopped$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "The Item-Finding Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Used an Itemfinder$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer used an Itemfinder\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "The Rain-Soaked Trainer$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Got rained on$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "The Avid Pokédex Reader$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Checked a Pokédex$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer checked a Pokédex\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "Pokémon in a Pokédex!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "The Ribbon Collector$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Received Ribbons$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer received Ribbons\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a Trainer who\n"
	.string "loves to collect Ribbons!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "The Ledge-Jumping Trainer$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Jumped down ledges$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "The Legendary TV Viewer$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Watched TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "The Time-Conscious Trainer$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Checked the time$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual Trainer\n"
	.string "who's conscious of the time.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "The Pokémon Lottery Wizard$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Won Pokémon Lotteries$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer won Pokémon Lotteries\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade Pokémon with!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "The Day Care-Using Trainer$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Left Pokémon at the Day Care$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer left Pokémon with the\n"
	.string "Day Care {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises Pokémon aggressively!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "The Cable Car-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Rode the Cable Car$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer rode the Cable Car\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy Trainer\n"
	.string "who's up and down all the time!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "The Hot Spring-Loving Trainer$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Bathed in hot springs$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "This is a tale of a Trainer\n"
	.string "named {STR_VAR_3}.\p"
	.string "This Trainer bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a Trainer with\n"
	.string "baby-smooth skin!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
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
	.string "I'm Giddy!\n"
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
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
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
	.string "Hi, I'm the Bard.\n"
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
	.string "Hey, yo! They call me the Hipster.\n"
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
