SeafloorCavern_Room1_MapScripts:: @ 82347EB
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt5:: @ 82347EC
	trainerbattle_single TRAINER_GRUNT_5, SeafloorCavern_Room1_Text_Grunt5Intro, SeafloorCavern_Room1_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt6:: @ 8234803
	trainerbattle_single TRAINER_GRUNT_6, SeafloorCavern_Room1_Text_Grunt6Intro, SeafloorCavern_Room1_Text_Grunt6Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt5Intro: @ 823481A
	.string "We don't need a kid around!\n"
	.string "Go on home already!$"

SeafloorCavern_Room1_Text_Grunt5Defeat: @ 823484A
	.string "I want to go home…$"

SeafloorCavern_Room1_Text_Grunt5PostBattle: @ 823485D
	.string "I want to get a promotion so I can\n"
	.string "boss around the GRUNTS…$"

SeafloorCavern_Room1_Text_Grunt6Intro: @ 8234898
	.string "That submarine… It's tiny inside.\n"
	.string "I'm sore all over!$"

SeafloorCavern_Room1_Text_Grunt6Defeat: @ 82348CD
	.string "Losing makes me sore!$"

SeafloorCavern_Room1_Text_Grunt6PostBattle: @ 82348E3
	.string "That submarine we jacked, man,\n"
	.string "it's brutal as a ride.\l"
	.string "It's way too tight in there!$"

