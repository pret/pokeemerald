EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Je suis le dernier du CONSEIL 4,\n"
	.string "ARAGON, le maître DRAGON.\p"
	.string "A l’état naturel, les POKéMON sont des\n"
	.string "créatures sauvages. Ils sont libres.\p"
	.string "Parfois, ils nous font obstacle.\n"
	.string "Parfois, ils nous aident.\p"
	.string "Combattre en s’alliant avec les\n"
	.string "POKéMON, tu sais ce que ça représente?\p"
	.string "Tu sais ce qu’il faut pour y parvenir?\p"
	.string "Si tu ne le sais pas, alors tu ne pourras\n"
	.string "jamais me dominer!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Superbe! Ça vaut la peine d’être dit!$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Quel mérite d’avoir fait tout ce chemin\n"
	.string "en tant que DRESSEUR de POKéMON!\p"
	.string "Tu sembles avoir la qualité que\n"
	.string "possèdent les vrais DRESSEURS.\p"
	.string "Oui, ce qu’un DRESSEUR doit avoir, c’est\n"
	.string "un cœur vertueux.\p"
	.string "Les POKéMON touchent le cœur vertueux\n"
	.string "des DRESSEURS et apprennent le bien.\p"
	.string "Ils touchent le cœur vertueux des\n"
	.string "DRESSEURS et deviennent forts.\p"
	.string "Allez, en avant!\n"
	.string "Le MAITRE t’attend!$"

