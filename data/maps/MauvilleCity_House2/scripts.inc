MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Als ik een FIETS had, fietste ik zo\n"
	.string "naar SLATEPORT om te winkelen.\p"
	.string "Dan kon ik HAVENBRIEF kopen bij de\n"
	.string "POKéMON MART in SLATEPORT…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Heb jij een HAVENBRIEF?\n"
	.string "Wil je die ruilen voor een MUNTENDOOS?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, wat ben ik blij!\n"
	.string "Oké, je krijgt een MUNTENDOOS!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Die MUNTENDOOS kun je gebruiken\n"
	.string "in de GAME CORNER.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, wat jammer.\p"
	.string "Je hebt een MUNTENDOOS nodig\n"
	.string "voor de GAME CORNER.$"

