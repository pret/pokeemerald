MagmaHideout_4F_MapScripts:: @ 823A55F
	.byte 0

MagmaHideout_4F_EventScript_23A560:: @ 823A560
	lockall
	playbgm MUS_MGM0, 0
	msgbox MagmaHideout_4F_Text_23A9F4, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_W197
	setfieldeffectargument 0, 18
	setfieldeffectargument 1, 42
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	special sub_80B0534
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 150
	removeobject 7
	addobject 1
	waitstate
	delay 60
	applymovement 1, MagmaHideout_4F_Movement_23A672
	waitmovement 0
	special sub_80B058C
	waitstate
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 1, MagmaHideout_4F_Movement_23A67D
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	delay 30
	applymovement 6, MagmaHideout_4F_Movement_23A680
	waitmovement 0
	msgbox MagmaHideout_4F_Text_23AADA, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_23AB33, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_1, MagmaHideout_4F_Text_23ABB5
	msgbox MagmaHideout_4F_Text_23ABE2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen 1
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen 0
	releaseall
	end

MagmaHideout_4F_Movement_23A672: @ 823A672
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_23A67D: @ 823A67D
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_23A680: @ 823A680
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_23A68C:: @ 823A68C
	trainerbattle_single TRAINER_GRUNT_48, MagmaHideout_4F_Text_23A6E8, MagmaHideout_4F_Text_23A775
	msgbox MagmaHideout_4F_Text_23A7B5, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6A3:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_49, MagmaHideout_4F_Text_23A7DA, MagmaHideout_4F_Text_23A81B
	msgbox MagmaHideout_4F_Text_23A841, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6BA:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_50, MagmaHideout_4F_Text_23A86D, MagmaHideout_4F_Text_23A8A7
	msgbox MagmaHideout_4F_Text_23A8C6, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6D1:: @ 823A6D1
	trainerbattle_single TRAINER_TABITHA_3, MagmaHideout_4F_Text_23A8E1, MagmaHideout_4F_Text_23A994
	msgbox MagmaHideout_4F_Text_23A9AC, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_23A6E8: @ 823A6E8
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_23A775: @ 823A775
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_23A7B5: @ 823A7B5
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_23A7DA: @ 823A7DA
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_23A81B: @ 823A81B
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_23A841: @ 823A841
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_23A86D: @ 823A86D
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_23A8A7: @ 823A8A7
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_23A8C6: @ 823A8C6
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_23A8E1: @ 823A8E1
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_23A994: @ 823A994
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_23A9AC: @ 823A9AC
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"

MagmaHideout_4F_Text_23A9F4: @ 823A9F4
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_23AADA: @ 823AADA
	.string "MAXIE: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_23AB33: @ 823AB33
	.string "MAXIE: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_23ABB5: @ 823ABB5
	.string "What makes you so adept at handling\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_23ABE2: @ 823ABE2
	.string "MAXIE: There has to be some reason\n"
	.string "why GROUDON fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after GROUDON, so this\n"
	.string "is where we part!$"
