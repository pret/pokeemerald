ScorchedSlab_MapScripts:: @ 8239291
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition: @ 8239297
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end

