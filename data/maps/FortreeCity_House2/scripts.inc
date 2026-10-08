FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
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
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
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
	.string "Mensen… POKéMON…\p"
	.string "Hun verborgen krachten ontwaken\n"
	.string "in de natuur…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Laat deze oude vrouw zien of jouw\n"
	.string "verborgen kracht wakker is…\p"
	.string "Ik hou een munt in mijn hand.\p"
	.string "Zeg me, zit hij in\n"
	.string "mijn rechterhand of linkerhand?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Ja, goed!\p"
	.string "We proberen het nog eens.\p"
	.string "In welke hand zit de munt?\n"
	.string "Links of rechts?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Ja, goed!\p"
	.string "We proberen het nog eens.\p"
	.string "In welke hand zit de munt?\n"
	.string "Links of rechts?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Prachtig!\n"
	.string "Je verborgen kracht is wakker!\p"
	.string "Hier, neem dit en wek de verborgen\n"
	.string "kracht van je POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "BINNENKRACHT is een aanval die\n"
	.string "verandert per POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Nee, jammer.\n"
	.string "Je raadde fout.$"

