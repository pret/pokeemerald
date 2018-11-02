BattleFrontier_ReceptionGate_EventObjects: @ 853D420
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 11, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_ReceptionGate_EventScript_2662FC, 0
	object_event 2, EVENT_OBJ_GFX_TEALA, 0, 8, 11, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_ReceptionGate_EventScript_266310, 0
	object_event 3, EVENT_OBJ_GFX_MAN_2, 0, 8, 4, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_ReceptionGate_EventScript_266436, 0
	object_event 4, EVENT_OBJ_GFX_SCOTT, 0, 4, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT
	object_event 5, EVENT_OBJ_GFX_MAN_2, 0, 0, 4, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_ReceptionGate_EventScript_2664F4, 0

BattleFrontier_ReceptionGate_MapWarps: @ 853D498
	warp_def 4, 13, 0, 8, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 4, 1, 0, 9, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_ReceptionGate_MapEvents:: @ 853D4A8
	map_events BattleFrontier_ReceptionGate_EventObjects, BattleFrontier_ReceptionGate_MapWarps, 0x0, 0x0

