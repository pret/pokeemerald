.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "ADRIANE, CHAMPION D’ARENE de\n"
	.string "VERMILAVA, utilise des POKéMON FEU.\p"
	.string "Sa passion des POKéMON est plus\n"
	.string "ardente qu’un volcan.\p"
	.string "Ne t’approche pas trop, tu pourrais\n"
	.string "te brûler! Arrose-la avec de l’eau et\l"
	.string "attaque-la sans pitié!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Eh ben! Quelle bataille flamboyante!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ouille ouille ouille!\n"
	.string "Bon sang, c’est brûlant!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "J’ai été aveuglé par la sueur qui me\n"
	.string "coulait dans les yeux…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "S’enterrer dans le sable chaud est\n"
	.string "excellent pour la circulation sanguine.\p"
	.string "C’est très efficace contre les\n"
	.string "rhumatismes.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "J’essaie de libérer mon stress. J’espère\n"
	.string "que tu ne viens pas pour m’énerver!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "J’espère qu’ADRIANE va te rôtir!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Pffiou…\p"
	.string "C’est étouffant de rester trop\n"
	.string "longtemps dans le sable chaud…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Tu commences à fatiguer.\n"
	.string "Tu préfèrerais sûrement te reposer\l"
	.string "dans le sable chaud, n’est-ce pas?\p"
	.string "Mais tu sais sans doute qu’en tant\n"
	.string "que DRESSEUR, tu dois garder une\l"
	.string "volonté à toute épreuve.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Quand on joue avec le feu, on se brûle…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Tu as vraiment du talent…\n"
	.string "Mais ADRIANE, notre CHAMPION,\l"
	.string "en a encore plus.\p"
	.string "Si tu ne fais pas attention, tu vas\n"
	.string "sérieusement te brûler.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Est-ce que tes POKéMON peuvent\n"
	.string "supporter une chaleur de 200 degrés?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Ça ne devait pas être assez chaud…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La température du magma est de\n"
	.string "200 degrés.\p"
	.string "Tes POKéMON m’ont battu, donc ils\n"
	.string "devraient survivre dans du magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Mmmh…\n"
	.string "D’accord, je vais me battre contre toi.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ouille, quelle puissance!$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "En tant que DRESSEUR, je vais devenir\n"
	.string "jolie et puissante, comme ADRIANE.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Allez, battons-nous!\n"
	.string "Je suis chaud!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Malgré la chaleur, j’ai encore trop\n"
	.string "froid aux yeux…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Le combat brûle dans tes veines.\n"
	.string "Tu devrais avoir tes chances face à\l"
	.string "notre CHAMPION.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Tu vois cette flamme dans mon regard?\n"
	.string "C’est la flamme de la victoire!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Quelque chose m’a échappé.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Bon, et alors? Je sais marcher sur\n"
	.string "du charbon ardent, moi d’abord!\p"
	.string "Mais je ne te conseille pas d’essayer!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "J’aime les montagnes, donc j’aime\n"
	.string "aussi les volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "J’ai perdu complètement le contrôle\n"
	.string "de la situation.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Je reste ici car je suis un fan\n"
	.string "d’ADRIANE. Quel regard de braise!\p"
	.string "Hé, hé, hé.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenue… Heu, non, attends.\p"
	.string "Misérable DRESSEUR, je suis contente de\n"
	.string "voir que tu as réussi à arriver ici!\p"
	.string "Par les pouvoirs qui me sont conférés…\n"
	.string "Heu, non, attends.\p"
	.string "Je m’appelle ADRIANE et je suis le\n"
	.string "CHAMPION de cette ARENE!\p"
	.string "Heu…\n"
	.string "Je ne suis pas CHAMPION depuis très\l"
	.string "longtemps, mais ne me sous-estime pas!\p"
	.string "Grâce aux techniques de mon\n"
	.string "grand-père, je vais te prouver, heu…\l"
	.string "que mes attaques sont puissantes!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh non…\n"
	.string "Je suppose que j’ai été prétentieuse…\p"
	.string "Je… Je ne suis devenue CHAMPION\n"
	.string "D’ARENE que très récemment.\p"
	.string "J’ai essayé de devenir quelqu’un que\n"
	.string "je ne suis pas.\p"
	.string "Je dois agir plus spontanément.\n"
	.string "Sinon, mes POKéMON seront confus.\p"
	.string "Merci pour cette leçon.\n"
	.string "Tu as bien mérité ceci.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} reçoit le BADGE CHALEUR\n"
	.string "de la part d’ADRIANE.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Avec le BADGE CHALEUR, tous les \n"
	.string "POKéMON jusqu’au niveau 50 t’obéiront\l"
	.string "sans discuter, même ceux que tu as\l"
	.string "échangés avec tes amis.\p"
	.string "Il permet aussi à tes POKéMON d’utiliser\n"
	.string "FORCE en dehors des combats.\p"
	.string "C’est un gage de ma sympathie.\n"
	.string "Ne sois pas timide. Prends-le!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La CT50 contient SURCHAUFFE.\p"
	.string "Cette attaque inflige de sérieux\n"
	.string "dégâts à l’adversaire.\p"
	.string "En revanche, elle fait aussi baisser\n"
	.string "l’ATTAQUE SPECIALE du POKéMON\l"
	.string "qui l’utilise. Il faut éviter de l’utiliser\l"
	.string "lors des longs combats.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE ADRIANE dans le POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Ta technique me rappelle quelqu’un…\p"
	.string "Oh, je sais! Tu te bats comme NORMAN,\n"
	.string "le CHAMPION D’ARENE de CLEMENTI-VILLE.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "ARENE POKéMON de VERMILAVA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "ARENE POKéMON de VERMILAVA\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR ADRIANE:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "ADRIANE: Je ne vais pas me dégonfler\n"
	.string "après une défaite.\p"
	.string "J’aime les POKéMON.\n"
	.string "J’aime me battre.\l"
	.string "Et surtout… j’adore cette ARENE!\p"
	.string "Allez, que la fièvre du combat s’empare\n"
	.string "de nous!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Waouh!\n"
	.string "Un vrai volcan en éruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "ADRIANE: J’ai perdu, mais j’ai eu ce\n"
	.string "que je voulais.\p"
	.string "Ce combat était chaud comme la\n"
	.string "braise.\p"
	.string "J’espère qu’il y en aura encore\n"
	.string "beaucoup d’autres!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "ADRIANE: Je ne vais pas me dégonfler\n"
	.string "après une défaite.\p"
	.string "J’aime les POKéMON.\n"
	.string "J’aime me battre.\l"
	.string "Et surtout… j’adore cette ARENE!\p"
	.string "Allez, que le feu du combat s’empare\n"
	.string "de nous!\p"
	.string "Mais, attends. Tu n’as qu’un seul\n"
	.string "POKéMON qui peut se battre?\p"
	.string "Désolée, mais je ne me battrai pas tant\n"
	.string "que tu n’en auras pas au moins deux.$"
