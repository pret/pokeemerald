MauvilleCity_GameCorner_EventObjects: @ 852FF28
	object_event 1, EVENT_OBJ_GFX_WOMAN_3, 0, 12, 7, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_210125, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 16, 5, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_21012E, 0
	object_event 3, EVENT_OBJ_GFX_BEAUTY, 0, 11, 2, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_20FBB9, 0
	object_event 4, EVENT_OBJ_GFX_BEAUTY, 0, 14, 2, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_20FCF1, 0
	object_event 5, EVENT_OBJ_GFX_GIRL_2, 0, 7, 3, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_210137, 0
	object_event 6, EVENT_OBJ_GFX_MAN_3, 0, 19, 4, 3, 8, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_21021D, 0
	object_event 7, EVENT_OBJ_GFX_OLD_MAN_2, 0, 20, 8, 3, 9, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_210279, 0
	object_event 8, EVENT_OBJ_GFX_COOK, 0, 6, 8, 3, 10, 0, 0, 0, 0, MauvilleCity_GameCorner_EventScript_210289, 0
	object_event 9, EVENT_OBJ_GFX_BEAUTY, 0, 13, 2, 3, 8, 1, 1, 0, 0, MauvilleCity_GameCorner_EventScript_20FE9F, 0
	object_event 10, EVENT_OBJ_GFX_MAN_4, 0, 1, 7, 3, 10, 1, 1, 0, 0, MauvilleCity_GameCorner_EventScript_210299, 0
	object_event 11, EVENT_OBJ_GFX_MANIAC, 0, 9, 8, 3, 9, 1, 1, 0, 0, MauvilleCity_GameCorner_EventScript_2102B6, 0
	object_event 12, EVENT_OBJ_GFX_WOMAN_7, 0, 4, 6, 3, 9, 1, 1, 0, 0, MauvilleCity_GameCorner_EventScript_2102C6, 0

MauvilleCity_GameCorner_MapWarps: @ 8530048
	warp_def 11, 10, 3, 5, MAP_MAUVILLE_CITY
	warp_def 12, 10, 3, 5, MAP_MAUVILLE_CITY

MauvilleCity_GameCorner_MapBGEvents: @ 8530058
	bg_event 2, 6, 0, 3, 0, MauvilleCity_GameCorner_EventScript_2102D6
	bg_event 2, 8, 0, 3, 0, MauvilleCity_GameCorner_EventScript_2102F6
	bg_event 2, 9, 0, 3, 0, MauvilleCity_GameCorner_EventScript_210316
	bg_event 3, 7, 0, 4, 0, MauvilleCity_GameCorner_EventScript_210336
	bg_event 3, 8, 0, 4, 0, MauvilleCity_GameCorner_EventScript_210356
	bg_event 3, 9, 0, 4, 0, MauvilleCity_GameCorner_EventScript_210376
	bg_event 7, 6, 0, 3, 0, MauvilleCity_GameCorner_EventScript_210396
	bg_event 7, 7, 0, 3, 0, MauvilleCity_GameCorner_EventScript_2103B6
	bg_event 7, 9, 0, 3, 0, MauvilleCity_GameCorner_EventScript_2103D6
	bg_event 8, 6, 0, 4, 0, MauvilleCity_GameCorner_EventScript_2103F6
	bg_event 8, 7, 0, 4, 0, MauvilleCity_GameCorner_EventScript_210416
	bg_event 8, 9, 0, 4, 0, MauvilleCity_GameCorner_EventScript_210436
	bg_event 14, 6, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 15, 6, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 14, 7, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 15, 7, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 14, 8, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 15, 8, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5AB1
	bg_event 18, 6, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF
	bg_event 19, 6, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF
	bg_event 18, 7, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF
	bg_event 19, 7, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF
	bg_event 18, 8, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF
	bg_event 19, 8, 0, 0, 0, MauvilleCity_GameCorner_EventScript_2A5ADF

MauvilleCity_GameCorner_MapEvents:: @ 8530178
	map_events MauvilleCity_GameCorner_EventObjects, MauvilleCity_GameCorner_MapWarps, 0x0, MauvilleCity_GameCorner_MapBGEvents

