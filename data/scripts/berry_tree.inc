BerryTreeScript:: @ 82742F9
	special EventObjectInteractionGetBerryTreeData
	switch VAR_0x8004
	case 255, Route102_EventScript_27434F
	case 0, Route102_EventScript_CheckSoil
	case 1, Route102_EventScript_CheckBerryStage1
	case 2, Route102_EventScript_CheckBerryStage2
	case 3, Route102_EventScript_CheckBerryStage3
	case 4, Route102_EventScript_CheckBerryStage4
	case 5, Route102_EventScript_CheckBerryFullyGrown
	end

Route102_EventScript_27434F:: @ 827434F
	lockall
	message Route102_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_CheckSoil:: @ 8274359
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_WantToPlant
	message Route102_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_WantToPlant:: @ 8274374
	msgbox Route102_Text_WantToPlant, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_ChooseBerryToPlant
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_CancelPlanting
	end

Route102_EventScript_ChooseBerryToPlant:: @ 8274393
	fadescreen 1
	closemessage
	special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq Route102_EventScript_CancelPlanting
	takeitem VAR_ITEM_ID, 1
	call Route102_EventScript_PlantBerry

Route102_EventScript_CancelPlanting:: @ 82743AF
	release
	end

Route102_EventScript_CheckBerryStage1:: @ 82743B1
	lockall
	special EventObjectInteractionGetBerryCountString
	message Route102_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_WantToWater

Route102_EventScript_CheckBerryStage2:: @ 82743C1
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_WantToWater

Route102_EventScript_CheckBerryStage3:: @ 82743D1
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_WantToWater

Route102_EventScript_CheckBerryStage4:: @ 82743E1
	call Route102_EventScript_GetCareAdverb
	lockall
	special EventObjectInteractionGetBerryName
	message Route102_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_WantToWater

Route102_EventScript_GetCareAdverb:: @ 82743F6
	compare VAR_0x8005, 0
	goto_if_eq Route102_EventScript_SetAdverbPoor
	compare VAR_0x8005, 4
	goto_if_eq Route102_EventScript_SetAdverbGreat
	bufferstring 1, Route102_Text_CareAdverbGood
	return

Route102_EventScript_SetAdverbGreat:: @ 8274413
	bufferstring 1, Route102_Text_CareAdverbGreat
	return

Route102_EventScript_SetAdverbPoor:: @ 827441A
	bufferstring 1, Route102_Text_CareAdverbPoor
	return

Route102_EventScript_CheckBerryFullyGrown:: @ 8274421
	buffernumberstring 1, VAR_0x8006
	lock
	faceplayer
	special EventObjectInteractionGetBerryCountString
	msgbox Route102_Text_WantToPick, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_PickBerry
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_CancelPickingBerry

Route102_EventScript_PickBerry:: @ 8274448
	special EventObjectInteractionPickBerryTree
	compare VAR_0x8004, 0
	goto_if_eq Route102_EventScript_BerryPocketFull
	special sub_80EED34
	special EventObjectInteractionRemoveBerryTree
	message Route102_Text_PickedTheBerry
	playfanfare MUS_ME_KINOMI
	waitmessage
	waitfanfare
	waitbuttonpress
	message Route102_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_BerryPocketFull:: @ 8274470
	message Route102_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_CancelPickingBerry:: @ 8274479
	message Route102_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274482:: @ 8274482
	lockall
	special EventObjectInteractionGetBerryTreeData
	call Route102_EventScript_PlantBerry
	releaseall
	end

Route102_EventScript_WantToWater:: @ 827448D
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_DontWater
	special EventObjectInteractionGetBerryName
	msgbox Route102_Text_WantToWater, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_WaterBerry
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_DontWater

Route102_EventScript_DontWater:: @ 82744BE
	releaseall
	end

Route102_EventScript_2744C0:: @ 82744C0
	special EventObjectInteractionGetBerryTreeData
	lockall

Route102_EventScript_WaterBerry:: @ 82744C4
	special EventObjectInteractionGetBerryName
	message Route102_Text_WateredTheBerry
	waitmessage
	special EventObjectInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	message Route102_Text_PlantIsDelighted
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_PlantBerry:: @ 82744DD
	special EventObjectInteractionPlantBerryTree
	incrementgamestat 3
	special sub_80EED10
	special EventObjectInteractionGetBerryCountString
	message Route102_Text_PlantedOneBerry
	waitmessage
	waitbuttonpress
	return

Route102_Text_ItsSoftLoamySoil: @ 82744F0
	.string "It's soft, loamy soil.$"

Route102_Text_WantToPlant: @ 8274507
	.string "It's soft, loamy soil.\n"
	.string "Want to plant a BERRY?$"

Route102_Text_PlantedOneBerry: @ 8274535
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
	.string "the soft, loamy soil.$"

Route102_Text_BerryGrowthStage1: @ 8274560
	.string "One {STR_VAR_1} was planted here.$"

Route102_Text_BerryGrowthStage2: @ 8274579
	.string "{STR_VAR_1} has sprouted.$"

Route102_Text_BerryGrowthStage3: @ 827458A
	.string "This {STR_VAR_1} plant is growing taller.$"

Route102_Text_BerryGrowthStage4: @ 82745AB
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}.$"

Route102_Text_CareAdverbGreat: @ 82745CD
	.string "very beautifully$"

Route102_Text_CareAdverbPoor: @ 82745DE
	.string "cutely$"

Route102_Text_CareAdverbGood: @ 82745E5
	.string "prettily$"

Route102_Text_WantToPick: @ 82745EE
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

Route102_Text_PickedTheBerry: @ 827461B
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"

Route102_Text_PutAwayBerry: @ 8274630
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG's BERRIES POCKET.\p"
	.string "The soil returned to its soft and\n"
	.string "loamy state.$"

Route102_Text_BerryPocketFull: @ 827468F
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

Route102_Text_BerryLeftUnpicked: @ 82746CB
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"

Route102_Text_WantToWater: @ 82746E4
	.string "Want to water the {STR_VAR_1} with the\n"
	.string "WAILMER PAIL?$"

Route102_Text_WateredTheBerry: @ 8274710
	.string "{PLAYER} watered the {STR_VAR_1}.$"

Route102_Text_PlantIsDelighted: @ 8274723
	.string "The plant seems to be delighted.$"

Route102_Text_ExclamationPoint: @ 8274744
	.string "!$"
