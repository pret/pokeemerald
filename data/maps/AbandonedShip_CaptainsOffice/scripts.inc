AbandonedShip_CaptainsOffice_MapScripts:: @ 82387E1
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_2387E2:: @ 82387E2
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_23881A
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_CaptainsOffice_EventScript_238810
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, AbandonedShip_CaptainsOffice_EventScript_23881A
	msgbox AbandonedShip_CaptainsOffice_Text_238824, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_238810:: @ 8238810
	msgbox AbandonedShip_CaptainsOffice_Text_23889D, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_23881A:: @ 823881A
	msgbox AbandonedShip_CaptainsOffice_Text_238918, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_238824: @ 8238824
	.string "I'm investigating this ship on behalf\n"
	.string "of CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

AbandonedShip_CaptainsOffice_Text_23889D: @ 823889D
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

AbandonedShip_CaptainsOffice_Text_238918: @ 8238918
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"

