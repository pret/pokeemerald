MagmaHideout_2F_2R_MapScripts:: @ 8239E07
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt52:: @ 8239E08
	trainerbattle_single TRAINER_GRUNT_52, MagmaHideout_2F_2R_Text_Grunt52Intro, MagmaHideout_2F_2R_Text_Grunt52Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt52PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt43:: @ 8239E1F
	trainerbattle_single TRAINER_GRUNT_43, MagmaHideout_2F_2R_Text_Grunt43Intro, MagmaHideout_2F_2R_Text_Grunt43Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt43PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt44:: @ 8239E36
	trainerbattle_single TRAINER_GRUNT_44, MagmaHideout_2F_2R_Text_Grunt44Intro, MagmaHideout_2F_2R_Text_Grunt44Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt44PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt45:: @ 8239E4D
	trainerbattle_single TRAINER_GRUNT_45, MagmaHideout_2F_2R_Text_Grunt45Intro, MagmaHideout_2F_2R_Text_Grunt45Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt45PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt52Intro: @ 8239E64
	.string "I don't have a bone to pick with you.\n"
	.string "I'm just following orders!$"

MagmaHideout_2F_2R_Text_Grunt52Defeat: @ 8239EA5
	.string "I may have lost, but…$"

MagmaHideout_2F_2R_Text_Grunt52PostBattle: @ 8239EBB
	.string "We dug up something beyond belief!\n"
	.string "And, we got the BLUE ORB!\p"
	.string "All that's left is for our leader to…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt43Intro: @ 8239F31
	.string "I can't stand heat. Maybe I should've\n"
	.string "joined TEAM AQUA instead…$"

MagmaHideout_2F_2R_Text_Grunt43Defeat: @ 8239F71
	.string "Yeah, I really may not be right for\n"
	.string "TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt43PostBattle: @ 8239FA1
	.string "Don't you get lonely for the sea\n"
	.string "being in a place like this?$"

MagmaHideout_2F_2R_Text_Grunt44Intro: @ 8239FDE
	.string "You can hear tremors here sometimes.\p"
	.string "Could it be the volcano rattling?\n"
	.string "Or is it GROU…\p"
	.string "Whoops!\n"
	.string "No, no, never mind!$"

MagmaHideout_2F_2R_Text_Grunt44Defeat: @ 823A050
	.string "You're a fiery battler.\n"
	.string "Just like a volcano!$"

MagmaHideout_2F_2R_Text_Grunt44PostBattle: @ 823A07D
	.string "You just happened to win this time,\n"
	.string "but that doesn't matter.\p"
	.string "TEAM MAGMA's goal is about to be\n"
	.string "reached!$"

MagmaHideout_2F_2R_Text_Grunt45Intro: @ 823A0E4
	.string "One of our guys was freaking out that\n"
	.string "he lost his MAGMA EMBLEM…\p"
	.string "Wait a minute!\n"
	.string "Was it you who found it?$"

MagmaHideout_2F_2R_Text_Grunt45Defeat: @ 823A14C
	.string "I'm having trouble believing this…$"

MagmaHideout_2F_2R_Text_Grunt45PostBattle: @ 823A16F
	.string "I'm getting this feeling that our plan\n"
	.string "is going to end in failure…$"

