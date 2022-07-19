.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Non! La TEAM MAGMA est arrivée\n"
	.string "avant nous!\p"
	.string "On ne peut pas toujours arriver\n"
	.string "après eux!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Je pensais que tu étais de la\n"
	.string "TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Eh! En effet, tu as une grande force…\n"
	.string "Mais nous sommes nombreux!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Dommage pour toi!\p"
	.string "En arrivant plus tôt, tu n’aurais eu que\n"
	.string "cette minable TEAM MAGMA à affronter.\p"
	.string "Mais maintenant, tu vas devoir\n"
	.string "nous affronter nous,\l"
	.string "la redoutable TEAM AQUA!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urrrgh…\p"
	.string "J’aurais dû te laisser affronter\n"
	.string "la TEAM MAGMA en premier!$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Tu n’y connais rien.\n"
	.string "Arrête de nous ennuyer!$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Hé, je me rappelle de toi!\n"
	.string "C’était au MONT CHIMNEE!!\p"
	.string "Tu ne fais partie d’aucune TEAM,\n"
	.string "alors qu’est-ce que tu fais ici?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si tu dois gêner quelqu’un, que ce soit\n"
	.string "au moins la TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Hé, c’est pas grave!\n"
	.string "On a gagné du temps!\p"
	.string "A l’heure qu’il est, le CHEF a dû réussir\n"
	.string "à obtenir ce qu’il voulait!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, je sais!\n"
	.string "Tu voulais faire partie de la TEAM\l"
	.string "MAGMA mais ils n’ont pas voulu de toi!\p"
	.string "Mais ne pense pas non plus pouvoir\n"
	.string "entrer dans la TEAM AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si tu tiens tant que ça à faire partie\n"
	.string "de la TEAM… On va y réfléchir…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Il y a une très bonne entente entre\n"
	.string "nous et notre chef.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARTHUR: MAX, de la TEAM MAGMA, a été\n"
	.string "plus rapide que nous.\p"
	.string "Mais nous avons aussi ce que nous\n"
	.string "voulions.\p"
	.string "L’ORBE ROUGE du MONT MEMORIA…\n"
	.string "Il est enfin en notre possession!\p"
	.string "… Nous pouvons maintenant\n"
	.string "accomplir notre ultime objectif!\p"
	.string "OK, à tous les membres!\n"
	.string "Repli immédiat!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, non…\n"
	.string "C’est pas possible…\p"
	.string "Après l’ORBE BLEU, l’ORBE ROUGE\n"
	.string "a également été dérobé…\p"
	.string "Il ne faut jamais séparer l’ORBE BLEU \n"
	.string "de l’ORBE ROUGE. Ils forment un tout.\p"
	.string "Qu’est-ce que ces hommes veulent\n"
	.string "faire avec les deux ORBES?\p"
	.string "… … … … … … … …\n"
	.string "Hum…\p"
	.string "Oh oui, c’est bien la TEAM MAGMA qui\n"
	.string "est d’abord venue voler l’ORBE BLEU?\p"
	.string "Eh bien, dans leur hâte, ils ont oublié\n"
	.string "ça derrière eux.\p"
	.string "Je n’arrive pas à voir à quoi\n"
	.string "ça peut servir.\p"
	.string "Je voudrais que tu le prennes.\n"
	.string "Ça pourrait t’être utile.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "L’ORBE BLEU et l’ORBE ROUGE qui\n"
	.string "ont été volés…\p"
	.string "Ils ne doivent jamais être séparés…\n"
	.string "Quelque chose de terrible va se passer…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Alors…\n"
	.string "Tu dis que KYOGRE et GROUDON se\l"
	.string "sont réveillés…\p"
	.string "On dit que l’ORBE BLEU et l’ORBE\n"
	.string "ROUGE peuvent apaiser la colère de\l"
	.string "KYOGRE et GROUDON…\p"
	.string "On raconte aussi que le vrai\n"
	.string "propriétaire des ORBES est toujours\l"
	.string "vivant.\p"
	.string "Pourtant, personne ne sait exactement\n"
	.string "qui il est, ou ce qu’il est.\p"
	.string "Ça pourrait être un humain, ou bien\n"
	.string "un POKéMON…\l"
	.string "Personne ne sait vraiment…$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Les deux hommes qui avaient dérobé\n"
	.string "les ORBES sont revenus les rendre\l"
	.string "de leur plein gré.\p"
	.string "Ces hommes…\p"
	.string "Ils ne sont peut-être pas si méchants\n"
	.string "que ça après tout…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Les esprits de la terre, de la mer\n"
	.string "et du ciel…\p"
	.string "C’est ce que les POKéMON ancestraux\n"
	.string "sont censés incarner…\p"
	.string "Tout comme les POKéMON et nous,\n"
	.string "la nature aussi est vivante…\p"
	.string "Les POKéMON ancestraux nous\n"
	.string "l’ont enseigné…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Au MONT MEMORIA, les esprits des\n"
	.string "POKéMON trépassés sont apaisés.\p"
	.string "C’est un endroit en hauteur, d’où l’on\n"
	.string "domine toute la région de HOENN…\p"
	.string "Les esprits désincarnés doivent y\n"
	.string "trouver réconfort…\p"
	.string "C’est une coïncidence que tu sois là…\p"
	.string "Veux-tu entendre mon récit? Un récit\n"
	.string "longtemps raconté à HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "C’était il y a très longtemps…\p"
	.string "Le monde était ravagé par un conflit\n"
	.string "acharné entre le POKéMON de la terre\l"
	.string "et le POKéMON de la mer…\p"
	.string "Le POKéMON de la terre érigea des\n"
	.string "montagnes et créa des continents.\p"
	.string "Le POKéMON de la mer souleva des\n"
	.string "vagues et découpa des océans.\p"
	.string "Leur duel acharné sévissait sans fin.\p"
	.string "Le monde fut englouti par de violentes\n"
	.string "tempêtes et des brasiers ardents.\p"
	.string "L’ORBE BLEU et l’ORBE ROUGE mirent\n"
	.string "fin à ce désastre.\p"
	.string "La lumière jaillit des deux ORBES et\n"
	.string "apaisa les adversaires furieux.\p"
	.string "Puis, les deux POKéMON finirent par\n"
	.string "disparaître dans les profondeurs\l"
	.string "de la terre…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Je vois…\n"
	.string "Eh bien, ça aussi c’est bien…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAX: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "C’est mon devoir de transmettre\n"
	.string "les légendes d’HOENN aux\l"
	.string "générations futures.\p"
	.string "Et cette crise qui vient de prendre\n"
	.string "fin à ATALANOPOLIS a réécrit\l"
	.string "la légende…\p"
	.string "As-tu le temps d’écouter la nouvelle\n"
	.string "légende d’HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "C’était il y a très longtemps…\p"
	.string "Le monde était ravagé par un conflit\n"
	.string "acharné entre le POKéMON de la terre\l"
	.string "et le POKéMON de la mer…\p"
	.string "Le POKéMON de la terre érigea des\n"
	.string "montagnes et créa des continents.\p"
	.string "Le POKéMON de la mer souleva des\n"
	.string "vagues et découpa des océans.\p"
	.string "Leur duel acharné sévissait sans fin.\p"
	.string "Le monde fut englouti par de violentes\n"
	.string "tempêtes et des brasiers ardents.\p"
	.string "C’est alors qu’apparut un POKéMON\n"
	.string "surgissant d’une tempête.\p"
	.string "Le POKéMON, d’un vert vif comme un\n"
	.string "joyau, réussit à calmer les deux\l"
	.string "POKéMON enragés.\p"
	.string "Sa tâche accomplie, le POKéMON vert\n"
	.string "retourna là-haut dans le ciel…$"

