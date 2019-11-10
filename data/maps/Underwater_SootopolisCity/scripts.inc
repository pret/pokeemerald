Underwater_SootopolisCity_MapScripts:: @ 822D94C
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SootopolisCity_OnResume
	.byte 0

Underwater_SootopolisCity_OnResume: @ 822D952
	setdivewarp MAP_SOOTOPOLIS_CITY, 255, 29, 53
	end

