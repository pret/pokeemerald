EverGrandeCity_ChampionsRoom_MapScripts:: @ 82289EF
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_MapScript2_228A05
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_MapScript2_228A14
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition: @ 82289FF
	call Common_EventScript_SetupRivalGender
	end

EverGrandeCity_ChampionsRoom_MapScript2_228A05: @ 8228A05
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_228A0F
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_228A0F:: @ 8228A0F
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

EverGrandeCity_ChampionsRoom_MapScript2_228A14: @ 8228A14
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_228A1E
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_228A1E:: @ 8228A1E
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_2725C1
	waitmovement 0
	delay 40
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_228A42
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_228A45
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_228A42: @ 8228A42
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_228A45:: @ 8228A45
	playbgm MUS_DAIGO, 0
	msgbox EverGrandeCity_ChampionsRoom_Text_228C4C, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_228EAC
	goto EverGrandeCity_ChampionsRoom_EventScript_228A61
	end

EverGrandeCity_ChampionsRoom_EventScript_228A61:: @ 8228A61
	playse SE_DOOR
	setmetatile 6, 1, 838, 0
	setmetatile 6, 2, 839, 0
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_228F66, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_228ABC
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_228AC1
	addobject 2
	call EverGrandeCity_ChampionsRoom_EventScript_228BFD
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_228AC6
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_228AFB
	end

EverGrandeCity_ChampionsRoom_EventScript_228ABC:: @ 8228ABC
	playbgm MUS_GIRL_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_228AC1:: @ 8228AC1
	playbgm MUS_BOY_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_228AC6:: @ 8228AC6
	msgbox EverGrandeCity_ChampionsRoom_Text_2290CA, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_228C12
	msgbox EverGrandeCity_ChampionsRoom_Text_22910B, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_228B30
	end

EverGrandeCity_ChampionsRoom_EventScript_228AFB:: @ 8228AFB
	msgbox EverGrandeCity_ChampionsRoom_Text_229152, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_228C12
	msgbox EverGrandeCity_ChampionsRoom_Text_2291A2, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_228B30
	end

EverGrandeCity_ChampionsRoom_EventScript_228B30:: @ 8228B30
	closemessage
	addobject 3
	applymovement 3, EverGrandeCity_ChampionsRoom_Movement_228C43
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_2291E6, MSGBOX_DEFAULT
	call EverGrandeCity_ChampionsRoom_EventScript_272184
	msgbox EverGrandeCity_ChampionsRoom_Text_22934D, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_229399, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_228C3B
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_228C1D
	applymovement 3, Common_Movement_WalkInPlaceUp
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_228C38
	waitmovement 0
	delay 20
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_2293EB, MSGBOX_DEFAULT
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_228BEB
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_228BF4
	closemessage
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_228C3F
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_228C20
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_228BEB:: @ 8228BEB
	msgbox EverGrandeCity_ChampionsRoom_Text_229479, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_228BF4:: @ 8228BF4
	msgbox EverGrandeCity_ChampionsRoom_Text_2294F5, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_228BFD:: @ 8228BFD
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_228C26
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_228C12:: @ 8228C12
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_228C2F
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_228C1D: @ 8228C1D
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C20: @ 8228C20
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C26: @ 8228C26
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_fastest_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C2F: @ 8228C2F
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C38: @ 8228C38
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C3B: @ 8228C3B
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C3F: @ 8228C3F
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_228C43: @ 8228C43
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

EverGrandeCity_ChampionsRoom_Text_228C4C: @ 8228C4C
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
	.string "That incident in SOOTOPOLIS CITY…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "Oops!\p"
	.string "It wouldn't be fair to say that you\n"
	.string "alone ended the crisis.\p"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your POKéMON.\p"
	.string "We TRAINERS raise POKéMON by giving\n"
	.string "them items and by teaching them new\l"
	.string "techniques for battle.\p"
	.string "But we ourselves also learn many\n"
	.string "things from POKéMON.\p"
	.string "And this is where your achievements\n"
	.string "are put to the test against what\l"
	.string "others like you have achieved.\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their POKéMON in HOENN?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_228EAC: @ 8228EAC
	.string "I, the CHAMPION, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble POKéMON\n"
	.string "TRAINER!$"

EverGrandeCity_ChampionsRoom_Text_228F66: @ 8228F66
	.string "WALLACE: The POKéMON you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your POKéMON.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the POKéMON LEAGUE.\p"
	.string "I now proclaim you to be the new\n"
	.string "HOENN region…$"

EverGrandeCity_ChampionsRoom_Text_2290CA: @ 82290CA
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the CHAMPION…$"

EverGrandeCity_ChampionsRoom_Text_22910B: @ 822910B
	.string "MAY: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_229152: @ 8229152
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the CHAMPION?…$"

EverGrandeCity_ChampionsRoom_Text_2291A2: @ 82291A2
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the CHAMPION?$"

EverGrandeCity_ChampionsRoom_Text_2291E6: @ 82291E6
	.string "PROF. BIRCH: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the PETALBURG GYM,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the CHAMPION!\p"
	.string "Ah, yes!\p"
	.string "What became of your POKéDEX?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_22934D: @ 822934D
	.string "PROF. BIRCH: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_229399: @ 8229399
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new CHAMPION!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_2293EB: @ 82293EB
	.string "WALLACE: I'm sorry, but…\p"
	.string "From here on, only those TRAINERS who\n"
	.string "have become CHAMPIONS may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_229479: @ 8229479
	.string "MAY: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_2294F5: @ 82294F5
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"

