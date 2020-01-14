AbandonedShip_Underwater2_MapScripts:: @ 823895D
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
	.byte 0

AbandonedShip_Underwater2_OnResume: @ 8238963
	setdivewarp MAP_ABANDONED_SHIP_ROOMS_B1F, 255, 13, 7
	end

