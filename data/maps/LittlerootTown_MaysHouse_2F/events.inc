LittlerootTown_MaysHouse_2F_EventObjects: @ 852D480
	object_event 1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL, 0, 1, 1, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F94C1, FLAG_0x2D2
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 0, 6, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0AE
	object_event 3, EVENT_OBJ_GFX_TRADER, 0, 1, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0AF
	object_event 4, EVENT_OBJ_GFX_STORYTELLER, 0, 2, 6, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B0
	object_event 5, EVENT_OBJ_GFX_GIDDY, 0, 3, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B1
	object_event 6, EVENT_OBJ_GFX_PLACEHOLDER_1, 0, 4, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B2
	object_event 7, EVENT_OBJ_GFX_PLACEHOLDER_2, 0, 5, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B3
	object_event 8, 246, 0, 0, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B4
	object_event 9, 247, 0, 1, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B5
	object_event 10, 248, 0, 2, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B6
	object_event 11, 249, 0, 3, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B7
	object_event 12, 250, 0, 4, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B8
	object_event 13, 251, 0, 5, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_0x0B9
	object_event 14, EVENT_OBJ_GFX_MOM, 0, 1, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 0, 0, 0, 0x0, FLAG_0x2F5
	object_event 15, EVENT_OBJ_GFX_PICHU_DOLL, 0, 3, 4, 4, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_0x351
	object_event 16, EVENT_OBJ_GFX_ITEM_BALL, 0, 5, 4, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_1F9334, FLAG_0x332

LittlerootTown_MaysHouse_2F_MapWarps: @ 852D600
	warp_def 1, 1, 0, 2, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F

LittlerootTown_MaysHouse_2F_MapBGEvents: @ 852D608
	bg_event 5, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_MaysHouse_2F_EventScript_1F865F
	bg_event 7, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_MaysHouse_2F_EventScript_1F8656
	bg_event 3, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_MaysHouse_2F_EventScript_29278D
	bg_event 8, 1, 0, BG_EVENT_PLAYER_FACING_ANY, EventScript_PlayerPCFemale

LittlerootTown_MaysHouse_2F_MapEvents:: @ 852D638
	map_events LittlerootTown_MaysHouse_2F_EventObjects, LittlerootTown_MaysHouse_2F_MapWarps, 0x0, LittlerootTown_MaysHouse_2F_MapBGEvents

