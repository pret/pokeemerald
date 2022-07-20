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
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "La CARTE COMBAT garde la trace\n"
	.string "de vos combats contre les\p"
	.string "DRESSEURS ayant la même\n"
	.string "CARTE.\p"
	.string "Recherchez les DRESSEURS ayant\n"
	.string "la même carte que vous.\p"
	.string "Vous pouvez voir le classement\n"
	.string "général en lisant les JOURNAUX.\p"
	.string "Vous devriez essayer!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Félicitations!\p"
	.string "Vous recevez un prix pour avoir\n"
	.string "gagné trois combats!\p"
	.string "On espère que ça vous donnera\n"
	.string "encore plus envie de combattre.$"
