FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
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
	.string "Luister, kind, werk je aan\n"
	.string "een POKéDEX?\p"
	.string "Hmm… Ga naar de SAFARI ZONE.\n"
	.string "Dat raad ik je aan.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Ben je al bij de\n"
	.string "RECORD CORNER geweest?\p"
	.string "Het is gaaf. Het mengt de\n"
	.string "records van TRAINERS.\p"
	.string "Ik snap niet hoe het werkt,\n"
	.string "maar het is spannend!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh wow, je hebt een POKéNAV!\n"
	.string "Precies zoals de mijne!\p"
	.string "Ken je het MATCH CALL-systeem\n"
	.string "van de POKéNAV?\p"
	.string "Daarmee kun je altijd praten met\n"
	.string "opgeslagen TRAINERS.\p"
	.string "Het laat ook zien welke TRAINERS\n"
	.string "weer met je willen vechten.\p"
	.string "Super handig! Die mensen van DEVON\n"
	.string "weten echt wat ze doen!$"

