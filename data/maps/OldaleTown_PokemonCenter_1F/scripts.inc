OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Die PC in de hoek mag elke\n"
	.string "POKéMON TRAINER gebruiken.\p"
	.string "Dus jij mag hem natuurlijk\n"
	.string "ook gebruiken.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS zijn geweldig!\p"
	.string "Je mag er zo vaak komen als je wilt,\n"
	.string "en het is helemaal gratis.\l"
	.string "Je hoeft je nergens zorgen om te maken!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "De POKéMON WIRELESS CLUB op\n"
	.string "de eerste verdieping is net nieuw.\p"
	.string "Maar ze zijn er nog mee\n"
	.string "bezig.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "De POKéMON WIRELESS CLUB op\n"
	.string "de eerste verdieping is net nieuw.\p"
	.string "Ik heb meteen POKéMON geruild.$"

