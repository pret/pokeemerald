EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_MapScript2_2286BB
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_MapScript1_2286D2
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_DrakesRoom_MapScript2_227F3E
	.byte 0

EverGrandeCity_DrakesRoom_MapScript2_2286AC: @ 82286AC
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_2286B6
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_2286B6:: @ 82286B6
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_MapScript2_2286BB: @ 82286BB
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_2286C5
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_2286C5:: @ 82286C5
	lockall
	call EverGrandeCity_DrakesRoom_EventScript_272475
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_MapScript1_2286D2: @ 82286D2
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_2286E7
	compare VAR_ELITE_4_STATE, 4
	call_if_eq EverGrandeCity_DrakesRoom_EventScript_2286ED
	end

EverGrandeCity_DrakesRoom_EventScript_2286E7:: @ 82286E7
	call EverGrandeCity_DrakesRoom_EventScript_2724BC
	return

EverGrandeCity_DrakesRoom_EventScript_2286ED:: @ 82286ED
	call EverGrandeCity_DrakesRoom_EventScript_27255F
	return

EverGrandeCity_DrakesRoom_EventScript_2286F3:: @ 82286F3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_22871A
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_DrakesRoom_Text_22873E, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_228895
	goto EverGrandeCity_DrakesRoom_EventScript_228724
	end

EverGrandeCity_DrakesRoom_EventScript_22871A:: @ 822871A
	msgbox EverGrandeCity_DrakesRoom_Text_2288B0, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_228724:: @ 8228724
	setvar VAR_0x8004, 0
	special sub_813BF7C
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call EverGrandeCity_DrakesRoom_EventScript_2723F8
	msgbox EverGrandeCity_DrakesRoom_Text_2288B0, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_22873E: @ 822873E
	.string "I am the last of the POKéMON LEAGUE\n"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
	.string "In their natural state, POKéMON are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "For us to battle with POKéMON as\n"
	.string "partners, do you know what it takes?\p"
	.string "Do you know what is needed?\p"
	.string "If you don't, then you will never\n"
	.string "prevail over me!$"

EverGrandeCity_DrakesRoom_Text_228895: @ 8228895
	.string "Superb, it should be said.$"

EverGrandeCity_DrakesRoom_Text_2288B0: @ 82288B0
	.string "You deserve every credit for coming\n"
	.string "this far as a TRAINER of POKéMON.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a TRAINER needs is a\n"
	.string "virtuous heart.\p"
	.string "POKéMON touch the good hearts of\n"
	.string "TRAINERS and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "TRAINERS and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The CHAMPION is waiting!$"

