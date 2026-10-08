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
	.string "Arrrgh! Ik ben het spuugzat om dit\n"
	.string "enorme schip schoon te maken!\p"
	.string "Laten we snel vechten!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Broertje, ik heb verloren!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Wij zijn de POETSBROERS!\p"
	.string "De oudste gooit de zeep,\n"
	.string "en de jongste doet het schrobben!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Dit is de bodem van het schip.\n"
	.string "Er is hier genoeg ruimte.\l"
	.string "Prima voor een POKéMON-gevecht.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Grote broer, ik heb verloren!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Wij zijn de POETSBROERS!\p"
	.string "De oudste gooit de zeep,\n"
	.string "en de jongste doet het schrobben!$"

