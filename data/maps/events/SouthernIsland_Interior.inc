SouthernIsland_Interior_MapObjects: @ 853B89C
	object_event 1, MAP_OBJ_GFX_HIPSTER, 0, 0, 13, 12, 3, 7, 0, 0, 0, 0, 0x0, 910, 0, 0
	object_event 2, MAP_OBJ_GFX_TRADER, 0, 0, 13, 2, 0, 8, 0, 0, 0, 0, 0x0, 911, 0, 0

SouthernIsland_Interior_MapWarps: @ 853B8CC
	warp_def 13, 18, 3, 0, SOUTHERN_ISLAND_EXTERIOR
	warp_def 14, 18, 3, 1, SOUTHERN_ISLAND_EXTERIOR

SouthernIsland_Interior_MapBGEvents: @ 853B8DC
	bg_event 13, 11, 3, 1, 0, SouthernIsland_Interior_EventScript_242AC4

SouthernIsland_Interior_MapEvents:: @ 853B8E8
	map_events SouthernIsland_Interior_MapObjects, SouthernIsland_Interior_MapWarps, 0x0, SouthernIsland_Interior_MapBGEvents

