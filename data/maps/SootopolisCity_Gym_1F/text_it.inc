
SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Ehi, come va giovane promessa,\n"
	.string "{PLAYER}?\p"
	.string "Il CAPOPALESTRA di CENERIDE,\n"
	.string "RODOLFO, è maestro dei POKéMON\l"
	.string "di tipo ACQUA.\p"
	.string "La strada per arrivare da RODOLFO\n"
	.string "è ghiacciata e cedevole…\p"
	.string "Mi dispiace, ma non ho altre\n"
	.string "dritte da darti.\p"
	.string "Il resto del cammino lo dovrai\n"
	.string "affrontare con le tue forze!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Wow! Hai battuto persino RODOLFO! È\n"
	.string "il migliore di tutta la regione di HOENN!\p"
	.string "Controlla la tua SCHEDA ALLENATORE!\p"
	.string "Se hai tutte le MEDAGLIE, puoi prendere\n"
	.string "parte alla sfida della LEGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Volevo chiederti una cosa.\n"
	.string "Sapevi che… ah, non dovrei essere\l"
	.string "così timido.\p"
	.string "Sono stato io ad insegnare ad ADRIANO\n"
	.string "tutto ciò che c’è da sapere sui POKéMON.\p"
	.string "Tempo fa, ho rinunciato alla mia\n"
	.string "posizione di CAPOPALESTRA.\p"
	.string "Avevo affidato la carica di\n"
	.string "CAPOPALESTRA ad ADRIANO.\p"
	.string "Per una serie di circostanze\n"
	.string "sono dovuto tornare.\p"
	.string "Basta con le chiacchiere.\n"
	.string "Cominciamo la lotta, va bene?\p"
	.string "Preparati ad assistere a una vera e\n"
	.string "propria dimostrazione di talento.\p"
	.string "Un’opera d’arte eseguita nell’acqua da\n"
	.string "me e dalla mia squadra di POKéMON!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahah! Eccellente!\n"
	.string "Bene, hai vinto!\p"
	.string "Intravedo in te una forza prorompente\n"
	.string "che ti permetterà di superare tutte le\l"
	.string "prove che ti attendono.\p"
	.string "Tuttavia, rispetto ad ADRIANO e a me\n"
	.string "ti manca l’eleganza.\p"
	.string "Vuoi che ti presti i miei vestiti?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ahahah, stavo scherzando!\p"
	.string "Invece dei vestiti, ti darò\n"
	.string "la MEDAGLIA PIOGGIA.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIOGGIA\n"
	.string "da RODOLFO.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Con questa MEDAGLIA tutti i tuoi\n"
	.string "POKéMON obbediranno a ogni\l"
	.string "tuo comando.\p"
	.string "La MEDAGLIA ti permetterà, inoltre,\n"
	.string "di usare la mossa MN CASCATA\l"
	.string "per risalire le cascate d’acqua.\p"
	.string "Accetta questo in ricordo\n"
	.string "della nostra sfida…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MACCHINA TECNICA che ti porgo\n"
	.string "contiene IDROPULSAR.\p"
	.string "Nelle sfide, può confondere\n"
	.string "l’avversario con onde ad ultrasuoni.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "RODOLFO nel POKéNAV avvenuta.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Gli ALLENATORI con tutte le MEDAGLIE\n"
	.string "della regione di HOENN possono incammi-\l"
	.string "narsi verso la destinazione finale.\p"
	.string "La LEGA POKéMON.\p"
	.string "Fai rotta verso le estremità orientali\n"
	.string "della regione di HOENN. La LEGA POKéMON\l"
	.string "si trova sull’isola di IRIDOPOLI.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Ti è rimasta ancora una MEDAGLIA da\n"
	.string "ottenere nella regione di HOENN.\p"
	.string "Se vuoi sfidare la LEGA POKéMON,\n"
	.string "devi ottenere l’ultima MEDAGLIA\l"
	.string "nella PALESTRA di FORESTOPOLI.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "PALESTRA POKéMON di CENERIDE$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di CENERIDE\p"
	.string "ALLENATORE CERTIFICATO da RODOLFO:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "RODOLFO: Questa PALESTRA aveva\n"
	.string "ritrovato la pace di sempre…\p"
	.string "ma il nostro piccolo tifone è ritornato\n"
	.string "per metterci nuovamente alla prova!\p"
	.string "Va bene, accetto!\p"
	.string "Sarò lieto di danzare con te ogni\n"
	.string "volta che lo vorrai!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahah, hai vinto!\n"
	.string "Mi hai sconfitto ancora!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "RODOLFO: Sono sicuro che non\n"
	.string "accetteresti che io diventassi\l"
	.string "il tuo maestro.\p"
	.string "Vorrei regalarti il cappotto che\n"
	.string "indosso.\p"
	.string "Ma so che non accetteresti\n"
	.string "neppure questo.\p"
	.string "Questo è un segno di nobiltà\n"
	.string "d’animo!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "RODOLFO: Questa PALESTRA aveva\n"
	.string "ritrovato la pace di sempre…\p"
	.string "ma il nostro piccolo tifone è ritornato\n"
	.string "per metterci nuovamente alla prova!\p"
	.string "Va bene, accetto!\n"
	.string "Sarò lieto di danzare con te…\p"
	.string "Ah, no, non ci siamo.\n"
	.string "Hai soltanto un POKéMON.\p"
	.string "Mi farebbe piacere se ritornassi\n"
	.string "con due o più POKéMON.$"
