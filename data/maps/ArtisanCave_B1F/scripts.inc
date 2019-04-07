ArtisanCave_B1F_MapScripts:: @ 823AFAD
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	.byte 0

ArtisanCave_B1F_OnTransition: @ 823AFB3
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end

