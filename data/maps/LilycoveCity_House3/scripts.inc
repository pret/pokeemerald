LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Jeetje! Reis je alleen?\n"
	.string "Wat jong nog! Goed van je!\p"
	.string "Mijn kinderen kunnen vast iets\n"
	.string "van jou leren!\p"
	.string "Ik? Ik ben een meester in\n"
	.string "{POKEBLOCK}S.\p"
	.string "Als ik me een beetje inspan,\n"
	.string "maak ik geweldige {POKEBLOCK}S.\p"
	.string "Wil je van me leren, van een\n"
	.string "meester in {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Weet je het zeker?\p"
	.string "Je moet niet altijd alles zelf\n"
	.string "proberen, lieverd!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, fijn! Je bent slim!\n"
	.string "Het is wat lang, dus luister goed!\p"
	.string "Ben je klaar?\p"
	.string "Bij {POKEBLOCK}S staat een\n"
	.string "waarde voor hoe ze aanvoelen.\p"
	.string "Hoe lager die waarde,\n"
	.string "hoe beter. Vergeet dat niet!\p"
	.string "Een goede {POKEBLOCK} heeft een lage\n"
	.string "waarde en een hoog level.\p"
	.string "Een POKéMON kan ook meer goede\n"
	.string "{POKEBLOCK}S eten dan gewone.\p"
	.string "En dit is belangrijk.\p"
	.string "Wil je zachte {POKEBLOCK}S maken,\n"
	.string "gebruik dan verschillende BESSEN.\p"
	.string "Wees niet zuinig: de soorten BESSEN\n"
	.string "bepalen hoe zacht de {POKEBLOCK}S zijn.\p"
	.string "En nog iets.\p"
	.string "Hoe meer mensen BESSEN mixen,\n"
	.string "hoe zachter de {POKEBLOCK}S.\p"
	.string "Praat dus met anderen en maak\n"
	.string "{POKEBLOCK}S samen.\p"
	.string "Dat is alles wat je moet weten\n"
	.string "voor goede {POKEBLOCK}S.\p"
	.string "Als iedereen POKéMON had om van te\n"
	.string "houden, zachte {POKEBLOCK}S en een\l"
	.string "liefdevol gezin, was de wereld\l"
	.string "gelukkiger.\p"
	.string "Geef niet op, lieverd!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Toen mijn vrouw een vierling kreeg,\n"
	.string "schrok ik me rot.\p"
	.string "Maar nu ze samen spelen,\n"
	.string "ben ik er blij mee.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "We doen MULTI-GEVECHTEN, maar ik\n"
	.string "weet zeker dat ik win.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "We mixen graag bij de\n"
	.string "RECORD CORNER.\p"
	.string "Maar wat wordt er gemixt?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "We maken super {POKEBLOCK}S\n"
	.string "met een BESSENMIXER!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Ik wil opscheppen over hoe sterk\n"
	.string "mijn POKéMON is, dus we doen samen\l"
	.string "mee aan een WEDSTRIJD.$"

