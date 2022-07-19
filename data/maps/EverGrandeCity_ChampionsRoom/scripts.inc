.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "MARC: Bienvenue, {PLAYER}{KUN}.\p"
	.string "A propos de l’incident d’ATALANOPOLIS…\n"
	.string "Réussir à mettre un terme à cette\l"
	.string "crise par tes propres moyens…\p"
	.string "Oups!\p"
	.string "Ça ne serait pas juste de dire que\n"
	.string "tout le mérite te revient.\p"
	.string "Tu as surmonté la situation grâce aux\n"
	.string "liens que tu as avec tes POKéMON.\p"
	.string "Nous, DRESSEURS, prenons soin de nos\n"
	.string "POKéMON en leur donnant des objets\l"
	.string "et en leur apprenant des capacités.\p"
	.string "Mais nous apprenons également\n"
	.string "énormément de nos POKéMON.\p"
	.string "Et c’est ici que tu peux tester le\n"
	.string "résultat de tous tes efforts, face à\l"
	.string "d’autres DRESSEURS et leurs POKéMON.\p"
	.string "Maintenant!\p"
	.string "Qui de nous deux va pouvoir se vanter\n"
	.string "d’avoir les meilleurs POKéMON d’HOENN?\p"
	.string "Nous allons le savoir tout de suite!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Tu as réussi à me battre, moi, le\n"
	.string "MAITRE POKéMON…\p"
	.string "Beau travail.\n"
	.string "Tu as combattu de façon exaspérante,\l"
	.string "mais cependant glorieuse et élégante!\p"
	.string "Gloire à toi, {PLAYER}{KUN}!\p"
	.string "Tu es un DRESSEUR POKéMON\n"
	.string "de grande classe!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "MARC: Les POKéMON que tu as\n"
	.string "envoyés au combat…\p"
	.string "Par moments, ils dansaient comme\n"
	.string "une brise de printemps, à d’autres,\l"
	.string "ils frappaient comme l’éclair.\p"
	.string "Bien que de manière assurée, tu\n"
	.string "as su combattre élégamment!\p"
	.string "Même moi, je fus ébloui par tant\n"
	.string "de maestria!\p"
	.string "Tu te trouves désormais au\n"
	.string "sommet de la LIGUE POKéMON.\p"
	.string "Je te proclame maintenant le\n"
	.string "nouveau…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "FLORA: {PLAYER}{KUN}!\p"
	.string "Voici un petit conseil avant que tu\n"
	.string "n’affrontes le MAITRE…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "FLORA: Hum? Quoi, quoi, quoi?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Il se pourrait que…\p"
	.string "C’est déjà fait?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRICE: {PLAYER}!\p"
	.string "Tu veux un conseil avant d’affronter\n"
	.string "le MAITRE…?$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRICE: {PLAYER}…\p"
	.string "Serais-tu en train de me dire…\n"
	.string "que tu as battu le MAITRE?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. SEKO: Tu as vu?\n"
	.string "Qu’est-ce que je t’avais dit, {RIVAL}?\p"
	.string "Ne t’avais-je pas dit de ne pas te faire\n"
	.string "de soucis pour {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, tu as enfin réussi!\p"
	.string "Quand j’ai su que tu avais battu ton\n"
	.string "propre père à l’ARENE de CLEMENTI,\l"
	.string "je me suis dit que tu avais une chance…\p"
	.string "Mais réaliser que tu es maintenant\n"
	.string "le MAITRE!\p"
	.string "Ah, oui!\p"
	.string "Qu’est-il advenu de ton POKéDEX?\n"
	.string "Laisse-moi voir.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. SEKO: Quoi qu’il en soit,\n"
	.string "félicitations!\p"
	.string "Entre fièrement dans l’ultime pièce!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "MARC: {PLAYER}{KUN}…\p"
	.string "Je vais donc terminer ma phrase.\p"
	.string "Le nouveau MAITRE!\p"
	.string "Suis-moi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "MARC: Je suis désolé, mais…\p"
	.string "A partir d’ici, seuls les DRESSEURS\n"
	.string "devenus MAITRES peuvent entrer.\p"
	.string "Tu vas devoir attendre à l’extérieur\n"
	.string "avec le PROFESSEUR.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "FLORA: Mais… Mais…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Je plaisante! Pas de problème!\n"
	.string "C’est le règlement!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Sincères félicitations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRICE: … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Si c’est le règlement…\p"
	.string "{PLAYER}, c’est bien!\n"
	.string "Félicitations!$"

