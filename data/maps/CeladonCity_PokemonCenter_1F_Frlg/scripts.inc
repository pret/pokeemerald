CeladonCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeladonCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons::
	.string "A POKé FLUTE awakens sleeping\n"
	.string "POKéMON. You know that.\p"
	.string "It does so with a sound that only\n"
	.string "they can hear.$"

CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia::
	.string "I rode here from FUCHSIA.\p"
	.string "It's an uphill ride on CYCLING\n"
	.string "ROAD, so I'm exhausted.$"

CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike::
	.string "If I had a BIKE, I would go to\n"
	.string "CYCLING ROAD!$"

