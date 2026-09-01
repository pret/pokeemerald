SSAnne_1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
	.string "You insolent pup!\n"
	.string "How dare you barge in!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
	.string "Humph! You rude child!\n"
	.string "You have no sense of courtesy!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
	.string "I wish to be left alone!\n"
	.string "Get out!$"

