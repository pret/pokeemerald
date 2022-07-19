.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Une petite astuce pour combattre?\p"
	.string "Il faut faire progresser divers types\n"
	.string "de POKéMON en même temps.\p"
	.string "Ce n’est pas bien d’avoir un seul\n"
	.string "POKéMON qui soit fort.\p"
	.string "S’il a un handicap à cause de son type,\n"
	.string "il n’aura aucune chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "J’échange des POKéMON avec mes amis.\p"
	.string "Quand le POKéMON échangé porte\n"
	.string "un objet, je suis encore plus contente.$"

