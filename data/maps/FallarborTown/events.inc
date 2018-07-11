FallarborTown_EventObjects: @ 8527BE0
	object_event 1, EVENT_OBJ_GFX_GIRL_1, 0, 8, 11, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 1, 0, 0, FallarborTown_EventScript_1EB22B, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 11, 9, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, FallarborTown_EventScript_1EB20C, 0
	object_event 3, EVENT_OBJ_GFX_GENTLEMAN, 0, 11, 15, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 1, 0, 0, FallarborTown_EventScript_1EB234, 0
	object_event 4, EVENT_OBJ_GFX_AZURILL, 0, 8, 12, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 0, 0, 0, FallarborTown_EventScript_1EB23D, 907

FallarborTown_MapWarps: @ 8527C40
	warp_def 15, 15, 0, 0, MAP_FALLARBOR_TOWN_MART
	warp_def 8, 7, 0, 0, MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
	warp_def 14, 7, 0, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F
	warp_def 6, 17, 0, 0, MAP_FALLARBOR_TOWN_HOUSE1
	warp_def 1, 6, 0, 0, MAP_FALLARBOR_TOWN_HOUSE2

FallarborTown_MapBGEvents: @ 8527C68
	bg_event 16, 15, 0, BG_EVENT_PLAYER_FACING_NORTH, FallarborTown_EventScript_271E6A
	bg_event 15, 7, 0, BG_EVENT_PLAYER_FACING_NORTH, FallarborTown_EventScript_271E73
	bg_event 6, 8, 0, BG_EVENT_PLAYER_FACING_ANY, FallarborTown_EventScript_1EB250
	bg_event 16, 7, 0, BG_EVENT_PLAYER_FACING_NORTH, FallarborTown_EventScript_271E73
	bg_event 10, 11, 0, BG_EVENT_PLAYER_FACING_ANY, FallarborTown_EventScript_1EB259
	bg_event 17, 15, 0, BG_EVENT_PLAYER_FACING_NORTH, FallarborTown_EventScript_271E6A
	bg_event 3, 7, 0, BG_EVENT_PLAYER_FACING_ANY, FallarborTown_EventScript_1EB262
	bg_hidden_item_event 2, 15, 3, ITEM_NUGGET, 28

FallarborTown_MapEvents:: @ 8527CC8
	map_events FallarborTown_EventObjects, FallarborTown_MapWarps, 0x0, FallarborTown_MapBGEvents

