TrainerHill_Elevator_EventObjects:
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, TrainerHill_Elevator_EventScript_26935F, 0

TrainerHill_Elevator_MapWarps:
	warp_def 1, 6, 3, 1, MAP_TRAINER_HILL_ROOF
	warp_def 2, 6, 3, 1, MAP_TRAINER_HILL_ROOF

TrainerHill_Elevator_MapEvents::
	map_events TrainerHill_Elevator_EventObjects, TrainerHill_Elevator_MapWarps, 0x0, 0x0

