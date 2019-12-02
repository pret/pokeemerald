Underwater5_MapScripts:: @ 81F7731
	map_script MAP_SCRIPT_ON_RESUME, Underwater5_OnResume
	.byte 0

Underwater5_OnResume: @ 81F7737
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

