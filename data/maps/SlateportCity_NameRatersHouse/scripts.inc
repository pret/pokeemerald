SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hoi, hoi! Ik ben de NAME RATER!\n"
	.string "Ik ben de waarzegger van namen!\p"
	.string "Ik geef graag een cijfer voor de\n"
	.string "bijnaam van je POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Van welke POKéMON zal ik de\n"
	.string "bijnaam beoordelen?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, zei je? Dat is\n"
	.string "een heel mooie naam.\p"
	.string "Maar! Wat zeg je ervan als ik een\n"
	.string "nog iets betere naam bedenk?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, mooi. Wat wordt de nieuwe\n"
	.string "bijnaam?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Klaar! Vanaf nu heet deze POKéMON\n"
	.string "{STR_VAR_1}!\p"
	.string "Dat is een betere naam dan eerst!\n"
	.string "Wat een geluk voor jou!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ik snap het.\n"
	.string "Kom gerust nog eens langs.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Klaar! Vanaf nu heet deze POKéMON\n"
	.string "{STR_VAR_1}!\p"
	.string "Het lijkt hetzelfde als eerst,\n"
	.string "maar het is veel beter!\p"
	.string "Wat een geluk voor jou!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} dus!\p"
	.string "Dat is een prachtige bijnaam!\n"
	.string "Daar is niks op aan te merken!\p"
	.string "Zorg goed voor je {STR_VAR_1},\n"
	.string "nu en altijd.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Nou, nou.\n"
	.string "Dat is maar een EI!$"

