Route123_BerryMastersHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_EXPERT_M, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route123_BerryMastersHouse_EventScript_26F845, 0
	object_event 2, EVENT_OBJ_GFX_OLD_WOMAN, 0, 7, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route123_BerryMastersHouse_EventScript_26F8C0, 0

Route123_BerryMastersHouse_MapWarps:
	warp_def 3, 7, 0, 0, MAP_ROUTE123
	warp_def 4, 7, 0, 0, MAP_ROUTE123

Route123_BerryMastersHouse_MapEvents::
	map_events Route123_BerryMastersHouse_EventObjects, Route123_BerryMastersHouse_MapWarps, 0x0, 0x0

