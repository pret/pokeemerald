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
	.string "Ecoute, mon petit, est-ce que tu\n"
	.string "travailles sur un POKéDEX?\p"
	.string "Hum… Va au PARC SAFARI, sur la\n"
	.string "ROUTE 121! C’est mon conseil.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Tu as déjà fait quelque chose au\n"
	.string "CENTRE DE DONNEES?\p"
	.string "C’est ingénieux. Ça permet d’échanger\n"
	.string "des données entre DRESSEURS.\p"
	.string "Je sais pas trop comment ça marche,\n"
	.string "mais c’est cool. C’est même génial!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Hé, tu as un POKéNAV!\n"
	.string "C’est le même que le mien!\p"
	.string "Tu connais la fonction MATCH PHONE?\p"
	.string "Utilise-la pour tchater avec les\n"
	.string "DRESSEURS que tu auras enregistrés.\p"
	.string "Cette option t’indique aussi les\n"
	.string "DRESSEURS souhaitant une revanche.\p"
	.string "C’est pas génial?\n"
	.string "Y a pas mieux que DEVON!$"

