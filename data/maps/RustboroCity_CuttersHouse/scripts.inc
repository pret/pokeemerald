RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
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
	.string "Die vastberaden blik…\n"
	.string "Die soepele manier van bewegen…\l"
	.string "En je goed getrainde POKéMON…\p"
	.string "Jij bent duidelijk een goede TRAINER!\p"
	.string "Nee, wacht, zeg maar niks.\n"
	.string "Ik zie het al aan je.\p"
	.string "Jij weet vast goed wat je met deze\n"
	.string "VERBORGEN MACHINE moet doen.\p"
	.string "Niet verlegen zijn.\n"
	.string "Kom, pak aan!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Die VERBORGEN MACHINE, of kortweg HM,\n"
	.string "is SNIJDEN.\p"
	.string "Een HM-aanval kan een POKéMON ook\n"
	.string "buiten gevechten gebruiken.\p"
	.string "Een POKéMON met SNIJDEN kan dunne\n"
	.string "boompjes omhakken als de TRAINER\l"
	.string "de STONE BADGE heeft.\p"
	.string "En anders dan een TM kun je een HM\n"
	.string "vaker gebruiken.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Toen RUSTBORO groter werd, hielp\n"
	.string "mijn vader mee.\p"
	.string "Zijn POKéMON gebruikten SNIJDEN om\n"
	.string "alle bomen weg te halen.$"

