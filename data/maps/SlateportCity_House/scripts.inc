SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/SlateportCity_House/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SlateportCity_House/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SlateportCity_House/text_es.inc"
.else
	.include "data/maps/SlateportCity_House/text.inc"
.endif
.endif
.endif
