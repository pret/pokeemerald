.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
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
	.string "TIMMY: Salut, {PLAYER}!\p"
	.string "J’parie que ça t’surprend de m’voir ici!\p"
	.string "J’ai fait le chemin jusqu’ici, et c’est\n"
	.string "grâce à toi!\p"
	.string "{PLAYER}, le fait de perdre contre toi\n"
	.string "l’autre fois m’a rendu plus fort!\p"
	.string "Mais je ne perdrai plus maintenant!\p"
	.string "Je vais gagner! Pour les POKéMON qui\n"
	.string "m’ont donné courage et force!\p"
	.string "OK… Me voilà!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Waouh!\n"
	.string "{PLAYER}, quelle force tu as quand même!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "TIMMY: Je n’ai pas réussi à te battre\n"
	.string "aujourd’hui, {PLAYER}, mais un de ces\l"
	.string "jours, je t’aurai!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "TIMMY: Salut, {PLAYER}!\p"
	.string "Je suis devenu plus fort!\n"
	.string "Il faut que j’te montre, {PLAYER}!\p"
	.string "OK… J’arrive!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Waouh!\n"
	.string "{PLAYER}, quelle force tu as quand même!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "TIMMY: Je n’ai pas réussi à te battre\n"
	.string "aujourd’hui, {PLAYER}, mais un de ces\l"
	.string "jours, je t’aurai…\p"
	.string "Et j’affronterai la LIGUE POKéMON!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "J’ai fait ça plus d’une fois, mais la\n"
	.string "dernière partie est tellement longue…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Mon rêve s’arrête là, encore une fois…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "T’as fait un bon bout d’chemin. Continue\n"
	.string "sur ta lancée et deviens le MAITRE!\l"
	.string "S’il y en a un qui peut réussir,\l"
	.string "c’est bien toi.$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Je n’ai pas fait toute cette route pour\n"
	.string "perdre. Pas question!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossible…\n"
	.string "J’ai perdu?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "J’ai perdu à ce niveau…\p"
	.string "Je n’ai donc pas les qualifications\n"
	.string "requises pour être le MAITRE…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Cette route difficile et sans fin\n"
	.string "porte bien son nom de VICTOIRE.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Ton style de combat est génial…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Tu sembles avoir le potentiel pour\n"
	.string "devenir le MAITRE.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Qu’est-ce que la ROUTE VICTOIRE?\n"
	.string "Je te le dirai quand tu gagneras!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "OK!\n"
	.string "Bien joué!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Sortir d’ici sain et sauf, c’est\n"
	.string "le dernier test pour les DRESSEURS\l"
	.string "qui veulent devenir MAITRE POKéMON.\p"
	.string "C’est pour cela qu’on appelle ce lieu\n"
	.string "la ROUTE VICTOIRE.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Je n’ai rien à dire à quelqu’un qui est\n"
	.string "allé si loin. Viens te battre!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Une vraie disgrâce…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Humpf, continue tout droit.\n"
	.string "Si tu en as le courage…$"
