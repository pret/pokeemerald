RecordCorner_EventObjects: @ 8539DFC
	object_event 1, EVENT_OBJ_GFX_WOMAN_6, 0, 10, 5, 3, 8, 0, 0, 0, 0, RecordCorner_EventScript_2774C6, 0

RecordCorner_MapWarps: @ 8539E14
	warp_def 8, 9, 3, 127, MAP_NONE
	warp_def 9, 9, 3, 127, MAP_NONE
	warp_def 11, 9, 3, 127, MAP_NONE
	warp_def 10, 9, 3, 127, MAP_NONE

RecordCorner_MapCoordEvents: @ 8539E34
	coord_event 6, 4, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_0827741D
	coord_event 6, 6, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_08277447
	coord_event 13, 4, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_08277432
	coord_event 13, 6, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_0827745C

RecordCorner_MapEvents:: @ 8539E74
	map_events RecordCorner_EventObjects, RecordCorner_MapWarps, RecordCorner_MapCoordEvents, 0x0

