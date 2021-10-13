Underwater_Route105_MapScripts:: @ 81F773D
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route105_OnResume
	.byte 0

Underwater_Route105_OnResume: @ 81F7743
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

