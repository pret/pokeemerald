SootopolisCity_Gym_1F_EventObjects: @ 8532FF4
	object_event 1, EVENT_OBJ_GFX_JUAN, 0, 8, 2, 0, 8, 0, 0, 0, SootopolisCity_Gym_1F_EventScript_224F44, 0
	object_event 2, EVENT_OBJ_GFX_MAN_2, 0, 7, 24, 3, 8, 0, 0, 0, SootopolisCity_Gym_1F_EventScript_225040, 0

SootopolisCity_Gym_1F_MapWarps: @ 8533024
	warp_def 8, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 9, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 11, 22, 3, 0, MAP_SOOTOPOLIS_CITY_GYM_B1F

SootopolisCity_Gym_1F_MapBGEvents: @ 853303C
	bg_event 6, 24, 0, 0, 0, SootopolisCity_Gym_1F_EventScript_22505F
	bg_event 10, 24, 0, 1, 0, SootopolisCity_Gym_1F_EventScript_22506F

SootopolisCity_Gym_1F_MapEvents:: @ 8533054
	map_events SootopolisCity_Gym_1F_EventObjects, SootopolisCity_Gym_1F_MapWarps, 0x0, SootopolisCity_Gym_1F_MapBGEvents

