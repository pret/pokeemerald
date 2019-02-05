LittlerootTown_EventObjects::
	object_event 1, EVENT_OBJ_GFX_TWIN, 0, 18, 10, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, LittlerootTown_EventScript_1E8034, 0
	object_event 2, EVENT_OBJ_GFX_EXPERT_F, 0, 14, 31, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, LittlerootTown_EventScript_1E8022, FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	object_event 3, EVENT_OBJ_GFX_BOY_2, 0, 26, 14, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, LittlerootTown_EventScript_1E802B, 0
	object_event 4, EVENT_OBJ_GFX_MOM, 0, 7, 8, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LittlerootTown_EventScript_1E863D, FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	object_event 5, EVENT_OBJ_GFX_TRUCK, 0, 4, 10, 4, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	object_event 6, EVENT_OBJ_GFX_TRUCK, 0, 13, 10, 4, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	object_event 7, EVENT_OBJ_GFX_VAR_0, 0, 15, 10, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	object_event 8, EVENT_OBJ_GFX_PROF_BIRCH, 0, 16, 10, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_BIRCH

LittlerootTown_MapWarps::
	warp_def 16, 18, 0, 1, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 7, 8, 0, 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 9, 16, 0, 0, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB

LittlerootTown_MapCoordEvents::
	coord_event 12, 1, 3, VAR_0x4050, 0, LittlerootTown_EventScript_1E8091
	coord_event 13, 1, 3, VAR_0x4050, 0, LittlerootTown_EventScript_1E80EF
	coord_event 13, 1, 3, VAR_0x4050, 1, LittlerootTown_EventScript_1E811F
	coord_event 10, 9, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E81F9
	coord_event 11, 9, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E8205
	coord_event 12, 9, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E81E1
	coord_event 13, 9, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E81ED
	coord_event 12, 2, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E81BB
	coord_event 13, 2, 3, VAR_0x4050, 3, LittlerootTown_EventScript_1E81CE

LittlerootTown_MapBGEvents::
	bg_event 37, 25, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_1E8151
	bg_event 8, 17, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_1E815A
	bg_event 9, 8, 3, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_1E8163
	bg_event 14, 18, 3, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_1E818F
	bg_event 38, 25, 3, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_1E8151

LittlerootTown_MapEvents::
	map_events LittlerootTown_EventObjects, LittlerootTown_MapWarps, LittlerootTown_MapCoordEvents, LittlerootTown_MapBGEvents
