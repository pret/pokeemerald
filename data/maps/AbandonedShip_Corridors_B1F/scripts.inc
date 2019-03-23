AbandonedShip_Corridors_B1F_MapScripts:: @ 8237D84
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_MapScript1_237D8F
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_MapScript1_237D98
	.byte 0

AbandonedShip_Corridors_B1F_MapScript1_237D8F: @ 8237D8F
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_Corridors_B1F_MapScript1_237D98: @ 8237D98
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237DAB
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237DB5
	end

AbandonedShip_Corridors_B1F_EventScript_237DAB:: @ 8237DAB
	setmetatile 11, 4, 563, 1
	return

AbandonedShip_Corridors_B1F_EventScript_237DB5:: @ 8237DB5
	setmetatile 11, 4, 555, 1
	return

AbandonedShip_Corridors_B1F_EventScript_237DBF:: @ 8237DBF
	msgbox AbandonedShip_Corridors_B1F_Text_237F03, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_237DC8:: @ 8237DC8
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237E09
	checkitem ITEM_STORAGE_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_Corridors_B1F_EventScript_237DFF
	msgbox AbandonedShip_Corridors_B1F_Text_237F4B, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_STORAGE_KEY, 1
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_237DB5
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237DFF:: @ 8237DFF
	msgbox AbandonedShip_Corridors_B1F_Text_237F15, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237E09:: @ 8237E09
	msgbox AbandonedShip_Corridors_B1F_Text_237FA5, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237E13:: @ 8237E13
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_237E2A, AbandonedShip_Corridors_B1F_Text_237E80
	msgbox AbandonedShip_Corridors_B1F_Text_237E92, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_237E2A: @ 8237E2A
	.string "When we go out to sea, we SAILORS\n"
	.string "always bring our POKéMON.\l"
	.string "How about a quick battle?$"

AbandonedShip_Corridors_B1F_Text_237E80: @ 8237E80
	.string "Whoops, I'm sunk!$"

AbandonedShip_Corridors_B1F_Text_237E92: @ 8237E92
	.string "The ship's bottom has sunk into the\n"
	.string "depths.\p"
	.string "If a POKéMON knew how to go underwater,\n"
	.string "we might make some progress…$"

AbandonedShip_Corridors_B1F_Text_237F03: @ 8237F03
	.string "Yay!\n"
	.string "It's a ship!$"

AbandonedShip_Corridors_B1F_Text_237F15: @ 8237F15
	.string "The door is locked.\p"
	.string "“STORAGE” is painted on the door.$"

AbandonedShip_Corridors_B1F_Text_237F4B: @ 8237F4B
	.string "{PLAYER} inserted and turned the\n"
	.string "STORAGE KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"

AbandonedShip_Corridors_B1F_Text_237FA5: @ 8237FA5
AbandonedShip_HiddenFloorCorridors_Text_237FA5: @ 8237FA5
	.string "The door is open.$"

