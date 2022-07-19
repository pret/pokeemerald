MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hé, toi, DRESSEUR!\n"
	.string "Une MEGA CANNE, c’est vraiment super!\p"
	.string "Tu peux dire c’que tu veux, ce bébé peut\n"
	.string "attraper des POKéMON au fond de la mer!\p"
	.string "Qu’est-ce que t’en penses?\n"
	.string "Tu veux qu’on essaie, hein?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Tu paries, tu paries! Après tout, une\n"
	.string "MEGA CANNE, c’est super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "S’il y a de l’eau, essaie de lancer ta\n"
	.string "CANNE et attends de voir si ça mord!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hum?\n"
	.string "T’aimes pas pêcher?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Essaie d’attraper les POKéMON au fond\n"
	.string "de la mer avec ta MEGA CANNE.$"

