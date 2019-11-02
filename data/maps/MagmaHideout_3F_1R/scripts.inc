MagmaHideout_3F_1R_MapScripts:: @ 823A1B2
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt46:: @ 823A1B3
	trainerbattle_single TRAINER_GRUNT_46, MagmaHideout_3F_1R_Text_Grunt46Intro, MagmaHideout_3F_1R_Text_Grunt46Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt46PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt53:: @ 823A1CA
	trainerbattle_single TRAINER_GRUNT_53, MagmaHideout_3F_1R_Text_Grunt53Intro, MagmaHideout_3F_1R_Text_Grunt53Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt53PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt46Intro: @ 823A1E1
	.string "What did I do to deserve this guard\n"
	.string "posting?\p"
	.string "My left ear is burning up!$"

MagmaHideout_3F_1R_Text_Grunt46Defeat: @ 823A229
	.string "I'm getting heat exhaustion…$"

MagmaHideout_3F_1R_Text_Grunt46PostBattle: @ 823A246
	.string "Do you think it's odd that we're wearing\n"
	.string "hoods in this magma-filled volcano?$"

MagmaHideout_3F_1R_Text_Grunt53Intro: @ 823A293
	.string "We joined so we can help our leader\n"
	.string "achieve his fantastic vision.\p"
	.string "I don't care if you're with TEAM AQUA\n"
	.string "or if you're just some kid passing by.\p"
	.string "No one interferes with us and gets\n"
	.string "away with it!$"

MagmaHideout_3F_1R_Text_Grunt53Defeat: @ 823A353
	.string "Oh, no!\n"
	.string "You're not to be trusted at all!$"

MagmaHideout_3F_1R_Text_Grunt53PostBattle: @ 823A37C
	.string "Listen to me.\n"
	.string "TEAM MAGMA is right!\p"
	.string "Don't listen to TEAM AQUA.\n"
	.string "Don't believe their lies!$"

