EverGrandeCity_PokemonLeague_1F_MapScripts:: @ 82295D2
	map_script 3, EverGrandeCity_PokemonLeague_1F_MapScript1_2295DD
	map_script 5, EverGrandeCity_PokemonLeague_1F_MapScript1_277C30
	.byte 0

EverGrandeCity_PokemonLeague_1F_MapScript1_2295DD: @ 82295DD
	setrespawn 20
	setflag FLAG_SYS_POKEMON_LEAGUE_FLY
	checkflag FLAG_0x107
	call_if 0, EverGrandeCity_PokemonLeague_1F_EventScript_2295ED
	end

EverGrandeCity_PokemonLeague_1F_EventScript_2295ED:: @ 82295ED
	setobjectxyperm 3, 9, 2
	setobjectxyperm 4, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_2295FC:: @ 82295FC
	setvar VAR_0x800B, 1
	call EverGrandeCity_PokemonLeague_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_22960A:: @ 822960A
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart_229624
	msgbox gUnknown_08272A3F, 4
	release
	end

	.incbin "baserom.gba", 0x229621, 0x3

EverGrandeCity_PokemonLeague_1F_Pokemart_229624: @ 8229624
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_229636:: @ 8229636
	lockall
	checkflag FLAG_0x107
	goto_eq EverGrandeCity_PokemonLeague_1F_EventScript_2296BB
	getplayerxy VAR_0x4000, VAR_0x4001
	compare_var_to_value VAR_0x4000, 11
	call_if 4, EverGrandeCity_PokemonLeague_1F_EventScript_229698
	compare_var_to_value VAR_0x4000, 8
	call_if 3, EverGrandeCity_PokemonLeague_1F_EventScript_2296A3
	message EverGrandeCity_PokemonLeague_1F_Text_2296E8
	waitmessage
	delay 120
	checkflag FLAG_BADGE06_GET
	goto_if 0, EverGrandeCity_PokemonLeague_1F_EventScript_2296AE
	closemessage
	applymovement 3, EverGrandeCity_PokemonLeague_1F_Movement_2296E2
	applymovement 4, EverGrandeCity_PokemonLeague_1F_Movement_2296E5
	waitmovement 0
	delay 10
	playfanfare BGM_ME_BACHI
	message EverGrandeCity_PokemonLeague_1F_Text_2297EF
	waitmessage
	waitfanfare
	closemessage
	moveobjectoffscreen 3
	moveobjectoffscreen 4
	setflag FLAG_0x107
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_229698:: @ 8229698
	applymovement 255, EverGrandeCity_PokemonLeague_1F_Movement_2296DA
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_2296A3:: @ 82296A3
	applymovement 255, EverGrandeCity_PokemonLeague_1F_Movement_2296DE
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_2296AE:: @ 82296AE
	playse SE_HAZURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_229787, 4
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_2296BB:: @ 82296BB
	applymovement VAR_LAST_TALKED, EverGrandeCity_PokemonLeague_1F_Movement_27259E
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_2297EF, 4
	closemessage
	applymovement VAR_LAST_TALKED, EverGrandeCity_PokemonLeague_1F_Movement_2725A2
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_2296DA: @ 82296DA
	step_down
	step_left
	step_26
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296DE: @ 82296DE
	step_down
	step_right
	step_26
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296E2: @ 82296E2
	step_left
	step_25
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296E5: @ 82296E5
	step_right
	step_25
	step_end

EverGrandeCity_PokemonLeague_1F_Text_2296E8: @ 82296E8
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_229787: @ 8229787
	.string "You haven’t obtained all the BADGES.\p"
	.string "If you’re bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_2297EF: @ 82297EF
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

