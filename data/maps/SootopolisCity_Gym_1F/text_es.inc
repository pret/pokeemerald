
SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Eh, ¿cómo lo llevas, {PLAYER}?\n"
	.string "¿Camino del CAMPEONATO?\p"
	.string "GALANO, el LÍDER del GIMNASIO\n"
	.string "de ARRECÍPOLIS es un maestro\l"
	.string "de los POKéMON de tipo AGUA.\p"
	.string "Y, si quieres llegar hasta GALANO,\n"
	.string "tendrás que superar un suelo helado.\p"
	.string "Lo siento, pero no puedo decirte más.\p"
	.string "¡El resto tendrás que descubrirlo tú!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "¡Guau! ¡Has vencido incluso a GALANO,\n"
	.string "que según dicen es el mejor de HOENN!\p"
	.string "Muy bien, comprueba tu FICHA\n"
	.string "de ENTRENADOR.\p"
	.string "Si tienes todas las MEDALLAS, puedes\n"
	.string "aceptar el desafío de la LIGA POKéMON.$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Quisiera explicarte algo.\n"
	.string "No sé si sabrás…\l"
	.string "Uf, no sé por qué me da corte…\p"
	.string "Verás, yo enseñé a PLUBIO todo lo que\n"
	.string "se puede saber sobre los POKéMON.\p"
	.string "Cuando acabé, renuncié a mi puesto\n"
	.string "como LÍDER de GIMNASIO.\p"
	.string "Decidí confiar esa responsabilidad\n"
	.string "a PLUBIO.\p"
	.string "Sin embargo, retomé mi puesto\n"
	.string "por una razón de peso…\p"
	.string "Pero ya basta de charlas…\n"
	.string "Deberíamos luchar, ¿no?\p"
	.string "Quisiera que fueras testigo\n"
	.string "de nuestra maestría.\p"
	.string "¡Mis POKéMON y yo hemos\n"
	.string "creado una gran ilusión acuática!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "¡Ja, ja, ja! ¡Magnífico!\n"
	.string "La victoria es tuya.\p"
	.string "Tengo el presentimiento de que\n"
	.string "tu destreza te llevará a lo más alto.\p"
	.string "No obstante, en comparación conmigo\n"
	.string "o PLUBIO, te falta elegancia.\p"
	.string "Puede que sea una buena idea\n"
	.string "prestarte mi traje…\p"
	.string "¿Te lo presto?…\n"
	.string "¿No te lo presto? …\p"
	.string "¡Que no, que es broma!\p"
	.string "¡Te voy a dar algo mejor! ¡Aquí\n"
	.string "tienes la MEDALLA LLUVIA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} recibió la MEDALLA LLUVIA\n"
	.string "de GALANO.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "La MEDALLA LLUVIA te concede la\n"
	.string "obediencia total de todos tus POKéMON\l"
	.string "a cada una de tus órdenes.\p"
	.string "También te permite usar el movimiento\n"
	.string "de la MO CASCADA, que hace posible\l"
	.string "que subas por cualquier catarata.\p"
	.string "Y, además, para que nunca olvides\n"
	.string "nuestro combate, toma esto…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MT que te he dado contiene\n"
	.string "HIDROPULSO.\p"
	.string "Lanza ondas ultrasónicas que pueden\n"
	.string "confundir a tu rival.\p"
	.string "Es una pasada…$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Acabas de registrar a GALANO,\n"
	.string "el LÍDER de GIMNASIO, en el POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Los ENTRENADORES que han reunido\n"
	.string "todas las MEDALLAS de GIMNASIO\l"
	.string "de HOENN deben dar el siguiente paso…\p"
	.string "¡La LIGA POKéMON!\p"
	.string "Viaja al extremo oriental de HOENN,\n"
	.string "a la isla de COLOSALIA.\l"
	.string "La LIGA POKéMON está allí.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Sólo te queda una MEDALLA\n"
	.string "por obtener en HOENN.\p"
	.string "Si quieres llegar hasta la LIGA\n"
	.string "POKéMON, debes conseguirla\l"
	.string "en el GIMNASIO de ARBORADA.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "GIMNASIO POKéMON de ARRECÍPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON de ARRECÍPOLIS\p"
	.string "NUEVOS ENTRENADORES CERTIFICADOS:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "GALANO: Ah, este GIMNASIO por fin\n"
	.string "ha vuelto a ser un oasis de serenidad…\p"
	.string "Pero nuestro pequeño maremoto\n"
	.string "ha regresado para ponernos a prueba.\p"
	.string "¡Será un placer darte satisfacción!\p"
	.string "¡Estaré dispuesto a enfrentarme\n"
	.string "a ti todas las veces que quieras!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "¡Ja, ja, ja! La victoria es tuya.\n"
	.string "¡Me has derrotado una vez más!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "GALANO: Si te propusiera que fueras\n"
	.string "mi aprendiz, te negarías, lo sé.\p"
	.string "Quisiera ofrecerte mi abrigo\n"
	.string "como regalo.\p"
	.string "Pero también lo rechazarías,\n"
	.string "estoy convencido.\p"
	.string "¡Y eso, sin duda, demuestra\n"
	.string "la nobleza de tu carácter!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "GALANO: Ah, este GIMNASIO por fin\n"
	.string "ha vuelto a ser un oasis de serenidad…\p"
	.string "Pero nuestro pequeño maremoto\n"
	.string "ha regresado para ponernos a prueba.\p"
	.string "¡Será un placer darte satisfacción!\p"
	.string "Pero no, no, no. Ni hablar.\n"
	.string "Sólo tienes un POKéMON.\p"
	.string "Te agradecería que regresaras\n"
	.string "con dos o incluso más POKéMON.$"
