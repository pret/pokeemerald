DewfordTown_Hall_MapScripts:: @ 81FD4CF
	.byte 0

DewfordTown_Hall_EventScript_1FD4D0:: @ 81FD4D0
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	special TrendyPhraseIsOld
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD4EF
	msgbox DewfordTown_Hall_Text_1FD818, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD4EF:: @ 81FD4EF
	msgbox DewfordTown_Hall_Text_1FD877, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD4F9:: @ 81FD4F9
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FD8ED, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD50A:: @ 81FD50A
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	special sub_811EF6C
	msgbox DewfordTown_Hall_Text_1FD948, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD533
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD53D
	end

DewfordTown_Hall_EventScript_1FD533:: @ 81FD533
	msgbox DewfordTown_Hall_Text_1FD9B3, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD53D:: @ 81FD53D
	msgbox DewfordTown_Hall_Text_1FDA06, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD547:: @ 81FD547
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDA5C, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_1FD563:: @ 81FD563
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDA99, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_1FD57F:: @ 81FD57F
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDAC4, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD590:: @ 81FD590
	lockall
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDB89, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD5A0:: @ 81FD5A0
	lockall
	call DewfordTown_Hall_EventScript_271E8B
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_1FD607
	case 4, DewfordTown_Hall_EventScript_1FD607
	case 1, DewfordTown_Hall_EventScript_1FD611
	case 5, DewfordTown_Hall_EventScript_1FD607
	case 2, DewfordTown_Hall_EventScript_1FD61B
	case 6, DewfordTown_Hall_EventScript_1FD61B
	case 3, DewfordTown_Hall_EventScript_1FD625
	case 7, DewfordTown_Hall_EventScript_1FD61B
	end

DewfordTown_Hall_EventScript_1FD607:: @ 81FD607
	msgbox DewfordTown_Hall_Text_1FDC05, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD611:: @ 81FD611
	msgbox DewfordTown_Hall_Text_1FDC21, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD61B:: @ 81FD61B
	msgbox DewfordTown_Hall_Text_1FDC3C, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD625:: @ 81FD625
	msgbox DewfordTown_Hall_Text_1FDC57, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD62F:: @ 81FD62F
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_1FD647
	end

DewfordTown_Hall_EventScript_1FD63B:: @ 81FD63B
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_1FD647
	end

DewfordTown_Hall_EventScript_1FD647:: @ 81FD647
	call DewfordTown_Hall_EventScript_271E8B
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_1FD6AD
	case 1, DewfordTown_Hall_EventScript_1FD6AD
	case 2, DewfordTown_Hall_EventScript_1FD6C9
	case 3, DewfordTown_Hall_EventScript_1FD6C9
	case 4, DewfordTown_Hall_EventScript_1FD6E5
	case 5, DewfordTown_Hall_EventScript_1FD6E5
	case 6, DewfordTown_Hall_EventScript_1FD701
	case 7, DewfordTown_Hall_EventScript_1FD71D
	end

DewfordTown_Hall_EventScript_1FD6AD:: @ 81FD6AD
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDC76, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDCE2, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD6C9:: @ 81FD6C9
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDD95, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDE0E, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD6E5:: @ 81FD6E5
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDE77, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDED8, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD701:: @ 81FD701
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDF72, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDFF1, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD71D:: @ 81FD71D
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FE09A, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FE0F2, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD739:: @ 81FD739
	return

DewfordTown_Hall_EventScript_1FD73A:: @ 81FD73A
	applymovement 8, DewfordTown_Hall_Movement_1FD7D6
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD75B
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD771
	end

DewfordTown_Hall_EventScript_1FD75B:: @ 81FD75B
	compare VAR_FACING, 4
	goto_if_eq DewfordTown_Hall_EventScript_1FD739
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD771:: @ 81FD771
	return

DewfordTown_Hall_EventScript_1FD772:: @ 81FD772
	applymovement 7, DewfordTown_Hall_Movement_1FD7D8
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD793
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD7C0
	end

DewfordTown_Hall_EventScript_1FD793:: @ 81FD793
	compare VAR_FACING, 2
	call_if_eq DewfordTown_Hall_EventScript_1FD7AA
	compare VAR_FACING, 1
	call_if_eq DewfordTown_Hall_EventScript_1FD7B5
	return

DewfordTown_Hall_EventScript_1FD7AA:: @ 81FD7AA
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD7B5:: @ 81FD7B5
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD7C0:: @ 81FD7C0
	compare VAR_FACING, 3
	goto_if_eq DewfordTown_Hall_EventScript_1FD739
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_1FD7D6: @ 81FD7D6
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_1FD7D8: @ 81FD7D8
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_1FD7DA:: @ 81FD7DA
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_1FD80E
	msgbox DewfordTown_Hall_Text_1FE142, MSGBOX_DEFAULT
	giveitem_std ITEM_TM36
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_1FD80E:: @ 81FD80E
	msgbox DewfordTown_Hall_Text_1FE1ED, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_1FD818: @ 81FD818
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "I can't imagine what life would be like\n"
	.string "without “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FD877: @ 81FD877
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "But I'm getting kind of bored with it.\p"
	.string "I should look for the next big thing.$"

DewfordTown_Hall_Text_1FD8ED: @ 81FD8ED
	.string "I'm teaching my POKéMON about\n"
	.string "“{STR_VAR_1},”\l"
	.string "but it's not going well.\p"
	.string "It's a bit too much, I think.$"

DewfordTown_Hall_Text_1FD948: @ 81FD948
	.string "I'm studying up on the hip and trendy\n"
	.string "“{STR_VAR_1}” now.\p"
	.string "Is it true that there's a deep link\n"
	.string "between “{STR_VAR_1}”\l"
	.string "and “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_1FD9B3: @ 81FD9B3
	.string "Oh!\n"
	.string "So, my hunch was right!\p"
	.string "I'm one step closer to being hip and\n"
	.string "happening, yowza!$"

DewfordTown_Hall_Text_1FDA06: @ 81FDA06
	.string "What?!\n"
	.string "Is that so?!\p"
	.string "It's not easy for an older fellow like\n"
	.string "me to keep up with trends!$"

DewfordTown_Hall_Text_1FDA5C: @ 81FDA5C
	.string "This whole business about\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Isn't there a TV show on it?$"

DewfordTown_Hall_Text_1FDA99: @ 81FDA99
	.string "Across the sea…\p"
	.string "Is “{STR_VAR_1}”\n"
	.string "even more popular?$"

DewfordTown_Hall_Text_1FDAC4: @ 81FDAC4
	.string "I collect official\n"
	.string "“{STR_VAR_1}”\l"
	.string "licensed merchandise.\p"
	.string "I have official\n"
	.string "“{STR_VAR_1}” DOLLS…\p"
	.string "Official “{STR_VAR_1}”\n"
	.string "brand clothing…\p"
	.string "And officially licensed\n"
	.string "“{STR_VAR_1}”\l"
	.string "picture books.\p"
	.string "Heheh, I own!\n"
	.string "I'm not sharing anything with you!$"

DewfordTown_Hall_Text_1FDB89: @ 81FDB89
	.string "IDENTIFYING GOOD\n"
	.string "“{STR_VAR_1}” &\l"
	.string "BAD “{STR_VAR_1}”…\p"
	.string "THE LINK BETWEEN\n"
	.string "“{STR_VAR_1}” AND\l"
	.string "POKéMON…\p"
	.string "USEFUL\n"
	.string "“{STR_VAR_1}”…\p"
	.string "It's neatly jammed with books about\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_1FDC05: @ 81FDC05
	.string "“{STR_VAR_1}'S\n"
	.string "SCREAM” is the title.$"

DewfordTown_Hall_Text_1FDC21: @ 81FDC21
	.string "“{STR_VAR_1}'S\n"
	.string "SMILE” is the title.$"

DewfordTown_Hall_Text_1FDC3C: @ 81FDC3C
	.string "It's titled “THE LAST\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC57: @ 81FDC57
	.string "It's titled “THE BIRTH OF\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC76: @ 81FDC76
	.string "I saw “{STR_VAR_1}”!\n"
	.string "Cool, huh?\p"
	.string "It's, like, the coolest thing going!\p"
	.string "It was awesome!\n"
	.string "It was the real thing, oh yeah!$"

DewfordTown_Hall_Text_1FDCE2: @ 81FDCE2
	.string "Oh, no, no, no.\p"
	.string "That alleged\n"
	.string "“{STR_VAR_1}”\l"
	.string "you claim to have seen--it's not.\p"
	.string "The authentic article is much…\n"
	.string "How should I say it?\l"
	.string "Sharper, yet more mellow!\p"
	.string "Ah, no matter. It's astonishing!$"

DewfordTown_Hall_Text_1FDD95: @ 81FDD95
	.string "Hey, listen, I composed a theme song\n"
	.string "for “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "is really popular right now.\p"
	.string "Okay, listen!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Wonderful\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_1FDE0E: @ 81FDE0E
	.string "… …\p"
	.string "I dare say, chap, it would pay for you\n"
	.string "to work on your singing before you\l"
	.string "trifle yourself with\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_1FDE77: @ 81FDE77
	.string "Anyway, as I was saying earlier, we\n"
	.string "should get together and organize a\l"
	.string "“{STR_VAR_1}” party\l"
	.string "on the island.$"

DewfordTown_Hall_Text_1FDED8: @ 81FDED8
	.string "Oh, a smashing good idea!\p"
	.string "It will settle once and for all\n"
	.string "who is the best at\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Brilliant, indeed!\p"
	.string "Starting today, our lives will revolve\n"
	.string "around “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FDF72: @ 81FDF72
	.string "I was thinking, though…\p"
	.string "Wouldn't you agree that\n"
	.string "“{STR_VAR_1}” has\l"
	.string "grown from being something trendy to\l"
	.string "being a part of our daily lives?$"

DewfordTown_Hall_Text_1FDFF1: @ 81FDFF1
	.string "Beg pardon?\n"
	.string "That much, what?\p"
	.string "However, it's true that\n"
	.string "“{STR_VAR_1}”\l"
	.string "weighs heavily on your mind, whether\l"
	.string "you're awake or asleep.\p"
	.string "Absolutely, you're the\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSOR, old sport!$"

DewfordTown_Hall_Text_1FE09A: @ 81FE09A
	.string "If you and me team up as a combo,\n"
	.string "we'll be invincible when it comes to all\l"
	.string "things “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FE0F2: @ 81FE0F2
	.string "Spot on, my friend!\p"
	.string "We shall be the\n"
	.string "“{STR_VAR_1}” DUO!\p"
	.string "Isn't that a ripe image?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_1FE142: @ 81FE142
	.string "For me, SLUDGE BOMB is at the peak\n"
	.string "of popularity. It's the one.\p"
	.string "Hunh? You're telling me that you don't\n"
	.string "know about SLUDGE BOMB?\p"
	.string "That's outright pitiful.\n"
	.string "I'll give you one.$"

DewfordTown_Hall_Text_1FE1ED: @ 81FE1ED
	.string "I love SLUDGE BOMB.\p"
	.string "But POKéMON with the move\n"
	.string "“{STR_VAR_1}”\l"
	.string "are in, too.$"

