SeafloorCavern_Room1_MapScripts:: @ 82347EB
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1:: @ 82347EC
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2:: @ 8234803
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro: @ 823481A
	.string "We don't need a kid around!\n"
	.string "Go on home already!$"

SeafloorCavern_Room1_Text_Grunt1Defeat: @ 823484A
	.string "I want to go home…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle: @ 823485D
	.string "I want to get a promotion so I can\n"
	.string "boss around the GRUNTS…$"

SeafloorCavern_Room1_Text_Grunt2Intro: @ 8234898
	.string "That submarine… It's tiny inside.\n"
	.string "I'm sore all over!$"

SeafloorCavern_Room1_Text_Grunt2Defeat: @ 82348CD
	.string "Losing makes me sore!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle: @ 82348E3
	.string "That submarine we jacked, man,\n"
	.string "it's brutal as a ride.\l"
	.string "It's way too tight in there!$"

