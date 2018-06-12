Route113_GlassWorkshop_EventObjects: @ 853EA78
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 0, 2, 3, 3, 8, 0, 0, 0, 0, Route113_GlassWorkshop_EventScript_26ED1E, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 0, 5, 4, 3, 2, 17, 0, 0, 0, Route113_GlassWorkshop_EventScript_26F194, 0, 0, 0

Route113_GlassWorkshop_MapWarps: @ 853EAA8
	warp_def 3, 8, 0, 0, ROUTE_113
	warp_def 4, 8, 0, 0, ROUTE_113

Route113_GlassWorkshop_MapEvents:: @ 853EAB8
	map_events Route113_GlassWorkshop_EventObjects, Route113_GlassWorkshop_MapWarps, 0x0, 0x0

