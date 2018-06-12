LittlerootTown_EventObjects: @ 85276A8
	object_event 1, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 16, 10, 3, 2, 33, 0, 0, 0, LittlerootTown_EventScript_1E8034, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_FAT_MAN, 0, 0, 12, 13, 3, 2, 18, 0, 0, 0, LittlerootTown_EventScript_1E8022, 868, 0, 0
	object_event 3, EVENT_OBJ_GFX_BOY_2, 0, 0, 14, 17, 3, 2, 18, 0, 0, 0, LittlerootTown_EventScript_1E802B, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_MOM, 0, 0, 5, 8, 3, 7, 0, 0, 0, 0, LittlerootTown_EventScript_1E863D, 752, 0, 0
	object_event 5, EVENT_OBJ_GFX_TRUCK, 0, 0, 2, 10, 4, 10, 0, 0, 0, 0, 0x0, 761, 0, 0
	object_event 6, EVENT_OBJ_GFX_TRUCK, 0, 0, 11, 10, 4, 10, 0, 0, 0, 0, 0x0, 762, 0, 0
	object_event 7, EVENT_OBJ_GFX_HIPSTER, 0, 0, 13, 10, 3, 7, 17, 0, 0, 0, 0x0, 794, 0, 0
	object_event 8, EVENT_OBJ_GFX_PROF_BIRCH, 0, 0, 14, 10, 3, 7, 17, 0, 0, 0, 0x0, 795, 0, 0

LittlerootTown_MapWarps: @ 8527768
	warp_def 14, 8, 0, 1, LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 5, 8, 0, 1, LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 7, 16, 0, 0, LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB

LittlerootTown_MapCoordEvents: @ 8527780
	coord_event 10, 1, 3, 0, VAR_0x4050, 0, 0, LittlerootTown_EventScript_1E8091
	coord_event 11, 1, 3, 0, VAR_0x4050, 0, 0, LittlerootTown_EventScript_1E80EF
	coord_event 11, 1, 3, 0, VAR_0x4050, 1, 0, LittlerootTown_EventScript_1E811F
	coord_event 8, 9, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E81F9
	coord_event 9, 9, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E8205
	coord_event 10, 9, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E81E1
	coord_event 11, 9, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E81ED
	coord_event 10, 2, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E81BB
	coord_event 11, 2, 3, 0, VAR_0x4050, 3, 0, LittlerootTown_EventScript_1E81CE

LittlerootTown_MapBGEvents: @ 8527810
	bg_event 15, 13, 0, 0, 0, LittlerootTown_EventScript_1E8151
	bg_event 6, 17, 0, 0, 0, LittlerootTown_EventScript_1E815A
	bg_event 7, 8, 3, 0, 0, LittlerootTown_EventScript_1E8163
	bg_event 12, 8, 3, 0, 0, LittlerootTown_EventScript_1E818F

LittlerootTown_MapEvents:: @ 8527840
	map_events LittlerootTown_EventObjects, LittlerootTown_MapWarps, LittlerootTown_MapCoordEvents, LittlerootTown_MapBGEvents

