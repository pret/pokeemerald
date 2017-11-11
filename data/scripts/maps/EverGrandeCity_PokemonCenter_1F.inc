EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
	map_script 3, EverGrandeCity_PokemonCenter_1F_MapScript1_229A3F
	map_script 5, EverGrandeCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

EverGrandeCity_PokemonCenter_1F_MapScript1_229A3F: @ 8229A3F
	setrespawn 11
	checkflag FLAG_0x1CF
	call_if 0, EverGrandeCity_PokemonCenter_1F_EventScript_229A4C
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A4C:: @ 8229A4C
	checkflag FLAG_BADGE06_GET
	goto_if 0, EverGrandeCity_PokemonCenter_1F_EventScript_27374E
	clearflag FLAG_0x319
	return

EverGrandeCity_PokemonCenter_1F_EventScript_229A59:: @ 8229A59
	setvar VAR_0x800B, 1
	call EverGrandeCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A67:: @ 8229A67
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229ADA, 2
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A70:: @ 8229A70
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229B62, 2
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A79:: @ 8229A79
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229BF1, 4
	closemessage
	compare_var_to_value VAR_FACING, 2
	call_if 1, EverGrandeCity_PokemonCenter_1F_EventScript_229AB6
	compare_var_to_value VAR_FACING, 4
	call_if 1, EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	compare_var_to_value VAR_FACING, 3
	call_if 1, EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	addvar VAR_0x40D1, 1
	setflag FLAG_0x1CF
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
	step_left
	step_down
	step_down
	step_left
	step_down
	step_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_229AD3: @ 8229AD3
	step_down
	step_down
	step_left
	step_left
	step_down
	step_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_229ADA: @ 8229ADA
	.string "The POKéMON LEAGUE is only a short\n"
	.string "distance after the VICTORY ROAD.\p"
	.string "If you’ve come this far, what choice\n"
	.string "do you have but to keep going?$"

EverGrandeCity_PokemonCenter_1F_Text_229B62: @ 8229B62
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It’s like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_229BF1: @ 8229BF1
	.string "SCOTT: {PLAYER}{KUN}, you’ve clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I’m happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I’ll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"

