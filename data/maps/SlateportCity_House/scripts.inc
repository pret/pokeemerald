SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mon POKéMON est PRESSE.\n"
	.string "C’est sa nature.\p"
	.string "Sa VITESSE est plus élevée que celle de\n"
	.string "mes autres POKéMON.\p"
	.string "La nature des POKéMON a peut-être\n"
	.string "un rapport avec leurs stats.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Tu es un DRESSEUR, n’est-ce pas?\p"
	.string "Tu dois vouloir te rendre à la TENTE\n"
	.string "DE COMBAT de POIVRESSEL, non?$"

