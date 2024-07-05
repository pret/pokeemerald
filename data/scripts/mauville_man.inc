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

.ifdef FRENCH
@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salut, je suis le BROCANTEUR. Tu veux\n"
	.string "échanger des décorations avec moi?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "Je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Mais, nous avons déjà échangé des\n"
	.string "décorations, toi et moi.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si tu veux un objet décoratif que j’ai,\n"
	.string "n’hésite pas à me le demander.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Tu ne veux rien?\n"
	.string "Bouh, je n’intéresse personne…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "A l’époque, cette décoration\n"
	.string "appartenait à {STR_VAR_1}.\p"
	.string "Tu la veux?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Hé… Une minute! Tu ne possèdes aucune\n"
	.string "décoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Très bien, choisis la décoration que tu\n"
	.string "veux échanger avec moi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Tu ne veux rien échanger avec moi?\n"
	.string "Bouh, je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Tu as déjà tous les objets de cette\n"
	.string "catégorie. Tu n’as plus de place.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Alors, on échange {STR_VAR_3}\n"
	.string "contre {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Tu utilises déjà cette décoration.\n"
	.string "Tu ne peux pas l’échanger.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Dans ce cas, faisons l’échange!\n"
	.string "J’enverrai ma décoration dans ton PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ah non, pas cet objet!\p"
	.string "C’est une décoration vraiment rare.\n"
	.string "Je ne peux pas te l’échanger!\p"
	.string "Il n’y a rien d’autre qui t’intéresse?$"
.else
.ifdef ITALIAN
@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salve! Sono il MERCANTE.\n"
	.string "Vuoi scambiare decorazioni con me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh… sento che la mia presenza\n"
	.string "non è gradita.$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Io e te abbiamo già scambiato\n"
	.string "decorazioni.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Se vedi qualche oggetto che ti piace,\n"
	.string "dimmelo.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Non vuoi niente?\n"
	.string "La mia presenza non è gradita…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Quella decorazione apparteneva a\n"
	.string "{STR_VAR_1} prima.\p"
	.string "La vuoi?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh? Aspetta un attimo. Non hai niente\n"
	.string "da darmi in cambio!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Va bene, scegli la decorazione che\n"
	.string "vorresti darmi in cambio.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Non vuoi scambiare niente con me?\n"
	.string "La mia presenza non è gradita…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "La tua collezione di questi oggetti è\n"
	.string "completa. Non c’è più spazio.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Va bene, vuoi darmi {STR_VAR_2}\n"
	.string "in cambio di {STR_VAR_3}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Quella decorazione è in uso.\n"
	.string "Non puoi scambiarla.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Allora facciamo lo scambio!\n"
	.string "Mando la decorazione al tuo PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oh, mi dispiace.\n"
	.string "È una decorazione molto rara.\l"
	.string "Non posso darla via!\p"
	.string "Ti potrebbe interessare qualcos’altro?$"
.else
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
.endif
.endif

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

.ifdef FRENCH
@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Je suis le CONTEUR.\n"
	.string "Je peux te raconter l’histoire de\l"
	.string "DRESSEURS légendaires.\p"
	.string "Alors, tu veux écouter mon histoire?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "Je me sens frustré…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "J’en connais, des légendes.\n"
	.string "Quelle histoire veux-tu que je raconte?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Mais je ne connais aucun DRESSEUR\n"
	.string "légendaire. Donc, pas d’histoire.\p"
	.string "Où peut-on trouver un DRESSEUR digne\n"
	.string "d’entrer dans la légende?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "De quoi?!?\n"
	.string "Toi… Tu as…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} fois?!?\p"
	.string "Mais c’est formidable! C’est la\n"
	.string "naissance d’une nouvelle légende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Mais j’y pense, il y a peut-être encore\n"
	.string "d’autres DRESSEURS à découvrir, avec\l"
	.string "des légendes plus impressionnantes?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Et toi, tu es DRESSEUR?\p"
	.string "Alors dis-moi, as-tu des histoires à me\n"
	.string "raconter, même vaguement légendaires?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hum…\n"
	.string "Je suis un peu déçu…\p"
	.string "J’aurais aimé que tu me racontes une\n"
	.string "histoire digne d’être appelée légende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "J’aimerais bien que plus de gens\n"
	.string "s’intéressent à mes épiques sagas de\l"
	.string "DRESSEURS légendaires.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "Le DRESSEUR à la sauvegarde facile$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "sauvegardé la partie$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauvegardé sa partie\n"
	.string "{STR_VAR_1} fois!\p"
	.string "Impossible de trouver un DRESSEUR plus\n"
	.string "prudent que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "Le DRESSEUR qui lançait des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "lancé des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a lancé de nouvelles modes\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} lance des modes dans toute\n"
	.string "la région de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "Le DRESSEUR qui plantait des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "planté des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a planté\n"
	.string "{STR_VAR_1} BAIES!\p"
	.string "{STR_VAR_3} est connu pour être un\n"
	.string "grand amateur de BAIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "Le DRESSEUR fan de VELOS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "changé de VELO$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a changé de VELO\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer les VELOS à\n"
	.string "la folie!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "Le DRESSEUR interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "répondu à une interview$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été interviewé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est vraiment un DRESSEUR\n"
	.string "très médiatisé!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "Le DRESSEUR combattant$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "combattu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a combattu {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui ne rate\n"
	.string "pas une occasion de se battre!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "Le DRESSEUR chasseur de POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "attrapé des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} est un chasseur de POKéMON\n"
	.string "sauvages légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "Le DRESSEUR pêcheur$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "attrapé des POKéMON avec une CANNE$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON en les pêchant!\p"
	.string "{STR_VAR_3} est un pêcheur légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "Le DRESSEUR qui couvait des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "fait éclore des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait éclore {STR_VAR_1}\n"
	.string "OEUF(S) de POKéMON!\p"
	.string "{STR_VAR_3} s’occupe formidablement\n"
	.string "bien des OEUFS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "Le DRESSEUR aux POKéMON évolués$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "fait évoluer des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait évoluer {STR_VAR_1}\n"
	.string "POKéMON!\p"
	.string "{STR_VAR_3} est un pro de l’évolution\n"
	.string "des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "Le DRESSEUR fan de CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "utilisé des CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné des\n"
	.string "POKéMON {STR_VAR_1} fois dans des\l"
	.string "CENTRES POKéMON!\p"
	.string "Il n’existe pas de plus grand fan de\n"
	.string "CENTRES POKéMON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "Le DRESSEUR casanier$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "soigné des POKéMON à la maison$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné ses POKéMON\n"
	.string "à la maison {STR_VAR_1} fois!\p"
	.string "Il n’existe pas de DRESSEUR plus\n"
	.string "casanier que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "Le DRESSEUR fan de SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "pénétré dans le PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR est entré dans le\n"
	.string "PARC SAFARI {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui exprime\n"
	.string "son côté sauvage au PARC SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "Le DRESSEUR à la COUPE facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "utilisé COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé COUPE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "utiliser COUPE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "Le DRESSEUR ECLATE-ROC$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "éclaté des rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé ECLATE-ROC\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui ne peut\n"
	.string "pas laisser un rocher entier!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "Le DRESSEUR qui aime déménager$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "déplacé ta BASE SECRETE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a déplacé sa BASE\n"
	.string "SECRETE {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "déménager!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "Le DRESSEUR fou de TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "utilisé TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé TREMPETTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "faire TREMPETTE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "Le DRESSEUR tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "fini par utiliser LUTTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a dû utiliser LUTTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR tenace qui\n"
	.string "n’abandonne jamais face à l’adversité!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Le champion des MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "eu le jackpot aux MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné le jackpot aux\n"
	.string "MACHINES A SOUS {STR_VAR_1} fois.\p"
	.string "{STR_VAR_3} est un DRESSEUR qui a eu de\n"
	.string "la chance aux MACHINES A SOUS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Le champion de la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "gagné consécutivement à la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la ROULETTE\n"
	.string "{STR_VAR_1} fois de suite.\p"
	.string "{STR_VAR_3} a eu beaucoup de chance\n"
	.string "à la ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Le candidat à la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "relevé les défis de la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a relevé les défis de la\n"
	.string "TOUR DE COMBAT {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR cherchant\n"
	.string "à être premier dans la TOUR DE COMBAT!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "Le DRESSEUR qui aime mixer$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "fait des {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait des {POKEBLOCK}S\n"
	.string "{STR_VAR_1} fois!\p"
	.string "Personne n’utilise un MIXEUR mieux\n"
	.string "que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "Le DRESSEUR fan de CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "participé à des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a participé à des\n"
	.string "CONCOURS {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} adore exhiber ses\n"
	.string "POKéMON devant un public!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Le maître des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "gagné des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné des CONCOURS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être incroyablement\n"
	.string "doué pour les CONCOURS!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Le joyeux consommateur$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "acheté des objets$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a acheté des objets\n"
	.string "dans un magasin {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être l’un de ces\n"
	.string "DRESSEURS nés pour faire des achats.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Le DRESSEUR chercheur d’objets$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "utilisé un CHERCH’OBJET$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé un CHERCH’OBJET\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer sonder le sol\n"
	.string "pour trouver des objets cachés!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "Le DRESSEUR trempé jusqu’aux os$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "pris une averse$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été trempé jusqu’aux\n"
	.string "os par la pluie {STR_VAR_1} fois!\p"
	.string "Le charisme de {STR_VAR_3} doit même\n"
	.string "attirer la pluie!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Le lecteur de POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "vérifié ton POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a vérifié son POKéDEX\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer en apprendre\n"
	.string "plus sur les POKéMON dans son POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Le collectionneur de RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "reçu des RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a reçu des RUBANS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "adore collectionner les RUBANS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "Le DRESSEUR qui saute des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "sauté des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauté des talus\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} ne peut pas s’empêcher de\n"
	.string "sauter d’un talus!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Le téléspectateur légendaire$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "regardé la télé$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé la télé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer regarder\n"
	.string "la télé!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "Le DRESSEUR conscient du temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "regardé l’heure$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé l’heure\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "ponctuel, toujours conscient du temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Le magicien de la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "gagné à la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la LOTERIE\n"
	.string "POKéMON {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit avoir de nombreux amis\n"
	.string "avec qui échanger des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "Le DRESSEUR client de la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "laissé des POKéMON à la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a laissé des POKéMON à\n"
	.string "la PENSION {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un vrai battant\n"
	.string "qui élève ses POKéMON avec énergie!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "Le DRESSEUR fan du TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "fait le trajet en TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a pris le TELEPHERIQUE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "surmené qui passe son temps à voyager!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "Le DRESSEUR fan de sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "pris un bain dans les sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s’est baigné dans les\n"
	.string "sources chaudes {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR avec\n"
	.string "une peau de bébé!$"
.else
.ifdef ITALIAN
@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sono il NARRATORE.\n"
	.string "Racconto storie di ALLENATORI\l"
	.string "leggendari.\p"
	.string "Vuoi sentire la mia storia?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh… mi sento avvilito…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Questa è la lista delle leggende che\n"
	.string "conosco. Quale storia vorresti sentire?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Veramente, non conosco né ALLENATORI\n"
	.string "leggendari né storie.\p"
	.string "Dove si potrebbe trovare un ALLENATORE\n"
	.string "degno di un racconto leggendario?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Cosa?\n"
	.string "Tu… tu…\p"
	.string "{STR_VAR_2} \n"
	.string "per un numero di volte pari a {STR_VAR_1}?!\p"
	.string "Ma è eccezionale! Assistiamo alla\n"
	.string "nascita di una leggenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Mi viene da pensare che ci potrebbero\n"
	.string "essere altri ALLENATORI con altre \l"
	.string "leggende avvincenti tutte da scoprire!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Sei un ALLENATORE?\p"
	.string "Allora dimmi, non hai delle storie che\n"
	.string "possano suonare un po’ leggendarie?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Uhm… non sono soddisfatto…\p"
	.string "Vorrei che mi raccontassi aneddoti\n"
	.string "degni di essere chiamati leggenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Vorrei che più persone fossero\n"
	.string "interessate ai miei racconti epici sugli\l"
	.string "ALLENATORI leggendari.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "L’ALLENATORE salvatutto$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "hai salvato il gioco$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha salvato il gioco? {STR_VAR_1}!\p"
	.string "Di ALLENATORI prudenti come \n"
	.string "{STR_VAR_3} non ne troverai a frotte.$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "L’ALLENATORE modaiolo$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "hai lanciato una moda$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha lanciato nuove mode? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} detta le mode per tutta\n"
	.string "la regione di HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "L’ALLENATORE piantabacche$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "hai piantato BACCHE$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha piantato BACCHE? {STR_VAR_1}!\p"
	.string "La passione per le BACCHE di {STR_VAR_3}\n"
	.string "è veramente leggendaria!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "L’ALLENATORE scambiabici$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "hai scambiato BICI$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha scambiato BICI? {STR_VAR_1}!\p"
	.string "La passione di {STR_VAR_3} per le BICI\n"
	.string "deve essere profonda e sincera!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "L’ALLENATORE intervistato$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "hai concesso interviste$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte è stato intervistato\n"
	.string "questo ALLENATORE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve essere un ALLENATORE\n"
	.string "che attira l’attenzione di tutti!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "L’ALLENATORE in lotta$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "hai sostenuto lotte$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte ha lottato\n"
	.string "questo ALLENATORE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve essere un ALLENATORE\n"
	.string "che non rifiuta mai una lotta!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "L’ALLENATORE acchiappa-POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "hai catturato POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha catturato\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3}, acchiappa-POKéMON di fama\n"
	.string "leggendaria!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "L’ALLENATORE pescatore$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "hai catturato POKéMON con l’AMO$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha pescato\n"
	.string "{STR_VAR_1} POKéMON.\p"
	.string "L’amore per la pesca di {STR_VAR_3}\n"
	.string "è leggendario!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "L’ALLENATORE covauova$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "hai fatto schiudere UOVA$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha fatto nascere\n"
	.string "{STR_VAR_1} POKéMON dalle UOVA!\p"
	.string "{STR_VAR_3}, covauova di fama\n"
	.string "internazionale!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "L’ALLENATORE evolvi-POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "hai fatto evolvere POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha fatto evolvere\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} è il “non plus ultra” degli\n"
	.string "evolvi-POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "L’ALLENATORE dei CENTRI POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "hai visitato CENTRI POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto riposare la sua squadra di\l"
	.string "POKéMON nei CENTRI POKéMON? {STR_VAR_1}!\p"
	.string "Non esiste nessuno che ami i CENTRI\n"
	.string "POKéMON più di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "L’ALLENATORE casalingo$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "hai rimesso in sesto i POKéMON a casa$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha rimesso in sesto la sua squadra di\l"
	.string "POKéMON a casa? {STR_VAR_1}!\p"
	.string "Non esiste ALLENATORE più casalingo\n"
	.string "di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "L’ALLENATORE safarista$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "hai visitato la ZONA SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "è entrato nella ZONA SAFARI? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE il cui \n"
	.string "spirito selvaggio si risveglia nella \l"
	.string "ZONA SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "L’ALLENATORE dal TAGLIO facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "hai usato TAGLIO$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato TAGLIO? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che adora\n"
	.string "TAGLIO!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "L’ALLENATORE SPACCAROCCIA$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "hai spaccato rocce$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SPACCAROCCIA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che\n"
	.string "spacca tutte le rocce che trova!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "L’ALLENATORE traslocatore$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "hai traslocato dalla BASE SEGRETA$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha traslocato dalla sua BASE SEGRETA?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che ama\n"
	.string "traslocare spesso!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "L’ALLENATORE con la SPLASH-mania$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "hai usato SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SPLASH? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE con\n"
	.string "la mania per gli SPLASH!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "L’ALLENATORE tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "hai usato SCONTRO$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SCONTRO? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE tenace che\n"
	.string "mai si arrende di fronte alle avversità!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Il campione di SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "hai vinto il jackpot alle SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "vinto il jackpot alle SLOT? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE\n"
	.string "fortunatissimo alle SLOT!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Il campione della ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "hai vinto di seguito alla ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte di seguito questo\n"
	.string "ALLENATORE ha vinto alla ROULETTE?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} ha una gran fortuna quando\n"
	.string "la pallina rimbalza nella ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "L’asso della TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "hai sfidato la TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha sfidato la TORRE LOTTA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che aspira\n"
	.string "alla perfezione nella TORRE LOTTA!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "L’ALLENATORE mixa-tutto$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "hai fatto {POKEMELLE}$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto {POKEMELLE}? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è veramente impareggiabile\n"
	.string "nell’uso del MIXER BACCHE!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "L’ALLENATORE sempre in GARA$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "hai partecipato alle GARE$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha partecipato alle GARE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora mostrare i propri\n"
	.string "POKéMON agli altri!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Il fuoriclasse delle GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "hai vinto GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha vinto GARE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è veramente imbattibile\n"
	.string "nelle GARE!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "L’amante degli acquisti$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "hai fatto acquisti$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "fatto acquisti nei negozi? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è una persona che non può\n"
	.string "fare a meno di entrare in un negozio.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Il professionista del DETECTOR$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "hai usato il DETECTOR$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato il DETECTOR? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora sondare il terreno\n"
	.string "per cercare strumenti nascosti!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "L’ALLENATORE fradicio$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "hai fatto docce d’acqua piovana$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto docce d’acqua piovana?\l"
	.string "{STR_VAR_1}!\p"
	.string "Deve essere il carisma di {STR_VAR_3}\n"
	.string "ad attirare la pioggia!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Il vorace lettore di POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "hai controllato il POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha controllato il POKéDEX? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora studiare i POKéMON\n"
	.string "sul POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Il collezionista di FIOCCHI$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "hai ricevuto FIOCCHI$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha ricevuto FIOCCHI? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che\n"
	.string "ama far collezione di FIOCCHI!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "L’ALLENATORE salta-salti$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "hai disceso salti$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha disceso salti? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} non si fa sfuggire neppure\n"
	.string "un salto da discendere!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Il telespettatore leggendario$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "hai guardato la TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha guardato la TV? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora guardare la TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "L’ALLENATORE puntuale$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "hai controllato l’ora$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha controllato l’ora? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE puntuale e\n"
	.string "con uno spiccato senso del tempo.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Il mago della LOTTERIA POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "hai vinto alle LOTTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "vinto alla LOTTERIA POKéMON? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve avere molti amici \n"
	.string "con cui scambiare i POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "L’ALLENATORE utente della PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "hai lasciato POKéMON alla PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha lasciato i POKéMON nella PENSIONE?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE intrapren-\n"
	.string "dente che allena i POKéMON con abilità.$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "L’ALLENATORE in FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "hai viaggiato in FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha viaggiato in FUNIVIA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE molto\n"
	.string "impegnato che va sempre su e giù!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "L’habitué delle sorgenti termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "hai lambito le sorgenti termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto bagni nelle sorgenti termali?\l"
	.string "{STR_VAR_1}! \p"
	.string "{STR_VAR_3} è un ALLENATORE con una\n"
	.string "pelle liscia come quella di un bambino!$"
.else
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
.endif
.endif

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
.ifdef FRENCH
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Je m’appelle PAPOTEUR!\n"
	.string "J’ai une super histoire à te raconter!\p"
	.string "Tu veux l’écouter?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "Tu m’as déprimé…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Et puis aussi, je me disais…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Eh bien, c’est tout, je pense…\p"
	.string "On discutera plus tard!\n"
	.string "Ciao!$"
.else
.ifdef ITALIAN
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sono STRAMBY!\n"
	.string "Ho una storia magnifica da raccontarti!\p"
	.string "Vuoi sentirla?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh… mi sento demotivato…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Stavo anche pensando…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "È tutto, mi pare…\p"
	.string "Speriamo di rivederci!\n"
	.string "Ciao, ciao!$"
.else
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
.endif
.endif

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

.ifdef FRENCH
MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Bonjour, je suis CAPELO.\n"
	.string "Tu veux entendre ma chanson?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quelle chanson émouvante… Je\n"
	.string "voudrais pouvoir la chanter aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Alors?\n"
	.string "Qu’est-ce que tu penses de ma chanson?\p"
	.string "Mais je ne suis pas très content des\n"
	.string "paroles.\p"
	.string "Ça te plairait d’écrire de nouvelles\n"
	.string "paroles pour moi?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Merci beaucoup!\n"
	.string "Je vais la chanter pour toi.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Tu la voulais bien comme ça, ta chanson?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Super! La chanson est finie, alors. Je\n"
	.string "vais la chanter pendant longtemps.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Yo, toi! On m’appelle MINET.\n"
	.string "Je vais te montrer ce qui est à la mode.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Hé, mais je t’ai déjà montré ce qui est\n"
	.string "à la mode en ce moment.\p"
	.string "Maintenant, j’aimerais prêcher la bonne\n"
	.string "parole aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Mais, tu sais déjà ce qui est à la mode\n"
	.string "en ce moment.\p"
	.string "Je n’ai rien de nouveau à t’apprendre!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Hé, t’as entendu parler de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Qu’est-ce que ça veut dire? Heu…\n"
	.string "T’as qu’à demander à ta maman, OK?$"
.else
.ifdef ITALIAN
MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Ciao, sono il CANTAUTORE.\n"
	.string "Vuoi sentire la mia canzone?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh… mi hai fatto intristire…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, che canzone commovente…\n"
	.string "Vorrei cantarla ad altri…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Mhmm?\n"
	.string "Ti piace la canzone?\p"
	.string "Non sono molto soddisfatto del testo.\p"
	.string "Mi aiuteresti a scrivere delle nuove\n"
	.string "parole per la canzone?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh… mi hai fatto intristire…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Grazie infinite!\n"
	.string "Adesso canterò per te!$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Erano queste le parole della canzone\n"
	.string "che volevi?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Va bene allora.\n"
	.string "Canterò questa canzone per un po’.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ehi! Tutti mi chiamano DANDY.\n"
	.string "Ti insegnerò cos’è all’ultimo grido.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Ma, aspetta, ti ho già insegnato cos’è\n"
	.string "all’ultimo grido.\p"
	.string "Mi piacerebbe poterlo insegnare\n"
	.string "ad altri.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Ehi, tu hai già un’idea molto chiara di\n"
	.string "che cosa sia all’ultimo grido.\p"
	.string "Non ho niente di nuovo da insegnarti.$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Ehi, hai sentito parlare di\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Che cosa significa? Beh, chiedi alla\n"
	.string "mamma o al papà, va bene?$"
.else
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
.endif
.endif
