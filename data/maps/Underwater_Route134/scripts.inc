Underwater_Route134_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route134_OnResume
	.byte 0

Underwater_Route134_OnResume:
	setdivewarp MAP_ROUTE134, 255, 60, 31
	end

