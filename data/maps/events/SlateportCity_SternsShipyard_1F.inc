SlateportCity_SternsShipyard_1F_MapObjects: @ 852F318
	object_event 1, MAP_OBJ_GFX_MAN_1, 0, 0, 5, 5, 3, 8, 0, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207F40, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SCIENTIST_1, 0, 0, 10, 7, 3, 7, 0, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FED, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_SCIENTIST_1, 0, 0, 18, 8, 3, 5, 1, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FF6, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 12, 11, 3, 2, 33, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FFF, 869, 0, 0

SlateportCity_SternsShipyard_1F_MapWarps: @ 852F378
	warp_def 2, 14, 0, 2, SLATEPORT_CITY
	warp_def 3, 14, 0, 2, SLATEPORT_CITY
	warp_def 3, 1, 0, 0, SLATEPORT_CITY_STERNS_SHIPYARD_2F

SlateportCity_SternsShipyard_1F_MapEvents:: @ 852F390
	map_events SlateportCity_SternsShipyard_1F_MapObjects, SlateportCity_SternsShipyard_1F_MapWarps, 0x0, 0x0

