
SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "JUAN, le CHAMPION d’ATALANOPOLIS est\n"
	.string "le spécialiste des POKéMON du type EAU.\p"
	.string "Mais pour le rencontrer, il te faudra\n"
	.string "réussir à avancer sur un sol gelé…\p"
	.string "Ecoute, je suis désolé, mais c’est tout\n"
	.string "ce que je peux te dire.\p"
	.string "Pour le reste, il va falloir que tu\n"
	.string "te débrouilles!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Waouh! Tu as même battu JUAN, censé\n"
	.string "être le meilleur de tout HOENN!\p"
	.string "OK! Regarde ta CARTE DRESSEUR.\p"
	.string "Si tu as tous les BADGES, tu vas pouvoir\n"
	.string "relever le défi de la LIGUE POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Laissez-moi vous demander.\n"
	.string "Saviez-vous que…\l"
	.string "Ah, je ne devrais point être si timide.\p"
	.string "Saviez-vous que j’ai appris à MARC\n"
	.string "tout ce qu’il sait sur les POKéMON?\p"
	.string "J’étais autrefois le CHAMPION de cette\n"
	.string "magnifique ARENE.\p"
	.string "Cependant, un concours de\n"
	.string "circonstances m’a forcé à revenir.\p"
	.string "Mais assez palabré.\n"
	.string "Nous devrions commencer notre\l"
	.string "match, ne pensez-vous pas?\p"
	.string "Préparez-vous à assister à une\n"
	.string "véritable démonstration de talent.\p"
	.string "Une œuvre sur le thème de l’eau\n"
	.string "composée par mes POKéMON et moi.$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ah ah ah, excellent!\n"
	.string "Très bien, la victoire est à vous.\p"
	.string "Je sens en vous l’existence d’une force\n"
	.string "qui vous permettra de surmonter les\l"
	.string "épreuves qui vous attendent.\p"
	.string "Cependant, si je vous compare à MARC\n"
	.string "ou bien à moi-même, je peux dire\l"
	.string "que vous manquez encore d’élégance.\p"
	.string "Peut-être devrais-je vous prêter\n"
	.string "mon habit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ah ah ah, je ne fais que me moquer!\p"
	.string "Plutôt que ma veste, je vous prie\n"
	.string "d’accepter ce BADGE PLUIE.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} reçoit le BADGE PLUIE\n"
	.string "de la part de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avec ce BADGE, tous vos POKéMON\n"
	.string "vous obéiront et feront tout ce que\l"
	.string "vous leur demanderez.\p"
	.string "Ce BADGE permet aussi d’utiliser la\n"
	.string "capacité CS CASCADE pour passer\l"
	.string "les chutes d’eau.\p"
	.string "Et pour que vous n’oubliiez jamais notre\n"
	.string "combat, prenez ceci…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La CT que je vous ai donnée\n"
	.string "contient VIBRAQUA.\p"
	.string "Avec ses vagues d’ultrasons,\n"
	.string "elle vous permettra parfois de rendre\l"
	.string "vos ennemis confus.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE JUAN dans le POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont rassemblé tous\n"
	.string "les BADGES de HOENN doivent faire\l"
	.string "route vers la destination ultime.\p"
	.string "La LIGUE POKéMON!\p"
	.string "Dirigez-vous vers la zone la plus à l’est\n"
	.string "de HOENN, jusqu’à l’île d’ETERNARA.\p"
	.string "La LIGUE POKéMON se trouve là-bas.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Mais il te reste encore un BADGE à\n"
	.string "obtenir à HOENN.\p"
	.string "Si tu veux affronter la LIGUE POKéMON,\n"
	.string "il te faut obtenir ce dernier BADGE du\l"
	.string "CHAMPION D’ARENE de CIMETRONELLE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARENE POKéMON d’ATALANOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ARENE POKéMON d’ATALANOPOLIS\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, cette ARENE avait enfin\n"
	.string "retrouvé toute sa sérénité…\p"
	.string "Mais le cataclysme que vous êtes est\n"
	.string "de retour pour nous tester de nouveau!\p"
	.string "Eh bien j’accepte votre défi avec joie!\p"
	.string "Je serai ravi de vous affronter aussi\n"
	.string "souvent que vous le souhaitez!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, vous remportez la victoire!\n"
	.string "Vous m’avez de nouveau vaincu!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Si je vous demandais de devenir\n"
	.string "mon élève, vous refuseriez, \l"
	.string "j’en suis certain.\p"
	.string "Je voudrais vous faire don de ma\n"
	.string "veste.\p"
	.string "Mais comme je l’imagine, vous la\n"
	.string "refuseriez de la même façon.\p"
	.string "Et cela, jeune DRESSEUR, est un\n"
	.string "signe certain de noblesse!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, cette ARENE avait enfin\n"
	.string "retrouvé toute sa sérénité…\p"
	.string "Mais le cataclysme que vous êtes est\n"
	.string "de retour pour nous tester de nouveau!\p"
	.string "Eh bien j’accepte votre défi avec joie!\p"
	.string "Ah, mais cessez cela!\n"
	.string "Vous n’avez qu’un POKéMON.\p"
	.string "Je souhaiterais que vous reveniez\n"
	.string "avec au moins deux POKéMON.$"
