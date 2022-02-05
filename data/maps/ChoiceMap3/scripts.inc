ChoiceMap3_MapScripts::
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, ChoiceMap3_OnIntroTrainers
	.byte 0

ChoiceMap3_OnIntroTrainers::
	declarewildmon 1
	declareitem 2
	declarewildmon 3
	declareitem 4
	declaretrainer 5, 0
	end
