FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "De boomhuizen van FORTREE zijn top!\p"
	.string "Volgens mij is dit de beste stad\n"
	.string "om samen met POKéMON te wonen.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON en mensen passen zich aan\n"
	.string "de natuur aan om te overleven.\p"
	.string "Je hoeft de natuur niet te\n"
	.string "veranderen om zo te leven.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"

