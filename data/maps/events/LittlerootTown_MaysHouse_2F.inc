LittlerootTown_MaysHouse_2F_EventObjects: @ 852D480
	object_event 1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL, 0, 1, 1, 0, 8, 1, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F94C1, 722
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 0, 6, 0, 1, 0, 0, 0, 0x0, 174
	object_event 3, EVENT_OBJ_GFX_TRADER, 0, 1, 6, 3, 1, 0, 0, 0, 0x0, 175
	object_event 4, EVENT_OBJ_GFX_STORYTELLER, 0, 2, 6, 0, 1, 0, 0, 0, 0x0, 176
	object_event 5, EVENT_OBJ_GFX_GIDDY, 0, 3, 6, 3, 1, 0, 0, 0, 0x0, 177
	object_event 6, EVENT_OBJ_GFX_PLACEHOLDER_1, 0, 4, 6, 3, 1, 0, 0, 0, 0x0, 178
	object_event 7, EVENT_OBJ_GFX_PLACEHOLDER_2, 0, 5, 6, 3, 1, 0, 0, 0, 0x0, 179
	object_event 8, 246, 0, 0, 7, 3, 1, 0, 0, 0, 0x0, 180
	object_event 9, 247, 0, 1, 7, 3, 1, 0, 0, 0, 0x0, 181
	object_event 10, 248, 0, 2, 7, 3, 1, 0, 0, 0, 0x0, 182
	object_event 11, 249, 0, 3, 7, 3, 1, 0, 0, 0, 0x0, 183
	object_event 12, 250, 0, 4, 7, 3, 1, 0, 0, 0, 0x0, 184
	object_event 13, 251, 0, 5, 7, 3, 1, 0, 0, 0, 0x0, 185
	object_event 14, EVENT_OBJ_GFX_MOM, 0, 1, 1, 3, 8, 1, 0, 0, 0x0, 757
	object_event 15, EVENT_OBJ_GFX_PICHU_DOLL, 0, 3, 4, 4, 8, 17, 0, 0, 0x0, 849
	object_event 16, EVENT_OBJ_GFX_ITEM_BALL, 0, 5, 4, 0, 1, 17, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F9334, 818

LittlerootTown_MaysHouse_2F_MapWarps: @ 852D600
	warp_def 1, 1, 0, 2, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F

LittlerootTown_MaysHouse_2F_MapBGEvents: @ 852D608
	bg_event 5, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F865F
	bg_event 7, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F8656
	bg_event 3, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_29278D
	bg_event 8, 1, 0, 0, 0, gUnknown_081F9553

LittlerootTown_MaysHouse_2F_MapEvents:: @ 852D638
	map_events LittlerootTown_MaysHouse_2F_EventObjects, LittlerootTown_MaysHouse_2F_MapWarps, 0x0, LittlerootTown_MaysHouse_2F_MapBGEvents

