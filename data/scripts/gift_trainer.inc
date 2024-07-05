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

.ifdef FRENCH
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
.else
.ifdef ITALIAN
sText_MysteryGiftVisitingTrainerInstructions:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "La SCHEDA SEGRETA ti\n"
	.string "permette di partecipare ad\l"
	.string "un sondaggio al POKéMON-MARKET.\p"
	.string "Così, potrai invitare gli\n"
	.string "ALLENATORI a CENERIDE.\p"
	.string "Ora ti do la password che ti serve\n"
	.string "per partecipare a un sondaggio:\p"
	.string "BATTI CINQUE ACUTI\n"
	.string "ALLENATORE.\p"
	.string "Scrivi questa password su\n"
	.string "un sondaggio e invialo al\l"
	.string "SISTEMA COMUNICAZIONE\l"
	.string "WIRELESS.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Un ALLENATORE è appena\n"
	.string "arrivato a CENERIDE per cercarti.\p"
	.string "Buon divertimento nella lotta\n"
	.string "contro questo ALLENATORE!\p"
	.string "Inserendo altre password,\n"
	.string "potrai invitare altri ALLENATORI!\p"
	.string "Cerca altre password valide!$"
.else @ENGLISH
sText_MysteryGiftVisitingTrainerInstructions:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "By holding this WONDER CARD, you\n"
	.string "may take part in a survey at a\l"
	.string "POKéMON MART.\p"
	.string "Use these surveys to invite\n"
	.string "TRAINERS to SOOTOPOLIS CITY.\p"
	.string "…Let me give you a secret\n"
	.string "password for a survey:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Write that in on a survey and send\n"
	.string "it to the WIRELESS\l"
	.string "COMMUNICATION SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "A TRAINER has arrived in\n"
	.string "SOOTOPOLIS CITY looking for you.\p"
	.string "We hope you will enjoy\n"
	.string "battling the visiting TRAINER.\p"
	.string "You may invite other TRAINERS by\n"
	.string "entering other passwords.\p"
	.string "Try looking for other passwords\n"
	.string "that may work.$"
.endif
.endif
