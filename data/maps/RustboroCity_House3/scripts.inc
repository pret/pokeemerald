RustboroCity_House3_MapScripts:: @ 8216190
	.byte 0

RustboroCity_House3_EventScript_216191:: @ 8216191
	msgbox RustboroCity_House3_Text_2161B6, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_21619A:: @ 821619A
	msgbox RustboroCity_House3_Text_21622A, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_2161A3:: @ 82161A3
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox RustboroCity_House3_Text_2162AB, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_2161B6: @ 82161B6
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_21622A: @ 821622A
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

RustboroCity_House3_Text_2162AB: @ 82162AB
	.string "PEKACHU: Peka!$"

