RustboroCity_CuttersHouse_MapScripts:: @ 8215BD3
	.byte 0

RustboroCity_CuttersHouse_EventScript_215BD4:: @ 8215BD4
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_215C00
	msgbox RustboroCity_CuttersHouse_Text_215C13, MSGBOX_DEFAULT
	giveitem_std ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox RustboroCity_CuttersHouse_Text_215D33, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_215C00:: @ 8215C00
	msgbox RustboroCity_CuttersHouse_Text_215D33, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_215C0A:: @ 8215C0A
	msgbox RustboroCity_CuttersHouse_Text_215E39, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_215C13: @ 8215C13
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_215D33: @ 8215D33
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_215E39: @ 8215E39
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"

