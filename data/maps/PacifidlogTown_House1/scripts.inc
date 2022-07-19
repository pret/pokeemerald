PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Dans la région de HOENN, il existe trois\n"
	.string "POKéMON qui symbolisent la puissance\l"
	.string "de la pierre, de la glace et de l’acier.\p"
	.string "On raconte qu’ils se cachent dans\n"
	.string "des grottes obscures.\p"
	.string "C’est une histoire que j’ai entendue\n"
	.string "quand j’étais petit.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Six points ouvrent trois portes.”\p"
	.string "Pépé disait souvent ça, mais je ne sais\n"
	.string "pas ce que ça veut dire.$"

