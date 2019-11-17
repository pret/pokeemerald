Underwater7_MapScripts:: @ 81F7749
	map_script MAP_SCRIPT_ON_RESUME, Underwater7_OnResume
	.byte 0

Underwater7_OnResume: @ 81F774F
	call UnusualWeather_Underwater_SetupEscapeWarp
	end

