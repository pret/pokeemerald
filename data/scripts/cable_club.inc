PokemonCenter_2F_OnTransition: @ 8276ACF
	call OldaleTown_PokemonCenter_2F_EventScript_OnTransitionCheckMysteryGift
	end

OldaleTown_PokemonCenter_2F_EventScript_OnTransitionCheckMysteryGift:: @ 8276AD5
	specialvar VAR_RESULT, sub_813B514
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276AFB
	specialvar VAR_RESULT, ValidateReceivedWonderCard
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276AFF
	goto OldaleTown_PokemonCenter_2F_EventScript_276AFB
	end

OldaleTown_PokemonCenter_2F_EventScript_276AFB:: @ 8276AFB
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

OldaleTown_PokemonCenter_2F_EventScript_276AFF:: @ 8276AFF
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
	return

BattleFrontier_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
DewfordTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
EverGrandeCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
EverGrandeCity_PokemonLeague_2F_EventScript_276B03:: @ 8276B03
FallarborTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
FortreeCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
LavaridgeTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
LilycoveCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
MauvilleCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
MossdeepCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
OldaleTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
PacifidlogTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
PetalburgCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
RustboroCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
SlateportCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
SootopolisCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
VerdanturfTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
	specialvar VAR_RESULT, sub_813B514
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276B23
	goto OldaleTown_PokemonCenter_2F_EventScript_276B19
	end

OldaleTown_PokemonCenter_2F_EventScript_276B19:: @ 8276B19
	gotoram

OldaleTown_PokemonCenter_2F_EventScript_276B1A:: @ 8276B1A
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_2F_EventScript_276B23:: @ 8276B23
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276B19
	goto_if_set FLAG_SYS_HAS_EON_TICKET, OldaleTown_PokemonCenter_2F_EventScript_276B19
	msgbox gUnknown_08273594, MSGBOX_DEFAULT
	giveitem_std ITEM_EON_TICKET
	setflag FLAG_SYS_HAS_EON_TICKET
	setvar VAR_ALWAYS_ZERO_0x403F, 0
	msgbox gUnknown_082735F2, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_276B62:: @ 8276B62
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
DewfordTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
EverGrandeCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
EverGrandeCity_PokemonLeague_2F_MapScript2_276B6C: @ 8276B6C
FallarborTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
FortreeCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
LavaridgeTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
LilycoveCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
MauvilleCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
MossdeepCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
OldaleTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
PacifidlogTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
PetalburgCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
RustboroCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
SlateportCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
SootopolisCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
VerdanturfTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
	map_script_2 VAR_CABLE_CLUB_STATE, 1, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 2, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 5, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 3, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 4, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 6, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 7, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_CABLE_CLUB_STATE, 8, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_276BAE:: @ 8276BAE
OldaleTown_PokemonCenter_2F_EventScript_276BAE:: @ 8276BAE
	compare VAR_0x8007, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276BBD
	turnobject VAR_0x8007, DIR_WEST

OldaleTown_PokemonCenter_2F_EventScript_276BBD:: @ 8276BBD
	end

BattleFrontier_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
DewfordTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
EverGrandeCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
EverGrandeCity_PokemonLeague_2F_MapScript1_276BBE: @ 8276BBE
FallarborTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
FortreeCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
LavaridgeTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
LilycoveCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
MauvilleCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
MossdeepCity_GameCorner_1F_MapScript1_276BBE: @ 8276BBE
MossdeepCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
OldaleTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
PacifidlogTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
PetalburgCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
RustboroCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
SlateportCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
SootopolisCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
VerdanturfTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
	compare VAR_CABLE_CLUB_STATE, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare VAR_CABLE_CLUB_STATE, 2
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare VAR_CABLE_CLUB_STATE, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare VAR_CABLE_CLUB_STATE, 3
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C1D
	compare VAR_CABLE_CLUB_STATE, 4
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C23
	compare VAR_CABLE_CLUB_STATE, 6
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C29
	compare VAR_CABLE_CLUB_STATE, 7
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C2F
	compare VAR_CABLE_CLUB_STATE, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276C35
	end

OldaleTown_PokemonCenter_2F_EventScript_276C17:: @ 8276C17
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C1D:: @ 8276C1D
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C23:: @ 8276C23
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C29:: @ 8276C29
	call OldaleTown_PokemonCenter_2F_EventScript_277BBE
	end

OldaleTown_PokemonCenter_2F_EventScript_276C2F:: @ 8276C2F
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C35:: @ 8276C35
	call OldaleTown_PokemonCenter_2F_EventScript_277C0A
	end

BattleFrontier_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
DewfordTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
EverGrandeCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
EverGrandeCity_PokemonLeague_2F_MapScript2_276C3B: @ 8276C3B
FallarborTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
FortreeCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
LavaridgeTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
LilycoveCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
MauvilleCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
MossdeepCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
OldaleTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
PacifidlogTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
PetalburgCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
RustboroCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
SlateportCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
SootopolisCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
VerdanturfTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
	map_script_2 VAR_CABLE_CLUB_TUTORIAL_STATE, 1, OldaleTown_PokemonCenter_2F_EventScript_276DE0
	map_script_2 VAR_CABLE_CLUB_STATE, 1, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_CABLE_CLUB_STATE, 2, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_CABLE_CLUB_STATE, 5, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_CABLE_CLUB_STATE, 3, OldaleTown_PokemonCenter_2F_EventScript_276CE7
	map_script_2 VAR_CABLE_CLUB_STATE, 4, OldaleTown_PokemonCenter_2F_EventScript_276D2C
	map_script_2 VAR_CABLE_CLUB_STATE, 6, OldaleTown_PokemonCenter_2F_EventScript_276D6C
	map_script_2 VAR_CABLE_CLUB_STATE, 7, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_CABLE_CLUB_STATE, 8, OldaleTown_PokemonCenter_2F_EventScript_276C9D
	.2byte 0

OldaleTown_PokemonCenter_2F_EventScript_276C85:: @ 8276C85
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CB5
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_276C9D:: @ 8276C9D
OldaleTown_PokemonCenter_2F_EventScript_276C9D:: @ 8276C9D
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CB5
	call OldaleTown_PokemonCenter_2F_EventScript_277C1D
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276CB5:: @ 8276CB5
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276CE7:: @ 8276CE7
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CFF
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276CFF:: @ 8276CFF
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735E
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	call OldaleTown_PokemonCenter_2F_EventScript_276DAE
	return

OldaleTown_PokemonCenter_2F_EventScript_276D2C:: @ 8276D2C
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276D44
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276D44:: @ 8276D44
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	compare VAR_0x8007, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276D6B
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0

OldaleTown_PokemonCenter_2F_EventScript_276D6B:: @ 8276D6B
	return

OldaleTown_PokemonCenter_2F_EventScript_276D6C:: @ 8276D6C
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276D84
	call OldaleTown_PokemonCenter_2F_EventScript_277BD1
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276D84:: @ 8276D84
	setvar VAR_CABLE_CLUB_STATE, 0
	compare VAR_0x8007, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735E
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	call OldaleTown_PokemonCenter_2F_EventScript_276DAE
	return

OldaleTown_PokemonCenter_2F_EventScript_276DAE:: @ 8276DAE
	message OldaleTown_PokemonCenter_2F_Text_278521
	waitmessage
	playse SE_PIN
	delay 60
	message OldaleTown_PokemonCenter_2F_Text_27854C
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276DD5:: @ 8276DD5
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276DE0:: @ 8276DE0
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox OldaleTown_PokemonCenter_2F_Text_27964A, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_276E10
	waitmovement 0
	delay 30
	msgbox OldaleTown_PokemonCenter_2F_Text_279718, MSGBOX_DEFAULT
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	releaseall
	end

OldaleTown_PokemonCenter_2F_Movement_276E10: @ 8276E10
	walk_up
	walk_up
	step_end

OldaleTown_PokemonCenter_2F_EventScript_276E13:: @ 8276E13
	message OldaleTown_PokemonCenter_2F_Text_277EA4
	waitmessage
	delay 28
	goto OldaleTown_PokemonCenter_2F_EventScript_276E30
	end

OldaleTown_PokemonCenter_2F_EventScript_276E22:: @ 8276E22
	msgbox OldaleTown_PokemonCenter_2F_Text_277EF1, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_276E30
	end

OldaleTown_PokemonCenter_2F_EventScript_276E30:: @ 8276E30
	setvar VAR_0x8004, 0
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, OldaleTown_PokemonCenter_2F_EventScript_276E75
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2770B2
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276EB7
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276E75:: @ 8276E75
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2770B2
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276EB7
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2771DB
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276EB7:: @ 8276EB7
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276EC2:: @ 8276EC2
	message OldaleTown_PokemonCenter_2F_Text_2790BE
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_276F23
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276F2E
	case 2, OldaleTown_PokemonCenter_2F_EventScript_276F55
	case 3, OldaleTown_PokemonCenter_2F_EventScript_276F15
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276F15:: @ 8276F15
	msgbox OldaleTown_PokemonCenter_2F_Text_279142, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276F23:: @ 8276F23
	setvar VAR_0x8004, 1
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F2E:: @ 8276F2E
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne OldaleTown_PokemonCenter_2F_EventScript_276F47
	setvar VAR_0x8004, 2
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F47:: @ 8276F47
	msgbox OldaleTown_PokemonCenter_2F_Text_277FEE, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276F55:: @ 8276F55
	setvar VAR_0x8004, 5
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F60:: @ 8276F60
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gText_PleaseWaitForLink
	waitmessage
	special sub_80B2DA4
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276FBD
	compare VAR_RESULT, 2
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare VAR_RESULT, 3
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare VAR_RESULT, 4
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277046
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare VAR_RESULT, 6
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	end

OldaleTown_PokemonCenter_2F_EventScript_276FBD:: @ 8276FBD
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	compare VAR_0x8004, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277036
	special SetCableClubWarp
	warp MAP_SINGLE_BATTLE_COLOSSEUM, 255, 6, 8
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_27702B:: @ 827702B
	applymovement EVENT_OBJ_ID_PLAYER, Movement_277352
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277036:: @ 8277036
	special SetCableClubWarp
	warp MAP_DOUBLE_BATTLE_COLOSSEUM, 255, 5, 8
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277046:: @ 8277046
	switch VAR_0x8004
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277094
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277083
	case 5, OldaleTown_PokemonCenter_2F_EventScript_277072
	goto OldaleTown_PokemonCenter_2F_EventScript_27730E
	end

OldaleTown_PokemonCenter_2F_EventScript_277072:: @ 8277072
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_27833D, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_277083:: @ 8277083
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278307, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_277094:: @ 8277094
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_2782D1, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_2770A5:: @ 82770A5
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278372, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2770B2:: @ 82770B2
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call OldaleTown_PokemonCenter_2F_EventScript_277199
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gText_PleaseWaitForLink
	waitmessage
	special sub_80B2E4C
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27713A
	compare VAR_RESULT, 2
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare VAR_RESULT, 3
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare VAR_RESULT, 4
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27730E
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare VAR_RESULT, 6
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	compare VAR_RESULT, 7
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772AB
	compare VAR_RESULT, 9
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772B8
	end

OldaleTown_PokemonCenter_2F_EventScript_27713A:: @ 827713A
	setvar VAR_0x8004, 3
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 255, 5, 8
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277199:: @ 8277199
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 2
	goto_if_lt OldaleTown_PokemonCenter_2F_EventScript_2771BF
	specialvar VAR_RESULT, sub_80F9370
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2771CD
	setvar VAR_RESULT, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_2771BF:: @ 82771BF
	msgbox OldaleTown_PokemonCenter_2F_Text_278027, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_2771CD:: @ 82771CD
	msgbox OldaleTown_PokemonCenter_2F_Text_278061, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_2771DB:: @ 82771DB
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gText_PleaseWaitForLink
	waitmessage
	special sub_80B2E74
	waitstate
	special sub_80B2EA8
	waitstate
	compare VAR_RESULT, 12
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277328
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27724C
	compare VAR_RESULT, 2
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare VAR_RESULT, 3
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare VAR_RESULT, 4
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27730E
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare VAR_RESULT, 6
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	end

OldaleTown_PokemonCenter_2F_EventScript_27724C:: @ 827724C
	setvar VAR_0x8004, 4
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_RECORD_CORNER, 255, 8, 9
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_2772AB:: @ 82772AB
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278565, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772B8:: @ 82772B8
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_2785C9, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_2772C5:: @ 82772C5
OldaleTown_PokemonCenter_2F_EventScript_2772C5:: @ 82772C5
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_27821C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_2772D2:: @ 82772D2
OldaleTown_PokemonCenter_2F_EventScript_2772D2:: @ 82772D2
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_2781C7, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772DF:: @ 82772DF
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278255, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772EC:: @ 82772EC
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278291, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_2772F9:: @ 82772F9
	special CloseLink
	msgbox MossdeepCity_GameCorner_1F_Text_278D51, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_277306:: @ 8277306
	special SetCableClubWarp
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_27730E:: @ 827730E
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_2782A8, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_27731B:: @ 827731B
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_2785E9, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_277328:: @ 8277328
	special CloseLink
	msgbox OldaleTown_PokemonCenter_2F_Text_278651, MSGBOX_DEFAULT
	release
	end

CableClub_EventScript_WirelessClubAdjustements:: @ 8277335
	msgbox gText_SorryWirelessClubAdjustments, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_27733F:: @ 827733F
	msgbox gText_UndergoingAdjustments, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_2F_Movement_277349: @ 8277349
	face_down
	step_end

OldaleTown_PokemonCenter_2F_Movement_27734B: @ 827734B
	face_right
	step_end

MossdeepCity_GameCorner_1F_Movement_27734D: @ 827734D
OldaleTown_PokemonCenter_2F_Movement_27734D: @ 827734D
	face_left
	step_end

OldaleTown_PokemonCenter_2F_Movement_27734F: @ 827734F
	walk_down
	walk_down
	step_end

Movement_277352: @ 8277352
	walk_right
	walk_up
	walk_up
	step_end

OldaleTown_PokemonCenter_2F_Movement_277356: @ 8277356
	walk_left
	walk_up
	walk_up
	step_end

OldaleTown_PokemonCenter_2F_Movement_27735A: @ 827735A
	walk_up
	step_end

OldaleTown_PokemonCenter_2F_Movement_27735C: @ 827735C
	face_left
	step_end

OldaleTown_PokemonCenter_2F_Movement_27735E: @ 827735E
	face_right
	step_end

MossdeepCity_GameCorner_1F_Movement_277360: @ 8277360
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

EventScript_CableBoxResults:: @ 8277365
	lockall
	setvar VAR_0x8004, 0
	special ShowLinkBattleRecords
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

EventScript_SingleBattleColosseum_PlayerSpot0:: @ 8277374
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_SingleBattleColosseum_PlayerSpot1:: @ 827737E
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot0:: @ 8277388
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 0
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot1:: @ 82773A3
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 1
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot2:: @ 82773BE
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 2
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_PlayerSpot3:: @ 82773D9
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoubleBattleColosseum_CancelSpotTrigger
	setvar VAR_0x8005, 3
	special ColosseumPlayerSpotTriggered
	waitstate
	end

EventScript_DoubleBattleColosseum_CancelSpotTrigger:: @ 82773F4
	end

EventScript_TradeCenter_Chair0:: @ 82773F5
	setvar VAR_0x8005, 0
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_TradeCenter_Chair1:: @ 82773FF
	setvar VAR_0x8005, 1
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair2:: @ 8277409
	setvar VAR_0x8005, 2
	special PlayerEnteredTradeSeat
	waitstate
	end

/* Never used */
EventScript_TradeCenter_Chair3:: @ 8277413
	setvar VAR_0x8005, 3
	special PlayerEnteredTradeSeat
	waitstate
	end

EventScript_RecordCenter_Spot0:: @ 827741D
	setvar VAR_0x8005, 0
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot1:: @ 8277432
	setvar VAR_0x8005, 1
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot2:: @ 8277447
	setvar VAR_0x8005, 2
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

EventScript_RecordCenter_Spot3:: @ 827745C
	setvar VAR_0x8005, 3
	special RecordMixingPlayerSpotTriggered
	waitstate
	compare VAR_TEMP_1, 0
	goto_if_ne RecordCorner_EventScript_277471
	end

RecordCorner_EventScript_277471:: @ 8277471
	bufferitemname 1, VAR_TEMP_1
	message RecordCorner_Text_27863C
	waitmessage
	waitbuttonpress
	releaseall
	end

gEventScript_TradeRoom_ReadTrainerCard_NoColor:: @ 827747E
	msgbox Text_278452, MSGBOX_DEFAULT
	fadescreen 1
	special sp02A_crash_sound
	waitstate
	end

gEventScript_TradeRoom_ReadTrainerCard_Normal:: @ 827748D
	msgbox Text_27847B, MSGBOX_DEFAULT
	fadescreen 1
	special sp02A_crash_sound
	waitstate
	end

gEventScript_TradeRoom_TooBusyToNotice:: @ 827749C
	msgbox Text_27842E, MSGBOX_DEFAULT
	closemessage
	end

SingleBattleColosseum_EventScript_2774A6:: @ 82774A6
	special sub_8098574
	msgbox SingleBattleColosseum_Text_2784B4, MSGBOX_DEFAULT
	special sub_809859C
	closemessage
	end

TradeCenter_EventScript_2774B6:: @ 82774B6
	special sub_8098574
	msgbox TradeCenter_Text_2784E2, MSGBOX_DEFAULT
	special sub_809859C
	closemessage
	end

RecordCorner_EventScript_2774C6:: @ 82774C6
	compare VAR_TEMP_0, 0
	goto_if_ne RecordCorner_EventScript_2774E0
	special sub_8098574
	message RecordCorner_Text_27861C
	waitmessage
	waitbuttonpress
	special sub_809859C
	closemessage
	end

RecordCorner_EventScript_2774E0:: @ 82774E0
	special sub_8098574
	message RecordCorner_Text_27850E
	waitmessage
	waitbuttonpress
	special sub_809859C
	closemessage
	end

EventScript_ConfirmLeaveTradeRoom:: @ 82774EF
	msgbox Text_TerminateLinkConfirmation, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_TerminateLink
	erasebox 0, 0, 29, 19
	releaseall
	end

EventScript_TerminateLink:: @ 8277509
	messageautoscroll Text_TerminateLinkPleaseWait
	waitmessage
	special ExitLinkRoom
	end

EventScript_DoLinkRoomExit:: @ 8277513
	special CleanupLinkRoomState
	special sub_80AF9F8
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_27751B:: @ 827751B
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 8
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27731B
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277668
	message OldaleTown_PokemonCenter_2F_Text_27940D
	waitmessage
	goto OldaleTown_PokemonCenter_2F_EventScript_27755C
	end

OldaleTown_PokemonCenter_2F_EventScript_27755C:: @ 827755C
	multichoice 17, 6, MULTI_YESNOINFO, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27759F
	case 1, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277593
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277593:: @ 8277593
	message OldaleTown_PokemonCenter_2F_Text_2794B8
	waitmessage
	goto OldaleTown_PokemonCenter_2F_EventScript_27755C
	end

OldaleTown_PokemonCenter_2F_EventScript_27759F:: @ 827759F
	call OldaleTown_PokemonCenter_2F_EventScript_277626
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	msgbox OldaleTown_PokemonCenter_2F_Text_27961C, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, 6
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call OldaleTown_PokemonCenter_2F_EventScript_277BBE
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 5, 1
	waitdooranim
	special sub_8018090
	special SetCableClubWarp
	warpteleport2 MAP_UNION_ROOM, 255, 7, 11
	waitstate
	special UnionRoomSpecial
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277626:: @ 8277626
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 2
	goto_if_lt OldaleTown_PokemonCenter_2F_EventScript_27764C
	specialvar VAR_RESULT, sub_80F9370
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27765A
	setvar VAR_RESULT, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_27764C:: @ 827764C
	msgbox OldaleTown_PokemonCenter_2F_Text_27893E, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

OldaleTown_PokemonCenter_2F_EventScript_27765A:: @ 827765A
	msgbox OldaleTown_PokemonCenter_2F_Text_27897B, MSGBOX_DEFAULT
	goto EventScript_CableClub_SetVarResult0
	end

OldaleTown_PokemonCenter_2F_EventScript_277668:: @ 8277668
	msgbox OldaleTown_PokemonCenter_2F_Text_2789B5, MSGBOX_DEFAULT
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277672:: @ 8277672
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox OldaleTown_PokemonCenter_2F_Text_279937, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27769A
	msgbox OldaleTown_PokemonCenter_2F_Text_2799AA, MSGBOX_DEFAULT
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_27769A:: @ 827769A
	msgbox OldaleTown_PokemonCenter_2F_Text_279C91, MSGBOX_DEFAULT
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_2776A4:: @ 82776A4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 9
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27731B
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_276E13
	message OldaleTown_PokemonCenter_2F_Text_279013
	waitmessage
	delay 28
	goto OldaleTown_PokemonCenter_2F_EventScript_2776E3
	end

OldaleTown_PokemonCenter_2F_EventScript_2776E3:: @ 82776E3
	checkitem ITEM_POWDER_JAR, 1
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_27778B
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, OldaleTown_PokemonCenter_2F_EventScript_27773E
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778F7
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27773E:: @ 827773E
	multichoice 0, 0, MULTI_WIRELESS_ALL_SERVICES, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778D9
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2778F7
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27778B:: @ 827778B
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, OldaleTown_PokemonCenter_2F_EventScript_2777CB
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_2777CB:: @ 82777CB
	multichoice 0, 0, MULTI_WIRELESS_NO_BERRY, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778D9
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27780D:: @ 827780D
	msgbox OldaleTown_PokemonCenter_2F_Text_27909D, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call OldaleTown_PokemonCenter_2F_EventScript_277199
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	setvar VAR_0x8004, 3
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_27783B:: @ 827783B
	message OldaleTown_PokemonCenter_2F_Text_2790BE
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27788E
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277899
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778C0
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2778CB
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27788E:: @ 827788E
	setvar VAR_0x8004, 0
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_277899:: @ 8277899
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne OldaleTown_PokemonCenter_2F_EventScript_2778B2
	setvar VAR_0x8004, 1
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778B2:: @ 82778B2
	msgbox OldaleTown_PokemonCenter_2F_Text_277FEE, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_27783B
	end

OldaleTown_PokemonCenter_2F_EventScript_2778C0:: @ 82778C0
	setvar VAR_0x8004, 2
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778CB:: @ 82778CB
	msgbox OldaleTown_PokemonCenter_2F_Text_279142, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_27783B
	end

OldaleTown_PokemonCenter_2F_EventScript_2778D9:: @ 82778D9
	msgbox OldaleTown_PokemonCenter_2F_Text_2790E8, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	setvar VAR_0x8004, 12
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778F7:: @ 82778F7
	msgbox OldaleTown_PokemonCenter_2F_Text_279114, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	special HasAtLeastOneBerry
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277923
	setvar VAR_0x8004, 5
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_277923:: @ 8277923
	msgbox OldaleTown_PokemonCenter_2F_Text_2788FC, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_2F_EventScript_2776E3
	end

OldaleTown_PokemonCenter_2F_EventScript_277931:: @ 8277931
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	switch VAR_0x8004
	case 3, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277A16
	case 5, OldaleTown_PokemonCenter_2F_EventScript_277AA3
	case 12, OldaleTown_PokemonCenter_2F_EventScript_277AA3
	end

OldaleTown_PokemonCenter_2F_EventScript_277989:: @ 8277989
	message OldaleTown_PokemonCenter_2F_Text_2792CD
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2779EE
	case 1, OldaleTown_PokemonCenter_2F_EventScript_2779C6
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_2779C6:: @ 82779C6
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277989
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2779C6
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_2779EE:: @ 82779EE
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277989
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_2779EE
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277A16:: @ 8277A16
	message OldaleTown_PokemonCenter_2F_Text_279334
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277A7B
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277A53
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277A53:: @ 8277A53
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277A16
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277A53
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277A7B:: @ 8277A7B
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277A16
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277A7B
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277AA3:: @ 8277AA3
	message OldaleTown_PokemonCenter_2F_Text_2793A3
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277B08
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277AE0
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case MULTI_B_PRESSED, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277AE0:: @ 8277AE0
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277AA3
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277AE0
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277B08:: @ 8277B08
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare VAR_RESULT, 5
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277AA3
	compare VAR_RESULT, 8
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_277B08
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_277B30:: @ 8277B30
MossdeepCity_GameCorner_1F_EventScript_277B30:: @ 8277B30
OldaleTown_PokemonCenter_2F_EventScript_277B30:: @ 8277B30
	special BerryBlenderLinkBecomeLeader
	waitstate
	return

BattleFrontier_BattleTowerLobby_EventScript_277B35:: @ 8277B35
MossdeepCity_GameCorner_1F_EventScript_277B35:: @ 8277B35
OldaleTown_PokemonCenter_2F_EventScript_277B35:: @ 8277B35
	special BerryBlenderLinkJoinGroup
	waitstate
	return

OldaleTown_PokemonCenter_2F_EventScript_277B3A:: @ 8277B3A
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_2781A5
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

EventScript_WirelessBoxResults:: @ 8277B8A
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_2F_EventScript_27733F
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 0
	goto_if_eq EventScript_277BB4
	fadescreen 1
	special sub_801A42C
	waitstate
	msgbox OldaleTown_PokemonCenter_2F_Text_27874F, MSGBOX_DEFAULT
	releaseall
	end

EventScript_277BB4:: @ 8277BB4
	msgbox OldaleTown_PokemonCenter_2F_Text_27871F, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_277BBE:: @ 8277BBE
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277BD1:: @ 8277BD1
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_277BE4:: @ 8277BE4
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277BF7:: @ 8277BF7
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

MossdeepCity_GameCorner_1F_EventScript_277C0A:: @ 8277C0A
OldaleTown_PokemonCenter_2F_EventScript_277C0A:: @ 8277C0A
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterOpen_Top, 0
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterOpen_Bottom, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277C1D:: @ 8277C1D
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterClosed_Top, 1
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterClosed_Bottom, 1
	return

BattleFrontier_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
DewfordTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
EverGrandeCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
EverGrandeCity_PokemonLeague_1F_MapScript1_277C30: @ 8277C30
FallarborTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
FortreeCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
LavaridgeTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
LilycoveCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
MauvilleCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
MossdeepCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
OldaleTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
PacifidlogTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
PetalburgCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
RustboroCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
SlateportCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
SootopolisCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
VerdanturfTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
	special sub_8016934
	end

MossdeepCity_GameCorner_1F_EventScript_277C34:: @ 8277C34
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_278A7D
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277C73
	case 1, MossdeepCity_GameCorner_1F_EventScript_277C7D
	case 2, MossdeepCity_GameCorner_1F_EventScript_277C87
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_277C87
	end

MossdeepCity_GameCorner_1F_EventScript_277C73:: @ 8277C73
	msgbox MossdeepCity_GameCorner_1F_Text_278ACB, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C7D:: @ 8277C7D
	msgbox MossdeepCity_GameCorner_1F_Text_278BF1, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C87:: @ 8277C87
	msgbox MossdeepCity_GameCorner_1F_Text_278CAC, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C91:: @ 8277C91
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_278CEB
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277E48
	delay 60
	message MossdeepCity_GameCorner_1F_Text_278DAD
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277CE9
	case 1, MossdeepCity_GameCorner_1F_EventScript_277D35
	case 2, MossdeepCity_GameCorner_1F_EventScript_2772F9
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277CE9:: @ 8277CE9
	setvar VAR_0x8005, 0
	special sub_802C920
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278DD9, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8005, 0
	special sub_81B8958
	waitstate
	compare VAR_0x8004, 6
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_2772F9
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	setvar VAR_0x8004, 4
	goto MossdeepCity_GameCorner_1F_EventScript_277D81
	end

MossdeepCity_GameCorner_1F_EventScript_277D35:: @ 8277D35
	setvar VAR_0x8005, 1
	special sub_8027A5C
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278DD9, MSGBOX_DEFAULT
	fadescreen 1
	setvar VAR_0x8005, 1
	special sub_81B8958
	waitstate
	compare VAR_0x8004, 6
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_2772F9
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	setvar VAR_0x8004, 6
	goto MossdeepCity_GameCorner_1F_EventScript_277D81
	end

MossdeepCity_GameCorner_1F_EventScript_277D81:: @ 8277D81
	message MossdeepCity_GameCorner_1F_Text_2793A3
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277DE6
	case 1, MossdeepCity_GameCorner_1F_EventScript_277DBE
	case 2, MossdeepCity_GameCorner_1F_EventScript_2772F9
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277DBE:: @ 8277DBE
	call MossdeepCity_GameCorner_1F_EventScript_277B30
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277E0E
	compare VAR_RESULT, 5
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277D81
	compare VAR_RESULT, 8
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277DBE
	release
	return

MossdeepCity_GameCorner_1F_EventScript_277DE6:: @ 8277DE6
	call MossdeepCity_GameCorner_1F_EventScript_277B35
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277E0E
	compare VAR_RESULT, 5
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277D81
	compare VAR_RESULT, 8
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_277DE6
	release
	return

MossdeepCity_GameCorner_1F_EventScript_277E0E:: @ 8277E0E
	messageautoscroll MossdeepCity_GameCorner_1F_Text_278E00
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call MossdeepCity_GameCorner_1F_EventScript_277C0A
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, MossdeepCity_GameCorner_1F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_GameCorner_1F_Movement_277360
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	release
	waitstate
	end

MossdeepCity_GameCorner_1F_EventScript_277E48:: @ 8277E48
	delay 60
	msgbox MossdeepCity_GameCorner_1F_Text_278D68, MSGBOX_DEFAULT
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277E55:: @ 8277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278E60, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	compare VAR_0x8005, 0
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_277E84
	compare VAR_0x8005, 1
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_277E8D
	goto MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277E84:: @ 8277E84
	msgbox MossdeepCity_GameCorner_1F_Text_278EDC, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_277E8D:: @ 8277E8D
	msgbox MossdeepCity_GameCorner_1F_Text_278FA4, MSGBOX_DEFAULT
	return

MossdeepCity_GameCorner_1F_EventScript_277E96:: @ 8277E96
	lockall
	special sub_802E3C4
	waitstate
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_277E9D:: @ 8277E9D
	lockall
	special sub_8027AAC
	waitstate
	releaseall
	end
OldaleTown_PokemonCenter_2F_Text_277EA4: @ 8277EA4
	.string "Welcome to the POKéMON CABLE\n"
	.string "CLUB.\p"
	.string "Which of our services do you wish\n"
	.string "to use?$"

OldaleTown_PokemonCenter_2F_Text_277EF1: @ 8277EF1
	.string "Which of our services do you wish\n"
	.string "to use?$"

CableClub_Text_TradeUsingLinkCable:: @ 8277F1B
	.string "Trade POKéMON with another player\n"
	.string "using a GBA Game Link cable.$"

CableClub_Text_BattleUsingLinkCable:: @ 8277F5A
	.string "You may battle another TRAINER\n"
	.string "using a GBA Game Link cable.$"

CableClub_Text_RecordCornerUsingLinkCable:: @ 8277F96
	.string "You can use the RECORD CORNER with\n"
	.string "others using a GBA Game Link cable.$"

OldaleTown_PokemonCenter_2F_Text_277FDD: @ 8277FDD
	.string "Close this menu.$"

OldaleTown_PokemonCenter_2F_Text_277FEE: @ 8277FEE
	.string "For a DOUBLE BATTLE, you must\n"
	.string "have at least two POKéMON.$"

OldaleTown_PokemonCenter_2F_Text_278027: @ 8278027
	.string "For trading, you must have at\n"
	.string "least two POKéMON with you.$"

OldaleTown_PokemonCenter_2F_Text_278061: @ 8278061
	.string "A POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY can't be traded.$"

gText_PleaseWaitForLink:: @ 8278091
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

gText_ConfirmLinkWhenPlayersReady:: @ 82780B3
	.string "When all players are ready…\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_ConfirmStartLinkWithXPlayers:: @ 82780F2
	.string "Start link with {STR_VAR_1} players.\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_AwaitingLinkup:: @ 8278131
	.string "Awaiting linkup…\n"
	.string "… … B Button: Cancel$"

OldaleTown_PokemonCenter_2F_Text_278157:: @ 8278157
	.string "Your progress must be saved before\n"
	.string "linking. Is it okay to save?$"

OldaleTown_PokemonCenter_2F_Text_278197: @ 8278197
	.string "Please enter.$"

OldaleTown_PokemonCenter_2F_Text_2781A5: @ 82781A5
	.string "I'll direct you to your room now.$"

LilycoveCity_ContestLobby_Text_2781C7: @ 82781C7
OldaleTown_PokemonCenter_2F_Text_2781C7: @ 82781C7
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"

LilycoveCity_ContestLobby_Text_27821C: @ 827821C
OldaleTown_PokemonCenter_2F_Text_27821C: @ 827821C
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"

BattleFrontier_BattleTowerLobby_Text_278255: @ 8278255
LilycoveCity_ContestLobby_Text_278255: @ 8278255
OldaleTown_PokemonCenter_2F_Text_278255: @ 8278255
	.string "The link partners appear to have\n"
	.string "made different selections.$"

OldaleTown_PokemonCenter_2F_Text_278291: @ 8278291
	.string "Please do visit again.$"

BattleFrontier_BattleTowerLobby_Text_2782A8: @ 82782A8
OldaleTown_PokemonCenter_2F_Text_2782A8: @ 82782A8
	.string "The number of participants is\n"
	.string "incorrect.$"

OldaleTown_PokemonCenter_2F_Text_2782D1: @ 82782D1
	.string "The SINGLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

OldaleTown_PokemonCenter_2F_Text_278307: @ 8278307
	.string "The DOUBLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"

OldaleTown_PokemonCenter_2F_Text_27833D: @ 827833D
	.string "There must be four players to play\n"
	.string "this Battle Mode.$"

OldaleTown_PokemonCenter_2F_Text_278372: @ 8278372
	.string "Please confirm the number of\n"
	.string "players and start again.$"

Text_TerminateLinkConfirmation: @ 82783A8
	.string "The link will be terminated if you\n"
	.string "leave the room. Is that okay?$"

Text_TerminateLinkPleaseWait: @ 82783E9
	.string "Terminating link…\n"
	.string "You will be escorted out of\l"
	.string "the room. Please wait.$"

Text_27842E: @ 827842E
	.string "This TRAINER is too busy to\n"
	.string "notice…$"

Text_278452: @ 8278452
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!$"

Text_27847B: @ 827847B
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"

SingleBattleColosseum_Text_2784B4: @ 82784B4
	.string "Please take your place and start\n"
	.string "your battle.$"

TradeCenter_Text_2784E2: @ 82784E2
	.string "Please take your seat and start\n"
	.string "your trade.$"

RecordCorner_Text_27850E: @ 827850E
	.string "Thanks for coming.$"

OldaleTown_PokemonCenter_2F_Text_278521: @ 8278521
	.string "The TRAINER CARD data will\n"
	.string "be overwritten.$"

OldaleTown_PokemonCenter_2F_Text_27854C: @ 827854C
	.string "I hope to see you again!$"

OldaleTown_PokemonCenter_2F_Text_278565: @ 8278565
	.string "I'm awfully sorry.\p"
	.string "We're not set up to conduct trades\n"
	.string "with TRAINERS far away in another\l"
	.string "region yet…$"

OldaleTown_PokemonCenter_2F_Text_2785C9: @ 82785C9
	.string "The other TRAINER is not ready.$"

OldaleTown_PokemonCenter_2F_Text_2785E9: @ 82785E9
	.string "You have at least one POKéMON\n"
	.string "that can't be taken.$"

RecordCorner_Text_27861C: @ 827861C
	.string "Please take your seat and wait.$"

RecordCorner_Text_27863C: @ 827863C
	.string "{STR_VAR_1} sent over one\n"
	.string "{STR_VAR_2}.$"

OldaleTown_PokemonCenter_2F_Text_278651: @ 8278651
	.string "Sorry, there is a transmission error.\p"
	.string "You may not mix records with  \n"
	.string "Japanese Ruby or Sapphire games.\p"
	.string "Also, you can't mix records with\n"
	.string "Japanese Emerald and overseas Ruby\l"
	.string "or Sapphire games at the same time.$"

OldaleTown_PokemonCenter_2F_Text_27871F: @ 827871F
	.string "The Wireless Adapter is not\n"
	.string "connected properly.$"

OldaleTown_PokemonCenter_2F_Text_27874F: @ 827874F
	.string "Participants are asked to step up\n"
	.string "to the reception counter.$"

OldaleTown_PokemonCenter_2F_Text_27878B: @ 827878B
	.string "Hello!$"

OldaleTown_PokemonCenter_2F_Text_278792: @ 8278792
	.string "Please wait.$"

CableClub_Text_YouMayTradeHere:: @ 827879F
	.string "You may trade your POKéMON here\n"
	.string "with another TRAINER.$"

CableClub_Text_YouMayBattleHere:: @ 82787D5
	.string "You may battle with your friends\n"
	.string "here.$"

CableClub_Text_CanMakeBerryPowder:: @ 82787FC
	.string "Two to five TRAINERS can make\n"
	.string "BERRY POWDER together.$"

CableClub_Text_CanMixRecords:: @ 8278831
	.string "The records of two to four players\n"
	.string "can be mixed together.$"

OldaleTown_PokemonCenter_2F_Text_27886B: @ 827886B
	.string "A guide to the WIRELESS CLUB's\n"
	.string "various services.$"

CableClub_Text_CancelSelectedItem:: @ 827889C
	.string "Cancels the selected MENU item.$"

OldaleTown_PokemonCenter_2F_Text_2788BC: @ 82788BC
	.string "Which battle mode would you like?$"

OldaleTown_PokemonCenter_2F_Text_2788DE: @ 82788DE
	.string "Returns to the previous step.$"

OldaleTown_PokemonCenter_2F_Text_2788FC: @ 82788FC
	.string "To use the BERRY CRUSH service,\n"
	.string "you must have at least one BERRY.$"

OldaleTown_PokemonCenter_2F_Text_27893E: @ 827893E
	.string "To enter the UNION ROOM, you must\n"
	.string "have at least two POKéMON.$"

OldaleTown_PokemonCenter_2F_Text_27897B: @ 827897B
	.string "No POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY may enter the UNION ROOM.$"

OldaleTown_PokemonCenter_2F_Text_2789B5: @ 82789B5
	.string "This is the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM.\p"
	.string "Unfortunately, your Wireless\n"
	.string "Adapter is not connected properly.\p"
	.string "Please do come again.$"

OldaleTown_PokemonCenter_2F_Text_278A39: @ 8278A39
	.string "Oh…\n"
	.string "Excuse me!$"

CableClub_Text_PlayerIsWaiting: @ 8278A48
	.string "It appears as if {STR_VAR_1} is playing\n"
	.string "right now.\l"
	.string "Go for it!$"

MossdeepCity_GameCorner_1F_Text_278A7D: @ 8278A7D
	.string "I can explain game rules to you,\n"
	.string "if you'd like.\p"
	.string "Which game should I describe?$"

MossdeepCity_GameCorner_1F_Text_278ACB: @ 8278ACB
	.string "“POKéMON JUMP”\p"
	.string "Make your POKéMON skip the VINE WHIP\n"
	.string "rope with the A Button.\p"
	.string "Only mini POKéMON around 28 inches\n"
	.string "or less may participate.\p"
	.string "POKéMON that only swim, burrow,\n"
	.string "or fly are not good at jumping.\p"
	.string "As a result, those POKéMON may not\n"
	.string "participate.\p"
	.string "Good things happen if everyone\n"
	.string "jumps in time.$"

MossdeepCity_GameCorner_1F_Text_278BF1: @ 8278BF1
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Command DODRIO's three heads to\n"
	.string "catch falling BERRIES.\p"
	.string "Press right, up, or left on the\n"
	.string "{PLUS} Control Pad to move the heads.\p"
	.string "To play this game, you must have\n"
	.string "a DODRIO.$"

MossdeepCity_GameCorner_1F_Text_278CAC: @ 8278CAC
	.string "If you want to play a game,\n"
	.string "please tell the old man beside me.$"

MossdeepCity_GameCorner_1F_Text_278CEB: @ 8278CEB
	.string "Hi, welcome!\n"
	.string "Are you here to play games using\l"
	.string "Wireless Communication?\p"
	.string "Can you wait just a little bit?$"

MossdeepCity_GameCorner_1F_Text_278D51: @ 8278D51
	.string "All right, come again!$"

MossdeepCity_GameCorner_1F_Text_278D68: @ 8278D68
	.string "The Wireless Adapter isn't connected.\n"
	.string "Come back when it's hooked up!$"

MossdeepCity_GameCorner_1F_Text_278DAD: @ 8278DAD
	.string "All right, which game did you want\n"
	.string "to play?$"

MossdeepCity_GameCorner_1F_Text_278DD9: @ 8278DD9
	.string "Which POKéMON would you like to\n"
	.string "enter?$"

MossdeepCity_GameCorner_1F_Text_278E00: @ 8278E00
	.string "Okay, you're all good to go.\n"
	.string "Don't let the others beat you!$"

MossdeepCity_GameCorner_1F_Text_278E3C: @ 8278E3C
	.string "Are you leaving now?\n"
	.string "Do come again!$"

MossdeepCity_GameCorner_1F_Text_278E60: @ 8278E60
	.string "It doesn't look like you have any\n"
	.string "POKéMON that you can enter…\p"
	.string "Would you like me to explain what\n"
	.string "kinds of POKéMON can enter?$"

MossdeepCity_GameCorner_1F_Text_278EDC: @ 8278EDC
	.string "“POKéMON JUMP” is open to POKéMON\n"
	.string "around 28 inches or less.\p"
	.string "What you can't enter are those\n"
	.string "POKéMON that can't jump.\p"
	.string "You know, like POKéMON that only\n"
	.string "swim, burrow, or fly.\p"
	.string "That's all you need to know.$"

MossdeepCity_GameCorner_1F_Text_278FA4: @ 8278FA4
	.string "DODRIO BERRY-PICKING is a game that \n"
	.string "only DODRIO may enter.$"

MossdeepCity_GameCorner_1F_Text_278FE0: @ 8278FE0
	.string "Could you retry this from the start\n"
	.string "again, please?$"

OldaleTown_PokemonCenter_2F_Text_279013: @ 8279013
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB DIRECT CORNER.\p"
	.string "You may interact directly with\n"
	.string "your friends here.\p"
	.string "Which room would you like to\n"
	.string "enter?$"

OldaleTown_PokemonCenter_2F_Text_27909D: @ 827909D
	.string "Would you like to trade POKéMON?$"

OldaleTown_PokemonCenter_2F_Text_2790BE: @ 82790BE
	.string "Which Battle Mode would you like\n"
	.string "to play?$"

OldaleTown_PokemonCenter_2F_Text_2790E8: @ 82790E8
	.string "Would you like to access\n"
	.string "the RECORD CORNER?$"

OldaleTown_PokemonCenter_2F_Text_279114: @ 8279114
	.string "Would you like to use the\n"
	.string "BERRY CRUSH System?$"

OldaleTown_PokemonCenter_2F_Text_279142: @ 8279142
	.string "There are three Battle Modes.\p"
	.string "SINGLE BATTLE is for two TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.\p"
	.string "DOUBLE BATTLE is for two TRAINERS\n"
	.string "with two or more POKéMON each.\p"
	.string "Each TRAINER will send out two\n"
	.string "POKéMON in battle at a time.\p"
	.string "MULTI BATTLE is for four TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.$"

BattleFrontier_BattleTowerLobby_Text_2792CD: @ 82792CD
OldaleTown_PokemonCenter_2F_Text_2792CD: @ 82792CD
	.string "Please decide which of you two\n"
	.string "will become the LEADER.\p"
	.string "The other player must then choose\n"
	.string "“JOIN GROUP.”$"

OldaleTown_PokemonCenter_2F_Text_279334: @ 8279334
	.string "Please decide which of you four\n"
	.string "will become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

MossdeepCity_GameCorner_1F_Text_2793A3: @ 82793A3
OldaleTown_PokemonCenter_2F_Text_2793A3: @ 82793A3
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

OldaleTown_PokemonCenter_2F_Text_27940D: @ 827940D
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB UNION ROOM.\p"
	.string "You may interact directly with\n"
	.string "other TRAINERS here, some of\l"
	.string "whom you may not even know.\p"
	.string "Would you like to enter the ROOM?$"

OldaleTown_PokemonCenter_2F_Text_2794B8: @ 82794B8
	.string "The TRAINERS in the UNION ROOM\n"
	.string "will be those players around you\l"
	.string "who have also entered the ROOM.\p"
	.string "You may do all sorts of things\n"
	.string "here, such as exchanging greetings.\p"
	.string "You may enter two POKéMON up to\n"
	.string "Lv. 30 for a one-on-one battle.\p"
	.string "You may take part in a chat with\n"
	.string "two to five people.\p"
	.string "Or, you may register a POKéMON for\n"
	.string "trade.\p"
	.string "Would you like to enter the ROOM?$"

OldaleTown_PokemonCenter_2F_Text_27961C: @ 827961C
	.string "I hope you enjoy your time in\n"
	.string "the UNION ROOM.$"

OldaleTown_PokemonCenter_2F_Text_27964A: @ 827964A
	.string "Hello!\n"
	.string "My name is TEALA.\p"
	.string "This must be your first time\n"
	.string "up here.\p"
	.string "I'll show you how the Wireless\n"
	.string "Communication System works.\p"
	.string "First, I need to show you this\n"
	.string "floor of our POKéMON CENTER.\p"
	.string "Right this way, please.$"

OldaleTown_PokemonCenter_2F_Text_279718: @ 8279718
	.string "On the top floor, there are two\n"
	.string "rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

OldaleTown_PokemonCenter_2F_Text_279937: @ 8279937
	.string "Hello, {PLAYER}!\p"
	.string "It's me, TEALA, the POKéMON\n"
	.string "CENTER 2F attendant.\p"
	.string "Is there something you needed to\n"
	.string "ask me about linking?$"

OldaleTown_PokemonCenter_2F_Text_2799AA: @ 82799AA
	.string "Let me explain how the POKéMON\n"
	.string "WIRELESS CLUB works.\p"
	.string "On this, the top floor, there are\n"
	.string "two rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "Sometimes, you may not be able to\n"
	.string "find your friends in the UNION ROOM\l"
	.string "or the DIRECT CORNER.\p"
	.string "In that case, please move closer\n"
	.string "to your friends.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

OldaleTown_PokemonCenter_2F_Text_279C91: @ 8279C91
	.string "I hope you enjoy the Wireless\n"
	.string "Communication System.$"
