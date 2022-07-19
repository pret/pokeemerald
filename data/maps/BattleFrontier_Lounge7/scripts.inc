BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_E, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Oh, oh!\p"
	.string "Tu auras du mal à le croire, mais dans le\n"
	.string "temps, j’étais un DRESSEUR hors pair.\p"
	.string "On disait que j’étais le CANON le\n"
	.string "plus doué du coin!\p"
	.string "… … … … … …\p"
	.string "Comment?\n"
	.string "Je sais, c’est dur à croire.\p"
	.string "Je ne suis pas comme cette vantarde en\n"
	.string "face. Moi, j’ai vraiment du talent!\p"
	.string "Je vais te le prouver.\n"
	.string "Je peux enseigner à tes POKéMON des\l"
	.string "capacités particulières mais mignonnes.\p"
	.string "Bien sûr, ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités avec des\l"
	.string "POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Oh, oh!\p"
	.string "Tu veux des capacités particulières\n"
	.string "mais mignonnes pour tes POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Bien!\n"
	.string "Quelle capacité veux-tu?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "{STR_VAR_1}, n’est-ce pas?\n"
	.string "{STR_VAR_2} POINTS DE COMBAT, d’accord?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Maintenant, choisis le POKéMON à\n"
	.string "qui je dois enseigner cette capacité.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Mais enfin…\n"
	.string "Tu n’as pas assez de POINTS DE COMBAT!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Je suis douée, non?\n"
	.string "Je prends tes POINTS DE COMBAT, merci!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Oh?\n"
	.string "Tu as changé d’avis…\p"
	.string "Si tu veux que je te montre à quel point\n"
	.string "je suis douée, reviens me voir!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Hi, hi, hi!\p"
	.string "C’est difficile à imaginer, à présent,\n"
	.string "mais j’ai été un DRESSEUR fantastique.\p"
	.string "On disait que j’étais la plus forte\n"
	.string "des NAGEUSE, rien que ça!\p"
	.string "… … … … … …\p"
	.string "Comment?\n"
	.string "Tu ne me crois pas, évidemment.\p"
	.string "Je ne suis pas comme cette menteuse\n"
	.string "en face. J’ai vraiment du talent!\p"
	.string "Je peux te le prouver. Je peux\n"
	.string "enseigner des capacités difficiles\l"
	.string "mais belles à tes POKéMON.\p"
	.string "Bien sûr, ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités avec des\l"
	.string "POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Hi, hi, hi!\p"
	.string "Tu veux que j’enseigne des capacités\n"
	.string "difficiles mais belles à tes POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Ces deux vieilles dames n’arrêtent pas\n"
	.string "de se critiquer, comme si elles se\l"
	.string "détestaient.\p"
	.string "Mais si c’était vrai, elles ne seraient\n"
	.string "pas toujours ensemble ici, non?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quand j’étais encore un GAMIN, ces deux\n"
	.string "femmes étaient fortes et magnifiques.\p"
	.string "Elles faisaient des ravages parmi\n"
	.string "les DRESSEURS.\p"
	.string "Mais malgré leur âge, elles sont\n"
	.string "toujours très fortes.\p"
	.string "On peut même dire qu’elles ont fait\n"
	.string "mûrir leurs capacités POKéMON.\p"
	.string "Tout de même… Je ne peux pas\n"
	.string "m’empêcher de penser…\p"
	.string "Vieillir, c’est bien cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Regagne jusqu’à la\n"
	.string "moitié des PV max\n"
	.string "du lanceur.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflige des\n"
	.string "dégâts selon le\n"
	.string "niveau du lanceur.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Aspire la moitié\n"
	.string "des dégâts sur\n"
	.string "l’ennemi endormi.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un coup de poing\n"
	.string "d’une puissance\n"
	.string "incroyable.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Un coup de pied\n"
	.string "super puissant et\n"
	.string "intense.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Une attaque en\n"
	.string "charge. Peut pa-\n"
	.string "ralyser l’ennemi.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Envoie de gros\n"
	.string "rochers. Peut\n"
	.string "apeurer l’ennemi.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Renvoie toute\n"
	.string "attaque physique,\n"
	.string "2 fois plus fort.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Un faible choc\n"
	.string "électrique qui\n"
	.string "paralyse l’ennemi.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Une danse de\n"
	.string "combat pour\n"
	.string "booster l’ATTAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "S’enroule, cache\n"
	.string "les faiblesses.\n"
	.string "Monte la DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Attaque sonore\n"
	.string "qui ne peut être\n"
	.string "lancée qu’endormi.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Envoie de la boue\n"
	.string "au visage et rend\n"
	.string "moins précis.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Envoie des rayons\n"
	.string "en forme d’étoile.\n"
	.string "Touche toujours.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Attaque glaciale.\n"
	.string "Baisse la VITESSE\n"
	.string "de l’ennemi.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Encaisse les\n"
	.string "attaques du tour\n"
	.string "et conserve 1 PV.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copie les effets\n"
	.string "de l’ennemi et les\n"
	.string "passe au lanceur.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un poing de glace\n"
	.string "pouvant geler\n"
	.string "l’ennemi.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un poing électri-\n"
	.string "que pouvant para-\n"
	.string "lyser l’ennemi.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un poing de feu\n"
	.string "pouvant brûler\n"
	.string "l’ennemi.$"
