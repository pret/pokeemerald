MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Allerlei wezens zwerven over de\n"
	.string "hellingen van MT. PYRE…\p"
	.string "Je weet niet wat er kan gebeuren.\n"
	.string "Neem dit. Het is voor je eigen bestwil.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Laat een POKéMON dat\n"
	.string "AFWEERLABEL vasthouden.\p"
	.string "Het helpt wilde POKéMON af te weren.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Kwam je eer bewijzen aan de\n"
	.string "geesten van overleden POKéMON?\p"
	.string "Je geeft vast veel om je POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Hier rust mijn ZIGZAGOON voor\n"
	.string "altijd. Ik hield veel van hem…$"

