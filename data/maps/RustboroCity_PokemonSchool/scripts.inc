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
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
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
	.string "Op het bord staan kwaaltjes die\n"
	.string "POKéMON in gevechten kunnen krijgen.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Waarover wil je lezen?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Een vergiftigde POKéMON verliest\n"
	.string "steeds HP.\p"
	.string "Het gif blijft ook na het\n"
	.string "gevecht.\p"
	.string "Tijdens het lopen verliest een\n"
	.string "vergiftigde POKéMON ook HP.\p"
	.string "Geneesmiddel: TEGENGIF.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Een verlamde POKéMON wordt\n"
	.string "langzamer.\p"
	.string "Soms kan hij in een gevecht\n"
	.string "niet bewegen.\p"
	.string "Verlamming blijft na het gevecht.\n"
	.string "Geneesmiddel: VERLAMZALF.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Een slapende POKéMON kan niet\n"
	.string "aanvallen.\p"
	.string "Hij kan vanzelf wakker worden, maar\n"
	.string "als het gevecht stopt terwijl hij\l"
	.string "slaapt, blijft hij slapen.\p"
	.string "Maak hem wakker met een WEKKER.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Een brandwond maakt de AANVAL\n"
	.string "zwakker en kost steeds HP.\p"
	.string "De brandwond blijft na het gevecht.\n"
	.string "Geneesmiddel: BRANDZALF.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Een bevroren POKéMON kan helemaal\n"
	.string "niets meer.\p"
	.string "Hij blijft bevroren na het gevecht.\n"
	.string "Ontdooi hem met een ONTDOOIER.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Leerlingen die niet leren, krijgen\n"
	.string "een tikje van mijn SNELKLAUW.\p"
	.string "Of je een goede leerling bent,\n"
	.string "zie je aan hoe je dit voorwerp\l"
	.string "gebruikt.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Een POKéMON met een SNELKLAUW is\n"
	.string "soms extra snel en valt dan eerst\l"
	.string "aan.\p"
	.string "Er zijn nog veel meer voorwerpen\n"
	.string "om POKéMON te laten vasthouden.\p"
	.string "Daar kun je al heel veel over\n"
	.string "leren!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Ik ruil nu POKéMON met mijn\n"
	.string "vriend.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Ik wilde altijd al een SEEDOT, en\n"
	.string "nu krijg ik er eindelijk een!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON kunnen voorwerpen vasthouden,\n"
	.string "maar ze weten niet wat ze moeten\l"
	.string "met een DRANKJE of TEGENGIF.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Sommige aanvallen maken een POKéMON\n"
	.string "in de war, weet je?\p"
	.string "Een POKéMON die in de war is, valt\n"
	.string "soms zichzelf aan.\p"
	.string "Maar na het gevecht is hij\n"
	.string "weer normaal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Een POKéMON met een BES geneest\n"
	.string "zichzelf…\p"
	.string "Er zijn veel voorwerpen die\n"
	.string "POKéMON kunnen vasthouden…\p"
	.string "Pfoe, aantekeningen maken is\n"
	.string "best moeilijk…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Het is het schrift van deze leerling…\p"
	.string "POKéMON vang je met\n"
	.string "POKé BALLS.\p"
	.string "Een TRAINER mag maximaal zes\n"
	.string "POKéMON bij zich hebben.\p"
	.string "Een TRAINER vangt POKéMON, traint\n"
	.string "ze en vecht met ze.\p"
	.string "De taak van een TRAINER is om de\n"
	.string "sterke TRAINERS in de POKéMON GYMS\l"
	.string "te verslaan.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hallo? Hebben we elkaar niet al eens\n"
	.string "gezien? In PETALBURG CITY, denk ik.\p"
	.string "Ik zal me even voorstellen.\n"
	.string "Ik heet SCOTT.\p"
	.string "Ik reis overal heen, op zoek naar\n"
	.string "goede TRAINERS.\p"
	.string "Ik zoek vooral experts in\n"
	.string "POKéMON-gevechten.\p"
	.string "Wat kom jij doen op deze SCHOOL?\n"
	.string "Ben jij ook een TRAINER?\p"
	.string "Leer eerst een POKéMON de aanval\n"
	.string "SNIJDEN.\p"
	.string "Als ik het goed heb, heeft iemand in\n"
	.string "deze stad SNIJDEN.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Hoe goed de leerlingen hier zijn,\n"
	.string "weet ik niet. Maar talent is er wel.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: O, wat is dat?\p"
	.string "Dat is een STONE BADGE, toch?\n"
	.string "Dat is best knap, vind ik.\p"
	.string "Maar ik had je graag zien\n"
	.string "vechten.\p"
	.string "Aan een BADGE zie je niet zo goed\n"
	.string "wat voor TRAINER iemand is.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hallo? Hebben we elkaar niet al eens\n"
	.string "gezien? In PETALBURG CITY, denk ik.\p"
	.string "Ik zal me even voorstellen.\n"
	.string "Ik heet SCOTT.\p"
	.string "Ik reis overal heen, op zoek naar\n"
	.string "goede TRAINERS.\p"
	.string "Ik zoek vooral experts in\n"
	.string "POKéMON-gevechten.\p"
	.string "O, wat is dat?\n"
	.string "Dat is een STONE BADGE, toch?\p"
	.string "Dat is best knap voor een\n"
	.string "beginnende TRAINER zoals jij.\p"
	.string "Maar ik had je graag zien\n"
	.string "vechten.\p"
	.string "Aan een BADGE zie je niet zo goed\n"
	.string "wat voor TRAINER iemand is.$"

