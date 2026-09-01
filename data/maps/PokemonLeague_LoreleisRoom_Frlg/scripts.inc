PokemonLeague_LoreleisRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LoreleisRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LoreleisRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_LoreleisRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LoreleisRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LoreleisRoom_OnFrame
	.byte 0

PokemonLeague_LoreleisRoom_OnResume::
	setvar VAR_0x8004, 0
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LoreleisRoom_OnLoad::
	call_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	call_if_eq VAR_MAP_SCENE_POKEMON_LEAGUE, 1, PokemonLeague_LoreleisRoom_EventScript_CloseEntry
	end

PokemonLeague_LoreleisRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_LoreleisRoom_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	end

PokemonLeague_LoreleisRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_LoreleisRoom_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 0, PokemonLeague_LoreleisRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 1
	releaseall
	end

PokemonLeague_LoreleisRoom_EventScript_Lorelei::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_PostBattle
	famechecker FAMECHECKER_LORELEI, 0
	famechecker FAMECHECKER_LORELEI, 1
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Intro
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Rematch
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_EventScript_Intro::
	msgbox PokemonLeague_LoreleisRoom_Text_Intro
	return

PokemonLeague_LoreleisRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_LoreleisRoom_Text_RematchIntro
	return

PokemonLeague_LoreleisRoom_EventScript_Battle::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat
	return

PokemonLeague_LoreleisRoom_EventScript_Rematch::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI_2, PokemonLeague_LoreleisRoom_Text_Defeat
	return

PokemonLeague_LoreleisRoom_EventScript_PostBattle::
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei::
	setflag FLAG_DEFEATED_LORELEI
	call PokemonLeague_EventScript_OpenDoor
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_Text_Intro::
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "I am LORELEI of the ELITE FOUR.\p"
	.string "No one can best me when it comes\n"
	.string "to icy POKéMON.\p"
	.string "Freezing moves are powerful.\p"
	.string "Your POKéMON will be at my mercy\n"
	.string "when they are frozen solid.\p"
	.string "Hahaha!\n"
	.string "Are you ready?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_LoreleisRoom_Text_RematchIntro::
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "I, LORELEI of the ELITE FOUR,\n"
	.string "have returned!\p"
	.string "You know how it goes.\n"
	.string "No one can best me when it comes\l"
	.string "to icy POKéMON.\p"
	.string "Freezing moves are powerful.\p"
	.string "Your POKéMON will be at my mercy\n"
	.string "when they are frozen solid.\p"
	.string "Hahaha!\n"
	.string "Are you ready?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_LoreleisRoom_Text_Defeat::
	.string "…Things shouldn't be this way!$"

PokemonLeague_LoreleisRoom_Text_PostBattle::
	.string "You're better than I thought.\n"
	.string "Go on ahead.\p"
	.string "You only got a taste of the\n"
	.string "POKéMON LEAGUE's power.$"

