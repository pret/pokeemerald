MauvilleCity_House2_MapScripts:: @ 8210C5C
	.byte 0

MauvilleCity_House2_EventScript_210C5D:: @ 8210C5D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_210CDA
	msgbox MauvilleCity_House2_Text_210CEE, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_House2_EventScript_210C82
	release
	end

MauvilleCity_House2_EventScript_210C82:: @ 8210C82
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_210D76, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_House2_EventScript_210CB8
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_House2_EventScript_210CE4
	end

MauvilleCity_House2_EventScript_210CB8:: @ 8210CB8
	msgbox MauvilleCity_House2_Text_210DB3, MSGBOX_DEFAULT
	takeitem ITEM_HARBOR_MAIL, 1
	giveitem_std ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_210CDA
	end

MauvilleCity_House2_EventScript_210CDA:: @ 8210CDA
	msgbox MauvilleCity_House2_Text_210DE7, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_210CE4:: @ 8210CE4
	msgbox MauvilleCity_House2_Text_210E16, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_210CEE: @ 8210CEE
	.string "If I had a Bike, it'd be easy to cycle to\n"
	.string "Slateport for some shopping.\p"
	.string "I'd be able to buy Harbor Mail at the\n"
	.string "Pokémon Mart in Slateport…$"

MauvilleCity_House2_Text_210D76: @ 8210D76
	.string "Oh! You have Harbor Mail?\n"
	.string "Will you trade it for a Coin Case?$"

MauvilleCity_House2_Text_210DB3: @ 8210DB3
	.string "Oh, I'm so happy!\n"
	.string "Okay, I'll trade you a Coin Case!$"

MauvilleCity_House2_Text_210DE7: @ 8210DE7
	.string "That Coin Case can be used\n"
	.string "at the Game Corner.$"

MauvilleCity_House2_Text_210E16: @ 8210E16
	.string "Oh, that's disappointing.\p"
	.string "A Coin Case is needed for the\n"
	.string "Game Corner.$"

