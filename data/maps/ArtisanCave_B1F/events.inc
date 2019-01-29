ArtisanCave_B1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 32, 38, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, ArtisanCave_B1F_EventScript_2914C4, FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP

ArtisanCave_B1F_MapWarps:
	warp_def 8, 48, 0, 10, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 38, 5, 0, 1, MAP_ARTISAN_CAVE_1F

ArtisanCave_B1F_MapBGEvents:
	bg_hidden_item_event 32, 29, 0, ITEM_ZINC, FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC
	bg_hidden_item_event 27, 8, 0, ITEM_CALCIUM, FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM
	bg_hidden_item_event 7, 5, 0, ITEM_PROTEIN, FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN
	bg_hidden_item_event 19, 43, 0, ITEM_IRON, FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON

ArtisanCave_B1F_MapEvents::
	map_events ArtisanCave_B1F_EventObjects, ArtisanCave_B1F_MapWarps, 0x0, ArtisanCave_B1F_MapBGEvents

