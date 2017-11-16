NavelRock_Top_MapObjects: @ 853DB74
	object_event 1, MAP_OBJ_GFX_HOOH, 0, 0, 12, 4, 0, 8, 17, 0, 0, 0, 0x0, 801, 0, 0

NavelRock_Top_MapWarps: @ 853DB8C
	warp_def 13, 20, 3, 1, NAVEL_ROCK_UP_4

NavelRock_Top_MapCoordEvents: @ 853DB94
	coord_event 12, 10, 3, 0, VAR_0x4001, 0, 0, NavelRock_Top_EventScript_26916F

NavelRock_Top_MapBGEvents: @ 853DBA4
	bg_event 12, 9, 3, 7, 0, ITEM_SACRED_ASH, 109, 0

NavelRock_Top_MapEvents:: @ 853DBB0
	map_events NavelRock_Top_MapObjects, NavelRock_Top_MapWarps, NavelRock_Top_MapCoordEvents, NavelRock_Top_MapBGEvents

