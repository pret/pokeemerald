SouthernIsland_Interior_EventObjects: @ 853B89C
	object_event 1, EVENT_OBJ_GFX_VAR_0, 0, 13, 12, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, 0x0, FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE
	object_event 2, EVENT_OBJ_GFX_VAR_1, 0, 13, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, 0x0, FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON

SouthernIsland_Interior_MapWarps: @ 853B8CC
	warp_def 13, 18, 3, 0, MAP_SOUTHERN_ISLAND_EXTERIOR
	warp_def 14, 18, 3, 1, MAP_SOUTHERN_ISLAND_EXTERIOR

SouthernIsland_Interior_MapBGEvents: @ 853B8DC
	bg_event 13, 11, 3, BG_EVENT_PLAYER_FACING_NORTH, SouthernIsland_Interior_EventScript_242AC4

SouthernIsland_Interior_MapEvents:: @ 853B8E8
	map_events SouthernIsland_Interior_EventObjects, SouthernIsland_Interior_MapWarps, 0x0, SouthernIsland_Interior_MapBGEvents

