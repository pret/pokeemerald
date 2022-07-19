.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "C’est PIERRE qui m’a donné ça, mais\n"
	.string "je ne sais pas à quoi ça sert au juste.\p"
	.string "Je crois qu’on appelle ça la ROCHE\n"
	.string "ROYALE. Tu la veux?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pourquoi en voudrais-tu?\n"
	.string "C’est bizarre.\p"
	.string "Tu peux la garder, mais il ne faut pas\n"
	.string "que PIERRE le sache.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La maison de PIERRE est juste là!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Hé, tu trouves aussi! Qu’est-ce qu’on\n"
	.string "peut bien pouvoir faire avec de drôles\l"
	.string "de pierres?$"

MossdeepCity_Text_WailmerWatching:
	.string "Aux alentours d’ALGATIA, tu peux\n"
	.string "voir des WAILMER sauvages.\p"
	.string "Ça s’appelle, euh…\n"
	.string "Comment c’est déjà…\p"
	.string "Attends, attends, attends…\p"
	.string "L’observation de WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Ce CENTRE SPATIAL insulaire a lancé\n"
	.string "de très grosses fusées.\p"
	.string "Mais ils sont très inquiets depuis qu’ils\n"
	.string "ont reçu une certaine lettre.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Ce CENTRE SPATIAL insulaire a lancé\n"
	.string "de très grosses fusées.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "J’ai appris d’un ami MARIN que la\n"
	.string "TEAM AQUA s’est installée à NENUCRIQUE.\p"
	.string "J’ai aussi appris que quelqu’un s’est\n"
	.string "mêlé de leurs affaires!\p"
	.string "Mais ALGATIA est déjà la cible de la\n"
	.string "TEAM MAGMA.\p"
	.string "Si tu veux savoir ce qu’ils manigancent,\n"
	.string "tu devrais aller au CENTRE SPATIAL.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Je suis MARIN, la mer est donc très\n"
	.string "importante pour moi.\p"
	.string "Mais tu sais, après un long voyage\n"
	.string "en mer, je me sens soulagé de poser\l"
	.string "le pied à terre.$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ça ne serait pas charmant?\p"
	.string "Si le monde entier était recouvert de\n"
	.string "plantes et de fleurs comme cette île?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toute forme de vie, même terrestre,\n"
	.string "a besoin de la mer pour vivre.\p"
	.string "La vie, une fois consumée, n’est plus\n"
	.string "que poussière qui retourne à la terre.\p"
	.string "Et la mer est toujours reliée à la terre.\p"
	.string "Oui, comme le rivage ici.$"

MossdeepCity_Text_SurfExhilarating:
	.string "C’est sympa de voyager sur un bateau.\p"
	.string "Mais traverser la mer avec un POKéMON\n"
	.string "qui utilise SURF…\p"
	.string "Là, c’est un voyage grisant!\n"
	.string "T’es pas d’accord, mon p’tit?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Cette pierre a un sens particulier\n"
	.string "pour les gens du CENTRE SPATIAL.\p"
	.string "Ils l’ont posée là et fait le vœu que\n"
	.string "leurs fusées volent en toute sécurité.\p"
	.string "Tu fais comment, toi, pour faire un\n"
	.string "vœu? T’attends de voir une étoile\l"
	.string "filante?\p"
	.string "Moi, je jette une pièce dans une\n"
	.string "fontaine pour que mon vœu se réalise.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "C’est une pierre blanche.$"

MossdeepCity_Text_GymSign:
	.string "ARENE POKéMON d’ALGATIA\n"
	.string "CHAMPIONS: TATIA et LEVY\p"
	.string "“La combinaison mystique!”$"

MossdeepCity_Text_CitySign:
	.string "ALGATIA\n"
	.string "“Notre slogan: chérir les POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRE SPATIAL D’ALGATIA\n"
	.string "“L’endroit le plus proche de l’espace.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: Comment ça va, {PLAYER}{KUN}?\n"
	.string "Pour moi ça roule en tout cas!\p"
	.string "J’ai entendu dire que le CHAMPION\n"
	.string "D’ARENE d’ALGATIA est assez fort, alors\l"
	.string "je viens voir ça de mes propres yeux.\p"
	.string "Mais il y a quelque chose d’étrange\n"
	.string "qui se passe ici.\p"
	.string "Les gens parlent d’une lettre et du\n"
	.string "CENTRE SPATIAL…\p"
	.string "Mais tout ça ne me concerne pas de\n"
	.string "toute façon.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahhh… C’est tellement bon de laisser\n"
	.string "les embruns caresser mon visage…\p"
	.string "En parlant de la mer, tu connais cette\n"
	.string "ville insulaire, ATALANOPOLIS?\p"
	.string "Je crois qu’ils ont un nouveau CHAMPION\n"
	.string "dans leur ARENE.\p"
	.string "Il paraît que ce nouveau CHAMPION\n"
	.string "était le mentor de MARC.$"

