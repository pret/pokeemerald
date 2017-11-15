SealedChamber_InnerRoom_MapWarps: @ 8536F00
	warp_def 10, 19, 3, 0, SEALED_CHAMBER_OUTER_ROOM

SealedChamber_InnerRoom_MapBGEvents: @ 8536F08
	bg_event 10, 4, 0, 0, 0, SealedChamber_InnerRoom_EventScript_2391F8
	bg_event 6, 8, 0, 0, 0, SealedChamber_InnerRoom_EventScript_239255
	bg_event 14, 8, 0, 0, 0, SealedChamber_InnerRoom_EventScript_23925F
	bg_event 4, 13, 0, 0, 0, SealedChamber_InnerRoom_EventScript_239269
	bg_event 16, 13, 0, 0, 0, SealedChamber_InnerRoom_EventScript_239273
	bg_event 6, 18, 0, 0, 0, SealedChamber_InnerRoom_EventScript_23927D
	bg_event 14, 18, 0, 0, 0, SealedChamber_InnerRoom_EventScript_239287
	bg_event 9, 4, 0, 0, 0, SealedChamber_InnerRoom_EventScript_2391F8
	bg_event 11, 4, 0, 0, 0, SealedChamber_InnerRoom_EventScript_2391F8

SealedChamber_InnerRoom_MapEvents:: @ 8536F74
	map_events 0x0, SealedChamber_InnerRoom_MapWarps, 0x0, SealedChamber_InnerRoom_MapBGEvents

