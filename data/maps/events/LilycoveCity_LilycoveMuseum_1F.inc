LilycoveCity_LilycoveMuseum_1F_EventObjects: @ 853124C
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 5, 12, 3, 10, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218CB9, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 16, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218CC2, 775
	object_event 3, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 13, 7, 3, 10, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DF5, 0
	object_event 4, EVENT_OBJ_GFX_ARTIST, 0, 13, 10, 3, 5, 2, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DFE, 0
	object_event 5, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 2, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E07, 0
	object_event 6, EVENT_OBJ_GFX_WOMAN_5, 0, 3, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E10, 0
	object_event 7, EVENT_OBJ_GFX_WOMAN_3, 0, 11, 3, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E19, 776
	object_event 8, EVENT_OBJ_GFX_ARTIST, 0, 19, 3, 3, 7, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E2B, 779
	object_event 9, EVENT_OBJ_GFX_FAT_MAN, 0, 2, 2, 3, 2, 2, 2, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E42, 780
	object_event 10, EVENT_OBJ_GFX_PSYCHIC_M, 0, 6, 2, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218E22, 778

LilycoveCity_LilycoveMuseum_1F_MapWarps: @ 853133C
	warp_def 9, 13, 0, 3, MAP_LILYCOVE_CITY
	warp_def 10, 13, 0, 13, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F

LilycoveCity_LilycoveMuseum_1F_MapBGEvents: @ 8531354
	bg_event 1, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DAD
	bg_event 2, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DAD
	bg_event 5, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DD1
	bg_event 6, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DD1
	bg_event 9, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DA4
	bg_event 3, 6, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DB6
	bg_event 2, 6, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DB6
	bg_event 15, 12, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DDA
	bg_event 11, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DA4
	bg_event 6, 6, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DC8
	bg_event 17, 9, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DEC
	bg_event 19, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DBF
	bg_event 20, 1, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DBF
	bg_event 18, 9, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DEC
	bg_event 18, 11, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DE3
	bg_event 16, 9, 0, 0, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_218DEC

LilycoveCity_LilycoveMuseum_1F_MapEvents:: @ 8531414
	map_events LilycoveCity_LilycoveMuseum_1F_EventObjects, LilycoveCity_LilycoveMuseum_1F_MapWarps, 0x0, LilycoveCity_LilycoveMuseum_1F_MapBGEvents

