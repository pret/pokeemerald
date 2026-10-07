RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
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
	.string "Mijn POKéMON is NAÏEF en die van\n"
	.string "mijn vriend is VROLIJK.\p"
	.string "Zo leuk dat POKéMON een eigen\n"
	.string "karakter hebben!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Net als mensen zijn er mannetjes-\n"
	.string "en vrouwtjes-POKéMON.\p"
	.string "Maar niemand weet echt wat het\n"
	.string "verschil is.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "De man hiernaast gaf me een HM!\p"
	.string "Daarmee leerde mijn POKéMON dunne\n"
	.string "boompjes weg te SNIJDEN.$"

