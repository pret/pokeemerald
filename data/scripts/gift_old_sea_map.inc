MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Laat me even kijken: ben jij {PLAYER}?\p"
	.string "We kregen deze ZEEKAART\n"
	.string "voor je.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Hij lijkt bedoeld voor de haven\n"
	.string "van LILYCOVE CITY.\p"
	.string "Probeer het eens en kijk wat\n"
	.string "het is!$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, sorry, {PLAYER}.\n"
	.string "Het BELANGRIJK-vak van je TAS is vol.\p"
	.string "Leg iets op je PC en kom dan\n"
	.string "terug hiervoor.$"
