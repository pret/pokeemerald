SSTidalLowerDeck_MapScripts:: @ 823C818
	.byte 0

SSTidalLowerDeck_EventScript_23C819:: @ 823C819
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_23C847, SSTidalLowerDeck_Text_23C8A0
	msgbox SSTidalLowerDeck_Text_23C8B4, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_23C830:: @ 823C830
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_23C917, SSTidalLowerDeck_Text_23C97D
	msgbox SSTidalLowerDeck_Text_23C98E, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_23C847: @ 823C847
	.string "Arrrgh! I'm fed up and dog-tired of\n"
	.string "cleaning this huge place!\p"
	.string "Let's have a quick battle!$"

SSTidalLowerDeck_Text_23C8A0: @ 823C8A0
	.string "Little bro, I lost!$"

SSTidalLowerDeck_Text_23C8B4: @ 823C8B4
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_Text_23C917: @ 823C917
	.string "This is the bottom of the ship's hull.\n"
	.string "There's plenty of room.\l"
	.string "It'll be alright for a POKéMON battle.$"

SSTidalLowerDeck_Text_23C97D: @ 823C97D
	.string "Big bro, I lost!$"

SSTidalLowerDeck_Text_23C98E: @ 823C98E
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

