.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

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
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
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
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
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
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
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
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
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
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
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
	removeobject LOCALID_RIVAL
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
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
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
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
	.string "MAMAN: Alors, {PLAYER}?\n"
	.string "C’est joli ici, non?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Les POKéMON déménageurs font tout\n"
	.string "le travail et nettoient après.\p"
	.string "C’est vraiment pratique!\p"
	.string "{PLAYER}, ta chambre est à l’étage.\n"
	.string "Va voir à quoi elle ressemble, mon chou!\p"
	.string "PAPA a acheté une nouvelle horloge\n"
	.string "pour fêter notre déménagement.\p"
	.string "N’oublie pas de la mettre à l’heure!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMAN: Eh bien, {PLAYER}?\p"
	.string "Tu n’as pas envie de voir ta\n"
	.string "nouvelle chambre?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMAN: {PLAYER}.\p"
	.string "Va mettre l’horloge de ta chambre à\n"
	.string "l’heure, mon chou.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMAN: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Vite! Viens voir!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMAN: Regarde! C’est l’ARENE de\n"
	.string "CLEMENTI-VILLE!\p"
	.string "On va peut-être voir PAPA!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMAN: Oh… C’est terminé.\p"
	.string "Ils ont sûrement interviewé PAPA,\n"
	.string "mais on l’a raté. Dommage.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, tiens!\n"
	.string "L’un des amis de PAPA vit ici.\p"
	.string "Il s’appelle PROF. SEKO.\p"
	.string "C’est notre voisin. Tu pourrais aller\n"
	.string "lui dire bonjour et te présenter.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMAN: A plus tard, mon chou!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMAN: Tu as déjà rencontré le\n"
	.string "PROF. SEKO?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMAN: Comment ça va, {PLAYER}?\n"
	.string "Tu as l’air raplapla.\p"
	.string "Tu devrais peut-être te reposer.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMAN: A bientôt, mon chou!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMAN: Oh? PAPA t’a donné\n"
	.string "un BADGE?\p"
	.string "Dans ce cas, je vais te donner ça!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Ne t’épuise pas trop, mon chou. Tu peux\n"
	.string "revenir à la maison quand tu veux.\p"
	.string "Bon courage, mon poussin!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMAN: C’est un POKéNAV, mon chou? \n"
	.string "Quelqu’un de DEVON te l’a donné?\p"
	.string "Dis, mon chou? Et si tu enregistrais\n"
	.string "ta maman?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Vous avez enregistré MAMAN\n"
	.string "dans le POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Vigooooh…$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Gorooooh…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "JOURNALISTE: … Ce reportage vous a été\n"
	.string "présenté devant l’ARENE de CLEMENTI.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Il y a un film à la télé.\p"
	.string "Deux hommes dansent sur un\n"
	.string "grand piano.\p"
	.string "Bon, il faut y aller!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "C’est le manuel d’instructions des\n"
	.string "CHAUSSURES DE SPORT.\p"
	.string "“Lorsque vous portez vos CHAUSSURES\n"
	.string "DE SPORT, appuyez sur le bouton B\l"
	.string "pour courir.”\p"
	.string "“Enfilez vos CHAUSSURES DE SPORT\n"
	.string "et foncez droit devant!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPA: Hein?\p"
	.string "Hé, mais c’est {PLAYER}!\p"
	.string "Ça fait un moment qu’on ne s’est pas\n"
	.string "vus. Tu as l’air d’avoir plus d’aplomb.\p"
	.string "C’est l’impression que tu me donnes.\n"
	.string "Mais ton vieux père n’abandonne pas!\p"
	.string "Ah, oui, j’ai quelque chose pour toi.\n"
	.string "Un certain M. MARCO m’a donné ça\l"
	.string "pour toi.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA: C’est un PASSE pour le ferry?\p"
	.string "Si ma mémoire est bonne, il y a des \n"
	.string "embarcadères à POIVRESSEL et à\l"
	.string "NENUCRIQUE pour le ferry.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Je dois retourner à l’ARENE de\n"
	.string "CLEMENTI-VILLE.\p"
	.string "Désolé chérie, je dois déjà repartir.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMAN: Ton PAPA est incroyable…\p"
	.string "Il n’est jamais à la maison et quand il\n"
	.string "rentre, il ne parle que de POKéMON.\p"
	.string "Il devrait se reposer et rentrer\n"
	.string "plus souvent.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMAN: Est-ce que c’est un scoop?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Et voici un bulletin spécial\n"
	.string "d’informations.\p"
	.string "Selon des témoignages, un POKéMON\n"
	.string "VOLANT de couleur BZZT… a été\l"
	.string "aperçu à plusieurs endroits dans HOENN.\p"
	.string "L’identité de ce POKéMON n’a pas encore\n"
	.string "été déterminée.\p"
	.string "Et maintenant, voici votre film du soir\n"
	.string "en exclusivité.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMAN: {PLAYER}, tu as compris?\p"
	.string "Qu’est-ce qu’ils ont dit à propos de la\n"
	.string "couleur de ce POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMAN: Dire qu’il reste encore des\n"
	.string "POKéMON inconnus à notre époque!$"
