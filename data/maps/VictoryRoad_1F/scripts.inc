VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Hoi! {PLAYER}!\p"
	.string "Je bent vast verrast om mij hier te\n"
	.string "zien!\p"
	.string "Ik ben helemaal hier gekomen, en\n"
	.string "dat is dankzij jou!\p"
	.string "{PLAYER}, door die keer van je te\n"
	.string "verliezen werd ik sterker!\p"
	.string "Maar ik ga niet meer verliezen!\p"
	.string "Ik ga winnen! Voor de POKéMON die\n"
	.string "mij moed en kracht gaf!\p"
	.string "Oké… Daar ga ik!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, je bent toch sterk!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Ik kon je vandaag niet\n"
	.string "verslaan, {PLAYER}, maar op een dag\l"
	.string "haal ik je in!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Hoi! {PLAYER}!\p"
	.string "Ik ben sterker geworden sinds\n"
	.string "de vorige keer! Dat wilde ik je\l"
	.string "laten zien, {PLAYER}!\p"
	.string "Oké… Daar ga ik!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, je bent toch sterk!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Ik kon je ook deze keer\n"
	.string "niet verslaan… Maar op een dag,\l"
	.string "{PLAYER}, haal ik je in…\p"
	.string "En daag ik de POKéMON LEAGUE uit!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Ik kwam hier al een paar keer,\n"
	.string "maar het laatste stuk is zo lang…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Mijn droom eindigt hier weer…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Je bent zo ver gekomen. Hou het\n"
	.string "tempo vast en word KAMPIOEN!\l"
	.string "Als iemand het kan, ben jij het!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Ik kwam niet helemaal hier om\n"
	.string "nu te verliezen. Dat kan niet!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Onmogelijk…\n"
	.string "Ik verloor?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Ik verloor hier…\p"
	.string "Dan ben ik niet goed genoeg om\n"
	.string "KAMPIOEN te worden…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Deze eindeloze, harde weg\n"
	.string "maakt zijn naam VICTORY waar.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Jouw vechtstijl is fantastisch…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Je lijkt het talent te hebben\n"
	.string "om KAMPIOEN te worden.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Wat is de VICTORY ROAD?\n"
	.string "Ik vertel het als je wint!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Oké!\n"
	.string "Goed gedaan!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Hier veilig doorheen komen is de\n"
	.string "laatste test voor elke TRAINER die\l"
	.string "POKéMON KAMPIOEN wil worden.\p"
	.string "Daarom heet het de VICTORY\n"
	.string "ROAD.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Ik heb niets te zeggen tegen\n"
	.string "iedereen die zo ver kwam. Kom op!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Dit is een schande…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hmpf, ga maar door.\n"
	.string "Het kan me niet schelen.$"
