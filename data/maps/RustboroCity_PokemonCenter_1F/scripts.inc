.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon POKéMON est NAIF et celui de mon\n"
	.string "ami est JOVIAL. C’est leur nature.\p"
	.string "C’est fascinant de voir comme les\n"
	.string "POKéMON ont leur caractère!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Tout comme chez les hommes, il existe\n"
	.string "des POKéMON mâles et femelles.\p"
	.string "Mais la différence entre les deux sexes\n"
	.string "ne saute pas aux yeux.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L’homme de la maison voisine m’a donné\n"
	.string "une CS!\p"
	.string "Je l’ai apprise à mon POKéMON pour\n"
	.string "qu’il COUPE les petits arbres.$"

