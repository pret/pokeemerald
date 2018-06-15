SlateportCity_OceanicMuseum_2F_EventObjects: @ 852F8A8
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 13, 6, 3, 8, 0, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BB00, 887
	object_event 2, EVENT_OBJ_GFX_ARCHIE, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x0, 886
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x0, 884
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x0, 885
	object_event 5, EVENT_OBJ_GFX_OLD_MAN_2, 0, 12, 7, 3, 10, 1, 1, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD64, 961
	object_event 6, EVENT_OBJ_GFX_WOMAN_2, 0, 9, 6, 3, 1, 1, 1, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD6D, 961
	object_event 7, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 1, 3, 3, 10, 1, 1, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD76, 961

SlateportCity_OceanicMuseum_2F_MapWarps: @ 852F950
	warp_def 6, 1, 0, 2, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F

SlateportCity_OceanicMuseum_2F_MapBGEvents: @ 852F958
	bg_event 18, 4, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD0A
	bg_event 18, 7, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD13
	bg_event 4, 3, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD52
	bg_event 4, 4, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD52
	bg_event 3, 3, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD49
	bg_event 2, 3, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD49
	bg_event 3, 4, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD49
	bg_event 3, 6, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD40
	bg_event 4, 6, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD40
	bg_event 13, 7, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD5B
	bg_event 14, 7, 3, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD5B
	bg_event 18, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD37
	bg_event 19, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD37
	bg_event 15, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD2E
	bg_event 16, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD2E
	bg_event 8, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD25
	bg_event 9, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD25
	bg_event 12, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD1C
	bg_event 13, 1, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD1C
	bg_event 3, 7, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD40
	bg_event 4, 7, 0, 0, 0, SlateportCity_OceanicMuseum_2F_EventScript_20BD40

SlateportCity_OceanicMuseum_2F_MapEvents:: @ 852FA54
	map_events SlateportCity_OceanicMuseum_2F_EventObjects, SlateportCity_OceanicMuseum_2F_MapWarps, 0x0, SlateportCity_OceanicMuseum_2F_MapBGEvents

