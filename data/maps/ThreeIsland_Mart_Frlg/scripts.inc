ThreeIsland_Mart_Frlg_MapScripts::
	.byte 0

ThreeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ThreeIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ThreeIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

ThreeIsland_Mart_EventScript_Picnicker::
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_BugCatcher::
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_Youngster::
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end

ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
	.string "Is it true?\p"
	.string "CELADON DEPT. STORE is several\n"
	.string "times bigger than this shop?$"

ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest::
	.string "I sometimes buy medicine here.\p"
	.string "But a lot of people heal POKéMON\n"
	.string "with BERRIES from BERRY FOREST.\p"
	.string "After all, BERRIES are free and\n"
	.string "they never run out.$"

ThreeIsland_Mart_Text_BikersWereAboutToTrashMart::
	.string "Those BIKERS were about to trash\n"
	.string "this POKéMON MART.\p"
	.string "Am I glad they decided to leave!$"

