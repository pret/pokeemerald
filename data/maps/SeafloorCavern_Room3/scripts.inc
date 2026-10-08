SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Hahahaha!\p"
	.string "Hoe ben je hier zonder duikboot\n"
	.string "gekomen?\l"
	.string "Wat een indrukwekkend kind!\p"
	.string "Maar… Je mag hier niet\n"
	.string "rondsnuffelen.\p"
	.string "En ik wil wraak voor wat er\n"
	.string "bij het WEATHER INSTITUTE gebeurde…\p"
	.string "Ik geef je een proefje van pijn!\n"
	.string "Bereid je maar voor!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Hahahaha!\p"
	.string "Au!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Hahahaha!\n"
	.string "Wat ben jij sterk.\p"
	.string "Het is jammer dat je niet bij\n"
	.string "TEAM AQUA zit.\p"
	.string "Je had kunnen genieten van de\n"
	.string "prachtige wereld die onze BAAS\l"
	.string "belooft, als een van ons…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Voor onze droom hebben we de kracht\n"
	.string "van POKéMON nodig.\p"
	.string "Maar bemoeials zoals jij gebruiken\n"
	.string "POKéMON-kracht om ons dwars te\l"
	.string "zitten, zelfs hier!\p"
	.string "Het leven gaat niet zoals wij\n"
	.string "het nodig hebben!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Weet je, wij durven de plannen\n"
	.string "van onze leider niet te betwijfelen.\p"
	.string "Maar jij, een straatschender,\n"
	.string "gaat tegen onze BAAS in.\p"
	.string "Misschien…\n"
	.string "Ben jij wel iets bijzonders…$"

