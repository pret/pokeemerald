SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Ahem! Ik ben de VOORZITTER van de\n"
	.string "POKéMON FAN CLUB!\p"
	.string "Als VOORZITTER ben ik natuurlijk\n"
	.string "de belangrijkste!\p"
	.string "Niemand traint POKéMON beter\n"
	.string "dan ik. Niemand!\p"
	.string "Laat me je vertellen over\n"
	.string "POKéMON CONTESTS.\p"
	.string "Daar laat je je POKéMON zien\n"
	.string "aan de hele wereld!\p"
	.string "Maar ze zijn in verre steden,\n"
	.string "dus ik kan er niet vaak heen.\p"
	.string "Daarom komen we hier samen.\n"
	.string "We laten onze POKéMON zien en\l"
	.string "kijken naar die van anderen.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "De POKéMON van een TRAINER die\n"
	.string "meedeed aan een POKéMON CONTEST…\l"
	.string "Die zou ik graag zien.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Ahem! Ik zie dat jij hebt meegedaan\n"
	.string "aan een POKéMON CONTEST!\p"
	.string "Alsjeblieft! Laat me zien hoe jij\n"
	.string "je POKéMON hebt getraind.\p"
	.string "Ik vind het heerlijk om POKéMON\n"
	.string "van andere TRAINERS te zien.\p"
	.string "De blije snoetjes van POKéMON\n"
	.string "die goed verzorgd zijn…\p"
	.string "De lieve ogen van de TRAINER\n"
	.string "die voor de POKéMON zorgde…\p"
	.string "Als ik daaraan denk, ben ik\n"
	.string "zo blij dat ik bijna ontplof.\p"
	.string "O! Neem me niet kwalijk!\n"
	.string "Ik praat veel te veel!\p"
	.string "Alsjeblieft! Laat me zien hoe goed\n"
	.string "je POKéMON is gegroeid!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Hoe gaat het met je POKéMON?\n"
	.string "Laat me eens kijken.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm…\n"
	.string "Ik zie het…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Niet slecht, maar ook\n"
	.string "niet goed…\p"
	.string "Jij, de TRAINER, moet beter je\n"
	.string "best doen met deze POKéMON!\p"
	.string "Geef hem bijvoorbeeld\n"
	.string "meer {POKEBLOCK}S!$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "O jee…\p"
	.string "Je POKéMON groeit heel goed,\n"
	.string "dus je verdient een beloning.\p"
	.string "Maar helaas heb je geen plek\n"
	.string "meer in je TAS.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Jouw {STR_VAR_1} groeit echt\n"
	.string "indrukwekkend goed!\l"
	.string "Wat een prachtig exemplaar!\p"
	.string "Maar! Als je hem dit geeft,\n"
	.string "groeit hij nog beter! Echt waar!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Laat een POKéMON die RODE SJAAL\n"
	.string "vasthouden.\p"
	.string "Iedereen ziet dan hoe stoer\n"
	.string "die POKéMON is!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Laat een POKéMON die BLAUWE SJAAL\n"
	.string "vasthouden.\p"
	.string "Dan wordt hij nog veel\n"
	.string "mooier dan nu!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Laat een POKéMON die ROZE SJAAL\n"
	.string "vasthouden.\p"
	.string "Dan wordt die POKéMON nog\n"
	.string "schattiger!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Laat een POKéMON die GROENE SJAAL\n"
	.string "vasthouden.\p"
	.string "Dan lijkt je POKéMON nog\n"
	.string "slimmer!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Laat een POKéMON die GELE SJAAL\n"
	.string "vasthouden.\p"
	.string "Dan lijkt je POKéMON nog\n"
	.string "veel sterker!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Sorry, maar ik heb niks meer\n"
	.string "voor je! Helemaal niks!\p"
	.string "Jij kunt POKéMON zo goed\n"
	.string "trainen, dat je geen\l"
	.string "voorwerpen nodig hebt!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Ik zie graag POKéMON die van\n"
	.string "hun TRAINER houden.\p"
	.string "POKéMON voelen heel goed wat\n"
	.string "hun TRAINER voelt.\p"
	.string "Als je lief en goed voor je POKéMON\n"
	.string "bent, houden ze ook van jou.\p"
	.string "Als je POKéMON echt van je houdt,\n"
	.string "kom het me dan laten zien.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Je POKéMON is echt dol op jou.\p"
	.string "Voor jou, zo'n lieve TRAINER,\n"
	.string "een cadeau van de FAN CLUB!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "POKéMON voelen heel goed wat\n"
	.string "hun TRAINER voelt.\p"
	.string "Als je lief en goed voor je POKéMON\n"
	.string "bent, houden ze ook van jou.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Als je POKéMON steeds verslagen\n"
	.string "raakt, wordt hij daar boos om.\p"
	.string "Dan vertrouwt hij zijn TRAINER\n"
	.string "steeds minder.\p"
	.string "Met andere woorden: hij vindt\n"
	.string "jou dan echt niet zo leuk.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Vinden POKéMON het fijn als je\n"
	.string "voorwerpen op ze gebruikt?\p"
	.string "De mijne was heel blij toen ik\n"
	.string "hem wat PROTEÏNE gaf.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Marimari?$"

