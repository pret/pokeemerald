SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/SootopolisCity_House7/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SootopolisCity_House7/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SootopolisCity_House7/text_es.inc"
.else
	.include "data/maps/SootopolisCity_House7/text.inc"
.endif
.endif
.endif
