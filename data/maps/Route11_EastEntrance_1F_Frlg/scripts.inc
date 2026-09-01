Route11_EastEntrance_1F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

@ Unclear where this is originally from
Route11_EastEntrance_1F_Text_BagIsFull::
	.string "{PLAYER}{KUN}の　バッグ\n"
	.string "いっぱい　みたい　だね$"

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
	.string "Don't you think it's hard to think\n"
	.string "up good names for POKéMON?\p"
	.string "Especially if you've caught a\n"
	.string "whole bunch?\p"
	.string "In LAVENDER TOWN, there's a man\n"
	.string "who rates POKéMON nicknames.\p"
	.string "He can even help you rename your\n"
	.string "POKéMON, too.$"

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
	.string "If you're aiming to reach LAVENDER\n"
	.string "TOWN, take ROCK TUNNEL.\p"
	.string "You can get to ROCK TUNNEL from\n"
	.string "CERULEAN CITY.$"

