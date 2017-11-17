MirageTower_4F_MapScripts:: @ 823AD47
	.byte 0

MirageTower_4F_EventScript_23AD48:: @ 823AD48
	lock
	faceplayer
	msgbox MirageTower_4F_Text_23ADF9, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MirageTower_4F_EventScript_23AD7F
	giveitem_std ITEM_ROOT_FOSSIL
	closemessage
	setflag FLAG_0x3C3
	setflag FLAG_0x3C4
	removeobject 1
	delay 30
	setflag FLAG_0x14F
	goto MirageTower_4F_EventScript_23ADCA
	end

MirageTower_4F_EventScript_23AD7F:: @ 823AD7F
	msgbox MirageTower_4F_Text_23AE79, 4
	release
	end

MirageTower_4F_EventScript_23AD89:: @ 823AD89
	lock
	faceplayer
	msgbox MirageTower_4F_Text_23AE98, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MirageTower_4F_EventScript_23ADC0
	giveitem_std ITEM_CLAW_FOSSIL
	closemessage
	setflag FLAG_0x3C4
	setflag FLAG_0x3C3
	removeobject 2
	delay 30
	setflag FLAG_0x150
	goto MirageTower_4F_EventScript_23ADCA
	end

MirageTower_4F_EventScript_23ADC0:: @ 823ADC0
	msgbox MirageTower_4F_Text_23AF18, 4
	release
	end

MirageTower_4F_EventScript_23ADCA:: @ 823ADCA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special sub_8139560
	waitstate
	special sub_81BE994
	waitstate
	setvar VAR_0x40CB, 1
	clearflag FLAG_0x078
	warp ROUTE_111, 255, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_23ADF9: @ 823ADF9
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_23AE79: @ 823AE79
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_23AE98: @ 823AE98
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_23AF18: @ 823AF18
	.string "{PLAYER} left the CLAW FOSSIL alone.$"

