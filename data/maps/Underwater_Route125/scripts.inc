Underwater_Route125_MapScripts:: @ 81F7749
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route125_OnResume
	.byte 0

Underwater_Route125_OnResume: @ 81F774F
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

