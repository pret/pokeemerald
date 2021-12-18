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
	.string "Thank you for using the Mystery\n"
	.string "Gift System.\p"
	.string "By holding this Wonder Card, you\n"
	.string "may take part in a survey at a\l"
	.string "Pokémon Mart.\p"
	.string "Use these surveys to invite\n"
	.string "Trainers to Sootopolis City.\p"
	.string "…Let me give you a secret\n"
	.string "password for a survey:\p"
	.string "“Give Me\n"
	.string "Awesome Trainer”\p"
	.string "Write that in on a survey and send\n"
	.string "it to the Wireless\l"
	.string "Communication System.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Thank you for using the Mystery\n"
	.string "Gift System.\p"
	.string "A Trainer has arrived in\n"
	.string "Sootopolis City looking for you.\p"
	.string "We hope you will enjoy\n"
	.string "battling the visiting Trainer.\p"
	.string "You may invite other Trainers by\n"
	.string "entering other passwords.\p"
	.string "Try looking for other passwords\n"
	.string "that may work.$"
