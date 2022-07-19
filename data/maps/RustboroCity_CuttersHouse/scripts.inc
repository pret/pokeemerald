RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Ton air déterminé…\n"
	.string "La souplesse de tes mouvements…\p"
	.string "Tes POKéMON bien entraînés…\n"
	.string "Tu es à l’évidence un DRESSEUR averti!\p"
	.string "Non, attends, ne dis rien!\n"
	.string "Je devine tout rien qu’à te voir.\p"
	.string "Je suis sûr que tu seras capable\n"
	.string "de faire bon usage de cette CS.\p"
	.string "Ne sois pas modeste ni timide!\n"
	.string "Allez, prends-la!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cette CS, c’est COUPE.\p"
	.string "Une CS, c’est une capacité qui peut être\n"
	.string "utilisée en dehors d’un combat.\p"
	.string "Tout POKéMON ayant appris COUPE peut\n"
	.string "abattre les petits arbres si son\l"
	.string "DRESSEUR possède le BADGE ROCHE.\p"
	.string "Et contrairement à une CT, une CS peut\n"
	.string "s’utiliser plusieurs fois.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quand ils ont agrandi MEROUVILLE,\n"
	.string "mon papa les a aidés.\p"
	.string "Il a fait utiliser COUPE à son POKéMON\n"
	.string "pour qu’il déboise le terrain.$"

