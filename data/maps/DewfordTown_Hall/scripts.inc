DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applywaitmovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applywaitmovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Wat is nu hip? Nou, dat is toch\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ik kan me een leven zonder\n"
	.string "“{STR_VAR_1}” niet voorstellen!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Wat is nu hip? Nou, dat is toch\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Maar ik vind het een beetje saai.\p"
	.string "Ik moet iets nieuws zoeken.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Ik leer mijn POKéMON over\n"
	.string "“{STR_VAR_1}”,\l"
	.string "maar dat gaat niet zo goed.\p"
	.string "Het is een beetje te moeilijk.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ik leer nu alles over het hippe\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Klopt het dat er een sterke band\n"
	.string "is tussen “{STR_VAR_1}”\l"
	.string "en “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "O!\n"
	.string "Dan had ik dus gelijk!\p"
	.string "Ik ben weer een stapje hipper,\n"
	.string "joepie!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Wat?!\n"
	.string "Is dat zo?!\p"
	.string "Voor een oude man als ik is het\n"
	.string "niet makkelijk om bij te blijven!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Al dat gedoe over\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Is daar geen tv-show over?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Aan de overkant van de zee…\p"
	.string "Is “{STR_VAR_1}”\n"
	.string "daar nog populairder?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Ik spaar echte\n"
	.string "“{STR_VAR_1}”-\l"
	.string "spullen.\p"
	.string "Ik heb echte\n"
	.string "“{STR_VAR_1}”-POPPEN…\p"
	.string "Echte “{STR_VAR_1}”-\n"
	.string "kleren…\p"
	.string "En echte\n"
	.string "“{STR_VAR_1}”-\l"
	.string "prentenboeken.\p"
	.string "Hehe, ze zijn van mij!\n"
	.string "Jij krijgt er niks van!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "HERKEN GOEDE\n"
	.string "“{STR_VAR_1}” &\l"
	.string "SLECHTE “{STR_VAR_1}”…\p"
	.string "DE BAND TUSSEN\n"
	.string "“{STR_VAR_1}” EN\l"
	.string "POKéMON…\p"
	.string "HANDIGE\n"
	.string "“{STR_VAR_1}”…\p"
	.string "De kast zit vol boeken over\n"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "De titel is “DE SCHREEUW VAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "De titel is “DE GLIMLACH VAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "De titel is “DE LAATSTE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "De titel is “DE GEBOORTE VAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Ik heb “{STR_VAR_1}” gezien!\n"
	.string "Cool, hè?\p"
	.string "Het is echt het coolste wat er is!\p"
	.string "Het was geweldig!\n"
	.string "Het was echt, o ja!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "O nee, nee, nee.\p"
	.string "Dat zogenaamde\n"
	.string "“{STR_VAR_1}”\l"
	.string "dat jij zag, dat was nep.\p"
	.string "Het echte is veel…\n"
	.string "Hoe zeg ik dat?\l"
	.string "Scherper, maar toch zachter!\p"
	.string "Ach, maakt niet uit. Het is geweldig!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hé, luister, ik heb een lied gemaakt\n"
	.string "over “{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}”\n"
	.string "is nu echt heel populair.\p"
	.string "Oké, luister!\n"
	.string "… …\p"
	.string "O!\n"
	.string "{STR_VAR_1}!\p"
	.string "Prachtig\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Beste vriend, ik zou eerst wat\n"
	.string "beter leren zingen voor je\l"
	.string "gaat zingen over\l"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Zoals ik al zei: we moeten samen\n"
	.string "een feest geven over\l"
	.string "“{STR_VAR_1}”\l"
	.string "hier op het eiland.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "O, wat een goed idee!\p"
	.string "Dan weten we eindelijk wie\n"
	.string "de beste is in\l"
	.string "“{STR_VAR_1}”.\l"
	.string "Geweldig, echt!\p"
	.string "Vanaf vandaag draait ons leven\n"
	.string "om “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Ik zat te denken…\p"
	.string "Vind jij ook niet dat\n"
	.string "“{STR_VAR_1}”\l"
	.string "niet meer zomaar hip is, maar\l"
	.string "een deel van ons leven?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Pardon?\n"
	.string "Zo erg, zeg je?\p"
	.string "Maar het klopt wel dat je altijd\n"
	.string "aan “{STR_VAR_1}”\l"
	.string "denkt, of je nu wakker\l"
	.string "bent of slaapt.\p"
	.string "Jij bent echt de\n"
	.string "“{STR_VAR_1}”-\l"
	.string "PROFESSOR, beste vriend!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Als jij en ik een team worden,\n"
	.string "verslaat niemand ons in alles\l"
	.string "over “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Helemaal goed, vriend!\p"
	.string "Wij worden het\n"
	.string "“{STR_VAR_1}”-DUO!\p"
	.string "Is dat geen mooi idee?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Voor mij is SLIJKBOM het\n"
	.string "allerhipst. Dat is 'm.\p"
	.string "Huh? Zeg je nou dat je SLIJKBOM\n"
	.string "niet kent?\p"
	.string "Dat is echt zielig.\n"
	.string "Ik geef je er een.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Ik hou van SLIJKBOM.\p"
	.string "Maar POKéMON met de aanval\n"
	.string "“{STR_VAR_1}”\l"
	.string "zijn ook hip.$"

