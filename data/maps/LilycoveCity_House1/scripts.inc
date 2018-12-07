LilycoveCity_House1_MapScripts:: @ 821ECCD
	.byte 0

LilycoveCity_House1_EventScript_21ECCE:: @ 821ECCE
	msgbox LilycoveCity_House1_Text_21ECEA, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_21ECD7:: @ 821ECD7
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, 0
	msgbox LilycoveCity_House1_Text_21ED63, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_21ECEA: @ 821ECEA
	.string "POKéMON are partners to people.\n"
	.string "They aren't our tools.\p"
	.string "Unfortunately, there are some people\n"
	.string "who fail to understand that…$"

LilycoveCity_House1_Text_21ED63: @ 821ED63
	.string "KECLEON: Ruroro?$"

