TerraCave_End_MapObjects: @ 8537850
	object_event 1, MAP_OBJ_GFX_GROUDON_1, 0, 0, 17, 22, 1, 8, 17, 0, 0, 0, 0x0, 783, 0, 0

TerraCave_End_MapWarps: @ 8537868
	warp_def 5, 4, 3, 1, TERRA_CAVE_ENTRANCE

TerraCave_End_MapCoordEvents: @ 8537870
	coord_event 17, 26, 3, 0, VAR_0x4001, 1, 0, TerraCave_End_EventScript_23B0EC

TerraCave_End_MapEvents:: @ 8537880
	map_events TerraCave_End_MapObjects, TerraCave_End_MapWarps, TerraCave_End_MapCoordEvents, 0x0

