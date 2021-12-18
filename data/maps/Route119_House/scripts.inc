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
	.string "I heard about a cave called the Cave\n"
	.string "of Origin.\p"
	.string "People rumor that the spirits of\n"
	.string "Pokémon are revived there. Could\l"
	.string "something like that really happen?$"

Route119_House_Text_Wingull:
	.string "Wingull: Pihyoh!$"

