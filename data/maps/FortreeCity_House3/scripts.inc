FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/FortreeCity_House3/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/FortreeCity_House3/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/FortreeCity_House3/text_it.inc"
.endif
.endif
.endif
