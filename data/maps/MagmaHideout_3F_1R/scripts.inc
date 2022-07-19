MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Qu’est-ce que j’ai fait de mal pour\n"
	.string "être obligé de monter la garde ici?\p"
	.string "Mon oreille gauche est presque\n"
	.string "en train de brûler!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Je dois avoir des bouffées de chaleur…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Tu trouves pas ça bizarre qu’on porte\n"
	.string "des bonnets dans cette fournaise?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Nous avons rejoint la TEAM pour aider\n"
	.string "notre leader à concrétiser sa vision.\p"
	.string "Je me moque que tu appartiennes\n"
	.string "ou non à la TEAM AQUA.\p"
	.string "Je ne laisserai personne interférer\n"
	.string "dans nos plans!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh non…\n"
	.string "Je n’ai rien pu faire.$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Ecoute-moi bien.\n"
	.string "Ne te trompe pas d’ennemi.\p"
	.string "N’écoute pas la TEAM AQUA.\n"
	.string "Ne crois pas leurs mensonges!$"

