LilycoveCity_DepartmentStore_2F_MapScripts:: @ 821FB2C
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_21FB2D:: @ 821FB2D
	msgbox LilycoveCity_DepartmentStore_2F_Text_21FBAC, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_21FB36:: @ 821FB36
	msgbox LilycoveCity_DepartmentStore_2F_Text_21FBDF, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_21FB3F:: @ 821FB3F
	msgbox LilycoveCity_DepartmentStore_2F_Text_21FC23, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_21FB48:: @ 821FB48
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart_21FB60
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart_21FB60: @ 821FB60
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_21FB7A:: @ 821FB7A
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart_21FB94
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart_21FB94: @ 821FB94
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_Text_21FBAC: @ 821FBAC
	.string "Learn to use items properly.\n"
	.string "That's basic, really.$"

LilycoveCity_DepartmentStore_2F_Text_21FBDF: @ 821FBDF
	.string "My husband is waiting at home.\n"
	.string "What would make a good gift for him?$"

LilycoveCity_DepartmentStore_2F_Text_21FC23: @ 821FC23
	.string "I'm leaving on a long journey soon.\n"
	.string "I need to stock up on items.$"

