DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

.ifdef ENGLISH
	.include "data/maps/DewfordTown_House1/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/DewfordTown_House1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/DewfordTown_House1/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/DewfordTown_House1/text_es.inc"
.endif
.endif
.endif
.endif

