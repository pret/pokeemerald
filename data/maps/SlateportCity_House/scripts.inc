SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "My Pokémon has a Hasty nature.\p"
	.string "It has higher Speed compared to\n"
	.string "my other Pokémon.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of Pokémon.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "You're a Trainer, aren't you?\p"
	.string "Since you came to Slateport City,\n"
	.string "you must be going to the Battle Tent.$"

