VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Ik kom steeds dichter bij de\n"
	.string "POKéMON LEAGUE…\p"
	.string "Ik krijg plankenkoorts…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Ik kon niets doen…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "De POKéMON LEAGUE is weer ver\n"
	.string "weg… Wat een teleurstelling…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Om door de POKéMON LEAGUE te\n"
	.string "comen, heb je het vertrouwen van je\l"
	.string "POKéMON nodig.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Jullie band is gebouwd op\n"
	.string "stevig vertrouwen.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Door altijd samen te zijn groeit\n"
	.string "vertrouwen tussen POKéMON\l"
	.string "en TRAINERS.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Dit is niet het doel. Het is maar\n"
	.string "een plek op weg naar de POKéMON LEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Zo mag het!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Het komt vast goed!\n"
	.string "Je POKéMON willen allemaal gaan!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mijn POKéMON zijn kosmisch\n"
	.string "indrukwekkend!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Zo iemand als jij zag ik nog nooit.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Ook buiten gevechten voel ik\n"
	.string "ongelofelijke kracht van jou en\l"
	.string "jouw POKéMON komen.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Oké, niet gelijk boos worden!\n"
	.string "Relax, doe maar rustig aan!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Whoa!\n"
	.string "Prachtig!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Dit is wel de VICTORY ROAD.\p"
	.string "Maar het verschilt niet veel van\n"
	.string "de weg die je al liep.\p"
	.string "Genieten tot het einde!$"

