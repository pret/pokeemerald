MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Ik hou van alles wat eng is…\n"
	.string "Het is als een ziekte…\p"
	.string "Als ik hier ben…\n"
	.string "ril ik van angst…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Verliezen, vind ik niks…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Ik wil enge dingen zien…\n"
	.string "Ik kan niet weg…\p"
	.string "Blijf…\n"
	.string "Blijf je bij me?$"

