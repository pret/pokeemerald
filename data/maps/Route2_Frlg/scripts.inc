Route2_Frlg_MapScripts::
	.byte 0

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_Text_RouteSign::
	.string "ROUTE 2\n"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCave::
	.string "DIGLETT'S CAVE$"

