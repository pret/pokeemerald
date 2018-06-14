TrainerHill_Elevator_EventObjects: @ 853DD84
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 0, 6, 3, 8, 17, 0, 0, 0, TrainerHill_Elevator_EventScript_26935F, 0, 0, 0

TrainerHill_Elevator_MapWarps: @ 853DD9C
	warp_def 1, 6, 3, 1, TRAINER_HILL_ROOF
	warp_def 2, 6, 3, 1, TRAINER_HILL_ROOF

TrainerHill_Elevator_MapEvents:: @ 853DDAC
	map_events TrainerHill_Elevator_EventObjects, TrainerHill_Elevator_MapWarps, 0x0, 0x0

