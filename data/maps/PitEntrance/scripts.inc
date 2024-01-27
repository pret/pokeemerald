PitEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_Entrance
	.byte 0

PitArena_Entrance:
	setvar VAR_PIT_FLOOR, 0
	setflag FLAG_PIT_STARTED
	setflag	FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	callnative StartTimer1Script
	setflashlevel 0
	return

PitEntrance_Warp::
	lockall
	setflag FLAG_PIT_ENTERED
	addvar VAR_PIT_FLOOR, 1
	callnative BufferMapFloorString
	callnative InitTrainerIdAndNameData
	callnative SetRandomTrainers
	setvar VAR_REWARD_STATE, 0
	givemon SPECIES_MUDKIP, 5
	givemon SPECIES_TREECKO, 5
	givemon SPECIES_TORCHIC, 5
	additem ITEM_RARE_CANDY, 99
	setflag FLAG_SYS_POKEMON_GET
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	releaseall
	end

PitEntrance_EventScript_Sign::
	msgbox PitEntrance_Text_Rules, MSGBOX_SIGN
	release
	end

PitEntrance_Text_Rules:
	.string "Welcome to the Pit of 100 Trials\p"
	.string "Beyond this point is a neverending\n"
	.string "series of rooms filled with\l"
	.string "opponents to fight.\n"
	.string "Can you survive 100 floors?$"
