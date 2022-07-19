AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Quoi? Quoi? Qu’est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n’est pas là! Il est parti\n"
	.string "chercher quelque chose d’important!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d’aussi vital?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Qu… Quoi?\n"
	.string "Tu appartiens à la TEAM MAGMA?\p"
	.string "Il paraît que la TEAM MAGMA essaye\n"
	.string "de réveiller un POKéMON formidable\l"
	.string "dans leur PLANQUE.\p"
	.string "Mais où est-ce que cette PLANQUE\n"
	.string "peut bien se trouver?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Quoi? Quoi? Qu’est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n’est pas là! Il est parti\n"
	.string "piquer un sous-marin!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d’aussi vital?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Quoi? Quoi? Qu’est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n’est pas là!\n"
	.string "Il est sur le CHENAL 122, en direction\l"
	.string "du MONT MEMORIA!\p"
	.string "… …\n"
	.string "Où est-il allé au juste?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d’aussi vital?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Qu… Quoi?\n"
	.string "Tu appartiens à la TEAM MAGMA?\p"
	.string "Il paraît que la TEAM MAGMA veut\n"
	.string "attraper un POKéMON formidable\l"
	.string "au MONT CHIMNEE.\p"
	.string "Mais à quoi peut bien ressembler\n"
	.string "ce POKéMON?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Quoi? Quoi? Qu’est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n’est pas là! Il est parti\n"
	.string "en direction de POIVRESSEL!\p"
	.string "… …\n"
	.string "Où est-il allé au juste?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d’aussi vital?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayaya!\n"
	.string "Personnage louche repéré!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Arrrrg…\n"
	.string "J’ai perdu!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "J’ai perdu en essayant de défendre la\n"
	.string "TEAM, mais j’ai fait de mon mieux…$"

