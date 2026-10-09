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
	setvar VAR_0x8004, FALSE  @ Play his current song
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
	setvar VAR_0x8004, TRUE  @ Play the new song
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
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
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
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hoi, ik ben de RUILER.\n"
	.string "Wil je decoraties met me ruilen?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "Nu voel ik me verdrietig…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Maar wij hebben al decoraties\n"
	.string "geruild, jij en ik.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Zie je een decoratie van mij\n"
	.string "die je wilt? Zeg het maar.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Wil je niets?\n"
	.string "Ik voel me niet gewild…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Die decoratie was ooit van\n"
	.string "{STR_VAR_1}.\p"
	.string "Wil je hem?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh… Wacht even. Je hebt geen\n"
	.string "enkele decoratie!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Goed, kies de decoratie die je\n"
	.string "met me ruilt.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Wil je niet ruilen?\n"
	.string "Ik voel me niet gewild…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Je hebt al alle {STR_VAR_2}S die je\n"
	.string "kunt bewaren. Hier is geen plek voor.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Goed, dus we ruilen mijn {STR_VAR_3}\n"
	.string "voor jouw {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Die decoratie is in gebruik.\n"
	.string "Je kunt hem niet ruilen.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Dan ruilen we!\n"
	.string "Ik stuur mijn decoratie naar je PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oeps! Sorry! Dat is een heel\n"
	.string "zeldzame decoratie.\l"
	.string "Die kan ik niet weggeven!\p"
	.string "Wil je iets anders?$"

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
	.string "Ik ben de VERTELLER.\n"
	.string "Ik vertel verhalen over legendarische\l"
	.string "TRAINERS.\p"
	.string "Wil je mijn verhaal horen?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "Nu voel ik me verdrietig…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Ik ken deze legenden.\n"
	.string "Welk verhaal wil je horen?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Maar ik ken geen legendarische\n"
	.string "TRAINERS. Dus geen verhalen.\p"
	.string "Waar vind je een TRAINER die een\n"
	.string "legende waard is?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Wat?!\n"
	.string "Jij… Jij…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} keer?!\p"
	.string "Dat is geweldig!\n"
	.string "Dit is het begin van een legende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Ik vraag me af of er TRAINERS zijn\n"
	.string "met nog grotere legenden die\l"
	.string "nog ontdekt moeten worden.$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Ben je een TRAINER?\p"
	.string "Heb je dan verhalen die een\n"
	.string "beetje legendarisch zijn?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Trouwens… Wil je nog een\n"
	.string "legendarisch verhaal horen?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Ik ben niet tevreden…\p"
	.string "Breng me nieuws dat een legende\n"
	.string "waard is.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Ik wou dat meer mensen mijn grote\n"
	.string "verhalen over legendarische\l"
	.string "TRAINERS wilden horen.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "De Opslag-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Het spel opgeslagen$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER sloeg het spel\n"
	.string "{STR_VAR_1} keer op!\p"
	.string "Een voorzichtiger TRAINER dan\n"
	.string "{STR_VAR_3} vind je niet!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "De Trendsetter-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Trends begonnen$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER begon nieuwe trends\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} zet trends voor heel\n"
	.string "HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "De BESSEN-Plant-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "BESSEN geplant$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER plantte BESSEN\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} is een legendarische\n"
	.string "BESSEN-liefhebber!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "De FIETS-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "FIETSEN geruild$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER ruilde FIETSEN\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} houdt vast heel veel\n"
	.string "van FIETSEN!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "De Geïnterviewde TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Geïnterviewd$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER werd {STR_VAR_1} keer\n"
	.string "geïnterviewd!\p"
	.string "{STR_VAR_3} trekt vast veel\n"
	.string "aandacht!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "De Gevecht-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Gevochten$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER vocht {STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} zegt vast nooit nee\n"
	.string "tegen een gevecht!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "De POKéMON-Vang-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "POKéMON gevangen$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER ving\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is een legendarische vanger\n"
	.string "van wilde POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "De Vis-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "POKéMON gevangen met een HENGEL$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER ving\n"
	.string "{STR_VAR_1} POKéMON met vissen!\p"
	.string "{STR_VAR_3} is een legendarische\n"
	.string "visser!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "De EI-Uitbroed-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "EIEREN uitgebroed$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER broedde {STR_VAR_1}\n"
	.string "POKéMON uit EIEREN!\p"
	.string "{STR_VAR_3} is een legendarische\n"
	.string "EI-warmer!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "De Evolutie-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "POKéMON geëvolueerd$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER liet {STR_VAR_1} POKéMON\n"
	.string "evolueren!\p"
	.string "{STR_VAR_3} is de beste\n"
	.string "evolueerder van POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "De POKéMON CENTER-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "POKéMON CENTERS gebruikt$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER genas POKéMON\n"
	.string "{STR_VAR_1} keer in POKéMON CENTERS!\p"
	.string "Niemand houdt meer van\n"
	.string "POKéMON CENTERS dan {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "De Thuisblijf-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "POKéMON thuis laten rusten$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER liet POKéMON\n"
	.string "{STR_VAR_1} keer thuis rusten!\p"
	.string "Niemand blijft liever thuis\n"
	.string "dan {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "De SAFARI-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "In de SAFARI ZONE geweest$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER ging {STR_VAR_1} keer\n"
	.string "naar de SAFARI ZONE!\p"
	.string "{STR_VAR_3} heeft vast een wilde\n"
	.string "kant in de SAFARI ZONE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "De CUT-Gek-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "CUT gebruikt$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER gebruikte CUT\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} houdt vast heel veel\n"
	.string "van CUT!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "De STEENBREKER-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Rotsen gebroken$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER gebruikte STEENBREKER\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} laat geen steen heel!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "De Verhuis-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "De GEHEIME BASIS verplaatst$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER verplaatste de\n"
	.string "GEHEIME BASIS {STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} verhuist vast graag\n"
	.string "vaak!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "De PLONS-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "PLONS gebruikt$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER gebruikte PLONS\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} houdt vast van\n"
	.string "PLONSEN!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "De Vasthoudende TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "SPARTELEN moeten gebruiken$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER moest {STR_VAR_1} keer\n"
	.string "SPARTELEN gebruiken!\p"
	.string "{STR_VAR_3} is een taaie TRAINER\n"
	.string "die nooit opgeeft!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "De GOKKAST-Kampioen$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Jackpot in de GOKKAST gewonnen$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER won de jackpot in\n"
	.string "de GOKKAST {STR_VAR_1} keer.\p"
	.string "{STR_VAR_3} had geluk\n"
	.string "bij de GOKKAST!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "De ROULETTE-Kampioen$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Achter elkaar ROULETTE gewonnen:$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER won {STR_VAR_1} keer\n"
	.string "achter elkaar bij ROULETTE.\p"
	.string "{STR_VAR_3} had geluk toen de bal\n"
	.string "rolde bij ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "De BATTLE TOWER-Uitdager$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "BATTLE TOWER-uitdaging gedaan$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER deed de BATTLE TOWER-\n"
	.string "uitdaging {STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} wil de beste worden in\n"
	.string "de BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "De Mix-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{POKEBLOCK}S gemaakt$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER maakte {POKEBLOCK}S\n"
	.string "{STR_VAR_1} keer!\p"
	.string "Niemand is beter in de BESSENMIXER\n"
	.string "dan {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "De WEDSTRIJD-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Meegedaan aan WEDSTRIJDEN$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER deed {STR_VAR_1} keer mee\n"
	.string "aan WEDSTRIJDEN!\p"
	.string "{STR_VAR_3} laat vast graag\n"
	.string "POKéMON aan anderen zien!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "De WEDSTRIJD-Meester$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "WEDSTRIJDEN gewonnen$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER won WEDSTRIJDEN\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} is vast een geweldige\n"
	.string "WEDSTRIJD-meester!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "De Vrolijke Koper$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Boodschappen gedaan$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER kocht voorwerpen in\n"
	.string "winkels {STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} is vast geboren\n"
	.string "om te winkelen.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "De Voorwerp-Zoek-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "SCHATZOEKER gebruikt$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER gebruikte de SCHATZOEKER\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} zoekt vast graag\n"
	.string "naar verborgen voorwerpen!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "De Doorweekte TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Nat geregend$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER werd {STR_VAR_1} keer\n"
	.string "nat van de regen!\p"
	.string "De uitstraling van {STR_VAR_3} trekt\n"
	.string "zelfs regen aan!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "De POKéDEX-Lezer$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "POKéDEX bekeken$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER keek {STR_VAR_1} keer\n"
	.string "in de POKéDEX!\p"
	.string "{STR_VAR_3} bekijkt vast graag\n"
	.string "POKéMON in de POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "De LINT-Verzamelaar$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "LINTEN gekregen$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER kreeg LINTEN\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} verzamelt vast graag\n"
	.string "LINTEN!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "De Rand-Spring-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Van randen gesprongen$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER sprong {STR_VAR_1} keer\n"
	.string "van een rand!\p"
	.string "Zit er een rand om vanaf te springen,\n"
	.string "dan kan {STR_VAR_3} het niet laten!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "De Legendarische TV-Kijker$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "TV gekeken$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER keek {STR_VAR_1} keer\n"
	.string "TV!\p"
	.string "{STR_VAR_3} kijkt vast graag TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "De Tijd-Bewuste TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "De tijd bekeken$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER keek {STR_VAR_1} keer\n"
	.string "naar de tijd!\p"
	.string "{STR_VAR_3} is vast altijd op tijd\n"
	.string "en let goed op de tijd.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "De POKéMON LOTERIJ-Tovenaar$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "POKéMON LOTERIJEN gewonnen$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER won POKéMON LOTERIJEN\n"
	.string "{STR_VAR_1} keer!\p"
	.string "{STR_VAR_3} heeft vast veel vrienden\n"
	.string "om POKéMON mee te ruilen!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "De OPPAS-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "POKéMON bij de OPPAS gelaten$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER liet POKéMON\n"
	.string "{STR_VAR_1} keer bij de OPPAS!\p"
	.string "{STR_VAR_3} is vast een doorzetter\n"
	.string "die POKéMON hard laat groeien!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "De KABELBAAN-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Met de KABELBAAN gegaan$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER ging {STR_VAR_1} keer\n"
	.string "met de KABELBAAN!\p"
	.string "{STR_VAR_3} heeft het vast druk\n"
	.string "en gaat de hele tijd op en neer!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "De Warme Bron-Fan-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "In warme bronnen gebaad$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Dit is het verhaal van een TRAINER\n"
	.string "genaamd {STR_VAR_3}.\p"
	.string "Deze TRAINER nam {STR_VAR_1} keer\n"
	.string "een bad in warme bronnen!\p"
	.string "{STR_VAR_3} heeft vast een huid\n"
	.string "zo zacht als van een baby!$"


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
	.string "Ik ben GIDDY!\n"
	.string "Ik heb een geweldig verhaal voor je!\p"
	.string "Wil je mijn verhaal horen?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "Nu voel ik me verdrietig…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "En ik dacht ook nog…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Dat was het wel, denk ik…\p"
	.string "Laten we weer eens praten!\n"
	.string "Dag!$"

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
	.string "Hoi, ik ben de ZANGER.\n"
	.string "Wil je mijn lied horen?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "Nu voel ik me verdrietig…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, wat een mooi lied…\n"
	.string "Ik wou dat ik het voor anderen\l"
	.string "kon spelen…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "En?\n"
	.string "Hoe vind je mijn lied?\p"
	.string "Maar ik ben niet blij met\n"
	.string "de tekst.\p"
	.string "Wil je een nieuwe tekst voor\n"
	.string "me schrijven?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "Nu voel ik me verdrietig…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Hartelijk bedankt!\n"
	.string "Ik zing het voor je.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Moest je lied zo klinken?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Goed! Zo blijft het dan.\n"
	.string "Ik zing dit lied een tijdje.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hé, yo! Ze noemen mij de HIPSTER.\n"
	.string "Ik leer je wat hip en cool is.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Maar hé, ik heb je al geleerd\n"
	.string "wat hip en cool is.\p"
	.string "Ik wil het ook aan andere mensen\n"
	.string "vertellen.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Maar hé, je weet al veel over\n"
	.string "wat hip en cool is.\p"
	.string "Ik heb niets nieuws meer\n"
	.string "voor je!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hé, ken je het woord\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Wat het betekent? Nou…\n"
	.string "Vraag het maar aan papa of mama!$"
