RustboroCity_CuttersHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_POKEFAN_M, 0, 7, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_CuttersHouse_EventScript_215BD4, 0
	object_event 2, EVENT_OBJ_GFX_LASS, 0, 9, 2, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, RustboroCity_CuttersHouse_EventScript_215C0A, 0

RustboroCity_CuttersHouse_MapWarps:
	warp_def 5, 8, 0, 8, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 8, MAP_RUSTBORO_CITY

RustboroCity_CuttersHouse_MapEvents::
	map_events RustboroCity_CuttersHouse_EventObjects, RustboroCity_CuttersHouse_MapWarps, 0x0, 0x0

