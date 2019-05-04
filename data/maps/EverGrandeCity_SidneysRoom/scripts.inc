EverGrandeCity_SidneysRoom_MapScripts:: @ 8227F01
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_MapScript1_227F1D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_MapScript2_227F3E
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_MapScript2_227F4D
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition: @ 8227F16
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_MapScript1_227F1D: @ 8227F1D
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_227F32
	compare VAR_ELITE_4_STATE, 1
	call_if_eq EverGrandeCity_SidneysRoom_EventScript_227F38
	end

EverGrandeCity_SidneysRoom_EventScript_227F32:: @ 8227F32
	call EverGrandeCity_SidneysRoom_EventScript_2724BC
	return

EverGrandeCity_SidneysRoom_EventScript_227F38:: @ 8227F38
	call EverGrandeCity_SidneysRoom_EventScript_27255F
	return

EverGrandeCity_DrakesRoom_MapScript2_227F3E: @ 8227F3E
EverGrandeCity_SidneysRoom_MapScript2_227F3E: @ 8227F3E
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_227F48
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_227F48:: @ 8227F48
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

EverGrandeCity_SidneysRoom_MapScript2_227F4D: @ 8227F4D
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_227F57
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_227F57:: @ 8227F57
	lockall
	call EverGrandeCity_SidneysRoom_EventScript_272475
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_227F64:: @ 8227F64
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_227F8B
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_SidneysRoom_Text_227FA7, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_2280A2
	goto EverGrandeCity_SidneysRoom_EventScript_227F95
	end

EverGrandeCity_SidneysRoom_EventScript_227F8B:: @ 8227F8B
	msgbox EverGrandeCity_SidneysRoom_Text_2280EC, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_227F95:: @ 8227F95
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call EverGrandeCity_SidneysRoom_EventScript_2723F8
	msgbox EverGrandeCity_SidneysRoom_Text_2280EC, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_227FA7: @ 8227FA7
	.string "Welcome, challenger!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!$"

EverGrandeCity_SidneysRoom_Text_2280A2: @ 82280A2
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

EverGrandeCity_SidneysRoom_Text_2280EC: @ 82280EC
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the next room and enjoy\l"
	.string "your next battle!$"

