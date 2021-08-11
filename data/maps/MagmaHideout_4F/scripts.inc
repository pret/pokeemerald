.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
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

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
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

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "What makes you so adept at handling\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
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
