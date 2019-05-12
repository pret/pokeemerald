NavelRock_Exterior_MapScripts:: @ 82690B2
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	.byte 0

NavelRock_Exterior_OnTransition: @ 82690B8
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end

