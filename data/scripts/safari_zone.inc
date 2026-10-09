SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Wil je de SAFARI ZONE nu\n"
	.string "verlaten?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! De tijd is om!\n"
	.string "Je SAFARI-spel is afgelopen.$"

SafariZone_Text_OutOfBalls:
	.string "Je SAFARIBALLEN zijn op.\n"
	.string "Je SAFARI-spel is afgelopen.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Wil je een {POKEBLOCK} op de\n"
	.string "{POKEBLOCK} VOEDERBAK leggen?$"

SafariZone_Text_PokeblockStillHere:
	.string "De {STR_VAR_1} die je eerder\n"
	.string "liet liggen, ligt er nog.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "De {STR_VAR_1} is op de\n"
	.string "{POKEBLOCK} VOEDERBAK gelegd.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Welkom in de SAFARI ZONE!\p"
	.string "Hier zie je veel soorten POKéMON\n"
	.string "die je zelden in HOENN ziet.\p"
	.string "Je ziet ze wild en vrij in hun\n"
	.string "natuurlijke omgeving.\p"
	.string "En we hebben de poorten geopend\n"
	.string "voor POKéMON TRAINERS.\p"
	.string "Je mag POKéMON vangen\n"
	.string "en houden!\p"
	.string "Kom binnen en geniet van de\n"
	.string "SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Welkom in de SAFARI ZONE!\n"
	.string "Ben je hier voor het eerst?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Kom binnen en geniet van de\n"
	.string "SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "In de SAFARI ZONE begin je met\n"
	.string "30 SAFARIBALLEN om POKéMON\l"
	.string "te vangen.\p"
	.string "Het SAFARI-spel is afgelopen als je\n"
	.string "SAFARIBALLEN op zijn, of als je\l"
	.string "500 stappen hebt gelopen.\p"
	.string "Kom binnen en geniet van de\n"
	.string "SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Welkom in de SAFARI ZONE!\p"
	.string "Vang zoveel je kunt voor maar ¥500!\n"
	.string "Wil je een SAFARI-spel spelen?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Goed.\n"
	.string "Speel een andere keer!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Je hebt niet genoeg geld.\n"
	.string "Sorry.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Dat is dan ¥500, graag.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Hier zijn je SAFARIBALLEN.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} kreeg 30 SAFARIBALLEN.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "We laten het je weten als je\n"
	.string "spel afgelopen is.\p"
	.string "Tot dan: veel plezier!\n"
	.string "Op naar je wilde tocht!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Pardon!\n"
	.string "Je PC BOX is vol.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Pardon!\n"
	.string "Je hebt zeker geen {POKEBLOCK} DOOS.\p"
	.string "Je SAFARI-spel gaat veel beter\n"
	.string "als je {POKEBLOCK}S gebruikt.\p"
	.string "Kom terug met een {POKEBLOCK} DOOS.\p"
	.string "Je krijgt een {POKEBLOCK} DOOS bij\n"
	.string "de LILYCOVE WEDSTRIJDHAL.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Je hebt nog tijd over. Wil je de\n"
	.string "SAFARI ZONE nu verlaten?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Veel plezier met de rest van\n"
	.string "je wilde avontuur!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Goed.\p"
	.string "Ik neem je overgebleven\n"
	.string "SAFARIBALLEN terug.\p"
	.string "Bedankt voor het spelen.\n"
	.string "Tot de volgende keer.$"

SafariZone_South_Text_GoodLuck:
	.string "Veel succes!\p"
	.string "Als je iets nodig hebt, vraag\n"
	.string "het me gerust!$"

SafariZone_South_Text_Boy:
	.string "Wist je dat?\p"
	.string "Als je een {POKEBLOCK} in dat vierkante\n"
	.string "bakje legt, komen er POKéMON op af.$"

SafariZone_South_Text_Man:
	.string "Ik wil verder gaan, maar ik ben mijn\n"
	.string "FIETS vergeten.\p"
	.string "Ik denk dat er zeldzame POKéMON\n"
	.string "in de verre hoeken wonen.$"

SafariZone_Southwest_Text_Woman:
	.string "Soms gooi ik een {POKEBLOCK} naar\n"
	.string "POKéMON en doen ze niets.\p"
	.string "Hebben POKéMON een voorkeur\n"
	.string "voor wat ze eten?$"

SafariZone_Northwest_Text_Man:
	.string "Hijg… Hijg…\n"
	.string "Ik ben hier gekomen…maar…\p"
	.string "Ik ben uitgeput… Ik heb geen\n"
	.string "kracht meer om POKéMON te vangen…$"

SafariZone_North_Text_Fisherman:
	.string "Ik zoek WATER-POKéMON die je in\n"
	.string "HOENN niet ziet.\p"
	.string "Weet jij waar het meer is?$"

SafariZone_North_Text_Man:
	.string "Ik ga hier veel zeldzame POKéMON\n"
	.string "vangen en met mijn vrienden ruilen!$"

SafariZone_South_Text_Youngster:
	.string "Ik legde een {POKEBLOCK} op de\n"
	.string "{POKEBLOCK} VOEDERBAK.\p"
	.string "Maar hij is verdwenen.\p"
	.string "De POKéMON hebben hem vast\n"
	.string "gegeten zonder dat ik het zag.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "SAFARI ZONE TRAINERTIP!\p"
	.string "Gooi {POKEBLOCK}S naar wilde POKéMON\n"
	.string "zodat ze minder snel vluchten.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Rust je vermoeide voeten uit.”\n"
	.string "RUSTHUIS$"

SafariZone_RestHouse_Text_Youngster:
	.string "Ik heb geen {POKEBLOCK}S, maar ik heb\n"
	.string "best veel POKéMON gevangen.\p"
	.string "Je vangt makkelijker als je dichter\n"
	.string "bij komt voordat je een SAFARIBAL\l"
	.string "gooit.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Met {POKEBLOCK}S rennen wilde POKéMON\n"
	.string "niet zo snel weg.\p"
	.string "Het helpt niet veel om {POKEBLOCK}S\n"
	.string "aan POKéMON te geven die niet vluchten.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Leg je een {POKEBLOCK} op de VOEDERBAK,\n"
	.string "dan komen POKéMON erop af.\p"
	.string "Ik denk dat POKéMON met dezelfde\n"
	.string "aard bij een bepaald {POKEBLOCK} komen.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Dit gebied is nog in aanbouw.\n"
	.string "Je mag er niet in, sorry!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "De uitbreiding van de SAFARI ZONE\n"
	.string "is nu klaar.\p"
	.string "We hopen dat je het nieuwe\n"
	.string "gebied leuk vindt.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Dit gebied is nog in aanbouw.\n"
	.string "Je mag er niet in, sorry!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Hoera! Deze POKéMON heb ik\n"
	.string "nog nooit gezien!$"

SafariZone_Southeast_Text_FatMan:
	.string "De POKéMON hier zijn allemaal\n"
	.string "nieuw voor mij.\p"
	.string "En ik mag deze zeldzame POKéMON\n"
	.string "vangen! Te gek!$"

SafariZone_Southeast_Text_RichBoy:
	.string "De POKéMON hier lijken uit een\n"
	.string "ander land dan HOENN te komen.$"

SafariZone_Northeast_Text_Boy:
	.string "Ik heb nog maar een paar\n"
	.string "SAFARIBALLEN over.\p"
	.string "Ik weet niet goed wat ik\n"
	.string "moet vangen.$"

SafariZone_Northeast_Text_Woman:
	.string "Ik hoorde dat je hier PIKACHU kunt\n"
	.string "zien. Waar zou die zijn?$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, boe!\n"
	.string "Ik kan niets vangen!\p"
	.string "Als ik niets vang, is het geld voor\n"
	.string "de toegang verspild!$"
