Route123_BerryMastersHouse_MapObjects: @ 853EACC
	object_event 1, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 4, 4, 3, 8, 0, 0, 0, 0, Route123_BerryMastersHouse_EventScript_26F845, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_OLD_WOMAN_2, 0, 0, 7, 4, 3, 8, 0, 0, 0, 0, Route123_BerryMastersHouse_EventScript_26F8C0, 0, 0, 0

Route123_BerryMastersHouse_MapWarps: @ 853EAFC
	warp_def 3, 7, 0, 0, ROUTE_123
	warp_def 4, 7, 0, 0, ROUTE_123

Route123_BerryMastersHouse_MapEvents:: @ 853EB0C
	map_events Route123_BerryMastersHouse_MapObjects, Route123_BerryMastersHouse_MapWarps, 0x0, 0x0

