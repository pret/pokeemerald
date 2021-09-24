MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
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
	.string "All sorts of beings wander the slopes\n"
	.string "of Mt. Pyre…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a Pokémon hold that\n"
	.string "Cleanse Tag.\p"
	.string "It will help ward off wild Pokémon.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed Pokémon?\p"
	.string "You must care for your Pokémon a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "Zigzagoon. I cherished it…$"

