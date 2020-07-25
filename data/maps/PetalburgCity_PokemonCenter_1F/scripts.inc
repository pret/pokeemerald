.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts:: @ 82079E8
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition: @ 82079F3
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ 82079FC
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ 8207A0A
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ 8207A13
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ 8207A1C
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo:: @ 8207A38
	compare VAR_STARTER_MON, 0
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	compare VAR_STARTER_MON, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	compare VAR_STARTER_MON, 2
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType:: @ 8207A5B
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType:: @ 8207A64
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType:: @ 8207A6D
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem: @ 8207A76
	.string "That PC-based Pokémon Storage\n"
	.string "System…\p"
	.string "Whoever made it must be some kind\n"
	.string "of a scientific wizard!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP: @ 8207AD6
	.string "When my Pokémon ate an\n"
	.string "Oran Berry, it regained HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon: @ 8207B09
	.string "There are many types of Pokémon.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of Pokémon,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType: @ 8207BB0
	.string "For example, your Treecko\n"
	.string "is a Grass type.\p"
	.string "It's strong against the Water and\n"
	.string "Ground types.\p"
	.string "But, it's weak against Fire-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType: @ 8207C35
	.string "For example, your Torchic\n"
	.string "is a Fire type.\p"
	.string "It's strong against the Grass and\n"
	.string "Bug types.\p"
	.string "But, it's weak against Water-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType: @ 8207CB7
	.string "For example, your Mudkip\n"
	.string "is a Water type.\p"
	.string "It's strong against the Fire type.\p"
	.string "But, it's weak against Grass-type\n"
	.string "and Electric-type Pokémon.$"

