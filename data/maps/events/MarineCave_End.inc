MarineCave_End_MapObjects: @ 85377E8
	object_event 1, MAP_OBJ_GFX_KYOGRE_1, 0, 0, 9, 22, 1, 8, 17, 0, 0, 0, 0x0, 782, 0, 0

MarineCave_End_MapWarps: @ 8537800
	warp_def 20, 4, 0, 0, MARINE_CAVE_ENTRANCE

MarineCave_End_MapCoordEvents: @ 8537808
	coord_event 9, 26, 3, 0, VAR_TEMP_1, 1, 0, MarineCave_End_EventScript_23B01B

MarineCave_End_MapEvents:: @ 8537818
	map_events MarineCave_End_MapObjects, MarineCave_End_MapWarps, MarineCave_End_MapCoordEvents, 0x0

