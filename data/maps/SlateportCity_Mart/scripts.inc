SlateportCity_Mart_MapScripts:: @ 820DC48
	.byte 0

SlateportCity_Mart_EventScript_20DC49:: @ 820DC49
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart SlateportCity_Mart_Pokemart_20DC60
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

SlateportCity_Mart_Pokemart_20DC60: @ 820DC60
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_20DC76:: @ 820DC76
	msgbox SlateportCity_Mart_Text_20DC88, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_20DC7F:: @ 820DC7F
	msgbox SlateportCity_Mart_Text_20DCF8, MSGBOX_NPC
	end

SlateportCity_Mart_Text_20DC88: @ 820DC88
	.string "The MARKET does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a POKéMON MART.$"

SlateportCity_Mart_Text_20DCF8: @ 820DCF8
	.string "A GREAT BALL is better than a POKé BALL\n"
	.string "at catching POKéMON.\p"
	.string "With this, I should be able to get that\n"
	.string "elusive POKéMON…$"

