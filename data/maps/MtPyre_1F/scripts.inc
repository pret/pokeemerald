MtPyre_1F_MapScripts:: @ 8230F3E
	.byte 0

MtPyre_1F_EventScript_230F3F:: @ 8230F3F
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_230F6E
	msgbox MtPyre_1F_Text_230F8A, MSGBOX_DEFAULT
	giveitem_std ITEM_CLEANSE_TAG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_230F6E:: @ 8230F6E
	msgbox MtPyre_1F_Text_231005, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_230F78:: @ 8230F78
	msgbox MtPyre_1F_Text_23104F, MSGBOX_NPC
	end

MtPyre_1F_EventScript_230F81:: @ 8230F81
	msgbox MtPyre_1F_Text_2310BA, MSGBOX_NPC
	end

MtPyre_1F_Text_230F8A: @ 8230F8A
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_231005: @ 8231005
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_23104F: @ 823104F
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_2310BA: @ 82310BA
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

