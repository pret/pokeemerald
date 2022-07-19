MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Professeur…\n"
	.string "Regardez les progrès que j’ai faits!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Professeur…\n"
	.string "Pardonnez-moi!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Mon prof, qui repose ici, ne trouvera\n"
	.string "la paix que lorsque j’aurai progressé…$"

