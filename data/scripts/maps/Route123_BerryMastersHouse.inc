Route123_BerryMastersHouse_MapScripts:: @ 826F83B
	map_script 3, Route123_BerryMastersHouse_MapScript1_26F841
	.byte 0

Route123_BerryMastersHouse_MapScript1_26F841: @ 826F841
	setflag FLAG_0x8C3
	end

Route123_BerryMastersHouse_EventScript_26F845:: @ 826F845
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_0x92D
	goto_eq Route123_BerryMastersHouse_EventScript_26F8B6
	msgbox Route123_BerryMastersHouse_Text_2A7386, 4
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x92D
	msgbox Route123_BerryMastersHouse_Text_2A7428, 4
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	msgbox Route123_BerryMastersHouse_Text_2A7445, 4
	release
	end

Route123_BerryMastersHouse_EventScript_26F8B6:: @ 826F8B6
	msgbox Route123_BerryMastersHouse_Text_2A749E, 4
	release
	end

Route123_BerryMastersHouse_EventScript_26F8C0:: @ 826F8C0
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_0x931
	goto_eq Route123_BerryMastersHouse_EventScript_26FA6F
	msgbox Route123_BerryMastersHouse_Text_2A74E6, 4
	setvar VAR_0x8004, 13
	call Route123_BerryMastersHouse_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route123_BerryMastersHouse_EventScript_26F909
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_26F8F7
	end

Route123_BerryMastersHouse_EventScript_26F8F7:: @ 826F8F7
	msgbox Route123_BerryMastersHouse_Text_2A7682, 4
	msgbox Route123_BerryMastersHouse_Text_2A761B, 4
	release
	end

Route123_BerryMastersHouse_EventScript_26F909:: @ 826F909
	compare_var_to_value VAR_0x8004, 0
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	compare_var_to_value VAR_0x8004, 1
	goto_eq Route123_BerryMastersHouse_EventScript_26F97A
	compare_var_to_value VAR_0x8004, 2
	goto_eq Route123_BerryMastersHouse_EventScript_26F9AB
	compare_var_to_value VAR_0x8004, 3
	goto_eq Route123_BerryMastersHouse_EventScript_26F9DC
	compare_var_to_value VAR_0x8004, 4
	goto_eq Route123_BerryMastersHouse_EventScript_26FA0D
	compare_var_to_value VAR_0x8004, 5
	goto_eq Route123_BerryMastersHouse_EventScript_26FA3E
	end

Route123_BerryMastersHouse_EventScript_26F94C:: @ 826F94C
	msgbox Route123_BerryMastersHouse_Text_2A75D0, 4
	random 10
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	goto Route123_BerryMastersHouse_EventScript_26FA79
	release
	end

Route123_BerryMastersHouse_EventScript_26F97A:: @ 826F97A
	checkflag FLAG_0x0F8
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, 4
	giveitem_std ITEM_SPELON_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x0F8
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26F9AB:: @ 826F9AB
	checkflag FLAG_0x0F9
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, 4
	giveitem_std ITEM_PAMTRE_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x0F9
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26F9DC:: @ 826F9DC
	checkflag FLAG_0x0FA
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, 4
	giveitem_std ITEM_WATMEL_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x0FA
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA0D:: @ 826FA0D
	checkflag FLAG_0x0FB
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, 4
	giveitem_std ITEM_DURIN_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x0FB
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA3E:: @ 826FA3E
	checkflag FLAG_0x0FC
	goto_eq Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, 4
	giveitem_std ITEM_BELUE_BERRY
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route123_BerryMastersHouse_EventScript_272054
	setflag FLAG_0x0FC
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA6F:: @ 826FA6F
	msgbox Route123_BerryMastersHouse_Text_2A761B, 4
	release
	end

Route123_BerryMastersHouse_EventScript_26FA79:: @ 826FA79
	setflag FLAG_0x931
	msgbox Route123_BerryMastersHouse_Text_2A761B, 4
	release
	end

