LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applywaitmovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMA: Zie je, {PLAYER}?\n"
	.string "Het is hier binnen ook fijn, toch?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "De POKéMON van de verhuizers doen\n"
	.string "al het werk en ruimen ook alles op.\l"
	.string "Dat is zo handig!\p"
	.string "{PLAYER}, je kamer is boven.\n"
	.string "Ga maar kijken, lieverd!\p"
	.string "PAPA heeft een nieuwe klok voor je\n"
	.string "gekocht omdat we verhuisd zijn.\l"
	.string "Vergeet hem niet goed te zetten!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMA: Nou, {PLAYER}?\p"
	.string "Wil je je eigen kamer\n"
	.string "niet zien?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMA: {PLAYER}.\p"
	.string "Zet de klok in je kamer, lieverd.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMA: O! {PLAYER}, {PLAYER}!\n"
	.string "Snel! Kom snel!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMA: Kijk! De PETALBURG GYM!\n"
	.string "Misschien komt PAPA op tv!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMA: O… Het is al voorbij.\p"
	.string "PAPA was er volgens mij, maar we\n"
	.string "hebben hem gemist. Jammer.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "O ja.\n"
	.string "Een vriend van PAPA woont hier.\p"
	.string "Hij heet PROF. BIRCH.\p"
	.string "Hij woont hiernaast. Ga maar even\n"
	.string "hallo zeggen.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMA: Tot straks, lieverd!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMA: Heb je PROF. BIRCH al\n"
	.string "hallo gezegd?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMA: Hoe gaat het, {PLAYER}?\n"
	.string "Je ziet er een beetje moe uit.\p"
	.string "Rust maar even uit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMA: Pas goed op jezelf, lieverd!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMA: O? Heeft PAPA je die BADGE\n"
	.string "gegeven?\p"
	.string "Dan krijg je ook iets van MAMA!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Doe niet te veel tegelijk, schat.\n"
	.string "Je kunt altijd naar huis komen.\p"
	.string "Zet 'm op, lieverd!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMA: Wat is dat, lieverd? Een POKéNAV?\n"
	.string "Gekregen van iemand van DEVON?\p"
	.string "Zet je mama er dan ook even in!\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MAMA staat nu\n"
	.string "in de POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "VERSLAGGEVER: …Dit was ons verslag\n"
	.string "voor de PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Er is een film op tv.\p"
	.string "Twee mannen dansen op een grote\n"
	.string "piano.\p"
	.string "Tijd om te gaan!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Dit is de uitleg van de\n"
	.string "RENSCHOENEN.\p"
	.string "“Houd de B-knop ingedrukt om te\n"
	.string "rennen met je RENSCHOENEN.\p"
	.string "“Strik je RENSCHOENEN en ren\n"
	.string "de wereld in!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPA: Hm?\p"
	.string "Hé, het is {PLAYER}!\p"
	.string "Ik heb je lang niet gezien, maar je\n"
	.string "ziet er… sterker uit.\p"
	.string "Dat is wat ik zie.\n"
	.string "Maar je vader is nog niet verslagen!\p"
	.string "O ja, ik heb iets voor je.\n"
	.string "Dit is voor jou, van ene\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA: Hm, een KAARTJE voor de boot?\p"
	.string "Volgens mij gaan er boten uit\n"
	.string "SLATEPORT en LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ik moet terug naar de PETALBURG GYM.\p"
	.string "MAMA, bedankt dat je voor het huis\n"
	.string "zorgt als ik weg ben.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMA: Die PAPA van jou…\p"
	.string "Hij is eindelijk eens thuis, maar hij\n"
	.string "praat alleen maar over POKéMON.\p"
	.string "Hij moet eens rustig wat langer blijven.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMA: Is dat belangrijk nieuws?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Hier is een\n"
	.string "nieuwsflits!\p"
	.string "Op allerlei plekken in HOENN is een\n"
	.string "vliegende BZZT…kleurige POKéMON\l"
	.string "gezien.\p"
	.string "Niemand weet nog welke POKéMON\n"
	.string "dit is.\p"
	.string "We gaan nu verder met\n"
	.string "de film.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMA: {PLAYER}, heb je het gehoord?\p"
	.string "Welke kleur had die POKéMON\n"
	.string "volgens de nieuwslezer?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMA: Nou, wat bijzonder!\n"
	.string "Er zijn nog steeds onbekende POKéMON.$"
