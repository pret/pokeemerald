SlateportCity_SternsShipyard_2F_EventObjects: @ 852F3A4
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 10, 7, 3, 7, 0, 0, 0, 0x0, 0
	object_event 2, EVENT_OBJ_GFX_SCIENTIST_1, 0, 8, 4, 3, 10, 0, 0, 0, SlateportCity_SternsShipyard_2F_EventScript_20863E, 0
	object_event 3, EVENT_OBJ_GFX_SCIENTIST_1, 0, 0, 9, 3, 7, 0, 0, 0, SlateportCity_SternsShipyard_2F_EventScript_208647, 0

SlateportCity_SternsShipyard_2F_MapWarps: @ 852F3EC
	warp_def 3, 1, 0, 2, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F

SlateportCity_SternsShipyard_2F_MapEvents:: @ 852F3F4
	map_events SlateportCity_SternsShipyard_2F_EventObjects, SlateportCity_SternsShipyard_2F_MapWarps, 0x0, 0x0

