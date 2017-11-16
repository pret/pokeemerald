SootopolisCity_LotadAndSeedotHouse_MapObjects: @ 853352C
	object_event 1, MAP_OBJ_GFX_FISHERMAN, 0, 0, 2, 4, 3, 10, 0, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_2272BC, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_HIKER, 0, 0, 5, 4, 3, 9, 0, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_22722B, 0, 0, 0

SootopolisCity_LotadAndSeedotHouse_MapWarps: @ 853355C
	warp_def 3, 6, 0, 11, SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 11, SOOTOPOLIS_CITY

SootopolisCity_LotadAndSeedotHouse_MapBGEvents: @ 853356C
	bg_event 5, 1, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_22734D
	bg_event 2, 1, 0, 0, 0, SootopolisCity_LotadAndSeedotHouse_EventScript_22735B

SootopolisCity_LotadAndSeedotHouse_MapEvents:: @ 8533584
	map_events SootopolisCity_LotadAndSeedotHouse_MapObjects, SootopolisCity_LotadAndSeedotHouse_MapWarps, 0x0, SootopolisCity_LotadAndSeedotHouse_MapBGEvents

