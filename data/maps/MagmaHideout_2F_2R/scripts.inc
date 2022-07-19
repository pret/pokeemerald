MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Je n’ai rien contre toi…\n"
	.string "Mais je dois suivre les ordres!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "C’est une défaite, mais…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "On a déterré quelque chose\n"
	.string "d’incroyable! Et on a l’ORBE BLEU!\p"
	.string "Notre leader n’a plus qu’à…\n"
	.string "Wahahah…$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Je ne supporte pas la chaleur…\n"
	.string "Je ferais peut-être mieux de rejoindre\l"
	.string "la TEAM AQUA…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Oui, je ne suis vraiment pas fait pour\n"
	.string "être dans la TEAM MAGMA!$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "La mer ne te manque pas dans un\n"
	.string "endroit comme ça?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "On entend quelquefois des grondements\n"
	.string "sourds par ici.\p"
	.string "Serait-ce le volcan? Ou bien serait-ce\n"
	.string "GROU…\p"
	.string "Oups!\n"
	.string "Oublie ce que je viens de dire!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Ça a été chaud!\n"
	.string "Presque aussi chaud qu’un volcan!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Tu as gagné contre moi, mais\n"
	.string "ça n’a pas vraiment d’importance.\p"
	.string "La TEAM MAGMA est sur le point de\n"
	.string "toucher son but!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un de nos sbires est très inquiet\n"
	.string "d’avoir perdu le SCEAU MAGMA…\p"
	.string "Attends un peu!\n"
	.string "Ça ne serait pas toi qui…?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "J’peux pas le croire…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "J’ai cette étrange impression que\n"
	.string "notre plan va échouer…$"

