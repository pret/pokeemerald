VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/VerdanturfTown_House/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/VerdanturfTown_House/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/VerdanturfTown_House/text_es.inc"
.else
	.include "data/maps/VerdanturfTown_House/text.inc"
.endif
.endif
.endif
