MauvilleCity_BikeShop_MapScripts:: @ 820EBBB
	.byte 0

MauvilleCity_BikeShop_EventScript_20EBBC:: @ 820EBBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_20EC94
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_20EBF7
	msgbox MauvilleCity_BikeShop_Text_20EE22, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_20EE99, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC4A
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC3D
	end

MauvilleCity_BikeShop_EventScript_20EBF7:: @ 820EBF7
	msgbox MauvilleCity_BikeShop_Text_20EE99, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC4A
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC3D
	end

MauvilleCity_BikeShop_EventScript_20EC16:: @ 820EC16
	message MauvilleCity_BikeShop_Text_20EF32
	waitmessage
	multichoice 21, 8, MULTI_BIKE, 1
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20EC53
	case 1, MauvilleCity_BikeShop_EventScript_20EC6D
	end

MauvilleCity_BikeShop_EventScript_20EC3D:: @ 820EC3D
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_20EEE8, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20EC4A:: @ 820EC4A
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC16
	end

MauvilleCity_BikeShop_EventScript_20EC53:: @ 820EC53
	msgbox MauvilleCity_BikeShop_Text_20F18D, MSGBOX_DEFAULT
	giveitem_std ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20EC6D:: @ 820EC6D
	msgbox MauvilleCity_BikeShop_Text_20F1A5, MSGBOX_DEFAULT
	giveitem_std ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20EC87:: @ 820EC87
	msgbox MauvilleCity_BikeShop_Text_20F1BD, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_20EC94:: @ 820EC94
	msgbox MauvilleCity_BikeShop_Text_20F1FB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECB3
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECE5
	end

MauvilleCity_BikeShop_EventScript_20ECB3:: @ 820ECB3
	msgbox MauvilleCity_BikeShop_Text_20F22F, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECEF
	checkitem ITEM_MACH_BIKE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ED10
	msgbox MauvilleCity_BikeShop_Text_20F2F3, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20ECE5:: @ 820ECE5
	msgbox MauvilleCity_BikeShop_Text_20F2C4, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20ECEF:: @ 820ECEF
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_20F294, MSGBOX_DEFAULT
	takeitem ITEM_ACRO_BIKE, 1
	giveitem_std ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20ED10:: @ 820ED10
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_20F263, MSGBOX_DEFAULT
	takeitem ITEM_MACH_BIKE, 1
	giveitem_std ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20ED31:: @ 820ED31
	msgbox MauvilleCity_BikeShop_Text_20F3C3, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_20ED3A:: @ 820ED3A
	message MauvilleCity_BikeShop_Text_20F445
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20ED46:: @ 820ED46
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20ED88
	case 1, MauvilleCity_BikeShop_EventScript_20ED94
	case 2, MauvilleCity_BikeShop_EventScript_20EDA0
	case 3, MauvilleCity_BikeShop_EventScript_20EDAC
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_20EDAC
	end

MauvilleCity_BikeShop_EventScript_20ED88:: @ 820ED88
	message MauvilleCity_BikeShop_Text_20F487
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20ED94:: @ 820ED94
	message MauvilleCity_BikeShop_Text_20F550
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20EDA0:: @ 820EDA0
	message MauvilleCity_BikeShop_Text_20F61A
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20EDAC:: @ 820EDAC
	release
	end

MauvilleCity_BikeShop_EventScript_20EDAE:: @ 820EDAE
	message MauvilleCity_BikeShop_Text_20F6ED
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EDBA:: @ 820EDBA
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20EDFC
	case 1, MauvilleCity_BikeShop_EventScript_20EE08
	case 2, MauvilleCity_BikeShop_EventScript_20EE14
	case 3, MauvilleCity_BikeShop_EventScript_20EE20
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_20EE20
	end

MauvilleCity_BikeShop_EventScript_20EDFC:: @ 820EDFC
	message MauvilleCity_BikeShop_Text_20F72F
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE08:: @ 820EE08
	message MauvilleCity_BikeShop_Text_20F7F5
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE14:: @ 820EE14
	message MauvilleCity_BikeShop_Text_20F898
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE20:: @ 820EE20
	release
	end

MauvilleCity_BikeShop_Text_20EE22: @ 820EE22
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me Rydel.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_20EE99: @ 820EE99
	.string "Rydel: Your Running Shoes…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_20EEE8: @ 820EEE8
	.string "Rydel: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my Bikes.$"

MauvilleCity_BikeShop_Text_20EF32: @ 820EF32
	.string "Rydel: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from Littleroot?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my Bikes, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a Bike!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of Bikes!\p"
	.string "They are the Mach Bike and\n"
	.string "the Acro Bike!\p"
	.string "The Mach Bike is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an Acro Bike is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

MauvilleCity_BikeShop_Text_20F18D: @ 820F18D
	.string "{PLAYER} chose the Mach Bike.$"

MauvilleCity_BikeShop_Text_20F1A5: @ 820F1A5
	.string "{PLAYER} chose the Acro Bike.$"

MauvilleCity_BikeShop_Text_20F1BD: @ 820F1BD
	.string "Rydel: If you get the urge to switch\n"
	.string "Bikes, just come see me!$"

MauvilleCity_BikeShop_Text_20F1FB: @ 820F1FB
	.string "Rydel: Oh? Were you thinking about\n"
	.string "switching Bikes?$"

MauvilleCity_BikeShop_Text_20F22F: @ 820F22F
	.string "Rydel: Okay, no problem!\n"
	.string "I'll switch Bikes for you!$"

MauvilleCity_BikeShop_Text_20F263: @ 820F263
	.string "{PLAYER} got the Mach Bike exchanged\n"
	.string "for an Acro Bike.$"

MauvilleCity_BikeShop_Text_20F294: @ 820F294
	.string "{PLAYER} got the Acro Bike exchanged\n"
	.string "for a Mach Bike.$"

MauvilleCity_BikeShop_Text_20F2C4: @ 820F2C4
	.string "Rydel: Good, good!\n"
	.string "I'm happy that you like it!$"

MauvilleCity_BikeShop_Text_20F2F3: @ 820F2F3
	.string "Oh? What happened to that Bike\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"

MauvilleCity_BikeShop_Text_20F3C3: @ 820F3C3
	.string "I'm learning about Bikes while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "Bike, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_20F445: @ 820F445
	.string "It's a handbook on the Mach Bike.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_20F487: @ 820F487
	.string "A Bike moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The Bike will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_20F550: @ 820F550
	.string "A Mach Bike is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_20F61A: @ 820F61A
	.string "There are small sandy slopes\n"
	.string "throughout the Hoenn region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a Mach Bike, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_20F6ED: @ 820F6ED
	.string "It's a handbook on the Acro Bike.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_20F72F: @ 820F72F
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_20F7F5: @ 820F7F5
	.string "Keeping the B Button pressed,\n"
	.string "your Bike can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_20F898: @ 820F898
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the Bike\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"

