Route110_TrickHouseCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseCorridor_OnTransition
	.byte 0

Route110_TrickHouseCorridor_OnTransition:
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1
	end

