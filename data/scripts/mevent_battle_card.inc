MysteryEventScript_BattleCard:: @ 867513C
	setvaddress MysteryEventScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_EVENT_DONE, MysteryEventScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryEventCardVal
	compare VAR_0x8008, REQUIRED_CARD_BATTLES
	vgoto_if_ne MysteryEventScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_EVENT_DONE
	end

MysteryEventScript_BattleCardInfo: @ 8675179
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Your BATTLE COUNT CARD keeps\n"
	.string "track of your battle record against\l"
	.string "TRAINERS with the same CARD.\p"
	.string "Look for and battle TRAINERS who\n"
	.string "have the same CARD as you.\p"
	.string "You may check the overall rankings\n"
	.string "by reading the NEWS.\p"
	.string "Please do give it a try!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Congratulations!\p"
	.string "You have won a prize for winning\n"
	.string "three battles!\p"
	.string "We hope you will be inspired to\n"
	.string "battle some more.$"
