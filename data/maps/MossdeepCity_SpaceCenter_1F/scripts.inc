.set LOCALID_SCIENTIST_1, 1
.set LOCALID_SCIENTIST_2, 2
.set LOCALID_SAILOR, 3
.set LOCALID_OLD_MAN, 4
.set LOCALID_WOMAN, 5
.set LOCALID_STAIR_GRUNT, 9

MossdeepCity_SpaceCenter_1F_MapScripts:: @ 8222F41
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition: @ 8222F4C
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma:: @ 8222F58
	setobjectxyperm LOCALID_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_WOMAN, 0, 8
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft:: @ 8222FAA
	setobjectxyperm LOCALID_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown:: @ 8222FB2
	setobjectxyperm LOCALID_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight:: @ 8222FBA
	setobjectxyperm LOCALID_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad: @ 8222FC2
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_le MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote:: @ 8222FCE
	setmetatile 2, 5, METATILE_Facility_DataPad, 1
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter:: @ 8222FD8
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet:: @ 8223012
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber:: @ 822301B
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma:: @ 8223024
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma:: @ 8223051
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma:: @ 822305A
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist:: @ 8223063
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma:: @ 822307A
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan:: @ 822308E
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone:: @ 82230D0
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma:: @ 82230DA
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma:: @ 8223119
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman:: @ 822312D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal:: @ 8223154
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma:: @ 822315E
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan:: @ 8223168
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal:: @ 822318F
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma:: @ 82231A4
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven:: @ 82231B9
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote:: @ 82231CF
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3:: @ 82231DA
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1:: @ 82231F1
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4:: @ 8223208
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2:: @ 822321F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
	#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
	#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
	#endif
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated:: @ 822326E
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest:: @ 8223278
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast:: @ 8223289
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest: @ 822329A
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast: @ 822329E
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs: @ 82232A2
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent: @ 82232A7
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber: @ 82232C8
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent: @ 8223305
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber: @ 822335E
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection: @ 82233D3
	.string "A rocket launch demands perfection.\n"
	.string "Not even a 1% margin of error is allowed.\p"
	.string "Even if it's 99% okay, the whole thing\n"
	.string "is useless if 1% happens to be no good.\p"
	.string "Despite that, we never stop trying.\n"
	.string "Why? It's a dream that never ends.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter: @ 82234B7
	.string "Those MAGMA thugs have their sights\n"
	.string "set on our SPACE CENTER.\p"
	.string "But we can't allow anything that minor\n"
	.string "to interfere with our rocket launch!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt: @ 8223540
	.string "I was taking a stroll down the beach\n"
	.string "when I found this.\p"
	.string "It's not anything I need, so you can\n"
	.string "have it.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers: @ 82235A6
	.string "The HOENN region has been famous for \n"
	.string "its meteor showers for a long time.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis: @ 82235F0
	.string "TEAM MAGMA can't be allowed to steal\n"
	.string "the rocket fuel.\p"
	.string "Oh, by the way, you can have this stone\n"
	.string "I found on the beach.$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma: @ 8223664
	.string "With TEAM MAGMA around, I guess\n"
	.string "strolls on the beach aren't safe.$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace: @ 82236A6
	.string "Some people claim that POKéMON came\n"
	.string "from space. Could it be true?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma: @ 82236E8
	.string "TEAM AQUA should take care of\n"
	.string "TEAM MAGMA!\p"
	.string "But if they did that, TEAM AQUA will\n"
	.string "become bold and brazen, won't they?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind: @ 822375B
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream: @ 82237B5
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But TEAM MAGMA wants to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel: @ 8223849
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

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro: @ 822396C
	.string "As promised, we've come for\n"
	.string "the rocket fuel!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat: @ 8223999
	.string "Ran out of fuel…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle: @ 82239AA
	.string "Don't think you're on a roll just\n"
	.string "because you've beaten me!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro: @ 82239E6
	.string "We gave you fair warning!\n"
	.string "There's nothing sneaky about us!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat: @ 8223A21
	.string "Grrr…\n"
	.string "We should've used sneaky treachery…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle: @ 8223A4B
	.string "Okay, I get it already! The next time,\n"
	.string "we'll come unannounced.$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro: @ 8223A8A
	.string "The rocket fuel the SPACE CENTER has\n"
	.string "in storage--that's what we're after.\p"
	.string "We mean to take every last bit of it!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat: @ 8223AFA
	.string "Please, can you spare some fuel?\n"
	.string "Even a chintzy cup will do!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle: @ 8223B37
	.string "What are we going to do with\n"
	.string "the rocket fuel?\p"
	.string "How would I know?\n"
	.string "Ask our leader upstairs!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro: @ 8223B90
	.string "Our leader said no one, but no one,\n"
	.string "gets past me!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat: @ 8223BC2
	.string "Ack! Ack! Aaack!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle: @ 8223BD3
	.string "Please, tell our leader that\n"
	.string "I never abandoned my post.\l"
	.string "That I stayed to the bitter end…$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice: @ 8223C2C
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
