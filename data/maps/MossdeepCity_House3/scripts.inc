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
	.string "Hé daar, TRAINER!\n"
	.string "Een SUPERHENGEL is echt super!\p"
	.string "Zeg wat je wilt, maar hiermee\n"
	.string "vang je POKéMON van de zeebodem!\p"
	.string "Wat vind je?\n"
	.string "Je wilt hem wel, of niet?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Natuurlijk, natuurlijk!\n"
	.string "Een SUPERHENGEL is echt super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Zie je water? Gooi je HENGEL\n"
	.string "uit en kijk wat er bijt!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hè?\n"
	.string "Vis je niet graag?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Ga met je SUPERHENGEL op zoek\n"
	.string "naar POKéMON van de zeebodem.$"

