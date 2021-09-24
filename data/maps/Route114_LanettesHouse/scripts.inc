Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "Lanette: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my Pokémon\n"
	.string "Storage System?\p"
	.string "You should organize your Boxes so you\n"
	.string "can tell which Pokémon are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's Lanette's research notes.\n"
	.string "There's information about Boxes.\p"
	.string "Design Boxes to hold 30 Pokémon each.\p"
	.string "Each Trainer should be able to store\n"
	.string "420 Pokémon on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make Pokémon easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "Box will be made changeable to please\l"
	.string "the stored Pokémon.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a Pokémon, it should be\n"
	.string "sent to the Box inspected last.\p"
	.string "If that Box is full, the received\n"
	.string "Pokémon is stored in the next Box.\p"
	.string "In other words, when a Box is examined,\n"
	.string "it is automatically selected as the Box\l"
	.string "to which Pokémon are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From Bill\n"
	.string "… … … … … … … …”$"

