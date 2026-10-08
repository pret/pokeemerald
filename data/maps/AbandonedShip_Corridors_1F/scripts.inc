AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Wat is er zo grappig aan een\n"
	.string "zwemband op een schip?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Wauw, jij bent te sterk!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Het is niet makkelijk om POKé BALLS\n"
	.string "te gooien met een zwemband om!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Is het hier niet leuk?\n"
	.string "Ik word er helemaal blij van!$"
