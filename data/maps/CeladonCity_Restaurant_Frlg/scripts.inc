CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "Hi!\p"
	.string "Sorry, but we're taking a break\n"
	.string "right now.$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "My POKéMON are weak, so I often\n"
	.string "have to go to the DRUGSTORE.$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "Psst! There's a basement under the\n"
	.string "GAME CORNER, I hear.$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
	.string "Munch…\p"
	.string "The man at that table lost it all\n"
	.string "at the slots.$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "Go ahead! Laugh!\n"
	.string "I'm flat-out busted!\p"
	.string "No more slots for me!\n"
	.string "I'm going straight!\p"
	.string "Here!\n"
	.string "I won't be needing this anymore!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "{PLAYER} received a COIN CASE\n"
	.string "from the man.$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "Make room for this!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
	.string "I always thought I was going to\n"
	.string "win it back…$"

