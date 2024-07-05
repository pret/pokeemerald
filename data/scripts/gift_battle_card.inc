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

.ifdef FRENCH
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
.else
.ifdef ITALIAN
sText_MysteryGiftBattleCountCard:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "La tua SCHEDA CONTALOTTE\n"
	.string "calcola il numero di LOTTE contro\l"
	.string "ALLENATORI con la stessa SCHEDA.\p"
	.string "Cerca altri ALLENATORI che hanno\n"
	.string "la SCHEDA CONTALOTTE e sfidali!\p"
	.string "I risultati saranno diffusi tra le\n"
	.string "NOTIZIE!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO!\p"
	.string "Congratulazioni! Hai ottenuto\n"
	.string "un premio per aver vinto tre lotte!\p"
	.string "Speriamo che questo ti aiuti ad\n"
	.string "impegnarti ancora di più nella\l"
	.string "lotta!$"
.else @ENGLISH
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
.endif
.endif
