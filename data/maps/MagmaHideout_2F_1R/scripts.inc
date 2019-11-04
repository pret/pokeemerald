MagmaHideout_2F_1R_MapScripts:: @ 8239B50
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14:: @ 8239B51
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3:: @ 8239B68
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4:: @ 8239B7F
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5:: @ 8239B96
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro: @ 8239BAD
	.string "What, what, what?\p"
	.string "Only TEAM MAGMA members are supposed\n"
	.string "to be in here!\p"
	.string "But you're not dressed in TEAM MAGMA's\n"
	.string "uniform…\p"
	.string "You rouse my suspicion!\n"
	.string "Battle with me!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat: @ 8239C4B
	.string "Aiyiyi…\n"
	.string "My pride as a TEAM MAGMA member…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle: @ 8239C74
	.string "If you suffer from chills, you should\n"
	.string "join TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro: @ 8239CAB
	.string "Hold it right there!\p"
	.string "You don't really expect me to keep\n"
	.string "my trap shut and let you waltz by me?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat: @ 8239D09
	.string "Ooh wow!\n"
	.string "I concede!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle: @ 8239D1D
	.string "Maybe it would've been better if I did\n"
	.string "just let you go unchallenged…$"

MagmaHideout_2F_1R_Text_Grunt4Intro: @ 8239D62
	.string "Ahah!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat: @ 8239D75
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle: @ 8239D7D
	.string "I've already lost.\p"
	.string "Do I really need to keep running\n"
	.string "around in a circle?$"

MagmaHideout_2F_1R_Text_Grunt5Intro: @ 8239DC5
	.string "Oh, oh!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat: @ 8239DDA
	.string "Mutter…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle: @ 8239DE2
	.string "Actually, I'm no expert at battling…$"

