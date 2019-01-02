BattleFrontier_Lounge2_MapScripts:: @ 8260642
	.byte 0

BattleFrontier_Lounge2_EventScript_260643:: @ 8260643
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_26065F
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_260766, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26065F:: @ 826065F
	msgbox BattleFrontier_Lounge2_Text_260857, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26066D:: @ 826066D
	compare VAR_FRONTIER_MANIAC_FACILITY, 0
	call_if_eq BattleFrontier_Lounge2_EventScript_26070A
	compare VAR_FRONTIER_MANIAC_FACILITY, 1
	call_if_eq BattleFrontier_Lounge2_EventScript_26070F
	compare VAR_FRONTIER_MANIAC_FACILITY, 2
	call_if_eq BattleFrontier_Lounge2_EventScript_260714
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_eq BattleFrontier_Lounge2_EventScript_260719
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_eq BattleFrontier_Lounge2_EventScript_26071E
	compare VAR_FRONTIER_MANIAC_FACILITY, 5
	call_if_eq BattleFrontier_Lounge2_EventScript_260723
	compare VAR_FRONTIER_MANIAC_FACILITY, 6
	call_if_eq BattleFrontier_Lounge2_EventScript_260728
	compare VAR_FRONTIER_MANIAC_FACILITY, 7
	call_if_eq BattleFrontier_Lounge2_EventScript_26072D
	compare VAR_FRONTIER_MANIAC_FACILITY, 8
	call_if_eq BattleFrontier_Lounge2_EventScript_260732
	compare VAR_FRONTIER_MANIAC_FACILITY, 9
	call_if_eq BattleFrontier_Lounge2_EventScript_260737
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_le BattleFrontier_Lounge2_EventScript_2606F8
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_ge BattleFrontier_Lounge2_EventScript_260701
	special sub_8139F20
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_2606F8:: @ 82606F8
	msgbox BattleFrontier_Lounge2_Text_260933, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_260701:: @ 8260701
	msgbox BattleFrontier_Lounge2_Text_2608F2, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_26070A:: @ 826070A
	bufferstdstring 0, 19
	return

BattleFrontier_Lounge2_EventScript_26070F:: @ 826070F
	bufferstdstring 0, 20
	return

BattleFrontier_Lounge2_EventScript_260714:: @ 8260714
	bufferstdstring 0, 21
	return

BattleFrontier_Lounge2_EventScript_260719:: @ 8260719
	bufferstdstring 0, 22
	return

BattleFrontier_Lounge2_EventScript_26071E:: @ 826071E
	bufferstdstring 0, 24
	return

BattleFrontier_Lounge2_EventScript_260723:: @ 8260723
	bufferstdstring 0, 25
	return

BattleFrontier_Lounge2_EventScript_260728:: @ 8260728
	bufferstdstring 0, 26
	return

BattleFrontier_Lounge2_EventScript_26072D:: @ 826072D
	bufferstdstring 0, 27
	return

BattleFrontier_Lounge2_EventScript_260732:: @ 8260732
	bufferstdstring 0, 28
	return

BattleFrontier_Lounge2_EventScript_260737:: @ 8260737
	bufferstdstring 0, 29
	return

BattleFrontier_Lounge2_EventScript_26073C:: @ 826073C
	lock
	msgbox BattleFrontier_Lounge2_Text_261C9C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_260747:: @ 8260747
	lock
	msgbox BattleFrontier_Lounge2_Text_261CDC, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_260752:: @ 8260752
	lock
	msgbox BattleFrontier_Lounge2_Text_261D1D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_26075D:: @ 826075D
	msgbox BattleFrontier_Lounge2_Text_261D5C, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_260766:: @ 8260766
	.string "Howdy! When it comes to news about\n"
	.string "the BATTLE FRONTIER, I'm no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER MANIAC.\p"
	.string "Just checking, but you are a TRAINER,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_260857:: @ 8260857
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"

BattleFrontier_Lounge2_Text_2608A1:: @ 82608A1
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_2608F2:: @ 82608F2
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_260933:: @ 8260933
	.string "Let's see now…\p"
	.string "It sounds like BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest.$"

BattleFrontier_Lounge2_Text_260971:: @ 8260971
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this mysterious TRAINER called\n"
	.string "the SALON MAIDEN that runs the place.$"

BattleFrontier_Lounge2_Text_260A1E:: @ 8260A1E
	.string "Have you battled the SALON MAIDEN?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A PSYCHIC-type PSI POKéMON,\n"
	.string "a FIRE-type VOLCANO POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_260AE7:: @ 8260AE7
	.string "Have you battled the SALON MAIDEN\n"
	.string "when she's serious?\p"
	.string "When she's battling flat out,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A DRAGON & PSYCHIC EON POKéMON,\n"
	.string "an ELECTRIC-type THUNDER POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_260BC4:: @ 8260BC4
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this flamboyant TRAINER called\n"
	.string "the DOME ACE that runs the place.$"

BattleFrontier_Lounge2_Text_260C6D:: @ 8260C6D
	.string "Have you battled the DOME ACE?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a FIRE & FLYING FLAME POKéMON.$"

BattleFrontier_Lounge2_Text_260D3A:: @ 8260D3A
	.string "Have you battled the DOME ACE\n"
	.string "when he's serious?\p"
	.string "When he's demonstrating his strategy,\n"
	.string "he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING EON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a STEEL- & PSYCHIC-type IRON LEG\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_260E1E:: @ 8260E1E
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this freaky TRAINER called\n"
	.string "the FACTORY HEAD that runs the place.$"

BattleFrontier_Lounge2_Text_260EC7:: @ 8260EC7
	.string "Have you battled the FACTORY HEAD\n"
	.string "already?\p"
	.string "Let me think… When he goes to battle,\n"
	.string "he just gets three rental POKéMON.\p"
	.string "He battles under pretty much the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_260F74:: @ 8260F74
	.string "Have you battled the FACTORY HEAD\n"
	.string "when he's serious?\p"
	.string "When he goes seriously to battle,\n"
	.string "he still gets three rental POKéMON.\p"
	.string "He battles under virtually the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_261026:: @ 8261026
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this scary TRAINER called\n"
	.string "the PIKE QUEEN that runs the place.$"

BattleFrontier_Lounge2_Text_2610CC:: @ 82610CC
	.string "Have you battled the PIKE QUEEN\n"
	.string "before?\p"
	.string "When she's in a good mood, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a BUG & ROCK MOLD POKéMON,\l"
	.string "and a WATER-type TENDER POKéMON.$"

BattleFrontier_Lounge2_Text_261194:: @ 8261194
	.string "Have you battled the PIKE QUEEN\n"
	.string "when she's serious?\p"
	.string "When she's seriously annoyed, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a STEEL & GROUND IRON SNAKE POKéMON,\l"
	.string "and a WATER- & FLYING-type ATROCIOUS\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_261282:: @ 8261282
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this cute TRAINER called\n"
	.string "the ARENA TYCOON that runs the place.$"

BattleFrontier_Lounge2_Text_261329:: @ 8261329
	.string "Have you battled the ARENA TYCOON\n"
	.string "before?\p"
	.string "When she's assessing the foe's ability,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A BUG & FIGHTING SINGLE HORN POKéMON,\n"
	.string "a DARK-type MOONLIGHT POKéMON,\l"
	.string "and a BUG & GHOST SHED POKéMON.$"

BattleFrontier_Lounge2_Text_261403:: @ 8261403
	.string "Have you battled the ARENA TYCOON\n"
	.string "when she's serious?\p"
	.string "When she battles for keeps,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A DARK-type MOONLIGHT POKéMON,\n"
	.string "a GHOST & POISON SHADOW POKéMON\l"
	.string "and a GRASS- & FIGHTING-type\l"
	.string "MUSHROOM POKéMON.$"

BattleFrontier_Lounge2_Text_2614E6:: @ 82614E6
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this sinister TRAINER called\n"
	.string "the PALACE MAVEN that runs the place.$"

BattleFrontier_Lounge2_Text_261591:: @ 8261591
	.string "Have you battled the PALACE MAVEN\n"
	.string "before?\p"
	.string "When he's testing the opponent's\n"
	.string "spirit, he's said to use these POKéMON:\p"
	.string "A POISON & FLYING-type BAT POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON, and a\l"
	.string "WATER- & ICE-type TRANSPORT POKéMON.$"

BattleFrontier_Lounge2_Text_26166F:: @ 826166F
	.string "Have you battled the PALACE MAVEN\n"
	.string "when he's serious?\p"
	.string "When he throws his entire might into\n"
	.string "battle, he's said to use these POKéMON:\p"
	.string "A FIRE-type LEGENDARY POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON,\l"
	.string "and a WATER-type AURORA POKéMON.$"

BattleFrontier_Lounge2_Text_26174D:: @ 826174D
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this fiery-hot TRAINER called\n"
	.string "the PYRAMID KING that runs the place.$"

BattleFrontier_Lounge2_Text_2617F9:: @ 82617F9
	.string "Have you battled the PYRAMID KING\n"
	.string "before?\p"
	.string "When he's checking the foe's power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "A ROCK-type ROCK PEAK POKéMON,\n"
	.string "an ICE-type ICEBERG POKéMON,\l"
	.string "and a STEEL-type IRON POKéMON.$"

BattleFrontier_Lounge2_Text_2618C4:: @ 82618C4
	.string "Have you battled the PYRAMID KING\n"
	.string "when he's serious?\p"
	.string "When he's pumped with hot power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "An ICE & FLYING FREEZE POKéMON, an\n"
	.string "ELECTRIC & FLYING ELECTRIC POKéMON,\l"
	.string "and a FIRE- & FLYING-type FLAME\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_2619AC:: @ 82619AC
	.string "Sure, there are several places where\n"
	.string "you can enter DOUBLE BATTLES.\p"
	.string "But the DOUBLE BATTLE ROOMS of\n"
	.string "the BATTLE TOWER are, like, basic!\p"
	.string "They're where you should learn about\n"
	.string "how DOUBLE BATTLES are played here\l"
	.string "in the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_261A91:: @ 8261A91
	.string "Watch yourself in the battles here.\p"
	.string "I hear there are TRAINERS that have\n"
	.string "strategies they developed just for\l"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_261B0C:: @ 8261B0C
	.string "Once you're confident and comfortable\n"
	.string "with DOUBLE BATTLES here, you should\l"
	.string "think about challenging other places\l"
	.string "offering DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_261B95:: @ 8261B95
	.string "All sorts of TRAINERS gather in\n"
	.string "the BATTLE SALON.\p"
	.string "Just think--you may run into your\n"
	.string "friends or followers!\l"
	.string "You should look carefully!$"

BattleFrontier_Lounge2_Text_261C1A:: @ 8261C1A
	.string "If you're with a friend, head for the\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "If you play with a strong friend,\n"
	.string "you can expect to see tough foes!$"

BattleFrontier_Lounge2_Text_261C9C:: @ 8261C9C
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_261CDC:: @ 8261CDC
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_261D1D:: @ 8261D1D
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_261D5C:: @ 8261D5C
	.string "…What is this place?\n"
	.string "It's scaring me…$"

