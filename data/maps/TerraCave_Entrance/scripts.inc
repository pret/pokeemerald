TerraCave_Entrance_MapScripts:: @ 823B0A6
	map_script EVENT_TAG_ON_MAP_TRANSITION, TerraCave_Entrance_MapScript1_23B0AC
	.byte 0

TerraCave_Entrance_MapScript1_23B0AC: @ 823B0AC
	setflag FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
	end

