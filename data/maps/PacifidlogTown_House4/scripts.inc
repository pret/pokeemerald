PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Les gens racontent qu’ils ont vu un\n"
	.string "POKéMON VOLANT au-dessus de\l"
	.string "la région de HOENN.\p"
	.string "Est-ce qu’il vole tout le temps?\n"
	.string "Il doit bien se reposer, non?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Un POKéMON ciel!\n"
	.string "Un POKéMON ciel!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "D’où viens-tu?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Oui?\n"
	.string "OUI VILLE?\p"
	.string "Je n’ai jamais entendu parler de\n"
	.string "cet endroit.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Non? Mais c’est n’importe quoi.\n"
	.string "Tu dois bien venir de quelque part.\p"
	.string "Oh! Attends! Tu ne vas pas me dire que\n"
	.string "tu viens du fond de l’océan?$"

