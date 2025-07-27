BattleFrontier_Lounge8_MapScripts::
	.byte 0

BattleFrontier_Lounge8_EventScript_Man::
	msgbox BattleFrontier_Lounge8_Text_WhatATrainerNeeds, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_Woman::
	msgbox BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_NinjaBoy::
	msgbox BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/BattleFrontier_Lounge8/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/BattleFrontier_Lounge8/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/BattleFrontier_Lounge8/text_es.inc"
.else
	.include "data/maps/BattleFrontier_Lounge8/text.inc"
.endif
.endif
.endif
