BattleFrontier_ReceptionGate_EventObjects: @ 853D420
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 0, 11, 0, 10, 17, 0, 0, 0, BattleFrontier_ReceptionGate_EventScript_2662FC, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_TEALA, 0, 0, 8, 11, 0, 9, 17, 0, 0, 0, BattleFrontier_ReceptionGate_EventScript_266310, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_MAN_2, 0, 0, 8, 4, 0, 9, 17, 0, 0, 0, BattleFrontier_ReceptionGate_EventScript_266436, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_SCOTT, 0, 0, 4, 5, 3, 8, 17, 0, 0, 0, 0x0, 836, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAN_2, 0, 0, 0, 4, 0, 10, 17, 0, 0, 0, BattleFrontier_ReceptionGate_EventScript_2664F4, 0, 0, 0

BattleFrontier_ReceptionGate_MapWarps: @ 853D498
	warp_def 4, 13, 0, 8, BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 4, 1, 0, 9, BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_ReceptionGate_MapEvents:: @ 853D4A8
	map_events BattleFrontier_ReceptionGate_EventObjects, BattleFrontier_ReceptionGate_MapWarps, 0x0, 0x0

