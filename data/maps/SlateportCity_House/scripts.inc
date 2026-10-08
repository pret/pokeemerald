SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mijn POKéMON heeft de aard HAASTIG.\p"
	.string "Hij heeft meer SNELHEID dan\n"
	.string "mijn andere POKéMON.\p"
	.string "Misschien heeft de aard iets te maken\n"
	.string "met hoe sterk POKéMON worden.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Jij bent een TRAINER, toch?\p"
	.string "Je bent in SLATEPORT CITY, dus je\n"
	.string "gaat vast naar de BATTLE TENT.$"

