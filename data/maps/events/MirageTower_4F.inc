MirageTower_4F_EventObjects: @ 8537670
	object_event 1, EVENT_OBJ_GFX_FOSSIL, 0, 0, 5, 4, 4, 8, 17, 0, 0, 0, MirageTower_4F_EventScript_23AD48, 963, 0, 0
	object_event 2, EVENT_OBJ_GFX_FOSSIL, 0, 0, 7, 4, 0, 8, 17, 0, 0, 0, MirageTower_4F_EventScript_23AD89, 964, 0, 0
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 6, 7, 3, 1, 17, 0, 0, 0, MirageTower_4F_EventScript_2907A6, 17, 0, 0

MirageTower_4F_MapWarps: @ 85376B8
	warp_def 1, 4, 3, 1, MAP_MIRAGE_TOWER_3F

MirageTower_4F_MapEvents:: @ 85376C0
	map_events MirageTower_4F_EventObjects, MirageTower_4F_MapWarps, 0x0, 0x0

