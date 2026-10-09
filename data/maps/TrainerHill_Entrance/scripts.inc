TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Dit is de TRAINER HILL waar je\n"
	.string "DUOGEVECHTEN kunt doen met veel\l"
	.string "TRAINERS.\p"
	.string "Helaas zijn we nog aan het\n"
	.string "voorbereiden. Kom later terug!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Welkom!\p"
	.string "Dit is de TRAINER HILL waar je\n"
	.string "DUOGEVECHTEN kunt doen met veel\l"
	.string "TRAINERS!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Ben je hier voor het eerst?\p"
	.string "Sla je spel op voordat je\n"
	.string "binnengaat.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Even kijken…\n"
	.string "De TRAINERS hier nu zijn…\p"
	.string "Tot verdieping {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Even kijken…\n"
	.string "De TRAINERS hier nu zijn…\p"
	.string "Er staan TRAINERS in elke kamer.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Wil je de wachtende TRAINERS\n"
	.string "uitdagen?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Ik hou je tijd bij.\n"
	.string "Succes!\p"
	.string "Op je plek…\p"
	.string "Klaar…\p"
	.string "Ga!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Kom zeker nog eens terug!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Jammer.\p"
	.string "Je hebt echt je best gedaan\n"
	.string "in het vechten.\p"
	.string "Kom terug en probeer het opnieuw!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Ik hoop dat je je best doet.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Als TRAINERS van plek wisselen,\n"
	.string "is het heel druk.\p"
	.string "Om het gedrang te vermijden,\n"
	.string "staat de balie nu hier.\p"
	.string "Sorry voor het ongemak.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Bedankt voor het spelen!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Hier bij de TRAINER HILL doen we\n"
	.string "een Tijdrace.\p"
	.string "Je meet hoe lang je erover doet\n"
	.string "om van deze balie naar onze baas\l"
	.string "op het dak te gaan.\p"
	.string "De snelste tijden staan op\n"
	.string "het Tijdbord. Probeer ze te\l"
	.string "kloppen met je vrienden.\p"
	.string "In TRAINER-gevechten onderweg\n"
	.string "krijg je geen Exp. Punten\l"
	.string "of geld.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, sorry, maar je hebt maar\n"
	.string "een POKéMON bij je.\p"
	.string "Je hebt minstens twee POKéMON\n"
	.string "nodig voor dit evenement.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Je bent eindelijk gekomen!\n"
	.string "Ja, je bent er!\p"
	.string "Wacht! Zeg het niet!\n"
	.string "Ik weet waarom je helemaal\l"
	.string "hierheen kwam!\p"
	.string "Je wilde mij zien, de eigenaar\n"
	.string "van de TRAINER HILL, omdat…\p"
	.string "Je een team met me wilt vormen!\n"
	.string "Wa-hoo!\p"
	.string "…Eh?\n"
	.string "Is dat het niet?\p"
	.string "Hoe dan ook, ik zag je op weg\n"
	.string "naar boven. Prachtig gevochten!\n"
	.string "Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Voor iemand zo geweldig als jij\n"
	.string "heb ik het mooiste cadeau!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh nee, je zit vol met spullen!\n"
	.string "Je komt hier later voor terug!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, wacht even! Ben je soms\n"
	.string "heel snel hier gekomen?\p"
	.string "Wat prachtig! Je hoefde niet zo te\n"
	.string "haasten om mij te zien!\p"
	.string "Dat is heerlijk. Ik laat het\n"
	.string "Tijdbord bij de balie bijwerken!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Maar, oh…\n"
	.string "Je was niet erg snel hier.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Misschien vind ik het fijner als je\n"
	.string "de volgende keer sneller komt.\p"
	.string "Dan vorm ik graag een team\n"
	.string "met je!\p"
	.string "Tot ziens, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Ik liet de TRAINER HILL bouwen\n"
	.string "voor maar één reden!\p"
	.string "Om de beste partner te vinden\n"
	.string "met wie ik een team kan vormen!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Wie weet wat voor TRAINERS en\n"
	.string "POKéMON hier voor ons staan?\p"
	.string "Ik weet alleen dat ik iedereen\n"
	.string "opzij duw die in de weg staat!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Ik hoorde dat sterke TRAINERS van\n"
	.string "overal naar de TRAINER HILL komen.\p"
	.string "Ik kan niet wachten om het te proberen!\p"
	.string "Ik duw iedereen opzij\n"
	.string "die in de weg staat!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Zie je het Tijdbord daar?\p"
	.string "Mijn vrienden en ik proberen te\n"
	.string "zien wie het snelst boven is.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Weet jij wanneer ze dit\n"
	.string "openen?\p"
	.string "Ik wacht hier om de allereerste\n"
	.string "uitdager te zijn!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Wil je terug naar\n"
	.string "de balie?$"
