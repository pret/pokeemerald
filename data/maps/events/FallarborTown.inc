FallarborTown_MapObjects: @ 8527BE0
	object_event 1, MAP_OBJ_GFX_GIRL_1, 0, 0, 8, 11, 3, 8, 16, 0, 0, 0, FallarborTown_EventScript_1EB22B, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 11, 9, 3, 5, 1, 0, 0, 0, FallarborTown_EventScript_1EB20C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 11, 15, 3, 3, 17, 0, 0, 0, FallarborTown_EventScript_1EB234, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_AZURILL, 0, 0, 8, 12, 3, 1, 1, 0, 0, 0, FallarborTown_EventScript_1EB23D, 907, 0, 0

FallarborTown_MapWarps: @ 8527C40
	warp_def 15, 15, 0, 0, FALLARBOR_TOWN_MART
	warp_def 8, 7, 0, 0, FALLARBOR_TOWN_BATTLE_TENT_LOBBY
	warp_def 14, 7, 0, 0, FALLARBOR_TOWN_POKEMON_CENTER_1F
	warp_def 6, 17, 0, 0, FALLARBOR_TOWN_HOUSE_1
	warp_def 1, 6, 0, 0, FALLARBOR_TOWN_HOUSE_2

FallarborTown_MapBGEvents: @ 8527C68
	bg_event 16, 15, 0, 1, 0, FallarborTown_EventScript_271E6A
	bg_event 15, 7, 0, 1, 0, FallarborTown_EventScript_271E73
	bg_event 6, 8, 0, 0, 0, FallarborTown_EventScript_1EB250
	bg_event 16, 7, 0, 1, 0, FallarborTown_EventScript_271E73
	bg_event 10, 11, 0, 0, 0, FallarborTown_EventScript_1EB259
	bg_event 17, 15, 0, 1, 0, FallarborTown_EventScript_271E6A
	bg_event 3, 7, 0, 0, 0, FallarborTown_EventScript_1EB262
	bg_event 2, 15, 3, 7, 0, ITEM_NUGGET, 28, 0

FallarborTown_MapEvents:: @ 8527CC8
	map_events FallarborTown_MapObjects, FallarborTown_MapWarps, 0x0, FallarborTown_MapBGEvents

