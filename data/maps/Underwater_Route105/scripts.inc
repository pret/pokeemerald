Underwater_Route105_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route105_OnResume
	.byte 0

Underwater_Route105_OnResume:
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

