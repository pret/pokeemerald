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
	.string "Zo, zo, wie hebben we hier?\n"
	.string "Wat een vrolijke klant!\p"
	.string "Ik? Noem me maar RYDEL.\n"
	.string "Ik ben de baas van deze fietswinkel.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Je RENSCHOENEN…\n"
	.string "Die zijn wel heel vies.\p"
	.string "Kom je van ver weg?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is dat zo?\p"
	.string "Dan heb je zeker geen FIETS\n"
	.string "van mij nodig.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "Je zegt dat je helemaal uit\n"
	.string "LITTLEROOT komt?\p"
	.string "Allemachtig!\n"
	.string "Dat is echt superver!\p"
	.string "Met een FIETS van mij kun je overal\n"
	.string "makkelijk heen. En je voelt de\l"
	.string "wind zacht langs je gezicht!\p"
	.string "Weet je wat?\n"
	.string "Ik geef je een FIETS!\p"
	.string "Oh, wacht even!\p"
	.string "Ik vergat te zeggen dat er\n"
	.string "twee soorten FIETSEN zijn!\p"
	.string "De RACEFIETS en\n"
	.string "de STUNTFIETS!\p"
	.string "De RACEFIETS is voor wie\n"
	.string "de wind hard wil voelen!\p"
	.string "En de STUNTFIETS is voor wie\n"
	.string "graag kunstjes doet!\p"
	.string "Ik ben een schat, dus je mag\n"
	.string "kiezen welke je wilt!\p"
	.string "Welke kies jij?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} kiest de RACEFIETS.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} kiest de STUNTFIETS.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Wil je een andere FIETS?\n"
	.string "Kom dan gewoon langs!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Wil je soms\n"
	.string "van FIETS ruilen?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Oké, geen probleem!\n"
	.string "Ik ruil je FIETS om!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} ruilt de RACEFIETS\n"
	.string "voor een STUNTFIETS.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} ruilt de STUNTFIETS\n"
	.string "voor een RACEFIETS.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Goed zo!\n"
	.string "Fijn dat je hem leuk vindt!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Waar is de FIETS die ik\n"
	.string "jou gaf?\p"
	.string "Ah, ik snap het. Hij zit in je PC.\p"
	.string "Haal hem uit de PC, dan ruil\n"
	.string "ik hem graag voor je om!\p"
	.string "Ik hoop dat je altijd wind mee\n"
	.string "hebt op je reis!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Ik leer hier veel over FIETSEN\n"
	.string "terwijl ik werk.\p"
	.string "Wil je tips over fietsen? Achterin\n"
	.string "liggen een paar handboeken.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Een handboek over de RACEFIETS.\p"
	.string "Welke bladzijde wil je lezen?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Een FIETS rijdt de kant op die je\n"
	.string "met de + Control Pad kiest.\p"
	.string "Als hij rolt, gaat hij steeds\n"
	.string "sneller.\p"
	.string "Wil je stoppen? Laat dan de\n"
	.string "+ Control Pad los.\l"
	.string "De FIETS remt dan af.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Een RACEFIETS is snel, maar kan\n"
	.string "niet snel stoppen.\p"
	.string "Een bocht maken is daarom\n"
	.string "een beetje lastig.\p"
	.string "Laat de + Control Pad vlak voor\n"
	.string "de bocht los en rem af.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Overal in HOENN zijn kleine\n"
	.string "zandhellingen.\p"
	.string "Het losse zand maakt het\n"
	.string "onmogelijk om gewoon te klimmen.\p"
	.string "Maar met een RACEFIETS rijd je\n"
	.string "zo'n zandhelling snel op.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Een handboek over de STUNTFIETS.\p"
	.string "Welke bladzijde wil je lezen?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Druk tijdens het rijden op de\n"
	.string "B-knop. Dan gaat je voorwiel omhoog.\p"
	.string "Met de + Control Pad rijd je\n"
	.string "rond op je achterwiel.\p"
	.string "Dat heet een wheelie.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Houd de B-knop ingedrukt.\n"
	.string "Dan springt je FIETS op de plek.\p"
	.string "Dat heet een bunny hop.\p"
	.string "Je kunt ook springend rijden.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Druk tegelijk op de B-knop en\n"
	.string "de + Control Pad om te springen.\p"
	.string "Druk de + Control Pad opzij om\n"
	.string "zijwaarts te springen.\p"
	.string "Druk hem naar achteren, dan draait\n"
	.string "de FIETS om tijdens de sprong.\p"
	.string "Wil je een andere bladzijde lezen?$"

