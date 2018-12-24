BerryTreeScript:: @ 82742F9
	special EventObjectInteractionGetBerryTreeData
	switch VAR_0x8004
	case 255, Route102_EventScript_27434F
	case 0, Route102_EventScript_274359
	case 1, Route102_EventScript_2743B1
	case 2, Route102_EventScript_2743C1
	case 3, Route102_EventScript_2743D1
	case 4, Route102_EventScript_2743E1
	case 5, Route102_EventScript_274421
	end

Route102_EventScript_27434F:: @ 827434F
	lockall
	message Route102_Text_274744
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_274359:: @ 8274359
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_274374
	message Route102_Text_2744F0
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274374:: @ 8274374
	msgbox Route102_Text_274507, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_274393
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_2743AF
	end

Route102_EventScript_274393:: @ 8274393
	fadescreen 1
	closemessage
	special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq Route102_EventScript_2743AF
	takeitem VAR_ITEM_ID, 1
	call Route102_EventScript_2744DD

Route102_EventScript_2743AF:: @ 82743AF
	release
	end

Route102_EventScript_2743B1:: @ 82743B1
	lockall
	special EventObjectInteractionGetBerryCountString
	message Route102_Text_274560
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743C1:: @ 82743C1
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_274579
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743D1:: @ 82743D1
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_27458A
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743E1:: @ 82743E1
	call Route102_EventScript_2743F6
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_2745AB
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743F6:: @ 82743F6
	compare VAR_0x8005, 0
	goto_if_eq Route102_EventScript_27441A
	compare VAR_0x8005, 4
	goto_if_eq Route102_EventScript_274413
	bufferstring 1, Route102_Text_2745E5
	return

Route102_EventScript_274413:: @ 8274413
	bufferstring 1, Route102_Text_2745CD
	return

Route102_EventScript_27441A:: @ 827441A
	bufferstring 1, Route102_Text_2745DE
	return

Route102_EventScript_274421:: @ 8274421
	buffernumberstring 1, VAR_0x8006
	lock
	faceplayer
	special EventObjectInteractionGetBerryCountString
	msgbox Route102_Text_2745EE, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_274448
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_274479

Route102_EventScript_274448:: @ 8274448
	special EventObjectInteractionPickBerryTree
	compare VAR_0x8004, 0
	goto_if_eq Route102_EventScript_274470
	special sub_80EED34
	special EventObjectInteractionRemoveBerryTree
	message Route102_Text_27461B
	playfanfare MUS_ME_KINOMI
	waitmessage
	waitfanfare
	waitbuttonpress
	message Route102_Text_274630
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274470:: @ 8274470
	message Route102_Text_27468F
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274479:: @ 8274479
	message Route102_Text_2746CB
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274482:: @ 8274482
	lockall
	special EventObjectInteractionGetBerryTreeData
	call Route102_EventScript_2744DD
	releaseall
	end

Route102_EventScript_27448D:: @ 827448D
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_2744BE
	special EventObjectInteractionGetBerryName
	msgbox Route102_Text_2746E4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_2744C4
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_2744BE

Route102_EventScript_2744BE:: @ 82744BE
	releaseall
	end

Route102_EventScript_2744C0:: @ 82744C0
	special EventObjectInteractionGetBerryTreeData
	lockall

Route102_EventScript_2744C4:: @ 82744C4
	special EventObjectInteractionGetBerryName
	message Route102_Text_274710
	waitmessage
	special EventObjectInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	message Route102_Text_274723
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_2744DD:: @ 82744DD
	special EventObjectInteractionPlantBerryTree
	incrementgamestat 3
	special sub_80EED10
	special EventObjectInteractionGetBerryCountString
	message Route102_Text_274535
	waitmessage
	waitbuttonpress
	return

Route102_Text_2744F0: @ 82744F0
	.string "It's soft, loamy soil.$"

Route102_Text_274507: @ 8274507
	.string "It's soft, loamy soil.\n"
	.string "Want to plant a BERRY?$"

Route102_Text_274535: @ 8274535
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
	.string "the soft, loamy soil.$"

Route102_Text_274560: @ 8274560
	.string "One {STR_VAR_1} was planted here.$"

Route102_Text_274579: @ 8274579
	.string "{STR_VAR_1} has sprouted.$"

Route102_Text_27458A: @ 827458A
	.string "This {STR_VAR_1} plant is growing taller.$"

Route102_Text_2745AB: @ 82745AB
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}.$"

Route102_Text_2745CD: @ 82745CD
	.string "very beautifully$"

Route102_Text_2745DE: @ 82745DE
	.string "cutely$"

Route102_Text_2745E5: @ 82745E5
	.string "prettily$"

Route102_Text_2745EE: @ 82745EE
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

Route102_Text_27461B: @ 827461B
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"

Route102_Text_274630: @ 8274630
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG's BERRIES POCKET.\p"
	.string "The soil returned to its soft and\n"
	.string "loamy state.$"

Route102_Text_27468F: @ 827468F
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

Route102_Text_2746CB: @ 82746CB
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"

Route102_Text_2746E4: @ 82746E4
	.string "Want to water the {STR_VAR_1} with the\n"
	.string "WAILMER PAIL?$"

Route102_Text_274710: @ 8274710
	.string "{PLAYER} watered the {STR_VAR_1}.$"

Route102_Text_274723: @ 8274723
	.string "The plant seems to be delighted.$"

Route102_Text_274744: @ 8274744
	.string "!$"
