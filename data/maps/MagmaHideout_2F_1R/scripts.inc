MagmaHideout_2F_1R_MapScripts:: @ 8239B50
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt51:: @ 8239B51
	trainerbattle_single TRAINER_GRUNT_51, MagmaHideout_2F_1R_Text_Grunt51Intro, MagmaHideout_2F_1R_Text_Grunt51Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt51PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt40:: @ 8239B68
	trainerbattle_single TRAINER_GRUNT_40, MagmaHideout_2F_1R_Text_Grunt40Intro, MagmaHideout_2F_1R_Text_Grunt40Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt40PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt41:: @ 8239B7F
	trainerbattle_single TRAINER_GRUNT_41, MagmaHideout_2F_1R_Text_Grunt41Intro, MagmaHideout_2F_1R_Text_Grunt41Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt41PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt42:: @ 8239B96
	trainerbattle_single TRAINER_GRUNT_42, MagmaHideout_2F_1R_Text_Grunt42Intro, MagmaHideout_2F_1R_Text_Grunt42Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt42PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt51Intro: @ 8239BAD
	.string "What, what, what?\p"
	.string "Only TEAM MAGMA members are supposed\n"
	.string "to be in here!\p"
	.string "But you're not dressed in TEAM MAGMA's\n"
	.string "uniform…\p"
	.string "You rouse my suspicion!\n"
	.string "Battle with me!$"

MagmaHideout_2F_1R_Text_Grunt51Defeat: @ 8239C4B
	.string "Aiyiyi…\n"
	.string "My pride as a TEAM MAGMA member…$"

MagmaHideout_2F_1R_Text_Grunt51PostBattle: @ 8239C74
	.string "If you suffer from chills, you should\n"
	.string "join TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt40Intro: @ 8239CAB
	.string "Hold it right there!\p"
	.string "You don't really expect me to keep\n"
	.string "my trap shut and let you waltz by me?$"

MagmaHideout_2F_1R_Text_Grunt40Defeat: @ 8239D09
	.string "Ooh wow!\n"
	.string "I concede!$"

MagmaHideout_2F_1R_Text_Grunt40PostBattle: @ 8239D1D
	.string "Maybe it would've been better if I did\n"
	.string "just let you go unchallenged…$"

MagmaHideout_2F_1R_Text_Grunt41Intro: @ 8239D62
	.string "Ahah!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt41Defeat: @ 8239D75
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt41PostBattle: @ 8239D7D
	.string "I've already lost.\p"
	.string "Do I really need to keep running\n"
	.string "around in a circle?$"

MagmaHideout_2F_1R_Text_Grunt42Intro: @ 8239DC5
	.string "Oh, oh!\n"
	.string "An intruder!$"

MagmaHideout_2F_1R_Text_Grunt42Defeat: @ 8239DDA
	.string "Mutter…$"

MagmaHideout_2F_1R_Text_Grunt42PostBattle: @ 8239DE2
	.string "Actually, I'm no expert at battling…$"

