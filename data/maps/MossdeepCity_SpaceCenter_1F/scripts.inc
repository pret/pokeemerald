MossdeepCity_SpaceCenter_1F_MapScripts:: @ 8222F41
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_MapScript1_222FC2
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition: @ 8222F4C
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222F58
	end

MossdeepCity_SpaceCenter_1F_EventScript_222F58:: @ 8222F58
	setobjectxyperm 3, 1, 9
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 5, 0, 8
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 4, 1, 6
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 1, 3, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 1
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FAA
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FB2
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 3
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FBA
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FAA:: @ 8222FAA
	setobjectxyperm 9, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FB2:: @ 8222FB2
	setobjectxyperm 9, 13, 3
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FBA:: @ 8222FBA
	setobjectxyperm 9, 14, 2
	end

MossdeepCity_SpaceCenter_1F_MapScript1_222FC2: @ 8222FC2
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_le MossdeepCity_SpaceCenter_1F_EventScript_222FCE
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FCE:: @ 8222FCE
	setmetatile 2, 5, METATILE_Facility_DataPad, 1
	return

MossdeepCity_SpaceCenter_1F_EventScript_222FD8:: @ 8222FD8
	lock
	faceplayer
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223024
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223012
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_22301B
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223012:: @ 8223012
	msgbox MossdeepCity_SpaceCenter_1F_Text_2232A7, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_22301B:: @ 822301B
	msgbox MossdeepCity_SpaceCenter_1F_Text_2232C8, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_223024:: @ 8223024
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223051
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_22305A
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223051:: @ 8223051
	msgbox MossdeepCity_SpaceCenter_1F_Text_223305, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_22305A:: @ 822305A
	msgbox MossdeepCity_SpaceCenter_1F_Text_22335E, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_223063:: @ 8223063
	lock
	faceplayer
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_22307A
	msgbox MossdeepCity_SpaceCenter_1F_Text_2233D3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22307A:: @ 822307A
	msgbox MossdeepCity_SpaceCenter_1F_Text_2234B7, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22308E:: @ 822308E
	lock
	faceplayer
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_2230DA
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_2230D0
	msgbox MossdeepCity_SpaceCenter_1F_Text_223540, MSGBOX_DEFAULT
	giveitem_std ITEM_SUN_STONE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2230D0:: @ 82230D0
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2230DA:: @ 82230DA
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_223119
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235F0, MSGBOX_DEFAULT
	giveitem_std ITEM_SUN_STONE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_223664, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223119:: @ 8223119
	msgbox MossdeepCity_SpaceCenter_1F_Text_223664, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22312D:: @ 822312D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_223154
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_22315E
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_223154
	goto MossdeepCity_SpaceCenter_1F_EventScript_22315E
	end

MossdeepCity_SpaceCenter_1F_EventScript_223154:: @ 8223154
	msgbox MossdeepCity_SpaceCenter_1F_Text_2236A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22315E:: @ 822315E
	msgbox MossdeepCity_SpaceCenter_1F_Text_2236E8, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223168:: @ 8223168
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_22318F
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_2231A4
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_22318F
	goto MossdeepCity_SpaceCenter_1F_EventScript_2231A4
	end

MossdeepCity_SpaceCenter_1F_EventScript_22318F:: @ 822318F
	msgbox MossdeepCity_SpaceCenter_1F_Text_22375B, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231A4:: @ 82231A4
	msgbox MossdeepCity_SpaceCenter_1F_Text_2237B5, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231B9:: @ 82231B9
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_223849, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231CF:: @ 82231CF
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_223C2C, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231DA:: @ 82231DA
	trainerbattle_single TRAINER_GRUNT_32, MossdeepCity_SpaceCenter_1F_Text_22396C, MossdeepCity_SpaceCenter_1F_Text_223999
	msgbox MossdeepCity_SpaceCenter_1F_Text_2239AA, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231F1:: @ 82231F1
	trainerbattle_single TRAINER_GRUNT_16, MossdeepCity_SpaceCenter_1F_Text_2239E6, MossdeepCity_SpaceCenter_1F_Text_223A21
	msgbox MossdeepCity_SpaceCenter_1F_Text_223A4B, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_223208:: @ 8223208
	trainerbattle_single TRAINER_GRUNT_33, MossdeepCity_SpaceCenter_1F_Text_223A8A, MossdeepCity_SpaceCenter_1F_Text_223AFA
	msgbox MossdeepCity_SpaceCenter_1F_Text_223B37, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_22321F:: @ 822321F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_22326E
	msgbox MossdeepCity_SpaceCenter_1F_Text_223B90, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_23, MossdeepCity_SpaceCenter_1F_Text_223BC2
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	moveobjectoffscreen 9
	switch VAR_FACING
	case 3, MossdeepCity_SpaceCenter_1F_EventScript_223278
	case 3, MossdeepCity_SpaceCenter_1F_EventScript_223289
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_2232A2
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22326E:: @ 822326E
	msgbox MossdeepCity_SpaceCenter_1F_Text_223BD3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223278:: @ 8223278
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_22329A
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 1
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223289:: @ 8223289
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_22329E
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_22329A: @ 822329A
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_22329E: @ 822329E
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_2232A2: @ 82232A2
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_2232A7: @ 82232A7
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_2232C8: @ 82232C8
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_223305: @ 8223305
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_22335E: @ 822335E
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_2233D3: @ 82233D3
	.string "A rocket launch demands perfection.\n"
	.string "Not even a 1% margin of error is allowed.\p"
	.string "Even if it's 99% okay, the whole thing\n"
	.string "is useless if 1% happens to be no good.\p"
	.string "Despite that, we never stop trying.\n"
	.string "Why? It's a dream that never ends.$"

MossdeepCity_SpaceCenter_1F_Text_2234B7: @ 82234B7
	.string "Those MAGMA thugs have their sights\n"
	.string "set on our SPACE CENTER.\p"
	.string "But we can't allow anything that minor\n"
	.string "to interfere with our rocket launch!$"

MossdeepCity_SpaceCenter_1F_Text_223540: @ 8223540
	.string "I was taking a stroll down the beach\n"
	.string "when I found this.\p"
	.string "It's not anything I need, so you can\n"
	.string "have it.$"

MossdeepCity_SpaceCenter_1F_Text_2235A6: @ 82235A6
	.string "The HOENN region has been famous for \n"
	.string "its meteor showers for a long time.$"

MossdeepCity_SpaceCenter_1F_Text_2235F0: @ 82235F0
	.string "TEAM MAGMA can't be allowed to steal\n"
	.string "the rocket fuel.\p"
	.string "Oh, by the way, you can have this stone\n"
	.string "I found on the beach.$"

MossdeepCity_SpaceCenter_1F_Text_223664: @ 8223664
	.string "With TEAM MAGMA around, I guess\n"
	.string "strolls on the beach aren't safe.$"

MossdeepCity_SpaceCenter_1F_Text_2236A6: @ 82236A6
	.string "Some people claim that POKéMON came\n"
	.string "from space. Could it be true?$"

MossdeepCity_SpaceCenter_1F_Text_2236E8: @ 82236E8
	.string "TEAM AQUA should take care of\n"
	.string "TEAM MAGMA!\p"
	.string "But if they did that, TEAM AQUA will\n"
	.string "become bold and brazen, won't they?$"

MossdeepCity_SpaceCenter_1F_Text_22375B: @ 822375B
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"

MossdeepCity_SpaceCenter_1F_Text_2237B5: @ 82237B5
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But TEAM MAGMA wants to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"

MossdeepCity_SpaceCenter_1F_Text_223849: @ 8223849
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
	.string "proclamation already?\p"
	.string "TEAM MAGMA is coming after the rocket\n"
	.string "fuel on this island.\p"
	.string "I don't know what they'd need it for,\n"
	.string "but they can't be allowed to take it.\p"
	.string "I'll keep an eye on things for\n"
	.string "a while longer.\p"
	.string "In the meantime, why don't you go\n"
	.string "check out the town?$"

MossdeepCity_SpaceCenter_1F_Text_22396C: @ 822396C
	.string "As promised, we've come for\n"
	.string "the rocket fuel!$"

MossdeepCity_SpaceCenter_1F_Text_223999: @ 8223999
	.string "Ran out of fuel…$"

MossdeepCity_SpaceCenter_1F_Text_2239AA: @ 82239AA
	.string "Don't think you're on a roll just\n"
	.string "because you've beaten me!$"

MossdeepCity_SpaceCenter_1F_Text_2239E6: @ 82239E6
	.string "We gave you fair warning!\n"
	.string "There's nothing sneaky about us!$"

MossdeepCity_SpaceCenter_1F_Text_223A21: @ 8223A21
	.string "Grrr…\n"
	.string "We should've used sneaky treachery…$"

MossdeepCity_SpaceCenter_1F_Text_223A4B: @ 8223A4B
	.string "Okay, I get it already! The next time,\n"
	.string "we'll come unannounced.$"

MossdeepCity_SpaceCenter_1F_Text_223A8A: @ 8223A8A
	.string "The rocket fuel the SPACE CENTER has\n"
	.string "in storage--that's what we're after.\p"
	.string "We mean to take every last bit of it!$"

MossdeepCity_SpaceCenter_1F_Text_223AFA: @ 8223AFA
	.string "Please, can you spare some fuel?\n"
	.string "Even a chintzy cup will do!$"

MossdeepCity_SpaceCenter_1F_Text_223B37: @ 8223B37
	.string "What are we going to do with\n"
	.string "the rocket fuel?\p"
	.string "How would I know?\n"
	.string "Ask our leader upstairs!$"

MossdeepCity_SpaceCenter_1F_Text_223B90: @ 8223B90
	.string "Our leader said no one, but no one,\n"
	.string "gets past me!$"

MossdeepCity_SpaceCenter_1F_Text_223BC2: @ 8223BC2
	.string "Ack! Ack! Aaack!$"

MossdeepCity_SpaceCenter_1F_Text_223BD3: @ 8223BD3
	.string "Please, tell our leader that\n"
	.string "I never abandoned my post.\l"
	.string "That I stayed to the bitter end…$"

MossdeepCity_SpaceCenter_1F_Text_223C2C: @ 8223C2C
	.string "This is…\n"
	.string "An intent-to-steal notice?\p"
	.string "“To the staff of the SPACE CENTER:\n"
	.string "How are you? We are doing fine.\p"
	.string "“We will soon visit you to take your\n"
	.string "rocket fuel.\p"
	.string "“Please don't try to stop us.\n"
	.string "We will take the fuel no matter what.\p"
	.string "“Let there be more land!\n"
	.string "                                          TEAM MAGMA”$"
