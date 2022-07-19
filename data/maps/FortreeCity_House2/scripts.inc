FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM10, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM10
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM10
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Les humains… Les POKéMON…\p"
	.string "Leurs pouvoirs cachés se développent\n"
	.string "lorsqu’ils vivent en milieu naturel…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Laisse la vieille dame que je suis voir si\n"
	.string "ton pouvoir caché s’est éveillé…\p"
	.string "J’ai une pièce dans une main.\p"
	.string "Dans quelle main l’ai-je cachée?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Oui, c’est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Oui, c’est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Superbe!\n"
	.string "Ton pouvoir caché s’est réveillé!\p"
	.string "Tiens, prends ça et révèle le pouvoir\n"
	.string "caché de tes POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "PUISSANCE CACHEE est une capacité\n"
	.string "qui diffère selon les POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Non, dommage.\n"
	.string "Tu n’as pas fait le bon choix.$"

