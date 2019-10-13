FallarborTown_House1_MapScripts:: @ 8200F12
	.byte 0

FallarborTown_House1_EventScript_200F13:: @ 8200F13
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_House1_EventScript_200FB2
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_House1_EventScript_200F38
	msgbox FallarborTown_House1_Text_200FEE, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200F38:: @ 8200F38
	call_if_unset FLAG_TEMP_2, FallarborTown_House1_EventScript_200F8B
	call_if_set FLAG_TEMP_2, FallarborTown_House1_EventScript_200F9C
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_House1_EventScript_200FA5
	msgbox FallarborTown_House1_Text_201159, MSGBOX_DEFAULT
	giveitem_std ITEM_TM27
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM27
	msgbox FallarborTown_House1_Text_2011A5, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200F8B:: @ 8200F8B
	msgbox FallarborTown_House1_Text_200FEE, MSGBOX_DEFAULT
	msgbox FallarborTown_House1_Text_2010A2, MSGBOX_YESNO
	return

FallarborTown_House1_EventScript_200F9C:: @ 8200F9C
	msgbox FallarborTown_House1_Text_201249, MSGBOX_YESNO
	return

FallarborTown_House1_EventScript_200FA5:: @ 8200FA5
	setflag FLAG_TEMP_2
	msgbox FallarborTown_House1_Text_201212, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200FB2:: @ 8200FB2
	msgbox FallarborTown_House1_Text_2011A5, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200FBC:: @ 8200FBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_House1_EventScript_200FE4
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_House1_EventScript_200FDA
	msgbox FallarborTown_House1_Text_2012BC, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200FDA:: @ 8200FDA
	msgbox FallarborTown_House1_Text_201310, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_EventScript_200FE4:: @ 8200FE4
	msgbox FallarborTown_House1_Text_20134B, MSGBOX_DEFAULT
	release
	end

FallarborTown_House1_Text_200FEE: @ 8200FEE
	.string "PROF. COZMO: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling TEAM MAGMA where\l"
	.string "you can find METEORITES…\p"
	.string "That METEORITE from METEOR FALLS…\n"
	.string "It's never going to be mine now…$"

FallarborTown_House1_Text_2010A2: @ 82010A2
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the METEORITE that TEAM MAGMA\n"
	.string "took from METEOR FALLS?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_House1_Text_201159: @ 8201159
	.string "PROF. COZMO: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"

FallarborTown_House1_Text_2011A5: @ 82011A5
	.string "PROF. COZMO: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!$"

FallarborTown_House1_Text_201212: @ 8201212
	.string "PROF. COZMO: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_House1_Text_201249: @ 8201249
	.string "PROF. COZMO: Please, may I have that\n"
	.string "METEORITE?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_House1_Text_2012BC: @ 82012BC
	.string "PROF. COZMO went off to METEOR FALLS\n"
	.string "on ROUTE 114 with some people from\l"
	.string "TEAM MAGMA.$"

FallarborTown_House1_Text_201310: @ 8201310
	.string "Poor PROF. COZMO…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_House1_Text_20134B: @ 820134B
	.string "Look at PROF. COZMO…\n"
	.string "He's so happy! I think it's cute.$"

