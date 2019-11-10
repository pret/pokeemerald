Underwater_MarineCave_MapScripts:: @ 823AFB8
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_OnTransition
	.byte 0

Underwater_MarineCave_OnTransition: @ 823AFC3
	setflag FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT
	end

Underwater_MarineCave_OnResume: @ 823AFC7
	setdivewarp MAP_MARINE_CAVE_ENTRANCE, 255, 10, 17
	end

