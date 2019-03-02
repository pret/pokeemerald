Underwater7_MapScripts:: @ 81F7749
	map_script MAP_SCRIPT_ON_RESUME, Underwater7_MapScript1_1F774F
	.byte 0

Underwater7_MapScript1_1F774F: @ 81F774F
	call UnusualWeather_Underwater_SetupEscapeWarp
	end

