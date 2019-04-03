Route123_BerryMastersHouse_MapScripts:: @ 826F83B
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_OnTransition
	.byte 0

Route123_BerryMastersHouse_OnTransition: @ 826F841
	setflag FLAG_LANDMARK_BERRY_MASTERS_HOUSE
	end

Route123_BerryMastersHouse_EventScript_26F845:: @ 826F845
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_26F8B6
	msgbox Route123_BerryMastersHouse_Text_2A7386, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	msgbox Route123_BerryMastersHouse_Text_2A7428, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox Route123_BerryMastersHouse_Text_2A7445, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_26F8B6:: @ 826F8B6
	msgbox Route123_BerryMastersHouse_Text_2A749E, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_26F8C0:: @ 826F8C0
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_26FA6F
	msgbox Route123_BerryMastersHouse_Text_2A74E6, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F909
	compare VAR_RESULT, 0
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F8F7
	end

Route123_BerryMastersHouse_EventScript_26F8F7:: @ 826F8F7
	msgbox Route123_BerryMastersHouse_Text_2A7682, MSGBOX_DEFAULT
	msgbox Route123_BerryMastersHouse_Text_2A761B, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_26F909:: @ 826F909
	compare VAR_0x8004, 0
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F94C
	compare VAR_0x8004, 1
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F97A
	compare VAR_0x8004, 2
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F9AB
	compare VAR_0x8004, 3
	goto_if_eq Route123_BerryMastersHouse_EventScript_26F9DC
	compare VAR_0x8004, 4
	goto_if_eq Route123_BerryMastersHouse_EventScript_26FA0D
	compare VAR_0x8004, 5
	goto_if_eq Route123_BerryMastersHouse_EventScript_26FA3E
	end

Route123_BerryMastersHouse_EventScript_26F94C:: @ 826F94C
	msgbox Route123_BerryMastersHouse_Text_2A75D0, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_26FA79
	release
	end

Route123_BerryMastersHouse_EventScript_26F97A:: @ 826F97A
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, MSGBOX_DEFAULT
	giveitem_std ITEM_SPELON_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SPELON_BERRY
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26F9AB:: @ 826F9AB
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, MSGBOX_DEFAULT
	giveitem_std ITEM_PAMTRE_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PAMTRE_BERRY
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26F9DC:: @ 826F9DC
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, MSGBOX_DEFAULT
	giveitem_std ITEM_WATMEL_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_WATMEL_BERRY
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA0D:: @ 826FA0D
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, MSGBOX_DEFAULT
	giveitem_std ITEM_DURIN_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_DURIN_BERRY
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA3E:: @ 826FA3E
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_26F94C
	msgbox Route123_BerryMastersHouse_Text_2A7583, MSGBOX_DEFAULT
	giveitem_std ITEM_BELUE_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BELUE_BERRY
	goto Route123_BerryMastersHouse_EventScript_26FA79
	end

Route123_BerryMastersHouse_EventScript_26FA6F:: @ 826FA6F
	msgbox Route123_BerryMastersHouse_Text_2A761B, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_26FA79:: @ 826FA79
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
	msgbox Route123_BerryMastersHouse_Text_2A761B, MSGBOX_DEFAULT
	release
	end

