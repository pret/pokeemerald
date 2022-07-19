SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "Un volcan immergé est entré en éruption\n"
	.string "et remonté des profondeurs marines.\p"
	.string "Son cratère a émergé de la mer et\n"
	.string "s’est rempli d’eau de pluie.\p"
	.string "C’est ainsi que la ville d’ATALANOPOLIS\n"
	.string "a été créée.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "La grotte qui relie ATALANOPOLIS au\n"
	.string "monde extérieur…\p"
	.string "C’est comme si elle avait été créée\n"
	.string "pour empêcher quelque chose de sortir.\p"
	.string "Ou s’agit-il juste de mon imagination?$"

