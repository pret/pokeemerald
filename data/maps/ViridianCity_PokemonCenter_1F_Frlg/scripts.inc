ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "Please feel free to use that PC in\n"
	.string "the corner.\p"
	.string "The receptionist told me so.\n"
	.string "It's so kind of her!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "There's a POKéMON CENTER in every\n"
	.string "town ahead.\p"
	.string "They charge no money, so don't\n"
	.string "be shy about healing POKéMON.$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "POKéMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKéMON.\p"
	.string "They make all POKéMON completely\n"
	.string "healthy.$"

