.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "That PC-based POKéMON Storage\n"
	.string "System…\p"
	.string "Whoever made it must be some kind\n"
	.string "of a scientific wizard!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "When my POKéMON ate an\n"
	.string "ORAN BERRY, it regained HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "There are many types of POKéMON.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of POKéMON,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For example, your TREECKO\n"
	.string "is a GRASS type.\p"
	.string "It's strong against the WATER and\n"
	.string "GROUND types.\p"
	.string "But, it's weak against FIRE-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For example, your TORCHIC\n"
	.string "is a FIRE type.\p"
	.string "It's strong against the GRASS and\n"
	.string "BUG types.\p"
	.string "But, it's weak against WATER-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For example, your MUDKIP\n"
	.string "is a WATER type.\p"
	.string "It's strong against the FIRE type.\p"
	.string "But, it's weak against GRASS-type\n"
	.string "and ELECTRIC-type POKéMON.$"

