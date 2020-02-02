MtPyre_4F_MapScripts:: @ 8231BC8
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi:: @ 8231BC9
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro: @ 8231BE0
	.string "Teacher…\n"
	.string "Please watch over my progress!$"

MtPyre_5F_Text_AtsushiDefeat: @ 8231C08
	.string "Teacher…\n"
	.string "Please forgive me!$"

MtPyre_5F_Text_AtsushiPostBattle: @ 8231C24
	.string "Until I improve, my teacher, who rests\n"
	.string "here, will never find true peace…$"

