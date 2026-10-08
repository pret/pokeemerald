VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Ik trainde met mijn hele familie,\n"
	.string "allemaal!\l"
	.string "Ik verlies van niemand!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Beter dan mijn familie?!\n"
	.string "Is dat mogelijk?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Ik was beter dan iedereen in mijn\n"
	.string "familie. Ik verloor nog nooit…\p"
	.string "Ik ben mijn zelfvertrouwen kwijt…\n"
	.string "Misschien ga ik naar huis…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Ik hoorde dat er een stoer klein\n"
	.string "kind rondloopt. Ben jij dat?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Dat kleine ding is stoer!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Ik hoorde dat dat stoere kleine\n"
	.string "kind uit PETALBURG CITY komt.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Je wordt vast een beetje moe.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Helemaal geen teken van moeheid!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "VICTORY ROAD en de POKéMON LEAGUE\n"
	.string "zijn lange, slopende uitdagingen.\l"
	.string "Pas op voor vermoeidheid!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Word niet te zelfverzekerd omdat\n"
	.string "je veel GYM BADGES hebt.\p"
	.string "Er is altijd iemand die beter\n"
	.string "is dan jij!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Je bent beter dan ik!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Kijk naar je BADGES en denk\n"
	.string "aan de TRAINERS die je versloeg.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Ik ben zo ver gekomen, maar de\n"
	.string "spanning geeft me buikpijn…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh…\n"
	.string "Au…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Ik word zenuwachtig omdat ik de\n"
	.string "POKéMON LEAGUE nader.\p"
	.string "Ik doe maar alsof ik rustig ben.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "De besten van de besten komen\n"
	.string "in deze grot samen.\p"
	.string "Hoe vind je het?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Helemaal niet van slag!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Je hebt lef! Dat vind ik leuk!\n"
	.string "Blijf het doen!$"

