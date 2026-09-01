Route12_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route12_NorthEntrance_2F_EventScript_TakeTMMale
	call_if_eq VAR_RESULT, FEMALE, Route12_NorthEntrance_2F_EventScript_TakeTMFemale
	checkitemspace ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	giveitem_msg Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl, ITEM_TM27
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_EventScript_TakeTMMale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale
	return

Route12_NorthEntrance_2F_EventScript_TakeTMFemale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale
	return

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
	msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
	release
	end

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	release
	end

@ Male and female text identical, differ (presumably) in JP
Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale::
	.string "My POKéMON's ashes are stored in\n"
	.string "POKéMON TOWER.\p"
	.string "You can have this TM.\n"
	.string "I don't need it anymore…$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale::
	.string "My POKéMON's ashes are stored in\n"
	.string "POKéMON TOWER.\p"
	.string "You can have this TM.\n"
	.string "I don't need it anymore…$"

Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl::
	.string "{PLAYER} received TM27\n"
	.string "from the little girl.$"

Route12_NorthEntrance_2F_Text_ExplainTM27::
	.string "TM27 is a move called RETURN…\p"
	.string "If you treat your POKéMON good,\n"
	.string "it will return your love by working\l"
	.string "its hardest in battle.$"

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
	.string "You don't have room for this.$"

Route12_NorthEntrance_2F_Text_TheresManFishing::
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "There's a man fishing!$"

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "It's POKéMON TOWER!$"

