LittlerootTown_EventObjects:
	object_event 1, EVENT_OBJ_GFX_OLD_MAN, 0, 26, 22, 3, MOVEMENT_TYPE_NONE, 0, 0, 0, 0, NULL, 0
	object_event 2, EVENT_OBJ_GFX_BIRCHS_BAG, 0, 29, 12, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NULL, FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	object_event 3, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 17, 20, 3, MOVEMENT_TYPE_NONE, 0, 0, 0, 0, NULL, FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 16, 18, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NULL, FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK

LittlerootTown_MapWarps:
	warp_def 16, 18, 3, 0, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 28, 22, 3, 0, MAP_LITTLEROOT_TOWN

LittlerootTown_MapBGEvents:
	bg_event 24, 13, 3, BG_EVENT_PLAYER_FACING_ANY, YamakiTown_HealingShrine
	bg_event 14, 18, 3, BG_EVENT_PLAYER_FACING_ANY, NULL

LittlerootTown_MapEvents::
	map_events LittlerootTown_EventObjects, LittlerootTown_MapWarps, 0x0, LittlerootTown_MapBGEvents

