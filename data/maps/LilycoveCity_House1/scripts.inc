LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

.ifdef FRENCH
	.include "data/maps/LilycoveCity_House1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/LilycoveCity_House1/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/LilycoveCity_House1/text_es.inc"
.else
	.include "data/maps/LilycoveCity_House1/text.inc"
.endif
.endif
.endif
