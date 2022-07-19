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
	.string "J’ai entendu parler d’une grotte\n"
	.string "appelée la GROTTE ORIGINE.\p"
	.string "Les gens racontent que les esprits des\n"
	.string "POKéMON y sont ranimés.\p"
	.string "C’est possible, une chose pareille?$"

Route119_House_Text_Wingull:
	.string "GOELISE: Liiise?$"

