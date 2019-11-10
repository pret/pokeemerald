AbandonedShip_Underwater1_MapScripts:: @ 8238096
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater1_OnResume
	.byte 0

AbandonedShip_Underwater1_OnResume: @ 823809C
	setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 255, 0, 10
	end

