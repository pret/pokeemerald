AlteringCave_MapScripts:: @ 823B177
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition: @ 823B17D
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

