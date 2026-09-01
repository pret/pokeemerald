SixIsland_GreenPath_Frlg_MapScripts::
	.byte 0

SixIsland_GreenPath_EventScript_RightRouteSign::
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_Text_JaclynIntro::
	.string "…Huh?\p"
	.string "I was envisioning my house, but\n"
	.string "this is where I TELEPORT?$"

SixIsland_GreenPath_Text_JaclynDefeat::
	.string "Big boo-boo!$"

SixIsland_GreenPath_Text_JaclynPostBattle::
	.string "I am so scatterbrained!\p"
	.string "I need to focus so I can TELEPORT\n"
	.string "properly to my house!$"

SixIsland_GreenPath_Text_LeftRouteSign::
	.string "GREEN PATH\n"
	.string "PATTERN BUSH AHEAD$"

SixIsland_GreenPath_Text_RightRouteSign::
	.string "GREEN PATH\n"
	.string "Think Green, Keep Nature Clean!$"

