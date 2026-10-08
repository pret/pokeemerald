MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "OPKIKKER is fantastisch!\p"
	.string "Geef hem aan een verslagen POKéMON\n"
	.string "en de POKéMON staat weer op.\p"
	.string "Maar let op, OPKIKKER herstelt de\n"
	.string "gebruikte PP van aanvallen niet.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAXAFWEER houdt alle zwakke POKéMON\n"
	.string "weg.\p"
	.string "Van alle AFWEER-sprays werkt hij\n"
	.string "het langst.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "De NETBALL en DUIKBALL zijn zeldzame\n"
	.string "POKé BALLS, alleen gemaakt in MOSSDEEP.\p"
	.string "Een NETBALL werkt goed tegen\n"
	.string "INSECT- en WATER-POKéMON.\p"
	.string "Een DUIKBALL werkt het best op\n"
	.string "POKéMON op de zeebodem.$"

