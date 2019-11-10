MtPyre_5F_MapScripts:: @ 8231C6D
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha:: @ 8231C6E
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro: @ 8231C85
	.string "I love all things horrifying…\n"
	.string "It's like a disease…\p"
	.string "When I'm here…\n"
	.string "I shiver with fear…$"

MtPyre_4F_Text_TashaDefeat: @ 8231CDB
	.string "Losing, I dislike…$"

MtPyre_4F_Text_TashaPostBattle: @ 8231CEE
	.string "I want to see dreadful things…\n"
	.string "I can't leave…\p"
	.string "Stay…\n"
	.string "Won't you stay with me?$"

