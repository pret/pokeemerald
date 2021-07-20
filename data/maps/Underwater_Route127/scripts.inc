Underwater_Route127_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_OnResume
	.byte 0

Underwater_Route127_OnResume:
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

