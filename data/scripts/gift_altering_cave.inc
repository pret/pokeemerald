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

sText_MysteryGiftAlteringCave:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Il y a de plus en plus de rumeurs\n"
	.string "sur l’apparition de POKéMON rares.\p"
	.string "Les rumeurs parlent de la GROTTE\n"
	.string "METAMO sur la ROUTE 103.\p"
	.string "Vous devriez y aller pour vérifier\n"
	.string "si les rumeurs sont vraies.$"
