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
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
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
	.string "Oh, ça alors! Tu voyages en solitaire?\n"
	.string "Mais tu es si jeune! C’est bien pour toi!\p"
	.string "Je suis sûre que tu pourrais apprendre\n"
	.string "un truc ou deux à mes enfants!\p"
	.string "Moi? Je suis une spécialiste\n"
	.string "des {POKEBLOCK}S.\p"
	.string "Si je me concentre un peu, je peux\n"
	.string "concocter de fabuleux {POKEBLOCK}S.\p"
	.string "Tu veux apprendre des choses de la\n"
	.string "spécialiste des {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Tu ne veux vraiment pas?\p"
	.string "Tu ne devrais pas toujours vouloir\n"
	.string "tout faire toi-même, mon p’tit!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Bien! Quelle âme avertie!\n"
	.string "C’est un peu long, alors écoute bien!\p"
	.string "C’est bon, je peux commencer?\p"
	.string "Si tu observes les {POKEBLOCK}S,\n"
	.string "tu verras qu’ils sont classés\l"
	.string "selon leur onctuosité.\p"
	.string "Plus le chiffre est bas, plus c’est\n"
	.string "onctueux et mieux c’est. N’oublie pas!\p"
	.string "Un bon {POKEBLOCK} est très onctueux\n"
	.string "et a un niveau élevé.\p"
	.string "Un POKéMON peut manger plus de\n"
	.string "bons {POKEBLOCK}S que de normaux.\p"
	.string "Et c’est important.\p"
	.string "Pour faire des {POKEBLOCK}S onctueux, il\n"
	.string "faut utiliser plusieurs sortes de\l"
	.string "BAIES.\p"
	.string "Ne sois pas avare! La variété des BAIES\n"
	.string "influe sur l’onctuosité des {POKEBLOCK}S.\p"
	.string "Et autre chose…\p"
	.string "Plus il y a de personnes qui mixent les\n"
	.string "BAIES, plus les {POKEBLOCK}S sont onctueux.\p"
	.string "C’est pourquoi tu dois parler aux\n"
	.string "autres et faire des {POKEBLOCK}S avec eux.\p"
	.string "Voilà à peu près tout ce que tu dois\n"
	.string "savoir pour faire de bons {POKEBLOCK}S.\p"
	.string "Si chacun avait des POKéMON qu’il\n"
	.string "aime, d’onctueux {POKEBLOCK}S et une famille\l"
	.string "aimante, le monde ne serait que bonheur.\p"
	.string "N’abandonne pas, mon p’tit.$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quand ma femme a mis au monde des\n"
	.string "quadruplés, ça a été un choc!\p"
	.string "Mais maintenant, je suis heureux de les\n"
	.string "voir jouer ensemble.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "On va faire des COMBATS MULTI, mais\n"
	.string "je sais que je vais gagner.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "On aime bien échanger des données\n"
	.string "au CENTRE DE DONNEES.\p"
	.string "Mais qu’est-ce qu’on va échanger\n"
	.string "au juste?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "On va faire de super {POKEBLOCK}S\n"
	.string "avec un MIXEUR!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Je veux que tu voies à quel point mon\n"
	.string "POKéMON est fort. Alors on va tous\l"
	.string "les deux participer à un CONCOURS.$"

