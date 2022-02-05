ChoiceMap1_MapScripts::
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, ChoiceMap1_OnIntroTrainers
	.byte 0

ChoiceMap1_OnIntroTrainers::
	declaretrainer 1, 0
	declaretrainer 2, 0
	declareitem 3
	declareitem 4
	declarewildmon 5
	declarewildmon 6
	end
