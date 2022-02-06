ChoiceMap6_MapScripts::
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, ChoiceMap6_OnIntroTrainers
	.byte 0

ChoiceMap6_OnIntroTrainers::
	declarewildmon 1
	declarenpc 2
	declaretrainer 3, 0
	declaretrainer 4, 0
	declarenpc 5
	declarewildmon 6
	end
