LittlerootTown_BrendansHouse_2F_MapObjects: @ 852D1A0
	object_event 1, MAP_OBJ_GFX_RIVAL_BRENDAN_NORMAL, 0, 0, 7, 1, 0, 8, 1, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F94C1, 760, 0, 0
	object_event 2, MAP_OBJ_GFX_HIPSTER, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0x0, 174, 0, 0
	object_event 3, MAP_OBJ_GFX_TRADER, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0x0, 175, 0, 0
	object_event 4, MAP_OBJ_GFX_STORYTELLER, 0, 0, 0, 2, 3, 1, 0, 0, 0, 0, 0x0, 176, 0, 0
	object_event 5, MAP_OBJ_GFX_GIDDY, 0, 0, 0, 3, 3, 1, 0, 0, 0, 0, 0x0, 177, 0, 0
	object_event 6, MAP_OBJ_GFX_PLACEHOLDER_1, 0, 0, 0, 4, 0, 1, 0, 0, 0, 0, 0x0, 178, 0, 0
	object_event 7, MAP_OBJ_GFX_PLACEHOLDER_2, 0, 0, 0, 5, 4, 1, 0, 0, 0, 0, 0x0, 179, 0, 0
	object_event 8, 246, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0x0, 180, 0, 0
	object_event 9, 247, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0x0, 181, 0, 0
	object_event 10, 248, 0, 0, 1, 2, 3, 1, 0, 0, 0, 0, 0x0, 182, 0, 0
	object_event 11, 249, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0x0, 183, 0, 0
	object_event 12, 250, 0, 0, 1, 4, 3, 1, 0, 0, 0, 0, 0x0, 184, 0, 0
	object_event 13, 251, 0, 0, 1, 5, 0, 1, 0, 0, 0, 0, 0x0, 185, 0, 0
	object_event 14, MAP_OBJ_GFX_MOM, 0, 0, 7, 1, 3, 8, 1, 0, 0, 0, 0x0, 757, 0, 0
	object_event 15, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 3, 4, 0, 1, 17, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8481, 817, 0, 0
	object_event 16, MAP_OBJ_GFX_SWABLU_DOLL, 0, 0, 5, 5, 3, 1, 17, 0, 0, 0, 0x0, 815, 0, 0

LittlerootTown_BrendansHouse_2F_MapWarps: @ 852D320
	warp_def 7, 1, 0, 2, LITTLEROOT_TOWN_BRENDANS_HOUSE_1F

LittlerootTown_BrendansHouse_2F_MapBGEvents: @ 852D328
	bg_event 0, 1, 0, 1, 0, gUnknown_081F860D
	bg_event 1, 1, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8656
	bg_event 5, 1, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_292781
	bg_event 3, 1, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F865F

LittlerootTown_BrendansHouse_2F_MapEvents:: @ 852D358
	map_events LittlerootTown_BrendansHouse_2F_MapObjects, LittlerootTown_BrendansHouse_2F_MapWarps, 0x0, LittlerootTown_BrendansHouse_2F_MapBGEvents

