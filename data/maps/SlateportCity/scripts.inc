SlateportCity_MapScripts:: @ 81DCC61
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_MapScript2_1DCD12
	.byte 0

SlateportCity_OnTransition: @ 81DCC6C
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_1DCC8D
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCC99
	compare VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCCE7
	end

SlateportCity_EventScript_1DCC8D:: @ 81DCC8D
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_1DCC99:: @ 81DCC99
	setobjectxyperm 11, 28, 13
	setobjectxyperm 7, 25, 13
	setobjectxyperm 3, 25, 14
	setobjectxyperm 6, 27, 16
	setobjectxyperm 8, 28, 16
	setobjectxyperm 1, 29, 16
	setobjectxyperm 2, 31, 14
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_1DCCE7:: @ 81DCCE7
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 30
	goto_if_eq SlateportCity_EventScript_1DCD06
	setobjectxyperm 35, 23, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_1DCD06:: @ 81DCD06
	setobjectxyperm 35, 22, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_MapScript2_1DCD12: @ 81DCD12
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_1DCD1C
	.2byte 0

SlateportCity_EventScript_1DCD1C:: @ 81DCD1C
	lockall
	addobject 35
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DCDA8
	applymovement 35, SlateportCity_Movement_1DCDAC
	waitmovement 0
	msgbox SlateportCity_Text_1DF032, MSGBOX_DEFAULT
	closemessage
	applymovement 35, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_1DF0FE, MSGBOX_DEFAULT
	applymovement 35, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SlateportCity_Text_1DF12B, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox SlateportCity_Text_1DF1A6, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_1DF1D3, MSGBOX_DEFAULT
	closemessage
	applymovement 35, SlateportCity_Movement_1DCDB4
	waitmovement 0
	removeobject 35
	setobjectxyperm 35, 10, 12
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_1DCDA8: @ 81DCDA8
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DCDAC: @ 81DCDAC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_1DCDB4: @ 81DCDB4
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_1DCDBD:: @ 81DCDBD
	lock
	faceplayer
	message SlateportCity_Text_1DD64A
	waitmessage
	pokemart SlateportCity_Pokemart_1DCDD4
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

SlateportCity_Pokemart_1DCDD4: @ 81DCDD4
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_1DCDE4:: @ 81DCDE4
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox SlateportCity_Text_1DD68A, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, 1
	call_if_eq SlateportCity_EventScript_1DCE38
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	compare VAR_RESULT, 0
	call_if_eq SlateportCity_EventScript_1DCE2E
	msgbox SlateportCity_Text_1DD697, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message SlateportCity_Text_1DD6E3
	waitfanfare
	msgbox SlateportCity_Text_1DD702, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_1DCE2E:: @ 81DCE2E
	msgbox SlateportCity_Text_1DD722, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE38:: @ 81DCE38
	msgbox SlateportCity_Text_1DD77B, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE42:: @ 81DCE42
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE59
	msgbox SlateportCity_Text_1DD81A, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE59:: @ 81DCE59
	msgbox SlateportCity_Text_1DE3E2, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE63:: @ 81DCE63
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE7A
	msgbox SlateportCity_Text_1DD8A6, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE7A:: @ 81DCE7A
	msgbox SlateportCity_Text_1DE28E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE84:: @ 81DCE84
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCEA4
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DCEAE
	msgbox SlateportCity_Text_1DD93D, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEA4:: @ 81DCEA4
	msgbox SlateportCity_Text_1DE30C, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEAE:: @ 81DCEAE
	msgbox SlateportCity_Text_1DD999, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEB8:: @ 81DCEB8
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCECF
	msgbox SlateportCity_Text_1DDA34, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCECF:: @ 81DCECF
	msgbox SlateportCity_Text_1DE376, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCED9:: @ 81DCED9
	compare VAR_SLATEPORT_STATE, 1
	goto_if_eq SlateportCity_EventScript_1DCEED
	msgbox SlateportCity_Text_1DDA9A, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCEED:: @ 81DCEED
	msgbox SlateportCity_Text_1DE43D, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCEF6:: @ 81DCEF6
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCF0D
	msgbox SlateportCity_Text_1DDB21, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF0D:: @ 81DCF0D
	msgbox SlateportCity_Text_1DE460, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF17:: @ 81DCF17
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_1DCF2C
	msgbox SlateportCity_Text_1DDBAC, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF2C:: @ 81DCF2C
	msgbox SlateportCity_Text_1DDBD5, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF36:: @ 81DCF36
	msgbox SlateportCity_Text_1DE8BC, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF3F:: @ 81DCF3F
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCF66
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_1DCF5C
	msgbox SlateportCity_Text_1DE8F8, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF5C:: @ 81DCF5C
	msgbox SlateportCity_Text_1DE940, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF66:: @ 81DCF66
	msgbox SlateportCity_Text_1DE9AA, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF70:: @ 81DCF70
	msgbox SlateportCity_Text_1DEA0B, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF79:: @ 81DCF79
	msgbox SlateportCity_Text_1DEA3B, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF82:: @ 81DCF82
	msgbox SlateportCity_Text_1DEA6F, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF8B:: @ 81DCF8B
	msgbox SlateportCity_Text_1DEAAF, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF94:: @ 81DCF94
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCFA8
	msgbox SlateportCity_Text_1DEAE3, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCFA8:: @ 81DCFA8
	msgbox SlateportCity_Text_1DEB5A, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCFB2:: @ 81DCFB2
	msgbox SlateportCity_Text_1DEBA0, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCFBB:: @ 81DCFBB
	lock
	faceplayer
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCFD2
	msgbox SlateportCity_Text_1DE10E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCFD2:: @ 81DCFD2
	msgbox SlateportCity_Text_1DE10E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCFDC:: @ 81DCFDC
	msgbox SlateportCity_Text_1DE16C, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFE5:: @ 81DCFE5
	msgbox SlateportCity_Text_1DDFF7, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFEE:: @ 81DCFEE
	msgbox SlateportCity_Text_1DE04B, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFF7:: @ 81DCFF7
	msgbox SlateportCity_Text_1DE0D2, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD000:: @ 81DD000
	msgbox SlateportCity_Text_1DE1EC, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD009:: @ 81DD009
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC4F, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD020:: @ 81DD020
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC8A, MSGBOX_DEFAULT
	closemessage
	applymovement 18, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD037:: @ 81DD037
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDCD5, MSGBOX_DEFAULT
	closemessage
	applymovement 19, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD04E:: @ 81DD04E
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDD18, MSGBOX_DEFAULT
	closemessage
	applymovement 26, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD065:: @ 81DD065
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDD7D, MSGBOX_DEFAULT
	closemessage
	applymovement 27, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD07C:: @ 81DD07C
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDC0, MSGBOX_DEFAULT
	closemessage
	applymovement 28, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD093:: @ 81DD093
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDDF, MSGBOX_DEFAULT
	closemessage
	applymovement 29, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD0AA:: @ 81DD0AA
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDE2F, MSGBOX_DEFAULT
	closemessage
	applymovement 30, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD0C1:: @ 81DD0C1
	lock
	faceplayer
	playse SE_PIN
	applymovement 31, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 31, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_1DDE6E, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_1DDE86, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	msgbox SlateportCity_Text_1DDEB8, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_1DD147: @ 81DD147
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_1DD14A:: @ 81DD14A
	msgbox SlateportCity_Text_1DDF32, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD153:: @ 81DD153
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDF8D, MSGBOX_DEFAULT
	closemessage
	applymovement 33, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD16A:: @ 81DD16A
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls: @ 81DD184
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_1DD18E:: @ 81DD18E
	msgbox gUnknown_08272E30, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD198:: @ 81DD198
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DD18E
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_1DD1B8
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemartDecor_1DD1B8: @ 81DD1B8
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_1DD1D8:: @ 81DD1D8
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart SlateportCity_Pokemart_1DD1F0
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_1DD1F0: @ 81DD1F0
	.2byte ITEM_TM10
	.2byte ITEM_TM43
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_1DD1F8:: @ 81DD1F8
	lockall
	msgbox SlateportCity_Text_1DE502, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_1DE54A, MSGBOX_DEFAULT
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 25
	applymovement 11, SlateportCity_Movement_1DD33C
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD34A
	applymovement 10, SlateportCity_Movement_1DD319
	applymovement 9, SlateportCity_Movement_1DD326
	waitmovement 0
	removeobject 10
	removeobject 9
	msgbox SlateportCity_Text_1DE5F7, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox SlateportCity_Text_1DE64F, MSGBOX_DEFAULT
	playbgm MUS_AQA_0, 0
	msgbox SlateportCity_Text_1DE724, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_WalkInPlaceLeft
	applymovement 1, Common_Movement_WalkInPlaceLeft
	applymovement 7, SlateportCity_Movement_1DD309
	applymovement 3, SlateportCity_Movement_272596
	applymovement 2, SlateportCity_Movement_1DD311
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SlateportCity_Text_1DE7F7, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, Common_Movement_Delay48
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox SlateportCity_Text_1DE860, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_1DE8A0, MSGBOX_DEFAULT
	closemessage
	applymovement 11, SlateportCity_Movement_1DD337
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD344
	waitmovement 0
	removeobject 11
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_1DD309: @ 81DD309
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DD311: @ 81DD311
	emote_question_mark
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DD319: @ 81DD319
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_1DD326: @ 81DD326
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_1DD334: @ 81DD334
	walk_down
	walk_in_place_fastest_up
	step_end

SlateportCity_Movement_1DD337: @ 81DD337
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_1DD33C: @ 81DD33C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_1DD344: @ 81DD344
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_1DD34A: @ 81DD34A
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_EventScript_1DD353:: @ 81DD353
	msgbox SlateportCity_Text_1DE491, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD35C:: @ 81DD35C
	msgbox SlateportCity_Text_1DE4C4, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD365:: @ 81DD365
	msgbox SlateportCity_Text_1DD7AD, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD36E:: @ 81DD36E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_1DD39A
	msgbox SlateportCity_Text_1DEBCE, MSGBOX_DEFAULT
	giveitem_std ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_1DED27, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD39A:: @ 81DD39A
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3C0
	msgbox SlateportCity_Text_1DEE40, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_1DD3CA
	end

SlateportCity_EventScript_1DD3C0:: @ 81DD3C0
	msgbox SlateportCity_Text_1DED27, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD3CA:: @ 81DD3CA
	message SlateportCity_Text_1DEE67
	waitmessage
	setvar VAR_0x8004, 7
	special sub_813A128
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_1DD46E
	case 1, SlateportCity_EventScript_1DD482
	case 2, SlateportCity_EventScript_1DD496
	case 3, SlateportCity_EventScript_1DD4AA
	case 4, SlateportCity_EventScript_1DD4BE
	case 5, SlateportCity_EventScript_1DD4D2
	case 6, SlateportCity_EventScript_1DD4E6
	case 7, SlateportCity_EventScript_1DD4FA
	case 8, SlateportCity_EventScript_1DD50E
	case 9, SlateportCity_EventScript_1DD522
	case 10, SlateportCity_EventScript_1DD536
	case 11, SlateportCity_EventScript_1DD54A
	case 127, SlateportCity_EventScript_1DD54A
	end

SlateportCity_EventScript_1DD46E:: @ 81DD46E
	bufferitemname 0, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, 30
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD482:: @ 81DD482
	bufferitemname 0, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, 31
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD496:: @ 81DD496
	bufferitemname 0, ITEM_HEAL_POWDER
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4AA:: @ 81DD4AA
	bufferitemname 0, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, 33
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4BE:: @ 81DD4BE
	bufferitemname 0, ITEM_PROTEIN
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4D2:: @ 81DD4D2
	bufferitemname 0, ITEM_IRON
	setvar VAR_0x8008, 65
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4E6:: @ 81DD4E6
	bufferitemname 0, ITEM_CARBOS
	setvar VAR_0x8008, 66
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4FA:: @ 81DD4FA
	bufferitemname 0, ITEM_CALCIUM
	setvar VAR_0x8008, 67
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD50E:: @ 81DD50E
	bufferitemname 0, ITEM_ZINC
	setvar VAR_0x8008, 70
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD522:: @ 81DD522
	bufferitemname 0, ITEM_HP_UP
	setvar VAR_0x8008, 63
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD536:: @ 81DD536
	bufferitemname 0, ITEM_PP_UP
	setvar VAR_0x8008, 69
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD54A:: @ 81DD54A
	msgbox SlateportCity_Text_1DEFBC, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD557:: @ 81DD557
	msgbox SlateportCity_Text_1DEE90, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3CA
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5CE
	giveitem_std VAR_0x8008
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5C1
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_1DEEF7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_EventScript_1DD3CA
	msgbox SlateportCity_Text_1DEF79, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD5C1:: @ 81DD5C1
	msgbox gUnknown_08272A89, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD5CE:: @ 81DD5CE
	msgbox SlateportCity_Text_1DEEC9, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_1DD3CA
	end

SlateportCity_EventScript_1DD5DC:: @ 81DD5DC
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject 35
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD630
	applymovement 35, SlateportCity_Movement_1DD637
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_1DF28C, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD634
	applymovement 35, SlateportCity_Movement_1DD63A
	waitmovement 0
	removeobject 35
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_1DD630: @ 81DD630
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_1DD634: @ 81DD634
	delay_16
	walk_in_place_fastest_right
	step_end

SlateportCity_Movement_1DD637: @ 81DD637
	delay_8
	walk_down
	step_end

SlateportCity_Movement_1DD63A: @ 81DD63A
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_1DD643:: @ 81DD643
	lockall
	special sub_80224D0
	waitstate
	releaseall
	end

SlateportCity_Text_1DD64A: @ 81DD64A
	.string "I'm the ENERGY GURU! I'll go for it and\n"
	.string "sell you what you need!$"

SlateportCity_Text_1DD68A: @ 81DD68A
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"

SlateportCity_Text_1DD697: @ 81DD697
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"

SlateportCity_Text_1DD6E3: @ 81DD6E3
	.string "{PLAYER} received the EFFORT RIBBON.$"

SlateportCity_Text_1DD702: @ 81DD702
	.string "{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"

SlateportCity_Text_1DD722: @ 81DD722
	.string "You have to go for it a little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"

SlateportCity_Text_1DD77B: @ 81DD77B
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"

SlateportCity_Text_1DD7AD: @ 81DD7AD
	.string "The light of the lighthouse reaches\n"
	.string "dozens of miles away.\p"
	.string "I wonder if it doesn't startle POKéMON\n"
	.string "in the sea.$"

SlateportCity_Text_1DD81A: @ 81DD81A
	.string "Ooh, look at this!\p"
	.string "The seaweed you can get around these\n"
	.string "parts is fresh and full of life.\p"
	.string "Why, it looks like it can even rear up\n"
	.string "and attack!$"

SlateportCity_Text_1DD8A6: @ 81DD8A6
	.string "Where the water is clean, the fruits\n"
	.string "of bountiful harvest gather.\p"
	.string "And where people gather, a market\n"
	.string "soon starts.\p"
	.string "That is how a town is born and grows.$"

SlateportCity_Text_1DD93D: @ 81DD93D
	.string "Shopping where you can breathe the\n"
	.string "scent of the ocean…\p"
	.string "SLATEPORT is such a wonderful place!$"

SlateportCity_Text_1DD999: @ 81DD999
	.string "If you put DOLLS or CUSHIONS on\n"
	.string "the floor, they'll get dirty.\p"
	.string "I'm going to buy some BRICKS so my\n"
	.string "DOLLS and CUSHIONS won't get dirty\l"
	.string "when I leave them out.$"

SlateportCity_Text_1DDA34: @ 81DDA34
	.string "Wroooar! I'm going to compete in\n"
	.string "the BATTLE TENT, too!\p"
	.string "But before that, I need to catch\n"
	.string "some POKéMON!$"

SlateportCity_Text_1DDA9A: @ 81DDA9A
	.string "Whew… I'm just bushed…\p"
	.string "I hiked over from MAUVILLE CITY.\n"
	.string "But, boy, this city's huge.\p"
	.string "If I'd known this, I would've ridden\n"
	.string "my BIKE here.$"

SlateportCity_Text_1DDB21: @ 81DDB21
	.string "STERN, the fellow who built the\n"
	.string "MUSEUM, also happens to be the leader\l"
	.string "of an undersea exploration team.\p"
	.string "So, everyone calls him CAPT. STERN.$"

SlateportCity_Text_1DDBAC: @ 81DDBAC
	.string "What is that over there?\n"
	.string "That long line…$"

SlateportCity_Text_1DDBD5: @ 81DDBD5
	.string "When I was a child, I visited\n"
	.string "the MUSEUM often.\p"
	.string "I used to dream about the mysteries of\n"
	.string "the sea after seeing the exhibits.$"

SlateportCity_Text_1DDC4F: @ 81DDC4F
	.string "Hey, there! Quit pushing!\n"
	.string "This is the line, can't you see?$"

SlateportCity_Text_1DDC8A: @ 81DDC8A
	.string "TEAM AQUA has a policy of\n"
	.string "assembling and dispersing at\l"
	.string "the operation site.$"

SlateportCity_Text_1DDCD5: @ 81DDCD5
	.string "Our BOSS is brilliant.\p"
	.string "What would he want to do with\n"
	.string "a MUSEUM now?$"

SlateportCity_Text_1DDD18: @ 81DDD18
	.string "What's the new scheme, I wonder?\p"
	.string "Our BOSS is scary when he's mad, so\n"
	.string "I'd better not screw things up…$"

SlateportCity_Text_1DDD7D: @ 81DDD7D
	.string "If there's something we need in\n"
	.string "the MUSEUM, we should take it all!$"

SlateportCity_Text_1DDDC0: @ 81DDDC0
	.string "Hey, you there!\n"
	.string "Don't butt in!$"

SlateportCity_Text_1DDDDF: @ 81DDDDF
	.string "A long line, huh?\p"
	.string "It reminds me of the times I lined up to\n"
	.string "buy smash-hit games…$"

SlateportCity_Text_1DDE2F: @ 81DDE2F
	.string "Why are we even lining up and paying?\n"
	.string "We should just march in!$"

SlateportCity_Text_1DDE6E: @ 81DDE6E
	.string "What?\n"
	.string "What do you want?$"

SlateportCity_Text_1DDE86: @ 81DDE86
	.string "You want to read this sign?\n"
	.string "I'll read it for you!$"

SlateportCity_Text_1DDEB8: @ 81DDEB8
	.string "Let's see…\p"
	.string "Um… I think it says something like\n"
	.string "“the life in the sea is endless.”\p"
	.string "Yup, I'm pretty sure that's what\n"
	.string "it says.$"

SlateportCity_Text_1DDF32: @ 81DDF32
	.string "Grumble…\p"
	.string "I should've brought my Game Boy\n"
	.string "Advance so I wouldn't get bored in line…\p"
	.string "Grumble…$"

SlateportCity_Text_1DDF8D: @ 81DDF8D
	.string "When this operation's over, I'll take\n"
	.string "you to a hot spring spa!\p"
	.string "That's what our leader said.\n"
	.string "I can't wait!$"

SlateportCity_Text_1DDFF7: @ 81DDFF7
	.string "The sea is just so vast…\p"
	.string "Could the sea have been made by\n"
	.string "the tears shed by POKéMON?$"

SlateportCity_Text_1DE04B: @ 81DE04B
	.string "Do you know what they do with old\n"
	.string "ships that become too creaky to sail?\p"
	.string "They sink them in the sea so they\n"
	.string "become habitats for POKéMON.$"

SlateportCity_Text_1DE0D2: @ 81DE0D2
	.string "Whenever I visit here, I get carried\n"
	.string "away and buy too much.$"

SlateportCity_Text_1DE10E: @ 81DE10E
	.string "If you want to change your POKéMON's\n"
	.string "nickname, you'll have to get the NAME\l"
	.string "RATER to help you.$"

SlateportCity_Text_1DE16C: @ 81DE16C
	.string "Any POKéMON you get in a trade,\n"
	.string "you can't change its nickname.\p"
	.string "The original TRAINER's love for that\n"
	.string "POKéMON is in the nickname.$"

SlateportCity_Text_1DE1EC: @ 81DE1EC
	.string "Recently, a BATTLE TENT was built\n"
	.string "in SLATEPORT.\p"
	.string "GYMS are fun, but the BATTLE TENT's\n"
	.string "awesome in its own way.\p"
	.string "You should go find tough POKéMON\n"
	.string "for the BATTLE TENT!$"

SlateportCity_Text_1DE28E: @ 81DE28E
	.string "I was hoping that it was a famous star\n"
	.string "so I could get an autograph.\p"
	.string "But who's that being interviewed?\n"
	.string "Isn't that CAPT. STERN?$"

SlateportCity_Text_1DE30C: @ 81DE30C
	.string "That lady interviewer is so cool\n"
	.string "and pretty.\p"
	.string "When I grow up, I'm going to be\n"
	.string "an international journalist!$"

SlateportCity_Text_1DE376: @ 81DE376
	.string "CAPT. STERN says they discovered\n"
	.string "something at the bottom of the sea.\p"
	.string "I wonder what it is?\n"
	.string "What could it be?$"

SlateportCity_Text_1DE3E2: @ 81DE3E2
	.string "What's going on here?\p"
	.string "Did the good CAPTAIN come back with\n"
	.string "a big fish from the ocean floor?$"

SlateportCity_Text_1DE43D: @ 81DE43D
	.string "Hey! Are you watching?\n"
	.string "Am I on TV?$"

SlateportCity_Text_1DE460: @ 81DE460
	.string "A TV interview! Here!\n"
	.string "The CAPTAIN's a celebrity!$"

SlateportCity_Text_1DE491: @ 81DE491
	.string "TY: Okay, CAPT. STERN, a big smile\n"
	.string "for the camera!$"

SlateportCity_Text_1DE4C4: @ 81DE4C4
	.string "GABBY: I see, I see. You've had a most\n"
	.string "invaluable experience…$"

SlateportCity_Text_1DE502: @ 81DE502
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
	.string "move ahead with our exploration.$"

SlateportCity_Text_1DE54A: @ 81DE54A
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
	.string "Thank you for taking the time from\l"
	.string "your busy schedule to talk to us.\p"
	.string "We hope we can interview you again\n"
	.string "with news of more discoveries!$"

SlateportCity_Text_1DE5F7: @ 81DE5F7
	.string "CAPT. STERN: Whew…\p"
	.string "That was my first time to be filmed for\n"
	.string "TV. That was nerve-wracking.$"

SlateportCity_Text_1DE64F: @ 81DE64F
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "You're looking great!\p"
	.string "We made a huge discovery on our last\n"
	.string "seafloor exploration.\p"
	.string "We found an underwater cavern on\n"
	.string "ROUTE 128.\p"
	.string "We think it's the habitat of a POKéMON\n"
	.string "that's said to have been long extinct.$"

SlateportCity_Text_1DE724: @ 81DE724
	.string "Fufufu…\n"
	.string "CAPT. STERN, I presume.\p"
	.string "We of TEAM AQUA will assume\n"
	.string "control of your submarine!\p"
	.string "Your objections are meaningless!\n"
	.string "We expect your total cooperation!\p"
	.string "Fufufu…\n"
	.string "Just watch and learn what TEAM\l"
	.string "AQUA has planned!$"

SlateportCity_Text_1DE7F7: @ 81DE7F7
	.string "CAPT. STERN: What was that all about?\p"
	.string "It sounded like someone using\n"
	.string "a megaphone…\p"
	.string "Where did it come from?$"

SlateportCity_Text_1DE860: @ 81DE860
	.string "It's from the HARBOR!\p"
	.string "The submarine!\n"
	.string "They're trying to take it!$"

SlateportCity_Text_1DE8A0: @ 81DE8A0
	.string "{PLAYER}{KUN}!\n"
	.string "Please, come with me!$"

SlateportCity_Text_1DE8BC: @ 81DE8BC
	.string "BATTLE TENT SLATEPORT SITE\n"
	.string "“Find it! The ultimate POKéMON!”$"

SlateportCity_Text_1DE8F8: @ 81DE8F8
	.string "STERN'S SHIPYARD\p"
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"

SlateportCity_Text_1DE940: @ 81DE940
	.string "STERN'S SHIPYARD\p"
	.string "“The ferry S.S. TIDAL nears\n"
	.string "completion for serving the ports of\l"
	.string "SLATEPORT and LILYCOVE.”$"

SlateportCity_Text_1DE9AA: @ 81DE9AA
	.string "STERN'S SHIPYARD\p"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
	.string "ferry S.S. TIDAL is handled at the\l"
	.string "HARBOR.”$"

SlateportCity_Text_1DEA0B: @ 81DEA0B
	.string "POKéMON FAN CLUB\n"
	.string "“Calling all fans of POKéMON!”$"

SlateportCity_Text_1DEA3B: @ 81DEA3B
	.string "“The endless sea sustains\n"
	.string "all life.”\p"
	.string "OCEANIC MUSEUM$"

SlateportCity_Text_1DEA6F: @ 81DEA6F
	.string "SLATEPORT CITY\p"
	.string "“The port where people and POKéMON\n"
	.string "cross paths.”$"

SlateportCity_Text_1DEAAF: @ 81DEAAF
	.string "SLATEPORT MARKET\n"
	.string "“Unique items found nowhere else!”$"

SlateportCity_Text_1DEAE3: @ 81DEAE3
	.string "SLATEPORT HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in the SHIPYARD.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

SlateportCity_Text_1DEB5A: @ 81DEB5A
	.string "SLATEPORT HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

SlateportCity_Text_1DEBA0: @ 81DEBA0
	.string "NAME RATER'S HOUSE\n"
	.string "“POKéMON nicknames rated.”$"

SlateportCity_Text_1DEBCE: @ 81DEBCE
	.string "If a wild POKéMON gets hurt, it heals\n"
	.string "itself by chewing on BERRIES.\p"
	.string "Did you know that?\p"
	.string "Somebody saw that and got the idea\n"
	.string "of making medicine from BERRIES.\p"
	.string "Did you know that?\p"
	.string "To turn BERRIES into medicine,\n"
	.string "they must be crushed into powder.\p"
	.string "Did you know that?\p"
	.string "You seem to have an interest\n"
	.string "in BERRIES!\p"
	.string "I've got something good for someone\n"
	.string "like you.$"

SlateportCity_Text_1DED27: @ 81DED27
	.string "I recently had machines installed at\n"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
	.string "The BERRY CRUSH machines are at\n"
	.string "the DIRECT CORNER upstairs.\p"
	.string "Did you know?\p"
	.string "Could you make BERRY POWDER for\n"
	.string "me using those machines?\p"
	.string "I can make you all sorts of medicine\n"
	.string "if you bring me lots of BERRY POWDER.$"

SlateportCity_Text_1DEE40: @ 81DEE40
	.string "Have you brought me some\n"
	.string "BERRY POWDER?$"

SlateportCity_Text_1DEE67: @ 81DEE67
	.string "What would you like to exchange\n"
	.string "it with?$"

SlateportCity_Text_1DEE90: @ 81DEE90
	.string "Okay, you want to exchange your\n"
	.string "BERRY POWDER for one {STR_VAR_1}?$"

SlateportCity_Text_1DEEC9: @ 81DEEC9
	.string "Oh, dear. You don't have enough\n"
	.string "BERRY POWDER.$"

SlateportCity_Text_1DEEF7: @ 81DEEF7
	.string "This is fine BERRY POWDER.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more of your\n"
	.string "BERRY POWDER for something else?$"

SlateportCity_Text_1DEF79: @ 81DEF79
	.string "Okay! When you get some more\n"
	.string "BERRY POWDER, bring it to me, please!$"

SlateportCity_Text_1DEFBC: @ 81DEFBC
	.string "Come back if you'd like to trade your\n"
	.string "BERRY POWDER for some medicine.\p"
	.string "I'm always running a bazaar here.\p"
	.string "Did you know?$"

SlateportCity_Text_1DF032: @ 81DF032
	.string "SCOTT: Huh?\n"
	.string "I'm sure I met you somewhere before.\p"
	.string "Have I introduced myself to you?\n"
	.string "If not, my name's SCOTT.\p"
	.string "I just saw TEAM AQUA run away from\n"
	.string "here like they were stung.\p"
	.string "Let me guess--you drove them away?$"

SlateportCity_Text_1DF0FE: @ 81DF0FE
	.string "SCOTT: Hmm…\n"
	.string "Maybe, just maybe, this TRAINER…$"

SlateportCity_Text_1DF12B: @ 81DF12B
	.string "SCOTT: All right! I think you're going\n"
	.string "to become a good friend.\p"
	.string "So, let's register each other in our\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_1DF1A6: @ 81DF1A6
	.string "Registered this SCOTT person\n"
	.string "in the POKéNAV.$"

SlateportCity_Text_1DF1D3: @ 81DF1D3
	.string "SCOTT: What I'd like to do is tag along\n"
	.string "with you, but I do want to keep an eye\l"
	.string "on the talents of other people, too.\p"
	.string "So, I'll be off to roam other towns\n"
	.string "a bit more.\p"
	.string "Be seeing you, {PLAYER}{KUN}!$"

SlateportCity_Text_1DF28C: @ 81DF28C
	.string "SCOTT: Oh, hey!\n"
	.string "If it isn't {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
	.string "to take the BATTLE TENT challenge?\p"
	.string "Yeah! That's a good idea!\n"
	.string "That's a really great idea!\p"
	.string "After all, a tough TRAINER is\n"
	.string "the perfect fit for the BATTLE TENT!\p"
	.string "Give it your best effort!$"
