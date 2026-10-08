Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Ik hoorde over een grot, de CAVE\n"
	.string "OF ORIGIN.\p"
	.string "Men zegt dat de geesten van POKéMON\n"
	.string "daar terugkomen. Kan dat echt?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

