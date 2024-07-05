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

.ifdef FRENCH
	.include "data/maps/RustboroCity_CuttersHouse/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_CuttersHouse/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_CuttersHouse/text_es.inc"
.else
	.include "data/maps/RustboroCity_CuttersHouse/text.inc"
.endif
.endif
.endif
