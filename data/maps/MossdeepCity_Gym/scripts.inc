MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "Les CHAMPIONS D’ARENE de cette ville\n"
	.string "utilisent des POKéMON du type PSY.\p"
	.string "Si tu te bats contre eux avec des\n"
	.string "POKéMON du type COMBAT ou POISON,\l"
	.string "ils vont t’infliger de sérieux dommages.\p"
	.string "En plus, ils t’affronteront avec de\n"
	.string "remarquables attaques combinées.\p"
	.string "Si tu veux gagner, il faudra que tu\n"
	.string "démontres combien tu es proche \l"
	.string "de tes POKéMON. En avant!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Waouh, renversant!\n"
	.string "Tu es un grand DRESSEUR!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "L’issue du combat dépend du mental!\n"
	.string "Les faibles d’esprit ne gagnent jamais!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "J’ai perdu!\n"
	.string "Je dois renforcer mon mental!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Les indécis perdent toujours.\n"
	.string "C’est mon avertissement.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Montre-moi ton talent!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Tu as un talent spectaculaire!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "S’il existe au monde des prodiges,\n"
	.string "ce sont bien nos CHAMPIONS!\p"
	.string "Mais tu as peut-être encore plus\n"
	.string "de talent qu’eux…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Hé, hé… Regarde-moi soulever une\n"
	.string "POKé BALL par télékinésie!\p"
	.string "Arrrrrrrrrrrrg!\n"
	.string "… … … … … … …\p"
	.string "Je suis parfois désynchronisé…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Les aptitudes au combat de mon POKéMON\n"
	.string "sont parfois désynchronisées aussi!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "La POKé BALL, c’était trop lourd à\n"
	.string "soulever mentalement. Mais ce flocon\l"
	.string "de poussière…\p"
	.string "Waaaaaaaaaaaaaaaaaaouh!\n"
	.string "… … … … … …\p"
	.string "Non, je ne triche pas!\n"
	.string "Je n’ai pas soufflé dessus! Vraiment!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Si tu perds contre moi, ne sois pas\n"
	.string "trop sévère avec toi-même.\p"
	.string "Ce n’est pas que tu sois faible, c’est\n"
	.string "que je suis trop forte pour toi!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "T’as tout simplement un meilleur niveau!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Je ne vais pas m’apitoyer parce que j’ai\n"
	.string "perdu. Je vais m’entraîner davantage.\p"
	.string "L’optimisme, c’est mon point fort!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Je vois…\n"
	.string "Je vois ton avenir…\p"
	.string "Si tu réussis à me battre, je te prédis\n"
	.string "ton avenir!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Je me rends!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Tu vas livrer un combat d’une grande\n"
	.string "intensité avec nos CHAMPIONS…\p"
	.string "Résultat…\n"
	.string "Tu ne l’entendras pas de ma bouche!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Le chemin que tu as parcouru…\n"
	.string "Tout ce que tu as vécu…\p"
	.string "Fais-moi voir ce que tu as appris!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Tu t’es frayé une voie dans la grandeur!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un brillant avenir attend ceux qui ont\n"
	.string "travaillé assidûment.\p"
	.string "Ceux qui paressent ne connaîtront\n"
	.string "finalement que le désespoir.\p"
	.string "Tout finit toujours par se payer…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Je gagnerai ce combat, même au\n"
	.string "péril de ma vie!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Qu’est-ce que tu as fait?\n"
	.string "Je suis horrifiée.$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Comment as-tu osé me battre?\p"
	.string "Ne viens pas te plaindre si quelque\n"
	.string "chose t’arrive bientôt!$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Je vais te montrer comme le type PSY\n"
	.string "peut être dur à vaincre!$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Je suis abasourdi!\n"
	.string "Ton style est fantastique!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "… Je… Je ne me… laisse pas…\n"
	.string "abattre… par la… défaite!$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Laisse-moi te montrer la noirceur\n"
	.string "de ton âme!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N… Noooon!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Ta vitalité est contagieuse!\n"
	.string "Eloigne-toi vite de moi!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Je ne suis peut-être plus tout jeune,\n"
	.string "mais je te suggère de ne pas me\l"
	.string "sous-estimer.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "La force de la jeunesse émane de toi!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Je n’ai pas réussi à contrer la fougue\n"
	.string "de la jeunesse.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Tu n’arriveras pas au bout!\n"
	.string "Je t’en empêcherai!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Comment un si petit corps peut-il\n"
	.string "cacher tant de force?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "J’ai perdu mais c’est mieux ainsi!\p"
	.string "Ta façon brutale de combattre ne\n"
	.string "convient pas aux POKéMON PSY.$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Yahaaa! Goûte un peu à la puissance\n"
	.string "de mon POKéMON!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Déjà?$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Très bien, je n’ai plus qu’à développer\n"
	.string "un nouveau type de POKéMON invincible!$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "LEVY: Hé, hé… Ça te surprend?\n"
	.string "TATIA: Ah, ah… Ça te surprend?\p"
	.string "LEVY: Qu’il y ait deux CHAMPIONS?\n"
	.string "TATIA: Qu’il y ait deux CHAMPIONS?\p"
	.string "LEVY: On est jumeaux!\n"
	.string "TATIA: On est jumeaux!\p"
	.string "LEVY: On n’a pas besoin de se parler…\n"
	.string "TATIA: On sait ce que…\p"
	.string "LEVY: l’autre pense…\n"
	.string "TATIA: Tout est dans nos esprits!\p"
	.string "LEVY: Cette osmose parfaite…\n"
	.string "TATIA: Pourras-tu la battre?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "LEVY: Quoi? Notre osmose…\n"
	.string "TATIA: a été brisée!\p"
	.string "LEVY: Tant pis! Tu as gagné…\n"
	.string "TATIA: Prends ça en récompense.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} reçoit le BADGE ESPRIT de\n"
	.string "la part de LEVY et TATIA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "LEVY: Le BADGE ESPRIT augmente\n"
	.string "l’ATQ. SPE. et la DEF. SPE. des POKéMON.\p"
	.string "TATIA: Il permet aussi d’utiliser la CS\n"
	.string "PLONGEE hors combat.\p"
	.string "LEVY: Tu devrais prendre ça, aussi.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "LEVY: Cette CT04 contient…\n"
	.string "TATIA: PLENITUDE!\p"
	.string "LEVY: Elle accroît l’ATQ. SPE. et…\n"
	.string "TATIA: elle accroît la DEF. SPE.!\p"
	.string "LEVY: C’est l’attaque parfaite…\n"
	.string "TATIA: pour les POKéMON du type PSY!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "CHAMPIONS D’ARENE LEVY & TATIA\n"
	.string "enregistrés dans le POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "LEVY: Le lien qui te lie à tes POKéMON\n"
	.string "semble bien plus fort que celui qui nous\l"
	.string "lie en tant que jumeaux.\p"
	.string "TATIA: Tu vas encore t’améliorer! On\n"
	.string "s’est battus contre toi. On sait de quoi\l"
	.string "on parle.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "LEVY: Hé, hé… Ça te surprend…\p"
	.string "TATIA: qu’il y ait deux CHAMPIONS?\p"
	.string "LEVY: Oups, tu n’as qu’un seul…\n"
	.string "TATIA: POKéMON pouvant combattre.\p"
	.string "LEVY: On ne peut pas s’affronter!\p"
	.string "TATIA: Si tu veux te mesurer à nous,\n"
	.string "reviens avec plus de POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "ARENE POKéMON d’ALGATIA$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "ARENE POKéMON d’ALGATIA\p"
	.string "NOUVEAU DRESSEUR RECONNU\n"
	.string "PAR TATIA ET LEVY: {PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "LEVY: POKéMON…\n"
	.string "TATIA: POKéMON…\p"
	.string "LEVY: En changeant l’ordre de l’équipe…\n"
	.string "TATIA: le style du combat change.\p"
	.string "LEVY: Mais moi…\n"
	.string "TATIA: Mais moi…\p"
	.string "LEVY: Je serai toujours avec TATIA!\n"
	.string "TATIA: Je serai toujours avec LEVY!\p"
	.string "LEVY: Tu verras encore et encore…\n"
	.string "TATIA: notre combinaison!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "LEVY: Tes POKéMON et toi…\n"
	.string "TATIA: vous êtes comme une seule\l"
	.string "personne!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "LEVY: Tu peux nous battre mais\n"
	.string "nous nous relèverons toujours!\p"
	.string "TATIA: Parce que nous nous soutenons\n"
	.string "l’un l’autre!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "LEVY: Tu es de retour…\n"
	.string "TATIA: Tu es de retour…\p"
	.string "LEVY: pour une revanche.\n"
	.string "TATIA: pour une revanche.\p"
	.string "LEVY: Mais…\n"
	.string "TATIA: pour notre match…\p"
	.string "LEVY: tu n’as qu’un POKéMON!\n"
	.string "TATIA: tu n’as qu’un POKéMON!\p"
	.string "LEVY: La prochaine fois…\n"
	.string "TATIA: ramène au moins 2 POKéMON!$"
