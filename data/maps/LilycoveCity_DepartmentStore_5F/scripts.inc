.set LOCALID_WOMAN, 7

LilycoveCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
	.byte 0

@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
LilycoveCity_DepartmentStore_5F_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs::
	setobjectxy LOCALID_WOMAN, 16, 2
	turnobject LOCALID_WOMAN, DIR_NORTH
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls:
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
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions:
	.2byte DECOR_PIKA_CUSHION
	.2byte DECOR_ROUND_CUSHION
	.2byte DECOR_ZIGZAG_CUSHION
	.2byte DECOR_SPIN_CUSHION
	.2byte DECOR_DIAMOND_CUSHION
	.2byte DECOR_BALL_CUSHION
	.2byte DECOR_GRASS_CUSHION
	.2byte DECOR_FIRE_CUSHION
	.2byte DECOR_WATER_CUSHION
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Posters:
	.2byte DECOR_BALL_POSTER
	.2byte DECOR_GREEN_POSTER
	.2byte DECOR_RED_POSTER
	.2byte DECOR_BLUE_POSTER
	.2byte DECOR_CUTE_POSTER
	.2byte DECOR_PIKA_POSTER
	.2byte DECOR_LONG_POSTER
	.2byte DECOR_SEA_POSTER
	.2byte DECOR_SKY_POSTER
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Mats:
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
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_Woman::
	lockall
	applymovement LOCALID_WOMAN, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal::
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather::
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
	.string "I'm not big enough to raise POKéMON,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"
