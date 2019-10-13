LavaridgeTown_HerbShop_MapScripts:: @ 81FE4D6
	.byte 0

LavaridgeTown_HerbShop_EventScript_1FE4D7:: @ 81FE4D7
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_1FE53E
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart_1FE4F0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart_1FE4F0: @ 81FE4F0
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_1FE4FC:: @ 81FE4FC
	msgbox LavaridgeTown_HerbShop_Text_1FE685, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_1FE505:: @ 81FE505
	lock
	faceplayer
	goto_if_set FLFLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_1FE534
	msgbox LavaridgeTown_HerbShop_Text_1FE584, MSGBOX_DEFAULT
	giveitem_std ITEM_CHARCOAL
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLFLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_1FE534:: @ 81FE534
	msgbox LavaridgeTown_HerbShop_Text_1FE5EB, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_1FE53E: @ 81FE53E
	.string "Welcome to the HERB SHOP, home of\n"
	.string "effective and inexpensive medicine!$"

LavaridgeTown_HerbShop_Text_1FE584: @ 81FE584
	.string "You've come to look at herbal medicine\n"
	.string "in LAVARIDGE?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"

LavaridgeTown_HerbShop_Text_1FE5EB: @ 81FE5EB
	.string "That CHARCOAL I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a POKéMON.\p"
	.string "It intensifies the power of FIRE-type\n"
	.string "moves.$"

LavaridgeTown_HerbShop_Text_1FE685: @ 81FE685
	.string "Herbal medicine works impressively well.\n"
	.string "But your POKéMON will dislike you for it.\l"
	.string "It must be horribly bitter!$"

