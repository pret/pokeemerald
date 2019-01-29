ArtisanCave_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 14, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, ArtisanCave_1F_EventScript_2914D1, FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS

ArtisanCave_1F_MapWarps:
	warp_def 10, 17, 0, 13, MAP_BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 6, 5, 0, 1, MAP_ARTISAN_CAVE_B1F

ArtisanCave_1F_MapEvents::
	map_events ArtisanCave_1F_EventObjects, ArtisanCave_1F_MapWarps, 0x0, 0x0

