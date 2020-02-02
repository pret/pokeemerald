CaveOfOrigin_Entrance_MapScripts:: @ 8235759
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_Entrance_OnResume
	.byte 0

CaveOfOrigin_Entrance_OnResume: @ 823575F
	setescapewarp MAP_SOOTOPOLIS_CITY, 255, 31, 17
	end

