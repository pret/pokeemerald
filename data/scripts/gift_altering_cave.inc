MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

.ifdef FRENCH
sText_MysteryGiftAlteringCave:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Il y a de plus en plus de rumeurs\n"
	.string "sur l’apparition de POKéMON rares.\p"
	.string "Les rumeurs parlent de la GROTTE\n"
	.string "METAMO sur la ROUTE 103.\p"
	.string "Vous devriez y aller pour vérifier\n"
	.string "si les rumeurs sont vraies.$"
.else
.ifdef ITALIAN
sText_MysteryGiftAlteringCave:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Recentemente sono stati visti\n"
	.string "POKéMON rari nella GROTTA\l"
	.string "MUTEVOLE sul PERCORSO 103.\p"
	.string "Perché non vai a vedere\n"
	.string "di persona?$"
.else @ENGLISH
sText_MysteryGiftAlteringCave:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "There appears to be a rumor about\n"
	.string "rare POKéMON sightings.\p"
	.string "The sightings reportedly came from\n"
	.string "the ALTERING CAVE on ROUTE 103.\p"
	.string "Perhaps it would be worthwhile for\n"
	.string "you to investigate this rumor.$"
.endif
.endif
