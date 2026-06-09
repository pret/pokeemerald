AbandonedShip_Rooms2_B1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_B1F_EventScript_Camper::
	msgbox AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/AbandonedShip_Rooms2_B1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/AbandonedShip_Rooms2_B1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/AbandonedShip_Rooms2_B1F/text_es.inc"
.else
	.include "data/maps/AbandonedShip_Rooms2_B1F/text.inc"
.endif
.endif
.endif
