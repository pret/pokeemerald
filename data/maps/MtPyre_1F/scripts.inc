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
	.string "Toutes sortes d’êtres se promènent sur\n"
	.string "les versants du MONT MEMORIA…\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Prends ça. C’est pour ton bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fais tenir cette RUNE PURIF. à l’un\n"
	.string "de tes POKéMON.\p"
	.string "Ça éloignera les POKéMON sauvages.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Es-tu là pour présenter tes respects\n"
	.string "aux esprits des défunts POKéMON?\p"
	.string "Tu dois prendre grand soin de tes\n"
	.string "POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "C’est ici que repose mon ZIGZATON.\n"
	.string "C’est un endroit que je chéris…$"

