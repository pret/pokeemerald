UnionRoom_EventObjects: @ 853B020
	object_event 1, EVENT_OBJ_GFX_UNION_ROOM_NURSE, 0, 3, 2, 3, 8, 0, 0, 0, UnionRoom_EventScript_23D236, 0
	object_event 2, EVENT_OBJ_GFX_GIDDY, 0, 1, 8, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D204, 706
	object_event 3, 247, 0, 7, 8, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D22C, 710
	object_event 4, 246, 0, 1, 4, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D222, 709
	object_event 5, EVENT_OBJ_GFX_PLACEHOLDER_2, 0, 7, 4, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D218, 708
	object_event 6, EVENT_OBJ_GFX_PLACEHOLDER_1, 0, 13, 4, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D20E, 707
	object_event 7, EVENT_OBJ_GFX_STORYTELLER, 0, 10, 6, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D1FA, 705
	object_event 8, EVENT_OBJ_GFX_TRADER, 0, 13, 8, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D1F0, 704
	object_event 9, EVENT_OBJ_GFX_HIPSTER, 0, 4, 6, 3, 2, 17, 0, 0, UnionRoom_EventScript_23D1E6, 703

UnionRoom_MapWarps: @ 853B0F8
	warp_def 7, 11, 3, 127, MAP_NONE
	warp_def 8, 11, 3, 127, MAP_NONE

UnionRoom_MapEvents:: @ 853B108
	map_events UnionRoom_EventObjects, UnionRoom_MapWarps, 0x0, 0x0

