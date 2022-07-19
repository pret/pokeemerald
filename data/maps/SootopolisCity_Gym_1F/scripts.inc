SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "JUAN, le CHAMPION d’ATALANOPOLIS est\n"
	.string "le spécialiste des POKéMON du type EAU.\p"
	.string "Mais pour le rencontrer, il te faudra\n"
	.string "réussir à avancer sur un sol gelé…\p"
	.string "Ecoute, je suis désolé, mais c’est tout\n"
	.string "ce que je peux te dire.\p"
	.string "Pour le reste, il va falloir que tu\n"
	.string "te débrouilles!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Waouh! Tu as même battu JUAN, censé\n"
	.string "être le meilleur de tout HOENN!\p"
	.string "OK! Regarde ta CARTE DRESSEUR.\p"
	.string "Si tu as tous les BADGES, tu vas pouvoir\n"
	.string "relever le défi de la LIGUE POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Laissez-moi vous demander.\n"
	.string "Saviez-vous que…\l"
	.string "Ah, je ne devrais point être si timide.\p"
	.string "Saviez-vous que j’ai appris à MARC\n"
	.string "tout ce qu’il sait sur les POKéMON?\p"
	.string "J’étais autrefois le CHAMPION de cette\n"
	.string "magnifique ARENE.\p"
	.string "Cependant, un concours de\n"
	.string "circonstances m’a forcé à revenir.\p"
	.string "Mais assez palabré.\n"
	.string "Nous devrions commencer notre\l"
	.string "match, ne pensez-vous pas?\p"
	.string "Préparez-vous à assister à une\n"
	.string "véritable démonstration de talent.\p"
	.string "Une œuvre sur le thème de l’eau\n"
	.string "composée par mes POKéMON et moi.$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ah ah ah, excellent!\n"
	.string "Très bien, la victoire est à vous.\p"
	.string "Je sens en vous l’existence d’une force\n"
	.string "qui vous permettra de surmonter les\l"
	.string "épreuves qui vous attendent.\p"
	.string "Cependant, si je vous compare à MARC\n"
	.string "ou bien à moi-même, je peux dire\l"
	.string "que vous manquez encore d’élégance.\p"
	.string "Peut-être devrais-je vous prêter\n"
	.string "mon habit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ah ah ah, je ne fais que me moquer!\p"
	.string "Plutôt que ma veste, je vous prie\n"
	.string "d’accepter ce BADGE PLUIE.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} reçoit le BADGE PLUIE\n"
	.string "de la part de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avec ce BADGE, tous vos POKéMON\n"
	.string "vous obéiront et feront tout ce que\l"
	.string "vous leur demanderez.\p"
	.string "Ce BADGE permet aussi d’utiliser la\n"
	.string "capacité CS CASCADE pour passer\l"
	.string "les chutes d’eau.\p"
	.string "Et pour que vous n’oubliiez jamais notre\n"
	.string "combat, prenez ceci…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La CT que je vous ai donnée\n"
	.string "contient VIBRAQUA.\p"
	.string "Avec ses vagues d’ultrasons,\n"
	.string "elle vous permettra parfois de rendre\l"
	.string "vos ennemis confus.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE JUAN dans le POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont rassemblé tous\n"
	.string "les BADGES de HOENN doivent faire\l"
	.string "route vers la destination ultime.\p"
	.string "La LIGUE POKéMON!\p"
	.string "Dirigez-vous vers la zone la plus à l’est\n"
	.string "de HOENN, jusqu’à l’île d’ETERNARA.\p"
	.string "La LIGUE POKéMON se trouve là-bas.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Mais il te reste encore un BADGE à\n"
	.string "obtenir à HOENN.\p"
	.string "Si tu veux affronter la LIGUE POKéMON,\n"
	.string "il te faut obtenir ce dernier BADGE du\l"
	.string "CHAMPION D’ARENE de CIMETRONELLE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARENE POKéMON d’ATALANOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ARENE POKéMON d’ATALANOPOLIS\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, cette ARENE avait enfin\n"
	.string "retrouvé toute sa sérénité…\p"
	.string "Mais le cataclysme que vous êtes est\n"
	.string "de retour pour nous tester de nouveau!\p"
	.string "Eh bien j’accepte votre défi avec joie!\p"
	.string "Je serai ravi de vous affronter aussi\n"
	.string "souvent que vous le souhaitez!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, vous remportez la victoire!\n"
	.string "Vous m’avez de nouveau vaincu!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Si je vous demandais de devenir\n"
	.string "mon élève, vous refuseriez, \l"
	.string "j’en suis certain.\p"
	.string "Je voudrais vous faire don de ma\n"
	.string "veste.\p"
	.string "Mais comme je l’imagine, vous la\n"
	.string "refuseriez de la même façon.\p"
	.string "Et cela, jeune DRESSEUR, est un\n"
	.string "signe certain de noblesse!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, cette ARENE avait enfin\n"
	.string "retrouvé toute sa sérénité…\p"
	.string "Mais le cataclysme que vous êtes est\n"
	.string "de retour pour nous tester de nouveau!\p"
	.string "Eh bien j’accepte votre défi avec joie!\p"
	.string "Ah, mais cessez cela!\n"
	.string "Vous n’avez qu’un POKéMON.\p"
	.string "Je souhaiterais que vous reveniez\n"
	.string "avec au moins deux POKéMON.$"

