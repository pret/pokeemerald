SlateportCity_SternsShipyard_1F_EventObjects: @ 852F318
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207F40, 0
	object_event 2, EVENT_OBJ_GFX_SCIENTIST_1, 0, 10, 7, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FED, 0
	object_event 3, EVENT_OBJ_GFX_SCIENTIST_1, 0, 18, 8, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FF6, 0
	object_event 4, EVENT_OBJ_GFX_EXPERT_M, 0, 12, 11, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, SlateportCity_SternsShipyard_1F_EventScript_207FFF, 869

SlateportCity_SternsShipyard_1F_MapWarps: @ 852F378
	warp_def 2, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 1, 0, 0, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F

SlateportCity_SternsShipyard_1F_MapEvents:: @ 852F390
	map_events SlateportCity_SternsShipyard_1F_EventObjects, SlateportCity_SternsShipyard_1F_MapWarps, 0x0, 0x0

