SealedChamber_OuterRoom_MapWarps: @ 8536D88
	warp_def 10, 2, 3, 0, MAP_SEALED_CHAMBER_INNER_ROOM

SealedChamber_OuterRoom_MapBGEvents: @ 8536D90
	bg_event 5, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23916C
	bg_event 5, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239176
	bg_event 5, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239180
	bg_event 5, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23918A
	bg_event 11, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239194
	bg_event 11, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23919E
	bg_event 11, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391A8
	bg_event 11, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391BC
	bg_event 16, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391B2
	bg_event 16, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391C6
	bg_event 10, 2, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391D0
	bg_event 6, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23916C
	bg_event 4, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23916C
	bg_event 4, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239176
	bg_event 6, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239176
	bg_event 4, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239180
	bg_event 6, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239180
	bg_event 4, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23918A
	bg_event 6, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23918A
	bg_event 10, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239194
	bg_event 12, 6, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_239194
	bg_event 10, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23919E
	bg_event 12, 9, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_23919E
	bg_event 10, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391A8
	bg_event 12, 12, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391A8
	bg_event 10, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391BC
	bg_event 12, 15, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391BC
	bg_event 9, 2, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391ED
	bg_event 11, 2, 0, BG_EVENT_PLAYER_FACING_ANY, SealedChamber_OuterRoom_EventScript_2391ED

SealedChamber_OuterRoom_MapEvents:: @ 8536EEC
	map_events 0x0, SealedChamber_OuterRoom_MapWarps, 0x0, SealedChamber_OuterRoom_MapBGEvents

