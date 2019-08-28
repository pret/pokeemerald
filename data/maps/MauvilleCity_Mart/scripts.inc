MauvilleCity_Mart_MapScripts:: @ 82110E5
	.byte 0

MauvilleCity_Mart_EventScript_2110E6:: @ 82110E6
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart_211100
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart_211100: @ 8211100
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

MauvilleCity_Mart_EventScript_21111C:: @ 821111C
	msgbox MauvilleCity_Mart_Text_21112E, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_211125:: @ 8211125
	msgbox MauvilleCity_Mart_Text_2111D8, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_21112E: @ 821112E
	.string "There are items that temporarily\n"
	.string "elevate the stats of POKéMON.\p"
	.string "The ones I know you use in battle\n"
	.string "are X ATTACK and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"

MauvilleCity_Mart_Text_2111D8: @ 82111D8
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The TRAINER's decisions determine how\n"
	.string "battles turn out, I think.$"

