Underwater_MarineCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_OnTransition
	.byte 0

Underwater_MarineCave_OnTransition:
	setflag FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT
	end

Underwater_MarineCave_OnResume:
	setdivewarp MAP_MARINE_CAVE_ENTRANCE, 255, 10, 17
	end

