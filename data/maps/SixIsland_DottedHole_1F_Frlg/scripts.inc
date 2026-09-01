SixIsland_DottedHole_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_DottedHole_1F_OnTransition
	.byte 0

SixIsland_DottedHole_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F
	end

SixIsland_DottedHole_B1F_EventScript_BrailleUp::
	lockall
	braillemsgbox Braille_Text_Up
	releaseall
	end

SixIsland_DottedHole_B4F_EventScript_BrailleDown::
	lockall
	braillemsgbox Braille_Text_Down
	releaseall
	end

SixIsland_DottedHole_B3F_EventScript_BrailleRight::
	lockall
	braillemsgbox Braille_Text_Right
	releaseall
	end

SixIsland_DottedHole_B2F_EventScript_BrailleLeft::
	lockall
	braillemsgbox Braille_Text_Left
	releaseall
	end
