SkyPillar_Entrance_MapScripts:: @ 823929E
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Entrance_OnTransition
	.byte 0

SkyPillar_Entrance_OnTransition: @ 82392A4
	setflag FLAG_LANDMARK_SKY_PILLAR
	end

