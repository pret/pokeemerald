LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Ma femme tente de faire éclore un OEUF\n"
	.string "dans les sources chaudes. Elle\l"
	.string "vient de me le dire.\p"
	.string "Elle a laissé deux POKéMON à la PENSION.\n"
	.string "Et ils ont découvert cet OEUF!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZATON: Zigzaaa!$"

