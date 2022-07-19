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
	.string "On s’entraîne tous ensemble, avec\n"
	.string "les membres de ma famille!\p"
	.string "Je ne perds contre personne!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Tu as un meilleur niveau que ma famille?!\n"
	.string "Est-ce possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "J’ai toujours été le meilleur de la\n"
	.string "famille. Je n’avais encore jamais perdu…\p"
	.string "J’ai perdu confiance en moi…\n"
	.string "Je vais peut-être rentrer chez moi…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "On m’avait dit qu’il y avait un môme\n"
	.string "très fort. C’est de toi qu’ils parlaient?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "La demi-portion est forte!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "D’après les rumeurs, le p’tit môme\n"
	.string "très fort viendrait de CLEMENTI-VILLE.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Tu dois commencer à fatiguer.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Aucun signe de fatigue du tout!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "La ROUTE VICTOIRE et la LIGUE POKéMON\n"
	.string "sont des défis épuisants et de longue\l"
	.string "haleine. Gare à la fatigue!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Avoir beaucoup de BADGES ne suffit pas.\p"
	.string "Il y aura toujours quelqu’un de plus\n"
	.string "fort que toi!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Tu as un meilleur niveau que moi!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Regarde bien tes BADGES et rappelle-\n"
	.string "toi quels DRESSEURS tu as affrontés.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Je suis arrivé jusqu’ici, mais le stress\n"
	.string "me donne des maux d’estomac…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Oooh…\n"
	.string "Ça fait mal…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Je ne peux pas m’empêcher de stresser\n"
	.string "en sachant que la LIGUE POKéMON\l"
	.string "est si proche.\p"
	.string "J’arrive à peine à me détendre.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L’élite de l’élite se réunit dans\n"
	.string "cette grotte.\p"
	.string "T’en penses quoi?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Pas une seule fausse note!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "T’as du cran, continue comme ça!$"

