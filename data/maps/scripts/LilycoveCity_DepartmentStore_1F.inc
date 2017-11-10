LilycoveCity_DepartmentStore_1F_MapScripts:: @ 821F692
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_21F693:: @ 821F693
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F866, 2
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F69C:: @ 821F69C
	lock
	faceplayer
	dodailyevents
	compare_var_to_value VAR_POKELOT_PRIZE, 0
	goto_if 5, LilycoveCity_DepartmentStore_1F_EventScript_21F7F7
	checkflag FLAG_0x92A
	goto_eq LilycoveCity_DepartmentStore_1F_EventScript_21F78D
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6390, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStore_1F_EventScript_21F797
	setflag FLAG_0x92A
	message LilycoveCity_DepartmentStore_1F_Text_2A64C8
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special sub_81397C4
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A650B, 4
	applymovement 2, LilycoveCity_DepartmentStore_1F_Movement_2725A8
	waitmovement 0
	playse SE_PC_ON
	special sub_8138EC0
	special PickLotteryCornerTicket
	delay 220
	special sub_8138FAC
	delay 10
	applymovement 2, LilycoveCity_DepartmentStore_1F_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x8004, 0
	goto_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7A1
	incrementgamestat 46
	compare_var_to_value VAR_0x8006, 0
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F77B
	compare_var_to_value VAR_0x8006, 1
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F784
	bufferitemname 0, VAR_0x8005
	compare_var_to_value VAR_0x8004, 1
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F7B9
	compare_var_to_value VAR_0x8004, 2
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F7C2
	compare_var_to_value VAR_0x8004, 3
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F7CB
	compare_var_to_value VAR_0x8004, 4
	call_if 1, LilycoveCity_DepartmentStore_1F_EventScript_21F7D4
	giveitem_std VAR_0x8005
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7DD
	special sub_80EE2CC
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7AF
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F77B:: @ 821F77B
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6592, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F784:: @ 821F784
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A65E6, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F78D:: @ 821F78D
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6496, 4
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F797:: @ 821F797
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A64B1, 4
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7A1:: @ 821F7A1
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A663C, 4
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7AF
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7AF:: @ 821F7AF
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6831, 4
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7B9:: @ 821F7B9
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6664, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7C2:: @ 821F7C2
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A66A7, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7CB:: @ 821F7CB
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A66ED, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7D4:: @ 821F7D4
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A6731, 4
	return

LilycoveCity_DepartmentStore_1F_EventScript_21F7DD:: @ 821F7DD
	copyvar VAR_0x404D, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_21F7ED
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7ED:: @ 821F7ED
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A678C, 4
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F7F7:: @ 821F7F7
	msgbox LilycoveCity_DepartmentStore_1F_Text_2A67E1, 4
	giveitem_std VAR_POKELOT_PRIZE
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStore_1F_EventScript_21F7ED
	copyvar VAR_0x8004, VAR_0x404D
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE
	special sub_80EE2CC
	setvar VAR_POKELOT_PRIZE, 0
	setvar VAR_0x404D, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F82F:: @ 821F82F
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F88C, 2
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F838:: @ 821F838
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F8F5, 2
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F841:: @ 821F841
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F92B, 2
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F84A:: @ 821F84A
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F974, 4
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_21F85D:: @ 821F85D
	msgbox LilycoveCity_DepartmentStore_1F_Text_21F98A, 3
	end

LilycoveCity_DepartmentStore_1F_Text_21F866: @ 821F866
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"

LilycoveCity_DepartmentStore_1F_Text_21F88C: @ 821F88C
	.string "Whenever I come to the DEPARTMENT\n"
	.string "STORE, I always end up buying all sorts\l"
	.string "of things because it’s so fun.$"

LilycoveCity_DepartmentStore_1F_Text_21F8F5: @ 821F8F5
	.string "Today, my mom is going to buy me some\n"
	.string "nice furniture.$"

LilycoveCity_DepartmentStore_1F_Text_21F92B: @ 821F92B
	.string "I’m buying something for my AZUMARILL\n"
	.string "as a reward for winning a CONTEST.$"

LilycoveCity_DepartmentStore_1F_Text_21F974: @ 821F974
	.string "AZUMARILL: Maririroo!$"

LilycoveCity_DepartmentStore_1F_Text_21F98A: @ 821F98A
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER’S ZONE\p"
	.string "3F: BATTLE COLLECTION\p"
	.string "4F: TM CORNER\p"
	.string "5F: POKé DOLL FLOOR\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"

	.incbin "baserom.gba", 0x21fa13, 0x119

