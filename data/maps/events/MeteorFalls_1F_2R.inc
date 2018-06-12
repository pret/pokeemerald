MeteorFalls_1F_2R_EventObjects: @ 85340C4
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 0, 13, 2, 3, 8, 0, 0, 1, 1, MeteorFalls_1F_2R_EventScript_22C4DE, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 6, 12, 3, 8, 17, 0, 1, 1, MeteorFalls_1F_2R_EventScript_22C540, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 0, 7, 12, 3, 8, 17, 0, 1, 1, MeteorFalls_1F_2R_EventScript_22C5A4, 0, 0, 0

MeteorFalls_1F_2R_MapWarps: @ 853410C
	warp_def 10, 29, 3, 2, METEOR_FALLS_1F_1R
	warp_def 4, 14, 3, 0, METEOR_FALLS_B1F_1R
	warp_def 7, 20, 3, 1, METEOR_FALLS_B1F_1R
	warp_def 21, 23, 3, 2, METEOR_FALLS_B1F_1R

MeteorFalls_1F_2R_MapBGEvents: @ 853412C
	bg_event 9, 58, 0, 0, 0, 0x0

MeteorFalls_1F_2R_MapEvents:: @ 8534138
	map_events MeteorFalls_1F_2R_EventObjects, MeteorFalls_1F_2R_MapWarps, 0x0, MeteorFalls_1F_2R_MapBGEvents

