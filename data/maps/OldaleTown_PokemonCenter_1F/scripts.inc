.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
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
	.string "Le PC dans le coin est à la\n"
	.string "disposition des DRESSEURS de POKéMON.\p"
	.string "Naturellement, tu peux l’utiliser\n"
	.string "quand tu veux.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Les CENTRES POKéMON sont géniaux!\p"
	.string "Tu peux utiliser leurs services autant\n"
	.string "que tu veux. En plus, c’est gratuit.\p"
	.string "Pas de souci!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "L’étage du CENTRE POKéMON\n"
	.string "vient d’être construit.\p"
	.string "Mais ils prétendent avoir encore besoin\n"
	.string "de faire quelques petits travaux.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "L’étage du CENTRE POKéMON\n"
	.string "vient d’être construit.\p"
	.string "J’y ai tout de suite échangé des\n"
	.string "POKéMON.$"

