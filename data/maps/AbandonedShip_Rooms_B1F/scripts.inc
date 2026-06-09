AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_FatMan::
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/AbandonedShip_Rooms_B1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/AbandonedShip_Rooms_B1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/AbandonedShip_Rooms_B1F/text_es.inc"
.else
	.include "data/maps/AbandonedShip_Rooms_B1F/text.inc"
.endif
.endif
.endif
