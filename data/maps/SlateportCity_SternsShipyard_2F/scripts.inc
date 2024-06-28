SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/SlateportCity_SternsShipyard_2F/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/SlateportCity_SternsShipyard_2F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SlateportCity_SternsShipyard_2F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SlateportCity_SternsShipyard_2F/text_es.inc"
.endif
.endif
.endif
.endif
