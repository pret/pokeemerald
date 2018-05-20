Route121_SafariZoneEntrance_MapObjects: @ 8533EDC
	object_event 1, MAP_OBJ_GFX_PICNICKER, 0, 0, 17, 9, 3, 9, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_22BBE6, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_CAMPER, 0, 0, 10, 2, 3, 8, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_22BBEF, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_CAMPER, 0, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0, 0, 0, 0

Route121_SafariZoneEntrance_MapWarps: @ 8533F24
	warp_def 2, 5, 0, 0, SAFARI_ZONE_SOUTH
	warp_def 3, 5, 0, 0, SAFARI_ZONE_SOUTH
	warp_def 14, 13, 0, 0, ROUTE_121
	warp_def 15, 13, 0, 0, ROUTE_121

Route121_SafariZoneEntrance_MapCoordEvents: @ 8533F44
	coord_event 8, 4, 3, 0, VAR_TEMP_1, 0, 0, Route121_SafariZoneEntrance_EventScript_22BC18

Route121_SafariZoneEntrance_MapBGEvents: @ 8533F54
	bg_event 15, 1, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_22BD21

Route121_SafariZoneEntrance_MapEvents:: @ 8533F60
	map_events Route121_SafariZoneEntrance_MapObjects, Route121_SafariZoneEntrance_MapWarps, Route121_SafariZoneEntrance_MapCoordEvents, Route121_SafariZoneEntrance_MapBGEvents

