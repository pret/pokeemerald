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
	.string "That Dr. Amigo, he isn't a real doctor,\n"
	.string "you know. Don't let him touch you.\p"
	.string "I made that mistake once and now\n"
	.string "I'm circumcised!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "I'm sorry sweetie, but this is\n"
	.string "the only place that our insurance\p"
	.string "said was covered!$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Yo, who the fuck is this, mom?!\n"
	.string "We could've gone to a real doctor\p"
	.string "but no! You had to go to Doctor Amigo!\n"
	.string "Jesus Christ!$"

