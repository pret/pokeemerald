AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_2379A5::
	msgbox AbandonedShip_Corridors_1F_Text_237A60, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_2379AE::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_2379C5, AbandonedShip_Corridors_1F_Text_237A01
	msgbox AbandonedShip_Corridors_1F_Text_237A1B, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_2379C5:
	.string "배 안에서\n"
	.string "튜브를 끼는 게 뭐가 그렇게 웃겨?$"

AbandonedShip_Corridors_1F_Text_237A01:
	.string "압도당했다...$"

AbandonedShip_Corridors_1F_Text_237A1B:
	.string "튜브를 끼고 있으면\n"
	.string "몬스터볼을 던지기 어려워$"

AbandonedShip_Corridors_1F_Text_237A60:
	.string "여긴 참 재미있구나!\n"
	.string "여기에 있는 것만으로도 두근거려!$"

