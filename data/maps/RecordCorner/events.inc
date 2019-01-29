RecordCorner_EventObjects:
	object_event 1, EVENT_OBJ_GFX_LINK_RECEPTIONIST, 0, 10, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RecordCorner_EventScript_2774C6, 0

RecordCorner_MapWarps:
	warp_def 8, 9, 3, 127, MAP_NONE
	warp_def 9, 9, 3, 127, MAP_NONE
	warp_def 11, 9, 3, 127, MAP_NONE
	warp_def 10, 9, 3, 127, MAP_NONE

RecordCorner_MapCoordEvents:
	coord_event 6, 4, 3, VAR_TEMP_0, 0, gUnknown_0827741D
	coord_event 6, 6, 3, VAR_TEMP_0, 0, gUnknown_08277447
	coord_event 13, 4, 3, VAR_TEMP_0, 0, gUnknown_08277432
	coord_event 13, 6, 3, VAR_TEMP_0, 0, gUnknown_0827745C

RecordCorner_MapEvents::
	map_events RecordCorner_EventObjects, RecordCorner_MapWarps, RecordCorner_MapCoordEvents, 0x0

