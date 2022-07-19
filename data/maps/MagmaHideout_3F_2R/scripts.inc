MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Je suis d’accord avec tout ce que dit\n"
	.string "notre leader. Mais tu sais quoi?\p"
	.string "Faire des trucs comme exhumer\n"
	.string "un POKéMON super vieux et voler\l"
	.string "le METEORITE de quelqu’un…\p"
	.string "Je crois qu’on va peut-être un peu\n"
	.string "trop loin. T’es pas d’accord?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ouaip, je pense vraiment qu’on fait\n"
	.string "quelque chose de mal.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tu sais, perdre permet de prendre\n"
	.string "conscience de certaines choses.\p"
	.string "La prochaine fois que je verrai notre\n"
	.string "leader, je lui parlerai de ce que nous\l"
	.string "sommes en train de faire.$"

