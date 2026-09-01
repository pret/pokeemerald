Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXSizeDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXSizeSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXSizeTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXSize
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "I'm the FISHING GURU's younger\n"
	.string "brother.\p"
	.string "I simply looove fishing!\n"
	.string "I can't bear to go without.\p"
	.string "Tell me, do you like to fish?$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "Grand! I like your style.\n"
	.string "I think we can be friends.\p"
	.string "Take this and fish, young friend!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "{PLAYER} received a SUPER ROD from\n"
	.string "the FISHING GURU's brother.$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "Fishing is a way of life!\n"
	.string "It is like the finest poetry.\p"
	.string "From the seas to rivers, go out\n"
	.string "and land the big one, my friend.\p"
	.string "Now, I have a request.\p"
	.string "If you catch a big MAGIKARP \n"
	.string "with that ROD, I want to see it.\p"
	.string "As much as I love to fish, I also\n"
	.string "love seeing gigantic MAGIKARP.$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "Oh…\n"
	.string "That's so disappointing…$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "Hello there, {PLAYER}!\n"
	.string "Have you been fishing?\p"
	.string "Try fishing with the SUPER ROD in\n"
	.string "any body of water.\p"
	.string "You'll find different POKéMON in\n"
	.string "different places.\p"
	.string "Oh, and don't forget to bring me\n"
	.string "gigantic MAGIKARP.$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "Oh? {PLAYER}?\n"
	.string "Why, if it isn't a MAGIKARP!\p"
	.string "Allow me to see it, quick!$"

Route12_FishingHouse_Text_WhoaXSizeTakeThis::
	.string "… … …Whoa!\n"
	.string "{STR_VAR_2}!\p"
	.string "You have a rare appreciation for\n"
	.string "the fine, poetic aspects of fishing!\p"
	.string "You must take this.\n"
	.string "I insist!$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "I'll look forward to seeing greater\n"
	.string "records from you!$"

Route12_FishingHouse_Text_HuhXSizeSameSizeAsLast::
	.string "Huh?\n"
	.string "{STR_VAR_2}?\p"
	.string "This is the same size as the one\n"
	.string "I saw before.$"

Route12_FishingHouse_Text_HmmXSizeDoesntMeasureUp::
	.string "Hmm…\n"
	.string "This one is {STR_VAR_2} long.\p"
	.string "It doesn't measure up to the\n"
	.string "{STR_VAR_3} one you brought before.$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "Uh… That doesn't look much like\n"
	.string "a MAGIKARP.$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "Oh, no!\p"
	.string "I had a gift for you, but you have\n"
	.string "no room for it.$"

Route12_FishingHouse_Text_MostGiganticMagikarpXSize::
	.string "The most gigantic MAGIKARP\n"
	.string "I have ever witnessed…\p"
	.string "{STR_VAR_3}!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "It's a blank chart of some sort.\p"
	.string "It has spaces for writing in\n"
	.string "records of some kind.$"
