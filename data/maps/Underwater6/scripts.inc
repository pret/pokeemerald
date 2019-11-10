Underwater6_MapScripts:: @ 81F773D
	map_script MAP_SCRIPT_ON_RESUME, Underwater6_OnResume
	.byte 0

Underwater6_OnResume: @ 81F7743
	call UnusualWeather_Underwater_SetupEscapeWarp
	end

