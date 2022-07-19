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
	.string "Ce système de stockage de POKéMON\n"
	.string "sur PC…\p"
	.string "Celui qui l’a inventé doit être\n"
	.string "une sorte de génie de la science!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Quand mon POKéMON mange une\n"
	.string "BAIE ORAN, il récupère des PV!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Il existe de nombreux types de POKéMON.\p"
	.string "Chaque type a ses forces et ses\n"
	.string "faiblesses face aux autres types.\p"
	.string "Selon les types de POKéMON,\n"
	.string "le combat peut être facile ou difficile.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Par exemple, ton ARCKO est un\n"
	.string "POKéMON du type PLANTE.\p"
	.string "Il est fort contre les POKéMON \n"
	.string "des types EAU et SOL.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "du type FEU.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Par exemple, ton POUSSIFEU est un\n"
	.string "POKéMON du type FEU.\p"
	.string "Il est fort contre les POKéMON \n"
	.string "des types PLANTE et INSECTE.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "du type EAU.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Par exemple, ton GOBOU est un\n"
	.string "POKéMON du type EAU.\p"
	.string "Il est fort contre les POKéMON \n"
	.string "du type FEU.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "des types PLANTE et ELECTRIK.$"

