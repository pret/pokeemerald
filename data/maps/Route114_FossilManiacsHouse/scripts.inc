Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mijn grote broer is de FOSSIL MANIAC…\n"
	.string "Hij is aardig en houdt van FOSSIELEN…\p"
	.string "Hij graaft ook graag gaten…\n"
	.string "Dit gat heeft hij zelf gegraven…\p"
	.string "Jij mag dit hebben. Dan kun je ook\n"
	.string "gaten GRAVEN, net als mijn broer…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Gebruikt een POKéMON GRAVEN in een\n"
	.string "grot? Dan ga je terug naar de ingang…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "De vitrine zit vol stenen met\n"
	.string "rare vormen…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "HOE AARDLAGEN ONTSTAAN…\n"
	.string "HOE REGEN HET LAND VORMT…\l"
	.string "STENEN, GROND EN ROTS…\p"
	.string "De kast zit vol boeken.$"

