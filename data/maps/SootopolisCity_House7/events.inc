SootopolisCity_House7_EventObjects: @ 85334D8
	object_event 1, EVENT_OBJ_GFX_OLD_MAN, 0, 5, 3, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, SootopolisCity_House7_EventScript_2270CC, 0
	object_event 2, EVENT_OBJ_GFX_POKEFAN_F, 0, 1, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SootopolisCity_House7_EventScript_2270D5, 0

SootopolisCity_House7_MapWarps: @ 8533508
	warp_def 3, 6, 0, 10, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 10, MAP_SOOTOPOLIS_CITY

SootopolisCity_House7_MapEvents:: @ 8533518
	map_events SootopolisCity_House7_EventObjects, SootopolisCity_House7_MapWarps, 0x0, 0x0

