CeruleanCity_BikeShop_Frlg_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 11, 0, MULTI_BIKE_SHOP, FALSE
	hidemoneybox
	showmoneybox 0, 0
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case 127, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo
	msgreceiveditem CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle, ITEM_BICYCLE, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	release
	end

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle
	release
	end

@ Unused
CeruleanCity_BikeShop_EventScript_NoRoomForBicycle::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle
	release
	end

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
	.string "Hi!\n"
	.string "Welcome to our BIKE SHOP.\p"
	.string "Have we got just the BIKE for\n"
	.string "you!$"

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
	.string "Sorry!\n"
	.string "You can't afford it!$"

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
	.string "Oh, that's…\p"
	.string "A BIKE VOUCHER!\p"
	.string "Okay!\n"
	.string "Here you go!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
	.string "{PLAYER} exchanged the\n"
	.string "BIKE VOUCHER for a BICYCLE.$"

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
	.string "Thank you!\n"
	.string "Come back again sometime!$"

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
	.string "How do you like your new BICYCLE?\n"
	.string "Do you like how it rides?\p"
	.string "You can take it out on CYCLING\n"
	.string "ROAD and even into caves!$"

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
	.string "You better make room for your\n"
	.string "BICYCLE!$"

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
	.string "A plain city bike is good enough\n"
	.string "for me.\p"
	.string "After all, you can't put a shopping\n"
	.string "basket on a mountain bike.$"

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
	.string "These bikes are cool, but they're\n"
	.string "way expensive!$"

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
	.string "Wow.\n"
	.string "Your BIKE is really cool!$"

@ Unused
CeruleanCity_BikeShop_Text_GermanFoldableBicyleFinallyOnMarket::
	.string "ついに　はつばい！\p"
	.string "ドイツ　せい　さいこうきゅう\n"
	.string "おりたたみ　じてんしゃ！$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
	.string "A shiny new BICYCLE!$"

