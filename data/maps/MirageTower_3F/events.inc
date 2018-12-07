MirageTower_3F_EventObjects: @ 853761C
	object_event 1, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 3, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MirageTower_3F_EventScript_2907A6, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 4, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MirageTower_3F_EventScript_2907A6, FLAG_TEMP_12

MirageTower_3F_MapWarps: @ 853764C
	warp_def 18, 12, 3, 0, MAP_MIRAGE_TOWER_2F
	warp_def 2, 4, 0, 0, MAP_MIRAGE_TOWER_4F

MirageTower_3F_MapEvents:: @ 853765C
	map_events MirageTower_3F_EventObjects, MirageTower_3F_MapWarps, 0x0, 0x0

