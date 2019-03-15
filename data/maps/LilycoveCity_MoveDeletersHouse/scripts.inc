LilycoveCity_MoveDeletersHouse_MapScripts:: @ 821EA0A
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_21EA0B:: @ 821EA0B
	lockall
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EAFD, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, LilycoveCity_MoveDeletersHouse_EventScript_21EA3B
	case 0, LilycoveCity_MoveDeletersHouse_EventScript_21EAE6
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EA3B:: @ 821EA3B
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EB65, MSGBOX_DEFAULT
	special sub_81B94B0
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_21EAE6
	special sub_81B98DC
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_21EADC
	special sub_81B96D0
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_21EACF
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EB89, MSGBOX_DEFAULT
	fadescreen 1
	special sub_81B968C
	fadescreen 0
	compare VAR_0x8005, 4
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_21EA3B
	special sub_81B9718
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EBDA, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, LilycoveCity_MoveDeletersHouse_EventScript_21EAB0
	case 0, LilycoveCity_MoveDeletersHouse_EventScript_21EAE6
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EAB0:: @ 821EAB0
	special sub_81B9918
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_21EAF0
	special sub_81B9770
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EC06, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EACF:: @ 821EACF
	special sub_81B9718
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EBA9, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EADC:: @ 821EADC
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EC78, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EAE6:: @ 821EAE6
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EC3F, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_21EAF0:: @ 821EAF0
	special sub_81B9718
	msgbox LilycoveCity_MoveDeletersHouse_Text_21EC9C, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_21EAFD: @ 821EAFD
	.string "Uh…\n"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

LilycoveCity_MoveDeletersHouse_Text_21EB65: @ 821EB65
	.string "Which POKéMON should forget a move?$"

LilycoveCity_MoveDeletersHouse_Text_21EB89: @ 821EB89
	.string "Which move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_21EBA9: @ 821EBA9
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

LilycoveCity_MoveDeletersHouse_Text_21EBDA: @ 821EBDA
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_21EC06: @ 821EC06
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

LilycoveCity_MoveDeletersHouse_Text_21EC3F: @ 821EC3F
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

LilycoveCity_MoveDeletersHouse_Text_21EC78: @ 821EC78
	.string "What?\n"
	.string "No EGG should know any moves.$"

LilycoveCity_MoveDeletersHouse_Text_21EC9C: @ 821EC9C
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"

