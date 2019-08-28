LilycoveCity_DepartmentStore_3F_MapScripts:: @ 821FC64
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_21FC65:: @ 821FC65
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_21FC7C
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_3F_Pokemart_21FC7C: @ 821FC7C
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FC8C:: @ 821FC8C
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_21FCA4
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_21FCA4: @ 821FCA4
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCB6:: @ 821FCB6
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FCD1, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCBF:: @ 821FCBF
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FD3B, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCC8:: @ 821FCC8
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FDB4, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_21FCD1: @ 821FCD1
	.string "For quickly toughening up POKéMON,\n"
	.string "items are the best.\p"
	.string "PROTEIN boosts ATTACK,\n"
	.string "and CALCIUM raises SP. ATK.$"

LilycoveCity_DepartmentStore_3F_Text_21FD3B: @ 821FD3B
	.string "I want my POKéMON to have more\n"
	.string "endurance.\p"
	.string "I'm trying to decide whether to raise\n"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"

LilycoveCity_DepartmentStore_3F_Text_21FDB4: @ 821FDB4
	.string "I gave a CARBOS to my POKéMON,\n"
	.string "and its SPEED went up.$"

