PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 2, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Hum-hum!\p"
	.string "Je suis la personne la plus influente\n"
	.string "du FAN CLUB POKéMON. Je suis\l"
	.string "le petit frère du PRESIDENT.\p"
	.string "Je suis ici en vacances, avec mes\n"
	.string "POKéMON, bien entendu.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah!\n"
	.string "Ton POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Il t’aime énormément, pas de doute.\p"
	.string "Un POKéMON aussi adorable et adoré\n"
	.string "mérite bien une CT comme ça, non?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm… Ce n’est pas mal, mais ce n’est\n"
	.string "pas génial non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu dois faire\n"
	.string "plus d’efforts.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Il a un regard mauvais.\p"
	.string "Un POKéMON aussi effrayant mérite\n"
	.string "une CT comme ça.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Lorsqu’un POKéMON t’aime beaucoup,\n"
	.string "la puissance de RETOUR est augmentée.\p"
	.string "S’il ne t’aime pas, la puissance de\n"
	.string "FRUSTRATION est augmentée.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Je devrais bientôt recevoir une ou deux\n"
	.string "bonnes CT. Tu veux savoir dans combien\l"
	.string "de jours? {STR_VAR_1}, je pense…\p"
	.string "Reviens me voir à ce moment-là.\n"
	.string "Je te donnerai une CT qui correspond\l"
	.string "à ton POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Uriii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Il a l’air d’être très ami avec le\n"
	.string "DRESSEUR.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Uuuurill!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Il n’a pas l’air d’aimer beaucoup le\n"
	.string "DRESSEUR.$"

