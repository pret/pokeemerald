BattleFrontier_BattlePointExchangeServiceCorner_MapScripts:: @ 825F070
	.byte 0

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071:: @ 825F071
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F7FA, MSGBOX_DEFAULT
	special sub_813A958
	return

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D:: @ 825F07D
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF12, MSGBOX_DEFAULT
	special sub_813A988
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A:: @ 825F08A
	specialvar VAR_TEMP_1, sub_813AA04
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0C9
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE86, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	compare VAR_TEMP_2, 2
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0C9:: @ 825F0C9
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F12A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5:: @ 825F0E5
	checkdecorspace VAR_0x8009
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F11D
	copyvar VAR_0x8004, VAR_0x8008
	special sub_813A9A4
	givedecoration VAR_0x8009
	special sub_813A8FC
	playse SE_REGI
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE45, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F11D:: @ 825F11D
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEB9, MSGBOX_DEFAULT
	special sub_813A988
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F12A:: @ 825F12A
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F166
	copyvar VAR_0x8004, VAR_0x8008
	special sub_813A9A4
	giveitem VAR_0x8009, 1
	special sub_813A8FC
	playse SE_REGI
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE72, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 2
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F166:: @ 825F166
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEE3, MSGBOX_DEFAULT
	special sub_813A988
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F173:: @ 825F173
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185:: @ 825F185
	setvar VAR_0x8004, 3
	special sub_813AA18
	special sub_813A128
	waitstate
	special sub_813AA44
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F21E
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F241
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F264
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F287
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2AA
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2CD
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2F0
	case 7, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F313
	case 8, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F336
	case 9, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F359
	case 10, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case 127, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F21E:: @ 825F21E
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8B6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, 75
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F241:: @ 825F241
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8E6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, 103
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F264:: @ 825F264
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F917, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, 87
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F287:: @ 825F287
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F949, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 79
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2AA:: @ 825F2AA
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F979, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 84
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2CD:: @ 825F2CD
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9A9, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 85
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2F0:: @ 825F2F0
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9DB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 86
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F313:: @ 825F313
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA0A, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, 80
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F336:: @ 825F336
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA3D, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, 81
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F359:: @ 825F359
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA70, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, 82
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F37C:: @ 825F37C
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E:: @ 825F38E
	setvar VAR_0x8004, 4
	special sub_813AA18
	special sub_813A128
	waitstate
	special sub_813AA44
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F3F0
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F413
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F436
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F459
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F47C
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case 127, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F3F0:: @ 825F3F0
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAA2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, 113
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F413:: @ 825F413
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAD2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, 111
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F436:: @ 825F436
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB03, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, 114
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F459:: @ 825F459
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB35, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, 115
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F47C:: @ 825F47C
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB68, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, 116
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F49F:: @ 825F49F
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1:: @ 825F4B1
	setvar VAR_0x8004, 5
	special sub_813AA18
	special sub_813A128
	waitstate
	special sub_813AA44
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F51E
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F541
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F564
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F587
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5AA
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5CD
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case 127, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F51E:: @ 825F51E
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB9B, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 64
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F541:: @ 825F541
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBC7, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 67
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F564:: @ 825F564
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBF3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 65
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F587:: @ 825F587
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC1C, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 70
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5AA:: @ 825F5AA
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC45, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 66
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5CD:: @ 825F5CD
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC70, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 63
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5F0:: @ 825F5F0
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602:: @ 825F602
	setvar VAR_0x8004, 6
	special sub_813AA18
	special sub_813A128
	waitstate
	special sub_813AA44
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F690
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6B3
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6D6
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6F9
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F71C
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F73F
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F762
	case 7, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F785
	case 8, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7A8
	case 9, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case 127, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F690:: @ 825F690
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE17, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 200
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6B3:: @ 825F6B3
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCCB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 180
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6D6:: @ 825F6D6
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCFA, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 183
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6F9:: @ 825F6F9
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD29, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, 185
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F71C:: @ 825F71C
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC9A, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 179
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F73F:: @ 825F73F
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD59, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 186
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F762:: @ 825F762
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD89, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 187
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F785:: @ 825F785
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDB9, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 196
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7A8:: @ 825F7A8
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDE8, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 198
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7CB:: @ 825F7CB
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_260099, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7D4:: @ 825F7D4
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_26002E, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7DD:: @ 825F7DD
	lock
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FFD0, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7E8:: @ 825F7E8
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF5D, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7F1:: @ 825F7F1
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_26012D, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F7FA: @ 825F7FA
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F890: @ 825F890
	.string "Please choose a prize from this list.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8B6: @ 825F8B6
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8E6: @ 825F8E6
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F917: @ 825F917
	.string "You've chosen the SMOOCHUM DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F949: @ 825F949
	.string "You've chosen the TOGEPI DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F979: @ 825F979
	.string "You've chosen the MEOWTH DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9A9: @ 825F9A9
	.string "You've chosen the CLEFAIRY DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9DB: @ 825F9DB
	.string "You've chosen the DITTO DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA0A: @ 825FA0A
	.string "You've chosen the CYNDAQUIL DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA3D: @ 825FA3D
	.string "You've chosen the CHIKORITA DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA70: @ 825FA70
	.string "You've chosen the TOTODILE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAA2: @ 825FAA2
	.string "You've chosen the LAPRAS DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAD2: @ 825FAD2
	.string "You've chosen the SNORLAX DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB03: @ 825FB03
	.string "You've chosen the VENUSAUR DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB35: @ 825FB35
	.string "You've chosen the CHARIZARD DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB68: @ 825FB68
	.string "You've chosen the BLASTOISE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB9B: @ 825FB9B
	.string "You've chosen the PROTEIN.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBC7: @ 825FBC7
	.string "You've chosen the CALCIUM.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBF3: @ 825FBF3
	.string "You've chosen the IRON.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC1C: @ 825FC1C
	.string "You've chosen the ZINC.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC45: @ 825FC45
	.string "You've chosen the CARBOS.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC70: @ 825FC70
	.string "You've chosen the HP UP.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC9A: @ 825FC9A
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCCB: @ 825FCCB
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCFA: @ 825FCFA
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD29: @ 825FD29
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD59: @ 825FD59
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD89: @ 825FD89
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDB9: @ 825FDB9
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDE8: @ 825FDE8
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE17: @ 825FE17
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE45: @ 825FE45
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE72: @ 825FE72
	.string "Here is your prize!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE86: @ 825FE86
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEB9: @ 825FEB9
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEE3: @ 825FEE3
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF12: @ 825FF12
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF5D: @ 825FF5D
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FFD0: @ 825FFD0
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26002E: @ 826002E
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260099: @ 8260099
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26012D: @ 826012D
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2601AA:: @ 82601AA
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2601D0:: @ 82601D0
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260201:: @ 8260201
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26022F:: @ 826022F
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26025B:: @ 826025B
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260287:: @ 8260287
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2602B5:: @ 82602B5
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2602E0:: @ 82602E0
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26030F:: @ 826030F
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26033E:: @ 826033E
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C:: @ 826036C
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260397:: @ 8260397
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2603BE:: @ 82603BE
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2603E6:: @ 82603E6
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26040E:: @ 826040E
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260436:: @ 8260436
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26045C:: @ 826045C
	.string "Raises the HP of one POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26047A:: @ 826047A
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2604AC:: @ 82604AC
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2604D8:: @ 82604D8
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26050F:: @ 826050F
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260542:: @ 8260542
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260575:: @ 8260575
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2605A8:: @ 82605A8
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2605E2:: @ 82605E2
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260613:: @ 8260613
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
