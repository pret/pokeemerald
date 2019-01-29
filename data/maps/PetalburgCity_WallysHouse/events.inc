PetalburgCity_WallysHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_POKEFAN_M, 0, 3, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_204278, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_4, 0, 7, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_2042C0, 0

PetalburgCity_WallysHouse_MapWarps:
	warp_def 3, 7, 0, 1, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 1, MAP_PETALBURG_CITY

PetalburgCity_WallysHouse_MapEvents::
	map_events PetalburgCity_WallysHouse_EventObjects, PetalburgCity_WallysHouse_MapWarps, 0x0, 0x0

