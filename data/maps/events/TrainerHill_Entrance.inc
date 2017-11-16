TrainerHill_Entrance_MapObjects: @ 853D874
	object_event 1, MAP_OBJ_GFX_TEALA, 0, 0, 11, 6, 3, 9, 17, 0, 0, 0, TrainerHill_Entrance_EventScript_2681FD, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_NURSE, 0, 0, 4, 9, 3, 8, 17, 0, 0, 0, TrainerHill_Entrance_EventScript_2681EF, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MART_EMPLOYEE, 0, 0, 14, 9, 3, 8, 17, 0, 0, 0, TrainerHill_Entrance_EventScript_2683C7, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_GIRL_3, 0, 0, 5, 14, 3, 2, 17, 0, 0, 0, TrainerHill_Entrance_EventScript_2683AC, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_MAN_4, 0, 0, 14, 15, 3, 2, 17, 0, 0, 0, TrainerHill_Entrance_EventScript_268391, 0, 0, 0

TrainerHill_Entrance_MapWarps: @ 853D8EC
	warp_def 9, 16, 3, 4, ROUTE_111
	warp_def 10, 16, 3, 4, ROUTE_111
	warp_def 9, 1, 3, 0, TRAINER_HILL_1F

TrainerHill_Entrance_MapCoordEvents: @ 853D904
	coord_event 9, 6, 3, 0, VAR_0x40D6, 0, 0, TrainerHill_Entrance_EventScript_268229

TrainerHill_Entrance_MapBGEvents: @ 853D914
	bg_event 8, 10, 0, 1, 0, TrainerHill_Entrance_EventScript_268388

TrainerHill_Entrance_MapEvents:: @ 853D920
	map_events TrainerHill_Entrance_MapObjects, TrainerHill_Entrance_MapWarps, TrainerHill_Entrance_MapCoordEvents, TrainerHill_Entrance_MapBGEvents

