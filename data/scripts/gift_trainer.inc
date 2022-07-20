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
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "En tenant la CARTE MIRACLE,\n"
	.string "vous pouvez effectuer des\p"
	.string "sondages dans les BOUTIQUES\n"
	.string "POKéMON.\p"
	.string "Utilisez ces sondages pour inviter\n"
	.string "des DRESSEURS à ATALANOPOLIS.\p"
	.string "Laissez-moi vous donner un mot\n"
	.string "de passe secret:\p"
	.string "“DONNE-MOI\n"
	.string "UN COMBAT”\p"
	.string "Ecrivez ça sur un sondage et\n"
	.string "envoyez-le au SYSTEME DE\p"
	.string "COMMUNICATION SANS FIL.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Un DRESSEUR arrivé à ATALANOPOLIS\n"
	.string "vous cherche.\p"
	.string "On espère que vous apprecierez\n"
	.string "le combat contre ce DRESSEUR.\p"
	.string "Vous pouvez inviter des DRESSEURS\n"
	.string "en entrant le mot de passe.\p"
	.string "Essayez de trouver des mots de\n"
	.string "passe qui pourraient fonctionner.$"
