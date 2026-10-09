MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Je GEVECHTSTELKAART houdt je\n"
	.string "gevechten bij tegen TRAINERS\l"
	.string "met dezelfde KAART.\p"
	.string "Zoek TRAINERS met dezelfde KAART\n"
	.string "als jij en vecht tegen ze.\p"
	.string "De ranglijst zie je in het\n"
	.string "NIEUWS.\p"
	.string "Probeer het zeker eens!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Gefeliciteerd!\p"
	.string "Je hebt een prijs gewonnen voor\n"
	.string "drie gewonnen gevechten!\p"
	.string "We hopen dat je nog meer\n"
	.string "gaat vechten.$"
