LavaridgeTown_EventObjects: @ 8527A54
	object_event 1, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 0, 8, 7, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA73B, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 5, 1, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA70E, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_2, 0, 0, 5, 8, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA717, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 10, 13, 3, 3, 32, 0, 0, 0, LavaridgeTown_EventScript_1EA720, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_HOT_SPRINGS_OLD_WOMAN, 0, 0, 4, 4, 3, 18, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA729, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_HOT_SPRINGS_OLD_WOMAN, 0, 0, 5, 4, 3, 17, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA732, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_GIDDY, 0, 0, 6, 16, 3, 9, 0, 0, 0, 0, 0x0, 930, 0, 0
	object_event 8, EVENT_OBJ_GFX_HIPSTER, 0, 0, 12, 15, 0, 8, 0, 0, 0, 0, 0x0, 929, 0, 0
	object_event 9, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 0, 4, 7, 3, 8, 17, 0, 0, 0, LavaridgeTown_EventScript_1EA744, 0, 0, 0

LavaridgeTown_MapWarps: @ 8527B2C
	warp_def 12, 15, 0, 0, MAP_LAVARIDGE_TOWN_HERB_SHOP
	warp_def 5, 15, 0, 0, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 15, 5, 0, 0, MAP_LAVARIDGE_TOWN_MART
	warp_def 9, 6, 0, 0, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	warp_def 16, 15, 0, 0, MAP_LAVARIDGE_TOWN_HOUSE
	warp_def 9, 2, 3, 3, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F

LavaridgeTown_MapCoordEvents: @ 8527B5C
	coord_event 6, 3, 3, 0, 0, 0, 0, LavaridgeTown_EventScript_1EA6FA

LavaridgeTown_MapBGEvents: @ 8527B6C
	bg_event 14, 16, 0, 0, 0, LavaridgeTown_EventScript_1EA7B7
	bg_event 7, 15, 0, 0, 0, LavaridgeTown_EventScript_1EA7AE
	bg_event 17, 5, 0, 1, 0, LavaridgeTown_EventScript_271E6A
	bg_event 13, 8, 0, 0, 0, LavaridgeTown_EventScript_1EA7A5
	bg_event 10, 6, 0, 1, 0, LavaridgeTown_EventScript_271E73
	bg_event 16, 5, 0, 1, 0, LavaridgeTown_EventScript_271E6A
	bg_event 11, 6, 0, 1, 0, LavaridgeTown_EventScript_271E73
	bg_event 4, 5, 3, 7, 0, ITEM_ICE_HEAL, 0, 0

LavaridgeTown_MapEvents:: @ 8527BCC
	map_events LavaridgeTown_EventObjects, LavaridgeTown_MapWarps, LavaridgeTown_MapCoordEvents, LavaridgeTown_MapBGEvents

