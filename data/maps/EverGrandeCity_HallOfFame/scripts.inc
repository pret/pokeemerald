EverGrandeCity_HallOfFame_MapScripts:: @ 822982C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_MapScript2_229846
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_MapScript2_229837
	.byte 0

EverGrandeCity_HallOfFame_MapScript2_229837: @ 8229837
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_229841
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_229841:: @ 8229841
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_HallOfFame_MapScript2_229846: @ 8229846
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_229850
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_229850:: @ 8229850
	lockall
	applymovement 1, EverGrandeCity_HallOfFame_Movement_229901
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_229901
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_22990E, MSGBOX_DEFAULT
	closemessage
	applymovement 1, EverGrandeCity_HallOfFame_Movement_229908
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_229908
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_2299A3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_2717C1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_2298E9
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_2298F5
	end

EverGrandeCity_HallOfFame_EventScript_2298E9:: @ 82298E9
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	fadescreenspeed 1, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_2298F5:: @ 82298F5
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	fadescreenspeed 1, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_Movement_229901: @ 8229901
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_229908: @ 8229908
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Text_22990E: @ 822990E
	.string "WALLACE: This room…\p"
	.string "This is where we keep records of\n"
	.string "POKéMON that prevailed through\l"
	.string "harsh battles.\p"
	.string "It is here that the LEAGUE CHAMPIONS\n"
	.string "are honored.$"

EverGrandeCity_HallOfFame_Text_2299A3: @ 82299A3
	.string "WALLACE: Come on, let's record your\n"
	.string "name as a TRAINER who triumphed over\l"
	.string "the POKéMON LEAGUE, and the names of\l"
	.string "the partners who battled with you.$"

