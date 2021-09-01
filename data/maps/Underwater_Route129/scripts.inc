Underwater_Route129_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route129_OnResume
	.byte 0

Underwater_Route129_OnResume:
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

