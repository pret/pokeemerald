LittlerootTown_BrendansHouse_2F_EventScript_2926FE:: @ 82926FE
LittlerootTown_MaysHouse_2F_EventScript_2926FE:: @ 82926FE
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

LittlerootTown_BrendansHouse_1F_EventScript_292704:: @ 8292704
LittlerootTown_MaysHouse_1F_EventScript_292704:: @ 8292704
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A1C, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_0x8005, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_29274D
	compare VAR_0x8005, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292758
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A46, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292763
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceUp
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_29274D:: @ 829274D
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292758:: @ 8292758
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_292763: @ 8292763
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292765:: @ 8292765
LittlerootTown_MaysHouse_1F_EventScript_292765:: @ 8292765
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7B24, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292AF0
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_292781:: @ 8292781
	lockall
	setvar VAR_0x8004, 0
	goto LittlerootTown_BrendansHouse_2F_EventScript_292799
	end

LittlerootTown_MaysHouse_2F_EventScript_29278D:: @ 829278D
	lockall
	setvar VAR_0x8004, 1
	goto LittlerootTown_MaysHouse_2F_EventScript_292799
	end

LittlerootTown_BrendansHouse_2F_EventScript_292799:: @ 8292799
LittlerootTown_MaysHouse_2F_EventScript_292799:: @ 8292799
	goto_if_set FLAG_SET_WALL_CLOCK, LittlerootTown_BrendansHouse_2F_EventScript_29283F
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F8668, MSGBOX_DEFAULT
	call LittlerootTown_BrendansHouse_2F_EventScript_292849
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_2927DF
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_29280F
	playse SE_KAIDAN
	removeobject VAR_0x8008
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_2927DF:: @ 82927DF
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292850
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F869A, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292857
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_29280F:: @ 829280F
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_29285B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F869A, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292862
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_29283F:: @ 829283F
	incrementgamestat 45
	fadescreen 1
	special Special_ViewWallClock
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_292849:: @ 8292849
	fadescreen 1
	special StartWallClock
	waitstate
	return

LittlerootTown_BrendansHouse_2F_Movement_292850: @ 8292850
	delay_8
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_8
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_292857: @ 8292857
	walk_right
	walk_up
	delay_8
	step_end

LittlerootTown_BrendansHouse_2F_Movement_29285B: @ 829285B
	delay_8
	walk_down
	walk_in_place_fastest_right
	delay_16
	delay_8
	walk_right
	step_end

LittlerootTown_BrendansHouse_2F_Movement_292862: @ 8292862
	walk_left
	walk_up
	delay_8
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292866:: @ 8292866
LittlerootTown_MaysHouse_1F_EventScript_292866:: @ 8292866
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_29286D:: @ 829286D
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceRight
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_29294B
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292AE0
	waitmovement 0
	playbgm MUS_INTER_V, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7BBC, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2929B7
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292AE6
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_29296C
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7BF1, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7C35, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2929BD
	waitmovement 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_292866
	end

LittlerootTown_MaysHouse_1F_EventScript_2928DC:: @ 82928DC
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	call LittlerootTown_MaysHouse_1F_EventScript_29294B
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_292AE8
	waitmovement 0
	playbgm MUS_INTER_V, 0
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7BBC, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, LittlerootTown_MaysHouse_1F_Movement_2929BA
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_292AEE
	waitmovement 0
	call LittlerootTown_MaysHouse_1F_EventScript_29296C
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7BF1, MSGBOX_DEFAULT
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7C35, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, LittlerootTown_MaysHouse_1F_Movement_2929C1
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_292866
	end

LittlerootTown_BrendansHouse_1F_EventScript_29294B:: @ 829294B
LittlerootTown_MaysHouse_1F_EventScript_29294B:: @ 829294B
	playse SE_PIN
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7B96, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_BrendansHouse_1F_EventScript_29296C:: @ 829296C
LittlerootTown_MaysHouse_1F_EventScript_29296C:: @ 829296C
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EC6, MSGBOX_DEFAULT
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

LittlerootTown_BrendansHouse_1F_Movement_292989: @ 8292989
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292991: @ 8292991
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292999: @ 8292999
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299B: @ 829299B
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299D: @ 829299D
	walk_in_place_fastest_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929A6: @ 82929A6
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	delay_16
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929AF: @ 82929AF
	walk_up
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B3: @ 82929B3
	walk_up
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B7: @ 82929B7
	walk_left
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_2929BA: @ 82929BA
	walk_right
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929BD: @ 82929BD
	walk_left
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_2929C1: @ 82929C1
	walk_right
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_2929C5:: @ 82929C5
LittlerootTown_MaysHouse_1F_EventScript_2929C5:: @ 82929C5
	lock
	faceplayer
	compare VAR_LITTLEROOT_HOUSES_STATE, 4
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	compare VAR_LITTLEROOT_HOUSES_STATE_2, 4
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	goto_if_set FLAG_HAS_MATCH_CALL, LittlerootTown_BrendansHouse_1F_EventScript_292A19
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_BrendansHouse_1F_EventScript_292A86
	compare VAR_TEMP_1, 1
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292A94
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292AB0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A1C, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A0F:: @ 8292A0F
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7DBE, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A19:: @ 8292A19
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, LittlerootTown_BrendansHouse_1F_EventScript_292A43
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7E0E, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7E89, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A43:: @ 8292A43
	goto_if_set FLAG_BADGE05_GET, LittlerootTown_BrendansHouse_1F_EventScript_292A51
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A86

LittlerootTown_BrendansHouse_1F_EventScript_292A51:: @ 8292A51
	goto_if_set FLAG_MOM_SAYS_GOODBYE, LittlerootTown_BrendansHouse_1F_EventScript_292A86
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D73, MSGBOX_DEFAULT
	giveitem_std ITEM_AMULET_COIN
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7DBE, MSGBOX_DEFAULT
	setflag FLAG_MOM_SAYS_GOODBYE
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A86:: @ 8292A86
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D08, MSGBOX_DEFAULT
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A9E
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A94:: @ 8292A94
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7CC3, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A9E:: @ 8292A9E
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat 16
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D5C, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292AB0:: @ 8292AB0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7CD8, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ABA:: @ 8292ABA
LittlerootTown_MaysHouse_1F_EventScript_292ABA:: @ 8292ABA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EA8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ACD:: @ 8292ACD
LittlerootTown_MaysHouse_1F_EventScript_292ACD:: @ 8292ACD
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EB3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_Movement_292AE0: @ 8292AE0
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292AE6: @ 8292AE6
	walk_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_292AE8: @ 8292AE8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_292AEE: @ 8292AEE
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292AF0: @ 8292AF0
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292AF2:: @ 8292AF2
LittlerootTown_MaysHouse_1F_EventScript_292AF2:: @ 8292AF2
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C76
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C86
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D08
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D13
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292C96
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CA1
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F800E, MSGBOX_DEFAULT
	giveitem_std ITEM_SS_TICKET
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F80FE, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CAC
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CC1
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F815B, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CD6
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292CEF
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D48
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D5D
	delay 20
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F81B9, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D72
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D7D
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F824B, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D1E
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D33
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F826F, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D88
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_292D9D
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8351, MSGBOX_DEFAULT
	multichoice 22, 8, 108, 1
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F83A1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 4
	releaseall
	end

@ Never called.
LittlerootTown_BrendansHouse_1F_EventScript_292C72:: @ 8292C72
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C76:: @ 8292C76
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C86:: @ 8292C86
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C96:: @ 8292C96
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CA1:: @ 8292CA1
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB5
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CAC:: @ 8292CAC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292989
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CC1:: @ 8292CC1
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292991
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBA
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CD6:: @ 8292CD6
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBC
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CEF:: @ 8292CEF
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DC1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D08:: @ 8292D08
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DC6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D13:: @ 8292D13
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DD1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D1E:: @ 8292D1E
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DD7
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D33:: @ 8292D33
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_292DDE
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D48:: @ 8292D48
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292999
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D5D:: @ 8292D5D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D72:: @ 8292D72
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299D
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D7D:: @ 8292D7D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929A6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D88:: @ 8292D88
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929AF
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D9D:: @ 8292D9D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929B3
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_292DB2: @ 8292DB2
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB5: @ 8292DB5
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB8: @ 8292DB8
	face_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBA: @ 8292DBA
	face_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBC: @ 8292DBC
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC1: @ 8292DC1
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC6: @ 8292DC6
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DCC: @ 8292DCC
	delay_8
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD1: @ 8292DD1
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD7: @ 8292DD7
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DDE: @ 8292DDE
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end
