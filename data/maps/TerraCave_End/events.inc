TerraCave_End_EventObjects: @ 8537850
	object_event 1, EVENT_OBJ_GFX_GROUDON_1, 0, 17, 22, 1, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_HIDE_TERRA_CAVE_GROUDON

TerraCave_End_MapWarps: @ 8537868
	warp_def 5, 4, 3, 1, MAP_TERRA_CAVE_ENTRANCE

TerraCave_End_MapCoordEvents: @ 8537870
	coord_event 17, 26, 3, VAR_TEMP_1, 1, TerraCave_End_EventScript_23B0EC

TerraCave_End_MapEvents:: @ 8537880
	map_events TerraCave_End_EventObjects, TerraCave_End_MapWarps, TerraCave_End_MapCoordEvents, 0x0

