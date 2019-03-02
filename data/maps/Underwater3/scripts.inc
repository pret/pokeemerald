Underwater3_MapScripts:: @ 81F7724
	map_script MAP_SCRIPT_ON_RESUME, Underwater3_MapScript1_1F772A
	.byte 0

Underwater3_MapScript1_1F772A: @ 81F772A
	call UnusualWeather_Underwater_SetupEscapeWarp
	end

