RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Ce tableau liste les changements de\n"
	.string "statut pouvant toucher les POKéMON\l"
	.string "au combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Lire quel sujet?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné, ses PV\n"
	.string "diminuent régulièrement.\p"
	.string "Les effets du poison perdurent\n"
	.string "après un combat.\p"
	.string "Les PV d’un POKéMON empoisonné\n"
	.string "continuent à diminuer hors combat.\p"
	.string "L’ANTIDOTE remédie à l’empoisonnement.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON est paralysé, sa\n"
	.string "VITESSE diminue.\p"
	.string "Il peut aussi être dans l’incapacité\n"
	.string "de se déplacer pendant le combat.\p"
	.string "La paralysie persiste après le combat.\n"
	.string "L’ANTI-PARA permet d’y remédier.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s’endort, il est\n"
	.string "dans l’incapacité d’attaquer.\p"
	.string "Le POKéMON peut se réveiller de\n"
	.string "lui-même, mais s’il est endormi à\l"
	.string "la fin du combat, il le restera ensuite.\p"
	.string "Le REVEIL le sortira de son sommeil.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit la puissance\n"
	.string "d’ATTAQUE et les PV de la victime.\p"
	.string "Une brûlure persiste après le combat.\n"
	.string "L’ANTI-BRULE permet d’y remédier.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON est gelé, il n’est\n"
	.string "plus d’aucune aide.\p"
	.string "Il restera gelé après le combat.\n"
	.string "L’ANTIGEL permet de le dégeler.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Les élèves qui ne travaillent pas n’ont\n"
	.string "qu’un petit échantillon de ma VIVE\l"
	.string "GRIFFE.\p"
	.string "La manière dont tu utiliseras cet objet\n"
	.string "indiquera de façon évidente si tu\l"
	.string "apprends bien ou pas.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON qui porte VIVE GRIFFE\n"
	.string "pourra parfois augmenter sa vitesse\l"
	.string "et attaquer avant son adversaire.\p"
	.string "D’autres objets comme celui-ci sont\n"
	.string "faits pour être portés par un POKéMON.\p"
	.string "Mais celui-ci te donnera déjà matière\n"
	.string "à réfléchir!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Je vais dès maintenant faire un\n"
	.string "échange de POKéMON avec mon ami.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J’ai toujours voulu un GRAINIPIOT\n"
	.string "et j’ai enfin réussi à en avoir un!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Les POKéMON peuvent porter des objets,\n"
	.string "mais ne savent pas utiliser les objets\l"
	.string "conçus par les hommes, tels que la\l"
	.string "POTION ou l’ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Tu sais combien certaines capacités\n"
	.string "peuvent troubler un POKéMON?\p"
	.string "Un POKéMON confus peut parfois\n"
	.string "se blesser sans le vouloir.\p"
	.string "Mais après le combat, il retrouve\n"
	.string "ses esprits.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON qui porte une BAIE\n"
	.string "se soignera lui-même…\p"
	.string "Il existe de nombreuses sortes\n"
	.string "d’objets qu’un POKéMON peut porter…\p"
	.string "C’est sûr, c’est pas facile d’arriver\n"
	.string "à tout noter…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C’est le carnet de cet étudiant…\p"
	.string "On attrape les POKéMON avec des\n"
	.string "POKé BALLS.\p"
	.string "Jusqu’à six POKéMON peuvent\n"
	.string "accompagner un DRESSEUR.\p"
	.string "Un DRESSEUR est une personne\n"
	.string "qui attrape des POKéMON, les fait\l"
	.string "progresser et se bat avec eux.\p"
	.string "L’objectif du DRESSEUR est de battre\n"
	.string "les puissants CHAMPIONS qui attendent\l"
	.string "les adversaires dans les ARENES POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Salut! On s’est déjà vus, non?\n"
	.string "Je crois que c’était à CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m’appelle SCOTT.\p"
	.string "Je voyage un peu partout à la recherche\n"
	.string "de DRESSEURS de talent.\p"
	.string "Plus précisément, je recherche des\n"
	.string "experts en combats de POKéMON.\p"
	.string "Alors dis-moi, qu’est-ce qui t’amène\n"
	.string "dans cette ECOLE? Es-tu aussi\l"
	.string "un DRESSEUR?\p"
	.string "La première chose que tu devrais faire\n"
	.string "est d’enseigner la capacité COUPE à\l"
	.string "un de tes POKéMON.\p"
	.string "Si je me souviens bien, quelqu’un\n"
	.string "dans cette ville possède COUPE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Je ne connais pas le niveau de ces\n"
	.string "étudiants, mais il y a du potentiel.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, qu’est-ce que c’est?\p"
	.string "C’est le BADGE ROCHE, n’est-ce pas?\n"
	.string "Je dois dire que je suis impressionné.\p"
	.string "Tu sais, j’aurais beaucoup aimé te voir\n"
	.string "en plein combat.\p"
	.string "Il est difficile d’imaginer quel genre de\n"
	.string "DRESSEUR tu es, à partir d’un\l"
	.string "BADGE de la LIGUE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Salut! On s’est déjà vus, non?\n"
	.string "Je crois que c’était à CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m’appelle SCOTT.\p"
	.string "Je voyage un peu partout à la recherche\n"
	.string "de DRESSEURS de talent.\p"
	.string "Plus précisément, je recherche des\n"
	.string "experts en combats de POKéMON.\p"
	.string "Oh, qu’est-ce que c’est?\p"
	.string "C’est le BADGE ROCHE, n’est-ce pas?\n"
	.string "Je dois dire que je suis impressionné.\p"
	.string "Tu sais, j’aurais beaucoup aimé te voir\n"
	.string "en plein combat.\p"
	.string "Il est difficile d’imaginer quel genre\n"
	.string "de DRESSEUR tu es, à partir d’un\l"
	.string "BADGE de la LIGUE.$"

