Underwater3_MapScripts:: @ 81F7724
	map_script MAP_SCRIPT_ON_RESUME, Underwater3_OnResume
	.byte 0

Underwater3_OnResume: @ 81F772A
	call UnusualWeather_Underwater_SetupEscapeWarp
	end

