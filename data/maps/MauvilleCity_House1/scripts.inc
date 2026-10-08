MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Joehoe!\p"
	.string "Mensen noemen mij de STEENBREKER-\n"
	.string "MAN, maar dat vind ik maar niks.\p"
	.string "Ik verdien meer respect. Noem me\n"
	.string "liever de STEENBREKER-HELD.\p"
	.string "Joehoe!\p"
	.string "Hoe dan ook, je POKéMON zien er\n"
	.string "best sterk uit.\p"
	.string "Dat vind ik leuk!\n"
	.string "Hier, neem deze VERBORGEN MACHINE!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Op die VM staat STEENBREKER.\p"
	.string "Zie je grote rotsen die je\n"
	.string "de weg versperren?\p"
	.string "Gebruik dan die VM-aanval en sla\n"
	.string "ze uit de weg!\p"
	.string "Ja! Sla die rotsen aan stukken!\n"
	.string "Joehoe!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh ja, als je een rots breekt, kan er\n"
	.string "soms een POKéMON uit springen.\p"
	.string "Joehoe!$"

