SootopolisCity_House1_EventObjects: @ 85332F8
	object_event 1, EVENT_OBJ_GFX_BLACK_BELT, 0, 2, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, SootopolisCity_House1_EventScript_22694D, 0
	object_event 2, EVENT_OBJ_GFX_KECLEON_1, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SootopolisCity_House1_EventScript_22698E, 0

SootopolisCity_House1_MapWarps: @ 8533328
	warp_def 3, 6, 0, 4, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 4, MAP_SOOTOPOLIS_CITY

SootopolisCity_House1_MapEvents:: @ 8533338
	map_events SootopolisCity_House1_EventObjects, SootopolisCity_House1_MapWarps, 0x0, 0x0

