SouthernIsland_Exterior_MapObjects: @ 853B83C
	object_event 1, MAP_OBJ_GFX_SAILOR, 0, 0, 13, 23, 3, 7, 0, 0, 0, 0, SouthernIsland_Exterior_EventScript_2429D2, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SS_TIDAL, 0, 0, 13, 25, 1, 10, 0, 0, 0, 0, 0x0, 0, 0, 0

SouthernIsland_Exterior_MapWarps: @ 853B86C
	warp_def 14, 5, 3, 0, SOUTHERN_ISLAND_INTERIOR
	warp_def 15, 5, 3, 1, SOUTHERN_ISLAND_INTERIOR

SouthernIsland_Exterior_MapBGEvents: @ 853B87C
	bg_event 16, 7, 3, 0, 0, SouthernIsland_Exterior_EventScript_242A3C

SouthernIsland_Exterior_MapEvents:: @ 853B888
	map_events SouthernIsland_Exterior_MapObjects, SouthernIsland_Exterior_MapWarps, 0x0, SouthernIsland_Exterior_MapBGEvents

