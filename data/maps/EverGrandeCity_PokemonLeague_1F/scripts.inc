EverGrandeCity_PokemonLeague_1F_MapScripts:: @ 82295D2
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_PokemonLeague_1F_MapScript1_277C30
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition: @ 82295DD
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_2
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_2295ED
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
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
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
	special SavePlayerParty
	
	fadescreen 1
    special ChooseHalfPartyForBattle
    waitstate
	@ Check here to see if the player didn't choose Cancel.
	
	special ReducePlayerPartyToSelectedMons
    setvar VAR_0x8004, 2
    setvar VAR_0x8005, 4
    special CallFrontierUtilFunc
	
	trainerbattle 10, 1, 0, NULL, EverGrandeCity_PokemonLeague_1F_Text_2296E8
	trainerbattle 11, TRAINER_ALEXA, 0, NULL, EverGrandeCity_PokemonLeague_1F_Text_2297EF
	
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 2 | 0x80
	setvar VAR_0x8006, TRAINER_EDWARDO
	setvar VAR_0x8007, TRAINER_BACK_PIC_LEAF
	special DoSpecialTrainerBattle
	waitstate
	
	setvar VAR_0x8004, 6
    special CallFrontierUtilFunc
	
	special LoadPlayerParty
	
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_2296BB
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 11
	call_if_ge EverGrandeCity_PokemonLeague_1F_EventScript_229698
	compare VAR_TEMP_0, 8
	call_if_le EverGrandeCity_PokemonLeague_1F_EventScript_2296A3
	message EverGrandeCity_PokemonLeague_1F_Text_2296E8
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_2296AE
	closemessage
	applymovement 3, EverGrandeCity_PokemonLeague_1F_Movement_2296E2
	applymovement 4, EverGrandeCity_PokemonLeague_1F_Movement_2296E5
	waitmovement 0
	delay 10
	playfanfare MUS_ME_BACHI
	message EverGrandeCity_PokemonLeague_1F_Text_2297EF
	waitmessage
	waitfanfare
	closemessage
	moveobjectoffscreen 3
	moveobjectoffscreen 4
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_229698:: @ 8229698
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_2296DA
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_2296A3:: @ 82296A3
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_2296DE
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_2296AE:: @ 82296AE
	playse SE_HAZURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_229787, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_2296BB:: @ 82296BB
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_2297EF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_2296DA: @ 82296DA
	walk_down
	walk_left
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296DE: @ 82296DE
	walk_down
	walk_right
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296E2: @ 82296E2
	walk_left
	walk_in_place_fastest_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_2296E5: @ 82296E5
	walk_right
	walk_in_place_fastest_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_2296E8: @ 82296E8
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_229787: @ 8229787
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_2297EF: @ 82297EF
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

