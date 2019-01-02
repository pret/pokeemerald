MossdeepCity_House3_MapScripts:: @ 82225C2
	.byte 0

MossdeepCity_House3_EventScript_2225C3:: @ 82225C3
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_222602
	msgbox MossdeepCity_House3_Text_222616, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_House3_EventScript_22260C
	msgbox MossdeepCity_House3_Text_2226B6, MSGBOX_DEFAULT
	giveitem_std ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_2226F0, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_222602:: @ 8222602
	msgbox MossdeepCity_House3_Text_222751, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_22260C:: @ 822260C
	msgbox MossdeepCity_House3_Text_222733, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_222616: @ 8222616
	.string "Hey there, TRAINER!\n"
	.string "A SUPER ROD really is super!\p"
	.string "Say all you want, but this baby can\n"
	.string "catch POKéMON off the seafloor!\p"
	.string "What do you think?\n"
	.string "You want it, don't you?$"

MossdeepCity_House3_Text_2226B6: @ 82226B6
	.string "You bet, you bet!\n"
	.string "After all, a SUPER ROD is really super!$"

MossdeepCity_House3_Text_2226F0: @ 82226F0
	.string "If there's any water, try dropping in\n"
	.string "your ROD and see what bites!$"

MossdeepCity_House3_Text_222733: @ 8222733
	.string "Hunh?\n"
	.string "Don't you like to fish?$"

MossdeepCity_House3_Text_222751: @ 8222751
	.string "Go after the seafloor POKéMON with\n"
	.string "your SUPER ROD.$"

