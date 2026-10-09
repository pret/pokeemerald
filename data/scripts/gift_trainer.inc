MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Met deze WONDERKAART kun je meedoen\n"
	.string "aan een enquête bij een POKéMON MART.\p"
	.string "Met enquêtes nodig je TRAINERS uit\n"
	.string "naar SOOTOPOLIS CITY.\p"
	.string "…Ik geef je een geheim\n"
	.string "wachtwoord voor een enquête:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Schrijf dat op een enquête en stuur\n"
	.string "het naar het DRAADLOZE\l"
	.string "COMMUNICATIESYSTEEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Een TRAINER is in SOOTOPOLIS CITY\n"
	.string "aangekomen en zoekt jou.\p"
	.string "Veel plezier met het vechten\n"
	.string "tegen de bezoekende TRAINER.\p"
	.string "Je kunt andere TRAINERS uitnodigen\n"
	.string "met andere wachtwoorden.\p"
	.string "Zoek maar naar andere wachtwoorden\n"
	.string "die werken.$"
