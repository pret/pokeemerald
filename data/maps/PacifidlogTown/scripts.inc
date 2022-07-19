PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Le courant de la mer entre PACIFIVILLE\n"
	.string "et POIVRESSEL est très fort.\p"
	.string "Si tu décidais de faire du SURF,\n"
	.string "tu pourrais te faire emporter et\l"
	.string "te retrouver très loin d’ici.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Regarde comme c’est chouette!\n"
	.string "Ces maisons sont construites sur l’eau.\p"
	.string "Je suis né ici!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "LE PILIER CELESTE?\p"
	.string "Oh, tu veux sûrement parler de cette\n"
	.string "très très grande tour un peu plus loin.\p"
	.string "Si tu veux mon avis, il faut être fou\n"
	.string "pour vouloir monter si haut!\p"
	.string "Vivre au niveau de la mer, ici à\n"
	.string "PACIFIVILLE, voilà ce qui me va!$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIVILLE\p"
	.string "“Là où le soleil du matin se reflète\n"
	.string "sur les eaux.”$"

