NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	.byte 0

NavelRock_Exterior_OnTransition:
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end

