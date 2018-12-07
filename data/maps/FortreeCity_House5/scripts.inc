FortreeCity_House5_MapScripts:: @ 8217EF1
	.byte 0

FortreeCity_House5_EventScript_217EF2:: @ 8217EF2
	msgbox FortreeCity_House5_Text_217F17, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_217EFB:: @ 8217EFB
	msgbox FortreeCity_House5_Text_217F80, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_217F04:: @ 8217F04
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox FortreeCity_House5_Text_217FFB, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_217F17: @ 8217F17
	.string "The tree houses of FORTREE are great!\p"
	.string "I think it's the number one town for\n"
	.string "living together with POKéMON.$"

FortreeCity_House5_Text_217F80: @ 8217F80
	.string "POKéMON and people have adapted to\n"
	.string "nature for survival.\p"
	.string "There's no need to make nature\n"
	.string "conform to the way we want to live.$"

FortreeCity_House5_Text_217FFB: @ 8217FFB
	.string "ZIGZAGOON: Bufuu!$"

