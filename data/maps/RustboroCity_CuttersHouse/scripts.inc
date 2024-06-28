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

.ifdef ENGLISH
	.include "data/maps/RustboroCity_CuttersHouse/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/RustboroCity_CuttersHouse/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_CuttersHouse/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_CuttersHouse/text_es.inc"
.endif
.endif
.endif
.endif
