LittlerootTown_MaysHouse_1F_MapObjects: @ 852D36C
	object_event 1, MAP_OBJ_GFX_MOM, 0, 0, 8, 6, 3, 9, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_2929C5, 759, 0, 0
	object_event 2, MAP_OBJ_GFX_VIGAROTH_FACING_AWAY, 0, 0, 6, 5, 3, 65, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_292ABA, 754, 0, 0
	object_event 3, MAP_OBJ_GFX_VIGAROTH_CARRYING_BOX, 0, 0, 9, 3, 3, 27, 3, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_292ACD, 755, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_5, 0, 0, 8, 7, 3, 9, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_1F89F3, 785, 0, 0
	object_event 5, MAP_OBJ_GFX_NORMAN, 0, 0, 5, 6, 3, 10, 17, 0, 0, 0, 0x0, 734, 0, 0
	object_event 6, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 9, 5, 3, 5, 17, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A3D, 736, 0, 0
	object_event 7, MAP_OBJ_GFX_RIVAL_MAY_NORMAL, 0, 0, 2, 8, 3, 7, 17, 0, 0, 0, 0x0, 746, 0, 0

LittlerootTown_MaysHouse_1F_MapWarps: @ 852D414
	warp_def 1, 8, 0, 0, LITTLEROOT_TOWN
	warp_def 2, 8, 0, 0, LITTLEROOT_TOWN
	warp_def 2, 2, 0, 0, LITTLEROOT_TOWN_MAYS_HOUSE_2F

LittlerootTown_MaysHouse_1F_MapCoordEvents: @ 852D42C
	coord_event 2, 8, 0, 0, VAR_0x4092, 4, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A4C
	coord_event 1, 3, 0, 0, VAR_0x408D, 2, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A67
	coord_event 2, 4, 0, 0, VAR_0x408D, 2, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A73
	coord_event 3, 3, 0, 0, VAR_0x408D, 2, 0, LittlerootTown_MaysHouse_1F_EventScript_1F8A7F

LittlerootTown_MaysHouse_1F_MapEvents:: @ 852D46C
	map_events LittlerootTown_MaysHouse_1F_MapObjects, LittlerootTown_MaysHouse_1F_MapWarps, LittlerootTown_MaysHouse_1F_MapCoordEvents, 0x0

