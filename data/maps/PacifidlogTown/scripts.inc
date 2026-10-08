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
	.string "De zee tussen PACIFIDLOG en\n"
	.string "SLATEPORT heeft een sterke stroming.\p"
	.string "Als je SURFEN gebruikt, word je\n"
	.string "misschien ergens anders heen gespoeld.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Gaaf, hè?\n"
	.string "Deze huizen staan op water!\p"
	.string "Ik ben hier geboren!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "De SKY PILLAR?\p"
	.string "…Oh, je bedoelt die hele hoge\n"
	.string "toren wat verderop.\p"
	.string "Ik zou er niet op klimmen.\n"
	.string "Het is te eng om zo hoog te gaan.\p"
	.string "Het leven op zeeniveau in PACIFIDLOG\n"
	.string "bevalt me prima.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Waar de ochtendzon lacht naar\n"
	.string "het water.”$"

