LilycoveCity_DepartmentStore_1F_MapScripts:: @ 821F692
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_21F693:: @ 821F693
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F866, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F69C:: @ 821F69C
	lock
	faceplayer
	dotimebasedevents
	compare VAR_POKELOT_PRIZE_ITEM, 0
	goto_if_ne LilycoveCity_DepartmentStore_1F_EventScript_21F7F7
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_21F78D
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6390, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F797
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_2A64C8
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A650B, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_0x8004, 0
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7A1
	incrementgamestat 46
	compare VAR_0x8006, 0
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F77B
	compare VAR_0x8006, 1
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F784
	bufferitemname 0, VAR_0x8005
	compare VAR_0x8004, 1
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7B9
	compare VAR_0x8004, 2
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7C2
	compare VAR_0x8004, 3
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7CB
	compare VAR_0x8004, 4
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7D4
	giveitem_std VAR_0x8005
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7DD
	special sub_80EE2CC
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7AF
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F77B:: @ 821F77B
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6592, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F784:: @ 821F784
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A65E6, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F78D:: @ 821F78D
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6496, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F797:: @ 821F797
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A64B1, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7A1:: @ 821F7A1
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A663C, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7AF
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7AF:: @ 821F7AF
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6831, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7B9:: @ 821F7B9
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6664, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7C2:: @ 821F7C2
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A66A7, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7CB:: @ 821F7CB
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A66ED, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7D4:: @ 821F7D4
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6731, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7DD:: @ 821F7DD
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7ED
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7ED:: @ 821F7ED
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A678C, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7F7:: @ 821F7F7
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A67E1, MSGBOX_DEFAULT
	giveitem_std VAR_POKELOT_PRIZE_ITEM
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7ED
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special sub_80EE2CC
	setvar VAR_POKELOT_PRIZE_ITEM, 0
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F82F:: @ 821F82F
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F88C, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F838:: @ 821F838
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F8F5, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F841:: @ 821F841
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F92B, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F84A:: @ 821F84A
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F974, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F85D:: @ 821F85D
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F98A, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_Text_21F866: @ 821F866
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"

LilycoveCity_DepartmentStore_1F_Text_21F88C: @ 821F88C
	.string "Whenever I come to the DEPARTMENT\n"
	.string "STORE, I always end up buying all sorts\l"
	.string "of things because it's so fun.$"

LilycoveCity_DepartmentStore_1F_Text_21F8F5: @ 821F8F5
	.string "Today, my mom is going to buy me some\n"
	.string "nice furniture.$"

LilycoveCity_DepartmentStore_1F_Text_21F92B: @ 821F92B
	.string "I'm buying something for my AZUMARILL\n"
	.string "as a reward for winning a CONTEST.$"

LilycoveCity_DepartmentStore_1F_Text_21F974: @ 821F974
	.string "AZUMARILL: Maririroo!$"

LilycoveCity_DepartmentStore_1F_Text_21F98A: @ 821F98A
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER'S ZONE\p"
	.string "3F: BATTLE COLLECTION\p"
	.string "4F: TM CORNER\p"
	.string "5F: POKé DOLL FLOOR\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"

LilycoveCity_DepartmentStore_1F_Text_21FA13: @ 821FA13
	.string "Wireless Communication is a\n"
	.string "lot of fun, isn't it?\p"
	.string "I think it lets you do things that\n"
	.string "weren't possible before.\p"
	.string "For instance, you can now trade\n"
	.string "with people you couldn't before.\p"
	.string "I think it's going to be exciting!$"

LilycoveCity_DepartmentStore_1F_Text_21FAE5: @ 821FAE5
	.string "I want to spread the word about how\n"
	.string "fun Wireless Communication can be.$"

