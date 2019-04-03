ScorchedSlab_MapScripts:: @ 8239291
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_MapScript1_SetLandmark
	.byte 0

ScorchedSlab_MapScript1_SetLandmark: @ 8239297
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end

