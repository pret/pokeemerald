.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "J’ai vu quelqu’un utiliser un POKéMON\n"
	.string "que je ne connaissais pas!\p"
	.string "En tout cas, je n’en avais jamais\n"
	.string "entendu parler à l’ECOLE DE DRESSEURS.\p"
	.string "Je me demande bien où tu peux\n"
	.string "attraper ce genre de POKéMON.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Bien! Prochain arrêt, le DOJO DE COMBAT!\n"
	.string "Je vais prendre des POKéMON du système\l"
	.string "de Gestion de Stocks de POKéMON.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Hi, hi, hi… Je vais relever tous\n"
	.string "les défis avec mon bébé!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Kiiiiity!$"

