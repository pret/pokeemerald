PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/PacifidlogTown_House1/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/PacifidlogTown_House1/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/PacifidlogTown_House1/text_it.inc"
.endif
.endif
.endif
