LittlerootTown_MaysHouse_1F_EventObjects: @ 852D36C
	object_event 1, EVENT_OBJ_GFX_MOM, 0, 8, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_2929C5, 759
	object_event 2, EVENT_OBJ_GFX_VIGAROTH_FACING_AWAY, 0, 6, 5, 3, MOVEMENT_TYPE_WALK_IN_PLACE_UP, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_292ABA, 754
	object_event 3, EVENT_OBJ_GFX_VIGAROTH_CARRYING_BOX, 0, 9, 3, 3, MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT, 3, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_292ACD, 755
	object_event 4, EVENT_OBJ_GFX_WOMAN_5, 0, 8, 7, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_1F89F3, 785
	object_event 5, EVENT_OBJ_GFX_NORMAN, 0, 5, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, 0x0, 734
	object_event 6, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 9, 5, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 1, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A3D, 736
	object_event 7, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL, 0, 2, 8, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, 746

LittlerootTown_MaysHouse_1F_MapWarps: @ 852D414
	warp_def 1, 8, 0, 0, MAP_LITTLEROOT_TOWN
	warp_def 2, 8, 0, 0, MAP_LITTLEROOT_TOWN
	warp_def 2, 2, 0, 0, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F

LittlerootTown_MaysHouse_1F_MapCoordEvents: @ 852D42C
	coord_event 2, 8, 0, VAR_0x4092, 4, LittlerootTown_MaysHouse_1F_EventScript_1F8A4C
	coord_event 1, 3, 0, VAR_0x408D, 2, LittlerootTown_MaysHouse_1F_EventScript_1F8A67
	coord_event 2, 4, 0, VAR_0x408D, 2, LittlerootTown_MaysHouse_1F_EventScript_1F8A73
	coord_event 3, 3, 0, VAR_0x408D, 2, LittlerootTown_MaysHouse_1F_EventScript_1F8A7F

LittlerootTown_MaysHouse_1F_MapEvents:: @ 852D46C
	map_events LittlerootTown_MaysHouse_1F_EventObjects, LittlerootTown_MaysHouse_1F_MapWarps, LittlerootTown_MaysHouse_1F_MapCoordEvents, 0x0

