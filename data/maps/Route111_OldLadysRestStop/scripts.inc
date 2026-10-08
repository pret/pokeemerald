Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Och, och.\n"
	.string "Zijn je POKéMON niet doodmoe?\p"
	.string "Als je wilt, kun je hier uitrusten.\n"
	.string "Dat is een goed idee! Doe dat maar.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Zo is het.\n"
	.string "Neem je tijd en rust lekker uit!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Och, och.\n"
	.string "Zijn je POKéMON nog steeds moe?\p"
	.string "Rust hier nog even uit.\n"
	.string "Dat is een goed idee. Doe dat maar.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "O, zo?\n"
	.string "Je hoeft niet verlegen te zijn.$"

