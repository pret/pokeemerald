EverGrandeCity_DrakesRoom_EventObjects: @ 85336C4
	object_event 1, EVENT_OBJ_GFX_DRAKE, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, EverGrandeCity_DrakesRoom_EventScript_2286F3, 0

EverGrandeCity_DrakesRoom_MapWarps: @ 85336DC
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL3
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL4

EverGrandeCity_DrakesRoom_MapEvents:: @ 85336EC
	map_events EverGrandeCity_DrakesRoom_EventObjects, EverGrandeCity_DrakesRoom_MapWarps, 0x0, 0x0

