MirageTower_4F_EventObjects: @ 8537670
	object_event 1, EVENT_OBJ_GFX_FOSSIL, 0, 5, 4, 4, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MirageTower_4F_EventScript_23AD48, FLAG_0x3C3
	object_event 2, EVENT_OBJ_GFX_FOSSIL, 0, 7, 4, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MirageTower_4F_EventScript_23AD89, FLAG_0x3C4
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 6, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MirageTower_4F_EventScript_2907A6, FLAG_TEMP_11

MirageTower_4F_MapWarps: @ 85376B8
	warp_def 1, 4, 3, 1, MAP_MIRAGE_TOWER_3F

MirageTower_4F_MapEvents:: @ 85376C0
	map_events MirageTower_4F_EventObjects, MirageTower_4F_MapWarps, 0x0, 0x0

