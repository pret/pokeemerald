PitWildEncounterFloor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitWildEncounterFloor_OnTransition
	.byte 0

PitWildEncounterFloor_OnTransition:
	callnative TrySetRandomMusic
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 0
	return
