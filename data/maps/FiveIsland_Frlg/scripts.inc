FiveIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	end

FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_Text_IslandSign::
	.string "FIVE ISLAND\n"
	.string "Chrono Island: Where Time Goes$"

FiveIsland_Text_WeirdBuildingInMeadow::
	.string "Oh, this stinks. I wanted to play in\n"
	.string "the MEADOW.\p"
	.string "But they put up a weird building\n"
	.string "on it, so I can't play there.$"

FiveIsland_Text_BeenGettingBusierAroundHere::
	.string "It's been getting busier around\n"
	.string "these parts lately.\p"
	.string "I haven't been catching many good\n"
	.string "fish lately, either.$"

