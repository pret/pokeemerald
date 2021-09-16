MarineCave_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_Entrance_OnResume
	.byte 0

MarineCave_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_MARINE_CAVE, 255, 9, 6
	end

