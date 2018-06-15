MossdeepCity_StevensHouse_EventObjects: @ 8532C10
	object_event 1, EVENT_OBJ_GFX_STEVEN, 0, 0, 9, 6, 3, 10, 0, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_222912, 967, 0, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 4, 3, 3, 1, 17, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_222841, 968, 0, 0
	object_event 3, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 0, 6, 4, 3, 76, 17, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_22291B, 727, 0, 0

MossdeepCity_StevensHouse_MapWarps: @ 8532C58
	warp_def 3, 7, 0, 6, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 6, MAP_MOSSDEEP_CITY

MossdeepCity_StevensHouse_MapBGEvents: @ 8532C68
	bg_event 0, 1, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_222909
	bg_event 1, 1, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_222909
	bg_event 10, 4, 3, 0, 0, MossdeepCity_StevensHouse_EventScript_222909
	bg_event 10, 6, 3, 0, 0, MossdeepCity_StevensHouse_EventScript_222909

MossdeepCity_StevensHouse_MapEvents:: @ 8532C98
	map_events MossdeepCity_StevensHouse_EventObjects, MossdeepCity_StevensHouse_MapWarps, 0x0, MossdeepCity_StevensHouse_MapBGEvents

