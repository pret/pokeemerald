MarineCave_Entrance_MapScripts:: @ 823AFD0
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_Entrance_OnResume
	.byte 0

MarineCave_Entrance_OnResume: @ 823AFD6
	setdivewarp MAP_UNDERWATER_MARINE_CAVE, 255, 9, 6
	end

