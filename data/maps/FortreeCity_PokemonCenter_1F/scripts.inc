.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Listen, kid, are you working\n"
	.string "on a Pokédex?\p"
	.string "Hmm… Go to the Safari Zone.\n"
	.string "That's my suggestion.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Have you done anything at\n"
	.string "the Record Corner?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of Trainers.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, you have a Pokénav!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about Pokénav's\n"
	.string "Match Call system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered Trainers anytime.\p"
	.string "It also shows you which Trainers\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those Devon guys\n"
	.string "sure know what they're doing!$"

