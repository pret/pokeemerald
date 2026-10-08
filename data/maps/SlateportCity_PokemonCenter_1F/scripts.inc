SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
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
	.string "Wil je een tip voor gevechten?\p"
	.string "Train verschillende soorten\n"
	.string "POKéMON, allemaal even goed.\p"
	.string "Het is niet slim om maar één\n"
	.string "POKéMON sterk te maken.\p"
	.string "Als het type slecht uitkomt,\n"
	.string "maakt hij misschien geen kans.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Ik ruil POKéMON met mijn vrienden.\p"
	.string "Als een geruilde POKéMON een voorwerp\n"
	.string "vasthoudt, ben ik dubbel blij!$"

