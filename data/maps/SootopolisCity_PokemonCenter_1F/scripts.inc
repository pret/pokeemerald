.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts:: @ 82264F1
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition: @ 82264FC
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse:: @ 8226500
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman:: @ 822650E
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries:: @ 822652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman:: @ 8226538
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries:: @ 8226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn: @ 8226562
	.string "Wallace is rumored to be the toughest\n"
	.string "Trainer in the whole Hoenn region.\p"
	.string "This town's Gym is led by the Trainer\n"
	.string "who taught Wallace.\p"
	.string "But the Elite Four… They're said to be\n"
	.string "even stronger than Wallace's mentor.\p"
	.string "How strong could they be?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge: @ 822664B
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon: @ 82266B9
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "Pokémon.\p"
	.string "Because it's fun to be with Pokémon!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends: @ 822672F
	.string "Aren't Pokémon our friends?\p"
	.string "Why are they going wild this way?$"

