AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef ENGLISH
	.include "data/maps/AbandonedShip_Corridors_1F/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/AbandonedShip_Corridors_1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/AbandonedShip_Corridors_1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/AbandonedShip_Corridors_1F/text_es.inc"
.endif
.endif
.endif
.endif
