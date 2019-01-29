SeafloorCavern_Entrance_EventObjects:
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, SeafloorCavern_Entrance_EventScript_234485, FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT

SeafloorCavern_Entrance_MapWarps:
	warp_def 10, 18, 3, 0, MAP_UNDERWATER4
	warp_def 10, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM1

SeafloorCavern_Entrance_MapEvents::
	map_events SeafloorCavern_Entrance_EventObjects, SeafloorCavern_Entrance_MapWarps, 0x0, 0x0

