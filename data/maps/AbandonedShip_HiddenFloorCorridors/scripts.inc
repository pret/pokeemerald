AbandonedShip_HiddenFloorCorridors_MapScripts:: @ 823896C
	map_script 5, AbandonedShip_HiddenFloorCorridors_MapScript1_238977
	map_script 1, AbandonedShip_HiddenFloorCorridors_MapScript1_238980
	.byte 0

AbandonedShip_HiddenFloorCorridors_MapScript1_238977: @ 8238977
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_HiddenFloorCorridors_MapScript1_238980: @ 8238980
	checkflag FLAG_0x0F0
	call_if 0, AbandonedShip_HiddenFloorCorridors_EventScript_2389F1
	checkflag FLAG_0x0F1
	call_if 0, AbandonedShip_HiddenFloorCorridors_EventScript_2389FB
	checkflag FLAG_0x0F2
	call_if 0, AbandonedShip_HiddenFloorCorridors_EventScript_238A05
	checkflag FLAG_0x0F3
	call_if 0, AbandonedShip_HiddenFloorCorridors_EventScript_238A0F
	checkflag FLAG_0x0F0
	call_if 1, AbandonedShip_HiddenFloorCorridors_EventScript_2389C9
	checkflag FLAG_0x0F1
	call_if 1, AbandonedShip_HiddenFloorCorridors_EventScript_2389D3
	checkflag FLAG_0x0F2
	call_if 1, AbandonedShip_HiddenFloorCorridors_EventScript_2389DD
	checkflag FLAG_0x0F3
	call_if 1, AbandonedShip_HiddenFloorCorridors_EventScript_2389E7
	end

AbandonedShip_HiddenFloorCorridors_EventScript_2389C9:: @ 82389C9
	setmetatile 3, 8, 555, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389D3:: @ 82389D3
	setmetatile 6, 8, 555, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389DD:: @ 82389DD
	setmetatile 3, 3, 538, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389E7:: @ 82389E7
	setmetatile 9, 3, 538, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389F1:: @ 82389F1
	setmetatile 3, 8, 563, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389FB:: @ 82389FB
	setmetatile 6, 8, 563, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A05:: @ 8238A05
	setmetatile 3, 3, 564, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A0F:: @ 8238A0F
	setmetatile 9, 3, 564, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A19:: @ 8238A19
	lockall
	checkflag FLAG_0x0F0
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_1_KEY, 1
	compare VAR_RESULT, 0
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238AF5
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_1_KEY, 1
	setflag FLAG_0x0F0
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389C9
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238A50:: @ 8238A50
	lockall
	checkflag FLAG_0x0F1
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_2_KEY, 1
	compare VAR_RESULT, 0
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238AFF
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_2_KEY, 1
	setflag FLAG_0x0F1
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389D3
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238A87:: @ 8238A87
	lockall
	checkflag FLAG_0x0F2
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_4_KEY, 1
	compare VAR_RESULT, 0
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B09
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_4_KEY, 1
	setflag FLAG_0x0F2
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389DD
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238ABE:: @ 8238ABE
	lockall
	checkflag FLAG_0x0F3
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_6_KEY, 1
	compare VAR_RESULT, 0
	goto_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B13
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_6_KEY, 1
	setflag FLAG_0x0F3
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389E7
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238AF5:: @ 8238AF5
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B27, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238AFF:: @ 8238AFF
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B5B, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B09:: @ 8238B09
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B8F, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B13:: @ 8238B13
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BC3, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B1D:: @ 8238B1D
	msgbox AbandonedShip_HiddenFloorCorridors_Text_237FA5, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_Text_238B27: @ 8238B27
	.string "The door is locked.\p"
	.string "“RM. 1” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_238B5B: @ 8238B5B
	.string "The door is locked.\p"
	.string "“RM. 2” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_238B8F: @ 8238B8F
	.string "The door is locked.\p"
	.string "“RM. 4” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_238BC3: @ 8238BC3
	.string "The door is locked.\p"
	.string "“RM. 6” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_238BF7: @ 8238BF7
	.string "{PLAYER} inserted and turned the\n"
	.string "KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"

