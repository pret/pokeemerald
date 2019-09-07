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
	.string "And your well-trained Pokémon…\p"
	.string "You're obviously a skilled Trainer!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "Hidden Machine to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_215D33: @ 8215D33
	.string "That Hidden Machine, or HM for\n"
	.string "short, is Cut.\p"
	.string "An HM move is one that can be used\n"
	.string "by Pokémon outside of battle.\p"
	.string "Any Pokémon that's learned Cut can\n"
	.string "chop down thin trees if the Trainer\l"
	.string "has earned the Stone Badge.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_215E39: @ 8215E39
	.string "When they were expanding the city of\n"
	.string "Rustboro, my dad helped out.\p"
	.string "He made his Pokémon use Cut to clear\n"
	.string "the land of trees.$"

