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

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Zouden ze vandaag interviews met\n"
	.string "sterke TRAINERS uitzenden?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Als ik hier een restaurant opende,\n"
	.string "verdiende ik zeker geld.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Pfoe…\p"
	.string "Ik moet even bijkomen na die\n"
	.string "zware gevechten…\p"
	.string "Maar zelfs nu stop ik nooit met\n"
	.string "plannen maken voor strategieën.$"

