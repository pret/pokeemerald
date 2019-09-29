GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
	.byte 0

GraniteCave_StevensRoom_EventScript_22DC7B:: @ 822DC7B
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_22DD5A, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_22DDBD, MSGBOX_DEFAULT
	giveitem_std ITEM_TM47
	compare VAR_RESULT, 0
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD3C
	msgbox GraniteCave_StevensRoom_Text_22DE6B, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox GraniteCave_StevensRoom_Text_22DF6A, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_22DF8C, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD0D
	compare VAR_FACING, 1
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD2A
	compare VAR_FACING, 3
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD18
	compare VAR_FACING, 4
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD18
	playse SE_KAIDAN
	removeobject 1
	release
	end

GraniteCave_StevensRoom_EventScript_22DD0D:: @ 822DD0D
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD45
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD18:: @ 822DD18
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_StevensRoom_Movement_22DD4C
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD45
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD2A:: @ 822DD2A
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_StevensRoom_Movement_22DD4C
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD51
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD3C:: @ 822DD3C
	msgbox GraniteCave_StevensRoom_Text_22DFAA, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_22DD45: @ 822DD45
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_22DD4C: @ 822DD4C
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

GraniteCave_StevensRoom_Movement_22DD51: @ 822DD51
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_22DD5A: @ 822DD5A
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_22DDBD: @ 822DDBD
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_22DE6B: @ 822DE6B
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_22DF6A: @ 822DF6A
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_22DF8C: @ 822DF8C
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_22DFAA: @ 822DFAA
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

