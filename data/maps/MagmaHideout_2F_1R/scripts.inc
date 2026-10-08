MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Wat, wat, wat?\p"
	.string "Hier mogen alleen leden van\n"
	.string "TEAM MAGMA zijn!\p"
	.string "Maar jij draagt het pak van\n"
	.string "TEAM MAGMA niet…\p"
	.string "Dat is verdacht!\n"
	.string "Vecht met me!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Mijn trots als lid van TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Heb je het vaak koud? Dan moet\n"
	.string "je bij TEAM MAGMA komen.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Stop daar!\p"
	.string "Je verwacht toch niet dat ik\n"
	.string "mijn mond hou en je laat gaan?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ooh wauw!\n"
	.string "Ik geef me over!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Misschien was het beter geweest\n"
	.string "om je gewoon te laten gaan…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Aha!\n"
	.string "Een indringer!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ik heb al verloren.\p"
	.string "Moet ik echt nog in cirkels\n"
	.string "blijven lopen?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Een indringer!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Mompel…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Eigenlijk ben ik niet zo goed\n"
	.string "in vechten…$"

