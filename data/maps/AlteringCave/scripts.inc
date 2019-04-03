AlteringCave_MapScripts:: @ 823B177
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_MapScript1_SetLandmark
	.byte 0

AlteringCave_MapScript1_SetLandmark: @ 823B17D
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

