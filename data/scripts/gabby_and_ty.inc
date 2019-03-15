EventScript_28CCAA:: @ 828CCAA
	setvar VAR_0x8005, 8
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq EventScript_28CCC6
	setvar VAR_0x8005, 8
	special InterviewAfter
	return

EventScript_28CCC6:: @ 828CCC6
	return

Route111_EventScript_28CCC7:: @ 828CCC7
Route118_EventScript_28CCC7:: @ 828CCC7
Route120_EventScript_28CCC7:: @ 828CCC7
	cleartrainerflag TRAINER_GABBY_AND_TY_6
	specialvar VAR_RESULT, GabbyAndTyGetBattleNum
	switch VAR_RESULT
	case 0, Route111_EventScript_28CD38
	case 1, Route111_EventScript_28CD3E
	case 2, Route111_EventScript_28CD49
	case 3, Route111_EventScript_28CD54
	case 4, Route111_EventScript_28CD5F
	case 5, Route111_EventScript_28CD6A
	case 6, Route111_EventScript_28CD75
	case 7, Route111_EventScript_28CD80
	case 8, Route111_EventScript_28CD8B
	end

Route111_EventScript_28CD38:: @ 828CD38
	call Route111_EventScript_28CD9A
	return

Route111_EventScript_28CD3E:: @ 828CD3E
	call Route111_EventScript_28CDA2
	call Route111_EventScript_28CD96
	return

Route111_EventScript_28CD49:: @ 828CD49
	call Route111_EventScript_28CDAA
	call Route111_EventScript_28CD9E
	return

Route111_EventScript_28CD54:: @ 828CD54
	call Route111_EventScript_28CDB2
	call Route111_EventScript_28CDA6
	return

Route111_EventScript_28CD5F:: @ 828CD5F
	call Route111_EventScript_28CDBA
	call Route111_EventScript_28CDAE
	return

Route111_EventScript_28CD6A:: @ 828CD6A
	call Route111_EventScript_28CDC2
	call Route111_EventScript_28CDB6
	return

Route111_EventScript_28CD75:: @ 828CD75
	call Route111_EventScript_28CDCA
	call Route111_EventScript_28CDBE
	return

Route111_EventScript_28CD80:: @ 828CD80
	call Route111_EventScript_28CDD2
	call Route111_EventScript_28CDC6
	return

Route111_EventScript_28CD8B:: @ 828CD8B
	call Route111_EventScript_28CDC2
	call Route111_EventScript_28CDCE
	return

Route111_EventScript_28CD96:: @ 828CD96
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

Route111_EventScript_28CD9A:: @ 828CD9A
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

Route111_EventScript_28CD9E:: @ 828CD9E
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

Route111_EventScript_28CDA2:: @ 828CDA2
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

Route111_EventScript_28CDA6:: @ 828CDA6
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

Route111_EventScript_28CDAA:: @ 828CDAA
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

Route111_EventScript_28CDAE:: @ 828CDAE
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

Route111_EventScript_28CDB2:: @ 828CDB2
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

Route111_EventScript_28CDB6:: @ 828CDB6
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

Route111_EventScript_28CDBA:: @ 828CDBA
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

Route111_EventScript_28CDBE:: @ 828CDBE
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

Route111_EventScript_28CDC2:: @ 828CDC2
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

Route111_EventScript_28CDC6:: @ 828CDC6
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

Route111_EventScript_28CDCA:: @ 828CDCA
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

Route111_EventScript_28CDCE:: @ 828CDCE
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

Route111_EventScript_28CDD2:: @ 828CDD2
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

Route111_EventScript_28CDD6:: @ 828CDD6
	trainerbattle_double TRAINER_GABBY_AND_TY_1, Route111_Text_28AF05, Route111_Text_28B000, Route111_Text_28B5EC, Route111_EventScript_28CF56
	msgbox Route111_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CDF6:: @ 828CDF6
	trainerbattle_double TRAINER_GABBY_AND_TY_1, Route111_Text_28B75C, Route111_Text_28B8B1, Route111_Text_28B841, Route111_EventScript_28CF56
	msgbox Route111_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_28CE16:: @ 828CE16
	trainerbattle_double TRAINER_GABBY_AND_TY_2, Route118_Text_28AF7D, Route118_Text_28B719, Route118_Text_28B5EC, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_28CE36:: @ 828CE36
	trainerbattle_double TRAINER_GABBY_AND_TY_2, Route118_Text_28B7B1, Route118_Text_28B8F6, Route118_Text_28B841, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_28CE56:: @ 828CE56
	trainerbattle_double TRAINER_GABBY_AND_TY_3, Route120_Text_28AF7D, Route120_Text_28B719, Route120_Text_28B5EC, Route120_EventScript_28CFC3
	msgbox Route120_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_28CE76:: @ 828CE76
	trainerbattle_double TRAINER_GABBY_AND_TY_3, Route120_Text_28B7B1, Route120_Text_28B8F6, Route120_Text_28B841, Route120_EventScript_28CFC3
	msgbox Route120_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CE96:: @ 828CE96
	trainerbattle_double TRAINER_GABBY_AND_TY_4, Route111_Text_28AF7D, Route111_Text_28B719, Route111_Text_28B5EC, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CEB6:: @ 828CEB6
	trainerbattle_double TRAINER_GABBY_AND_TY_4, Route111_Text_28B7B1, Route111_Text_28B8F6, Route111_Text_28B841, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_28CED6:: @ 828CED6
	trainerbattle_double TRAINER_GABBY_AND_TY_5, Route118_Text_28AF7D, Route118_Text_28B719, Route118_Text_28B5EC, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_28CEF6:: @ 828CEF6
	trainerbattle_double TRAINER_GABBY_AND_TY_5, Route118_Text_28B7B1, Route118_Text_28B8F6, Route118_Text_28B841, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CF16:: @ 828CF16
Route118_EventScript_28CF16:: @ 828CF16
Route120_EventScript_28CF16:: @ 828CF16
	trainerbattle_double TRAINER_GABBY_AND_TY_6, Route111_Text_28AF7D, Route111_Text_28B719, Route111_Text_28B5EC, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B5C0, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CF36:: @ 828CF36
Route118_EventScript_28CF36:: @ 828CF36
Route120_EventScript_28CF36:: @ 828CF36
	trainerbattle_double TRAINER_GABBY_AND_TY_6, Route111_Text_28B7B1, Route111_Text_28B8F6, Route111_Text_28B841, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B805, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_28CF56:: @ 828CF56
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToEventObjectLocalIds
	compare VAR_FACING, 2
	call_if_eq Route111_EventScript_28CF94
	compare VAR_FACING, 1
	call_if_eq Route111_EventScript_28CF9F
	compare VAR_FACING, 4
	call_if_eq Route111_EventScript_28CFB1
	goto_if_set FLAG_TEMP_1, Route111_EventScript_28D0EE
	msgbox Route111_Text_28B042, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28CF94:: @ 828CF94
	applymovement VAR_0x8004, Route111_Movement_28D04D
	waitmovement 0
	return

Route111_EventScript_28CF9F:: @ 828CF9F
	applymovement VAR_0x8004, Route111_Movement_28D04F
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

Route111_EventScript_28CFB1:: @ 828CFB1
	applymovement VAR_0x8004, Route111_Movement_28D051
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

Route111_EventScript_28CFC3:: @ 828CFC3
Route118_EventScript_28CFC3:: @ 828CFC3
Route120_EventScript_28CFC3:: @ 828CFC3
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToEventObjectLocalIds
	compare VAR_FACING, 2
	call_if_eq Route111_EventScript_28CF94
	compare VAR_FACING, 1
	call_if_eq Route111_EventScript_28CF9F
	compare VAR_FACING, 4
	call_if_eq Route111_EventScript_28CFB1
	goto_if_set FLAG_TEMP_1, Route111_EventScript_28D0EE
	specialvar VAR_RESULT, GabbyAndTyGetLastQuote
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_28D053
	msgbox Route111_Text_28B137, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GabbyAndTyGetLastBattleTrivia
	switch VAR_RESULT
	case 0, Route111_EventScript_28D061
	case 1, Route111_EventScript_28D06F
	case 2, Route111_EventScript_28D07D
	case 3, Route111_EventScript_28D08B
	case 4, Route111_EventScript_28D099
	end

Route111_Movement_28D04D: @ 828D04D
	walk_in_place_down
	step_end

Route111_Movement_28D04F: @ 828D04F
	walk_in_place_up
	step_end

Route111_Movement_28D051: @ 828D051
	walk_in_place_left
	step_end

Route111_EventScript_28D053:: @ 828D053
	msgbox Route111_Text_28B62D, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D061:: @ 828D061
	msgbox Route111_Text_28B3F3, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D06F:: @ 828D06F
	msgbox Route111_Text_28B1B3, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D07D:: @ 828D07D
	msgbox Route111_Text_28B23D, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D08B:: @ 828D08B
	msgbox Route111_Text_28B2FA, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D099:: @ 828D099
	msgbox Route111_Text_28B379, MSGBOX_YESNO
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D0A7:: @ 828D0A7
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_28D0E1
	msgbox Route111_Text_28B433, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_GABBY_AND_TY
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_28D0E1
	msgbox Route111_Text_28B4AB, MSGBOX_DEFAULT
	special GabbyAndTyAfterInterview
	setflag FLAG_TEMP_1
	release
	end

Route111_EventScript_28D0E1:: @ 828D0E1
	msgbox Route111_Text_28B577, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	release
	end

Route111_EventScript_28D0EE:: @ 828D0EE
	msgbox Route111_Text_28B5C0, MSGBOX_DEFAULT
	release
	end
