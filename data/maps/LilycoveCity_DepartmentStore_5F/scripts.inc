LilycoveCity_DepartmentStore_5F_MapScripts:: @ 821FF7A
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_MapScript2_21FF80
	.byte 0

LilycoveCity_DepartmentStore_5F_MapScript2_21FF80: @ 821FF80
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_21FF9A
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_21FF9A:: @ 821FF9A
	setobjectxy 7, 16, 2
	turnobject 7, DIR_NORTH
	end

LilycoveCity_DepartmentStore_5F_EventScript_21FFA6:: @ 821FFA6
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls: @ 821FFC0
	.2byte DECOR_PICHU_DOLL
	.2byte DECOR_PIKACHU_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_JIGGLYPUFF_DOLL
	.2byte DECOR_DUSKULL_DOLL 
	.2byte DECOR_WYNAUT_DOLL
	.2byte DECOR_BALTOY_DOLL
	.2byte DECOR_KECLEON_DOLL
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_SWABLU_DOLL
	.2byte DECOR_GULPIN_DOLL
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_21FFDC:: @ 821FFDC
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions: @ 821FFF4
	.2byte DECOR_PIKA_CUSHION
	.2byte DECOR_ROUND_CUSHION
	.2byte DECOR_ZIGZAG_CUSHION
	.2byte DECOR_SPIN_CUSHION
	.2byte DECOR_DIAMOND_CUSHION
	.2byte DECOR_BALL_CUSHION
	.2byte DECOR_GRASS_CUSHION
	.2byte DECOR_FIRE_CUSHION
	.2byte DECOR_WATER_CUSHION
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22000A:: @ 822000A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Posters: @ 8220024
	.2byte DECOR_BALL_POSTER
	.2byte DECOR_GREEN_POSTER
	.2byte DECOR_RED_POSTER
	.2byte DECOR_BLUE_POSTER
	.2byte DECOR_CUTE_POSTER
	.2byte DECOR_PIKA_POSTER
	.2byte DECOR_LONG_POSTER
	.2byte DECOR_SEA_POSTER
	.2byte DECOR_SKY_POSTER
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22003A:: @ 822003A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Mats: @ 8220054
	.2byte DECOR_SURF_MAT
	.2byte DECOR_THUNDER_MAT
	.2byte DECOR_FIRE_BLAST_MAT
	.2byte DECOR_POWDER_SNOW_MAT
	.2byte DECOR_ATTRACT_MAT
	.2byte DECOR_FISSURE_MAT
	.2byte DECOR_SPIKES_MAT
	.2byte DECOR_GLITTER_MAT
	.2byte DECOR_JUMP_MAT
	.2byte DECOR_SPIN_MAT
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_22006C:: @ 822006C
	msgbox LilycoveCity_DepartmentStore_5F_Text_2200C5, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_220075:: @ 8220075
	lockall
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq LilycoveCity_DepartmentStore_5F_EventScript_22009C
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
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
	applymovement 7, Common_Movement_WalkInPlaceUp
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
