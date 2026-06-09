BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/BattleFrontier_Lounge4/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/BattleFrontier_Lounge4/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/BattleFrontier_Lounge4/text_es.inc"
.else
	.include "data/maps/BattleFrontier_Lounge4/text.inc"
.endif
.endif
.endif
