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
	.2byte ITEM_NONE
	release
	end

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
	.string "RAPPEL est fabuleux!\p"
	.string "Si tu en donnes à un POKéMON K.O.,\n"
	.string "il reprend connaissance.\p"
	.string "Mais attention, RAPPEL ne restitue\n"
	.string "pas les PP des capacités déjà utilisés.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPOUSSE maintient les POKéMON\n"
	.string "faibles à l’écart.\p"
	.string "Parmi tous les REPOUSSES, c’est celui\n"
	.string "qui dure le plus longtemps.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les FILET BALLS et les SCUBA BALLS\n"
	.string "sont des POKé BALLS rares, qui ne\l"
	.string "sont fabriquées qu’à ALGATIA.\p"
	.string "La FILET BALL est efficace contre les\n"
	.string "POKéMON des types INSECTE et EAU.\p"
	.string "La SCUBA BALL est plus efficace\n"
	.string "contre les POKéMON qui vivent\l"
	.string "au fond de la mer.$"

