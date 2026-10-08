VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Je bent geen echte TRAINER als\n"
	.string "je niet in je POKéMON\l"
	.string "gelooft.\p"
	.string "Alleen wie gelooft in zijn\n"
	.string "POKéMON, kan tot het einde\l"
	.string "blijven winnen.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Waarom zou iemand naar\n"
	.string "VERDANTURF komen…\p"
	.string "Voor de BATTLE TENT natuurlijk.\n"
	.string "Dat is toch logisch.\p"
	.string "Of kom je hier iemand\n"
	.string "opzoeken?$"

