MauvilleCity_House2_MapScripts:: @ 8210C5C
	.byte 0

MauvilleCity_House2_EventScript_Woman:: @ 8210C5D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail:: @ 8210C82
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_House2_EventScript_AcceptTrade
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade:: @ 8210CB8
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase:: @ 8210CDA
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade:: @ 8210CE4
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport: @ 8210CEE
	.string "If I had a Bike, it'd be easy to cycle to\n"
	.string "Slateport for some shopping.\p"
	.string "I'd be able to buy Harbor Mail at the\n"
	.string "Pokémon Mart in Slateport…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase: @ 8210D76
	.string "Oh! You have Harbor Mail?\n"
	.string "Will you trade it for a Coin Case?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase: @ 8210DB3
	.string "Oh, I'm so happy!\n"
	.string "Okay, I'll trade you a Coin Case!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner: @ 8210DE7
	.string "That Coin Case can be used\n"
	.string "at the Game Corner.$"

MauvilleCity_House2_Text_ThatsDisappointing: @ 8210E16
	.string "Oh, that's disappointing.\p"
	.string "A Coin Case is needed for the\n"
	.string "Game Corner.$"

