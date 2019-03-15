EverGrandeCity_PhoebesRoom_MapScripts:: @ 8228174
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_MapScript1_2281AA
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_MapScript2_228184
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_MapScript2_228193
	.byte 0

EverGrandeCity_PhoebesRoom_MapScript2_228184: @ 8228184
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_22818E
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_22818E:: @ 822818E
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

EverGrandeCity_PhoebesRoom_MapScript2_228193: @ 8228193
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_22819D
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_22819D:: @ 822819D
	lockall
	call EverGrandeCity_PhoebesRoom_EventScript_272475
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_MapScript1_2281AA: @ 82281AA
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_2281BF
	compare VAR_ELITE_4_STATE, 2
	call_if_eq EverGrandeCity_PhoebesRoom_EventScript_2281C5
	end

EverGrandeCity_PhoebesRoom_EventScript_2281BF:: @ 82281BF
	call EverGrandeCity_PhoebesRoom_EventScript_2724BC
	return

EverGrandeCity_PhoebesRoom_EventScript_2281C5:: @ 82281C5
	call EverGrandeCity_PhoebesRoom_EventScript_27255F
	return

EverGrandeCity_PhoebesRoom_EventScript_2281CB:: @ 82281CB
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_2281F2
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_PhoebesRoom_Text_22820E, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_228325
	goto EverGrandeCity_PhoebesRoom_EventScript_2281FC
	end

EverGrandeCity_PhoebesRoom_EventScript_2281F2:: @ 82281F2
	msgbox EverGrandeCity_PhoebesRoom_Text_228343, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_2281FC:: @ 82281FC
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call EverGrandeCity_PhoebesRoom_EventScript_2723F8
	msgbox EverGrandeCity_PhoebesRoom_Text_228343, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_22820E: @ 822820E
	.string "Ahahaha!\p"
	.string "I'm PHOEBE of the ELITE FOUR.\n"
	.string "I did my training on MT. PYRE.\p"
	.string "While I trained, I gained the ability\n"
	.string "to commune with GHOST-type POKéMON.\p"
	.string "Yes, the bond I developed with POKéMON\n"
	.string "is extremely tight.\p"
	.string "So, come on, just try and see if you can\n"
	.string "even inflict damage on my POKéMON!$"

EverGrandeCity_PhoebesRoom_Text_228325: @ 8228325
	.string "Oh, darn.\n"
	.string "I've gone and lost.$"

EverGrandeCity_PhoebesRoom_Text_228343: @ 8228343
	.string "There's a definite bond between you\n"
	.string "and your POKéMON, too.\p"
	.string "I didn't recognize it, so it's only\n"
	.string "natural that I lost.\p"
	.string "Yup, I'd like to see how far your bond\n"
	.string "will carry you.\p"
	.string "Go ahead, move on to the next room.$"

