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
	.string "Je me demande s’il y aura des interviews\n"
	.string "de bons DRESSEURS aujourd’hui.$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si j’ouvrais un restaurant ici, je\n"
	.string "ferais fortune!$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Pfiou…\p"
	.string "J’aurais besoin de faire le vide dans\n"
	.string "ma tête entre deux combats…\p"
	.string "Mais je n’arrête jamais de penser à\n"
	.string "ma stratégie.$"

