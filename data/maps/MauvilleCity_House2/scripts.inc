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
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
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
	.string "Avec un VELO, ce serait facile d’aller\n"
	.string "faire des courses à POIVRESSEL.\p"
	.string "Je pourrais acheter une LETTRE PORT à\n"
	.string "la BOUTIQUE POKéMON de POIVRESSEL…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Tu as une LETTRE PORT?\p"
	.string "Tu me l’échanges contre une\n"
	.string "BOITE JETONS?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, ça me fait tellement plaisir!\n"
	.string "OK, je t’échange une BOITE JETONS!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Cette BOITE JETONS peut être utilisée\n"
	.string "au CASINO.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, désolée…\p"
	.string "Mais il faut une BOITE JETONS\n"
	.string "pour jouer au CASINO.$"

