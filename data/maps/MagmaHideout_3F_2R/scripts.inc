MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "I understand everything our leader\n"
	.string "says. But you know what?\p"
	.string "Doing stuff like digging up a super-\n"
	.string "ancient POKéMON and ripping off\l"
	.string "someone's METEORITE…\p"
	.string "I think we're going a little too far.\n"
	.string "What do you think?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Yeah, I think we are doing something\n"
	.string "wrong somehow.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "You know, losing to you cleared my mind.\p"
	.string "The next time I see our leader,\n"
	.string "I'm going to ask him about what we do.$"

