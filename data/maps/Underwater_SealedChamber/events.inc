Underwater_SealedChamber_MapWarps: @ 8536D60
	warp_def 7, 1, 0, 0, MAP_UNDERWATER_ROUTE134

Underwater_SealedChamber_MapBGEvents: @ 8536D68
	bg_event 12, 43, 0, BG_EVENT_PLAYER_FACING_ANY, Underwater_SealedChamber_EventScript_2390FC

Underwater_SealedChamber_MapEvents:: @ 8536D74
	map_events 0x0, Underwater_SealedChamber_MapWarps, 0x0, Underwater_SealedChamber_MapBGEvents

