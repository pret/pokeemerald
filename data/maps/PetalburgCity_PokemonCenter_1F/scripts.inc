PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
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
	.string "Dat POKéMON-opslagsysteem op\n"
	.string "de PC…\p"
	.string "Wie dat heeft gemaakt, is echt\n"
	.string "een tovenaar in wetenschap!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Toen mijn POKéMON een ORAN BES\n"
	.string "at, kreeg hij HP terug!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Er zijn veel soorten POKéMON.\p"
	.string "Elk type is sterk en zwak tegen\n"
	.string "andere types.\p"
	.string "Hangt af van de types: een gevecht\n"
	.string "kan makkelijk of moeilijk zijn.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Je TREECKO is bijvoorbeeld\n"
	.string "een GRAS-type.\p"
	.string "Hij is sterk tegen WATER en\n"
	.string "GROND.\p"
	.string "Maar hij is zwak tegen\n"
	.string "VUUR-POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Je TORCHIC is bijvoorbeeld\n"
	.string "een VUUR-type.\p"
	.string "Hij is sterk tegen GRAS en\n"
	.string "INSECT.\p"
	.string "Maar hij is zwak tegen\n"
	.string "WATER-POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Je MUDKIP is bijvoorbeeld\n"
	.string "een WATER-type.\p"
	.string "Hij is sterk tegen VUUR.\p"
	.string "Maar hij is zwak tegen GRAS-\n"
	.string "en ELEKTRISCHE POKéMON.$"

