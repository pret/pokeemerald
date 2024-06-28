Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

.ifdef ENGLISH
	.include "data/maps/Route119_House/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/Route119_House/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/Route119_House/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/Route119_House/text_es.inc"
.endif
.endif
.endif
.endif
