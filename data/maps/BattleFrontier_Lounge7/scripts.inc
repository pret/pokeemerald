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
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
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
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
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
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
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
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
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
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
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
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Je ziet het nu niet meer, maar ik was\n"
	.string "vroeger een sterke TRAINER.\p"
	.string "Ik stond bekend als de sterkste\n"
	.string "SCHOONHEID van allemaal!\p"
	.string "… … … … … …\p"
	.string "Wat is er?\n"
	.string "Je gelooft me niet.\p"
	.string "Ik ben niet zoals die opschepper\n"
	.string "daar. Ik kan echt iets!\p"
	.string "Ik bewijs het je.\n"
	.string "Ik leer je POKéMON speciale en\l"
	.string "toch schattige AANVALLEN.\p"
	.string "Maar mijn lessen zijn niet gratis.\n"
	.string "Wat dacht je van een beetje\l"
	.string "GEVECHTSPUNTEN voor elke AANVAL?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Kom je speciale en toch schattige\n"
	.string "POKéMON-AANVALLEN leren?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Goed, goed, kijk maar!\n"
	.string "Welke AANVAL moet ik leren?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "De AANVAL {STR_VAR_1}, is het die?\n"
	.string "Dat kost {STR_VAR_2} GEVECHTSPUNTEN, oké?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Goed, goed, kies nu de POKéMON\n"
	.string "die de AANVAL moet leren.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Wat nou…\n"
	.string "Je hebt niet genoeg GEVECHTSPUNTEN!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Zie je nu hoe goed ik ben?\n"
	.string "Ik neem je GEVECHTSPUNTEN, bedankt!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Wat zeg je?\n"
	.string "Je wilt niet…\p"
	.string "Wil je zien hoe goed ik ben,\n"
	.string "kom dan altijd langs!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Je ziet het nu niet meer, maar ik was\n"
	.string "vroeger een fantastische TRAINER.\p"
	.string "Ik stond bekend als de meest\n"
	.string "onverslaanbare ZWEMSTER van allemaal!\p"
	.string "… … … … … …\p"
	.string "Wat is er?\n"
	.string "Je gelooft me niet.\p"
	.string "Ik ben niet zoals die rare vrouw\n"
	.string "daar. Ik heb echt ervaring!\p"
	.string "Ik bewijs het je.\n"
	.string "Ik leer je POKéMON stoere en\l"
	.string "toch mooie AANVALLEN.\p"
	.string "Maar mijn lessen zijn niet gratis.\n"
	.string "Wat dacht je van een beetje\l"
	.string "GEVECHTSPUNTEN voor elke AANVAL?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Kom je stoere en toch mooie\n"
	.string "POKéMON-AANVALLEN leren?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Zoals die dames over elkaar praten,\n"
	.string "denk je vast dat ze het niet met\l"
	.string "elkaar kunnen vinden.\p"
	.string "Maar dan zouden ze hier niet samen\n"
	.string "blijven zitten, toch?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Toen ik nog een kleine JONGEN was,\n"
	.string "waren die dames sterk en mooi.\p"
	.string "Ze waren onze idolen als TRAINERS.\p"
	.string "Zelfs nu zijn ze nog steeds\n"
	.string "zo goed.\p"
	.string "Ze AANVALLEN zijn zelfs nog\n"
	.string "beter geworden.\p"
	.string "Maar… Om de een of andere reden\n"
	.string "voel ik dit toch…\p"
	.string "De tijd is zo wreed…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Geneest de helft\n"
	.string "van de HP van\n"
	.string "de gebruiker.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Doet schade\n"
	.string "gelijk aan het\n"
	.string "level van de gebruiker.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Geneest de helft\n"
	.string "van de schade\n"
	.string "aan een slapende vijand.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Een sterke vuist\n"
	.string "met ongelofelijke\n"
	.string "kracht.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Een supersterke\n"
	.string "trap met enorme\n"
	.string "kracht.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Een zware botsing\n"
	.string "die kan\n"
	.string "verlammen.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Grote rotsen\n"
	.string "worden gegooid.\n"
	.string "Kan terugdeinzen.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Slaat elke klap\n"
	.string "terug met dubbele\n"
	.string "kracht.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Een zwakke schok\n"
	.string "die de vijand\n"
	.string "verlamt.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Een vechtdans die\n"
	.string "AANVAL flink\n"
	.string "verhoogt.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Rolt zich op om\n"
	.string "zwakke plekken\n"
	.string "te beschermen.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Een luide aanval\n"
	.string "die alleen in je\n"
	.string "slaap werkt.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Gooit modder in\n"
	.string "het gezicht om\n"
	.string "de raakkans te\l"
	.string "verlagen.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Schiet sterren\n"
	.string "die nooit\n"
	.string "missen.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Een ijzige aanval\n"
	.string "die de SNELHEID\n"
	.string "van de vijand\l"
	.string "verlaagt.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Houdt elke aanval\n"
	.string "een beurt vol\n"
	.string "met 1 HP over.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Kopieert de\n"
	.string "verbeteringen van\n"
	.string "de vijand.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Een ijskoude vuist\n"
	.string "die de vijand\n"
	.string "kan bevriezen.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Een vuist vol\n"
	.string "stroom die kan\n"
	.string "verlammen.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Een vurige vuist\n"
	.string "die de vijand\n"
	.string "kan verbranden.$"
