Underwater_Route127_MapScripts:: @ 81F7724
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_OnResume
	.byte 0

Underwater_Route127_OnResume: @ 81F772A
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

