MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_House3_EventScript_DeclineSuperRod
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
	.string "Hey there, Trainer!\n"
	.string "A Super Rod really is super!\p"
	.string "Say all you want, but this baby can\n"
	.string "catch Pokémon off the seafloor!\p"
	.string "What do you think?\n"
	.string "You want it, don't you?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "You bet, you bet!\n"
	.string "After all, a Super Rod is really super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "If there's any water, try dropping in\n"
	.string "your Rod and see what bites!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hunh?\n"
	.string "Don't you like to fish?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Go after the seafloor Pokémon with\n"
	.string "your Super Rod.$"

