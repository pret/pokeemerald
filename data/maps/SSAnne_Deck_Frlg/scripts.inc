SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "The party's over.\n"
	.string "The ship will be departing soon.$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "Whew!\n"
	.string "Scrubbing decks is hard work!$"

SSAnne_Deck_Text_FeelSeasick::
	.string "Urf… I feel ill…\p"
	.string "I got seasick, so I stepped out to\n"
	.string "get some air…$"

SSAnne_Deck_Text_EdmondIntro::
	.string "Hey, matey!\p"
	.string "Let's do a little jig!$"

SSAnne_Deck_Text_EdmondDefeat::
	.string "You're impressive!$"

SSAnne_Deck_Text_EdmondPostBattle::
	.string "How many kinds of POKéMON do you\n"
	.string "think there are in this big world?$"

SSAnne_Deck_Text_TrevorIntro::
	.string "Ahoy, there!\n"
	.string "Are you seasick?$"

SSAnne_Deck_Text_TrevorDefeat::
	.string "I was just careless!$"

SSAnne_Deck_Text_TrevorPostBattle::
	.string "My pa said there are 100 kinds of\n"
	.string "POKéMON. I think there are more.$"

