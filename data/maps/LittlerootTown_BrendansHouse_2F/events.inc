LittlerootTown_BrendansHouse_2F_EventObjects: @ 852D1A0
	object_event 1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL, 0, 7, 1, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 0, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F94C1, 760
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 0, 0, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 174
	object_event 3, EVENT_OBJ_GFX_TRADER, 0, 0, 1, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 175
	object_event 4, EVENT_OBJ_GFX_STORYTELLER, 0, 0, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 176
	object_event 5, EVENT_OBJ_GFX_GIDDY, 0, 0, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 177
	object_event 6, EVENT_OBJ_GFX_PLACEHOLDER_1, 0, 0, 4, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 178
	object_event 7, EVENT_OBJ_GFX_PLACEHOLDER_2, 0, 0, 5, 4, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 179
	object_event 8, 246, 0, 1, 0, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 180
	object_event 9, 247, 0, 1, 1, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 181
	object_event 10, 248, 0, 1, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 182
	object_event 11, 249, 0, 1, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 183
	object_event 12, 250, 0, 1, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 184
	object_event 13, 251, 0, 1, 5, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, 185
	object_event 14, EVENT_OBJ_GFX_MOM, 0, 7, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 0, 0, 0, 0x0, 757
	object_event 15, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 4, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8481, 817
	object_event 16, EVENT_OBJ_GFX_SWABLU_DOLL, 0, 5, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, 0x0, 815

LittlerootTown_BrendansHouse_2F_MapWarps: @ 852D320
	warp_def 7, 1, 0, 2, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F

LittlerootTown_BrendansHouse_2F_MapBGEvents: @ 852D328
	bg_event 0, 1, 0, BG_EVENT_PLAYER_FACING_NORTH, gUnknown_081F860D
	bg_event 1, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_BrendansHouse_2F_EventScript_1F8656
	bg_event 5, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_BrendansHouse_2F_EventScript_292781
	bg_event 3, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_BrendansHouse_2F_EventScript_1F865F

LittlerootTown_BrendansHouse_2F_MapEvents:: @ 852D358
	map_events LittlerootTown_BrendansHouse_2F_EventObjects, LittlerootTown_BrendansHouse_2F_MapWarps, 0x0, LittlerootTown_BrendansHouse_2F_MapBGEvents

