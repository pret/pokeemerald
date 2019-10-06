OldaleTown_Mart_MapScripts:: @ 81FC23F
	.byte 0

OldaleTown_Mart_EventScript_1FC240:: @ 81FC240
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_1FC26C
	pokemart OldaleTown_Mart_Pokemart_1FC260
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_Pokemart_1FC260: @ 81FC260
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_1FC26C:: @ 81FC26C
	pokemart OldaleTown_Mart_Pokemart_1FC27C
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_1FC27C: @ 81FC27C
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_1FC28A:: @ 81FC28A
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_1FC29F
	msgbox OldaleTown_Mart_Text_1FC2B2, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_1FC29F:: @ 81FC29F
	msgbox OldaleTown_Mart_Text_1FC2F3, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_1FC2A9:: @ 81FC2A9
	msgbox OldaleTown_Mart_Text_1FC338, MSGBOX_NPC
	end

OldaleTown_Mart_Text_1FC2B2: @ 81FC2B2
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any POKé BALLS.$"

OldaleTown_Mart_Text_1FC2F3: @ 81FC2F3
	.string "I'm going to buy a bunch of POKé BALLS\n"
	.string "and catch a bunch of POKéMON!$"

OldaleTown_Mart_Text_1FC338: @ 81FC338
	.string "If a POKéMON gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your POKéMON from fainting,\n"
	.string "restore its HP with a POTION.$"

