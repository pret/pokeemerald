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
	.string "Ahahahaha!\p"
	.string "Comment t’as fait pour venir jusqu’ici\n"
	.string "sans sous-marin?\l"
	.string "Quel môme impressionnant!\p"
	.string "Mais… C’est pas pour autant qu’on va\n"
	.string "te laisser te mêler de nos affaires.\p"
	.string "Et j’voudrais avoir ma revanche pour\n"
	.string "ce qui s’est passé au CENTRE METEO…\p"
	.string "Je vais te faire goûter à la douleur!\n"
	.string "Tu ferais mieux de renoncer!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ouille!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Quelle puissance tu as!\p"
	.string "C’est vraiment dommage que tu ne\n"
	.string "sois pas membre de la TEAM AQUA.\p"
	.string "Tu aurais pu prendre du plaisir dans le\n"
	.string "fabuleux monde que notre CHEF nous\l"
	.string "a promis…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Pour réaliser notre rêve, nous avons\n"
	.string "besoin de la puissance des POKéMON.\p"
	.string "Mais il y a toujours des enquiquineurs\n"
	.string "comme toi qui utilisent leurs POKéMON\l"
	.string "pour contrecarrer nos plans!\p"
	.string "Rien ne se passe jamais comme prévu!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Graaah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Tu sais, nous ne remettons pas en\n"
	.string "question les motifs de notre CHEF.\p"
	.string "Mais tu es là, à vouloir stopper\n"
	.string "nos plans.\p"
	.string "Peut-être que…\n"
	.string "Tu dois avoir tes raisons…$"

