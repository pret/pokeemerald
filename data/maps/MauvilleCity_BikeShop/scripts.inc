MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Bon, bon, bon… Qu’est-ce qu’on a là?\n"
	.string "Un client des plus énergiques!\p"
	.string "Moi? Tu peux m’appeler RODOLPHE.\n"
	.string "Je suis le propriétaire de ce magasin\l"
	.string "de vélos.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RODOLPHE: Tes CHAUSSURES DE SPORT…\n"
	.string "Elles sont dégoûtantes!\p"
	.string "Tu viens de loin?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RODOLPHE: C’est vrai?\p"
	.string "Alors je suppose que tu n’as pas\n"
	.string "besoin de mes VELOS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RODOLPHE: Hum, hum… … … … …\n"
	.string "… … … … … … … …\p"
	.string "Tu veux dire que tu as fait toute\n"
	.string "la route depuis BOURG-EN-VOL?\p"
	.string "Mon dieu!\n"
	.string "C’est terriblement loin!\p"
	.string "Si tu avais un de mes VELOS, tu pourrais\n"
	.string "aller n’importe où sans problème, en\l"
	.string "sentant le vent te caresser le visage!\p"
	.string "Tu sais quoi?\n"
	.string "Je vais te donner un VELO!\p"
	.string "Oh, attends une seconde!\p"
	.string "J’ai oublié de te préciser qu’il y\n"
	.string "a deux sortes de VELOS.\p"
	.string "Il y a le VELO COURSE et le\n"
	.string "VELO CROSS.\p"
	.string "Le VELO COURSE est pour ceux qui\n"
	.string "veulent sentir le souffle du vent.\p"
	.string "Et le VELO CROSS est pour ceux qui\n"
	.string "préfèrent les performances techniques.\p"
	.string "Je suis un vrai passionné. Tu peux\n"
	.string "prendre celui que tu veux.\p"
	.string "Alors, tu choisis lequel?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} choisit le VELO COURSE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} choisit le VELO CROSS.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RODOLPHE: Si tu as besoin de changer de\n"
	.string "VELO, n’hésite pas à venir me voir!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RODOLPHE: Oh? Tu voudrais changer\n"
	.string "de VELO?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RODOLPHE: D’accord, pas de problème!\n"
	.string "Je t’échange ton VELO contre l’autre.$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} reçoit le VELO CROSS en\n"
	.string "échange du VELO COURSE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} reçoit le VELO COURSE en\n"
	.string "échange du VELO CROSS.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RODOLPHE: Très bien!\n"
	.string "Content qu’il te convienne!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Qu’est-ce qui est arrivé au VELO\n"
	.string "que je t’avais donné?\p"
	.string "Ah, je vois! Tu l’as stocké sur ton PC.\p"
	.string "Bon, sors-le du PC et je te l’échangerai!\p"
	.string "Que les vents te soient favorables!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "J’apprends beaucoup de choses sur les\n"
	.string "VELOS depuis que je travaille ici.\p"
	.string "Si tu as besoin de conseils pour\n"
	.string "conduire ton vélo, il y a deux ou\l"
	.string "trois manuels derrière.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "C’est un guide sur le VELO COURSE.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Le VELO prend la direction indiquée\n"
	.string "sur la manette +.\p"
	.string "Il accélère dès qu’il commence à rouler.\p"
	.string "Quand la manette + n’est plus utilisée,\n"
	.string "le VELO ralentit et s’arrête.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Le VELO COURSE est rapide, mais il ne\n"
	.string "s’arrête pas immédiatement.\p"
	.string "C’est aussi un peu difficile de prendre\n"
	.string "les virages.\p"
	.string "Il faut relâcher la manette +\n"
	.string "et ralentir un peu avant le virage.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "De petites coulées de sable parsèment\n"
	.string "toute la région de HOENN.\p"
	.string "Ce sable fin empêche d’avancer\n"
	.string "normalement.\p"
	.string "Mais avec un VELO COURSE, il est\n"
	.string "possible de gravir un versant de sable.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "C’est un guide sur le VELO CROSS.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Si vous appuyez sur le bouton B en\n"
	.string "roulant, la roue avant se soulève.\p"
	.string "Vous pouvez rouler sur une roue\n"
	.string "en utilisant la manette +.\p"
	.string "Cette technique se nomme\n"
	.string "la roue arrière.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "En maintenant le bouton B enfoncé,\n"
	.string "vous pourrez sauter sur des rebords.\p"
	.string "Cette technique est appelée bunny hop.\p"
	.string "Vous pouvez aussi avancer en sautant.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Appuyez simultanément sur le bouton B\n"
	.string "et sur la manette + pour faire un saut.\p"
	.string "Appuyez sur gauche ou droite sur la\n"
	.string "manette + pour faire un saut latéral.\p"
	.string "Appuyez sur haut sur la manette + pour\n"
	.string "changer de direction en sautant.\p"
	.string "Voir une autre page?$"

