OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/OldaleTown_House1/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/OldaleTown_House1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/OldaleTown_House1/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/OldaleTown_House1/text_es.inc"
.endif
.endif
.endif
.endif
