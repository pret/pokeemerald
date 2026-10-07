RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Hallo en welkom bij de DEVON\n"
	.string "CORPORATION.\p"
	.string "We maken met trots spullen en\n"
	.string "medicijnen die je leven beter maken.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Een onderzoeker van ons is zo dom\n"
	.string "geweest: hij is een pakket kwijt.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, die RENSCHOENEN!\n"
	.string "Die hebben wij gemaakt!\p"
	.string "Ik word er blij van als iemand\n"
	.string "iets gebruikt wat wij maakten.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Dat gestolen pakket…\p"
	.string "Het is wel belangrijk, maar niemand\n"
	.string "anders kan er iets mee.\p"
	.string "Volgens mij was die dief niet\n"
	.string "zo slim.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Het gestolen DEVONPAKKET is\n"
	.string "blijkbaar terug.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Sorry, alleen mensen met\n"
	.string "toestemming mogen hier naar binnen.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Dit is echt superdom.\n"
	.string "Hoe konden we beroofd worden?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hoi!\n"
	.string "Je bent hier altijd welkom!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "In de glazen kast liggen stukjes\n"
	.string "steen en metaal.\p"
	.string "Er staat een bordje met tekst\n"
	.string "erbij…\p"
	.string "“DEVON CORPORATION begon als\n"
	.string "bedrijf dat stenen uit groeven haalde.\p"
	.string "“Ook maakte het ijzer van\n"
	.string "ijzervijlsel uit het zand.\p"
	.string "“Zo begon DEVON klein, met\n"
	.string "ruwe materialen.\p"
	.string "“Nu maakt DEVON allerlei\n"
	.string "verschillende producten.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "In de glazen kast staan proefmodellen\n"
	.string "en nieuwe producten.\p"
	.string "Er staat een bordje bij…\p"
	.string "“Naast producten voor fabrieken\n"
	.string "maakt DEVON nu ook spullen en\l"
	.string "medicijnen voor een fijner leven.\p"
	.string "“Sinds kort maakt DEVON ook spullen\n"
	.string "voor POKéMON TRAINERS, zoals\l"
	.string "POKé BALLS en de POKéNAV.”$"

