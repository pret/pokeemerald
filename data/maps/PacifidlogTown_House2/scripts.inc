PacifidlogTown_House2_MapScripts:: @ 8203791
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother:: @ 8203792
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 2
	goto_if_ge PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag:: @ 82037DE
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	compare VAR_RESULT, 0
	call_if_eq PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment:: @ 82037F8
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment:: @ 8203801
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM:: @ 8203812
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn:: @ 8203816
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort:: @ 8203845
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration:: @ 820384F
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays:: @ 820387E
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring 0, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill:: @ 8203891
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill:: @ 82038AC
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 2
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation: @ 82038C7
	.string "Er-hem!\p"
	.string "I am the POKéMON FAN CLUB's most\n"
	.string "important person, the CHAIRMAN's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "POKéMON, yes, indeed.$"

PacifidlogTown_House2_Text_AhYourPokemon: @ 820395B
	.string "Ah!\n"
	.string "Your POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis: @ 820396D
	.string "It clearly likes you very much.\p"
	.string "A POKéMON that adoring and adorable\n"
	.string "deserves a TM like this, no?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort: @ 82039CE
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the TRAINER, need to put in\n"
	.string "some more effort.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis: @ 8203A2F
	.string "It has a vicious look to it.\p"
	.string "A frightening POKéMON like that\n"
	.string "deserves a TM like this.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration: @ 8203A85
	.string "If a POKéMON likes you a lot, RETURN's\n"
	.string "power is enhanced.\p"
	.string "If it doesn't like you, FRUSTRATION's\n"
	.string "power goes up.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays: @ 8203AF4
	.string "Oh, yes. In about {STR_VAR_1} or so days,\n"
	.string "I should be getting a good TM or two.\p"
	.string "You should come see me then.\n"
	.string "I'll give you a TM that's suitable for\l"
	.string "your POKéMON.$"

PacifidlogTown_House2_Text_Rurii: @ 8203B8D
	.string "AZURILL: Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer: @ 8203B9D
	.string "It appears to be very friendly with the\n"
	.string "TRAINER.$"

PacifidlogTown_House2_Text_Rururi: @ 8203BCE
	.string "AZURILL: Rururi!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch: @ 8203BDF
	.string "It doesn't appear to like the TRAINER\n"
	.string "very much.$"

