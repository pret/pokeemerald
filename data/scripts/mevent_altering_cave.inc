MysteryEventScript_AlteringCave::
	setvaddress MysteryEventScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	compare VAR_ALTERING_CAVE_WILD_SET, 10
	vgoto_if_ne MysteryEventScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryEventScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave::
	.string "Thank you for using the Mystery\n"
	.string "Gift System.\p"
	.string "There appears to be a rumor about\n"
	.string "rare Pokémon sightings.\p"
	.string "The sightings reportedly came from\n"
	.string "the Altering Cave on Route 103.\p"
	.string "Perhaps it would be worthwhile for\n"
	.string "you to investigate this rumor.$"
