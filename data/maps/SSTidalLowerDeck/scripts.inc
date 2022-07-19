SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrg! J’en ai plein le dos de nettoyer\n"
	.string "cet endroit gigantesque!\p"
	.string "C’est l’heure de la pause,\n"
	.string "battons-nous!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Hé, p’tit frère, j’ai perdu!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Nous sommes les FRERES PROPRETE!\p"
	.string "L’aîné répand le détergent et le\n"
	.string "benjamin frotte!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Nous sommes dans la cale du navire.\n"
	.string "Il y a beaucoup de place.\l"
	.string "Profitons-en pour faire un combat\l"
	.string "de POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Hé, grand frère, j’ai perdu!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Nous sommes les FRERES PROPRETE!\p"
	.string "L’aîné répand le détergent et le\n"
	.string "benjamin frotte!$"

