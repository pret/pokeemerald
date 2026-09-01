PokemonMansion_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_1F_OnTransition
	.byte 0

PokemonMansion_1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_1F
	end

PokemonMansion_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_MANSION_1F
	end

PokemonMansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat
	msgbox PokemonMansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_TedIntro::
	.string "Who are you?\n"
	.string "There shouldn't be anyone here.$"

PokemonMansion_1F_Text_TedDefeat::
	.string "Ouch!$"

PokemonMansion_1F_Text_TedPostBattle::
	.string "A key? I don't know what you're\n"
	.string "talking about.$"

PokemonMansion_1F_Text_JohnsonIntro::
	.string "W-w-waah! You startled me!\n"
	.string "I thought you were a ghost.$"

PokemonMansion_1F_Text_JohnsonDefeat::
	.string "Tch!\n"
	.string "I can't get any wins.$"

PokemonMansion_1F_Text_JohnsonPostBattle::
	.string "I was exploring here by myself,\n"
	.string "but I feel spooked.\p"
	.string "I ought to go soon.$"

