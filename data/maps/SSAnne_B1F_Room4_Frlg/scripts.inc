SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
	.string "You know what they say about\n"
	.string "sailors and battling!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
	.string "Right!\n"
	.string "Good battle, mate!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
	.string "Hahaha!\n"
	.string "Want to be a sailor, mate?$"

SSAnne_B1F_Room4_Text_DuncanIntro::
	.string "Come on, then!\n"
	.string "My sailor's pride is at stake!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "Your spirit sank me!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
	.string "Did you see the FISHING GURU in\n"
	.string "VERMILION CITY?$"

