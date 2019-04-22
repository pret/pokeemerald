TerraCave_Entrance_MapScripts:: @ 823B0A6
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_Entrance_OnTransition
	.byte 0

TerraCave_Entrance_OnTransition: @ 823B0AC
	setflag FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
	end

