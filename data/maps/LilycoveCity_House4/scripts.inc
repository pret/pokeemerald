LilycoveCity_House4_MapScripts::
	.byte 0

LilycoveCity_House4_EventScript_Man1::
	msgbox LilycoveCity_House4_Text_MysteriesAtBottomOfSea, MSGBOX_NPC
	end

LilycoveCity_House4_EventScript_Man2::
	msgbox LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/LilycoveCity_House4/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/LilycoveCity_House4/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/LilycoveCity_House4/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/LilycoveCity_House4/text_es.inc"
.endif
.endif
.endif
.endif
