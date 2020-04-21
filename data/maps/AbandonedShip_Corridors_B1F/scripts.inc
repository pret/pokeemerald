AbandonedShip_Corridors_B1F_MapScripts:: @ 8237D84
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume: @ 8237D8F
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad: @ 8237D98
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom:: @ 8237DAB
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, 1
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom:: @ 8237DB5
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, 1
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM:: @ 8237DBF
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor:: @ 8237DC8
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked:: @ 8237DFF
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked:: @ 8237E09
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan:: @ 8237E13
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro: @ 8237E2A
	.string "When we go out to sea, we SAILORS\n"
	.string "always bring our POKéMON.\l"
	.string "How about a quick battle?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat: @ 8237E80
	.string "Whoops, I'm sunk!$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle: @ 8237E92
	.string "The ship's bottom has sunk into the\n"
	.string "depths.\p"
	.string "If a POKéMON knew how to go underwater,\n"
	.string "we might make some progress…$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip: @ 8237F03
	.string "Yay!\n"
	.string "It's a ship!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked: @ 8237F15
	.string "The door is locked.\p"
	.string "“STORAGE” is painted on the door.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey: @ 8237F4B
	.string "{PLAYER} inserted and turned the\n"
	.string "STORAGE KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"

AbandonedShip_Text_TheDoorIsOpen: @ 8237FA5
	.string "The door is open.$"

