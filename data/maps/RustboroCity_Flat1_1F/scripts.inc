RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/RustboroCity_Flat1_1F/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/RustboroCity_Flat1_1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/RustboroCity_Flat1_1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/RustboroCity_Flat1_1F/text_es.inc"
.endif
.endif
.endif
.endif
