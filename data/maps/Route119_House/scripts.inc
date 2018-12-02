Route119_House_MapScripts:: @ 8270965
	.byte 0

Route119_House_EventScript_270966:: @ 8270966
	msgbox Route119_House_Text_270982, MSGBOX_NPC
	end

Route119_House_EventScript_27096F:: @ 827096F
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route119_House_Text_270A17, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_270982: @ 8270982
	.string "I heard about a cave called the CAVE\n"
	.string "OF ORIGIN.\p"
	.string "People rumor that the spirits of\n"
	.string "POKéMON are revived there. Could\l"
	.string "something like that really happen?$"

Route119_House_Text_270A17: @ 8270A17
	.string "WINGULL: Pihyoh!$"

