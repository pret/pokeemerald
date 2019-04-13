TrainerHill_Entrance_MapScripts:: @ 82680AC
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_MapScript1_2680D0
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_MapScript1_26811B
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_MapScript1_268128
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_MapScript2_26813E
	.byte 0

TrainerHill_Entrance_OnTransition: @ 82680C6
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerHill_Entrance_MapScript1_2680CF: @ 82680CF
	end

TrainerHill_Entrance_MapScript1_2680D0: @ 82680D0
	setvar VAR_0x8004, TRAINER_HILL_FUNC_RESUME_TIMER
	special CallTrainerHillFunction
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, TRAINER_HILL_FUNC_9
	special CallTrainerHillFunction
	compare VAR_RESULT, 0
	goto_if_eq TrainerHill_Entrance_EventScript_2680FF
	setobjectxy EVENT_OBJ_ID_PLAYER, 9, 6
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_26837F
	end

TrainerHill_Entrance_EventScript_2680FF:: @ 82680FF
	setvar VAR_0x8004, TRAINER_HILL_FUNC_16
	special CallTrainerHillFunction
	compare VAR_RESULT, 1
	goto_if_eq TrainerHill_Entrance_EventScript_26811A
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_26837F
	end

TrainerHill_Entrance_EventScript_26811A:: @ 826811A
	end

TrainerHill_Entrance_MapScript1_26811B: @ 826811B
	addobject 2
	addobject 1
	addobject 5
	addobject 4
	end

TrainerHill_Entrance_MapScript1_268128: @ 8268128
	compare VAR_TEMP_D, 17
	call_if_eq TrainerHill_Entrance_EventScript_268134
	end

TrainerHill_Entrance_EventScript_268134:: @ 8268134
	setmetatile 17, 10, 775, 0
	return

TrainerHill_Entrance_MapScript2_26813E: @ 826813E
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_268182
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_268160
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_268229
	map_script_2 VAR_TEMP_1, 1, TrainerHill_Entrance_EventScript_2C83DF
	.2byte 0

TrainerHill_Entrance_EventScript_268160:: @ 8268160
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_268385
	waitmovement 0
	setmetatile 17, 10, 820, 1
	special DrawWholeMapView
	playse SE_TK_KASYA
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_268182:: @ 8268182
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_STATUS
	special CallTrainerHillFunction
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_2681B5
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_2681CA
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_2681EE

TrainerHill_Entrance_EventScript_2681B5:: @ 82681B5
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_26837F
	msgbox TrainerHill_Entrance_Text_268689, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_2681DA

TrainerHill_Entrance_EventScript_2681CA:: @ 82681CA
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_26837F
	msgbox TrainerHill_Entrance_Text_268712, MSGBOX_DEFAULT

TrainerHill_Entrance_EventScript_2681DA:: @ 82681DA
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_268381
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall

TrainerHill_Entrance_EventScript_2681EE:: @ 82681EE
	end

TrainerHill_Entrance_EventScript_2681EF:: @ 82681EF
	setvar VAR_0x800B, 2
	call TrainerHill_Entrance_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_2681FD:: @ 82681FD
	lock
	faceplayer
	setvar VAR_0x8004, TRAINER_HILL_FUNC_10
	special CallTrainerHillFunction
	compare VAR_RESULT, 0
	goto_if_eq TrainerHill_Entrance_EventScript_26821F
	msgbox TrainerHill_Entrance_Text_2686F4, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_268227

TrainerHill_Entrance_EventScript_26821F:: @ 826821F
	msgbox TrainerHill_Entrance_Text_2687AC, MSGBOX_DEFAULT

TrainerHill_Entrance_EventScript_268227:: @ 8268227
	release
	end

TrainerHill_Entrance_EventScript_268229:: @ 8268229
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_26837F
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_26836A
	msgbox TrainerHill_Entrance_Text_2684C6, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRAINER_HILL_FUNC_13
	special CallTrainerHillFunction
	compare VAR_RESULT, 0
	call_if_eq TrainerHill_Entrance_EventScript_26832E
	setvar VAR_0x8004, TRAINER_HILL_FUNC_8
	special CallTrainerHillFunction
	compare VAR_RESULT, 1
	goto_if_eq TrainerHill_Entrance_EventScript_268275
	msgbox TrainerHill_Entrance_Text_268564, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_26827D

TrainerHill_Entrance_EventScript_268275:: @ 8268275
	msgbox TrainerHill_Entrance_Text_26859E, MSGBOX_DEFAULT

TrainerHill_Entrance_EventScript_26827D:: @ 826827D
	message TrainerHill_Entrance_Text_2685F8
	waitmessage
	multichoice 15, 6, 17, 0
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_2682C8
	case 1, TrainerHill_Entrance_EventScript_268314
	case 2, TrainerHill_Entrance_EventScript_2682BA
	case 127, TrainerHill_Entrance_EventScript_268314
	end

TrainerHill_Entrance_EventScript_2682BA:: @ 82682BA
	msgbox TrainerHill_Entrance_Text_2687C3, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_26827D
	end

TrainerHill_Entrance_EventScript_2682C8:: @ 82682C8
	multichoice 13, 2, 113, 0
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_268314
	case 127, TrainerHill_Entrance_EventScript_268314
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_TAG
	copyvar VAR_0x8005, VAR_RESULT
	special CallTrainerHillFunction
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_26862A, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRAINER_HILL_FUNC_START
	special CallTrainerHillFunction
	releaseall
	end

TrainerHill_Entrance_EventScript_268314:: @ 8268314
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_26866F, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_268381
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_26832E:: @ 826832E
	msgbox TrainerHill_Entrance_Text_26851C, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRAINER_HILL_FUNC_14
	special CallTrainerHillFunction
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq TrainerHill_Entrance_EventScript_26835C
	setvar VAR_0x8004, TRAINER_HILL_FUNC_14
	special CallTrainerHillFunction
	return

TrainerHill_Entrance_EventScript_26835C:: @ 826835C
	setvar VAR_0x8004, TRAINER_HILL_FUNC_15
	special CallTrainerHillFunction
	goto TrainerHill_Entrance_EventScript_268314
	end

TrainerHill_Entrance_EventScript_26836A:: @ 826836A
	msgbox TrainerHill_Entrance_Text_268430, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Entrance_Movement_268381
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_26837F: @ 826837F
	face_right
	step_end

TrainerHill_Entrance_Movement_268381: @ 8268381
	walk_down
	step_end

TrainerHill_Entrance_Movement_268383: @ 8268383
	face_up
	step_end

TrainerHill_Entrance_Movement_268385: @ 8268385
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_268388:: @ 8268388
	lockall
	fadescreen 1
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_268391:: @ 8268391
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_2683A3
	msgbox TrainerHill_Entrance_Text_268D5A, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_2683A3:: @ 82683A3
	msgbox TrainerHill_Entrance_Text_268DDA, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_2683AC:: @ 82683AC
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_2683BE
	msgbox TrainerHill_Entrance_Text_268E6A, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_2683BE:: @ 82683BE
	msgbox TrainerHill_Entrance_Text_268EDC, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_2683C7:: @ 82683C7
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_268402
	pokemart TrainerHill_Entrance_Pokemart_2683E8
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_2683E8: @ 82683E8
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_EventScript_268402:: @ 8268402
	pokemart TrainerHill_Entrance_Pokemart_268414
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_268414: @ 8268414
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_Text_268430: @ 8268430
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS.\p"
	.string "Unfortunately, we're still getting\n"
	.string "things ready. Please come back later!$"

TrainerHill_Entrance_Text_2684C6: @ 82684C6
	.string "Welcome!\p"
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS!$"

TrainerHill_Entrance_Text_26851C: @ 826851C
	.string "Is this your first visit here?\p"
	.string "Before you enter, please save\n"
	.string "your game.$"

TrainerHill_Entrance_Text_268564: @ 8268564
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "Up to floor no. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_26859E: @ 826859E
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "There appear to be TRAINERS gathered\n"
	.string "in every room.$"

TrainerHill_Entrance_Text_2685F8: @ 82685F8
	.string "Would you like to challenge the\n"
	.string "waiting TRAINERS?$"

TrainerHill_Entrance_Text_26862A: @ 826862A
	.string "I will time your progress.\n"
	.string "Best of luck!\p"
	.string "On your marks…\p"
	.string "Get set…\p"
	.string "Go!$"

TrainerHill_Entrance_Text_26866F: @ 826866F
	.string "Please do visit us again!$"

TrainerHill_Entrance_Text_268689: @ 8268689
	.string "That was too bad.\p"
	.string "I think you put in a tremendous\n"
	.string "effort in your battling.\p"
	.string "Please come back and try again!$"

TrainerHill_Entrance_Text_2686F4: @ 82686F4
	.string "I hope you give it your best.$"

TrainerHill_Entrance_Text_268712: @ 8268712
	.string "When the TRAINERS switch places,\n"
	.string "the movement can be hectic.\p"
	.string "To avoid the stampede, we moved\n"
	.string "the reception counter here.\p"
	.string "I'm sorry for the inconvenience.$"

TrainerHill_Entrance_Text_2687AC: @ 82687AC
	.string "Thank you for playing!$"

TrainerHill_Entrance_Text_2687C3: @ 82687C3
	.string "Here at the TRAINER HILL, we conduct\n"
	.string "an event called the Time Attack.\p"
	.string "It is a race that measures how long\n"
	.string "you take to reach our owner on\l"
	.string "the rooftop from this counter.\p"
	.string "The fastest times are posted on\n"
	.string "the Time Board--try competing with\l"
	.string "your friends.\p"
	.string "In TRAINER battles along the way,\n"
	.string "neither Exp. Points nor money will\l"
	.string "be awarded.$"

TrainerHill_Entrance_Text_26890D: @ 826890D
	.string "Oh, I'm sorry, but you appear to have\n"
	.string "only one POKéMON with you.\p"
	.string "You will need at least two POKéMON\n"
	.string "to enter this event.$"

TrainerHill_Roof_Text_268986: @ 8268986
	.string "Hm! Hm!\p"
	.string "You finally came!\n"
	.string "Yes, you have arrived!\p"
	.string "Wait! Don't say it!\n"
	.string "I know why you came all the way\l"
	.string "here by yourself!\p"
	.string "You wanted to see me, the owner\n"
	.string "of the TRAINER HILL, because…\p"
	.string "You want to form a tag team with me!\n"
	.string "Wa-hoo!\p"
	.string "…Uh?\n"
	.string "That's not it?\p"
	.string "Anyway, I watched you on your way up.\n"
	.string "Marvelous battling! Bravo, indeed!$"

TrainerHill_Roof_Text_268AC5: @ 8268AC5
	.string "For a marvelous someone like you,\n"
	.string "I have the most marvelous gift!$"

TrainerHill_Roof_Text_268B07: @ 8268B07
	.string "Oh, no, full up with things!\n"
	.string "You'll be back later for this!$"

TrainerHill_Roof_Text_268B43: @ 8268B43
	.string "Oh, hold on here! Did you possibly get\n"
	.string "here marvelously quickly?\p"
	.string "How splendid! You needn't have\n"
	.string "hurried so to see me!\p"
	.string "That is so delightful. I'll have the Time\n"
	.string "Board at the reception updated!$"

TrainerHill_Roof_Text_268C03: @ 8268C03
	.string "But, oh…\n"
	.string "You weren't very quick getting here.$"

TrainerHill_Roof_Text_268C31: @ 8268C31
	.string "Perhaps it would please me more if you\n"
	.string "arrived zippier next time.\p"
	.string "Then, I should be pleased to form\n"
	.string "a tag team with you!\p"
	.string "Until we meet again, amigo!$"

TrainerHill_Roof_Text_268CC6: @ 8268CC6
	.string "I had the TRAINER HILL built for but\n"
	.string "one reason and one only!\p"
	.string "To find the most suitable partner\n"
	.string "with whom I may form a tag team!$"

TrainerHill_Entrance_Text_268D47: @ 8268D47
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_268D5A: @ 8268D5A
	.string "Who knows what sort of TRAINERS\n"
	.string "and POKéMON combos are ahead?\p"
	.string "All I know is that I'll knock aside\n"
	.string "anyone that stands in my way!$"

TrainerHill_Entrance_Text_268DDA: @ 8268DDA
	.string "I heard tough TRAINERS come to this\n"
	.string "TRAINER HILL from all over.\p"
	.string "I can't wait to test the waters!\p"
	.string "I'll knock aside anyone that stands\n"
	.string "in my way!$"

TrainerHill_Entrance_Text_268E6A: @ 8268E6A
	.string "Do you see the Time Board over there?\p"
	.string "My friends and I are trying to see who\n"
	.string "can reach the top in the least time.$"

TrainerHill_Entrance_Text_268EDC: @ 8268EDC
	.string "Do you know when they're opening\n"
	.string "this place up?\p"
	.string "I'm waiting here to be the first\n"
	.string "challenger ever!$"

TrainerHill_Elevator_Text_268F3E: @ 8268F3E
	.string "Would you like to return to\n"
	.string "the reception counter?$"
