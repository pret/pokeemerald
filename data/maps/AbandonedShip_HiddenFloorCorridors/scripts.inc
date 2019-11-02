AbandonedShip_HiddenFloorCorridors_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_MapScript1_238977
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_MapScript1_238980
	.byte 0

AbandonedShip_HiddenFloorCorridors_MapScript1_238977:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_HiddenFloorCorridors_MapScript1_238980:
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389F1
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389FB
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238A05
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238A0F
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389C9
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389D3
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389DD
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_2389E7
	end

AbandonedShip_HiddenFloorCorridors_EventScript_2389C9::
	setmetatile 3, 8, METATILE_InsideShip_InTactDoor1_Bottom, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389D3::
	setmetatile 6, 8, METATILE_InsideShip_InTactDoor1_Bottom, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389DD::
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent1, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389E7::
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent1, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389F1::
	setmetatile 3, 8, METATILE_InsideShip_InTactDoor0_Bottom, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_2389FB::
	setmetatile 6, 8, METATILE_InsideShip_InTactDoor0_Bottom, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A05::
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent0, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A0F::
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent0, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_238A19::
	lockall
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_1_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_238AF5
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_1_KEY, 1
	setflag FLAG_USED_ROOM_1_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389C9
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238A50::
	lockall
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_2_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_238AFF
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_2_KEY, 1
	setflag FLAG_USED_ROOM_2_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389D3
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238A87::
	lockall
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_4_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B09
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_4_KEY, 1
	setflag FLAG_USED_ROOM_4_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389DD
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238ABE::
	lockall
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_238B1D
	checkitem ITEM_ROOM_6_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_238B13
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BF7, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_ROOM_6_KEY, 1
	setflag FLAG_USED_ROOM_6_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_2389E7
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238AF5::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B27, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238AFF::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B5B, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B09::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238B8F, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B13::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_238BC3, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_238B1D::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_237FA5, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_Text_238B27:
	.string "문이 잠겨 있다\p"
	.string "문에는 1호실이라고 쓰여 있다$"

AbandonedShip_HiddenFloorCorridors_Text_238B5B:
	.string "문이 잠겨 있다\p"
	.string "문에는 2호실이라고 쓰여 있다$"

AbandonedShip_HiddenFloorCorridors_Text_238B8F:
	.string "문이 잠겨 있다\p"
	.string "문에는 4호실이라고 쓰여 있다$"

AbandonedShip_HiddenFloorCorridors_Text_238BC3:
	.string "문이 잠겨 있다\p"
	.string "문에는 6호실이라고 쓰여 있다$"

AbandonedShip_HiddenFloorCorridors_Text_238BF7:
	.string "{PLAYER}{K_EUNNEUN}\n"
	.string "열쇠를 썼다!\p"
	.string "열쇠 구멍에 꽂은 열쇠는\n"
	.string "빠지지 않게 되었지만\l"
	.string "문은 열렸다!$"

