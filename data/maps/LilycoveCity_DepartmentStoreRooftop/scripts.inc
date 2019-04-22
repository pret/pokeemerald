LilycoveCity_DepartmentStoreRooftop_MapScripts:: @ 8220207
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition: @ 822020D
	getpricereduction 3
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220227
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_22022B
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220227:: @ 8220227
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_22022B:: @ 822022B
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_22022F:: @ 822022F
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_220248
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_220248: @ 8220248
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220268:: @ 8220268
	lock
	faceplayer
	getpricereduction 3
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220282
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_220463, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220282:: @ 8220282
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2204C9, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_22028C:: @ 822028C
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_220552, MSGBOX_NPC
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220295:: @ 8220295
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_22056D
	waitmessage
	showmoneybox 0, 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_2202A6
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2202A6:: @ 82202A6
	multichoice 16, 0, 42, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_2202E4
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_2202EF
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_2202FA
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_220603, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22045E
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2202E4:: @ 82202E4
	setvar VAR_TEMP_0, 26
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22032F
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2202EF:: @ 82202EF
	setvar VAR_TEMP_0, 27
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22032F
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2202FA:: @ 82202FA
	setvar VAR_TEMP_0, 28
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22032F
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220305:: @ 8220305
	checkmoney 0xc8, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_22030C:: @ 822030C
	checkmoney 0x12c, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_220313:: @ 8220313
	checkmoney 0x15e, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_22031A:: @ 822031A
	takemoney 0xc8, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_220321:: @ 8220321
	takemoney 0x12c, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_220328:: @ 8220328
	takemoney 0x15e, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_22032F:: @ 822032F
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220305
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_22030C
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220313
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220442
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220450
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_22031A
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220321
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220328
	updatemoneybox 0, 0
	nop
	bufferitemname 0, VAR_TEMP_0
	playse SE_JIHANKI
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2205A1, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, 14
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_220436
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220450
	playse SE_JIHANKI
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2205C2, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, 14
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_220436
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_220450
	playse SE_JIHANKI
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2205C2, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0, 1
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, 14
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_220436
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220436:: @ 8220436
	message LilycoveCity_DepartmentStoreRooftop_Text_22056D
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_2202A6
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220442:: @ 8220442
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2205F1, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22045E
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_220450:: @ 8220450
	msgbox gUnknown_08272A89, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_22045E
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_22045E:: @ 822045E
	hidemoneybox
	nop
	nop
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_220463: @ 8220463
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_2204C9: @ 82204C9
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_220552: @ 8220552
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_22056D: @ 822056D
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_2205A1: @ 82205A1
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_2205C2: @ 82205C2
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_2205F1: @ 82205F1
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_220603: @ 8220603
	.string "Decided against buying a drink.$"
