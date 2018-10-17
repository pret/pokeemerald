ArtisanCave_B1F_EventObjects: @ 8537708
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 32, 38, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, ArtisanCave_B1F_EventScript_2914C4, FLAG_0x48A

ArtisanCave_B1F_MapWarps: @ 8537720
	warp_def 8, 48, 0, 10, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 38, 5, 0, 1, MAP_ARTISAN_CAVE_1F

ArtisanCave_B1F_MapBGEvents: @ 8537730
	bg_hidden_item_event 32, 29, 0, ITEM_ZINC, FLAG_0x066
	bg_hidden_item_event 27, 8, 0, ITEM_CALCIUM, FLAG_0x065
	bg_hidden_item_event 7, 5, 0, ITEM_PROTEIN, FLAG_0x067
	bg_hidden_item_event 19, 43, 0, ITEM_IRON, FLAG_0x068

ArtisanCave_B1F_MapEvents:: @ 8537760
	map_events ArtisanCave_B1F_EventObjects, ArtisanCave_B1F_MapWarps, 0x0, ArtisanCave_B1F_MapBGEvents

