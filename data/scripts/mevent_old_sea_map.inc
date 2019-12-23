MysteryEventScript_OldSeaMap:: @ 86757F4
	setvaddress MysteryEventScript_OldSeaMap
	lock
	faceplayer
	checkflag FLAG_RECEIVED_OLD_SEA_MAP
	vgoto_if_eq OldSeaMap_Obtained
	checkflag FLAG_CAUGHT_MEW
	vgoto_if_eq OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, TRUE
	vgoto_if_eq OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, FALSE
	vgoto_if_eq OldSeaMap_NoBagSpace
	giveitem_std ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace: @ 867584F
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained: @ 8675858
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Let me confirm--you are {PLAYER}?\p"
	.string "We received this OLD SEA MAP\n"
	.string "addressed to you.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
