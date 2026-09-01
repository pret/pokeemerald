FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "We've had a great and powerful\n"
	.string "TRAINER grow up on this island.\p"
	.string "I bet even you'd know her.\n"
	.string "It's LORELEI of the ELITE FOUR!\p"
	.string "When LORELEI was just a tyke,\n"
	.string "I taught her about POKéMON.$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "The SEVII ISLANDS are in a warm\n"
	.string "region overall.\p"
	.string "But there is one exception you\n"
	.string "need to know about.\p"
	.string "The ICEFALL CAVE is frigid because\n"
	.string "of the POKéMON that live in it.$"

