OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/OldaleTown_House2/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/OldaleTown_House2/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/OldaleTown_House2/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/OldaleTown_House2/text_es.inc"
.endif
.endif
.endif
.endif
