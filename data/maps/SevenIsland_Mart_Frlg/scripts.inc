SevenIsland_Mart_Frlg_MapScripts::
	.byte 0

SevenIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SevenIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SevenIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SevenIsland_Mart_EventScript_Lass::
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Hiker::
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Fisher::
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
	end

SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
	.string "POKéMON have personalities of their\n"
	.string "own, just like people.\p"
	.string "My PIKACHU has a HASTY nature,\n"
	.string "so it grew to be a speedy POKéMON.$"

SevenIsland_Mart_Text_PreparationsCompleteForRuins::
	.string "Okay, preparations are complete\n"
	.string "for me to explore the RUINS.$"

SevenIsland_Mart_Text_NeedToFishOnSevenIsland::
	.string "I need to fish on SEVEN ISLAND.\p"
	.string "That will complete my fishing tour\n"
	.string "of the SEVII ISLANDS.\p"
	.string "I'd better stock up on some\n"
	.string "POKé BALLS first, though.$"

