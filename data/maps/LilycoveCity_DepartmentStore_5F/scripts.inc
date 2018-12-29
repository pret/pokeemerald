LilycoveCity_DepartmentStore_5F_MapScripts:: @ 821FF7A
	map_script 4, LilycoveCity_DepartmentStore_5F_MapScript2_21FF80
	.byte 0

LilycoveCity_DepartmentStore_5F_MapScript2_21FF80: @ 821FF80
	map_script_2 VAR_0x405E, 1, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	map_script_2 VAR_0x405E, 2, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	map_script_2 VAR_0x405E, 3, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_21FF9A:: @ 821FF9A
	setobjectxy 7, 16, 2
	turnobject 7, 2
	end

LilycoveCity_DepartmentStore_5F_EventScript_21FFA6:: @ 821FFA6
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_21FFC0
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_21FFC0: @ 821FFC0
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_SUPER_REPEL
	.2byte 91
	.2byte 92
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_21FFDC:: @ 821FFDC
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_21FFF4
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_21FFF4: @ 821FFF4
	.2byte 101
	.2byte 102
	.2byte ITEM_BIG_MUSHROOM
	.2byte 105
	.2byte ITEM_PEARL
	.2byte ITEM_BIG_PEARL
	.2byte ITEM_STARDUST
	.2byte ITEM_STAR_PIECE
	.2byte ITEM_NUGGET
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22000A:: @ 822000A
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_220024
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_220024: @ 8220024
	.2byte ITEM_CARBOS
	.2byte ITEM_CALCIUM
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_PP_UP
	.2byte ITEM_ZINC
	.2byte ITEM_PP_MAX
	.2byte 72
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22003A:: @ 822003A
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_220054
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_220054: @ 8220054
	.2byte 59
	.2byte 60
	.2byte 61
	.2byte 62
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_RED_SHARD
	.2byte ITEM_BLUE_SHARD
	.2byte ITEM_YELLOW_SHARD
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22006C:: @ 822006C
	msgbox LilycoveCity_DepartmentStore_5F_Text_2200C5, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_220075:: @ 8220075
	lockall
	applymovement 7, LilycoveCity_DepartmentStore_5F_Movement_27259E
	waitmovement 0
	compare VAR_0x405E, 0
	goto_if_eq LilycoveCity_DepartmentStore_5F_EventScript_22009C
	compare VAR_0x405E, 4
	goto_if_ge LilycoveCity_DepartmentStore_5F_EventScript_22009C
	goto LilycoveCity_DepartmentStore_5F_EventScript_2200A7
	end

LilycoveCity_DepartmentStore_5F_EventScript_22009C:: @ 822009C
	msgbox LilycoveCity_DepartmentStore_5F_Text_22016B, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_2200A7:: @ 82200A7
	msgbox LilycoveCity_DepartmentStore_5F_Text_2201C4, MSGBOX_DEFAULT
	closemessage
	applymovement 7, LilycoveCity_DepartmentStore_5F_Movement_2725A6
	waitmovement 0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_2200BC:: @ 82200BC
	msgbox LilycoveCity_DepartmentStore_5F_Text_220122, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_2200C5: @ 82200C5
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_220122: @ 8220122
	.string "I'm not big enough to raise POKéMON,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_22016B: @ 822016B
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_2201C4: @ 82201C4
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"

