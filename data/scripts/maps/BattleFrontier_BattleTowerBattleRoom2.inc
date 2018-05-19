BattleFrontier_BattleTowerBattleRoom2_MapScripts:: @ 8248EE8
	map_script 3, BattleFrontier_BattleTowerBattleRoom2_MapScript1_248EF8
	map_script 4, BattleFrontier_BattleTowerBattleRoom2_MapScript2_248F33
	map_script 2, BattleFrontier_BattleTowerBattleRoom2_MapScript2_248F43
	.byte 0

BattleFrontier_BattleTowerBattleRoom2_MapScript1_248EF8: @ 8248EF8
	compare VAR_0x40CE, 2
	call_if 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_248F0F
	compare VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_248F2F
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_248F0F:: @ 8248F0F
	setvar VAR_0x8004, 14
	special sub_8161F74
	checkplayergender
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_248F29
	setvar VAR_OBJ_GFX_ID_F, 0
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_248F29:: @ 8248F29
	setvar VAR_OBJ_GFX_ID_F, 89
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_248F2F:: @ 8248F2F
	special sub_813A76C
	return

BattleFrontier_BattleTowerBattleRoom2_MapScript2_248F33: @ 8248F33
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_248F3D
	.2byte 0

BattleFrontier_BattleTowerBattleRoom2_EventScript_248F3D:: @ 8248F3D
	hideobjectat 255, BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM_2
	end

BattleFrontier_BattleTowerBattleRoom2_MapScript2_248F43: @ 8248F43
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_248F4D
	.2byte 0

BattleFrontier_BattleTowerBattleRoom2_EventScript_248F4D:: @ 8248F4D
	setvar VAR_TEMP_0, 1
	applymovement 5, BattleFrontier_BattleTowerBattleRoom2_Movement_249518
	applymovement 6, BattleFrontier_BattleTowerBattleRoom2_Movement_24951E
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_248FB4
	applymovement 2, BattleFrontier_BattleTowerBattleRoom2_Movement_24953E
	applymovement 3, BattleFrontier_BattleTowerBattleRoom2_Movement_24953E
	waitmovement 0
	applymovement 5, BattleFrontier_BattleTowerBattleRoom2_Movement_249524
	applymovement 6, BattleFrontier_BattleTowerBattleRoom2_Movement_249524
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_81A1780
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_248FB4:: @ 8248FB4
	setvar VAR_0x8004, 3
	special sub_8161F74
	addobject 1
	addobject 4
	applymovement 1, BattleFrontier_BattleTowerBattleRoom2_Movement_249528
	applymovement 4, BattleFrontier_BattleTowerBattleRoom2_Movement_24952E
	waitmovement 0
	compare VAR_0x40CE, 3
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_249026
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special sub_8161F74
	delay 15
	applymovement 1, BattleFrontier_BattleTowerBattleRoom2_Movement_249545
	waitmovement 0
	msgbox 0x2021fc4, 4
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special sub_8161F74
	applymovement 4, BattleFrontier_BattleTowerBattleRoom2_Movement_249545
	waitmovement 0
	msgbox 0x2021fc4, 4
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249069

BattleFrontier_BattleTowerBattleRoom2_EventScript_249026:: @ 8249026
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special sub_8161F74
	delay 15
	applymovement 1, BattleFrontier_BattleTowerBattleRoom2_Movement_249545
	waitmovement 0
	messageautoscroll 0x2021fc4
	waitmessage
	delay 48
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special sub_8161F74
	applymovement 4, BattleFrontier_BattleTowerBattleRoom2_Movement_249545
	waitmovement 0
	messageautoscroll 0x2021fc4
	waitmessage
	delay 48

BattleFrontier_BattleTowerBattleRoom2_EventScript_249069:: @ 8249069
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_24210E
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2490AA

BattleFrontier_BattleTowerBattleRoom2_EventScript_24907E:: @ 824907E
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special sub_8161F74
	setvar VAR_0x8004, 3
	special sub_813BF7C
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_2421B8

BattleFrontier_BattleTowerBattleRoom2_EventScript_2490AA:: @ 82490AA
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_241EBA
	setvar VAR_0x8004, 4
	special sub_8161F74
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom2_EventScript_2492AF
	applymovement 4, BattleFrontier_BattleTowerBattleRoom2_Movement_249534
	applymovement 1, BattleFrontier_BattleTowerBattleRoom2_Movement_249539
	waitmovement 0
	removeobject 1
	removeobject 4
	applymovement 2, BattleFrontier_BattleTowerBattleRoom2_Movement_24953E
	applymovement 3, BattleFrontier_BattleTowerBattleRoom2_Movement_24953E
	waitmovement 0
	applymovement 5, BattleFrontier_BattleTowerBattleRoom2_Movement_249524
	applymovement 6, BattleFrontier_BattleTowerBattleRoom2_Movement_249524
	waitmovement 0
	compare VAR_0x40CE, 3
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_249118
	msgbox BattleFrontier_BattleTowerBattleRoom2_Text_242217, 4
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249121

BattleFrontier_BattleTowerBattleRoom2_EventScript_249118:: @ 8249118
	messageautoscroll BattleFrontier_BattleTowerBattleRoom2_Text_242217
	waitmessage
	delay 48

BattleFrontier_BattleTowerBattleRoom2_EventScript_249121:: @ 8249121
	special LoadPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special sub_81A1780
	compare VAR_0x40CE, 3
	call_if 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249514
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleTowerBattleRoom2_EventScript_249143:: @ 8249143
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_2492FD
	compare VAR_0x40CE, 3
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_249283
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_2491B1
	multichoice 19, 4, 103, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249283
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2491E7
	case 2, BattleFrontier_BattleTowerBattleRoom2_EventScript_249223
	case 3, BattleFrontier_BattleTowerBattleRoom2_EventScript_249251
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_2491B1:: @ 82491B1
	multichoice 20, 6, 104, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249283
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249223
	case 2, BattleFrontier_BattleTowerBattleRoom2_EventScript_249251
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_2491E7:: @ 82491E7
	message BattleFrontier_BattleTowerBattleRoom2_Text_2423A3
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249219
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_249219:: @ 8249219
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_23E8B4
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_249223:: @ 8249223
	msgbox BattleFrontier_BattleTowerBattleRoom2_Text_2423FC, 5
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2492DB
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_249251:: @ 8249251
	message BattleFrontier_BattleTowerBattleRoom2_Text_24244C
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_24907E
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143

BattleFrontier_BattleTowerBattleRoom2_EventScript_249283:: @ 8249283
	closemessage
	clearflag FLAG_0x002
	applymovement 5, BattleFrontier_BattleTowerBattleRoom2_Movement_249526
	applymovement 6, BattleFrontier_BattleTowerBattleRoom2_Movement_249526
	waitmovement 0
	applymovement 2, BattleFrontier_BattleTowerBattleRoom2_Movement_249541
	applymovement 3, BattleFrontier_BattleTowerBattleRoom2_Movement_249541
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_248FB4
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2492AF:: @ 82492AF
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special sub_8161F74
	setvar VAR_0x8004, 3
	special sub_813BF7C
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_2421B8

BattleFrontier_BattleTowerBattleRoom2_EventScript_2492DB:: @ 82492DB
	message BattleFrontier_BattleTowerBattleRoom2_Text_242426
	waitmessage
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 2
	special sub_8161F74
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special sub_81A1780
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2492FD:: @ 82492FD
	compare VAR_0x40CE, 3
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_24937E
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249354
	case 2, BattleFrontier_BattleTowerBattleRoom2_EventScript_24935B
	case 3, BattleFrontier_BattleTowerBattleRoom2_EventScript_249362
	case 4, BattleFrontier_BattleTowerBattleRoom2_EventScript_249369
	case 5, BattleFrontier_BattleTowerBattleRoom2_EventScript_249370
	case 6, BattleFrontier_BattleTowerBattleRoom2_EventScript_249377

BattleFrontier_BattleTowerBattleRoom2_EventScript_249354:: @ 8249354
	message BattleFrontier_BattleTowerBattleRoom2_Text_249547
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_24935B:: @ 824935B
	message BattleFrontier_BattleTowerBattleRoom2_Text_249578
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_249362:: @ 8249362
	message BattleFrontier_BattleTowerBattleRoom2_Text_2495A9
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_249369:: @ 8249369
	message BattleFrontier_BattleTowerBattleRoom2_Text_2495DA
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_249370:: @ 8249370
	message BattleFrontier_BattleTowerBattleRoom2_Text_24960B
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_249377:: @ 8249377
	message BattleFrontier_BattleTowerBattleRoom2_Text_24963C
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_24937E:: @ 824937E
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2493CA
	case 2, BattleFrontier_BattleTowerBattleRoom2_EventScript_2493D6
	case 3, BattleFrontier_BattleTowerBattleRoom2_EventScript_2493E2
	case 4, BattleFrontier_BattleTowerBattleRoom2_EventScript_2493EE
	case 5, BattleFrontier_BattleTowerBattleRoom2_EventScript_2493FA
	case 6, BattleFrontier_BattleTowerBattleRoom2_EventScript_249406

BattleFrontier_BattleTowerBattleRoom2_EventScript_2493CA:: @ 82493CA
	message BattleFrontier_BattleTowerBattleRoom2_Text_249547
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2493D6:: @ 82493D6
	message BattleFrontier_BattleTowerBattleRoom2_Text_249578
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2493E2:: @ 82493E2
	message BattleFrontier_BattleTowerBattleRoom2_Text_2495A9
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2493EE:: @ 82493EE
	message BattleFrontier_BattleTowerBattleRoom2_Text_2495DA
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2493FA:: @ 82493FA
	message BattleFrontier_BattleTowerBattleRoom2_Text_24960B
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_249406:: @ 8249406
	message BattleFrontier_BattleTowerBattleRoom2_Text_24963C
	waitmessage
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249417
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_249412:: @ 8249412
	waitmessage
	delay 48
	return

BattleFrontier_BattleTowerBattleRoom2_EventScript_249417:: @ 8249417
	checkflag FLAG_0x002
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_249457
	multichoice 19, 6, 105, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249483
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2494A8
	case 2, BattleFrontier_BattleTowerBattleRoom2_EventScript_2494DD
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_2494DD
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_249457:: @ 8249457
	multichoice 20, 8, 106, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom2_EventScript_249483
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_2494DD
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_2494DD
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_249483:: @ 8249483
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	message gText_LinkStandby3
	waitmessage
	special sub_813B568
	waitstate
	compare VAR_RESULT, 0
	goto_if 5, BattleFrontier_BattleTowerBattleRoom2_EventScript_24907E
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249412
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2494A8:: @ 82494A8
	message BattleFrontier_BattleTowerBattleRoom2_Text_2423A3
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	case 127, BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	call BattleFrontier_BattleTowerBattleRoom2_EventScript_23E8B4
	setflag FLAG_0x002
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2494DD:: @ 82494DD
	message BattleFrontier_BattleTowerBattleRoom2_Text_24244C
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerBattleRoom2_EventScript_2494FA
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_249143
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_2494FA:: @ 82494FA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	message gText_LinkStandby3
	waitmessage
	special sub_813B568
	waitstate
	goto BattleFrontier_BattleTowerBattleRoom2_EventScript_24907E
	end

BattleFrontier_BattleTowerBattleRoom2_EventScript_249514:: @ 8249514
	special sub_813B534
	return

BattleFrontier_BattleTowerBattleRoom2_Movement_249518: @ 8249518
	step_up
	step_up
	step_up
	step_up
	step_03
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_24951E: @ 824951E
	step_left
	step_up
	step_up
	step_up
	step_03
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249524: @ 8249524
	step_02
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249526: @ 8249526
	step_28
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249528: @ 8249528
	step_down
	step_down
	step_down
	step_down
	step_02
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_24952E: @ 824952E
	step_right
	step_down
	step_down
	step_down
	step_02
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249534: @ 8249534
	step_up
	step_up
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249539: @ 8249539
	step_up
	step_up
	step_up
	step_up
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_24953E: @ 824953E
	step_right
	step_right
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249541: @ 8249541
	step_left
	step_left
	step_28
	step_end

BattleFrontier_BattleTowerBattleRoom2_Movement_249545: @ 8249545
	step_1f
	step_end

BattleFrontier_BattleTowerBattleRoom2_Text_249547: @ 8249547
	.string "The 2nd set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_249578: @ 8249578
	.string "The 3rd set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_2495A9: @ 82495A9
	.string "The 4th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_2495DA: @ 82495DA
	.string "The 5th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_24960B: @ 824960B
	.string "The 6th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_24963C: @ 824963C
	.string "The 7th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom2_Text_24966D: @ 824966D
	.string "The 2nd set of opponents is next.\n"
	.string "Do your best!$"

BattleFrontier_BattleTowerBattleRoom2_Text_24969D: @ 824969D
	.string "The 3rd set of opponents is next.\n"
	.string "Do your best!$"

BattleFrontier_BattleTowerBattleRoom2_Text_2496CD: @ 82496CD
	.string "The 4th set of opponents is next.\n"
	.string "Do your best!$"

BattleFrontier_BattleTowerBattleRoom2_Text_2496FD: @ 82496FD
	.string "The 5th set of opponents is next.\n"
	.string "Do your best!$"

BattleFrontier_BattleTowerBattleRoom2_Text_24972D: @ 824972D
	.string "The 6th set of opponents is next.\n"
	.string "Do your best!$"

BattleFrontier_BattleTowerBattleRoom2_Text_24975D: @ 824975D
	.string "The 7th set of opponents is next.\n"
	.string "Do your best!$"

gText_LinkStandby3:: @ 824978D
	.string "Link standby…$"

gText_YourPartnerHasRetired:: @ 824979B
	.string "Your partner has retired.\p"
	.string "Your BATTLE ROOM challenge\n"
	.string "will be canceled.$"
