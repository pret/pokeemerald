EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition: @ 8229A3F
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_1
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_229A4C
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A4C:: @ 8229A4C
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_229A59:: @ 8229A59
	setvar VAR_0x800B, 1
	call EverGrandeCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A67:: @ 8229A67
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229ADA, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A70:: @ 8229A70
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229B62, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A79:: @ 8229A79
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229BF1, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AB6
	compare VAR_FACING, 4
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	compare VAR_FACING, 3
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_KAIDAN
	waitse
	removeobject 4
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229AB6:: @ 8229AB6
	applymovement 4, EverGrandeCity_PokemonCenter_1F_Movement_229ACC
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_229AC1:: @ 8229AC1
	applymovement 4, EverGrandeCity_PokemonCenter_1F_Movement_229AD3
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_229ACC: @ 8229ACC
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_229AD3: @ 8229AD3
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_229ADA: @ 8229ADA
	.string "The POKéMON LEAGUE is only a short\n"
	.string "distance after the VICTORY ROAD.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?$"

EverGrandeCity_PokemonCenter_1F_Text_229B62: @ 8229B62
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_229BF1: @ 8229BF1
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"

