SixIsland_Mart_Frlg_MapScripts::
	.byte 0

SixIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SixIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SixIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_DREAM_MAIL
	.2byte ITEM_NONE
	release
	end

SixIsland_Mart_EventScript_Picnicker::
	msgbox SixIsland_Mart_Text_ShouldBuyMailAndWriteLetter, MSGBOX_NPC
	end

SixIsland_Mart_Text_AgathaOldestEverEliteFourMember::
	.string "Play with POKéMON lots and live\n"
	.string "a long life!\p"
	.string "Take AGATHA, for example.\p"
	.string "She set a record for being the\n"
	.string "oldest-ever ELITE FOUR member.\p"
	.string "She spurs me to do bigger things.$"

SixIsland_Mart_Text_ShouldBuyMailAndWriteLetter::
	.string "I should buy some MAIL and write\n"
	.string "him a letter…$"

