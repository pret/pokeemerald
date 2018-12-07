LilycoveCity_DepartmentStore_4F_MapScripts:: @ 821FDEA
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_21FDEB:: @ 821FDEB
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FE50, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FDF4:: @ 821FDF4
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FEC7, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FDFD:: @ 821FDFD
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FF2D, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FE06:: @ 821FE06
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_21FE20
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_21FE20: @ 821FE20
	.2byte ITEM_TM38
	.2byte ITEM_TM25
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FE2C:: @ 821FE2C
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_21FE44
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_21FE44: @ 821FE44
	.2byte ITEM_TM17
	.2byte ITEM_TM20
	.2byte ITEM_TM33
	.2byte ITEM_TM16
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_21FE50: @ 821FE50
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to POKéMON…$"

LilycoveCity_DepartmentStore_4F_Text_21FEC7: @ 821FEC7
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are fifty\n"
	.string "different kinds.$"

LilycoveCity_DepartmentStore_4F_Text_21FF2D: @ 821FF2D
	.string "I'd like to get all the different TMs,\n"
	.string "but a POKéMON learns only four moves.$"

