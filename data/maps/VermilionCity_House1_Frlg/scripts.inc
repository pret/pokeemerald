VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "I'm the FISHING GURU!\p"
	.string "I simply looove fishing!\n"
	.string "I can't bear to go without.\p"
	.string "Tell me, do you like to fish?$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "Grand! I like your style.\n"
	.string "I think we can be friends.\p"
	.string "Take this and fish, young friend!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "{PLAYER} received an OLD ROD from\n"
	.string "the FISHING GURU.$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "Fishing is a way of life!\n"
	.string "It is like the finest poetry.\p"
	.string "From the seas to rivers, go out\n"
	.string "and land the big one, my friend.$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "Oh…\n"
	.string "That's so disappointing…$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "Hello there, {PLAYER}!\p"
	.string "How are the fish biting?$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "Oh, no!\p"
	.string "I had a nice gift for you, but you\n"
	.string "have no room for it!$"

