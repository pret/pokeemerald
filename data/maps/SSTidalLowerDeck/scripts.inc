SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! I'm fed up and dog-tired of\n"
	.string "cleaning this huge place!\p"
	.string "Let's have a quick battle!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Little bro, I lost!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "We're the Cleanup Brothers!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "This is the bottom of the ship's hull.\n"
	.string "There's plenty of room.\l"
	.string "It'll be alright for a Pokémon battle.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Big bro, I lost!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "We're the Cleanup Brothers!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

