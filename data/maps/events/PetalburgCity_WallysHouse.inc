PetalburgCity_WallysHouse_EventObjects: @ 852ED74
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 0, 3, 4, 3, 10, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_204278, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_5, 0, 0, 7, 5, 3, 9, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_2042C0, 0, 0, 0

PetalburgCity_WallysHouse_MapWarps: @ 852EDA4
	warp_def 3, 7, 0, 1, PETALBURG_CITY
	warp_def 4, 7, 0, 1, PETALBURG_CITY

PetalburgCity_WallysHouse_MapEvents:: @ 852EDB4
	map_events PetalburgCity_WallysHouse_EventObjects, PetalburgCity_WallysHouse_MapWarps, 0x0, 0x0

