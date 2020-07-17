.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ 820273A
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon: @ 820275A
	.string "You can't consider yourself a real\n"
	.string "TRAINER if you don't have faith\l"
	.string "in your POKéMON.\p"
	.string "Only those people who can believe\n"
	.string "in their battling POKéMON can win\l"
	.string "through to the very end.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "VERDANTURF…\p"
	.string "It's the BATTLE TENT. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"

