LilycoveCity_ContestLobby_EventScript_279CC5:: @ 8279CC5
	lock
	faceplayer
	compare VAR_CONTEST_PRIZE_PICKUP, 0
	goto_if_ne LilycoveCity_ContestLobby_EventScript_279D13
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_279CEA
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_279CF3
	goto LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279CEA:: @ 8279CEA
	msgbox LilycoveCity_ContestLobby_Text_27AEA8, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_279CF3:: @ 8279CF3
	msgbox LilycoveCity_ContestLobby_Text_27ADA7, MSGBOX_DEFAULT
	giveitem_std ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_27AE47, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_279D13:: @ 8279D13
	msgbox LilycoveCity_ContestLobby_Text_27B67B, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_279D2C
	end

LilycoveCity_ContestLobby_EventScript_279D2C:: @ 8279D2C
	giveitem_std ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279D4B
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_279D4B:: @ 8279D4B
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_27B6E7, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_279D5A:: @ 8279D5A
	message LilycoveCity_ContestLobby_Text_27AF28
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E62
	case 1, LilycoveCity_ContestLobby_EventScript_279D97
	case 2, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279D97:: @ 8279D97
	message LilycoveCity_ContestLobby_Text_27AF5E
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279DDF
	case 1, LilycoveCity_ContestLobby_EventScript_279DED
	case 2, LilycoveCity_ContestLobby_EventScript_279DFB
	case 3, LilycoveCity_ContestLobby_EventScript_279D5A
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279DDF:: @ 8279DDF
	msgbox LilycoveCity_ContestLobby_Text_27AF7A, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DED:: @ 8279DED
	msgbox LilycoveCity_ContestLobby_Text_27B17D, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DFB:: @ 8279DFB
	msgbox LilycoveCity_ContestLobby_Text_27B221, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279E09:: @ 8279E09
	msgbox LilycoveCity_ContestLobby_Text_27BD4F, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_279E13:: @ 8279E13
	msgbox LilycoveCity_ContestLobby_Text_27B44A, MSGBOX_DEFAULT
	choosecontestmon
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279E09
	special sub_80F7F30
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F12
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F87
	compare VAR_RESULT, 2
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F45
	compare VAR_RESULT, 3
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F69
	compare VAR_RESULT, 4
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F78
	end

LilycoveCity_ContestLobby_EventScript_279E62:: @ 8279E62
	message LilycoveCity_ContestLobby_Text_27B3FF
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279EB5
	case 1, LilycoveCity_ContestLobby_EventScript_279EC0
	case 2, LilycoveCity_ContestLobby_EventScript_279ECB
	case 3, LilycoveCity_ContestLobby_EventScript_279ED6
	case 4, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279EB5:: @ 8279EB5
	setvar VAR_CONTEST_RANK, 0
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EC0:: @ 8279EC0
	setvar VAR_CONTEST_RANK, 1
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ECB:: @ 8279ECB
	setvar VAR_CONTEST_RANK, 2
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ED6:: @ 8279ED6
	setvar VAR_CONTEST_RANK, 3
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EE1:: @ 8279EE1
	message LilycoveCity_ContestLobby_Text_27B423
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, 0
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	end

LilycoveCity_ContestLobby_EventScript_279F12:: @ 8279F12
	msgbox LilycoveCity_ContestLobby_Text_27B471, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F21:: @ 8279F21
	msgbox LilycoveCity_ContestLobby_Text_27B5C4, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E13
	case 1, LilycoveCity_ContestLobby_EventScript_279F87
	end

LilycoveCity_ContestLobby_EventScript_279F45:: @ 8279F45
	msgbox LilycoveCity_ContestLobby_Text_27B547, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E13
	case 1, LilycoveCity_ContestLobby_EventScript_279F87
	end

LilycoveCity_ContestLobby_EventScript_279F69:: @ 8279F69
	msgbox LilycoveCity_ContestLobby_Text_27B4C4, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F78:: @ 8279F78
	msgbox LilycoveCity_ContestLobby_Text_27B501, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F87:: @ 8279F87
	msgbox LilycoveCity_ContestLobby_Text_27B5E2, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_LINK_CONTEST_ROOM_STATE, 1
	return

LinkContestRoom1_EventScript_279F97:: @ 8279F97
	special sub_80F90DC
	setvar VAR_0x8006, 0
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD43
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD09
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_279FF2
	call LinkContestRoom1_EventScript_27A03C
	call LinkContestRoom1_EventScript_27A097
	call LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A801
	call LinkContestRoom1_EventScript_27A8A5
	call LinkContestRoom1_EventScript_27A987
	call LinkContestRoom1_EventScript_27A9D4
	call LinkContestRoom1_EventScript_27AA1B
	call LinkContestRoom1_EventScript_27AB36
	setvar VAR_LINK_CONTEST_ROOM_STATE, 2
	return

LinkContestRoom1_EventScript_279FF2:: @ 8279FF2
	switch VAR_CONTEST_RANK
	case 0, LinkContestRoom1_EventScript_27A024
	case 1, LinkContestRoom1_EventScript_27A02A
	case 2, LinkContestRoom1_EventScript_27A030
	case 3, LinkContestRoom1_EventScript_27A036
	return

LinkContestRoom1_EventScript_27A024:: @ 827A024
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

LinkContestRoom1_EventScript_27A02A:: @ 827A02A
	setvar VAR_0x8009, STDSTRING_SUPER
	return

LinkContestRoom1_EventScript_27A030:: @ 827A030
	setvar VAR_0x8009, STDSTRING_HYPER
	return

LinkContestRoom1_EventScript_27A036:: @ 827A036
	setvar VAR_0x8009, STDSTRING_MASTER
	return

LinkContestRoom1_EventScript_27A03C:: @ 827A03C
	switch VAR_CONTEST_CATEGORY
	case 0, LinkContestRoom1_EventScript_27A079
	case 1, LinkContestRoom1_EventScript_27A07F
	case 2, LinkContestRoom1_EventScript_27A085
	case 3, LinkContestRoom1_EventScript_27A08B
	case 4, LinkContestRoom1_EventScript_27A091
	return

LinkContestRoom1_EventScript_27A079:: @ 827A079
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

LinkContestRoom1_EventScript_27A07F:: @ 827A07F
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

LinkContestRoom1_EventScript_27A085:: @ 827A085
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

LinkContestRoom1_EventScript_27A08B:: @ 827A08B
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

LinkContestRoom1_EventScript_27A091:: @ 827A091
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

LinkContestRoom1_EventScript_27A097:: @ 827A097
	buffercontesttypestring 1, VAR_0x8008
	bufferstdstring 2, VAR_0x8009
	call LinkContestRoom1_EventScript_27A0B1
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD0B
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A0B1:: @ 827A0B1
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A0C7
	lockall
	msgbox LinkContestRoom1_Text_27B711, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27A0C7:: @ 827A0C7
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A0DE
	messageautoscroll LinkContestRoom1_Text_27B78F
	waitmessage
	return

LinkContestRoom1_EventScript_27A0DE:: @ 827A0DE
	messageautoscroll LinkContestRoom1_Text_27C929
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27C972
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A0F5:: @ 827A0F5
	call LinkContestRoom1_EventScript_27A149
	call LinkContestRoom1_EventScript_27A1D2
	call LinkContestRoom1_EventScript_27A34F
	call LinkContestRoom1_EventScript_27A2D5
	call LinkContestRoom1_EventScript_27A77A
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A133
	addvar VAR_0x8006, 1
	compare VAR_0x8006, 4
	goto_if_ne LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A230
	setvar VAR_TEMP_1, 6
	return

LinkContestRoom1_EventScript_27A133:: @ 827A133
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A144
	return

LinkContestRoom1_EventScript_27A144:: @ 827A144
	special sub_80F905C
	waitstate
	return

LinkContestRoom1_EventScript_27A149:: @ 827A149
	compare VAR_0x8006, 0
	goto_if_eq LinkContestRoom1_EventScript_27A176
	compare VAR_0x8006, 1
	goto_if_eq LinkContestRoom1_EventScript_27A18D
	compare VAR_0x8006, 2
	goto_if_eq LinkContestRoom1_EventScript_27A1A4
	compare VAR_0x8006, 3
	goto_if_eq LinkContestRoom1_EventScript_27A1BB
	return

LinkContestRoom1_EventScript_27A176:: @ 827A176
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 3, LinkContestRoom1_Movement_27AD52
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 3
	return

LinkContestRoom1_EventScript_27A18D:: @ 827A18D
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 4, LinkContestRoom1_Movement_27AD5E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 4
	return

LinkContestRoom1_EventScript_27A1A4:: @ 827A1A4
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 5, LinkContestRoom1_Movement_27AD66
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 5
	return

LinkContestRoom1_EventScript_27A1BB:: @ 827A1BB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD6E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 14
	return

LinkContestRoom1_EventScript_27A1D2:: @ 827A1D2
	special sub_80F8850
	addvar VAR_0x8006, 1
	buffernumberstring 1, VAR_0x8006
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27AD80
	addobject 13
	playse SE_DANSA
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	addvar VAR_0x8006, 65535
	playse SE_BOWA2
	special ShowContestEntryMonPic
	call LinkContestRoom1_EventScript_27A217
	return

LinkContestRoom1_EventScript_27A217:: @ 827A217
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A229
	message LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A229:: @ 827A229
	messageautoscroll LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A230:: @ 827A230
	call LinkContestRoom1_EventScript_27A26C
	call LinkContestRoom1_EventScript_27A2B9
	playse SE_W227B
	waitmessage
	call LinkContestRoom1_EventScript_27AA1B
	applymovement 1, LinkContestRoom1_Movement_27AD23
	waitmovement 0
	applymovement 2, LinkContestRoom1_Movement_27AD25
	waitmovement 0
	delay 20
	applymovement 1, LinkContestRoom1_Movement_27AD13
	applymovement 2, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A26C:: @ 827A26C
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A280
	msgbox LinkContestRoom1_Text_27B830, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A280:: @ 827A280
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A297
	messageautoscroll LinkContestRoom1_Text_27B830
	waitmessage
	return

LinkContestRoom1_EventScript_27A297:: @ 827A297
	messageautoscroll LinkContestRoom1_Text_27C9AF
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA04
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA42
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2B9:: @ 827A2B9
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A2CA
	message LinkContestRoom1_Text_27B8F2
	return

LinkContestRoom1_EventScript_27A2CA:: @ 827A2CA
	messageautoscroll LinkContestRoom1_Text_27B8F2
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2D5:: @ 827A2D5
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	playse SE_W227B
	call LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD45
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD4E
	applymovement 2, LinkContestRoom1_Movement_27AD49
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A34F:: @ 827A34F
	special sub_80F82FC
	compare VAR_CONTEST_LOCATION, 1
	call_if_eq LinkContestRoom1_EventScript_27A454
	compare VAR_CONTEST_LOCATION, 2
	call_if_eq LinkContestRoom1_EventScript_27A4B2
	compare VAR_CONTEST_LOCATION, 3
	call_if_eq LinkContestRoom1_EventScript_27A510
	compare VAR_CONTEST_LOCATION, 4
	call_if_eq LinkContestRoom1_EventScript_27A56E
	compare VAR_CONTEST_LOCATION, 5
	call_if_eq LinkContestRoom1_EventScript_27A5CC
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	compare VAR_TEMP_0, 0
	call_if_gt LinkContestRoom1_EventScript_27A3E5
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	return

LinkContestRoom1_EventScript_27A3E5:: @ 827A3E5
	setvar VAR_RESULT, 8
	special ScriptRandom
	compare VAR_RESULT, 0
	call_if_eq LinkContestRoom1_EventScript_27A65A
	compare VAR_RESULT, 1
	call_if_eq LinkContestRoom1_EventScript_27A67E
	compare VAR_RESULT, 2
	call_if_eq LinkContestRoom1_EventScript_27A6A2
	compare VAR_RESULT, 3
	call_if_eq LinkContestRoom1_EventScript_27A6C6
	compare VAR_RESULT, 4
	call_if_eq LinkContestRoom1_EventScript_27A6EA
	compare VAR_RESULT, 5
	call_if_eq LinkContestRoom1_EventScript_27A70E
	compare VAR_RESULT, 6
	call_if_eq LinkContestRoom1_EventScript_27A732
	compare VAR_RESULT, 7
	call_if_eq LinkContestRoom1_EventScript_27A756
	compare VAR_TEMP_0, 0
	goto_if_gt LinkContestRoom1_EventScript_27A3E5
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A454:: @ 827A454
	compare VAR_0x8004, 80
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 70
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 60
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 50
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 40
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 30
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 20
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 10
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A4B2:: @ 827A4B2
	compare VAR_0x8004, 230
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 210
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 190
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 170
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 150
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 130
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 110
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 90
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A510:: @ 827A510
	compare VAR_0x8004, 380
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 350
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 320
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 290
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 260
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 230
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 200
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 170
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A56E:: @ 827A56E
	compare VAR_0x8004, 600
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 560
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 520
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 480
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 440
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 400
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 360
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 320
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A5CC:: @ 827A5CC
	compare VAR_0x8004, 600
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 550
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 500
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 450
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 400
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 300
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 200
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 100
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A62A:: @ 827A62A
	setvar VAR_TEMP_0, 1
	return

LinkContestRoom1_EventScript_27A630:: @ 827A630
	setvar VAR_TEMP_0, 2
	return

LinkContestRoom1_EventScript_27A636:: @ 827A636
	setvar VAR_TEMP_0, 3
	return

LinkContestRoom1_EventScript_27A63C:: @ 827A63C
	setvar VAR_TEMP_0, 4
	return

LinkContestRoom1_EventScript_27A642:: @ 827A642
	setvar VAR_TEMP_0, 5
	return

LinkContestRoom1_EventScript_27A648:: @ 827A648
	setvar VAR_TEMP_0, 6
	return

LinkContestRoom1_EventScript_27A64E:: @ 827A64E
	setvar VAR_TEMP_0, 7
	return

LinkContestRoom1_EventScript_27A654:: @ 827A654
	setvar VAR_TEMP_0, 8
	return

LinkContestRoom1_EventScript_27A65A:: @ 827A65A
	compare VAR_TEMP_1, 1
	goto_if_eq LinkContestRoom1_EventScript_27A67D
	applymovement 6, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A67D:: @ 827A67D
	return

LinkContestRoom1_EventScript_27A67E:: @ 827A67E
	compare VAR_TEMP_2, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6A1
	applymovement 12, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6A1:: @ 827A6A1
	return

LinkContestRoom1_EventScript_27A6A2:: @ 827A6A2
	compare VAR_TEMP_3, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6C5
	applymovement 7, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6C5:: @ 827A6C5
	return

LinkContestRoom1_EventScript_27A6C6:: @ 827A6C6
	compare VAR_TEMP_4, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6E9
	applymovement 8, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6E9:: @ 827A6E9
	return

LinkContestRoom1_EventScript_27A6EA:: @ 827A6EA
	compare VAR_TEMP_5, 1
	goto_if_eq LinkContestRoom1_EventScript_27A70D
	applymovement 9, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A70D:: @ 827A70D
	return

LinkContestRoom1_EventScript_27A70E:: @ 827A70E
	compare VAR_TEMP_6, 1
	goto_if_eq LinkContestRoom1_EventScript_27A731
	applymovement 10, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A731:: @ 827A731
	return

LinkContestRoom1_EventScript_27A732:: @ 827A732
	compare VAR_TEMP_7, 1
	goto_if_eq LinkContestRoom1_EventScript_27A755
	applymovement 11, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A755:: @ 827A755
	return

LinkContestRoom1_EventScript_27A756:: @ 827A756
	compare VAR_TEMP_8, 1
	goto_if_eq LinkContestRoom1_EventScript_27A779
	applymovement 15, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A779:: @ 827A779
	return

LinkContestRoom1_EventScript_27A77A:: @ 827A77A
	closemessage
	release
	removeobject 13
	special sub_80F8EB8
	call LinkContestRoom1_EventScript_27A133
	switch VAR_0x8006
	case 0, LinkContestRoom1_EventScript_27A7B9
	case 1, LinkContestRoom1_EventScript_27A7CB
	case 2, LinkContestRoom1_EventScript_27A7DD
	case 3, LinkContestRoom1_EventScript_27A7EF
	return

LinkContestRoom1_EventScript_27A7B9:: @ 827A7B9
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD58
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7CB:: @ 827A7CB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD62
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7DD:: @ 827A7DD
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD6A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7EF:: @ 827A7EF
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD74
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A801:: @ 827A801
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD27
	waitmovement 0
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A853
	waitmessage
	applymovement 1, LinkContestRoom1_Movement_27AD15
	applymovement 2, LinkContestRoom1_Movement_27AD19
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	setvar VAR_TEMP_9, 1
	special sub_80F910C
	startcontest
	special sub_80F90DC
	setvar VAR_TEMP_9, 0
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD19
	applymovement 2, LinkContestRoom1_Movement_27AD15
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A853:: @ 827A853
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A867
	msgbox LinkContestRoom1_Text_27B904, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A867:: @ 827A867
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A87E
	messageautoscroll LinkContestRoom1_Text_27B904
	waitmessage
	return

LinkContestRoom1_EventScript_27A87E:: @ 827A87E
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA71
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CAD0
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CB55
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A8A5:: @ 827A8A5
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A8FB
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A91E
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD0F
	waitmovement 0
	call LinkContestRoom1_EventScript_27A941
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A964
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	closemessage
	releaseall
	special sub_80F910C
	setvar VAR_TEMP_9, 1
	showcontestresults
	setvar VAR_TEMP_9, 0
	playbgm MUS_CON_FAN, 0
	return

LinkContestRoom1_EventScript_27A8FB:: @ 827A8FB
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A90F
	msgbox LinkContestRoom1_Text_27BA15, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A90F:: @ 827A90F
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA15
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A91E:: @ 827A91E
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A932
	msgbox LinkContestRoom1_Text_27BA30, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A932:: @ 827A932
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA30
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A941:: @ 827A941
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A955
	msgbox LinkContestRoom1_Text_27BAAC, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A955:: @ 827A955
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BAAC
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A964:: @ 827A964
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A978
	msgbox LinkContestRoom1_Text_27BB25, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A978:: @ 827A978
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BB25
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A987:: @ 827A987
	special sub_80F831C
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27A9BC
	case 1, LinkContestRoom1_EventScript_27A9C2
	case 2, LinkContestRoom1_EventScript_27A9C8
	case 3, LinkContestRoom1_EventScript_27A9CE
	return

LinkContestRoom1_EventScript_27A9BC:: @ 827A9BC
	setvar VAR_TEMP_3, 3
	return

LinkContestRoom1_EventScript_27A9C2:: @ 827A9C2
	setvar VAR_TEMP_3, 4
	return

LinkContestRoom1_EventScript_27A9C8:: @ 827A9C8
	setvar VAR_TEMP_3, 5
	return

LinkContestRoom1_EventScript_27A9CE:: @ 827A9CE
	setvar VAR_TEMP_3, 14
	return

LinkContestRoom1_EventScript_27A9D4:: @ 827A9D4
	special sub_80F834C
	special sub_80F8390
	addvar VAR_0x8005, 1
	buffernumberstring 1, VAR_0x8005
	addvar VAR_0x8005, 65535
	call LinkContestRoom1_EventScript_27AA00
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD1D
	waitmovement 0
	playse SE_W227B
	setvar VAR_TEMP_1, 0
	return

LinkContestRoom1_EventScript_27AA00:: @ 827AA00
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27AA14
	msgbox LinkContestRoom1_Text_27BB4C, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27AA14:: @ 827AA14
	messageautoscroll LinkContestRoom1_Text_27BB4C
	waitmessage
	return

LinkContestRoom1_EventScript_27AA1B:: @ 827AA1B
	addvar VAR_TEMP_1, 1
	lockall
	compare VAR_CONTEST_LOCATION, 1
	call_if_gt LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	delay 30
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	compare VAR_TEMP_1, 4
	goto_if_ne LinkContestRoom1_EventScript_27AA1B
	delay 30
	return

LinkContestRoom1_EventScript_27AA6F:: @ 827AA6F
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 28, DIR_EAST
	delay 10
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 25, DIR_NORTH
	turnvobject 27, DIR_NORTH
	turnvobject 28, DIR_NORTH
	delay 10
	turnvobject 1, DIR_NORTH
	turnvobject 3, DIR_NORTH
	turnvobject 5, DIR_NORTH
	turnvobject 7, DIR_NORTH
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 13, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 19, DIR_NORTH
	turnvobject 21, DIR_WEST
	turnvobject 23, DIR_WEST
	turnvobject 24, DIR_WEST
	turnvobject 26, DIR_EAST
	turnvobject 29, DIR_WEST
	turnvobject 30, DIR_WEST
	delay 10
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_NORTH
	turnvobject 29, DIR_NORTH
	turnvobject 30, DIR_NORTH
	delay 10
	return

LinkContestRoom1_EventScript_27AB36:: @ 827AB36
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27ABD8
	call LinkContestRoom1_EventScript_27AB9E
	goto_if_set FLAG_TEMP_2, LinkContestRoom1_EventScript_27AB82
	lockall
	msgbox LinkContestRoom1_Text_27BBA8, MSGBOX_DEFAULT
	releaseall
	call LinkContestRoom1_EventScript_27ABF8
	call LinkContestRoom1_EventScript_27AC5E
	playse SE_W227B
	setvar VAR_TEMP_1, 0
	call LinkContestRoom1_EventScript_27AA1B
	delay 30
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB82:: @ 827AB82
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	delay 90
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB9E:: @ 827AB9E
	specialvar VAR_RESULT, sub_80F7F7C
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABAF
	return

LinkContestRoom1_EventScript_27ABAF:: @ 827ABAF
	special sub_80F831C
	compare VAR_0x8005, 3
	goto_if_eq LinkContestRoom1_EventScript_27ABBE
	return

LinkContestRoom1_EventScript_27ABBE:: @ 827ABBE
	compare VAR_CONTEST_RANK, 3
	goto_if_eq LinkContestRoom1_EventScript_27ABCD
	setflag FLAG_TEMP_2
	return

LinkContestRoom1_EventScript_27ABCD:: @ 827ABCD
	return

LinkContestRoom1_EventScript_27ABCE:: @ 827ABCE
	setflag FLAG_CONTEST_SKETCH_CREATED
	return

LinkContestRoom1_EventScript_27ABD2:: @ 827ABD2
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

LinkContestRoom1_EventScript_27ABD8:: @ 827ABD8
	delay 60
	special sub_80F84B0
	special sub_80F831C
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABF1
	closemessage
	return

LinkContestRoom1_EventScript_27ABF1:: @ 827ABF1
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

LinkContestRoom1_EventScript_27ABF7:: @ 827ABF7
	return

LinkContestRoom1_EventScript_27ABF8:: @ 827ABF8
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27AC2A
	case 1, LinkContestRoom1_EventScript_27AC37
	case 2, LinkContestRoom1_EventScript_27AC44
	case 3, LinkContestRoom1_EventScript_27AC51
	return

LinkContestRoom1_EventScript_27AC2A:: @ 827AC2A
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD7A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC37:: @ 827AC37
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD7E
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC44:: @ 827AC44
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD29
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC51:: @ 827AC51
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD2D
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC5E:: @ 827AC5E
	special sub_80F831C
	compare VAR_0x8005, 3
	goto_if_eq LinkContestRoom1_EventScript_27AC77
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27AC77:: @ 827AC77
	compare VAR_CONTEST_LOCATION, 2
	call_if_eq LinkContestRoom1_EventScript_27ABCE
	specialvar VAR_RESULT, sub_80F7F7C
	compare VAR_RESULT, 0
	goto_if_eq LinkContestRoom1_EventScript_27ACDF
	compare VAR_CONTEST_RANK, 3
	goto_if_eq LinkContestRoom1_EventScript_27ACBD
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27ACA8:: @ 827ACA8
	lockall
	call Common_EventScript_BagIsFull
	msgbox LinkContestRoom1_Text_27BC2F, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

LinkContestRoom1_EventScript_27ACBD:: @ 827ACBD
	giveitem_std ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq LinkContestRoom1_EventScript_27ACA8
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27ACDF:: @ 827ACDF
	special sub_80F7FFC
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox LinkContestRoom1_Text_27BBD4, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	msgbox LinkContestRoom1_Text_27BC00, MSGBOX_DEFAULT
	waitfanfare
	special sub_80F8390
	msgbox LinkContestRoom1_Text_27BC16, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_Movement_27AD09: @ 827AD09
	walk_down
	step_end

LinkContestRoom1_Movement_27AD0B: @ 827AD0B
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

LinkContestRoom1_Movement_27AD0F: @ 827AD0F
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD11: @ 827AD11
	emote_heart
	step_end

LinkContestRoom1_Movement_27AD13: @ 827AD13
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD15: @ 827AD15
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD19: @ 827AD19
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD1D: @ 827AD1D
	walk_up
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD20: @ 827AD20
	delay_16
	delay_16
	step_end

LinkContestRoom1_Movement_27AD23: @ 827AD23
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD25: @ 827AD25
	walk_in_place_fastest_left
	step_end

LinkContestRoom1_Movement_27AD27: @ 827AD27
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD29: @ 827AD29
	walk_left
	walk_left
	walk_up
	step_end

LinkContestRoom1_Movement_27AD2D: @ 827AD2D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LinkContestRoom1_Movement_27AD33: @ 827AD33
	face_left
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD37: @ 827AD37
	face_up
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD3B: @ 827AD3B
	face_right
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD3F: @ 827AD3F
	face_down
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD43: @ 827AD43
	face_up
	step_end

LinkContestRoom1_Movement_27AD45: @ 827AD45
	face_up
	delay_16
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD49: @ 827AD49
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD4E: @ 827AD4E
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD52: @ 827AD52
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD58: @ 827AD58
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD5E: @ 827AD5E
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD62: @ 827AD62
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD66: @ 827AD66
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD6A: @ 827AD6A
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD6E: @ 827AD6E
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD74: @ 827AD74
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD7A: @ 827AD7A
	walk_right
	walk_right
	walk_up
	step_end

LinkContestRoom1_Movement_27AD7E: @ 827AD7E
	walk_up
	step_end

LinkContestRoom1_EventScript_27AD80:: @ 827AD80
	specialvar VAR_RESULT, sub_80F9134
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27AD91
	return

LinkContestRoom1_EventScript_27AD91:: @ 827AD91
	return

LilycoveCity_ContestLobby_EventScript_27AD92:: @ 827AD92
	specialvar VAR_RESULT, sub_80F9134
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_27ADA3
	return

LilycoveCity_ContestLobby_EventScript_27ADA3:: @ 827ADA3
	delay 9
	return

LilycoveCity_ContestLobby_Text_27ADA7: @ 827ADA7
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.\p"
	.string "Oh? It appears that you don't have\n"
	.string "a {POKEBLOCK} CASE yet.\p"
	.string "In that case, we need to provide you\n"
	.string "with this!$"

LilycoveCity_ContestLobby_Text_27AE47: @ 827AE47
	.string "Okay, now that we've cleared that\n"
	.string "up…\p"
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_27AEA8: @ 827AEA8
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_27AEE3: @ 827AEE3
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_27AF28: @ 827AF28
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"

LilycoveCity_ContestLobby_Text_27AF5E: @ 827AF5E
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_27AF7A: @ 827AF7A
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"

LilycoveCity_ContestLobby_Text_27B17D: @ 827B17D
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"

LilycoveCity_ContestLobby_Text_27B221: @ 827B221
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER, and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up to the SUPER Rank\l"
	.string "in the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and\l"
	.string "a HYPER Rank winner can advance to\l"
	.string "the MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"

LilycoveCity_ContestLobby_Text_27B3FF: @ 827B3FF
	.string "Which Rank would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B423: @ 827B423
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B44A: @ 827B44A
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B471: @ 827B471
	.string "I'm terribly sorry, but your POKéMON\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"

LilycoveCity_ContestLobby_Text_27B4C4: @ 827B4C4
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_27B501: @ 827B501
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_27B547: @ 827B547
	.string "Oh, but that RIBBON…\p"
	.string "Your POKéMON has won this CONTEST\n"
	.string "before, hasn't it?\p"
	.string "Would you like to enter it in this\n"
	.string "CONTEST anyway?$"

LilycoveCity_ContestLobby_Text_27B5C4: @ 827B5C4
	.string "Is that your CONTEST POKéMON?$"

LilycoveCity_ContestLobby_Text_27B5E2: @ 827B5E2
	.string "Okay, your POKéMON will be entered\n"
	.string "in this CONTEST.\p"
	.string "Your POKéMON is Entry No. 4.\n"
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_27B653: @ 827B653
	.string "Please come in through here.\n"
	.string "Good luck!$"

LilycoveCity_ContestLobby_Text_27B67B: @ 827B67B
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"

LilycoveCity_ContestLobby_Text_27B6E7: @ 827B6E7
	.string "Please come back for your prize\n"
	.string "later on.$"

LinkContestRoom1_Text_27B711: @ 827B711
	.string "MC: Hello! We're just getting started\n"
	.string "with a {STR_VAR_3} Rank POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27B78F: @ 827B78F
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27B815: @ 827B815
	.string "MC: Entry No. {STR_VAR_2}!\n"
	.string "{STR_VAR_1}'s {STR_VAR_3}!$"

LinkContestRoom1_Text_27B830: @ 827B830
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!\p"
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.\p"
	.string "Without any further ado, let the\n"
	.string "voting begin!$"

LinkContestRoom1_Text_27B8F2: @ 827B8F2
	.string "Voting under way…$"

LinkContestRoom1_Text_27B904: @ 827B904
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!\p"
	.string "The second stage of judging is the\n"
	.string "much anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!\p"
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"

LinkContestRoom1_Text_27BA15: @ 827BA15
	.string "MC: That's it for judging!$"

LinkContestRoom1_Text_27BA30: @ 827BA30
	.string "Thank you all for a most wonderful\n"
	.string "display of quality appeals!\p"
	.string "This concludes all judging!\n"
	.string "Thank you for your fine efforts!$"

LinkContestRoom1_Text_27BAAC: @ 827BAAC
	.string "Now, all that remains is the pulse-\n"
	.string "pounding proclamation of the winner.\p"
	.string "The JUDGE looks ready to make\n"
	.string "the announcement!$"

LinkContestRoom1_Text_27BB25: @ 827BB25
	.string "JUDGE: We will now declare the winner!$"

LinkContestRoom1_Text_27BB4C: @ 827BB4C
	.string "MC: Entry No. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
	.string "congratulations!$"

LinkContestRoom1_Text_27BB7A: @ 827BB7A
	.string "MC: Congratulations!\n"
	.string "Please do compete again!$"

LinkContestRoom1_Text_27BBA8: @ 827BBA8
	.string "MC: Here you are!\n"
	.string "Please accept your prize!$"

LinkContestRoom1_Text_27BBD4: @ 827BBD4
	.string "We confer on you this RIBBON\n"
	.string "as your prize!$"

LinkContestRoom1_Text_27BC00: @ 827BC00
	.string "{PLAYER} received a RIBBON.$"

LinkContestRoom1_Text_27BC16: @ 827BC16
	.string "{PLAYER} put the RIBBON on\n"
	.string "{STR_VAR_1}.$"

LinkContestRoom1_Text_27BC2F: @ 827BC2F
	.string "Please pick up your prize at\n"
	.string "the reception counter later.\l"
	.string "Please do compete again!$"

LinkContestRoom1_Text_27BC82: @ 827BC82
	.string "I only register four players for\n"
	.string "POKéMON CONTESTS.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same CONTEST.\p"
	.string "Would you like to take part?$"

LilycoveCity_ContestLobby_Text_27BD17: @ 827BD17
	.string "Before entering a CONTEST, your\n"
	.string "progress will be saved.$"

LilycoveCity_ContestLobby_Text_27BD4F: @ 827BD4F
	.string "We hope you will participate another\n"
	.string "time.$"

LilycoveCity_ContestLobby_Text_27BD7A: @ 827BD7A
	.string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_27BD9D: @ 827BD9D
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same CONTEST\n"
	.string "as your fellow contestants.\p"
	.string "The CONTEST begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual CONTEST rules\n"
	.string "apply.$"

LilycoveCity_ContestLobby_Text_27BE9E: @ 827BE9E
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27BEC5: @ 827BEC5
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_27BEEC: @ 827BEEC
	.string "Transmitting…$"

LilycoveCity_ContestLobby_Text_27BEFA: @ 827BEFA
	.string "Transmission error…$"

LilycoveCity_ContestLobby_Text_27BF0E: @ 827BF0E
	.string "You may have chosen a different\n"
	.string "CONTEST than another player.$"

LilycoveCity_ContestLobby_Text_27BF4B: @ 827BF4B
	.string "You may have made a different\n"
	.string "choice than another player.$"

LilycoveCity_ContestLobby_Text_27BF85: @ 827BF85
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

LilycoveCity_ContestLobby_Text_27BFA7: @ 827BFA7
	.string "We hope you will participate another\n"
	.string "time.$"

LilycoveCity_ContestLobby_Text_27BFD2: @ 827BFD2
	.string "Transmission error.\n"
	.string "Please try again.$"

LilycoveCity_ContestLobby_Text_27BFF8: @ 827BFF8
	.string "Your POKéMON will be entered in\n"
	.string "the CONTEST.\p"
	.string "Your POKéMON is Entry No. {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_27C043: @ 827C043
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_27C063: @ 827C063
	.string "Welcome! This is the POKéMON CONTEST\n"
	.string "link reception counter.\p"
	.string "You may enter CONTESTS together with\n"
	.string "one or more friends.$"

LilycoveCity_ContestLobby_Text_27C0DA: @ 827C0DA
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_27C0F6: @ 827C0F6
	.string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_27C119: @ 827C119
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27C140: @ 827C140
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_27C186: @ 827C186
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_27C1C3: @ 827C1C3
	.string "Which POKéMON would you like to enter?$"

Text_DecideLinkLeader: @ 827C1EA
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

LilycoveCity_ContestLobby_Text_27C254: @ 827C254
	.string "At least one player has entered using\n"
	.string "the 4-player reception counter.\p"
	.string "There must be four players connected\n"
	.string "using a GBA Game Link cable.\p"
	.string "When the four players are ready,\n"
	.string "select G-MODE (GLOBAL MODE),\l"
	.string "then register to enter again, please.$"

LilycoveCity_ContestLobby_Text_27C340: @ 827C340
	.string "This is a CONTEST for two to four\n"
	.string "players linked using a Wireless\l"
	.string "Adapter or a GBA Game Link cable.\p"
	.string "Participants are first asked to choose\n"
	.string "the mode they wish to enter.\p"
	.string "There are two different modes.\p"
	.string "E-MODE (EMERALD MODE) is for\n"
	.string "two to four players, each with a\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "G-MODE (GLOBAL MODE) is only for\n"
	.string "four players, each with a POKéMON\l"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The players should discuss which mode\n"
	.string "they want, then choose the same mode.\p"
	.string "Once all the players have chosen\n"
	.string "the same CONTEST in the same mode,\l"
	.string "the entry registration is complete.\p"
	.string "After that, a CONTEST will start in\n"
	.string "the usual manner.$"

LilycoveCity_ContestLobby_Text_27C5B1: @ 827C5B1
	.string "In E-MODE (EMERALD MODE),\n"
	.string "a LINK CONTEST can be held with\l"
	.string "two to four players. Each player must\l"
	.string "have a POKéMON Emerald Game Pak.\p"
	.string "The players must be linked with each\n"
	.string "other using Wireless Adapters or\l"
	.string "GBA Game Link cables.\p"
	.string "If there are fewer than four players,\n"
	.string "TRAINERS in the hall will join to fill\l"
	.string "the 4-player CONTEST lineup.\p"
	.string "Please be aware that E-MODE is not\n"
	.string "available in POKéMON Ruby or Sapphire.$"

LilycoveCity_ContestLobby_Text_27C742: @ 827C742
	.string "G-MODE (GLOBAL MODE) is specifically\n"
	.string "for four players who are linked using\l"
	.string "GBA Game Link cables.\p"
	.string "Each player must have a POKéMON\n"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The CONTEST starts after all players\n"
	.string "choose G-MODE (POKéMON Emerald) or\l"
	.string "enter through the 4-player reception\l"
	.string "counter (POKéMON Ruby or Sapphire).$"

LilycoveCity_ContestLobby_Text_27C879: @ 827C879
	.string "I'm terribly sorry.\p"
	.string "G-MODE does not function\n"
	.string "with Wireless Adapters.\p"
	.string "Please select E-MODE or try\n"
	.string "again using a GBA Game Link cable.$"

LilycoveCity_ContestLobby_Text_27C8FD: @ 827C8FD
	.string "Which CONTEST MODE would you like\n"
	.string "to enter?$"

LinkContestRoom1_Text_27C929: @ 827C929
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!$"

LinkContestRoom1_Text_27C972: @ 827C972
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27C9AF: @ 827C9AF
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!$"

LinkContestRoom1_Text_27CA04: @ 827CA04
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.$"

LinkContestRoom1_Text_27CA42: @ 827CA42
	.string "Without any further ado,\n"
	.string "let the voting begin!$"

LinkContestRoom1_Text_27CA71: @ 827CA71
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!$"

LinkContestRoom1_Text_27CAD0: @ 827CAD0
	.string "The second stage of judging is\n"
	.string "the much-anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!$"

LinkContestRoom1_Text_27CB55: @ 827CB55
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"
