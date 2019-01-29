SootopolisCity_LotadAndSeedotHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_FISHERMAN, 0, 2, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_2272BC, 0
	object_event 2, EVENT_OBJ_GFX_HIKER, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_22722B, 0

SootopolisCity_LotadAndSeedotHouse_MapWarps:
	warp_def 3, 6, 0, 11, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 11, MAP_SOOTOPOLIS_CITY

SootopolisCity_LotadAndSeedotHouse_MapBGEvents:
	bg_event 5, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SootopolisCity_LotadAndSeedotHouse_EventScript_22734D
	bg_event 2, 1, 0, BG_EVENT_PLAYER_FACING_ANY, SootopolisCity_LotadAndSeedotHouse_EventScript_22735B

SootopolisCity_LotadAndSeedotHouse_MapEvents::
	map_events SootopolisCity_LotadAndSeedotHouse_EventObjects, SootopolisCity_LotadAndSeedotHouse_MapWarps, 0x0, SootopolisCity_LotadAndSeedotHouse_MapBGEvents

