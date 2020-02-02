BattleFrontier_Lounge4_MapScripts:: @ 826358C
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman:: @ 826358D
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook:: @ 8263596
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man:: @ 826359F
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring: @ 82635A8
	.string "I wonder if they'll be airing interviews\n"
	.string "with tough TRAINERS today?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere: @ 82635EC
	.string "If I opened a restaurant here,\n"
	.string "it'd make money for sure.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles: @ 8263625
	.string "Whew…\p"
	.string "I need to take a breather after\n"
	.string "some intense battles…\p"
	.string "But even now, I never take a break\n"
	.string "from plotting strategy and combos.$"

