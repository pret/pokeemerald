HealerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, HealerRoom_OnIntroTrainers
	.byte 0

HealerRoom_OnIntroTrainers::
	declarenpc 1, 0
	declareitem 2
	declaretrainer 3, 0, 4
	declaretrainer 4, 0, 3
	end
